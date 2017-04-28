package com.company;

import javax.json.*;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.String;
import java.util.*;

import java.util.ArrayList;

import static javax.json.JsonValue.ValueType.*;


//enum accessAttr { R_ONLY, RW, RW_ROOT, R0W, R0W_ROOT }





public class Main {

    public static void main(String[] args) {

        JsonStructure jsonData = null; // LAT data
        JsonStructure jsonType = null; // LAT types
        FileReader fTypeReader = null;
        FileReader fDataReader = null;
        FileWriter fOutputWriter = null;
        JsonReader jTypeReader = null;
        JsonReader jDataReader = null;
        Map<String, LatType> typeMap = null;     // consist all types
        List<LatVariable> varList = null; // consist all variables
        try {
            fTypeReader = new FileReader("/home/hp/Idea/IdeaProjects/LAT/LAT_types.js");
            fDataReader = new FileReader("/home/hp/Idea/IdeaProjects/LAT/LAT.js");
            fOutputWriter = new FileWriter("/home/hp/Idea/IdeaProjects/LAT/LAT_defines.h", true);
            // fOutputWriter delete file content
        } catch (FileNotFoundException e) {
            System.out.println("FileNotFoundException :" + e.getMessage());
        } catch (IOException e) {
            System.out.println("IOException :" + e.getMessage());
        }
        try {
            jDataReader = Json.createReader(fDataReader);
            jTypeReader = Json.createReader(fTypeReader);
        } catch (JsonException e) {
            System.out.println("JsonException :" + e.getMessage());
        }
        try {
            jsonData = jDataReader.read();
            jsonType = jTypeReader.read();
        } catch (JsonException e) {
            System.out.println("JsonException :" + e.getMessage());
        } catch (IllegalStateException e) {
            System.out.println("IllegalStateException :" + e.getMessage());
        }
        if (jsonData != null && jsonType != null) {
            JsonVariableParser vparser = new JsonVariableParser();
            JsonTypeParser tparser = new JsonTypeParser();
            typeMap = tparser.generateTypes(jsonType, vparser);
            varList = vparser.generateVars(jsonData, typeMap);
        } else {
            System.out.println("Error while parsing input files");
        }
        //generate outputs
        OutputBuilder dg = new CDefineGenerator();
        OutputBuilder tg = new CTypesGenerator();
        System.out.println("LAT generation started");
        dg.generateOutput(fOutputWriter, varList, typeMap);
        System.out.println("LAT generation completed");
        System.out.println("LAT types generation started");
        //tg.printCVarFromLatVar(null, null, null, null) {
        tg.generateOutput(fOutputWriter, varList, typeMap);
        System.out.println("LAT types generation completed");
        while(true){}
    }
}

class BitField{

    public void calcMask() {
        int bfSize = size;
        int bfMask = 0;
        while(bfSize > 0) {
            bfSize--;
            bfMask |= 1 << pos + bfSize;
        }
        mask = bfMask;
    }

    Integer size;
    Integer pos;
    Integer mask;
    String name;
    String comment;
}
interface LatObject {
    public int getSerialNum();
    public boolean setSize(Integer size);
    public boolean setName(String name);
    public Integer getSize();
    public String getName();

    //public void setChild(LatObject object);
    //public int getChildsNum();
    //public LatObject getChild(Integer num);

    public boolean fInalize();
}
abstract class LatObjectAbstract implements LatObject {

    protected String name;
    protected Integer size;
    protected int serialNum;
    protected boolean finalized;

    protected LatObjectAbstract(int snum) {
        serialNum = snum;
        size = null;
        name = null;
        finalized = false;
    }

    public int getSerialNum() { return serialNum; }
    //public abstract boolean setSize(Integer size);
    //public abstract boolean setName(String name);
    //public abstract Integer getSize();
    public String getName() {
        return name;
    }//public abstract String getName();
    //public abstract boolean fInalize();
}
interface LatType extends LatObject {
    public boolean addBitField(BitField bitf);
    public BitField getBitField(int bitFieldNum);

    public void setChild(LatVariable var);
    public LatVariable getChild(Integer num);
    public int getChildsNum();

    public int searchAttr(String attr);
    public boolean haveOnly(String attr);
}
interface LatVariable extends LatObject {
    public boolean setAttr(String attr);
    public boolean setCnt(Integer cnt);
    public boolean setArraySize(Integer arraysize);
    public boolean setType(LatType type);
    public boolean setChild(LatVariable var);

    public String getAttr();
    public Integer getCnt();
    public Integer getArraySize();
    public LatType getType();
    public LatVariable getChild(Integer num);
    public int getChildsNum();

    public int searchAttr(String attr);
    public boolean haveOnly(String attr);
}
class LatVariableImpl extends LatObjectAbstract implements LatVariable {

    // number of variables in existance
    private static int instanceCnt;
    public static int getInstanceCnt() {
        return instanceCnt;
    }

    // access attribute
    // have priority over child.attr
    String attr;
    // number of variables with that name
    // 1 address define for each
    Integer varCnt;
    // number of elements in each variable
    Integer arraysize;
    // tyreturn false;pe description
    // ignored if childs.size() > 0
    LatType type;
    List<LatVariable> child;

    LatVariableImpl() {
        super(instanceCnt);
        instanceCnt++;

        attr = null;
        varCnt = null;
        arraysize = null;
        type = null;
        child = new ArrayList<LatVariable>();
    }

    private void printError(String msg) {
        if(name != null) {
            System.out.println("Error : " + msg + " in variable '" + name + "'");
        } else {
            System.out.println("Error : " + msg + " in variable #" + serialNum);
        }
        while(true){}
    }
    private void printWarning(String msg) {
        if(name != null) {
            System.out.println("Warning : " + msg + " in variable '" + name + "'");
        } else {
            System.out.println("Warning : " + msg + " in variable #" + serialNum);
        }
    }
    public boolean setName(String name) {
        if(finalized == true) {
            printError("attempt to change name");
            return false;
        }
        if(this.name != null){
            printError("duplicate key 'name'");
            return false;
        }
        this.name = name;
        return true;
    }
    public boolean setSize(Integer size) {
        printWarning("attempt to set size of variable, ignored");
        return false;
    }
    public boolean setAttr(String attr){
        if(finalized == true) {
            printError("attempt to change attr");
            return false;
        }
        if(!attr.equals("r_only") && !attr.equals("rw") && !attr.equals("rw_root") && !attr.equals("r0w") && !attr.equals("r0w_root")) {
            printError("unknown access attribute '" + attr + "' found");
            return false;
        }
        if(this.attr != null) {
            printError("duplicate key 'attr' found");
            return false;
        }
        this.attr = attr;
        return true;
    }
    public boolean setCnt(Integer cnt) {
        if(finalized == true) {
            printError("attempt to change cnt");
            return false;
        }
        if(this.varCnt != null) {
            printError("duplicate definition of key 'cnt'");
            return false;
        }
        if(cnt <= 0) {
            printError("key 'cnt' must be a positive integer");
            return false;
        }
        this.varCnt = cnt;
        return true;
    }
    public boolean setArraySize(Integer arraysize) {
        if(finalized == true) {
            printError("attempt to change cnt");
            return false;
        }
        //if(child.size() > 0) {
        //    printWarning("key 'arraysize' is ignored");
        //    return true;
        //}
        if(this.arraysize != null) { //  = 1 при создании
            printError("duplicate definition of key 'arraysize'");
        }
        if(arraysize <= 0) {
            printError("key 'arraysize' must be a positive integer");
            return false;
        }
        this.arraysize = arraysize;
        return true;
    }
    public boolean setType(LatType type) {
        if(finalized == true) {
            printError("attempt to change cnt");
            return false;
        }
        if(child.size() > 0) {
            printWarning("key 'type' is ignored");
            return true;
        }
        if(this.type != null) {
            printError("duplicate definition of key 'type'");
            return false;
        }
        this.type = type;
        //for(int i = 0; i < type.getChildsNum(); i++)
        //{
        //    child.add(type.getChild(i));
        //}
        return true;
    }
    public boolean setChild(LatVariable var) {
        if(finalized == true) {
            printError("attempt to add child");
            return false;
        }
        /*if(child.size() > 0) {
            if(type != null) {
                printWarning("key 'type' is ignored");
                type = null;
            }
            //if(attr != null) {
            //    printWarning("key 'attr' is ignored");
            //    attr = null;
            //}
            if(arraysize != null) {
                printWarning("key 'arraysize' is ignored");
                arraysize = null;
            }
        }*/
        child.add(var);
        return true;
    }
    public boolean fInalize() {
        if(finalized) {
            return true;
        }
        if(name == null) {
            printError("incomplete variable - missing 'name' key");
            return false;
        }
        if(varCnt == null) {
            printWarning("incomplete variable - missing 'cnt' key, assumed as 1 at finalization");
            varCnt = 1;
            //return false;
        }
        if(arraysize == null) {
            printWarning("incomplete variable - missing 'arraysize' key, assumed as 1 at finalization");
            arraysize = 1;
        }
        if(child.size() == 0) {
            if(type == null) {
                printError("incomplete variable - missing 'type' key");
                return false;
            }
            if(attr == null &&
               type.searchAttr("r_only") == 0 && type.searchAttr("rw") == 0 && type.searchAttr("rw_root") == 0 &&
               type.searchAttr("r0w") == 0 && type.searchAttr("r0w_root") == 0) {
                printError("incomplete variable - missing 'attr' key");
                return false;
            }
            size = type.getSize() * arraysize;
        } else {
            if(type != null) {
                printWarning("key 'type' is ignored at finilization");
                //return false;
            }
            if(attr != null) {
                printWarning("key 'attr' have priority over childs");
                //return false;
            }
            size = 0;
            for(int i = 0; i < child.size() ; i++) {
                size += child.get(i).getSize();
            }
            size *= arraysize;
        }
        if(size % 2 != 0) {
            printError("'size' must be multiple of 2");
            return false;
        }
        finalized = true;
        return true;
    }

    //public String getName() {
    //    return name;
    //}
    public Integer getSize() {
        return size;
    }
    public String getAttr() {
        return attr;
    }
    public Integer getCnt() {
        return varCnt;
    }
    public Integer getArraySize() {
        return arraysize;
    }
    public LatType getType() {
        return type;
    }
    public int getChildsNum() {
        return child.size();
    }
    public LatVariable getChild(Integer num){
        return child.get(num);
    }
    public int searchAttr(String attr) {
        int result = 0;
        if(this.attr != null) {
            return this.attr.equals(attr) ? 1 : 0;
        } else {
            if(this.getChildsNum() > 0) {
                for (int i = 0; i < this.child.size(); i++) {
                    result += this.getChild(i).searchAttr(attr);
                }
            } else {
                result += this.type.searchAttr(attr);
            }
        }
        return result;
    }
    public boolean haveOnly(String attr)
    {
        if(searchAttr(attr) == 0) return false;
        if(getChildsNum() == 0) {
            int i = 0;
            while(i < getType().getChildsNum()) {
                if(!getType().getChild(i).haveOnly(attr)) { return false; }
                i++;
            }
        } else {
            int j = 0;
            while(j < getChildsNum()) {
                if(!getChild(j).haveOnly(attr)) return false;
                j++;
            }
        }
        return true;
    }
}
class LatTypeImpl extends LatObjectAbstract implements LatType {

    // number of types in existance
    private static int instanceCnt;
    public static int getInstanceCnt() {
        return instanceCnt;
    }

    // type size in bytes
    // set up ignored if childs.size() > 0 (calculated from childs sizes)
    //Integer size;
    // bitfield mapping "bitNum : value"
    // ignored if childs.size() > 0
    Map<Integer, BitField> bitMap;
    // num of defined bits
    Integer bitsNum;
    // variables as part of complex type
    List<LatVariable> child;

    LatTypeImpl() {
        super(instanceCnt);
        instanceCnt++;

        bitsNum = 0;
        bitMap = new HashMap<Integer, BitField>();
        child = new ArrayList<LatVariable>();
    }

    private void printError(String msg) {
        if(name != null) {
            if(finalized) {
                System.out.println("Error : " + msg + " in finalized type '" + this.name + "'");
            } else {
                System.out.println("Error : " + msg + " in type '" + this.name + "'");
            }
        } else {
            System.out.println("Error : " + msg + " in type # " + instanceCnt);
        }
        while(true){}
    }
    private void printWarning(String msg) {
        if(name != null) {
            System.out.println("Warning : " + msg + ", found in type '" + this.name + "'");
        } else {
            System.out.println("Warning : " + msg + ", found in type # " + instanceCnt);
        }
    }

    public void setChild(LatVariable var) {
        if(finalized == true) {
            printError("attempt to add child variable");// if name = null??
            return;
        }
        if(child.size() == 0 && size != null) {
            printWarning("key 'size' is ignored because complex type calculates it's size by his own");
            size = null;
        }
        if(size == null) {
            size = 0;
        }
        size += var.getSize();
        child.add(var);
    }
    public boolean setName(String name) {
        if(finalized == true) {
            printError("attempt to change name");// if name = null??
        }
        if(this.name != null) {
            printWarning("duplicate key 'name' in type declaration");
        }
        this.name = name;
        return true;
    }
    public boolean setSize(Integer size) {
        if(finalized == true) {
            printError("attempt to change size");// if name = null??
            return false;
        }
        //if(child.size() > 0) {
        //    printWarning("'size' is ignored because complex type calculates it's size by his own");
        //    return true;
        //}
        if(size <= 0) {
            printError("'size' must be a positive integer");
            return false;
        }
        //if(size % 2 != 0) {
        //    printError("'size' must be multiple of 2");
        //    return false;
        //}
        if(this.size != null) {
            printError("duplicate key 'size' in type declaration");// if name = null??
            return false;
        }
        this.size = size;
        return true;
    }
    public boolean addBitField(BitField bitf) {
        if(finalized == true) {
            printError("attempt to add bitfield");// if name = null??
            return false;
        }
        if(child.size() > 0) {
            printWarning("bitfileds ignored in complex type");// if name = null??
            return true;
        }
        if(bitf == null) {
            printError("attempt to add 'null' bitfield");// if name = null??
            return false;
        }
        //if(size == null) {
        //    printError("define key 'size' before 'bitfield'");
        //   return false;
        //}
        if(size != null)//if(size != null && bitMap.size() > size * 8)
        {
            if(bitsNum + bitf.size >= size * 8) {
                printError("type declaration have more bits descriptions than actual bits available (size * 8)");
                return false;
            }
            if(bitsNum + bitf.size >= 32) {
                printError("type declaration can't have more than 32 bits descriptions");
                return false;
            }
        }
        bitf.pos = bitsNum;
        bitf.calcMask();
        bitMap.put(bitMap.size(), bitf);
        bitsNum += bitf.size;
        return true;
    }
    public boolean fInalize() {
        if(finalized) {
            return true;
        }
        if(name == null) {
            printError("incomplete type - missing name attribute");
            return false;
        }
        if(child.size() == 0) {
            if(size == null) {
                printError("incomplete type - missing size attribute");
                return false;
            } else {
                if(size * 8 < bitMap.size()) {
                    printError("invalid type - have more bit descriptions than available bits");
                    return false;
                }
            }
        }
        else
        {
            if(size != null) {
                printWarning("'size' is ignored because complex type calculates it's size by his own");
            }
            size = 0;
            for(int i = 0; i < child.size(); i++) {
                size += child.get(i).getSize();
            }
            if(bitMap.size() != 0) {
                printWarning("bitfiled ignored in complex type");// if name = null??
            }
        }
        finalized = true;
        return true;
    }

    public Integer getSize() {
        return size;
    }
    public BitField getBitField(int bitFieldNum) {
        return bitMap.get(bitFieldNum);
    }
    public int getChildsNum() {
        return child.size();
    }
    public LatVariable getChild(Integer num){
        return child.get(num);
    }

    public int searchAttr(String attr) {
        int result = 0;
        for (int i = 0; i < this.child.size(); i++) {
            result += this.getChild(i).searchAttr(attr);
        }
        return result;
    }
    public boolean haveOnly(String attr)
    {
        if(searchAttr(attr) == 0) return false;
        if(getChildsNum() == 0) {
            return true;
        }
        int i = 0;
        while(i < getChildsNum()) {
            if(!getChild(i).haveOnly(attr)) return false;
            i++;
        }
        return true;
    }
}

abstract class JsonWorker {
    abstract void printWarning(String wrMsg);
    abstract void printError(String errMsg);
//    abstract void parseObject(JsonObject object, String key);
}
class JsonTypeParser extends JsonWorker {

    private JsonVariableParser varParser;
    private TreeMap<String, LatType> typeMap;

    // Parser states:
    // EMPTY / 'type' not found - 1
    // TYPE_DECLARATION_FOUND / 'type : OBJECT' found  - 2
    // BIT_DECLARATION_FOUND / 'bitfield : OBJECT' found inside 'type : OBJECT'
    //Integer state;
    LatType type;
    BitField bf;

    public Map<String, LatType> generateTypes(JsonValue tree, JsonVariableParser parser) {
        type = null;
        bf = null;
        typeMap = new TreeMap<String, LatType>();
        varParser = parser;
        navigateTree(tree, null, 1);
        return typeMap;
    }

    private void navigateTree(JsonValue tree, String key, Integer state) {
        if (key != null) {
            System.out.print("Key " + key + ": ");
        }
        switch (tree.getValueType()) {
            case OBJECT:
                System.out.println("OBJECT");
                JsonObject object = (JsonObject) tree;
                parseObject(object, key, state);
                break;
            case ARRAY:
                System.out.println("ARRAY");
                JsonArray array = (JsonArray) tree;
                parseArray(array, key, state);
                break;
            case STRING:
                JsonString st = (JsonString) tree;
                System.out.println("STRING " + st.getString());
                parseString(st, key, state);
                break;
            case NUMBER:
                JsonNumber num = (JsonNumber) tree;
                System.out.println("NUMBER " + num.toString());
                parseNumber(num, key, state);
                break;
            case TRUE:
                System.out.println(tree.getValueType().toString());
                break;
            case FALSE:
                System.out.println(tree.getValueType().toString());
                break;
            case NULL:
                System.out.println(tree.getValueType().toString());
                break;
        }
    }

    private void parseObject(JsonObject object, String key, Integer state) {
        switch (state) {
            case 1: // EMPTY
                parseObject_1(object, key, state);
                break;
            case 2: //TYPE_DECLARATION_FOUND
                parseObject_2(object, key, state);
                break;
            case 3:// BIT_DECLARATION_FOUND
                parseObject_3(object, key, state);
                break;
            default:
                printError("Error: unknown parser state: " + state.toString());
        }
    }
    private void parseObject_1(JsonObject object, String key, Integer state) {
        if (key == null) {
            for (String newKey : object.keySet()) {
                navigateTree(object.get(newKey), newKey, state);
            }
            return;
        }
        switch (key) {
            case "type_declaration":
                type = new LatTypeImpl();
                for (String newKey : object.keySet()) {
                    navigateTree(object.get(newKey), newKey, 2); //state = 2 / TYPE_DECLARATION_FOUND
                }
                type.fInalize();
                typeMap.put(type.getName(), type);
                break;
            default:
                printWarning("Warning : key '" + key + "' found outside of 'type_declaration', ignored");
        }
    }
    private void parseObject_2(JsonObject object, String key, Integer state) {
        if (key == null) {
            printError("some error"); // ???
            return;
        }
        if (key.equals("attr") || key.equals("arraysize") || key.equals("cnt") || key.equals("type")) {
            printError("Error: " + key + " key is not allowed in 'type_declaration' object");
            return;
        }
        switch (key) {
            case "type_declaration":
                printError("Error : 'type_declaration' inside 'type_declaration' found"); // ???
                break;
            case "name":
                printError("Error : must be 'name : STRING', found 'name : OBJECT'");
                break;
            case "size":
                printError("Error : must be 'size : NUMBER', found 'size : OBJECT'");
                break;
            case "bitfield":
                bf = new BitField();
                for (String newKey : object.keySet()) {
                    navigateTree(object.get(newKey), newKey, 3); //state = 3 - BIT_DECLARATION_FOUND
                }
                type.addBitField(bf);
                break;
            default:
                varParser.setTypes(typeMap);
                type.setChild(varParser.parseVariable(object, key)); // child variable declaration
        }
    }
    private void parseObject_3(JsonObject object, String key, Integer state) {
        printError("Error : OBJECT inside 'bitfield' object");
        /*if (key == null || !key.equals("bitfield")) ) {
            printError("some error"); // ??? reentrance
            return;
        }
        bf = new BitField();
        for (String newKey : object.keySet()) {
            navigateTree(object.get(newKey), newKey, 3); //state = 3 - BIT_DECLARATION_FOUND
        }
        type.addBitField(bf);*/
    }

    private void parseArray(JsonArray array, String key, Integer state) {
        switch (state) {
            case 1: // EMPTY
                parseArray_1(array, key, state);
                break;
            case 2: //TYPE_DECLARATION_FOUND
                parseArray_2(array, key, state);
                break;
            case 3: // BIT_DECLARATION_FOUND
                parseArray_3(array, key, state);
                break;
            default:
                printError("Error: unknown parser state: " + state.toString());
        }
    }
    private void parseArray_1(JsonArray array, String key, Integer state) {
        for (JsonValue val : array) {
            navigateTree(val, key, state);
        }
    }
    private void parseArray_2(JsonArray array, String key, Integer state) {
        if (key.equals("attr") || key.equals("arraysize") || key.equals("cnt") || key.equals("type")) {
            printError("Error: " + key + " key is not allowed in 'type_declaration' object");
            return;
        }
        switch (key) {
            case "type_declaration":
                printError("Error : 'type_declaration' inside 'type_declaration' found"); // ???
                break;
            case "name":
                printError("Error : must be 'name : STRING', found 'name : ARRAY'");
                break;
            case "size":
                printError("Error : must be 'size : NUMBER', found 'size : ARRAY'");
                break;
            case "bitfield":
                for (JsonValue val : array) {
                    //bf = new BitField();
                    navigateTree(val, key, 2);
                    //type.addBitField(bf);
                }
                break;
            default:
                printError("Error : unknown key '" + key + "' found in type_declaration");
        }
    }
    private void parseArray_3(JsonArray array, String key, Integer state) {
        printError("Error : ARRAY found inside 'bitfield' object");
    }

    private void parseString(JsonString jstring, String key, Integer state) {
        switch (state) {
            case 1: // EMPTY
                parseString_1(jstring, key, state);
                break;
            case 2: //TYPE_DECLARATION_FOUND
                parseString_2(jstring, key, state);
                break;
            case 3: // BIT_DECLARATION_FOUND
                parseString_3(jstring, key, state);
                break;
            default:
                printError("Error: unknown parser state: " + state.toString());
        }
    }
    private void parseString_1(JsonString jstring, String key, Integer state) {
        if (key == null) {
            printWarning("string '" + jstring.getString() + "' found outside of 'type_declaration', ignored ");
        } else {
            printWarning("pair '" + key + " : " + jstring.getString() + "' found outside of 'type_declaration', ignored");
        }
    }
    private void parseString_2(JsonString jstring, String key, Integer state) {
        if (key.equals("attr") || key.equals("arraysize") || key.equals("cnt") || key.equals("type")) {
            printError("Error: " + key + " key is not allowed in 'type_declaration' object");
            return;
        }
        switch (key) {
            case "type_declaration":
                printError("Error : 'type_declaration' inside 'type_declaration' found"); // ???
                break;
            case "name":
                type.setName(jstring.getString());
                break;
            case "size":
                printError("Error : must be 'size : NUMBER', found 'size : STRING'");
                break;
            case "bitfield":
                printError("Error : must be 'bitfield : OBJECT/ARRAY', found 'bitfield : STRING'");
                break;
            default:
                printError("Error : unknown key '" + key + "' found in type_declaration");
        }
    }
    private void parseString_3(JsonString jstring, String key, Integer state) {
        if (key.equals("attr") || key.equals("arraysize") || key.equals("cnt") || key.equals("type")) {
            printError("Error: " + key + " key is not allowed in 'type_declaration' object");
            return;
        }
        switch (key) {
            case "type_declaration":
                printError("Error : 'type_declaration' inside 'bitfield' found"); // ???
                break;
            case "name":
                bf.name = jstring.getString();
                break;
            case "size":
                printError("Error : must be 'size : NUMBER', found 'size : STRING'");
                break;
            case "comment":
                bf.comment = jstring.getString();
                break;
            case "bitfield":
                printError("Error : key 'bitfield' inside of 'bitfield' found");
                break;
            default:
                printWarning("Error : unknown key '" + key + " found in 'bitfield', ignored");
        }
    }

    private void parseNumber(JsonNumber jnum, String key, Integer state) {
        switch (state) {
            case 1: // EMPTY
                parseNumber_1(jnum, key, state);
                break;
            case 2: //TYPE_DECLARATION_FOUND
                parseNumber_2(jnum, key, state);
                break;
            case 3: // BIT_DECLARATION_FOUND
                parseNumber_3(jnum, key, state);
                break;
            default:
                printError("Error: unknown parser state: " + state.toString());
        }
    }
    private void parseNumber_1(JsonNumber jnum, String key, Integer state) {
        if (key == null) {
            printWarning("string '" + jnum.toString() + "' found outside of 'type_declaration', ignored ");
        } else {
            printWarning("pair '" + key + " : " + jnum.toString() + "' found outside of 'type_declaration', ignored");
        }
    }
    private void parseNumber_2(JsonNumber jnum, String key, Integer state) {
        if (key.equals("attr") || key.equals("arraysize") || key.equals("cnt") || key.equals("type")) {
            printError("Error: " + key + " key is not allowed in 'type_declaration' object");
            return;
        }
        switch (key) {
            case "type_declaration":
                printError("Error : 'type_declaration' inside 'type_declaration' found"); // ???
                break;
            case "name":
                printError("Error : must be 'size : NUMBER', found 'size : STRING'");
                break;
            case "size":
                if (jnum.isIntegral() == false || jnum.intValue() <= 0) {
                    printError("Error: size must be a positive integer, found " + jnum.toString());
                } else {
                    type.setSize(jnum.intValue());
                }
                break;
            case "bitfield":
                printError("Error : must be 'bitfield : OBJECT/ARRAY', found 'bitfield : NUMBER'");
                break;
            default:
                printError("Error : unknown key '" + key + "' found in type_declaration");
        }
    }
    private void parseNumber_3(JsonNumber jnum, String key, Integer state) {
        if (key.equals("attr") || key.equals("arraysize") || key.equals("cnt") || key.equals("type")) {
            printError("Error: " + key + " key is not allowed in 'type_declaration' object");
            return;
        }
        switch (key) {
            case "type_declaration":
                printError("Error : 'type_declaration' inside 'bitfield' found"); // ???
                break;
            case "name":
                printError("Error : must be 'name : STRING', found 'name : NUMBER'");
                break;
            case "size":
                if (jnum.isIntegral() == false || jnum.intValue() <= 0) {
                    printError("Error: size must be a positive integer, found " + jnum.toString());
                } else {
                    bf.size = jnum.intValue();
                }
                break;
            case "comment":
                bf.comment = jnum.toString();
                break;
            case "bitfield":
                printError("Error : key 'bitfield' inside 'bitfield' found");
                break;
            default:
                printError("Error : unknown key  '" + key + "' found in 'bitfield', ignored");
        }
    }

    void printWarning(String wrMsg) {
        System.out.println(wrMsg);
        while (true) {
        }
    }
    void printError(String errMsg) {
        System.out.println(errMsg);
        //System.out.println("Found in type #" + LatType.getSerialNum());
        while (true) {
        }
    }
}
class JsonVariableParser extends JsonWorker {

    private List<LatVariable> varList;
    private Map<String, LatType> typesMap;//LatTypeImpl

    JsonVariableParser() {
        typesMap = new TreeMap<String, LatType>();
        varList = null;
    }

    void printWarning(String wrMsg) {
        System.out.println(wrMsg);
    }
    void printError(String errMsg) {
        System.out.println(errMsg);
        // where ???
        while(true){}
    }
    void navigateTree(JsonValue tree, String key, LatVariable parent) {
        if (key != null) {
            System.out.print("Key " + key + ": ");
        }
        switch(tree.getValueType()) {
            case OBJECT:
                System.out.println("OBJECT");
                JsonObject object = (JsonObject) tree;
                parseObject(object, key, parent);
                break;
            case ARRAY:
                System.out.println("ARRAY");
                printError("Error: arrays are restricted");
                break;
            case STRING:
                JsonString st = (JsonString) tree;
                System.out.println("STRING " + st.getString());
                parseString(st, key, parent);
                break;
            case NUMBER:
                JsonNumber num = (JsonNumber) tree;
                System.out.println("NUMBER " + num.toString());
                parseNumber(num, key, parent);
                break;
            case TRUE:
                System.out.println(tree.getValueType().toString());
                printError("Error: booleans are restricted");
                break;
            case FALSE:
                System.out.println(tree.getValueType().toString());
                printError("Error: booleans are restricted");
                break;
            case NULL:
                System.out.println(tree.getValueType().toString());
                printError("Error: no variables found");
                break;
        }
    }
    void parseObject(JsonObject object, String key, LatVariable parent) {
        if(key == null) {
            for (String newKey : object.keySet()) {
                navigateTree(object.get(newKey), newKey, parent);
            }
            return;
        }
        if (key.equals("type_declaration") || key.equals("name") || key.equals("size") || key.equals("bit")) {
            printError("Error: key '" + key + "' found as variable name / as object key");
            return;
        }
        if (key.equals("attr") || key.equals("arraysize") || key.equals("cnt") || key.equals("type")) {
            printError("Error: key '" + key + "' found as variable name / as object key");
            return;
        }
        if(parent != null) {
            parent.setChild(parseVariable(object, key));
        } else {
            varList.add(parseVariable(object, key));
        }
    }
    void parseString(JsonString string, String key, LatVariable var) {
        String st = string.getString();
        if(var == null) {
            printError("Error: pair '" + key + "' : " + st + "' found outside of variable definition");
            return;
        }
        if (key.equals("type_declaration") || key.equals("name") || key.equals("size") || key.equals("bit")) {
            printError("Error: key '" + key + "' found as variable attribute");
            return;
        }
        if(key.equals("arraysize") || key.equals("cnt")) {
            printError("Error: must be '" + key + " : NUMBER' , found '" + key + " : STRING'");
        }
        switch(key) {
            case "attr":
                var.setAttr(st);
                break;
            case "type":
                LatType type = typesMap.get(st);
                if(type == null) {
                    printError("Error : unknown type '" + st + "' found ");
                    return;
                }
                var.setType(type);
                break;
            default: printWarning("Warning: unknown variable attribute '" + key + "' ,ignored");
        }
    }
    void parseNumber(JsonNumber number, String key, LatVariable var) {
        Integer num = number.intValue(); // проверить на целое
        if(var == null) {
            printError("Error: pair '" + key + "' : " + num + "' found outside of variable definition");
            return;
        }
        if (key.equals("type_declaration") || key.equals("name") || key.equals("size") || key.equals("bit")) {
            printError("Error: key '" + key + "' found as variable attribute");
            return;
        }
        if(key.equals("attr") || key.equals("type")) {
            printError("Error: must be '" + key + " : STRING' , found '" + key + " : NUMBER'");
        }
        switch(key) {
            case "arraysize":
                var.setArraySize(num);
                break;
            case "cnt":
                var.setCnt(num);
                break;
            default: printWarning("Warning: unknown variable attribute ignored");
        }
    }

    public void setTypes(TreeMap<String, LatType> typesMap) {
        if(typesMap != null) {
            this.typesMap = typesMap;
        }
    }
    public LatVariable parseVariable(JsonObject object, String name) {//}, String attr) {
        LatVariable newVar = new LatVariableImpl();
        newVar.setName(name);
        System.out.println("Variable '" + name + "' created");
        /*if(!attr.equals(null)) {
            newVar.setAttr(attr);
        }*/
        for (String newKey : object.keySet()) {
            navigateTree(object.get(newKey), newKey, newVar);
        }
        newVar.fInalize();
        System.out.println("Variable '" + name + "' finalized");
        return newVar;
    }
    public List<LatVariable> generateVars(JsonValue tree, Map<String, LatType> typesMap){

        if(typesMap == null) return null;

        this.typesMap = typesMap;
        varList = new ArrayList<LatVariable>();

        System.out.println("Variables generation started");
        navigateTree(tree, null, null);
        System.out.println("Variables generation completed");
        return varList;
    }
}

interface OutputBuilder {
    public void generateOutput(FileWriter file, List<LatVariable> varList, Map<String, LatType> typeMap);
}
abstract class OutputBuilderAbstract implements OutputBuilder{
    protected void newLine(FileWriter file, String offset) {
        try {
            file.write("\n" + offset);
        } catch(IOException e) {
            System.out.println("IOException :" + e.getMessage());
        }
    }
    protected void newLine(FileWriter file, String offset, int num) {
        try {
            while(num > 0) {
                file.write("\n" + offset);
                num--;
            }
        } catch(IOException e) {
            System.out.println("IOException :" + e.getMessage());
        }
    }
    protected void assertError(boolean condition, String ifFalse) {
        if(!condition) {
            System.out.println("Error : " + ifFalse);
            while(true){}
        }
    }
}
class CDefineGenerator extends OutputBuilderAbstract {
    public void generateOutput(FileWriter file, List<LatVariable> varList, Map<String, LatType> typeMap) {
        assertError(varList != null && typeMap != null && varList.size() > 0 && typeMap.size() > 0, "can't generate defines, need non 'null' variables list and types map");
        try {
            // generate address defines for each variable, grouped by access attribute
            int address = 0;
            String offset = "";
            newLine(file, offset, 2);
            file.write("/************************************************************/");
            newLine(file, offset);
            file.write(" /************ LAT ************/");
            newLine(file, offset, 2);
            offset += "  ";
            address = printRegionAddrByAttr(file, varList, address, offset, "r_only");
            address += 1000; // reserved
            address = printRegionAddrByAttr(file, varList, address, offset, "rw");
            address += 1000; // reserved
            address = printRegionAddrByAttr(file, varList, address, offset, "rw_root");
            address += 1000; // reserved
            address = printRegionAddrByAttr(file, varList, address, offset, "r0w");
            address += 1000; // reserved
            address = printRegionAddrByAttr(file, varList, address, offset, "r0w_root");
            address += 1000; // reserved
            // generate bit defines for each type
            offset = "";
            newLine(file, offset, 2);
            file.write(" /************ TYPES SIZES DEFINES ************/");
            for(String key : typeMap.keySet()) {
                printSizeFromLatType(file, typeMap.get(key), offset);
            }
            newLine(file, offset, 2);
            file.write(" /************ BIT DEFINES ************/");
            newLine(file, offset, 2);
            for(String key : typeMap.keySet()) {
                printBitDefines(file, typeMap.get(key), offset);
            }
            newLine(file, offset, 2);
            file.write("/************************************************************/");
            // save to disk
            file.flush();
        } catch(IOException e) {
            System.out.println("IOException :" + e.getMessage());
        }
    }
    private Integer printRegionAddrByAttr(FileWriter file, List<LatVariable> varList, Integer address, String offset, String attr) {
        Integer rStartAddr = address;
        Integer rByteSize = 0;
        try {
            newLine(file, offset, 2);
            file.write("/************ " + attr + " region ************/");
            newLine(file, offset);
            for(LatVariable var : varList) { //for(int i = 0; i < varList.size())
                address = generateCAddrFromLatVar(file, var, null, address, offset, attr, null);
            }
            rByteSize = address - rStartAddr;
            newLine(file, offset, 2);
            file.write("#define " + attr + "_REGION_START 0x" + rStartAddr.toHexString(rStartAddr));
            newLine(file, offset);
            file.write("#define " + attr + "_REGION_STOP 0x" + address.toHexString(address));
            newLine(file, offset);
            file.write("#define " + attr + "_REGION_SIZE " + rByteSize.toString());
        } catch(IOException e) {
            System.out.println("IOException :" + e.getMessage());
        }
        return address;
    }
    // сгенерировать и записать адресса, запись только по соответсвию атрибута доступа
    private Integer generateCAddrFromLatVar(FileWriter file, LatVariable var, String define, Integer address,  String offset, String searchAttr, String parentAttr) {
        assertError(var.getChildsNum() != 1, "found variable with 1 child - nonsense");
        if(define == null) {
            define = new String("#define ");
        }
        //var.check();
        if(parentAttr == null && var.getAttr() != null) {
            if(var.getAttr().equals(searchAttr)) {
                parentAttr = var.getAttr();
            } else {
                return address;
            }
        }
        define += var.getName() + "_";
        if (var.getChildsNum() > 0) {
            if(var.getCnt() > 1) {
                for (Integer j = 0; j < var.getCnt(); j++) {
                    for (Integer i = 0; i < var.getChildsNum(); i++) {
                        address = generateCAddrFromLatVar(file, var.getChild(i), define + j.toString() + "_", address, offset, searchAttr, parentAttr);
                    }
                }
            } else {
                for (Integer i = 0; i < var.getChildsNum(); i++) {
                    address = generateCAddrFromLatVar(file, var.getChild(i), define, address, offset, searchAttr, parentAttr);
                }
            }
            return address;
        }
        if(var.getType().getChildsNum() > 0) {
            if(var.getCnt() > 1) {
                for(Integer j = 0; j < var.getCnt(); j++) {
                    for (int i = 0; i < var.getType().getChildsNum(); i++) {
                        address = generateCAddrFromLatVar(file, var.getType().getChild(i), define + j.toString() + "_", address, offset, searchAttr, parentAttr);
                    }
                }
            } else {
                for (int i = 0; i < var.getType().getChildsNum(); i++) {
                    address = generateCAddrFromLatVar(file, var.getType().getChild(i), define, address, offset, searchAttr, parentAttr);
                }
            }
            return address;
        }
        if ((parentAttr != null && parentAttr.equals(searchAttr)) || var.getAttr().equals(searchAttr)) {
            address =  printCAddrFromLatVar(file, var, define, address, offset); // дайю define и var - должен их смешать
        }
        return address;
    }
    private Integer printCAddrFromLatVar(FileWriter file, LatVariable var, String define, Integer address,  String offset) {
        try {
            if(var.getCnt() > 1) {
                for (Integer i = 0; i < var.getCnt(); i++) {
                    newLine(file, offset);
                    if(var.getArraySize() > 1) {
                        file.write(define + i.toString() + "__" + var.getType().getName() + "_" + var.getArraySize().toString() + "  0x" + address.toHexString(address));
                    }
                    else {
                        file.write(define + i.toString() + "__" + var.getType().getName() + "  0x" + address.toHexString(address));
                    }
                    address += var.getSize() / 2;
                }
            } else {
                newLine(file, offset);
                if(var.getArraySize() > 1) {
                    file.write(define + "_" + var.getType().getName() + "_" + var.getArraySize().toString() + "  0x" + address.toHexString(address));
                } else {
                    file.write(define + "_" + var.getType().getName() + "  0x" + address.toHexString(address));
                }
                address += var.getSize() / 2;
            }
        } catch (IOException e) {
            System.out.println("IOException :" + e.getMessage());
        }
        return address;
    }
    private void printSizeFromLatType(FileWriter file, LatType type, String offset) {
        try {
            newLine(file, offset);
            file.write("#define " + type.getName() + "_SIZE 0x" + type.getSize().toHexString(type.getSize()));
            /*for(Integer i = 0; i < type.getChildsNum(); i++) {
                printSizeFromLatType(file, type.getChild(i), offset + " ");

            }*/
        } catch (IOException e) {
            System.out.println("IOException :" + e.getMessage());
        }
    }

    private void printBitDefines(FileWriter file, LatType type, String offset) {
        if(type.getChildsNum() == 0 && type.getBitField(0) != null) {
            newLine(file, offset);
            try {
                file.write("/************ Bit defenitions for type '" + type.getName() + "' ************/");
            } catch(IOException e) {
                System.out.println("IOException :" + e.getMessage());
            }
            int index = 0;
            BitField bf = type.getBitField(index++);
            while (bf != null) { // bit field defines
                printBitField(file, bf, offset + " ");
                bf = type.getBitField(index++);
            }
        }
    }
    private void printBitField(FileWriter file, BitField bf, String offset) {
        try {
            if(bf.size > 1) { // bitfield's discrete bits defines
                newLine(file, offset);
                file.write("#define " + bf.name + "_SIZE ((uint32_t)" + bf.size.toString() + ")");
                newLine(file, offset);
                file.write("#define " + bf.name + "_POS ((uint32_t)" + bf.pos.toString() + ")");
                newLine(file, offset);
                file.write("#define " + bf.name + "_MASK ((uint32_t)" + bf.mask.toString() + ")");
                for (Integer i = 0; i < bf.size; i++) {
                    Integer subBitPos = bf.pos + i;
                    Integer subBitMask = 1 << subBitPos;
                    // вариант без расписания саббитов
                    //newLine(file, offset + "  ");
                    //file.write("#define " + bf.name + "_" + i.toString() + " ((uint32_t)" + subBitMask.toString() + ")");

                    // вариант с расписание саббитов
                    //newLine(file, offset + "  ");
                    //file.write("#define " + bf.name + "_" + i.toString() + "_SIZE ((uint32_t)" + i.toString() + ")");
                    newLine(file, offset + "  ");
                    file.write("#define " + bf.name + "_" + i.toString() + "_POS ((uint32_t)" + subBitPos.toString() + ")");
                    newLine(file, offset + "  ");
                    file.write("#define " + bf.name + "_" + i.toString() + "_MASK ((uint32_t)" + subBitMask.toString() + ")");
                }
            } else {
                // вариант без расписания обиночных битов
                //newLine(file, offset + "  ");
                //file.write("#define " + bf.name + " ((uint32_t)" + bf.mask.toString() + ")");

                // вариант с расписанием обиночных битов
                //newLine(file, offset + "  ");
                //file.write("#define " + bf.name + "_SIZE ((uint32_t)" + bf.size.toString() + ")");
                newLine(file, offset + "  ");
                file.write("#define " + bf.name + "_POS ((uint32_t)" + bf.pos.toString() + ")");
                newLine(file, offset + "  ");
                file.write("#define " + bf.name + "_MASK ((uint32_t)" + bf.mask.toString() + ")");
            }
        } catch(IOException e) {
            System.out.println("IOException :" + e.getMessage());
        }
    }
}

class CTypesGenerator extends OutputBuilderAbstract {
    public void generateOutput(FileWriter file, List<LatVariable> varList, Map<String, LatType> typeMap) {
        assertError(varList.size() != 0, "can't generate defines, variables list is empty");
        // generate types for each variable root
        try {
            String offset = "";
            newLine(file, offset, 2);
            file.write("/********** LAT types **********/");
            newLine(file, offset);
            file.write("/********** types from 'JSON LAT types' **********/");
            for (String type : typeMap.keySet()) {
                printCTypeFromLatType(file, typeMap.get(type), offset + " ");
            }
            newLine(file, offset);
            file.write("/********** types from 'JSON LAT' **********/");
            printRegionTypeByAttr(file, varList, "r_only", offset + " ");
            printRegionTypeByAttr(file, varList, "rw", offset + " ");
            printRegionTypeByAttr(file, varList, "rw_root", offset + " ");
            printRegionTypeByAttr(file, varList, "r0w", offset + " ");
            printRegionTypeByAttr(file, varList, "r0w_root", offset + " ");
            /*newLine(file, offset, 2);
            for (int i = 0; i < varList.size(); i++) {
                printCTypeFromLatVar(file, varList.get(i), "r_only", offset);
                printCTypeFromLatVar(file, varList.get(i), "rw", offset);
                printCTypeFromLatVar(file, varList.get(i), "rw_root", offset);
                printCTypeFromLatVar(file, varList.get(i), "r0w", offset);
                printCTypeFromLatVar(file, varList.get(i), "r0w_root", offset);
            }*/
            file.flush();
        } catch (IOException e) {
            System.out.println("IOException :" + e.getMessage());
        }
    }
    private void printCTypeFromLatType(FileWriter file, LatType type, String offset) {
        if(type.getName().equals("float") ||
           type.getName().equals("uint8_t") ||
           type.getName().equals("uint16_t") ||
           type.getName().equals("uint32_t") ||
           type.getName().equals("int16_t") ||
           type.getName().equals("time_t")) {
            return;
        }
        if(type.getChildsNum() == 0) { // simple type
            printCTypeFromSimpleLatType(file, type, offset + " ");
        } else {                       // type with variables inside
            printCTypeFromComplexLatType(file, type, "r_only", offset + " ");
            printCTypeFromComplexLatType(file, type, "rw", offset + " ");
            printCTypeFromComplexLatType(file, type, "rw_root", offset + " ");
            printCTypeFromComplexLatType(file, type, "r0w", offset + " ");
            printCTypeFromComplexLatType(file, type, "r0w_root", offset + " ");
        }
    }
    private void printCTypeFromSimpleLatType(FileWriter file, LatType type, String offset) {
        try {
            newLine(file, offset);
            assertError(type.getSize() % 2 == 0, "invalid type found (size not multiple of 2!)");
            //assertError(type.getSize() <= 4 , "invalid type found (size > 4 in simple type)");
            switch(type.getSize()) {
                case 2:
                    file.write("typedef uint16_t " + type.getName() + ";");
                    break;
                case 4:
                    file.write("typedef uint32_t " + type.getName() + ";");
                    break;
                default:
            }
            /*if(type.getSize() > 1) {
                file.write("typedef " + type.getName() + " uint8_t[" + type.getSize().toString() + "];");
            } else {
                file.write("typedef " + type.getName() + " uint8_t;");
            }*/
        } catch(IOException e) {
            System.out.println("IOException :" + e.getMessage());
        }
    }
    private void printCTypeFromComplexLatType(FileWriter file, LatType type, String attr, String offset) {

        checkType(file, type, attr, offset, 0);

        if(type.searchAttr(attr) > 0) {
            try {
                newLine(file, offset);
                file.write("__PACKED typedef struct {");
                for(int i = 0; i < type.getChildsNum(); i++) {
                    printCVarFromLatVar(file, type.getChild(i), attr, offset + " ");
                }
                newLine(file, offset);
                if(!type.haveOnly(attr)) {
                    file.write("}" + type.getName() + "__" + attr + " PACKED__;");
                } else {
                    file.write("}" + type.getName() + " PACKED__;");
                }
            } catch(IOException e) {
                System.out.println("IOException :" + e.getMessage());
            }
        }
    }
    // prints C variable if LatVariable's access type equals to 'attr'
    private void checkVar(FileWriter file, LatVariable var, String attr, String offset, int position) {
        if(file == null) {
            int a = 0; }
        if(offset == null) {
            int a = 0; }
        if(attr == null) {
            int a = 0; }
        if(var == null){
            int a = 0; }
        if(var.getCnt() == null){
            int a = 0; }
        if(var.getName() == null){
            int a = 0; }
        if(var.getArraySize() == null){
            int a = 0; }
        if(position != 0 && position != 2) {
            if(var.getAttr() == null){
                int a = 0; }
            if(var.getType() == null){
                int a = 0; }
            if(var.getType().getName() == null){
                int a = 0; }
        }
        //while(var.getType().getChildsNum() == null){ int a = 0; }
    }
    private void checkType(FileWriter file, LatType type, String attr, String offset, int position) {
        if(file == null) {
            int a = 0; }
        if(offset == null) {
            int a = 0; }
        if(attr == null) {
            int a = 0; }
        if(type == null){
            int a = 0; }
        if(type.getName() == null){
            int a = 0; }
        int i = 0;
        while(i < type.getChildsNum()) {
            if (type.getChild(i) == null) {
                int a = 0;
            }
            i++;
        }
    }
    private void printCVarFromLatVar(FileWriter file, LatVariable var, String attr, String offset) {

        //checkVar(file, var, attr, offset, 0);

        if(var.searchAttr(attr) > 0) {
            try {
                String typeName = var.getChildsNum() > 0 ? (var.getName() + "_t") : var.getType().getName();
                if(!var.haveOnly(attr)) {//if (var.getChildsNum() > 0 || var.getType().searchAttr(attr) > 0 && var.getType().haveOnly(attr)) {//if (var.getChildsNum() > 0 || var.getType().searchAttr(attr) > 0) {
                    typeName += "__" + attr;
                }
                Integer i = 0;
                while (i < var.getCnt()) {
                    String varName = var.getName();
                    if (var.getCnt() > 1) { // one variable / set of variables 1,2,3....
                        varName += "_" + i.toString();
                    }
                    if (var.getArraySize() > 1) { // array / not array
                        varName += "[" + var.getArraySize().toString() + "]";
                    }
                    newLine(file, offset);
                    file.write(typeName + " " + varName + ";");
                    i++;
                }
            } catch (IOException e) {
                System.out.println("IOException :" + e.getMessage());
            }
        }
    }

    private void printRegionTypeByAttr(FileWriter file, List<LatVariable> varList, String attr, String offset) {
        try {
            newLine(file, offset);
            file.write("/********** " + attr + " types **********/");
            newLine(file, offset);
            file.write("__PACKED typedef struct {");
            //newLine(file, "  ");
            for (int i = 0; i < varList.size(); i++) {
                printCTypeFromLatVar(file, varList.get(i), attr, offset + "  ");
            }
            newLine(file, offset);
            file.write("}device_t__" + attr + " PACKED__;");
        } catch (IOException e) {
            System.out.println("IOException :" + e.getMessage());
        }
    }
    private void printCTypeFromLatVar(FileWriter file, LatVariable var, String attr, String offset) {
        if(var.searchAttr(attr) > 0) {
            if (var.getChildsNum() == 0) {
                //checkVar(file, var, attr, offset, 1);
                printCVarFromLatVar(file, var, attr, offset);
            } else {
                try {
                    newLine(file, offset);
                    file.write("__PACKED typedef struct {");
                    for(int i = 0; i < var.getChildsNum(); i++) {
                        printCTypeFromLatVar(file, var.getChild(i), attr, offset + "  ");
                    }
                    newLine(file, offset);
                    if(!var.haveOnly(attr)) {
                        file.write("}" + var.getName() + "_t__" + attr + " PACKED__;");
                    } else {
                        file.write("}" + var.getName() + "_t PACKED__;");
                    }
                    //checkVar(file, var, attr, offset, 2);
                    printCVarFromLatVar(file, var, attr, offset);
                    /*newLine(file, offset);
                    if(var.getCnt() > 1) {
                        for(Integer i = 0; i < var.getCnt(); i++) {
                            file.write(var.getName() + "_t" + "__" + attr + " " + var.getName() + "_" + i.toString() + ";");
                        }
                    } else {
                        file.write(var.getName() + "_t" + "__" + attr + " " + var.getName() + ";");
                    }*/
                } catch(IOException e) {
                    System.out.println("IOException :" + e.getMessage());
                }
            }
        }
    }

}
