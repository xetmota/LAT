/*
TODO:

1. Ввести знаковые, без знаковые целочисленные типы. Сейчас только WORD, HWORD, BYTE

       SIZE IN BYTE AND ALWAYS Multiples 2
          ADDR IN ADDR_EVERY_WORD AS MODBUS

//        ABRIVIATURE

// RD - RADIATION DETECTOR

*/


#ifndef __LAT_H
#define __LAT_H


//#include "stdint.h"


//#define USE__LAT_TYPES   1

//#if USE__LAT_TYPES == 1
#include "LAT_types.h"
//#endif

#define BYTE             1
#define HWORD            2
#define WORD             4
#define FLOAT            4


/*********         LOGIC ADDRESSES TABLE MODBUS    TABLE        ************/

/*        READ ONLY DATA      */

#define   DEVICE_HASH_REFERENCE_VALUE             0
#define   DEVICE_HASH_REFERENCE_VALUE_SIZE        512 * BYTE

/***************************************************************************/
/***************************************************************************/

#define   DEVICE_HASH_CALCULATED_VALUE             DEVICE_HASH_REFERENCE_VALUE + DEVICE_HASH_REFERENCE_VALUE_SIZE/2
#define   DEVICE_HASH_CALCULATED_VALUE_SIZE        512 * BYTE

/***************************************************************************/
/***************************************************************************/

#define   DEVICE_HASH_LENTH             DEVICE_HASH_CALCULATED_VALUE + DEVICE_HASH_CALCULATED_VALUE_SIZE/2
#define   DEVICE_HASH_LENTH_SIZE        1 * HWORD

/***************************************************************************/
/***************************************************************************/

#define   DEVICE_HASH_ALGORITHM            DEVICE_HASH_LENTH + DEVICE_HASH_LENTH_SIZE/2
#define   DEVICE_HASH_ALGORITHM_SIZE       1 * HWORD

/***************************************************************************/
/***************************************************************************/

#define   DEVICE_IDENTIFICATION             DEVICE_HASH_ALGORITHM + DEVICE_HASH_ALGORITHM_SIZE/2
#define   DEVICE_IDENTIFICATION_SIZE        5 * WORD

      #define   DEVICE_ID                            0*WORD         +         DEVICE_IDENTIFICATION
      #define   DEVICE_FIRMWARE_VER                  1*WORD         +         DEVICE_IDENTIFICATION
      #define   DEVICE_HARDWARE_VER                  2*WORD         +         DEVICE_IDENTIFICATION
      #define   DEVICE_ROM_VER                       3*WORD         +         DEVICE_IDENTIFICATION

/***************************************************************************/
/***************************************************************************/

#define   DEVICE_STATUS                 DEVICE_IDENTIFICATION + DEVICE_IDENTIFICATION_SIZE/2
#define   DEVICE_STATUS_SIZE            6 * BYTE

/***************************************************************************/
/***************************************************************************/

#define   DEVICE_STATUS_FLAGS           DEVICE_STATUS
#define   DEVICE_STATUS_FLAGS_SIZE      4 * BYTE

      #define   ERR_SOFT_BIT_mask             (1 << 0)
      #define   ERR_SOFT_BIT_pos              0
      #define   ERR_SOFT_BIT_size             1

      #define   ERR_ADDR_BIT_mask             (1 << 1)
      #define   ERR_ADDR_BIT_pos              1
      #define   ERR_ADDR_BIT_size             1

      #define   ERR_CALIBRATION_BIT_mask      (1 << 2)
      #define   ERR_CALIBRATION_BIT_pos       2
      #define   ERR_CALIBRATION_BIT_size      1

      #define   ERR_OTHER_DATA_BIT_mask       (1 << 3)
      #define   ERR_OTHER_DATA_BIT_pos        3
      #define   ERR_OTHER_DATA_BIT_size       1

      #define   ERR_CONFIG_DATA_BIT_mask      (1 << 4)
      #define   ERR_CONFIG_DATA_BIT_pos       4   
      #define   ERR_CONFIG_DATA_BIT_size      1   

      #define   ERR_CALIBR_SPECTR_BIT_mask    (1 << 5)
      #define   ERR_CALIBR_SPECTR_BIT_pos     5
      #define   ERR_CALIBR_SPECTR_BIT_size    1

      #define   ERR_GENERAL_SPECTR_BIT_mask   (1 << 6)
      #define   ERR_GENERAL_SPECTR_BIT_pos    6
      #define   ERR_GENERAL_SPECTR_BIT_size   1

      #define   ERR_ROM_MEMORY_BIT_mask       (1 << 7)
      #define   ERR_ROM_MEMORY_BIT_pos        7
      #define   ERR_ROM_MEMORY_BIT_size       1

      #define   ERR_EEPROM_MEM_BIT_mask       (1 << 8)
      #define   ERR_EEPROM_MEM_BIT_pos        8
      #define   ERR_EEPROM_MEM_BIT_size       1

      #define   ERR_FPGA_BIT_mask             (1 << 9)
      #define   ERR_FPGA_BIT_pos              9
      #define   ERR_FPGA_BIT_size             1

      #define   ERR_FLASH_BIT_mask            (1 << 10)
      #define   ERR_FLASH_BIT_pos             10
      #define   ERR_FLASH_BIT_size            1

      #define   ERR_INTERRUPT_BIT_mask        (1 << 11)
      #define   ERR_INTERRUPT_BIT_pos         11
      #define   ERR_INTERRUPT_BIT_size        1

      #define   ERR_SUPPLY_VOLTAGE_BIT_mask   (1 << 12)
      #define   ERR_SUPPLY_VOLTAGE_BIT_pos    12
      #define   ERR_SUPPLY_VOLTAGE_BIT_size   1

      #define   ERR_EXTERNAL_PERIPH_BIT_mask  (1 << 13)
      #define   ERR_EXTERNAL_PERIPH_BIT_pos   13
      #define   ERR_EXTERNAL_PERIPH_BIT_size  1

/***************************************************************************/
/***************************************************************************/

#define   DEVICE_STATUS_SIGNALS         DEVICE_STATUS_FLAGS + DEVICE_STATUS_FLAGS_SIZE/2
#define   DEVICE_STATUS_SIGNALS_SIZE    2 * BYTE

/***************************************************************************/
/***************************************************************************/
#define   INTERFACE_STATISTIC           DEVICE_STATUS + DEVICE_STATUS_SIZE/2
#define   INTERFACE_STATISTIC_SIZE      7 * WORD

      #define   BUS_MSG_CNT_WORD              0*WORD         +         INTERFACE_STATISTIC
      #define   RECV_MSG_CNT_WORD             1*WORD         +         INTERFACE_STATISTIC
      #define   TIMEOUT_MSG_CNT_WORD          2*WORD         +         INTERFACE_STATISTIC
      #define   ERR_CRC_MSG_CNT_WORD          3*WORD         +         INTERFACE_STATISTIC
      #define   ERR_NAK_MSG_CNT_WORD          4*WORD         +         INTERFACE_STATISTIC
      #define   ERR_OVERRUN_MSG_CNT_WORD      5*WORD         +         INTERFACE_STATISTIC
      #define   ERR_OTHER_MSG_CNT_WORD        6*WORD         +         INTERFACE_STATISTIC

/***************************************************************************/
/***************************************************************************/

#define   RD_CNT_RESULT                   INTERFACE_STATISTIC + INTERFACE_STATISTIC_SIZE/2
#define   RD_CNT_RESULT_SIZE              14 * FLOAT

      #define   CNT_RESULT_INST_FLOAT             0*FLOAT      +         RD_CNT_RESULT
      #define   CNT_RESULT_AVER_FLOAT             1*FLOAT      +         RD_CNT_RESULT
      #define   CNT_RESULT_AVER_SKO_FLOAT         2*FLOAT      +         RD_CNT_RESULT
      #define   CNT_RESULT_BACKGND_FLOAT          3*FLOAT      +         RD_CNT_RESULT
      #define   CNT_RESULT_BACKGND_SKO_FLOAT      4*FLOAT      +         RD_CNT_RESULT
      #define   CNT_RESULT_1_FLOAT                5*FLOAT      +         RD_CNT_RESULT
      #define   CNT_RESULT_2_FLOAT                6*FLOAT      +         RD_CNT_RESULT
      #define   CNT_RESULT_3_FLOAT                7*FLOAT      +         RD_CNT_RESULT
      #define   CNT_RESULT_4_FLOAT                8*FLOAT      +         RD_CNT_RESULT
      #define   CNT_RESULT_5_FLOAT                9*FLOAT      +         RD_CNT_RESULT

/***************************************************************************/
/***************************************************************************/

#define   RD_CNT_FLAGS                   RD_CNT_RESULT + RD_CNT_RESULT_SIZE/2
#define   RD_CNT_FLAGS_SIZE              2 * BYTE
/***************************************************************************/
/***************************************************************************/

#define   RD_DOSIMETER_RESULT               RD_CNT_FLAGS + RD_CNT_FLAGS_SIZE/2
#define   RD_DOSIMETER_RESULT_SIZE          6 * FLOAT

      #define   RD_DOSIMETER_RESULT_INST_DRATE_FLOAT       0*FLOAT      +         RD_DOSIMETER_RESULT
      #define   RD_DOSIMETER_RESULT_AVER_DRATE_FLOAT       1*FLOAT      +         RD_DOSIMETER_RESULT
      #define   RD_DOSIMETER_RESULT_BACKGND_DRATE_FLOAT    2*FLOAT      +         RD_DOSIMETER_RESULT
      #define   RD_DOSIMETER_RESULT_MEAS_DOSE_FLOAT        3*FLOAT      +         RD_DOSIMETER_RESULT
      #define   RD_DOSIMETER_RESULT_PWRON_DOSE_FLOAT       4*FLOAT      +         RD_DOSIMETER_RESULT
      #define   RD_DOSIMETER_RESULT_LIFETIME_DOSE_FLOAT    5*FLOAT      +         RD_DOSIMETER_RESULT

/***************************************************************************/
/***************************************************************************/

#define   RD_DOSIMETER_FLAGS           RD_DOSIMETER_RESULT + RD_DOSIMETER_RESULT_SIZE/2
#define   RD_DOSIMETER_FLAGS_SIZE      2 * BYTE
      // the same bit defenition in RD_RADIOMETER_STATUS_FLAGS
      #define ERR_FLAG_BIT_mask               (1 << 0) 
      #define ERR_FLAG_BIT_pos                0
      #define ERR_FLAG_BIT_size               1 

      #define OVR_FLAG_BIT_mask               (1 << 1)
      #define OVR_FLAG_BIT_pos                1
      #define OVR_FLAG_BIT_size               1

      #define THRSH_1_OVR_BIT_mask            (1 << 2)
      #define THRSH_1_OVR_BIT_pos             2
      #define THRSH_1_OVR_BIT_size            1

      #define THRSH_2_OVR_BIT_mask            (1 << 3)
      #define THRSH_2_OVR_BIT_pos             3
      #define THRSH_2_OVR_BIT_size            1

      #define THRSH_3_OVR_BIT_mask            (1 << 4)
      #define THRSH_3_OVR_BIT_pos             4
      #define THRSH_3_OVR_BIT_size            1

      #define THRSH_4_OVR_BIT_mask            (1 << 5)
      #define THRSH_4_OVR_BIT_pos             5
      #define THRSH_4_OVR_BIT_size            1

      #define THRSH_5_OVR_BIT_mask            (1 << 6)
      #define THRSH_5_OVR_BIT_pos             6
      #define THRSH_5_OVR_BIT_size            1

      #define THRSH_6_OVR_BIT_mask            (1 << 7)
      #define THRSH_6_OVR_BIT_pos             7
      #define THRSH_6_OVR_BIT_size            1

      #define THRSH_7_OVR_BIT_mask            (1 << 8)
      #define THRSH_7_OVR_BIT_pos             8
      #define THRSH_7_OVR_BIT_size            1

      #define THRSH_8_OVR_BIT_mask            (1 << 9)
      #define THRSH_8_OVR_BIT_pos             9
      #define THRSH_8_OVR_BIT_size            1

      #define THRSH_9_OVR_BIT_mask            (1 << 10)
      #define THRSH_9_OVR_BIT_pos             10
      #define THRSH_9_OVR_BIT_size            1

      #define THRSH_10_OVR_BIT_mask           (1 << 11)
      #define THRSH_10_OVR_BIT_size           11
      #define THRSH_10_OVR_BIT_pos            1

/***************************************************************************/
/***************************************************************************/

#define   RD_DOSIMETER_INTERPRET            RD_DOSIMETER_FLAGS + RD_DOSIMETER_FLAGS_SIZE/2
#define   RD_DOSIMETER_INTERPRET_SIZE       2 * BYTE

/***************************************************************************/
/***************************************************************************/

#define   RD_RADIOMETR_RESULT               RD_DOSIMETER_INTERPRET + RD_DOSIMETER_INTERPRET_SIZE/2
#define   RD_RADIOMETR_RESULT_SIZE          15 * FLOAT

      #define   RD_RADIOMETR_RESULT_INST_ACTIVITY_FLOAT             0*FLOAT      +         RD_RADIOMETR_RESULT
      #define   RD_RADIOMETR_RESULT_AVER_ACTIVITY_FLOAT             1*FLOAT      +         RD_RADIOMETR_RESULT
      #define   RD_RADIOMETR_RESULT_BACKGND_ACTIVITY_FLOAT          2*FLOAT      +         RD_RADIOMETR_RESULT
      #define   RD_RADIOMETR_RESULT_INST_FLUENCE_FLOAT              3*FLOAT      +         RD_RADIOMETR_RESULT
      #define   RD_RADIOMETR_RESULT_AVER_FLUENCE_FLOAT              4*FLOAT      +         RD_RADIOMETR_RESULT
      #define   RD_RADIOMETR_RESULT_BACKGND_FLUENCE_FLOAT           5*FLOAT      +         RD_RADIOMETR_RESULT
      #define   RD_RADIOMETR_RESULT_INST_FLUX_DENSITY_FLOAT         6*FLOAT      +         RD_RADIOMETR_RESULT
      #define   RD_RADIOMETR_RESULT_AVER_FLUX_DENSITY_FLOAT         7*FLOAT      +         RD_RADIOMETR_RESULT
      #define   RD_RADIOMETR_RESULT_BACKGND_FLUX_DENSITY_FLOAT      8*FLOAT      +         RD_RADIOMETR_RESULT

/***************************************************************************/
/***************************************************************************/

#define   RD_RADIOMETR_FLAGS            RD_RADIOMETR_RESULT + RD_RADIOMETR_RESULT_SIZE/2
#define   RD_RADIOMETR_FLAGS_SIZE       2 * BYTE
  
      // see RD_DOSIMETER_STATUS_FLAGS
/***************************************************************************/
/***************************************************************************/

#define   RD_RADIOMETR_INTERPRET            RD_RADIOMETR_FLAGS + RD_RADIOMETR_FLAGS_SIZE/2
#define   RD_RADIOMETR_INTERPRET_SIZE       2 * BYTE

/***************************************************************************/
/***************************************************************************/

#define   RD_SPECTROMETR_RESULT               RD_RADIOMETR_INTERPRET + RD_RADIOMETR_INTERPRET_SIZE/2
#define   RD_SPECTROMETR_RESULT_SIZE          (4096 * BYTE + 3 * WORD)

/***************************************************************************/
/***************************************************************************/

#define   RD_SPECTROMETR_INTERPRET            RD_SPECTROMETR_RESULT + RD_SPECTROMETR_RESULT_SIZE/2
#define   RD_SPECTROMETR_INTERPRET_SIZE       2 * BYTE

/***************************************************************************/
/***************************************************************************/

#define   RD_IDENTIFICATION_CONFIG            RD_SPECTROMETR_INTERPRET + RD_SPECTROMETR_INTERPRET_SIZE/2
#define   RD_IDENTIFICATION_CONFIG_SIZE       2 * BYTE
      // the same bit defenition in RD_CONTROL_CONFIG and RD_STATUS_CONFIG
      #define ENERGY_RANGE_BIT_0              (1 << 0)
      #define ENERGY_RANGE_BIT_1              (1 << 1)
      #define ENERGY_RANGE_BIT_2              (1 << 2)
      #define ENERGY_RANGE_mask               ( (ENERGY_RANGE_BIT_0) | (ENERGY_RANGE_BIT_1) | (ENERGY_RANGE_BIT_2) )
      #define ENERGY_RANGE_pos                0
      #define ENERGY_RANGE_size               3

      #define MEAS_RANGE_BIT_0                (1 << 3)
      #define MEAS_RANGE_BIT_1                (1 << 4)
      #define MEAS_RANGE_BIT_2                (1 << 5)
      #define MEAS_RANGE_mask                 ( (MEAS_RANGE_BIT_0) | (MEAS_RANGE_BIT_1) | (MEAS_RANGE_BIT_2) )
      #define MEAS_RANGE_pos                  3
      #define MEAS_RANGE_size                 3

      #define MEAS_CH_BIT_0                   (1 << 6)
      #define MEAS_CH_BIT_1                   (1 << 7)
      #define MEAS_CH_BIT_2                   (1 << 8)
      #define MEAS_CH_mask                    ( (MEAS_CH_BIT_0) | (MEAS_CH_BIT_1) | (MEAS_CH_BIT_2) )
      #define MEAS_CH_pos                     6
      #define MEAS_CH_size                    3

/***************************************************************************/
/***************************************************************************/

#define   RD_IDENTIFICATION_ENERGY_RANGE            RD_IDENTIFICATION_CONFIG + RD_IDENTIFICATION_CONFIG_SIZE/2
#define   RD_IDENTIFICATION_ENERGY_RANGE_SIZE       3 * WORD

/***************************************************************************/
/***************************************************************************/


#define   RD_IDENTIFICATION_MEAS_RANGE            RD_IDENTIFICATION_ENERGY_RANGE + RD_IDENTIFICATION_ENERGY_RANGE_SIZE/2
#define   RD_IDENTIFICATION_MEAS_RANGE_SIZE       3 * WORD

/***************************************************************************/
/***************************************************************************/

#define   RD_IDENTIFICATION_MEAS_CH            RD_IDENTIFICATION_MEAS_RANGE + RD_IDENTIFICATION_MEAS_RANGE_SIZE/2
#define   RD_IDENTIFICATION_MEAS_CH_SIZE       3 * WORD

/***************************************************************************/
/***************************************************************************/

#define   RD_STATUS_FLAGS            RD_IDENTIFICATION_MEAS_CH + RD_IDENTIFICATION_MEAS_CH_SIZE/2
#define   RD_STATUS_FLAGS_SIZE       2 * WORD

      #define RD_INIT_FLAG_BIT_mask              (1 << 0)
      #define RD_INIT_FLAG_BIT_pos               0
      #define RD_INIT_FLAG_BIT_size              1

      #define RD_ERR_FLAG_BIT_mask               (1 << 1)
      #define RD_ERR_FLAG_BIT_pos                1
      #define RD_ERR_FLAG_BIT_size               1

      #define RD_OVR_FLAG_BIT_mask               (1 << 2) 
      #define RD_OVR_FLAG_BIT_pos                2
      #define RD_OVR_FLAG_BIT_size               1

      #define RD_THRSH_OVR_BIT_mask              (1 << 3)
      #define RD_THRSH_OVR_BIT_pos               3
      #define RD_THRSH_OVR_BIT_size              1

      #define RD_ERR_HV_FLAG_BIT_mask            (1 << 4)
      #define RD_ERR_HV_FLAG_BIT_pos             4
      #define RD_ERR_HV_FLAG_BIT_size            1

      #define RD_ERR_CNTRL_FLAG_BIT_mask         (1 << 5)
      #define RD_ERR_CNTRL_FLAG_BIT_pos          5
      #define RD_ERR_CNTRL_FLAG_BIT_size         1

      #define RD_ERR_LEDSTAB_FLAG_BIT_mask       (1 << 6)
      #define RD_ERR_LEDSTAB_FLAG_BIT_pos        6
      #define RD_ERR_LEDSTAB_FLAG_BIT_size       1

/***************************************************************************/
/***************************************************************************/

#define   RD_STATUS_MODE            RD_STATUS_FLAGS + RD_STATUS_FLAGS_SIZE/2
#define   RD_STATUS_MODE_SIZE       2 * WORD
      // the same bit defenition in RD_RADIOMETER_STATUS_MODE_ON and RD_RADIOMETER_CONTROL_MODE_OFF

      #define BACKGND_SUBSTRACT_MODE_BIT_mask (1 << 0)
      #define BACKGND_SUBSTRACT_MODE_BIT_pos  0
      #define BACKGND_SUBSTRACT_MODE_BIT_size 1

      #define SEARCH_MODE_BIT_mask            (1 << 1)
      #define SEARCH_MODE_BIT_pos             1
      #define SEARCH_MODE_BIT_size            1

      #define SPECTROMETER_MODE_BIT_mask      (1 << 2)
      #define SPECTROMETER_MODE_BIT_pos       2
      #define SPECTROMETER_MODE_BIT_size      1

      #define LPOWER_MODE_BIT_mask            (1 << 3)
      #define LPOWER_MODE_BIT_pos             3
      #define LPOWER_MODE_BIT_size            1

      #define SETTING_MODE_BIT_mask           (1 << 4)
      #define SETTING_MODE_BIT_pos            4
      #define SETTING_MODE_BIT_size           1

      #define GATING_MODE_BIT_mask            (1 << 5)
      #define GATING_MODE_BIT_pos             5
      #define GATING_MODE_BIT_size            1

      #define SEARCH_SOUND_BIT_mask           (1 << 6)
      #define SEARCH_SOUND_BIT_pos            6
      #define SEARCH_SOUND_BIT_size           1
      
      #define SELTEST_MODE_BIT_mask           (1 << 7)
      #define SELTEST_MODE_BIT_pos            7
      #define SELTEST_MODE_BIT_size           1
      
      #define TEMP_CORRECTION_MODE_BIT_mask   (1 << 8)
      #define TEMP_CORRECTION_MODE_BIT_pos    8
      #define TEMP_CORRECTION_MODE_BIT_size   1
      
      #define AUTO_MEAS_RANGE_MODE_BIT_mask   (1 << 9)
      #define AUTO_MEAS_RANGE_MODE_BIT_pos    9
      #define AUTO_MEAS_RANGE_MODE_BIT_size   1

      #define SPECTR_ACCUMULATION_BIT_mask    (1 << 10)
      #define SPECTR_ACCUMULATION_BIT_pos     10
      #define SPECTR_ACCUMULATION_BIT_size    1

      #define LED_IN_SPECTR_MODE_BIT_mask     (1 << 11)
      #define LED_IN_SPECTR_MODE_BIT_pos      11
      #define LED_IN_SPECTR_MODE_BIT_size     1

      #define AVERAGE_MEAS_MODE_BIT_mask      (1 << 12)
      #define AVERAGE_MEAS_MODE_BIT_pos       12
      #define AVERAGE_MEAS_MODE_BIT_size      1

/***************************************************************************/
/***************************************************************************/

#define   RD_STATUS_CONFIG            RD_STATUS_MODE + RD_STATUS_MODE_SIZE/2
#define   RD_STATUS_CONFIG_SIZE       2 * WORD
/***************************************************************************/
/***************************************************************************/


#define   CLOCKS_PWRON_TIME              RD_STATUS_CONFIG + RD_STATUS_CONFIG_SIZE/2
#define   CLOCKS_PWRON_TIME_SIZE              6 * BYTE
/***************************************************************************/
/***************************************************************************/

#define   CLOCKS_LIFE_TIME                   CLOCKS_PWRON_TIME + CLOCKS_PWRON_TIME_SIZE/2
#define   CLOCKS_LIFE_TIME_SIZE              6 * BYTE
/***************************************************************************/
/***************************************************************************/

#define   CLOCKS_MEAS_START_TIME                   CLOCKS_LIFE_TIME + CLOCKS_LIFE_TIME_SIZE/2
#define   CLOCKS_MEAS_START_TIME_SIZE              6 * BYTE
/***************************************************************************/
/***************************************************************************/


#define   CLOCKS_MEAS_DURATION                   CLOCKS_MEAS_START_TIME + CLOCKS_MEAS_START_TIME_SIZE/2
#define   CLOCKS_MEAS_DURATION_SIZE              6 * BYTE
/***************************************************************************/
/***************************************************************************/

#define   CLOCKS_ALARM_1_ON_TIME                   CLOCKS_MEAS_DURATION + CLOCKS_MEAS_DURATION_SIZE/2
#define   CLOCKS_ALARM_1_ON_TIME_SIZE              6 * BYTE
/***************************************************************************/
/***************************************************************************/

#define   CLOCKS_ALARM_1_DURATION                   CLOCKS_ALARM_1_ON_TIME + CLOCKS_ALARM_1_ON_TIME_SIZE/2
#define   CLOCKS_ALARM_1_DURATION_SIZE              6 * BYTE
/***************************************************************************/
/***************************************************************************/

#define   CLOCKS_ALARM_2_ON_TIME                   CLOCKS_ALARM_1_DURATION + CLOCKS_ALARM_1_DURATION_SIZE/2
#define   CLOCKS_ALARM_2_ON_TIME_SIZE              6 * BYTE
/***************************************************************************/
/***************************************************************************/

#define   CLOCKS_ALARM_2_DURATION                   CLOCKS_ALARM_2_ON_TIME + CLOCKS_ALARM_2_ON_TIME_SIZE/2
#define   CLOCKS_ALARM_2_DURATION_SIZE              6 * BYTE
/***************************************************************************/
/***************************************************************************/

#define   CLOCKS_FLAGS                  CLOCKS_ALARM_2_DURATION + CLOCKS_ALARM_2_DURATION_SIZE/2
#define   CLOCKS_FLAGS_SIZE             2 * BYTE
/***************************************************************************/
/***************************************************************************/

#define   TEMP_VALUE                  CLOCKS_FLAGS + CLOCKS_FLAGS_SIZE/2
#define   TEMP_VALUE_SIZE             1 * HWORD
/***************************************************************************/
/***************************************************************************/

#define   TEMP_FLAGS                  TEMP_VALUE + TEMP_VALUE_SIZE/2
#define   TEMP_FLAGS_SIZE             2 * BYTE
/***************************************************************************/
/***************************************************************************/

#define   ALARM_FLAGS                  TEMP_FLAGS + TEMP_FLAGS_SIZE/2
#define   ALARM_FLAGS_SIZE             2 * BYTE
/***************************************************************************/
/***************************************************************************/

#define   ALARM_STATS                  ALARM_FLAGS + ALARM_FLAGS_SIZE/2
#define   ALARM_STATS_SIZE             2 * FLOAT

      #define ALARM_DOSE_FLOAT         0*FLOAT      +         ALARM_STATS
      #define ALARM_DOSE_CNT_FLOAT     1*FLOAT      +         ALARM_STATS
/***************************************************************************/
/***************************************************************************/








/*        READ=0/WRITE  DATA      */

#define   DEVICE_CONTROL_MODE             ALARM_STATS + ALARM_STATS_SIZE/2
#define   DEVICE_CONTROL_MODE_SIZE        2 * BYTE
/***************************************************************************/
/***************************************************************************/

#define   DEVICE_CONTROL_ACTION             DEVICE_CONTROL_MODE + DEVICE_CONTROL_MODE_SIZE/2
#define   DEVICE_CONTROL_ACTION_SIZE        2 * BYTE
/***************************************************************************/
/***************************************************************************/

#define   DEVICE_CONTROL_SIGNAL_ON             DEVICE_CONTROL_ACTION + DEVICE_CONTROL_ACTION_SIZE/2
#define   DEVICE_CONTROL_SIGNAL_ON_SIZE        2 * BYTE
/***************************************************************************/
/***************************************************************************/

#define   DEVICE_CONTROL_SIGNAL_OFF             DEVICE_CONTROL_SIGNAL_ON + DEVICE_CONTROL_SIGNAL_ON_SIZE/2
#define   DEVICE_CONTROL_SIGNAL_OFF_SIZE        2 * BYTE
/***************************************************************************/
/***************************************************************************/

#define   RD_CONTROL_HARDWARE             DEVICE_CONTROL_SIGNAL_OFF + DEVICE_CONTROL_SIGNAL_OFF_SIZE/2
#define   RD_CONTROL_HARDWARE_SIZE        2 * BYTE
/***************************************************************************/
/***************************************************************************/


#define   RD_CONTROL_MODE_ON             RD_CONTROL_HARDWARE + RD_CONTROL_HARDWARE_SIZE/2
#define   RD_CONTROL_MODE_ON_SIZE        2 * BYTE
      // see RD_STATUS_MODE
/***************************************************************************/
/***************************************************************************/

#define   RD_CONTROL_MODE_OFF             RD_CONTROL_MODE_ON + RD_CONTROL_MODE_ON_SIZE/2
#define   RD_CONTROL_MODE_OFF_SIZE        2 * BYTE
      // see RD_STATUS_MODE
/***************************************************************************/
/***************************************************************************/


#define   RD_CONTROL_ACTION             RD_CONTROL_MODE_OFF + RD_CONTROL_MODE_OFF_SIZE/2
#define   RD_CONTROL_ACTION_SIZE        2 * BYTE

      #define RESTART_ACTION_BIT_mask             (1 << 0)
      #define RESTART_ACTION_BIT_pos              0
      #define RESTART_ACTION_BIT_size             1

      #define SET_AS_BACKGND_ACTION_BIT_mask      (1 << 1)
      #define SET_AS_BACKGND_ACTION_BIT_pos       1
      #define SET_AS_BACKGND_ACTION_BIT_size      1

      #define SET_AS_SEARCHBASE_ACTION_BIT_mask   (1 << 2)
      #define SET_AS_SEARCHBASE_ACTION_BIT_pos    2
      #define SET_AS_SEARCHBASE_ACTION_BIT_size   1

      #define CLEAR_DOSE_ACTION_BIT_mask          (1 << 3)
      #define CLEAR_DOSE_ACTION_BIT_pos           3
      #define CLEAR_DOSE_ACTION_BIT_size          1

      #define STABILIZE_ACTION_BIT_mask           (1 << 4)
      #define STABILIZE_ACTION_BIT_pos            4
      #define STABILIZE_ACTION_BIT_size           1

      //#define хз как назвать бит 5          (1 << 5)      
      //#define хз как назвать бит 5          5     
      //#define хз как назвать бит 5          1

      #define STORE_SPECTR_ACTION_BIT_mask        (1 << 6)
      #define STORE_SPECTR_ACTION_BIT_pos         6
      #define STORE_SPECTR_ACTION_BIT_size        1

      #define LOAD_SPECTR_ACTION_BIT_mask         (1 << 7)
      #define LOAD_SPECTR_ACTION_BIT_pos          7
      #define LOAD_SPECTR_ACTION_BIT_size         1
/***************************************************************************/
/***************************************************************************/


#define   RD_CONTROL_CONFIG             RD_CONTROL_ACTION + RD_CONTROL_ACTION_SIZE/2
#define   RD_CONTROL_CONFIG_SIZE        2 * BYTE
/***************************************************************************/
/***************************************************************************/

#define   ALARM_CONTROL_ALARM_ON                 RD_CONTROL_CONFIG + RD_CONTROL_CONFIG_SIZE/2
#define   ALARM_CONTROL_ALARM_ON_SIZE            2 * BYTE
       // the same bit defenition in ALARM_CONTROL_ALARM_OFF
       #define ALARM_1_BIT_mask         (1 << 0)           
       #define ALARM_1_BIT_pos          0         
       #define ALARM_1_BIT_size         1

       #define ALARM_2_BIT_mask         (1 << 1)
       #define ALARM_2_BIT_pos          1
       #define ALARM_2_BIT_size         1
/***************************************************************************/
/***************************************************************************/

#define   ALARM_CONTROL_ALARM_OFF                 ALARM_CONTROL_ALARM_ON + ALARM_CONTROL_ALARM_ON_SIZE/2
#define   ALARM_CONTROL_ALARM_OFF_SIZE            2 * BYTE
       // see ALARM_CONTROL_ALARM_ON
/***************************************************************************/
/***************************************************************************/



/*        READ/WRITE ROOT DATA      */

#define   DEVICE_SERIAL_NUM             ALARM_CONTROL_ALARM_ON + ALARM_CONTROL_ALARM_ON_SIZE/2
#define   DEVICE_SERIAL_NUM_SIZE        WORD
/***************************************************************************/
/***************************************************************************/

#define   RD_DOSIMETER_CALIBRATION_TBL             DEVICE_SERIAL_NUM + DEVICE_SERIAL_NUM_SIZE/2
#define   RD_DOSIMETER_CALIBRATION_TBL_SIZE        10 * FLOAT

      #define   RD_DOSIMETER_CALIBRATION_POINT_1             0 * FLOAT         +         RD_DOSIMETER_CALIBRATION_TBL
      #define   RD_DOSIMETER_CALIBRATION_POINT_2             1 * FLOAT         +         RD_DOSIMETER_CALIBRATION_TBL
      #define   RD_DOSIMETER_CALIBRATION_POINT_3             2 * FLOAT         +         RD_DOSIMETER_CALIBRATION_TBL
      #define   RD_DOSIMETER_CALIBRATION_POINT_4             3 * FLOAT         +         RD_DOSIMETER_CALIBRATION_TBL
      #define   RD_DOSIMETER_CALIBRATION_POINT_5             4 * FLOAT         +         RD_DOSIMETER_CALIBRATION_TBL
      #define   RD_DOSIMETER_CALIBRATION_POINT_6             5 * FLOAT         +         RD_DOSIMETER_CALIBRATION_TBL
      #define   RD_DOSIMETER_CALIBRATION_POINT_7             6 * FLOAT         +         RD_DOSIMETER_CALIBRATION_TBL
      #define   RD_DOSIMETER_CALIBRATION_POINT_8             7 * FLOAT         +         RD_DOSIMETER_CALIBRATION_TBL
      #define   RD_DOSIMETER_CALIBRATION_POINT_9             8 * FLOAT         +         RD_DOSIMETER_CALIBRATION_TBL
      #define   RD_DOSIMETER_CALIBRATION_POINT_10            9 * FLOAT         +         RD_DOSIMETER_CALIBRATION_TBL
/***************************************************************************/
/***************************************************************************/

#define   RD_RADIOMETR_CALIBRATION_TBL             RD_DOSIMETER_CALIBRATION_TBL + RD_DOSIMETER_CALIBRATION_TBL_SIZE/2
#define   RD_RADIOMETR_CALIBRATION_TBL_SIZE        10 * FLOAT

      #define   RD_RADIOMETR_CALIBRATION_POINT_1             0 * FLOAT         +         RD_RADIOMETR_CALIBRATION_TBL
      #define   RD_RADIOMETR_CALIBRATION_POINT_2             1 * FLOAT         +         RD_RADIOMETR_CALIBRATION_TBL
      #define   RD_RADIOMETR_CALIBRATION_POINT_3             2 * FLOAT         +         RD_RADIOMETR_CALIBRATION_TBL
      #define   RD_RADIOMETR_CALIBRATION_POINT_4             3 * FLOAT         +         RD_RADIOMETR_CALIBRATION_TBL
      #define   RD_RADIOMETR_CALIBRATION_POINT_5             4 * FLOAT         +         RD_RADIOMETR_CALIBRATION_TBL
      #define   RD_RADIOMETR_CALIBRATION_POINT_6             5 * FLOAT         +         RD_RADIOMETR_CALIBRATION_TBL
      #define   RD_RADIOMETR_CALIBRATION_POINT_7             6 * FLOAT         +         RD_RADIOMETR_CALIBRATION_TBL
      #define   RD_RADIOMETR_CALIBRATION_POINT_8             7 * FLOAT         +         RD_RADIOMETR_CALIBRATION_TBL
      #define   RD_RADIOMETR_CALIBRATION_POINT_9             8 * FLOAT         +         RD_RADIOMETR_CALIBRATION_TBL
      #define   RD_RADIOMETR_CALIBRATION_POINT_10            9 * FLOAT         +         RD_RADIOMETR_CALIBRATION_TBL
/***************************************************************************/
/***************************************************************************/

#define   RD_COEFFICIENTS             RD_RADIOMETR_CALIBRATION_TBL + RD_RADIOMETR_CALIBRATION_TBL_SIZE/2
#define   RD_COEFFICIENTS_SIZE        10 * FLOAT
/***************************************************************************/
/***************************************************************************/

#define   CLOCKS_CALIBRATION_TIME             RD_COEFFICIENTS + RD_COEFFICIENTS_SIZE/2
#define   CLOCKS_CALIBRATION_TIME_SIZE        6 * BYTE
/***************************************************************************/
/***************************************************************************/

#define   CLOCKS_PRODUCTION_TIME             CLOCKS_CALIBRATION_TIME + CLOCKS_CALIBRATION_TIME_SIZE/2
#define   CLOCKS_PRODUCTION_TIME_SIZE        6 * BYTE
/***************************************************************************/
/***************************************************************************/






/*        READ=0/WRITE ROOT DATA      */

#define   RD_DOSIMETER_CALIBRATION_ACTION             CLOCKS_PRODUCTION_TIME + CLOCKS_PRODUCTION_TIME_SIZE/2
#define   RD_DOSIMETER_CALIBRATION_ACTION_SIZE        6 * BYTE
/***************************************************************************/
/***************************************************************************/

#define   RD_RADIOMETR_CALIBRATION_ACTION             RD_DOSIMETER_CALIBRATION_ACTION + RD_DOSIMETER_CALIBRATION_ACTION_SIZE/2
#define   RD_RADIOMETR_CALIBRATION_ACTION_SIZE        6 * BYTE
/***************************************************************************/
/***************************************************************************/






/*        READ/WRITE DATA      */

#define INTERFACE_OPTIONS_PHY_LAYER                         RD_RADIOMETR_CALIBRATION_ACTION + RD_RADIOMETR_CALIBRATION_ACTION_SIZE/2
#define INTERFACE_OPTIONS_PHY_LAYER_SIZE                    2 * WORD     
/***************************************************************************/
/***************************************************************************/
  
#define INTERFACE_OPTIONS_CH_LAYER                          INTERFACE_OPTIONS_PHY_LAYER + INTERFACE_OPTIONS_PHY_LAYER_SIZE/2
#define INTERFACE_OPTIONS_CH_LAYER_SIZE                     2 * HWORD 

#define INTERFACE_RTU_MODE                                  0*HWORD         +         INTERFACE_OPTIONS_CH_LAYER    
#define INTERFACE_ADDRESS                                   1*HWORD         +         INTERFACE_OPTIONS_CH_LAYER    
/***************************************************************************/
/***************************************************************************/
      
#define INTERFACE_OPTIONS_APP_LAYER                          INTERFACE_OPTIONS_CH_LAYER + INTERFACE_OPTIONS_CH_LAYER_SIZE/2
#define INTERFACE_OPTIONS_APP_LAYER_SIZE                     1 * HWORD     
/***************************************************************************/
/***************************************************************************/

#define RD_CNT_THRESHOLD                               INTERFACE_OPTIONS_APP_LAYER + INTERFACE_OPTIONS_APP_LAYER_SIZE/2
#define RD_CNT_THRESHOLD_SIZE                          10 * FLOAT

      #define   RD_CNT_THRESHOLD_1_FLOAT            0*FLOAT         +         RD_CNT_THRESHOLD
      #define   RD_CNT_THRESHOLD_2_FLOAT            1*FLOAT         +         RD_CNT_THRESHOLD
      #define   RD_CNT_THRESHOLD_3_FLOAT            2*FLOAT         +         RD_CNT_THRESHOLD
      #define   RD_CNT_THRESHOLD_4_FLOAT            3*FLOAT         +         RD_CNT_THRESHOLD
      #define   RD_CNT_THRESHOLD_5_FLOAT            4*FLOAT         +         RD_CNT_THRESHOLD
      #define   RD_CNT_THRESHOLD_6_FLOAT            5*FLOAT         +         RD_CNT_THRESHOLD
      #define   RD_CNT_THRESHOLD_7_FLOAT            6*FLOAT         +         RD_CNT_THRESHOLD
      #define   RD_CNT_THRESHOLD_8_FLOAT            7*FLOAT         +         RD_CNT_THRESHOLD
      #define   RD_CNT_THRESHOLD_9_FLOAT            8*FLOAT         +         RD_CNT_THRESHOLD
      #define   RD_CNT_THRESHOLD_10_FLOAT           9*FLOAT         +         RD_CNT_THRESHOLD
/***************************************************************************/
/***************************************************************************/

#define RD_DOSIMETER_THRESHOLD                          RD_CNT_THRESHOLD + RD_CNT_THRESHOLD_SIZE/2
#define RD_DOSIMETER_THRESHOLD_SIZE                     10 * FLOAT

      #define   RD_DOSIMETER_THRESHOLD_1_FLOAT            0*FLOAT         +         RD_DOSIMETER_THRESHOLD
      #define   RD_DOSIMETER_THRESHOLD_2_FLOAT            1*FLOAT         +         RD_DOSIMETER_THRESHOLD
      #define   RD_DOSIMETER_THRESHOLD_3_FLOAT            2*FLOAT         +         RD_DOSIMETER_THRESHOLD
      #define   RD_DOSIMETER_THRESHOLD_4_FLOAT            3*FLOAT         +         RD_DOSIMETER_THRESHOLD
      #define   RD_DOSIMETER_THRESHOLD_5_FLOAT            4*FLOAT         +         RD_DOSIMETER_THRESHOLD
      #define   RD_DOSIMETER_THRESHOLD_6_FLOAT            5*FLOAT         +         RD_DOSIMETER_THRESHOLD
      #define   RD_DOSIMETER_THRESHOLD_7_FLOAT            6*FLOAT         +         RD_DOSIMETER_THRESHOLD
      #define   RD_DOSIMETER_THRESHOLD_8_FLOAT            7*FLOAT         +         RD_DOSIMETER_THRESHOLD
      #define   RD_DOSIMETER_THRESHOLD_9_FLOAT            8*FLOAT         +         RD_DOSIMETER_THRESHOLD
      #define   RD_DOSIMETER_THRESHOLD_10_FLOAT           9*FLOAT         +         RD_DOSIMETER_THRESHOLD
/***************************************************************************/
/***************************************************************************/

#define RD_RADIOMETR_THRESHOLD                          RD_DOSIMETER_THRESHOLD + RD_DOSIMETER_THRESHOLD_SIZE/2
#define RD_RADIOMETR_THRESHOLD_SIZE                     10 * FLOAT

      #define   RD_RADIOMETR_THRESHOLD_1_FLOAT            0*FLOAT         +         RD_RADIOMETR_THRESHOLD
      #define   RD_RADIOMETR_THRESHOLD_2_FLOAT            1*FLOAT         +         RD_RADIOMETR_THRESHOLD
      #define   RD_RADIOMETR_THRESHOLD_3_FLOAT            2*FLOAT         +         RD_RADIOMETR_THRESHOLD
      #define   RD_RADIOMETR_THRESHOLD_4_FLOAT            3*FLOAT         +         RD_RADIOMETR_THRESHOLD
      #define   RD_RADIOMETR_THRESHOLD_5_FLOAT            4*FLOAT         +         RD_RADIOMETR_THRESHOLD
      #define   RD_RADIOMETR_THRESHOLD_6_FLOAT            5*FLOAT         +         RD_RADIOMETR_THRESHOLD
      #define   RD_RADIOMETR_THRESHOLD_7_FLOAT            6*FLOAT         +         RD_RADIOMETR_THRESHOLD
      #define   RD_RADIOMETR_THRESHOLD_8_FLOAT            7*FLOAT         +         RD_RADIOMETR_THRESHOLD
      #define   RD_RADIOMETR_THRESHOLD_9_FLOAT            8*FLOAT         +         RD_RADIOMETR_THRESHOLD
      #define   RD_RADIOMETR_THRESHOLD_10_FLOAT           9*FLOAT         +         RD_RADIOMETR_THRESHOLD
/***************************************************************************/
/***************************************************************************/

#define RD_SPECTROMETR_OPTIONS                          RD_RADIOMETR_THRESHOLD + RD_RADIOMETR_THRESHOLD_SIZE/2
#define RD_SPECTROMETR_OPTIONS_SIZE                     1 * HWORD
/***************************************************************************/
/***************************************************************************/

#define RD_OPTIONS                          RD_RADIOMETR_THRESHOLD + RD_RADIOMETR_THRESHOLD_SIZE/2
#define RD_OPTIONS_SIZE                     2 * WORD

      #define RD_OPTIONS_MOVEAVERWIN_WORD              0*WORD         +         RD_OPTIONS
      #define RD_OPTIONS_MEASFREQ_WORD                 1*WORD         +         RD_OPTIONS
/***************************************************************************/
/***************************************************************************/

#define CLOCKS_TIME                          RD_OPTIONS + RD_OPTIONS_SIZE/2
#define CLOCKS_TIME_SIZE                     6 * BYTE
/***************************************************************************/
/***************************************************************************/

#endif
