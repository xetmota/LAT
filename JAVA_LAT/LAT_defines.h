

/************************************************************/
 /************ LAT ************/


  
  /************ r_only region ************/
  
  #define identification_lat_ver__uint32_t  0x0
  #define identification_device_code__uint32_t  0x2
  #define identification_firmware_ver__uint32_t  0x4
  #define identification_hardware_ver__uint32_t  0x6
  #define identification_rom_ver__uint32_t  0x8
  #define identification_RESERVED_R_ONLY__uint16_t_5  0xa
  #define hashsum_reference_val__uint8_t_512  0xf
  #define hashsum_calulated_val__uint8_t_512  0x10f
  #define hashsum_length__uint16_t  0x20f
  #define hashsum_algorithm__uint32_t  0x210
  #define hashsum_RESERVED_R_ONLY__uint16_t_5  0x212
  #define status_mode__device_mode_t  0x217
  #define status_flags__device_flags_t  0x219
  #define status_signals__device_signals_t  0x21b
  #define status_access__device_access_t  0x21d
  #define status_battery_charge__uint16_t  0x21e
  #define status_RESERVED_R_ONLY__uint16_t_5  0x21f
  #define radiation_detector_counter_results_instant_count_rate__float  0x224
  #define radiation_detector_counter_results_average_count_rate__float  0x226
  #define radiation_detector_counter_results_average_sko__float  0x228
  #define radiation_detector_counter_results_background_count_rate__float  0x22a
  #define radiation_detector_counter_results_background_sko__float  0x22c
  #define radiation_detector_counter_results_RESERVED_R_ONLY__float_10  0x22e
  #define radiation_detector_counter_flags__uint16_t  0x242
  #define radiation_detector_counter_interpretation_radiation_type__uint16_t  0x243
  #define radiation_detector_counter_interpretation_average_alg__uint16_t  0x244
  #define radiation_detector_dosimeter_results_instant_drate__float  0x245
  #define radiation_detector_dosimeter_results_average_drate__float  0x247
  #define radiation_detector_dosimeter_results_average_sko__float  0x249
  #define radiation_detector_dosimeter_results_backgnd_drate__float  0x24b
  #define radiation_detector_dosimeter_results_backgnd_sko__float  0x24d
  #define radiation_detector_dosimeter_results_measurment_dose__float  0x24f
  #define radiation_detector_dosimeter_results_pwron_dose__float  0x251
  #define radiation_detector_dosimeter_results_lifetime_dose__float  0x253
  #define radiation_detector_dosimeter_results_RESERVED_R_ONLY__float_8  0x255
  #define radiation_detector_dosimeter_flags__uint16_t  0x265
  #define radiation_detector_dosimeter_interpretation_radiation_type__uint16_t  0x266
  #define radiation_detector_dosimeter_interpretation_average_alg__uint16_t  0x267
  #define radiation_detector_radiometer_result_instant_activity__float  0x268
  #define radiation_detector_radiometer_result_average_activity__float  0x26a
  #define radiation_detector_radiometer_result_backgnd_activity__float  0x26c
  #define radiation_detector_radiometer_result_instant_fluence__float  0x26e
  #define radiation_detector_radiometer_result_average_fluence__float  0x270
  #define radiation_detector_radiometer_result_backgnd_fluence__float  0x272
  #define radiation_detector_radiometer_result_instant_flux_density__float  0x274
  #define radiation_detector_radiometer_result_average_flux_density__float  0x276
  #define radiation_detector_radiometer_result_backgnd_flux_density__float  0x278
  #define radiation_detector_radiometer_result_RESERVED_R_ONLY__float_10  0x27a
  #define radiation_detector_radiometer_flags__radiometer_flags_t  0x28e
  #define radiation_detector_radiometer_interpretation_radiation_type__uint16_t  0x28f
  #define radiation_detector_radiometer_interpretation_average_alg__uint16_t  0x290
  #define radiation_detector_spectrometer_results__uint8_t_4200  0x291
  #define radiation_detector_spectrometer_interpretation_radiation_type__uint16_t  0xac5
  #define radiation_detector_spectrometer_interpretation_average_alg__uint16_t  0xac6
  #define radiation_detector_capabilities_configuration_energy_range__uint16_t  0xac7
  #define radiation_detector_capabilities_configuration_exposure_range__uint16_t  0xac8
  #define radiation_detector_capabilities_configuration_measuring_circuit__uint16_t  0xac9
  #define radiation_detector_capabilities_configuration_measuring_mode__uint16_t  0xaca
  #define radiation_detector_capabilities_rd_sub_devices__radiation_detector_configuration2_t  0xacb
  #define radiation_detector_capabilities_RESERVED_R_ONLY__uint8_t_160  0xacc
  #define radiation_detector_status_flags__radiation_detector_flags_t  0xb1c
  #define radiation_detector_status_mode__radiation_detector_mode_t  0xb1d
  #define radiation_detector_log_RESERVED_R_ONLY__uint8_t_10  0xb1f
  #define clocks_pwron_time__time_t  0xb24
  #define clocks_life_time__time_t  0xb27
  #define clocks_meas_duration__time_t  0xb2a
  #define clocks_flags__alarm_flags_t  0xb2d
  #define clocks_RESERVED_R_ONLY__time_t_3  0xb2e
  #define temperature_sensor_temperature__int16_t  0xb37
  #define temperature_sensor_flags__alarm_flags_t  0xb38
  #define alarm_0_flags__alarm_flags_t  0xb39
  #define alarm_0_accum_dose__float  0xb3a
  #define alarm_0_max_drate__float  0xb3c
  #define alarm_0_start_time__time_t  0xb3e
  #define alarm_0_duration__time_t  0xb41
  #define alarm_1_flags__alarm_flags_t  0xb44
  #define alarm_1_accum_dose__float  0xb45
  #define alarm_1_max_drate__float  0xb47
  #define alarm_1_start_time__time_t  0xb49
  #define alarm_1_duration__time_t  0xb4c
  #define modbus_statistics_cnt_message_all__uint32_t  0xb4f
  #define modbus_statistics_cnt_message_addressed__uint32_t  0xb51
  #define modbus_statistics_cnt_answer_timeout__uint32_t  0xb53
  #define modbus_statistics_cnt_message_badcrc__uint32_t  0xb55
  #define modbus_statistics_cnt_message_nak__uint32_t  0xb57
  #define modbus_statistics_cnt_message_overrun__uint32_t  0xb59
  #define modbus_statistics_cnt_message_othererr__uint32_t  0xb5b
  
  #define r_only_REGION_START 0x0
  #define r_only_REGION_STOP 0xb5d
  #define r_only_REGION_SIZE 2909
  
  /************ rw region ************/
  
  #define radiation_detector_counter_threshold_0__float  0xf45
  #define radiation_detector_counter_threshold_1__float  0xf47
  #define radiation_detector_counter_threshold_2__float  0xf49
  #define radiation_detector_counter_threshold_3__float  0xf4b
  #define radiation_detector_counter_threshold_4__float  0xf4d
  #define radiation_detector_counter_threshold_5__float  0xf4f
  #define radiation_detector_counter_threshold_6__float  0xf51
  #define radiation_detector_counter_threshold_7__float  0xf53
  #define radiation_detector_counter_threshold_8__float  0xf55
  #define radiation_detector_counter_threshold_9__float  0xf57
  #define radiation_detector_counter_interpretation_mode__uint16_t  0xf59
  #define radiation_detector_counter_interpretation_unit__uint16_t  0xf5a
  #define radiation_detector_dosimeter_threshold_0__float  0xf5b
  #define radiation_detector_dosimeter_threshold_1__float  0xf5d
  #define radiation_detector_dosimeter_threshold_2__float  0xf5f
  #define radiation_detector_dosimeter_threshold_3__float  0xf61
  #define radiation_detector_dosimeter_threshold_4__float  0xf63
  #define radiation_detector_dosimeter_threshold_5__float  0xf65
  #define radiation_detector_dosimeter_threshold_6__float  0xf67
  #define radiation_detector_dosimeter_threshold_7__float  0xf69
  #define radiation_detector_dosimeter_threshold_8__float  0xf6b
  #define radiation_detector_dosimeter_threshold_9__float  0xf6d
  #define radiation_detector_dosimeter_interpretation_mode__uint16_t  0xf6f
  #define radiation_detector_dosimeter_interpretation_unit__uint16_t  0xf70
  #define radiation_detector_radiometer_threshold_instant_activity__float  0xf71
  #define radiation_detector_radiometer_threshold_average_activity__float  0xf73
  #define radiation_detector_radiometer_threshold_instant_fluence__float  0xf75
  #define radiation_detector_radiometer_threshold_average_fluence__float  0xf77
  #define radiation_detector_radiometer_threshold_instant_flux_density__float  0xf79
  #define radiation_detector_radiometer_threshold_average_flux_density__float  0xf7b
  #define radiation_detector_radiometer_threshold_RESERVED_RW__float_10  0xf7d
  #define radiation_detector_radiometer_interpretation_mode__uint16_t  0xf91
  #define radiation_detector_radiometer_interpretation_unit__uint16_t  0xf92
  #define radiation_detector_spectrometer_options__uint8_t_120  0xf93
  #define radiation_detector_spectrometer_interpretation_mode__uint16_t  0xfcf
  #define radiation_detector_spectrometer_interpretation_unit__uint16_t  0xfd0
  #define radiation_detector_options_configuration_energy_range__uint16_t  0xfd1
  #define radiation_detector_options_configuration_exposure_range__uint16_t  0xfd2
  #define radiation_detector_options_configuration_measuring_circuit__uint16_t  0xfd3
  #define radiation_detector_options_configuration_measuring_mode__uint16_t  0xfd4
  #define radiation_detector_options_average_win__uint32_t  0xfd5
  #define radiation_detector_options_measurment_freq__uint32_t  0xfd7
  #define radiation_detector_log_RESERVED_RW__uint8_t_20  0xfd9
  #define clocks_time__time_t  0xfe3
  #define clocks_RESERVED_RW__time_t_3  0xfe6
  #define alarm_0_RESERVED__uint8_t_12  0xfef
  #define alarm_1_RESERVED__uint8_t_12  0xff5
  #define modbus_config_phy_layer_baudrate__uint32_t  0xffb
  #define modbus_config_phy_layer_parity__uint16_t  0xffd
  #define modbus_config_phy_layer_frame_size__uint16_t  0xffe
  #define modbus_config_phy_layer_stop_bits__uint16_t  0xfff
  #define modbus_config_channel_layer_tmode__uint16_t  0x1000
  #define modbus_config_channel_layer_address__uint16_t  0x1001
  
  #define rw_REGION_START 0xf45
  #define rw_REGION_STOP 0x1002
  #define rw_REGION_SIZE 189
  
  /************ rw_root region ************/
  
  #define identification_serial_num__uint32_t  0x13ea
  #define identification_manufacture_num__uint32_t  0x13ec
  #define identification_RESERVED_RW_ROOT__uint16_t_5  0x13ee
  #define radiation_detector_dosimeter_calibration_point_0_reference_val__float  0x13f3
  #define radiation_detector_dosimeter_calibration_point_0_average_val__float  0x13f5
  #define radiation_detector_dosimeter_calibration_point_0_RESERVED__float_10  0x13f7
  #define radiation_detector_dosimeter_calibration_point_1_reference_val__float  0x140b
  #define radiation_detector_dosimeter_calibration_point_1_average_val__float  0x140d
  #define radiation_detector_dosimeter_calibration_point_1_RESERVED__float_10  0x140f
  #define radiation_detector_dosimeter_calibration_point_2_reference_val__float  0x1423
  #define radiation_detector_dosimeter_calibration_point_2_average_val__float  0x1425
  #define radiation_detector_dosimeter_calibration_point_2_RESERVED__float_10  0x1427
  #define radiation_detector_dosimeter_calibration_point_3_reference_val__float  0x143b
  #define radiation_detector_dosimeter_calibration_point_3_average_val__float  0x143d
  #define radiation_detector_dosimeter_calibration_point_3_RESERVED__float_10  0x143f
  #define radiation_detector_dosimeter_calibration_point_4_reference_val__float  0x1453
  #define radiation_detector_dosimeter_calibration_point_4_average_val__float  0x1455
  #define radiation_detector_dosimeter_calibration_point_4_RESERVED__float_10  0x1457
  #define radiation_detector_dosimeter_calibration_point_5_reference_val__float  0x146b
  #define radiation_detector_dosimeter_calibration_point_5_average_val__float  0x146d
  #define radiation_detector_dosimeter_calibration_point_5_RESERVED__float_10  0x146f
  #define radiation_detector_dosimeter_calibration_point_6_reference_val__float  0x1483
  #define radiation_detector_dosimeter_calibration_point_6_average_val__float  0x1485
  #define radiation_detector_dosimeter_calibration_point_6_RESERVED__float_10  0x1487
  #define radiation_detector_dosimeter_calibration_point_7_reference_val__float  0x149b
  #define radiation_detector_dosimeter_calibration_point_7_average_val__float  0x149d
  #define radiation_detector_dosimeter_calibration_point_7_RESERVED__float_10  0x149f
  #define radiation_detector_dosimeter_calibration_point_8_reference_val__float  0x14b3
  #define radiation_detector_dosimeter_calibration_point_8_average_val__float  0x14b5
  #define radiation_detector_dosimeter_calibration_point_8_RESERVED__float_10  0x14b7
  #define radiation_detector_dosimeter_calibration_point_9_reference_val__float  0x14cb
  #define radiation_detector_dosimeter_calibration_point_9_average_val__float  0x14cd
  #define radiation_detector_dosimeter_calibration_point_9_RESERVED__float_10  0x14cf
  #define radiation_detector_radiometer_calibration_point_0_reference_val__float  0x14e3
  #define radiation_detector_radiometer_calibration_point_0_average_val__float  0x14e5
  #define radiation_detector_radiometer_calibration_point_0_RESERVED__float_10  0x14e7
  #define radiation_detector_radiometer_calibration_point_1_reference_val__float  0x14fb
  #define radiation_detector_radiometer_calibration_point_1_average_val__float  0x14fd
  #define radiation_detector_radiometer_calibration_point_1_RESERVED__float_10  0x14ff
  #define radiation_detector_radiometer_calibration_point_2_reference_val__float  0x1513
  #define radiation_detector_radiometer_calibration_point_2_average_val__float  0x1515
  #define radiation_detector_radiometer_calibration_point_2_RESERVED__float_10  0x1517
  #define radiation_detector_radiometer_calibration_point_3_reference_val__float  0x152b
  #define radiation_detector_radiometer_calibration_point_3_average_val__float  0x152d
  #define radiation_detector_radiometer_calibration_point_3_RESERVED__float_10  0x152f
  #define radiation_detector_radiometer_calibration_point_4_reference_val__float  0x1543
  #define radiation_detector_radiometer_calibration_point_4_average_val__float  0x1545
  #define radiation_detector_radiometer_calibration_point_4_RESERVED__float_10  0x1547
  #define radiation_detector_radiometer_calibration_point_5_reference_val__float  0x155b
  #define radiation_detector_radiometer_calibration_point_5_average_val__float  0x155d
  #define radiation_detector_radiometer_calibration_point_5_RESERVED__float_10  0x155f
  #define radiation_detector_radiometer_calibration_point_6_reference_val__float  0x1573
  #define radiation_detector_radiometer_calibration_point_6_average_val__float  0x1575
  #define radiation_detector_radiometer_calibration_point_6_RESERVED__float_10  0x1577
  #define radiation_detector_radiometer_calibration_point_7_reference_val__float  0x158b
  #define radiation_detector_radiometer_calibration_point_7_average_val__float  0x158d
  #define radiation_detector_radiometer_calibration_point_7_RESERVED__float_10  0x158f
  #define radiation_detector_radiometer_calibration_point_8_reference_val__float  0x15a3
  #define radiation_detector_radiometer_calibration_point_8_average_val__float  0x15a5
  #define radiation_detector_radiometer_calibration_point_8_RESERVED__float_10  0x15a7
  #define radiation_detector_radiometer_calibration_point_9_reference_val__float  0x15bb
  #define radiation_detector_radiometer_calibration_point_9_average_val__float  0x15bd
  #define radiation_detector_radiometer_calibration_point_9_RESERVED__float_10  0x15bf
  #define radiation_detector_coefficients_0__float  0x15d3
  #define radiation_detector_coefficients_1__float  0x15d5
  #define radiation_detector_coefficients_2__float  0x15d7
  #define radiation_detector_coefficients_3__float  0x15d9
  #define radiation_detector_coefficients_4__float  0x15db
  #define radiation_detector_coefficients_5__float  0x15dd
  #define radiation_detector_coefficients_6__float  0x15df
  #define radiation_detector_coefficients_7__float  0x15e1
  #define radiation_detector_coefficients_8__float  0x15e3
  #define radiation_detector_coefficients_9__float  0x15e5
  #define radiation_detector_coefficients_10__float  0x15e7
  #define radiation_detector_coefficients_11__float  0x15e9
  #define radiation_detector_coefficients_12__float  0x15eb
  #define radiation_detector_coefficients_13__float  0x15ed
  #define radiation_detector_coefficients_14__float  0x15ef
  #define radiation_detector_coefficients_15__float  0x15f1
  #define radiation_detector_coefficients_16__float  0x15f3
  #define radiation_detector_coefficients_17__float  0x15f5
  #define radiation_detector_coefficients_18__float  0x15f7
  #define radiation_detector_coefficients_19__float  0x15f9
  #define radiation_detector_coefficients_20__float  0x15fb
  #define radiation_detector_coefficients_21__float  0x15fd
  #define radiation_detector_coefficients_22__float  0x15ff
  #define radiation_detector_coefficients_23__float  0x1601
  #define radiation_detector_coefficients_24__float  0x1603
  #define radiation_detector_coefficients_25__float  0x1605
  #define radiation_detector_coefficients_26__float  0x1607
  #define radiation_detector_coefficients_27__float  0x1609
  #define radiation_detector_coefficients_28__float  0x160b
  #define radiation_detector_coefficients_29__float  0x160d
  #define clocks_calibration_time__time_t  0x160f
  #define clocks_manufacture_time__time_t  0x1612
  #define clocks_RESERVED_RW_ROOT__time_t_3  0x1615
  
  #define rw_root_REGION_START 0x13ea
  #define rw_root_REGION_STOP 0x161e
  #define rw_root_REGION_SIZE 564
  
  /************ r0w region ************/
  
  #define control_action__device_actions_t  0x1a06
  #define control_mode_on__device_mode_t  0x1a08
  #define control_mode_off__device_mode_t  0x1a0a
  #define control_signal_on__device_signals_t  0x1a0c
  #define control_signal_off__device_signals_t  0x1a0e
  #define control_password__uint8_t_32  0x1a10
  #define control_RESERVED_R0W__uint16_t_5  0x1a20
  #define radiation_detector_control_mode_on__radiation_detector_mode_t  0x1a25
  #define radiation_detector_control_mode_off__radiation_detector_mode_t  0x1a27
  #define radiation_detector_control_action__radiation_detector_action_t  0x1a29
  #define alarm_0_action__alarm_action_t  0x1a2b
  #define alarm_1_action__alarm_action_t  0x1a2c
  
  #define r0w_REGION_START 0x1a06
  #define r0w_REGION_STOP 0x1a2d
  #define r0w_REGION_SIZE 39
  
  /************ r0w_root region ************/
  
  #define radiation_detector_dosimeter_calibration_action__calibration_action_t  0x1e15
  #define radiation_detector_radiometer_calibration_action__calibration_action_t  0x1e16
  
  #define r0w_root_REGION_START 0x1e15
  #define r0w_root_REGION_STOP 0x1e17
  #define r0w_root_REGION_SIZE 2

 /************ TYPES SIZES DEFINES ************/
#define alarm_action_t_SIZE 0x2
#define alarm_flags_t_SIZE 0x2
#define alarm_t_SIZE 0x24
#define calibration_action_t_SIZE 0x2
#define calibration_point_t_SIZE 0x30
#define calibration_t_SIZE 0x32
#define counter_flags_t_SIZE 0x2
#define device_access_t_SIZE 0x2
#define device_actions_t_SIZE 0x4
#define device_flags_t_SIZE 0x4
#define device_mode_t_SIZE 0x4
#define device_signals_t_SIZE 0x4
#define dosimeter_flags_t_SIZE 0x2
#define float_SIZE 0x4
#define int16_t_SIZE 0x2
#define interpretation_t_SIZE 0x8
#define radiation_detector_action_t_SIZE 0x4
#define radiation_detector_configuration2_t_SIZE 0x2
#define radiation_detector_configuration_t_SIZE 0x8
#define radiation_detector_flags_t_SIZE 0x2
#define radiation_detector_mode_t_SIZE 0x4
#define radiometer_flags_t_SIZE 0x2
#define temperature_sensor_t_SIZE 0x4
#define time_t_SIZE 0x6
#define uint16_t_SIZE 0x2
#define uint32_t_SIZE 0x4
#define uint8_t_SIZE 0x1

 /************ BIT DEFINES ************/


/************ Bit defenitions for type 'alarm_action_t' ************/
   #define alarm_enable_action_POS ((uint32_t)0)
   #define alarm_enable_action_MASK ((uint32_t)1)
   #define alarm_disable_action_POS ((uint32_t)1)
   #define alarm_disable_action_MASK ((uint32_t)2)
   #define alarm_init_action_POS ((uint32_t)2)
   #define alarm_init_action_MASK ((uint32_t)4)
/************ Bit defenitions for type 'alarm_flags_t' ************/
   #define alarm_init_flag_POS ((uint32_t)0)
   #define alarm_init_flag_MASK ((uint32_t)1)
   #define alarm_error_flag_POS ((uint32_t)1)
   #define alarm_error_flag_MASK ((uint32_t)2)
/************ Bit defenitions for type 'calibration_action_t' ************/
   #define calculate_1_action_POS ((uint32_t)0)
   #define calculate_1_action_MASK ((uint32_t)1)
   #define calculate_2_action_POS ((uint32_t)1)
   #define calculate_2_action_MASK ((uint32_t)2)
/************ Bit defenitions for type 'counter_flags_t' ************/
   #define counter_error_flag_POS ((uint32_t)0)
   #define counter_error_flag_MASK ((uint32_t)1)
   #define counter_overload_flag_POS ((uint32_t)1)
   #define counter_overload_flag_MASK ((uint32_t)2)
 #define counter_threshold_exceeded_flag_SIZE ((uint32_t)10)
 #define counter_threshold_exceeded_flag_POS ((uint32_t)2)
 #define counter_threshold_exceeded_flag_MASK ((uint32_t)4092)
   #define counter_threshold_exceeded_flag_0_POS ((uint32_t)2)
   #define counter_threshold_exceeded_flag_0_MASK ((uint32_t)4)
   #define counter_threshold_exceeded_flag_1_POS ((uint32_t)3)
   #define counter_threshold_exceeded_flag_1_MASK ((uint32_t)8)
   #define counter_threshold_exceeded_flag_2_POS ((uint32_t)4)
   #define counter_threshold_exceeded_flag_2_MASK ((uint32_t)16)
   #define counter_threshold_exceeded_flag_3_POS ((uint32_t)5)
   #define counter_threshold_exceeded_flag_3_MASK ((uint32_t)32)
   #define counter_threshold_exceeded_flag_4_POS ((uint32_t)6)
   #define counter_threshold_exceeded_flag_4_MASK ((uint32_t)64)
   #define counter_threshold_exceeded_flag_5_POS ((uint32_t)7)
   #define counter_threshold_exceeded_flag_5_MASK ((uint32_t)128)
   #define counter_threshold_exceeded_flag_6_POS ((uint32_t)8)
   #define counter_threshold_exceeded_flag_6_MASK ((uint32_t)256)
   #define counter_threshold_exceeded_flag_7_POS ((uint32_t)9)
   #define counter_threshold_exceeded_flag_7_MASK ((uint32_t)512)
   #define counter_threshold_exceeded_flag_8_POS ((uint32_t)10)
   #define counter_threshold_exceeded_flag_8_MASK ((uint32_t)1024)
   #define counter_threshold_exceeded_flag_9_POS ((uint32_t)11)
   #define counter_threshold_exceeded_flag_9_MASK ((uint32_t)2048)
/************ Bit defenitions for type 'device_flags_t' ************/
   #define device_software_err_flag_POS ((uint32_t)0)
   #define device_software_err_flag_MASK ((uint32_t)1)
   #define device_clock_err_flag_POS ((uint32_t)1)
   #define device_clock_err_flag_MASK ((uint32_t)2)
   #define device_calibration_err_flag_POS ((uint32_t)2)
   #define device_calibration_err_flag_MASK ((uint32_t)4)
   #define device_other_data_err_flag_POS ((uint32_t)3)
   #define device_other_data_err_flag_MASK ((uint32_t)8)
   #define device_config_data_err_flag_POS ((uint32_t)4)
   #define device_config_data_err_flag_MASK ((uint32_t)16)
   #define device_calibration_spectrum_err_flag_POS ((uint32_t)5)
   #define device_calibration_spectrum_err_flag_MASK ((uint32_t)32)
   #define device_general_spectrum_err_flag_POS ((uint32_t)6)
   #define device_general_spectrum_err_flag_MASK ((uint32_t)64)
   #define device_rom_err_flag_POS ((uint32_t)7)
   #define device_rom_err_flag_MASK ((uint32_t)128)
   #define device_eeprom_err_flag_POS ((uint32_t)8)
   #define device_eeprom_err_flag_MASK ((uint32_t)256)
   #define device_fpga_err_flag_POS ((uint32_t)9)
   #define device_fpga_err_flag_MASK ((uint32_t)512)
   #define device_flash_err_flag_POS ((uint32_t)10)
   #define device_flash_err_flag_MASK ((uint32_t)1024)
   #define device_interrupt_err_flag_POS ((uint32_t)11)
   #define device_interrupt_err_flag_MASK ((uint32_t)2048)
   #define device_supply_voltage_err_flag_POS ((uint32_t)12)
   #define device_supply_voltage_err_flag_MASK ((uint32_t)4096)
   #define device_external_periph_err_flag_POS ((uint32_t)13)
   #define device_external_periph_err_flag_MASK ((uint32_t)8192)
   #define device_stabilization_sys_err_flag_POS ((uint32_t)14)
   #define device_stabilization_sys_err_flag_MASK ((uint32_t)16384)
   #define device_io_err_flag_POS ((uint32_t)15)
   #define device_io_err_flag_MASK ((uint32_t)32768)
   #define device_addr_err_flag_POS ((uint32_t)16)
   #define device_addr_err_flag_MASK ((uint32_t)65536)
   #define device_battery_discharged_flag_POS ((uint32_t)17)
   #define device_battery_discharged_flag_MASK ((uint32_t)131072)
/************ Bit defenitions for type 'device_mode_t' ************/
   #define sleep_mode_POS ((uint32_t)0)
   #define sleep_mode_MASK ((uint32_t)1)
   #define low_power_mode_POS ((uint32_t)1)
   #define low_power_mode_MASK ((uint32_t)2)
   #define setup_mode_POS ((uint32_t)2)
   #define setup_mode_MASK ((uint32_t)4)
   #define self_control_mode_POS ((uint32_t)3)
   #define self_control_mode_MASK ((uint32_t)8)
/************ Bit defenitions for type 'device_signals_t' ************/
 #define device_signal_SIZE ((uint32_t)20)
 #define device_signal_POS ((uint32_t)0)
 #define device_signal_MASK ((uint32_t)1048575)
   #define device_signal_0_POS ((uint32_t)0)
   #define device_signal_0_MASK ((uint32_t)1)
   #define device_signal_1_POS ((uint32_t)1)
   #define device_signal_1_MASK ((uint32_t)2)
   #define device_signal_2_POS ((uint32_t)2)
   #define device_signal_2_MASK ((uint32_t)4)
   #define device_signal_3_POS ((uint32_t)3)
   #define device_signal_3_MASK ((uint32_t)8)
   #define device_signal_4_POS ((uint32_t)4)
   #define device_signal_4_MASK ((uint32_t)16)
   #define device_signal_5_POS ((uint32_t)5)
   #define device_signal_5_MASK ((uint32_t)32)
   #define device_signal_6_POS ((uint32_t)6)
   #define device_signal_6_MASK ((uint32_t)64)
   #define device_signal_7_POS ((uint32_t)7)
   #define device_signal_7_MASK ((uint32_t)128)
   #define device_signal_8_POS ((uint32_t)8)
   #define device_signal_8_MASK ((uint32_t)256)
   #define device_signal_9_POS ((uint32_t)9)
   #define device_signal_9_MASK ((uint32_t)512)
   #define device_signal_10_POS ((uint32_t)10)
   #define device_signal_10_MASK ((uint32_t)1024)
   #define device_signal_11_POS ((uint32_t)11)
   #define device_signal_11_MASK ((uint32_t)2048)
   #define device_signal_12_POS ((uint32_t)12)
   #define device_signal_12_MASK ((uint32_t)4096)
   #define device_signal_13_POS ((uint32_t)13)
   #define device_signal_13_MASK ((uint32_t)8192)
   #define device_signal_14_POS ((uint32_t)14)
   #define device_signal_14_MASK ((uint32_t)16384)
   #define device_signal_15_POS ((uint32_t)15)
   #define device_signal_15_MASK ((uint32_t)32768)
   #define device_signal_16_POS ((uint32_t)16)
   #define device_signal_16_MASK ((uint32_t)65536)
   #define device_signal_17_POS ((uint32_t)17)
   #define device_signal_17_MASK ((uint32_t)131072)
   #define device_signal_18_POS ((uint32_t)18)
   #define device_signal_18_MASK ((uint32_t)262144)
   #define device_signal_19_POS ((uint32_t)19)
   #define device_signal_19_MASK ((uint32_t)524288)
/************ Bit defenitions for type 'dosimeter_flags_t' ************/
   #define dosimeter_error_flag_POS ((uint32_t)0)
   #define dosimeter_error_flag_MASK ((uint32_t)1)
   #define dosimeter_overload_flag_POS ((uint32_t)1)
   #define dosimeter_overload_flag_MASK ((uint32_t)2)
 #define dosimeter_threshold_exceeded_flag_SIZE ((uint32_t)10)
 #define dosimeter_threshold_exceeded_flag_POS ((uint32_t)2)
 #define dosimeter_threshold_exceeded_flag_MASK ((uint32_t)4092)
   #define dosimeter_threshold_exceeded_flag_0_POS ((uint32_t)2)
   #define dosimeter_threshold_exceeded_flag_0_MASK ((uint32_t)4)
   #define dosimeter_threshold_exceeded_flag_1_POS ((uint32_t)3)
   #define dosimeter_threshold_exceeded_flag_1_MASK ((uint32_t)8)
   #define dosimeter_threshold_exceeded_flag_2_POS ((uint32_t)4)
   #define dosimeter_threshold_exceeded_flag_2_MASK ((uint32_t)16)
   #define dosimeter_threshold_exceeded_flag_3_POS ((uint32_t)5)
   #define dosimeter_threshold_exceeded_flag_3_MASK ((uint32_t)32)
   #define dosimeter_threshold_exceeded_flag_4_POS ((uint32_t)6)
   #define dosimeter_threshold_exceeded_flag_4_MASK ((uint32_t)64)
   #define dosimeter_threshold_exceeded_flag_5_POS ((uint32_t)7)
   #define dosimeter_threshold_exceeded_flag_5_MASK ((uint32_t)128)
   #define dosimeter_threshold_exceeded_flag_6_POS ((uint32_t)8)
   #define dosimeter_threshold_exceeded_flag_6_MASK ((uint32_t)256)
   #define dosimeter_threshold_exceeded_flag_7_POS ((uint32_t)9)
   #define dosimeter_threshold_exceeded_flag_7_MASK ((uint32_t)512)
   #define dosimeter_threshold_exceeded_flag_8_POS ((uint32_t)10)
   #define dosimeter_threshold_exceeded_flag_8_MASK ((uint32_t)1024)
   #define dosimeter_threshold_exceeded_flag_9_POS ((uint32_t)11)
   #define dosimeter_threshold_exceeded_flag_9_MASK ((uint32_t)2048)
/************ Bit defenitions for type 'radiation_detector_action_t' ************/
   #define rd_restart_measurment_action_POS ((uint32_t)0)
   #define rd_restart_measurment_action_MASK ((uint32_t)1)
   #define rd_set_average_as_background_action_POS ((uint32_t)1)
   #define rd_set_average_as_background_action_MASK ((uint32_t)2)
   #define rd_perform_stabilization_action_POS ((uint32_t)2)
   #define rd_perform_stabilization_action_MASK ((uint32_t)4)
   #define rd_clear_spectrum_action_POS ((uint32_t)3)
   #define rd_clear_spectrum_action_MASK ((uint32_t)8)
   #define rd_store_speflagsctrum_action_POS ((uint32_t)4)
   #define rd_store_speflagsctrum_action_MASK ((uint32_t)16)
   #define rd_load_spectrum_action_POS ((uint32_t)5)
   #define rd_load_spectrum_action_MASK ((uint32_t)32)
   #define rd_clear_dose_action_POS ((uint32_t)6)
   #define rd_clear_dose_action_MASK ((uint32_t)64)
   #define rd_set_average_as_base_action_POS ((uint32_t)7)
   #define rd_set_average_as_base_action_MASK ((uint32_t)128)
/************ Bit defenitions for type 'radiation_detector_configuration2_t' ************/
   #define counter_module_POS ((uint32_t)0)
   #define counter_module_MASK ((uint32_t)1)
   #define dosimeter_module_POS ((uint32_t)1)
   #define dosimeter_module_MASK ((uint32_t)2)
   #define radiometer_module_POS ((uint32_t)2)
   #define radiometer_module_MASK ((uint32_t)4)
   #define spectrometer_module_POS ((uint32_t)3)
   #define spectrometer_module_MASK ((uint32_t)8)
/************ Bit defenitions for type 'radiation_detector_flags_t' ************/
   #define rd_initializing_flag_POS ((uint32_t)0)
   #define rd_initializing_flag_MASK ((uint32_t)1)
   #define rd_error_flag_POS ((uint32_t)1)
   #define rd_error_flag_MASK ((uint32_t)2)
   #define rd_overload_flag_POS ((uint32_t)2)
   #define rd_overload_flag_MASK ((uint32_t)4)
   #define rd_thrsh_exceded_flag_POS ((uint32_t)3)
   #define rd_thrsh_exceded_flag_MASK ((uint32_t)8)
   #define rd_hv_error_flag_POS ((uint32_t)4)
   #define rd_hv_error_flag_MASK ((uint32_t)16)
   #define rd_hvreg_error_flag_POS ((uint32_t)5)
   #define rd_hvreg_error_flag_MASK ((uint32_t)32)
   #define rd_led_error_flag_POS ((uint32_t)6)
   #define rd_led_error_flag_MASK ((uint32_t)64)
/************ Bit defenitions for type 'radiation_detector_mode_t' ************/
   #define backgnd_substraction_mode_POS ((uint32_t)0)
   #define backgnd_substraction_mode_MASK ((uint32_t)1)
   #define search_mode_POS ((uint32_t)1)
   #define search_mode_MASK ((uint32_t)2)
   #define search_sound_mode_POS ((uint32_t)2)
   #define search_sound_mode_MASK ((uint32_t)4)
   #define spectrometer_mode_POS ((uint32_t)3)
   #define spectrometer_mode_MASK ((uint32_t)8)
   #define strobe_mode_POS ((uint32_t)4)
   #define strobe_mode_MASK ((uint32_t)16)
   #define temperature_correction_mode_POS ((uint32_t)5)
   #define temperature_correction_mode_MASK ((uint32_t)32)
   #define auto_exposure_range_mode_POS ((uint32_t)6)
   #define auto_exposure_range_mode_MASK ((uint32_t)64)
   #define led_on_spectrum_mode_POS ((uint32_t)7)
   #define led_on_spectrum_mode_MASK ((uint32_t)128)
   #define hv_dc_dc_mode_POS ((uint32_t)8)
   #define hv_dc_dc_mode_MASK ((uint32_t)256)
   #define measurment_stoped_mode_POS ((uint32_t)9)
   #define measurment_stoped_mode_MASK ((uint32_t)512)
   #define spectrum_accum_mode_POS ((uint32_t)10)
   #define spectrum_accum_mode_MASK ((uint32_t)1024)
/************ Bit defenitions for type 'radiometer_flags_t' ************/
   #define radiometer_error_flag_POS ((uint32_t)0)
   #define radiometer_error_flag_MASK ((uint32_t)1)
   #define radiometer_overload_flag_POS ((uint32_t)1)
   #define radiometer_overload_flag_MASK ((uint32_t)2)
 #define radiometer_threshold_exceeded_flag_SIZE ((uint32_t)10)
 #define radiometer_threshold_exceeded_flag_POS ((uint32_t)2)
 #define radiometer_threshold_exceeded_flag_MASK ((uint32_t)4092)
   #define radiometer_threshold_exceeded_flag_0_POS ((uint32_t)2)
   #define radiometer_threshold_exceeded_flag_0_MASK ((uint32_t)4)
   #define radiometer_threshold_exceeded_flag_1_POS ((uint32_t)3)
   #define radiometer_threshold_exceeded_flag_1_MASK ((uint32_t)8)
   #define radiometer_threshold_exceeded_flag_2_POS ((uint32_t)4)
   #define radiometer_threshold_exceeded_flag_2_MASK ((uint32_t)16)
   #define radiometer_threshold_exceeded_flag_3_POS ((uint32_t)5)
   #define radiometer_threshold_exceeded_flag_3_MASK ((uint32_t)32)
   #define radiometer_threshold_exceeded_flag_4_POS ((uint32_t)6)
   #define radiometer_threshold_exceeded_flag_4_MASK ((uint32_t)64)
   #define radiometer_threshold_exceeded_flag_5_POS ((uint32_t)7)
   #define radiometer_threshold_exceeded_flag_5_MASK ((uint32_t)128)
   #define radiometer_threshold_exceeded_flag_6_POS ((uint32_t)8)
   #define radiometer_threshold_exceeded_flag_6_MASK ((uint32_t)256)
   #define radiometer_threshold_exceeded_flag_7_POS ((uint32_t)9)
   #define radiometer_threshold_exceeded_flag_7_MASK ((uint32_t)512)
   #define radiometer_threshold_exceeded_flag_8_POS ((uint32_t)10)
   #define radiometer_threshold_exceeded_flag_8_MASK ((uint32_t)1024)
   #define radiometer_threshold_exceeded_flag_9_POS ((uint32_t)11)
   #define radiometer_threshold_exceeded_flag_9_MASK ((uint32_t)2048)

/************************************************************/

/********** LAT types **********/
/********** types from 'JSON LAT types' **********/
  typedef uint16_t alarm_action_t;
  typedef uint16_t alarm_flags_t;
  __PACKED typedef struct {
   alarm_flags_t flags;
   float accum_dose;
   float max_drate;
   time_t start_time;
   time_t duration;
  }alarm_t__r_only PACKED__;
  __PACKED typedef struct {
   uint8_t RESERVED[12];
  }alarm_t__rw PACKED__;
  __PACKED typedef struct {
   alarm_action_t action;
  }alarm_t__r0w PACKED__;
  typedef uint16_t calibration_action_t;
  __PACKED typedef struct {
   float reference_val;
   float average_val;
   float RESERVED[10];
  }calibration_point_t PACKED__;
  __PACKED typedef struct {
   calibration_point_t point_0;
   calibration_point_t point_1;
   calibration_point_t point_2;
   calibration_point_t point_3;
   calibration_point_t point_4;
   calibration_point_t point_5;
   calibration_point_t point_6;
   calibration_point_t point_7;
   calibration_point_t point_8;
   calibration_point_t point_9;
  }calibration_t__rw_root PACKED__;
  __PACKED typedef struct {
   calibration_action_t action;
  }calibration_t__r0w_root PACKED__;
  typedef uint16_t counter_flags_t;
  typedef uint16_t device_access_t;
  typedef uint32_t device_actions_t;
  typedef uint32_t device_flags_t;
  typedef uint32_t device_mode_t;
  typedef uint32_t device_signals_t;
  typedef uint16_t dosimeter_flags_t;
  __PACKED typedef struct {
   uint16_t radiation_type;
   uint16_t average_alg;
  }interpretation_t__r_only PACKED__;
  __PACKED typedef struct {
   uint16_t mode;
   uint16_t unit;
  }interpretation_t__rw PACKED__;
  typedef uint32_t radiation_detector_action_t;
  typedef uint16_t radiation_detector_configuration2_t;
  __PACKED typedef struct {
   uint16_t energy_range;
   uint16_t exposure_range;
   uint16_t measuring_circuit;
   uint16_t measuring_mode;
  }radiation_detector_configuration_t PACKED__;
  typedef uint16_t radiation_detector_flags_t;
  typedef uint32_t radiation_detector_mode_t;
  typedef uint16_t radiometer_flags_t;
  __PACKED typedef struct {
   int16_t temperature;
   alarm_flags_t flags;
  }temperature_sensor_t PACKED__;
/********** types from 'JSON LAT' **********/
 /********** r_only types **********/
 __PACKED typedef struct {
   __PACKED typedef struct {
     uint32_t lat_ver;
     uint32_t device_code;
     uint32_t firmware_ver;
     uint32_t hardware_ver;
     uint32_t rom_ver;
     uint16_t RESERVED_R_ONLY[5];
   }identification_t__r_only PACKED__;
   identification_t__r_only identification;
   __PACKED typedef struct {
     uint8_t reference_val[512];
     uint8_t calulated_val[512];
     uint16_t length;
     uint32_t algorithm;
     uint16_t RESERVED_R_ONLY[5];
   }hashsum_t PACKED__;
   hashsum_t hashsum;
   __PACKED typedef struct {
     device_mode_t mode;
     device_flags_t flags;
     device_signals_t signals;
     device_access_t access;
     uint16_t battery_charge;
     uint16_t fRESERVED_R_ONLY[5];
   }status_t PACKED__;
   status_t status;
   __PACKED typedef struct {
     __PACKED typedef struct {
       __PACKED typedef struct {
         float instant_count_rate;
         float average_count_rate;
         float average_sko;
         float background_count_rate;
         float background_sko;
         float RESERVED_R_ONLY[10];
       }results_t PACKED__;
       results_t results;
       uint16_t flags;
       interpretation_t__r_only interpretation;
     }counter_t__r_only PACKED__;
     counter_t__r_only counter;
     __PACKED typedef struct {
       __PACKED typedef struct {
         float instant_drate;
         float average_drate;
         float average_sko;
         float backgnd_drate;
         float backgnd_sko;
         float measurment_dose;
         float pwron_dose;
         float lifetime_dose;
         float RESERVED_R_ONLY[8];
       }results_t PACKED__;
       results_t results;
       uint16_t flags;
       interpretation_t__r_only interpretation;
     }dosimeter_t__r_only PACKED__;
     dosimeter_t__r_only dosimeter;
     __PACKED typedef struct {
       __PACKED typedef struct {
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
       }result_t PACKED__;
       result_t result;
       radiometer_flags_t flags;
       interpretation_t__r_only interpretation;
     }radiometer_t__r_only PACKED__;
     radiometer_t__r_only radiometer;
     __PACKED typedef struct {
       uint8_t results[4200];
       interpretation_t__r_only interpretation;
     }spectrometer_t__r_only PACKED__;
     spectrometer_t__r_only spectrometer;
     __PACKED typedef struct {
       radiation_detector_configuration_t configuration;
       radiation_detector_configuration2_t rd_sub_devices;
       uint8_t RESERVED_R_ONLY[160];
     }capabilities_t PACKED__;
     capabilities_t capabilities;
     __PACKED typedef struct {
       radiation_detector_flags_t flags;
       radiation_detector_mode_t mode;
     }status_t PACKED__;
     status_t status;
     __PACKED typedef struct {
       uint8_t RESERVED_R_ONLY[10];
     }log_t__r_only PACKED__;
     log_t__r_only log;
   }radiation_detector_t__r_only PACKED__;
   radiation_detector_t__r_only radiation_detector;
   __PACKED typedef struct {
     time_t pwron_time;
     time_t life_time;
     time_t meas_duration;
     alarm_flags_t flags;
     time_t RESERVED_R_ONLY[3];
   }clocks_t__r_only PACKED__;
   clocks_t__r_only clocks;
   temperature_sensor_t temperature_sensor;
   alarm_t__r_only alarm_0;
   alarm_t__r_only alarm_1;
   __PACKED typedef struct {
     __PACKED typedef struct {
       uint32_t cnt_message_all;
       uint32_t cnt_message_addressed;
       uint32_t cnt_answer_timeout;
       uint32_t cnt_message_badcrc;
       uint32_t cnt_message_nak;
       uint32_t cnt_message_overrun;
       uint32_t cnt_message_othererr;
     }statistics_t PACKED__;
     statistics_t statistics;
   }modbus_t__r_only PACKED__;
   modbus_t__r_only modbus;
 }device_t__r_only PACKED__;
 /********** rw types **********/
 __PACKED typedef struct {
   __PACKED typedef struct {
     __PACKED typedef struct {
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
       interpretation_t__rw interpretation;
     }counter_t__rw PACKED__;
     counter_t__rw counter;
     __PACKED typedef struct {
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
       interpretation_t__rw interpretation;
     }dosimeter_t__rw PACKED__;
     dosimeter_t__rw dosimeter;
     __PACKED typedef struct {
       __PACKED typedef struct {
         float instant_activity;
         float average_activity;
         float instant_fluence;
         float average_fluence;
         float instant_flux_density;
         float average_flux_density;
         float RESERVED_RW[10];
       }threshold_t PACKED__;
       threshold_t threshold;
       interpretation_t__rw interpretation;
     }radiometer_t__rw PACKED__;
     radiometer_t__rw radiometer;
     __PACKED typedef struct {
       uint8_t options[120];
       interpretation_t__rw interpretation;
     }spectrometer_t__rw PACKED__;
     spectrometer_t__rw spectrometer;
     __PACKED typedef struct {
       radiation_detector_configuration_t__rw configuration;
       uint32_t average_win;
       uint32_t measurment_freq;
     }options_t__rw PACKED__;
     options_t__rw options;
     __PACKED typedef struct {
       uint8_t RESERVED_RW[20];
     }log_t__rw PACKED__;
     log_t__rw log;
   }radiation_detector_t__rw PACKED__;
   radiation_detector_t__rw radiation_detector;
   __PACKED typedef struct {
     time_t time;
     time_t RESERVED_RW[3];
   }clocks_t__rw PACKED__;
   clocks_t__rw clocks;
   alarm_t__rw alarm_0;
   alarm_t__rw alarm_1;
   __PACKED typedef struct {
     __PACKED typedef struct {
       __PACKED typedef struct {
         uint32_t baudrate;
         uint16_t parity;
         uint16_t frame_size;
         uint16_t stop_bits;
       }phy_layer_t PACKED__;
       phy_layer_t phy_layer;
       __PACKED typedef struct {
         uint16_t tmode;
         uint16_t address;
       }channel_layer_t PACKED__;
       channel_layer_t channel_layer;
     }config_t PACKED__;
     config_t config;
   }modbus_t__rw PACKED__;
   modbus_t__rw modbus;
 }device_t__rw PACKED__;
 /********** rw_root types **********/
 __PACKED typedef struct {
   __PACKED typedef struct {
     uint32_t serial_num;
     uint32_t manufacture_num;
     uint16_t RESERVED_RW_ROOT[5];
   }identification_t__rw_root PACKED__;
   identification_t__rw_root identification;
   __PACKED typedef struct {
     __PACKED typedef struct {
       calibration_t__rw_root calibration;
     }dosimeter_t__rw_root PACKED__;
     dosimeter_t__rw_root dosimeter;
     __PACKED typedef struct {
       calibration_t__rw_root calibration;
     }radiometer_t__rw_root PACKED__;
     radiometer_t__rw_root radiometer;
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
   }radiation_detector_t__rw_root PACKED__;
   radiation_detector_t__rw_root radiation_detector;
   __PACKED typedef struct {
     time_t calibration_time;
     time_t manufacture_time;
     time_t RESERVED_RW_ROOT[3];
   }clocks_t__rw_root PACKED__;
   clocks_t__rw_root clocks;
 }device_t__rw_root PACKED__;
 /********** r0w types **********/
 __PACKED typedef struct {
   __PACKED typedef struct {
     device_actions_t action;
     device_mode_t mode_on;
     device_mode_t mode_off;
     device_signals_t signal_on;
     device_signals_t signal_off;
     uint8_t password[32];
     uint16_t RESERVED_R0W[5];
   }control_t PACKED__;
   control_t control;
   __PACKED typedef struct {
     __PACKED typedef struct {
       radiation_detector_mode_t mode_on;
       radiation_detector_mode_t mode_off;
       radiation_detector_action_t action;
     }control_t PACKED__;
     control_t control;
   }radiation_detector_t__r0w PACKED__;
   radiation_detector_t__r0w radiation_detector;
   alarm_t__r0w alarm_0;
   alarm_t__r0w alarm_1;
 }device_t__r0w PACKED__;
 /********** r0w_root types **********/
 __PACKED typedef struct {
   __PACKED typedef struct {
     __PACKED typedef struct {
       calibration_t__r0w_root calibration;
     }dosimeter_t__r0w_root PACKED__;
     dosimeter_t__r0w_root dosimeter;
     __PACKED typedef struct {
       calibration_t__r0w_root calibration;
     }radiometer_t__r0w_root PACKED__;
     radiometer_t__r0w_root radiometer;
   }radiation_detector_t__r0w_root PACKED__;
   radiation_detector_t__r0w_root radiation_detector;
 }device_t__r0w_root PACKED__;