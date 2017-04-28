

/************************************************************/
 /************ LAT ************/


  
  /************ r_only region ************/
  
  #define identification_lat_ver__uint32_t  0x0
  #define identification_device_code__uint32_t  0x2
  #define identification_firmware_ver__uint32_t  0x6
  #define identification_hardware_ver__uint32_t  0xe
  #define identification_rom_ver__uint32_t  0x1e
  #define identification_RESERVED_R_ONLY__uint16_t_5  0x3e
  #define hashsum_reference_val__uint8_t_512  0x81
  #define hashsum_calulated_val__uint8_t_512  0x202
  #define hashsum_length__uint16_t  0x504
  #define hashsum_algorithm__uint32_t  0xa09
  #define hashsum_RESERVED_R_ONLY__uint16_t_5  0x1414
  #define status_mode__device_mode_t  0x282d
  #define status_flags__device_flags_t  0x505c
  #define status_signals__device_signals_t  0xa0ba
  #define status_access__device_access_t  0x14176
  #define status_RESERVED_R_ONLY__uint16_t_5  0x282ed
  #define radiation_detector_counter_results_instant_count_rate__float  0x505df
  #define radiation_detector_counter_results_average_count_rate__float  0xa0bc0
  #define radiation_detector_counter_results_average_sko__float  0x141782
  #define radiation_detector_counter_results_background_count_rate__float  0x282f06
  #define radiation_detector_counter_results_background_sko__float  0x505e0e
  #define radiation_detector_counter_results_RESERVED_R_ONLY__float_10  0xa0bc1e
  #define radiation_detector_counter_flags__uint16_t  0x1417850
  #define radiation_detector_counter_interpretation_radiation_type__uint16_t  0xa0bc284
  #define radiation_detector_counter_interpretation_average_alg__uint16_t  0x1e23478d
  #define radiation_detector_dosimeter_results_instant_drate__float  0x5a69d6a8
  #define radiation_detector_dosimeter_results_average_drate__float  0xb4d3ad52
  #define radiation_detector_dosimeter_results_average_sko__float  0x69a75aa6
  #define radiation_detector_dosimeter_results_backgnd_drate__float  0xd34eb54e
  #define radiation_detector_dosimeter_results_backgnd_sko__float  0xa69d6a9e
  #define radiation_detector_dosimeter_results_measurment_dose__float  0x4d3ad53e
  #define radiation_detector_dosimeter_results_pwron_dose__float  0x9a75aa7e
  #define radiation_detector_dosimeter_results_lifetime_dose__float  0x34eb54fe
  #define radiation_detector_dosimeter_results_RESERVED_R_ONLY__float_8  0x69d6a9fe
  #define radiation_detector_dosimeter_flags__uint16_t  0xd3ad540c
  #define radiation_detector_dosimeter_interpretation_radiation_type__uint16_t  0x9d6aa064
  #define radiation_detector_dosimeter_interpretation_average_alg__uint16_t  0xd83fe12d
  #define radiation_detector_radiometer_result_instant_activity__float  0x22fe8e20
  #define radiation_detector_radiometer_result_average_activity__float  0x45fd1c42
  #define radiation_detector_radiometer_result_backgnd_activity__float  0x8bfa3886
  #define radiation_detector_radiometer_result_instant_fluence__float  0x17f4710e
  #define radiation_detector_radiometer_result_average_fluence__float  0x2fe8e21e
  #define radiation_detector_radiometer_result_backgnd_fluence__float  0x5fd1c43e
  #define radiation_detector_radiometer_result_instant_flux_density__float  0xbfa3887e
  #define radiation_detector_radiometer_result_average_flux_density__float  0x7f4710fe
  #define radiation_detector_radiometer_result_backgnd_flux_density__float  0xfe8e21fe
  #define radiation_detector_radiometer_result_RESERVED_R_ONLY__float_10  0xfd1c43fe
  #define radiation_detector_radiometer_flags__radiometer_flags_t  0xfa388810
  #define radiation_detector_radiometer_interpretation_radiation_type__uint16_t  0xd1c44084
  #define radiation_detector_radiometer_interpretation_average_alg__uint16_t  0x754cc18d
  #define radiation_detector_spectrometer_results__uint8_t_4200  0x7f9912a0
  #define radiation_detector_spectrometer_interpretation_radiation_type__uint16_t  0xfcc8b5d0
  #define radiation_detector_spectrometer_interpretation_average_alg__uint16_t  0xf65a2171
  #define radiation_detector_capabilities_configuration_energy_range__uint16_t  0xe30e6454
  #define radiation_detector_capabilities_configuration_exposure_range__uint16_t  0xa92b2cfd
  #define radiation_detector_capabilities_configuration_measuring_circuit__uint16_t  0xfb8186f8
  #define radiation_detector_capabilities_configuration_measuring_mode__uint16_t  0xf28494e9
  #define radiation_detector_capabilities_rd_sub_devices__radiation_detector_configuration2_t  0xd78dbebc
  #define radiation_detector_capabilities_RESERVED_R_ONLY__uint8_t_160  0xaf1b7d79
  #define radiation_detector_status_flags__radiation_detector_flags_t  0x5e36fb42
  #define radiation_detector_status_mode__radiation_detector_mode_t  0xbc6df685
  #define radiation_detector_log_RESERVED_R_ONLY__uint8_t_10  0x78dbed0c
  #define clocks_pwron_time__time_t  0xf1b7da1d
  #define clocks_life_time__time_t  0xe36fb43d
  #define clocks_meas_duration__time_t  0xc6df687d
  #define clocks_flags__alarm_flags_t  0x8dbed0fd
  #define clocks_RESERVED_R_ONLY__time_t_3  0x1b7da1fb
  #define temperature_sensor_temperature__int16_t  0x36fb43ff
  #define temperature_sensor_flags__alarm_flags_t  0xa4f1cbfe
  #define alarm_flags__alarm_flags_t  0xddaac7f6
  #define alarm_accum_dose__float  0x990057e3
  #define alarm_max_drate__float  0xcb0107ab
  #define alarm_start_time__time_t  0x61031703
  #define alarm_duration__time_t  0x2309450c
  #define modbus_statistics_cnt_message_all__uint32_t  0xd2379e4e
  #define modbus_statistics_cnt_message_addressed__uint32_t  0xa46f3c9e
  #define modbus_statistics_cnt_answer_timeout__uint32_t  0x48de793e
  #define modbus_statistics_cnt_message_badcrc__uint32_t  0x91bcf27e
  #define modbus_statistics_cnt_message_nak__uint32_t  0x2379e4fe
  #define modbus_statistics_cnt_message_overrun__uint32_t  0x46f3c9fe
  #define modbus_statistics_cnt_message_othererr__uint32_t  0x8de793fe
  
  #define r_only_REGION_START 0x0
  #define r_only_REGION_STOP 0x1bcf27fe
  #define r_only_REGION_SIZE 0x1bcf27fe
  
  /************ rw region ************/
  
  #define radiation_detector_counter_threshold_0__float  0x1bcf2be6
  #define radiation_detector_counter_threshold_1__float  0x1bcf2be8
  #define radiation_detector_counter_threshold_2__float  0x1bcf2bea
  #define radiation_detector_counter_threshold_3__float  0x1bcf2bec
  #define radiation_detector_counter_threshold_4__float  0x1bcf2bee
  #define radiation_detector_counter_threshold_5__float  0x1bcf2bf0
  #define radiation_detector_counter_threshold_6__float  0x1bcf2bf2
  #define radiation_detector_counter_threshold_7__float  0x1bcf2bf4
  #define radiation_detector_counter_threshold_8__float  0x1bcf2bf6
  #define radiation_detector_counter_threshold_9__float  0x1bcf2bf8
  #define radiation_detector_counter_interpretation_mode__uint16_t  0x379e57e0
  #define radiation_detector_counter_interpretation_unit__uint16_t  0xa6db07a1
  #define radiation_detector_dosimeter_threshold_0__float  0xd2445b90
  #define radiation_detector_dosimeter_threshold_1__float  0xd2445b92
  #define radiation_detector_dosimeter_threshold_2__float  0xd2445b94
  #define radiation_detector_dosimeter_threshold_3__float  0xd2445b96
  #define radiation_detector_dosimeter_threshold_4__float  0xd2445b98
  #define radiation_detector_dosimeter_threshold_5__float  0xd2445b9a
  #define radiation_detector_dosimeter_threshold_6__float  0xd2445b9c
  #define radiation_detector_dosimeter_threshold_7__float  0xd2445b9e
  #define radiation_detector_dosimeter_threshold_8__float  0xd2445ba0
  #define radiation_detector_dosimeter_threshold_9__float  0xd2445ba2
  #define radiation_detector_dosimeter_interpretation_mode__uint16_t  0xa488b734
  #define radiation_detector_dosimeter_interpretation_unit__uint16_t  0xed9a259d
  #define radiation_detector_radiometer_threshold_instant_activity__float  0x8ce70d80
  #define radiation_detector_radiometer_threshold_average_activity__float  0x19ce1b02
  #define radiation_detector_radiometer_threshold_instant_fluence__float  0x339c3606
  #define radiation_detector_radiometer_threshold_average_fluence__float  0x67386c0e
  #define radiation_detector_radiometer_threshold_instant_flux_density__float  0xce70d81e
  #define radiation_detector_radiometer_threshold_average_flux_density__float  0x9ce1b03e
  #define radiation_detector_radiometer_threshold_RESERVED_RW__float_10  0x39c3607e
  #define radiation_detector_radiometer_interpretation_mode__uint16_t  0x7386c110
  #define radiation_detector_radiometer_interpretation_unit__uint16_t  0x5a944331
  #define radiation_detector_spectrometer_options__uint8_t_120  0xfbcc9940
  #define radiation_detector_spectrometer_interpretation_mode__uint16_t  0xf79932bc
  #define radiation_detector_spectrometer_interpretation_unit__uint16_t  0xe6cb9835
  #define radiation_detector_options_configuration_energy_range__uint16_t  0xd18b2280
  #define radiation_detector_options_configuration_exposure_range__uint16_t  0x74a16781
  #define radiation_detector_options_configuration_measuring_circuit__uint16_t  0x5de43684
  #define radiation_detector_options_configuration_measuring_mode__uint16_t  0x19aca38d
  #define radiation_detector_options_average_win__uint32_t  0x4d05eaa8
  #define radiation_detector_options_measurment_freq__uint32_t  0x9a0bd552
  #define radiation_detector_log_RESERVED_RW__uint8_t_20  0x3417aaa6
  #define clocks_time__time_t  0x682f5556
  #define clocks_RESERVED_RW__time_t_3  0xd05eaaaf
  #define alarm_RESERVED__uint8_t_12  0xbd556700
  #define modbus_config_phy_layer_baudrate__uint32_t  0x38003506
  #define modbus_config_phy_layer_parity__uint16_t  0x70006a0e
  #define modbus_config_phy_layer_frame_size__uint16_t  0xe000d41d
  #define modbus_config_phy_layer_stop_bits__uint16_t  0xc001a83b
  #define modbus_config_channel_layer_tmode__uint16_t  0x80035077
  #define modbus_config_channel_layer_address__uint16_t  0x6a0ef
  
  #define rw_REGION_START 0x1bcf2be6
  #define rw_REGION_STOP 0xd41df
  #define rw_REGION_SIZE 0xe43e15f9
  
  /************ rw_root region ************/
  
  #define identification_serial_num__uint32_t  0xd45c7
  #define identification_manufacture_num__uint32_t  0x1a8b90
  #define identification_RESERVED_RW_ROOT__uint16_t_5  0x351722
  #define radiation_detector_dosimeter_calibration_point_reference_val__float  0x6a2e4900
  #define radiation_detector_dosimeter_calibration_point_average_val__float  0x3e8adb02
  #define radiation_detector_dosimeter_calibration_point_RESERVED_0__float  0xbba09108
  #define radiation_detector_dosimeter_calibration_point_RESERVED_1__float  0xbba0910a
  #define radiation_detector_dosimeter_calibration_point_RESERVED_2__float  0xbba0910c
  #define radiation_detector_dosimeter_calibration_point_RESERVED_3__float  0xbba0910e
  #define radiation_detector_dosimeter_calibration_point_RESERVED_4__float  0xbba09110
  #define radiation_detector_dosimeter_calibration_point_RESERVED_5__float  0xbba09112
  #define radiation_detector_dosimeter_calibration_point_RESERVED_6__float  0xbba09114
  #define radiation_detector_dosimeter_calibration_point_RESERVED_7__float  0xbba09116
  #define radiation_detector_dosimeter_calibration_point_RESERVED_8__float  0xbba09118
  #define radiation_detector_dosimeter_calibration_point_RESERVED_9__float  0xbba0911a
  #define radiation_detector_radiometer_calibration_point_reference_val__float  0xa1ff8580
  #define radiation_detector_radiometer_calibration_point_average_val__float  0xe5fe9082
  #define radiation_detector_radiometer_calibration_point_RESERVED_0__float  0xb1fbb188
  #define radiation_detector_radiometer_calibration_point_RESERVED_1__float  0xb1fbb18a
  #define radiation_detector_radiometer_calibration_point_RESERVED_2__float  0xb1fbb18c
  #define radiation_detector_radiometer_calibration_point_RESERVED_3__float  0xb1fbb18e
  #define radiation_detector_radiometer_calibration_point_RESERVED_4__float  0xb1fbb190
  #define radiation_detector_radiometer_calibration_point_RESERVED_5__float  0xb1fbb192
  #define radiation_detector_radiometer_calibration_point_RESERVED_6__float  0xb1fbb194
  #define radiation_detector_radiometer_calibration_point_RESERVED_7__float  0xb1fbb196
  #define radiation_detector_radiometer_calibration_point_RESERVED_8__float  0xb1fbb198
  #define radiation_detector_radiometer_calibration_point_RESERVED_9__float  0xb1fbb19a
  #define radiation_detector_coefficients_0__float  0xfe534580
  #define radiation_detector_coefficients_1__float  0xfe534582
  #define radiation_detector_coefficients_2__float  0xfe534584
  #define radiation_detector_coefficients_3__float  0xfe534586
  #define radiation_detector_coefficients_4__float  0xfe534588
  #define radiation_detector_coefficients_5__float  0xfe53458a
  #define radiation_detector_coefficients_6__float  0xfe53458c
  #define radiation_detector_coefficients_7__float  0xfe53458e
  #define radiation_detector_coefficients_8__float  0xfe534590
  #define radiation_detector_coefficients_9__float  0xfe534592
  #define radiation_detector_coefficients_10__float  0xfe534594
  #define radiation_detector_coefficients_11__float  0xfe534596
  #define radiation_detector_coefficients_12__float  0xfe534598
  #define radiation_detector_coefficients_13__float  0xfe53459a
  #define radiation_detector_coefficients_14__float  0xfe53459c
  #define radiation_detector_coefficients_15__float  0xfe53459e
  #define radiation_detector_coefficients_16__float  0xfe5345a0
  #define radiation_detector_coefficients_17__float  0xfe5345a2
  #define radiation_detector_coefficients_18__float  0xfe5345a4
  #define radiation_detector_coefficients_19__float  0xfe5345a6
  #define radiation_detector_coefficients_20__float  0xfe5345a8
  #define radiation_detector_coefficients_21__float  0xfe5345aa
  #define radiation_detector_coefficients_22__float  0xfe5345ac
  #define radiation_detector_coefficients_23__float  0xfe5345ae
  #define radiation_detector_coefficients_24__float  0xfe5345b0
  #define radiation_detector_coefficients_25__float  0xfe5345b2
  #define radiation_detector_coefficients_26__float  0xfe5345b4
  #define radiation_detector_coefficients_27__float  0xfe5345b6
  #define radiation_detector_coefficients_28__float  0xfe5345b8
  #define radiation_detector_coefficients_29__float  0xfe5345ba
  #define clocks_calibration_time__time_t  0xfca68b3c
  #define clocks_manufacture_time__time_t  0xf94d167b
  #define clocks_RESERVED_RW_ROOT__time_t_3  0xf29a2cf9
  
  #define rw_root_REGION_START 0xd45c7
  #define rw_root_REGION_STOP 0x68b3f600
  #define rw_root_REGION_SIZE 0x68a6b039
  
  /************ r0w region ************/
  
  #define control_action__device_actions_t  0x68b3f9e8
  #define control_mode_on__device_mode_t  0xd167f3d2
  #define control_mode_off__device_mode_t  0xa2cfe7a6
  #define control_signal_on__device_signals_t  0x459fcf4e
  #define control_signal_off__device_signals_t  0x8b3f9e9e
  #define control_password__uint8_t_32  0x167f3d3e
  #define control_RESERVED_R0W__uint16_t_5  0x2cfe7a8c
  #define radiation_detector_control_mode_on__radiation_detector_mode_t  0x51d00000
  #define radiation_detector_control_mode_off__radiation_detector_mode_t  0xa3a00002
  #define radiation_detector_control_action__radiation_detector_action_t  0x47400006
  #define alarm_action__alarm_action_t  0x3a000038
  
  #define r0w_REGION_START 0x68b3f9e8
  #define r0w_REGION_STOP 0x80002a40
  #define r0w_REGION_SIZE 0x174c3058
  
  /************ r0w_root region ************/
  
  #define radiation_detector_dosimeter_calibration_action__calibration_action_t  0x5c5000
  #define radiation_detector_radiometer_calibration_action__calibration_action_t  0x229e0020
  
  #define r0w_root_REGION_START 0x80002e28
  #define r0w_root_REGION_STOP 0x400c2000
  #define r0w_root_REGION_SIZE 0xc00bf1d8

 /************ BIT DEFINES ************/


/************ Bit defenitions for type 'alarm_action_t' ************/
   #define enable 1
   #define disable 2
   #define init 4
/************ Bit defenitions for type 'alarm_flags_t' ************/
   #define init 1
   #define error 2
/************ Bit defenitions for type 'calibration_action_t' ************/
   #define calculate_1 1
   #define calculate_2 2
/************ Bit defenitions for type 'counter_flags_t' ************/
   #define error 1
   #define overload 2
 #define exceeded_threshold_SIZE 10
 #define exceeded_threshold_POS 2
 #define exceeded_threshold_MASK 0xffc
   #define exceeded_threshold_0 4
   #define exceeded_threshold_1 8
   #define exceeded_threshold_2 16
   #define exceeded_threshold_3 32
   #define exceeded_threshold_4 64
   #define exceeded_threshold_5 128
   #define exceeded_threshold_6 256
   #define exceeded_threshold_7 512
   #define exceeded_threshold_8 1024
   #define exceeded_threshold_9 2048
/************ Bit defenitions for type 'device_flags_t' ************/
   #define err_software 1
   #define err_clock 2
   #define err_calibration 4
   #define err_other_data 8
   #define err_config_data 16
   #define err_calibration_spectrum 32
   #define err_general_spectrum 64
   #define err_rom 128
   #define err_rom 256
   #define err_eeprom 512
   #define err_fpga 1024
   #define err_flash 2048
   #define err_interrupt 4096
   #define err_supply_voltage 8192
   #define err_external_periph 16384
   #define err_stabilization_sys 32768
   #define err_io 65536
   #define err_addr 131072
   #define battery_discharged 262144
/************ Bit defenitions for type 'device_mode_t' ************/
   #define sleep 1
/************ Bit defenitions for type 'device_signals_t' ************/
 #define signal_SIZE 20
 #define signal_POS 0
 #define signal_MASK 0xfffff
   #define signal_0 1
   #define signal_1 2
   #define signal_2 4
   #define signal_3 8
   #define signal_4 16
   #define signal_5 32
   #define signal_6 64
   #define signal_7 128
   #define signal_8 256
   #define signal_9 512
   #define signal_10 1024
   #define signal_11 2048
   #define signal_12 4096
   #define signal_13 8192
   #define signal_14 16384
   #define signal_15 32768
   #define signal_16 65536
   #define signal_17 131072
   #define signal_18 262144
   #define signal_19 524288
/************ Bit defenitions for type 'dosimeter_flags_t' ************/
   #define error 1
   #define overload 2
 #define exceeded_threshold_SIZE 10
 #define exceeded_threshold_POS 2
 #define exceeded_threshold_MASK 0xffc
   #define exceeded_threshold_0 4
   #define exceeded_threshold_1 8
   #define exceeded_threshold_2 16
   #define exceeded_threshold_3 32
   #define exceeded_threshold_4 64
   #define exceeded_threshold_5 128
   #define exceeded_threshold_6 256
   #define exceeded_threshold_7 512
   #define exceeded_threshold_8 1024
   #define exceeded_threshold_9 2048
/************ Bit defenitions for type 'radiation_detector_action_t' ************/
   #define restart_measurment 1
   #define set_average_as_background 2
   #define perform_stabilization 4
   #define clear_spectrum 8
   #define store_spectrum 16
   #define load_spectrum 32
   #define clear_dose 64
   #define set_average_as_base 128
/************ Bit defenitions for type 'radiation_detector_configuration2_t' ************/
   #define counter 1
   #define dosimeter 2
   #define radiometer 4
   #define spectrometer 8
/************ Bit defenitions for type 'radiation_detector_flags_t' ************/
   #define initializing 1
   #define error 2
   #define overload 4
   #define thrsh_exceded 8
   #define hv_error 16
   #define hvreg_error 32
   #define led_error 64
/************ Bit defenitions for type 'radiation_detector_mode_t' ************/
   #define backgnd_substraction 1
   #define search 2
   #define spectrometer 4
   #define low_power 8
   #define setup 16
   #define strobe 32
   #define self_control 64
   #define temperature_correction 128
   #define auto_exposure_range 256
   #define led_on_spectrum 512
   #define search_sound 1024
   #define measurment_stoped 2048
   #define spectrum_accum 4096
/************ Bit defenitions for type 'radiometer_flags_t' ************/
   #define error 1
   #define overload 2

 /************************************************************//********** LAT types **********/
/********** Common types **********/
  typedef alarm_action_t uint8_t[2];
  typedef alarm_flags_t uint8_t[2];
  typedef struct {
   alarm_flags_t flags;
   float accum_dose;
   float max_drate;
   time_t start_time;
   time_t duration;
  }alarm_t__r_only;
  typedef struct {
   uint8_t RESERVED[12];
  }alarm_t__rw;
  typedef struct {
   alarm_action_t action;
  }alarm_t__r0w;
  typedef calibration_action_t uint8_t[2];
  typedef struct {
   float reference_val;
   float average_val;
   float RESERVED_0;
   float RESERVED_1;
   float RESERVED_2;
   float RESERVED_3;
   float RESERVED_4;
   float RESERVED_5;
   float RESERVED_6;
   float RESERVED_7;
   float RESERVED_8;
   float RESERVED_9;
  }calibration_point_t__rw_root;
  typedef struct {
   calibration_point_t_rw_root point_0;
   calibration_point_t_rw_root point_1;
   calibration_point_t_rw_root point_2;
   calibration_point_t_rw_root point_3;
   calibration_point_t_rw_root point_4;
   calibration_point_t_rw_root point_5;
   calibration_point_t_rw_root point_6;
   calibration_point_t_rw_root point_7;
   calibration_point_t_rw_root point_8;
   calibration_point_t_rw_root point_9;
  }calibration_t__rw_root;
  typedef struct {
   calibration_action_t action;
  }calibration_t__r0w_root;
  typedef counter_flags_t uint8_t[2];
  typedef device_access_t uint8_t[2];
  typedef device_actions_t uint8_t[4];
  typedef device_flags_t uint8_t[4];
  typedef device_mode_t uint8_t[4];
  typedef device_signals_t uint8_t[4];
  typedef dosimeter_flags_t uint8_t[2];
  typedef struct {
   uint16_t radiation_type;
   uint16_t average_alg;
  }interpretation_t__r_only;
  typedef struct {
   uint16_t mode;
   uint16_t unit;
  }interpretation_t__rw;
  typedef radiation_detector_action_t uint8_t[4];
  typedef radiation_detector_configuration2_t uint8_t[2];
  typedef struct {
   uint16_t energy_range;
   uint16_t exposure_range;
   uint16_t measuring_circuit;
   uint16_t measuring_mode;
  }radiation_detector_configuration_t__r_only;
  typedef radiation_detector_flags_t uint8_t[2];
  typedef radiation_detector_mode_t uint8_t[4];
  typedef radiometer_flags_t uint8_t[2];
  typedef struct {
   int16_t temperature;
   alarm_flags_t flags;
  }temperature_sensor_t__r_only;
  typedef time_t uint8_t[6];
 /********** r_only types **********/
 typedef struct {
   typedef struct {
     uint32_t lat_ver;
     uint32_t device_code;
     uint32_t firmware_ver;
     uint32_t hardware_ver;
     uint32_t rom_ver;
     uint16_t RESERVED_R_ONLY[5];
   }identification__r_only;
   typedef struct {
     uint8_t reference_val[512];
     uint8_t calulated_val[512];
     uint16_t length;
     uint32_t algorithm;
     uint16_t RESERVED_R_ONLY[5];
   }hashsum__r_only;
   typedef struct {
     device_mode_t mode;
     device_flags_t flags;
     device_signals_t signals;
     device_access_t access;
     uint16_t RESERVED_R_ONLY[5];
   }status__r_only;
   typedef struct {
     typedef struct {
       typedef struct {
         float instant_count_rate;
         float average_count_rate;
         float average_sko;
         float background_count_rate;
         float background_sko;
         float RESERVED_R_ONLY[10];
       }results__r_only;
       uint16_t flags;
       interpretation_t_r_only interpretation;
     }counter__r_only;
     typedef struct {
       typedef struct {
         float instant_drate;
         float average_drate;
         float average_sko;
         float backgnd_drate;
         float backgnd_sko;
         float measurment_dose;
         float pwron_dose;
         float lifetime_dose;
         float RESERVED_R_ONLY[8];
       }results__r_only;
       uint16_t flags;
       interpretation_t_r_only interpretation;
     }dosimeter__r_only;
     typedef struct {
       typedef struct {
         float instant_activity;
         float average_activity;
         float backgnd_activity;
         float instant_fluence;
         float average_fluence;
         float backgnd_fluence;
         float instant_flux_density;
         float average_flux_density;
         float backgnd_flux_density;
         float RESERVED_R_ONLY[10];
       }result__r_only;
       radiometer_flags_t flags;
       interpretation_t_r_only interpretation;
     }radiometer__r_only;
     typedef struct {
       uint8_t results[4200];
       interpretation_t_r_only interpretation;
     }spectrometer__r_only;
     typedef struct {
       radiation_detector_configuration_t_r_only configuration;
       radiation_detector_configuration2_t rd_sub_devices;
       uint8_t RESERVED_R_ONLY[160];
     }capabilities__r_only;
     typedef struct {
       radiation_detector_configuration_t_r_only configuration;
     }options__r_only;
     typedef struct {
       radiation_detector_flags_t flags;
       radiation_detector_mode_t mode;
     }status__r_only;
     typedef struct {
       uint8_t RESERVED_R_ONLY[10];
     }log__r_only;
   }radiation_detector__r_only;
   typedef struct {
     time_t pwron_time;
     time_t life_time;
     time_t meas_duration;
     alarm_flags_t flags;
     time_t RESERVED_R_ONLY[3];
   }clocks__r_only;
   temperature_sensor_t_r_only temperature_sensor;
   alarm_t_r_only alarm_0;
   alarm_t_r_only alarm_1;
   typedef struct {
     typedef struct {
       uint32_t cnt_message_all;
       uint32_t cnt_message_addressed;
       uint32_t cnt_answer_timeout;
       uint32_t cnt_message_badcrc;
       uint32_t cnt_message_nak;
       uint32_t cnt_message_overrun;
       uint32_t cnt_message_othererr;
     }statistics__r_only;
   }modbus__r_only;
 }device__r_only_t;
 /********** rw types **********/
 typedef struct {
   typedef struct {
     typedef struct {
       float threshold_0;
       float threshold_1;
       float threshold_2;
       float threshold_3;
       float threshold_4;
       float threshold_5;
       float threshold_6;
       float threshold_7;
       float threshold_8;
       float threshold_9;
       interpretation_t_rw interpretation;
     }counter__rw;
     typedef struct {
       float threshold_0;
       float threshold_1;
       float threshold_2;
       float threshold_3;
       float threshold_4;
       float threshold_5;
       float threshold_6;
       float threshold_7;
       float threshold_8;
       float threshold_9;
       interpretation_t_rw interpretation;
     }dosimeter__rw;
     typedef struct {
       typedef struct {
         float instant_activity;
         float average_activity;
         float instant_fluence;
         float average_fluence;
         float instant_flux_density;
         float average_flux_density;
         float RESERVED_RW[10];
       }threshold__rw;
       interpretation_t_rw interpretation;
     }radiometer__rw;
     typedef struct {
       uint8_t options[120];
       interpretation_t_rw interpretation;
     }spectrometer__rw;
     typedef struct {
       radiation_detector_configuration_t configuration;
       uint32_t average_win;
       uint32_t measurment_freq;
     }options__rw;
     typedef struct {
       uint8_t RESERVED_RW[20];
     }log__rw;
   }radiation_detector__rw;
   typedef struct {
     time_t time;
     time_t RESERVED_RW[3];
   }clocks__rw;
   alarm_t_rw alarm_0;
   alarm_t_rw alarm_1;
   typedef struct {
     typedef struct {
       typedef struct {
         uint32_t baudrate;
         uint16_t parity;
         uint16_t frame_size;
         uint16_t stop_bits;
       }phy_layer__rw;
       typedef struct {
         uint16_t tmode;
         uint16_t address;
       }channel_layer__rw;
     }config__rw;
   }modbus__rw;
 }device__rw_t;
 /********** rw_root types **********/
 typedef struct {
   typedef struct {
     uint32_t serial_num;
     uint32_t manufacture_num;
     uint16_t RESERVED_RW_ROOT[5];
   }identification__rw_root;
   typedef struct {
     typedef struct {
       calibration_t_rw_root calibration;
     }dosimeter__rw_root;
     typedef struct {
       calibration_t_rw_root calibration;
     }radiometer__rw_root;
     float coefficients_0;
     float coefficients_1;
     float coefficients_2;
     float coefficients_3;
     float coefficients_4;
     float coefficients_5;
     float coefficients_6;
     float coefficients_7;
     float coefficients_8;
     float coefficients_9;
     float coefficients_10;
     float coefficients_11;
     float coefficients_12;
     float coefficients_13;
     float coefficients_14;
     float coefficients_15;
     float coefficients_16;
     float coefficients_17;
     float coefficients_18;
     float coefficients_19;
     float coefficients_20;
     float coefficients_21;
     float coefficients_22;
     float coefficients_23;
     float coefficients_24;
     float coefficients_25;
     float coefficients_26;
     float coefficients_27;
     float coefficients_28;
     float coefficients_29;
   }radiation_detector__rw_root;
   typedef struct {
     time_t calibration_time;
     time_t manufacture_time;
     time_t RESERVED_RW_ROOT[3];
   }clocks__rw_root;
 }device__rw_root_t;
 /********** r0w types **********/
 typedef struct {
   typedef struct {
     device_actions_t action;
     device_mode_t mode_on;
     device_mode_t mode_off;
     device_signals_t signal_on;
     device_signals_t signal_off;
     uint8_t password[32];
     uint16_t RESERVED_R0W[5];
   }control__r0w;
   typedef struct {
     typedef struct {
       radiation_detector_mode_t mode_on;
       radiation_detector_mode_t mode_off;
       radiation_detector_action_t action;
     }control__r0w;
   }radiation_detector__r0w;
   alarm_t_r0w alarm_0;
   alarm_t_r0w alarm_1;
 }device__r0w_t;
 /********** r0w_root types **********/
 typedef struct {
   typedef struct {
     typedef struct {
       calibration_t_r0w_root calibration;
     }dosimeter__r0w_root;
     typedef struct {
       calibration_t_r0w_root calibration;
     }radiometer__r0w_root;
   }radiation_detector__r0w_root;
 }device__r0w_root_t;