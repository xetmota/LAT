#ifndef __COMPILER_DEFINES
#define __COMPILER_DEFINES_H

#if   defined ( __CC_ARM )

  #define __PACKED    // edit
  #define PACKED__    // edit

#elif defined ( __ICCARM__ )

  #define __PACKED    __packed
  #define PACKED__    //empty line

#elif defined ( __GNUC__ )

  #define __PACKED    //empty line
  #define PACKED__    __attribute__((packed))

#endif

#endif






