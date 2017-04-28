
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
            fTypeReader = new FileReader("/home/hp/IdeaProjects/JSON/LAT_types.js");
            fDataReadern = new FileReader("/home/hp/IdeaProjects/JSON/LAT.js");
            fOutputWriter = new FileWriter("/home/hp/IdeaProjects/JSON/LAT_defines.h", true);
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
        dg.generateOutput(fOutputWriter, varList, typeMap);
        tg.generateOutput(fOutputWriter, varList, typeMap);
        while(true){}
    }
}
interface LatObject {
    public boolean setSize(Integer size);
    public boolean setName(String name);
    public int getSerialNum();
    public Integer getSize();
    public String getName();

    //public void setChild(LatObject object);
    //public int getChildsNum();
    //public LatObject getChild(Integer num);

    public boolean fInalize();
}
abstract class LatObjectAbstract implements LatObject {

    protected int serialNum;
    protected String name;
    protected boolean finalized;

    protected LatObjectAbstract(int snum) {
        serialNum = snum;
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
    public boolean addBitDescription(String bitDescription);
    //public String getBitDescription(int bitNum);
    public LatTypeImpl.BitField getBitField(int bitFieldNum);

    public void setChild(LatVariable var);
    public LatVariable getChild(Integer num);
    public int getChildsNum();
}
interface LatVariable extends LatObject {
    public boolean setAttr(String attr);
    public boolean setCnt(Integer cnt);
    public boolean setArraySize(Integer arraysize);
    public boolean setType(LatType type);
    public void setChild(LatVariable var);

    public String getAttr();
    public Integer getCnt();
    public Integer getArraySize();
    public LatType getType();
    public LatVariable getChild(Integer num);
    public int getChildNum();
}
class LatVariableImpl extends LatObjectAbstract implements LatVariable {

    // number of variables in existance
    private static int instanceCnt;
    public static int getInstanceCnt() {
        return instanceCnt;
    }

    // access attribute
    // ignored if child.size() > 0
    String attr;
    // number of variables with that name
    Integer varCnt;
    // array size for a simple type, only
    // used with simple types to generate arrays
    // ignored if child.size() > 0
    Integer arraysize;
    // type description
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
        if(child.size() > 0) {
            printWarning("key 'attr' is ignored");
            return true;
        }
        if(this.attr != null) {
            printError("duplicate key 'attr' found in variable");
            return false;
        }
        if(!attr.equals("r_only") && !attr.equals("rw") && !attr.equals("rw_root") && !attr.equals("r0w") && !attr.equals("r0w_root")) {
            printError("unknown access attribute '" + attr + "' found");
            return false;
        }
        this.attr = attr;
        return true;
    }
    public boolean setCnt(Integer cnt) {
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
        if(child.size() > 0) {
            printWarning("key 'arraysize' is ignored");
            return true;
        }
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
    public boolean setType(LatType type){
        if(child.size() > 0) {
            printWarning("key 'type' is ignored");
            return true;
        }
        if(this.type != null) {
            printError("duplicate definition of key 'type'");
            return false;
        }
        this.type = type;
        for(int i = 0; i < type.getChildsNum(); i++)
        {
            child.add(type.getChild(i));
        }
        return true;
    }
    public void setChild(LatVariable var) {
        if(child.size() > 0) {
            if(type != null) {
                printWarning("key 'type' is ignored");
                type = null;
            }
            if(attr != null) {
                printWarning("key 'attr' is ignored");
                attr = null;
            }
            if(arraysize != null) {
                printWarning("key 'arraysize' is ignored");
                attr = null;
            }
        }
        child.add(var);
    }
    public boolean fInalize() {
        if(finalized) {
            return true;
        }
        if(name == null) {
            printError("incomplete variable - missing 'name' key");
            return false;
        }
        if(child.size() == 0) {
            if(type == null) {
                printError("incomplete variable - missing 'type' key");
                return false;
            }
            if(attr == null) {
                printError("incomplete variable - missing 'attr' key");
                return false;
            }
            if (varCnt == null) {
                printError("incomplete variable - missing 'cnt' key");
                return false;
            }
            if (arraysize == null) {
                printWarning("incomplete variable - missing 'arraysize' key, assumed as 1");
                arraysize = 1;
                return false;
            }
        } else {
            if(type != null) {
                printWarning("key 'type' is ignored at finilization");
                return false;
            }
            if(attr != null) {
                printWarning("key 'attr' is ignored at finilization");
                return false;
            }
            if (varCnt != null) {
                printWarning("key 'cnt' is ignored at finilization");
                return false;
            }
            if (arraysize != null) {
                printWarning("key 'arraysize' is ignored at finilization");
                return false;
            }
        }
        finalized = true;
        return true;
    }

    //public String getName() {
    //    return name;
    //}
    public Integer getSize() {
        int size = 0;
        if(child.size() > 0) {
            for(int i = 0; i < child.size() ; i++) {
                size += child.get(i).getSize();
            }
        } else {
            size = type.getSize() * arraysize * varCnt;
        }
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
    public int getChildNum() {
        return child.size();
    }
    public LatVariable getChild(Integer num){
        return child.get(num);
    }
}
class LatTypeImpl extends LatObjectAbstract implements LatType {

    // number of types in existance
    private static int instanceCnt;
    public static int getInstanceCnt() {
        return instanceCnt;
    }

    class BitField{
        Integer size;
        Integer pos;
        Integer mask;
        String description;
    }

    // type size in bytes
    // set up ignored if childs.size() > 0 (calculated from childs sizes)
    Integer size;
    // bitfield mapping "bitNum : value"
    // ignored if childs.size() > 0
    Map<Integer, BitField> bitMap;
    // num of defined bits
    Integer bitsNum;
    // variables as part of complex type
    List<LatVariable> child;

    LatTypeImpl() {
        super(instanceCnt);

        size = null;
        bitsNum = 0;
        bitMap = new HashMap<Integer, BitField>();
        child = new ArrayList<LatVariable>();
    }

    private void printError(String msg) {
        if(name != null) {
            System.out.println("Error : " + msg + " in type '" + this.name + "'");
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
            printError("attempt to change name of finalized type");// if name = null??
        }
        if(this.name != null) {
            printWarning("duplicate key 'name' found in type declaration");
        }
        this.name = name;
        return true;
    }
    public boolean setSize(Integer size) {
        if(finalized == true) {
            printError("attempt to change size of finalized type" + this.name);// if name = null??
            return false;
        }
        if(child.size() > 0) {
            printWarning("'size' is ignored because complex type calculates it's size by his own");
            return true;
        }
        if(size <= 0) {
            printError("'size' must be a positive integer");
            return false;
        }
        if(this.size != null) {
            printWarning("duplicate key 'size' found in type declaration " + this.name + ", ignored");// if name = null??
        }
        this.size = size;
        return true;
    }
    public boolean addBitDescription(String bitDescription) {
        if(finalized == true) {
            printError("attempt to add bit description to finalized type" + this.name);// if name = null??
            return false;
        }
        if(child.size() > 0) {
            printWarning("bit description ignored in complex type " + this.name);// if name = null??
            return true;
        }
        //if(size == null) {
        //    printError("define key 'size' before 'bit'");
        //   return false;
        //}
        if(size != null)//if(size != null && bitMap.size() > size * 8)
        {
            if(bitsNum >= size * 8) {
                printError("type declaration have more bits descriptions than actual bits available (size * 8)");
                return false;
            }
            if(bitsNum >= 32) {
                printError("type declaration can't have more than 32 bits descriptions");
                return false;
            }
        }
        BitField bitf = null;
        int index = bitMap.size();
        while(index > 0) {
            index--;
            bitf = bitMap.get(index);
            if(bitf.description.equals(bitDescription) && index + 1 == bitMap.size()) {
                int bitMask = 0;
                int bitSize = ++bitf.size;
                while(bitSize > 0) {
                    bitMask |= 1 << bitSize--;
                }
                bitf.mask = bitMask << bitf.pos;
                bitMap.put(index, bitf);
                bitsNum++;
                return true;
            } else {
                printError("dublicate bit description");
                return false;
            }
        }
        bitf = new BitField();
        bitf.size = 1;
        bitf.pos = bitMap.size();
        bitf.mask = 1 << bitf.pos;
        bitf.description = bitDescription;
        bitMap.put(bitMap.size(), bitf);
        bitsNum++;
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
        if(size == null && child.size() == 0) {
            printError("incomplete type - missing size attribute");
            return false;
        }
        if(size * 8 < bitMap.size()) {
            printError("invalid type - have more bit descriptions than available bits");
            return false;
        }
        finalized = true;
        return true;
    }

    public Integer getSize() {
        return size;
    }
    //public String getBitDescription(int bitNum) {
    //    return bitMap.get(bitNum).description;
    //}
    public BitField getBitField(int bitFieldNum) {
        return bitMap.get(bitFieldNum);
    }
    public int getChildsNum() {
        return child.size();
    }
    public LatVariable getChild(Integer num){
        return child.get(num);
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

    //JsonTypeParser(JsonVariableParser parser) {
    //    varParser = parser;
    //}

    void printWarning(String wrMsg) {
        System.out.println(wrMsg);
        while(true){}
    }
    void printError(String errMsg) {
        System.out.println(errMsg);
        //System.out.println("Found in type #" + LatType.getSerialNum());
        while(true){}
    }
    void parseObject(JsonObject object, String key) {
        if(key == null) {
            for (String newKey : object.keySet()) {
                navigateTree(object.get(newKey), newKey);
            }
            return;
        }
        switch(key) {
            case "type_declaration":
                LatType newType = parseType(object);
                if(newType == null) {
                    printError("Error : parseType() returned null");
                } else {
                    String newTypeName = newType.getName();
                    typeMap.put(newTypeName, newType);
                }
                break;
            default:
                    System.out.println("Warning: key" + key + "found outside of 'type_declaration', ignored");
        }
    }

    private void navigateTree(JsonValue tree, String key) {
        if (key != null) {
            System.out.print("Key " + key + ": ");
        }
        switch(tree.getValueType()) {
            case OBJECT:
                System.out.println("OBJECT");
                JsonObject object = (JsonObject) tree;
                parseObject(object, key);
                break;
            case ARRAY:
                System.out.println("ARRAY");
                JsonArray array = (JsonArray) tree;
                for (JsonValue val : array) {
                    navigateTree(val, key);
                }
                break;
            case STRING:
                JsonString st = (JsonString) tree;
                System.out.println("STRING " + st.getString());
                break;
            case NUMBER:
                JsonNumber num = (JsonNumber) tree;
                System.out.println("NUMBER " + num.toString());
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
    private LatType parseType(JsonObject object) {
        LatType newType = new LatTypeImpl();
        for (String newKey : object.keySet()) {
            JsonValue newValue = object.get(newKey);
            JsonValue.ValueType newValueType = newValue.getValueType();
            if (newValueType != NUMBER &&
                newValueType != STRING &&
                newValueType != ARRAY &&
                newValueType != OBJECT) {
                printError("Error: 'type_declaration' object must have only 'key : STRING/NUMBER/OBJECT/ARRAY' pairs");
            }
            if (newKey.equals("attr") || newKey.equals("arraysize") || newKey.equals("cnt") || newKey.equals("type")) {
                printError("Error: " + newKey + " key is not allowed in 'type_declaration' object");
            }
            switch(newKey) {
                case "size":
                    switch(newValueType) {
                        case STRING:
                            printError("Error: must be 'size : NUMBER', found 'size : STRING' ");
                            break;
                        case NUMBER:
                            JsonNumber jnum = (JsonNumber) newValue;
                            if(jnum.isIntegral() == false || jnum.intValue() <= 0) {
                                printError("Error: size must be a positive integer, found " + jnum.toString());
                            } else {
                                newType.setSize(jnum.intValue());
                            }
                            break;
                        case OBJECT:
                            printError("Error: must be 'size : NUMBER', found 'size : OBJECT'");
                            break;
                        case ARRAY:
                            printError("Error: must be 'size : ARRAY', found 'size : OBJECT'");
                            break;
                    }
                    break;
                case "name":
                    switch(newValueType) {
                        case STRING:
                            String st = ((JsonString)newValue).getString();
                            newType.setName(st);
                            break;
                        case NUMBER:
                            printError("Error: must be 'name : STRING', found 'name : NUMBER'");
                            break;
                        case OBJECT:
                            printError("Error: must be 'name : STRING', found 'name : OBJECT'");
                            break;
                        case ARRAY:
                            printError("Error: must be 'name : STRING', found 'name : ARRAY'");
                            break;
                    }
                    break;
                case "bits":
                    switch(newValueType) {
                        case STRING:
                            printError("Error: must be 'bits : ARRAY', found 'bits : STRING'");
                            break;
                        case NUMBER:
                            printError("Error: must be 'bits : ARRAY', found 'bits : NUMBER'");
                            break;
                        case OBJECT:
                            printError("Error: must be 'bits : ARRAY', found 'bits : OBJECT'");
                            break;
                        case ARRAY:
                            JsonArray array = (JsonArray) newValue;
                            for (JsonValue val : array) {
                                if(val.getValueType() != STRING) {
                                    printError("Error: must be 'bits : ARRAY' of strings");
                                }
                                newType.addBitDescription(((JsonString)val).getString());
                            }
                            break;
                    }
                    break;
                default: // is child variable name
                    JsonObject newObject = (JsonObject) newValue;
                    if(varParser == null)  {
                        printError("Error: type parser found a variable but have no variable parser!");
                        break;
                    }
                    varParser.setTypes(typeMap); // set up new types
                    LatVariable newVar = varParser.parseVariable(newObject, newKey);
                    newType.setChild(newVar);
            }
            /*switch(newValueType) {
                case STRING:
                    String st = ((JsonString)newValue).getString();
                    switch (newKey) {
                        case "size":
                            printError("Error: must be 'size : NUMBER', found 'size : STRING' ");
                            break;
                        case "name":
                            newType.setName(st);
                            break;
                        case "bit":
                            newType.addBitDescription(st);
                            break;
                        default: printError("Error: unknown key found");
                    }
                    break;
                case NUMBER:
                    JsonNumber jnum = (JsonNumber) newValue;
                    switch (newKey) {
                        case "size":
                            if(jnum.isIntegral() == false || jnum.intValue() <= 0) {
                                printError("Error: size must be a positive integer");
                            } else {
                                newType.setSize(jnum.intValue());
                            }
                            break;
                        case "name":
                            printError("Error: must be 'name : STRING', found 'name : NUMBER' ");
                            break;
                        case "bit":
                            printError("Error: must be 'bit : STRING', found 'bit : NUMBER' ");
                            break;
                        default: printError("Error: unknown key found");
                    }
                    break;
                case OBJECT:
                    if(newKey.equals("size") || newKey.equals("name") || newKey.equals("bit")) {
                        printError("Error: key pair '" + newKey + " : OBJECT' is not allowed (must be NUMBER or STRING)");
                        break;
                    }
                    JsonObject newObject = (JsonObject) newValue;
                    if(varParser == null)  {
                        printError("Error: type parser found a variable but have no variable parser!");
                        break;
                    }
                    varParser.setTypes(typeMap); // set up new types
                    LatVariable newVar = varParser.parseVariable(newObject, newKey);
                    newType.setChild(newVar);
                    break;
                case ARRAY:
            }
        }*/
        newType.fInalize();
        return newType;
    }

    public TreeMap<String, LatType> generateTypes(JsonValue tree, JsonVariableParser parser) {
        if(tree == null) {
            printError("Error : JSON tree not found");
            return null;
        }
        if(parser == null) {
            printError("Error : JSON variable parser not found");
            return null;
        }
        typeMap = new TreeMap<String, LatType>();
        varParser = parser;
        System.out.println("Types generation started");
        navigateTree(tree, null);
        System.out.println("Types generation completed");
        return typeMap;
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
        if(key != null) {
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
        } else {
            for (String newKey : object.keySet()) {
                navigateTree(object.get(newKey), newKey, parent);
            }
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
    public LatVariable parseVariable(JsonObject object, String name) {
        LatVariable newVar = new LatVariableImpl();
        newVar.setName(name);

        for (String newKey : object.keySet()) {
            navigateTree(object.get(newKey), newKey, newVar);
        }
        newVar.fInalize();
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
}

class CDefineGenerator extends OutputBuilderAbstract {
    public void generateOutput(FileWriter file, List<LatVariable> varList,  Map<String, LatType> typeMap) {
        if(varList == null || typeMap == null || varList.size() == 0 || typeMap.size() == 0) {
            System.out.println("Error : can't generate defines, need non 'null' variables list and types map");
        }
        try {
            // generate address defines for each variable root / grouped by access attribute
            int lastAddr = 0;
            file.write(" \n \n /************ R_ONLY region ************/ \n \n");
            for (int i = 0; i < varList.size(); i++) {
                lastAddr = generateAddressDefines(file, varList.get(i), null, lastAddr, "r_only");
            }
            file.write(" \n \n /************ RW region ************/ \n \n");
            for (int i = 0; i < varList.size(); i++) {
                lastAddr = generateAddressDefines(file, varList.get(i), null, lastAddr, "rw");
            }
            file.write(" \n \n /************ RW_ROOT region ************/ \n \n");
            for (int i = 0; i < varList.size(); i++) {
                lastAddr = generateAddressDefines(file, varList.get(i), null, lastAddr, "rw_root");
            }
            file.write(" \n \n /************ R0W_ROOT region ************/ \n \n");
            for (int i = 0; i < varList.size(); i++) {
                lastAddr = generateAddressDefines(file, varList.get(i), null, lastAddr, "r0w");
            }
            file.write(" \n \n /************ RW_ROOT region ************/ \n \n");
            for (int i = 0; i < varList.size(); i++) {
                lastAddr = generateAddressDefines(file, varList.get(i), null, lastAddr, "r0w_root");
            }
            // generate bit defines for each type
            file.write(" \n \n /************ BIT DEFINES ************/ \n \n");
            for(String key : typeMap.keySet()) {
                generateBitDefines(file, typeMap.get(key));
            }
            file.flush();
        } catch(IOException e) {
            System.out.println("IOException :" + e.getMessage());
        }
    }

    private int generateAddressDefines(FileWriter file, LatVariable var, String define, Integer address, String attr) {
        if(var.getChildNum() == 1) {
            while(true){}
        }
        if(define == null) {
            define = new String("#define ");
        }
        define += var.getName() + "_";// if(var.getName() != null) define += var.getName() + "_";// root have 'null' name
        if(var.getChildNum() > 1) {
            for (Integer i = 0; i < var.getChildNum(); i++) {
                address = generateAddressDefines(file, var.getChild(i), define, address, attr);
            }
            return address;
        }
        if(var.getAttr().equals(attr)) {
            define += "_" + var.getType().getName();
            try {
                file.write(define + "  0x" + address.toHexString(address.intValue()) + "\n");
            } catch (IOException e) {
                System.out.println("IOException :" + e.getMessage());
            }
            address += var.getSize();
        }
        return address;
    }
    private void generateBitDefines(FileWriter file, LatType type) {
        if(type.getChildsNum() == 0) {
            newLine(file, "");
            try {
                file.write("/************ Bit defenitions for type '" + type.getName() + "' ************/");
                int index = 0;
                LatTypeImpl.BitField bf = type.getBitField(index++);
                while (bf != null) { // bit field defines
                    newLine(file, "");
                    file.write("#define " + bf.description + "_SIZE " + bf.size.toString());
                    newLine(file, "");
                    file.write("#define " + bf.description + "_POS " + bf.pos.toString());
                    newLine(file, "");
                    file.write("#define " + bf.description + "_MASK " + bf.mask.toString());
                    if(bf.size > 1) { // bitfield's discrete bits defines
                        for(Integer i = 0; i < bf.size; i++) {
                            Integer subBitMask = 1 << (bf.pos + i);
                            newLine(file, "  ");
                            file.write("#define " + bf.description + "_" + i.toString() + " " + subBitMask.toString());
                        }
                    }
                    bf = type.getBitField(index++);
                }
            } catch(IOException e) {
                System.out.println("IOException :" + e.getMessage());
            }
        }
    }
}

class CTypesGenerator extends OutputBuilderAbstract {
    public void generateOutput(FileWriter file, List<LatVariable> vars, Map<String, LatType> typeMap) {
        if(vars.size() == 0) {
            System.out.println("Error : can't generate defines, need non 'null' variables list");
        }
        // generate types for each variable root
        // should now current file line offset ???
        try {
            ///////
            newLine(file, "");
            file.write("/********** R_ONLY Types **********/");
            newLine(file, "");
            file.write("typedef struct {");
            newLine(file, "  ");
            for (int i = 0; i < vars.size(); i++) {
                generateType(file, vars.get(i), "  ", "r_only");
            }
            newLine(file, "");
            file.write("}device__r_only_t;");
            ///////
            newLine(file, "");
            file.write("/********** RW Types **********/");
            newLine(file, "");
            file.write("typedef struct {");
            newLine(file, "  ");
            for (int i = 0; i < vars.size(); i++) {
                generateType(file, vars.get(i), "  ", "rw");
            }
            newLine(file, "");
            file.write("}device__rw_t;");
            ///////
            newLine(file, "");
            file.write("/********** RW_ROOT Types **********/");
            newLine(file, "");
            file.write("typedef struct {");
            newLine(file, "  ");
            for (int i = 0; i < vars.size(); i++) {
                generateType(file, vars.get(i), "  ", "rw_root");
            }
            file.write("}device__rw_root_t;");

            newLine(file, "");
            file.write("/********** R0W Types **********/");
            newLine(file, "");
            file.write("typedef struct {");
            newLine(file, "  ");
            for (int i = 0; i < vars.size(); i++) {
                generateType(file, vars.get(i), "  ", "r0w");
            }
            file.write("}device__r0w_t;");
            ///////
            newLine(file, "");
            file.write("/********** R0W_ROOT Types **********/");
            newLine(file, "");
            file.write("typedef struct {");
            newLine(file, "  ");
            for (int i = 0; i < vars.size(); i++) {
                generateType(file, vars.get(i), "  ", "r0w_root");
            }
            file.write("}device__r0w_root_t;");
            ///////
            file.flush();
        } catch (IOException e) {
            System.out.println("IOException :" + e.getMessage());
        }
    }
    private void generateType(FileWriter file, LatVariable var, String offset, String attr) {
        if(offset == null) {
            offset = new String();
        }
        try {
            if(var.getChildNum() > 0) {
                file.write("typedef struct {");
                for(int i = 0; i < var.getChildNum(); i++) {
                    newLine(file, offset + "  ");
                    generateType(file, var.getChild(i), offset + "  ", attr);
                }
                newLine(file, offset);
                file.write("}" + var.getName() + "__" + attr + "_t;");
                newLine(file, offset);
                file.write(var.getName() + "_t " + " + " + var.getName() + ";");
                return;
            }
            if(attr == var.getAttr()) {
                file.write(var.getType().getName() + " - " + var.getName() + ";");
            }
        } catch(IOException e) {
            System.out.println("IOException :" + e.getMessage());
        }
    }
    /*private void write(String string) {
        try {
            file.write("\n" + offset);
        } catch(IOException e) {
            System.out.println("IOException :" + e.getMessage());
        }
    }*/
}
/* Old
interface LatType extends LatObject {
    public void addChild(VarComposite var);
    public LatVariable getChild(Integer num); //public VarComposite getChild(Integer num);
    public int getChildsNum();
    public boolean setName(String name);
    public String getName();
    public boolean setSize(Integer _size);
    public Integer getSize();
    public boolean addBitDescription(String bitDescription);
    public String getBitDescription(int bitNum);
    public boolean fInalize();
}
interface LatVariable {

    public boolean setName(String name);
    public boolean setAttr(String attr);
    public boolean setCnt(Integer cnt);
    public boolean setArraySize(Integer arraysize);
    public boolean setType(TypeComposite type);
    public void addChild(VarComposite var);

    public Integer getSize();
}
class VarComposite implements LatVariable {

    // number of types in existance
    private static int instanceCnt;
    public static int getInstanceCnt() {
        return instanceCnt;
    }

    // instance serial num
    int serialNum;
    // if true - no changes allowed
    boolean finalized;
    String name;
    // access attributeDefineGenerator
    // ignored if child.size() > 0
    String attr;
    // number of variables with that name
    Integer varCnt;
    // used with simple types to generate arrays
    // ignored if child.size() > 0
    Integer arraysize;
    // type description
    // ignored if childs.size() > 0
    TypeComposite type;
    List<VarComposite> child;

    VarComposite(){
        instanceCnt++;
        serialNum = instanceCnt;
        finalized = false;
        name = null;
        attr = null;
        varCnt = null;
        arraysize = null;
        type = null;
        child = new ArrayList<VarComposite>();
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
        if(this.name != null){
            printError("duplicate key 'name'");
            return false;
        }
        this.name = name;
        return true;
    }
    public boolean setAttr(String attr){
        if(child.size() > 0) {
            printWarning("key 'attr' is ignored");
            return true;
        }
        if(this.attr != null) {
            printError("duplicate key 'attr' found in variable");
            return false;
        }
        if(!attr.equals("r_only") && !attr.equals("rw") && !attr.equals("rw_root") && !attr.equals("r0w") && !attr.equals("r0w_root")) {
            printError("unknown access attribute '" + attr + "' found");
            return false;
        }
        this.attr = attr;
        return true;
    }
    public boolean setCnt(Integer cnt) {
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
        if(child.size() > 0) {
            printWarning("key 'arraysize' is ignored");
            return true;
        }
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
    public boolean setType(TypeComposite type){
        if(child.size() > 0) {
            printWarning("key 'type' is ignored");
            return true;
        }
        if(this.type != null) {
            printError("duplicate definition of key 'type'");
            return false;
        }
        this.type = type;
        for(int i = 0; i < type.getChildsNum(); i++)
        {
            child.add(type.getChild(i));
        }
        return true;
    }
    public void addChild(VarComposite var) {
        if(child.size() > 0) {
            if(type != null) {
                printWarning("key 'type' is ignored");
                type = null;
            }
            if(attr != null) {
                printWarning("key 'attr' is ignored");
                attr = null;
            }
            if(arraysize != null) {
                printWarning("key 'arraysize' is ignored");
                attr = null;
            }
        }
        child.add(var);
    }
    public boolean fInalize() {
        if(finalized) {
            return true;
        }
        if(name == null) {
            printError("incomplete variable - missing 'name' key");
            return false;
        }
        if (varCnt == null) {
            printError("incomplete variable - missing 'cnt' key");
            return false;
        }
        if(child.size() == 0) {
            if(type == null) {
                printError("incomplete variable - missing 'type' key");
                return false;
            }
            if(attr == null) {
                printError("incomplete variable - missing 'attr' key");
                return false;
            }
            if (arraysize == null) {
                printError("incomplete variable - missing 'arraysize' key");
                return false;
            }
        } else {
            if(type != null) {
                printWarning("key 'type' is ignored at finilization");
                return false;
            }
            if(attr != null) {
                printWarning("key 'attr' is ignored at finilization");
                return false;
            }
            if (arraysize != null) {
                printWarning("key 'arraysize' is ignored at finilization");
                return false;
            }
        }
        finalized = true;
        return true;
    }

    public String getName() {
        return name;
    }
    public Integer getSize() {
        int size = 0;
        if(child.size() > 0) {
            for(int i = 0; i < child.size() ; i++) {
                size += child.get(i).getSize();
            }
        } else {
            size = type.getSize() * arraysize * varCnt;
        }
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
    public TypeComposite getType() {
        return type;
    }
    public Integer getChildNum() {
        return child.size();
    }
    public VarComposite getChild(Integer num){
        return child.get(num);
    }
}
//class NodeVar extends VarComposite
//class LeaveVar extends LatVariable
class TypeComposite implements LatType {

    // number of types in existance
    private static int instanceCnt;
    public static int getInstanceCnt() {
        return instanceCnt;
    }

    int serialNum
    boolean finalized;
    // type name
    String name;
    // type size in bytes
    // set up ignored if childs.size() > 0 (calculated from childs sizes)
    Integer size;
    // bit mapping "bitNum : value"
    // ignored if childs.size() > 0
    Map<Integer, String> bitMap;
    // variables as part of complex type
    List<VarComposite> child;

    TypeComposite() {
        instanceCnt++;
        finalized = false;
        name = null;
        size = null;
        bitMap = new HashMap<Integer, String>();
        child = new ArrayList<VarComposite>();
    }

    private void printError(String msg) {
        if(name != null) {
            System.out.println("Error : " + msg + " in type '" + this.name + "'");
        } else {
            System.out.println("Error : " + msg + " in type # " + typesCnt);
        }
        while(true){}
    }
    private void printWarning(String msg) {
        if(name != null) {
            System.out.println("Warning : " + msg + ", found in type '" + this.name + "'");
        } else {
            System.out.println("Warning : " + msg + ", found in type # " + typesCnt);
        }
    }

    public void addChild(VarComposite var) {
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
            printError("attempt to change name of finalized type");// if name = null??
        }
        if(this.name != null) {
            printWarning("duplicate key 'name' found in type declaration");
        }
        this.name = name;
        return true;
    }
    public boolean setSize(Integer size) {
        if(finalized == true) {
            printError("attempt to change size of finalized type" + this.name);// if name = null??
            return false;
        }
        if(child.size() > 0) {
            printWarning("'size' is ignored because complex type calculates it's size by his own");
            return true;
        }
        if(size <= 0) {
            printError("'size' must be a positive integer");
            return false;
        }
        if(this.size != null) {
            printWarning("duplicate key 'size' found in type declaration " + this.name + ", ignored");// if name = null??
        }
        this.size = size;
        return true;
    }
    public boolean addBitDescription(String bitDescription) {
        if(finalized == true) {
            printError("attempt to add bit description to finalized type" + this.name);// if name = null??
            return false;
        }
        if(child.size() > 0) {
            printWarning("bit description ignored in complex type " + this.name);// if name = null??
            return true;
        }
        //if(size == null) {
        //    printError("define key 'size' before 'bit'");
        //   return false;
        //}
        if(size != null && bitMap.size() > size * 8)
        {
            printError("type declaration have more bits descriptions than actual bits available (size * 8)");
            return false;
        }
        bitMap.put(bitMap.size(), bitDescription);
        return true;
    }
    public boolean fInalize() {
        if(finalized) {
            return true;
        }
        if(name == null) {
            printError("incomplete type - missing name attribute");
            return false;
 class VarComposite implements LatVariable {

    // number of types in existance
    private static int instanceCnt;
    public static int getInstanceCnt() {
        return instanceCnt;
    }

    // instance serial num
    int serialNum;
    // if true - no changes allowed
    boolean finalized;
    String name;
    // access attributeDefineGenerator
    // ignored if child.size() > 0
    String attr;
    // number of variables with that name
    Integer varCnt;
    // used with simple types to generate arrays
    // ignored if child.size() > 0
    Integer arraysize;
    // type description
    // ignored if childs.size() > 0
    TypeComposite type;
    List<VarComposite> child;

    VarComposite(){
        instanceCnt++;
        serialNum = instanceCnt;
        finalized = false;
        name = null;
        attr = null;
        varCnt = null;
        arraysize = null;
        type = null;
        child = new ArrayList<VarComposite>();
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
        if(this.name != null){
            printError("duplicate key 'name'");
            return false;
        }
        this.name = name;
        return true;
    }
    public boolean setAttr(String attr){
        if(child.size() > 0) {
            printWarning("key 'attr' is ignored");
            return true;
        }
        if(this.attr != null) {
            printError("duplicate key 'attr' found in variable");
            return false;
        }
        if(!attr.equals("r_only") && !attr.equals("rw") && !attr.equals("rw_root") && !attr.equals("r0w") && !attr.equals("r0w_root")) {
            printError("unknown access attribute '" + attr + "' found");
            return false;
        }
        this.attr = attr;
        return true;
    }
    public boolean setCnt(Integer cnt) {
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
        if(child.size() > 0) {
            printWarning("key 'arraysize' is ignored");
            return true;
        }
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
    public boolean setType(TypeComposite type){
        if(child.size() > 0) {
            printWarning("key 'type' is ignored");
            return true;
        }
        if(this.type != null) {
            printError("duplicate definition of key 'type'");
            return false;
        }
        this.type = type;
        for(int i = 0; i < type.getChildsNum(); i++)
        {
            child.add(type.getChild(i));
        }
        return true;
    }
    public void addChild(VarComposite var) {
        if(child.size() > 0) {
            if(type != null) {
                printWarning("key 'type' is ignored");
                type = null;
            }
            if(attr != null) {
                printWarning("key 'attr' is ignored");
                attr = null;
            }
            if(arraysize != null) {
                printWarning("key 'arraysize' is ignored");
                attr = null;
            }
        }
        child.add(var);
    }
    public boolean fInalize() {
        if(finalized) {
            return true;
        }
        if(name == null) {
            printError("incomplete variable - missing 'name' key");
            return false;
        }
        if (varCnt == null) {
            printError("incomplete variable - missing 'cnt' key");
            return false;
        }
        if(child.size() == 0) {
            if(type == null) {
                printError("incomplete variable - missing 'type' key");
                return false;
            }
            if(attr == null) {
                printError("incomplete variable - missing 'attr' key");
                return false;
            }
            if (arraysize == null) {
                printError("incomplete variable - missing 'arraysize' key");
                return false;
            }
        } else {
            if(type != null) {
                printWarning("key 'type' is ignored at finilization");
                return false;
            }
            if(attr != null) {
                printWarning("key 'attr' is ignored at finilization");
                return false;
            }
            if (arraysize != null) {
                printWarning("key 'arraysize' is ignored at finilization");
                return false;
            }
        }
        finalized = true;
        return true;
    }

    public String getName() {
        return name;
    }
    public Integer getSize() {
        int size = 0;
        if(child.size() > 0) {
            for(int i = 0; i < child.size() ; i++) {
                size += child.get(i).getSize();
            }
        } else {
            size = type.getSize() * arraysize * varCnt;
        }
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
    public TypeComposite getType() {
        return type;
    }
    public Integer getChildNum() {
        return child.size();
    }
    public VarComposite getChild(Integer num){
        return child.get(num);
    }
}
//class NodeVar extends VarComposite
//class LeaveVar extends LatVariable
class TypeComposite implements LatType {

    // number of types in existance
    private static int instanceCnt;
    public static int getInstanceCnt() {
        return instanceCnt;
    }

    int serialNum
    boolean finalized;
    // type name
    String name;
    // type size in bytes
    // set up ignored if childs.size() > 0 (calculated from childs sizes)
    Integer size;
    // bit mapping "bitNum : value"
    // ignored if childs.size() > 0
    Map<Integer, String> bitMap;
    // variables as part of complex type
    List<VarComposite> child;

    TypeComposite() {
        instanceCnt++;
        finalized = false;
        name = null;
        size = null;
        bitMap = new HashMap<Integer, String>();
        child = new ArrayList<VarComposite>();
    }

    private void printError(String msg) {
        if(name != null) {
            System.out.println("Error : " + msg + " in type '" + this.name + "'");
        } else {
            System.out.println("Error : " + msg + " in type # " + typesCnt);
        }
        while(true){}
    }
    private void printWarning(String msg) {
        if(name != null) {
            System.out.println("Warning : " + msg + ", found in type '" + this.name + "'");
        } else {
            System.out.println("Warning : " + msg + ", found in type # " + typesCnt);
        }
    }

    public void addChild(VarComposite var) {
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
            printError("attempt to change name of finalized type");// if name = null??
        }
        if(this.name != null) {
            printWarning("duplicate key 'name' found in type declaration");
        }
        this.name = name;
        return true;
    }
    public boolean setSize(Integer size) {
        if(finalized == true) {
            printError("attempt to change size of finalized type" + this.name);// if name = null??
            return false;
        }
        if(child.size() > 0) {
            printWarning("'size' is ignored because complex type calculates it's size by his own");
            return true;
        }
        if(size <= 0) {
            printError("'size' must be a positive integer");
            return false;
        }
        if(this.size != null) {
            printWarning("duplicate key 'size' found in type declaration " + this.name + ", ignored");// if name = null??
        }
        this.size = size;
        return true;
    }
    public boolean addBitDescription(String bitDescription) {
        if(finalized == true) {
            printError("attempt to add bit description to finalized type" + this.name);// if name = null??
            return false;
        }
        if(child.size() > 0) {
            printWarning("bit description ignored in complex type " + this.name);// if name = null??
            return true;
        }
        //if(size == null) {
        //    printError("define key 'size' before 'bit'");
        //   return false;
        //}
        if(size != null && bitMap.size() > size * 8)
        {
            printError("type declaration have more bits descriptions than actual bits available (size * 8)");
            return false;
        }
        bitMap.put(bitMap.size(), bitDescription);
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
        if(size == null && child.size() == 0) {
            printError("incomplete type - missing size attribute");
            return false;
        }
        if(size * 8 < bitMap.size()) {
            printError("invalid type - have more bit descriptions than available bits");
            return false;
        }
        finalized = true;
        return true;
    }


    public String getName(){
        return name;
    }
    public Integer getSize() {
        return size;
    }
    public String getBitDescription(int bitNum) {
        return bitMap.get(bitNum);
    }
    public int getChildsNum() {
        return child.size();
    }
    public VarComposite getChild(Integer num){
        return child.get(num);
    }
}       }
        if(size == null && child.size() == 0) {
            printError("incomplete type - missing size attribute");
            return false;
        }
        if(size * 8 < bitMap.size()) {
            printError("invalid type - have more bit descriptions than available bits");
            return false;
        }
        finalized = true;
        return true;
    }


    public String getName(){
        return name;
    }
    public Integer getSize() {
        return size;
    }
    public String getBitDescription(int bitNum) {
        return bitMap.get(bitNum);
    }
    public int getChildsNum() {
        return child.size();
    }
    public VarComposite getChild(Integer num){
        return child.get(num);
    }
}




*/
/* Twice old
class TypeComposite implements LatType{

    // number of types in existance
    private static int typesCnt;
    public static int getTypesCnt() {
        return typesCnt;
    }

    // type name
    String name;
    // type size in bytes
    // set up ignored if childs.size() > 0 (calculated from childs sizes)
    Integer size;
    // bit mapping "bitNum : value"
    // ignored if childs.size() > 0
    Map<Integer, String> bitMap;
    // variables as part of complex type
    List<VarComposite> child;

    TypeComposite() {
        typesCnt++;

        //complex = false;
        name = null;
        size = null;
        bitMap = new HashMap<Integer, String>();
        child = new ArrayList<VarComposite>();
    }

    private void printError(String msg) {
        System.out.println(msg);
        System.out.println("Found in type # " + typesCnt);
        while(true){}
    }
    private void printWarning(String msg) {
        System.out.println(msg);
        System.out.println("Found in type # " + typesCnt + "/n");
    }
    public void addChild(VarComposite var) {
        if(child.size() == 0 && size != null) {
            printWarning("Warning: 'size' is ignored because complex type calculates it's size by his own");
            size = null;
        }
        if(size == null) {
            size = 0;
        }
        size += var.getSize();
        child.add(var);
    }
    public VarComposite getChild(Integer num){
        return child.get(num);
    }
    public int getChildsNum() {
        return child.size();
    }
    public boolean setName(String name) {
        if(this.name != null){
            printError("Error: duplicate key 'name' found in type declaration");
            return false;
        }
        this.name = name;
        return true;
    }
    public String getName(){
        return name;
    }
    public boolean setSize(Integer _size) {
        if(child.size() > 0) {
            printWarning("Warning: 'size' is ignored because complex type calculates it's size by his own");
            return true;
        }
        if(this.size != null) {
            printError("Error: duplicate key 'size' is not allowed in type declaration");
            return false;
        }
        if(_size <= 0) {
            printError("Error: 'size' must be a positive integer");
            return false;
        }
        this.size = _size;
        return true;
    }
    public Integer getSize() {
        return size;
    }
    public boolean addBitDescription(String bitDescription) {
        //if(child.size() > 0) {printError("Error: size must be a positive integer");
        //    printError("Error: complex type must not have bit descriptions");
        //}
        if(size == null) {
            printError("Error: paste 'size' key before 'bit' keys");
            return false;
        }
        if(bitMap.size() >= size * 8)
        {
            printError("Error: type declaration have more bits descriptions than actual bits availiable (size * 8)");
            return false;
        }
        bitMap.put(bitMap.size(), bitDescription);
        return true;
    }
    public String getBitDescription(int bitNum) {
        return bitMap.get(bitNum);
    }
}*/


    /*private VarComposite generateVars(JsonObject object, Map<String, TypeComposite> typesMap) {
        VarComposite var = new VarComposite();
        for (String newKey : object.keySet()) {
            JsonValue newValue = object.get(newKey);
            JsonValue.ValueType newValueType = newValue.getValueType();
            if (newValueType != NUMBER && newValueType != STRING && newValueType != OBJECT) {
                printError("Error: 'variable' object must have only 'key : STRING/NUMBER/OBJECT' pairs");
            }
            if(newKey == "type_declaration" || newKey == "size" || newKey == "name" || newKey == "bit") {
                printError("Error: " + newKey + " key is not allowed in 'variable' object");
            }
            switch(newValueType) {
                case STRING:
                    String st = ((JsonString)newValue).toString();
                    switch (newKey) {
                        case "name":
                            var.setName(st);
                            break;
                        case "attr":
                            if(newKey != "r_only" && newKey != "rw" && newKey != "rw_root" &&
                                    newKey != "r0w" && newKey != "r0w_root") {
                                printError("Error: unknown access attribute found: " + newKey);
                            }
                            var.setAttr(st);
                            break;
                        case "arraysize":
                            printError("Error: should be 'arraysize : NUMBER', found 'arraysize : STRING' ");
                            break;
                        case "cnt":
                            printError("Error: should be 'cnt : NUMBER', found 'cnt : STRING' ");
                            break;
                        case "type":
                            TypeComposite type = typesMap.get(st);
                            if(type == null) {
                                printError("Error: unknown type found: " + st);
                            } else {
                                var.setType(type);
                            }
                            break;
                    }
                case NUMBER:
                    JsonNumber jnum = (JsonNumber) newValue;
                    switch (newKey) {
                        case "attr":
                            printError("Error: should be 'attr : STRING', found 'attr : NUMBER' ");
                            break;
                        case "arraysize":
                            if(jnum.isIntegral() == false || jnum.intValue() <= 0) {
                                printError("Error: arraysize must be a pJsonObject newObject = (JsonObject) newValue;ositive integer");
                            } else {
                                var.setArraySize(jnum.intValue());
                            }
                        case "cnt":
                            if(jnum.isIntegral() == false || jnum.intValue() <= 0) {
                                printError("Error: arraysize must be a positive integer");
                            }
                            var.setCnt(jnum.intValue());
                        case "type":
                            printError("Error: should be 'type : STRING', found 'type : NUMBER' ");
                            break;
                    }
                case OBJECT:
                    if(newKey == "attr" || newKey == "arraysize" || newKey == "cnt" || newKey == "type") {
                        printError("Error: key pair '" + newKey + " : OBJECT' is not allowed (must be NUMBER or STRING)");
                        break;
                    }
                    JsonObject newObject = (JsonObject) newValue;
                    VarComposite newVar = parseVariable(newObject, null);
                    newVar.setName(newKey);
                    var.addChild(newVar);
            }
        }
    }*/
    /*
    static void parseObject(JsonObject object, String key, typeParserState state, TypeComposite type) {
        switch(state) {
            case TYPE_KEY_SEARCH:
                switch(key) {
                    case "type_declaration":
                        state = typeParserState.TYPE_PARSE;
                        typesDeclFound++;
                        TypeComposite newType = new TypeComposite();
                        for (String newKey : object.keySet()) {
                            //navigateTree(object.get(newKey), newKey, state, newType);
                        }
                        state = typeParserState.TYPE_KEY_SEARCH;
                        break;
                    case null:
                        foSystem.out.println("Found in '" + name + "' /n");r (String newKey : object.keySet()) {
                            navigateTree(object.get(newKey), newKey, state);
                        }
                        break;
                    default: System.out.println("Warning: key" + key + "found outside of 'type_declaration', ignored");
                }
            case TYPE_PARSE:
                System.out.println("Error: value of key 'type_declaration' #" + typesDeclFound + "must not have an object inside");
                while (true) {}// fixme
                break;
        }
    }
    static void parseArray(JsonArray array, String key, typeParserState state, TypeComposite type) {
        switch(state) {
            case TYPE_KEY_SEARCH:
                for (JsonValue val : array) {
                    navigateTree(val, null, state);
                }
                break;
            case TYPE_PARSE:
                System.out.println("Error: key 'type_declaration' #" + typesDeclFound + "must not have an array inside");
                while (true) {}// fixme
                break;
        }
    }*/

