
[
    { "type_declaration" : { "name" : "float", "size" : 4 }},
    { "type_declaration" : { "name" : "uint8_t", "size" : 1	}},
    { "type_declaration" : { "name" : "uint16_t", "size" : 2 }},
    { "type_declaration" : { "name" : "uint32_t", "size" : 4 }},
    { "type_declaration" : { "name" : "int16_t", "size" : 2 }},
    { "type_declaration" : { "name" : "time_t", "size" : 6  }},
    { "type_declaration" : {
            "name": "device_flags_t",
            "size": 4,
            "bitfield": [
                {"name": "device_software_err_flag", "size": 1, "comment": "some comment"},
                {"name": "device_clock_err_flag", "size": 1, "comment": "some comment"},
                {"name": "device_calibration_err_flag", "size": 1, "comment": "some comment"},
                {"name": "device_other_data_err_flag", "size": 1, "comment": "some comment"},
                {"name": "device_config_data_err_flag", "size": 1, "comment": "some comment"},
                {"name": "device_calibration_spectrum_err_flag", "size": 1, "comment": "some comment"},
                {"name": "device_general_spectrum_err_flag", "size": 1, "comment": "some comment"},
                {"name": "device_rom_err_flag", "size": 1, "comment": "some comment"},
                {"name": "device_eeprom_err_flag", "size": 1, "comment": "some comment"},
                {"name": "device_fpga_err_flag", "size": 1, "comment": "some comment"},
                {"name": "device_flash_err_flag", "size": 1, "comment": "some comment"},
                {"name": "device_interrupt_err_flag", "size": 1, "comment": "some comment"},
                {"name": "device_supply_voltage_err_flag", "size": 1, "comment": "some comment"},
                {"name": "device_external_periph_err_flag", "size": 1, "comment": "some comment"},
                {"name": "device_stabilization_sys_err_flag", "size": 1, "comment": "some comment"},
                {"name": "device_io_err_flag", "size": 1, "comment": "some comment"},
                {"name": "device_addr_err_flag", "size": 1, "comment": "some comment"},
                {"name": "device_battery_discharged_flag", "size": 1, "comment": "some comment"}
            ]
        }
    },
    { "type_declaration" : {
            "name" :    "device_access_t",
            "size" :    2
        }
    },
    { "type_declaration" : {
            "name" : "device_signals_t",
            "size" : 4,
            "bitfield" : { "name" : "device_signal", "size" : 20, "comment" : "some comment" }
        }
    },
    { "type_declaration" : {
            "name" : "device_mode_t",
            "size" : 4,
            "bitfield" : [
                { "name" : "sleep_mode", "size" : 1, "comment" : "some comment" },
                { "name" : "low_power_mode", "size" : 1, "comment" : "some comment" },
                { "name" : "setup_mode", "size" : 1, "comment" : "some comment" },
                { "name" : "self_control_mode", "size" : 1, "comment" : "some comment" }
            ]
        }
    },
    { "type_declaration" : {
            "name" : "device_actions_t",
            "size" : 4
        }
    },
    { "type_declaration" : {
            "name" : "alarm_flags_t",
            "size" : 2,
            "bitfield" : [
                { "name" : "alarm_init_flag", "size" : 1, "comment" : "some comment" },
                { "name" : "alarm_error_flag", "size" : 1, "comment" : "some comment" }
            ]
        }
    },
    { "type_declaration" : {
        "name" : "alarm_action_t",
        "size" : 2,
        "bitfield" : [
            { "name" : "alarm_enable_action", "size" : 1, "comment" : "some comment" },
            { "name" : "alarm_disable_action", "size" : 1, "comment" : "some comment" },
            { "name" : "alarm_init_action", "size" : 1, "comment" : "some comment" }
        ]
    }
    },
    { "type_declaration" : {
            "name"        : "alarm_t",
            "action"      : { "attr" : "r0w", "type" : "alarm_action_t", "cnt" : 1 },
            "flags"       : { "attr" : "r_only", "type" : "alarm_flags_t", "cnt" : 1 },
            "accum_dose"  : { "attr" : "r_only", "type" : "float", "cnt" : 1 },
            "max_drate"   : { "attr" : "r_only", "type" : "float", "cnt" : 1 },
            "start_time" :  { "attr" : "r_only", "type" : "time_t", "cnt" : 1 },
            "duration" :    { "attr" : "r_only", "type" : "time_t", "cnt" : 1 },
            "RESERVED" :    { "attr" : "r_only", "type" : "uint8_t", "cnt" : 1, "arraysize" : 40 },
            "RESERVED" :    { "attr" : "rw", "type" : "uint8_t", "cnt" : 1, "arraysize" : 12 }
        }
    },
    { "type_declaration" : {
            "name": "temperature_sensor_t",
            "temperature": {"attr": "r_only", "type": "int16_t", "cnt": 1},
            "flags": {"attr": "r_only", "type": "alarm_flags_t", "cnt": 1}
        }
    },
    { "type_declaration" : {
            "name" : "radiation_detector_mode_t",
            "size" : 4,
            "bitfield" : [
                { "name" : "backgnd_substraction_mode", "size" : 1, "comment" : "some comment" },
                { "name" : "search_mode", "size" : 1, "comment" : "some comment" },
                { "name" : "search_sound_mode", "size" : 1, "comment" : "some comment" },
                { "name" : "spectrometer_mode", "size" : 1, "comment" : "some comment" },
                { "name" : "strobe_mode", "size" : 1, "comment" : "some comment" },
                { "name" : "temperature_correction_mode", "size" : 1, "comment" : "some comment" },
                { "name" : "auto_exposure_range_mode", "size" : 1, "comment" : "some comment" },
                { "name" : "led_on_spectrum_mode", "size" : 1, "comment" : "some comment" },
                { "name" : "hv_dc_dc_mode", "size" : 1, "comment" : "some comment" },
                { "name" : "measurment_stoped_mode", "size" : 1, "comment" : "some comment" },
                { "name" : "spectrum_accum_mode", "size" : 1, "comment" : "some comment" }
                ]
        }
    },
    { "type_declaration" : {
            "name" : "radiation_detector_action_t",
            "size" : 4,
            "bitfield" : [
                { "name" : "rd_restart_measurment_action", "size" : 1, "comment" : "some comment" },
                { "name" : "rd_set_average_as_background_action", "size" : 1, "comment" : "some comment" },
                { "name" : "rd_perform_stabilization_action", "size" : 1, "comment" : "some comment" },
                { "name" : "rd_clear_spectrum_action", "size" : 1, "comment" : "some comment" },
                { "name" : "rd_store_speflagsctrum_action", "size" : 1, "comment" : "some comment" },
                { "name" : "rd_load_spectrum_action", "size" : 1, "comment" : "some comment" },
                { "name" : "rd_clear_dose_action", "size" : 1, "comment" : "some comment" },
                { "name" : "rd_set_average_as_base_action", "size" : 1, "comment" : "some comment" }
            ]
        }
    },
    { "type_declaration" : {
            "name" : "radiation_detector_configuration_t",
            "energy_range" : { "attr" : "r_only", "type" : "uint16_t", "cnt"  : 1 },
            "exposure_range" : { "attr" : "r_only", "type" : "uint16_t", "cnt"  : 1 },
            "measuring_circuit" : { "attr" : "r_only", "type" : "uint16_t", "cnt"  : 1 },
            "measuring_mode" : { "attr" : "r_only", "type" : "uint16_t", "cnt"  : 1 }
        }
    },
    { "type_declaration" : {
            "name" : "radiation_detector_configuration2_t",
            "size" : 2,
            "bitfield" : [
                { "name" : "counter_module", "size" : 1, "comment" : "some comment" },
                { "name" : "dosimeter_module", "size" : 1, "comment" : "some comment" },
                { "name" : "radiometer_module", "size" : 1, "comment" : "some comment" },
                { "name" : "spectrometer_module", "size" : 1, "comment" : "some comment" }
            ]
       }
    },
    { "type_declaration" : {
            "name" : "radiation_detector_flags_t",
            "size" : 2,
            "bitfield" : [
                { "name" : "rd_initializing_flag", "size" : 1, "comment" : "some comment" },
                { "name" : "rd_error_flag", "size" : 1, "comment" : "some comment" },
                { "name" : "rd_overload_flag", "size" : 1, "comment" : "some comment" },
                { "name" : "rd_thrsh_exceded_flag", "size" : 1, "comment" : "some comment" },
                { "name" : "rd_hv_error_flag", "size" : 1, "comment" : "some comment" },
                { "name" : "rd_hvreg_error_flag", "size" : 1, "comment" : "some comment" },
                { "name" : "rd_led_error_flag", "size" : 1, "comment" : "some comment" }
            ]
        }
    },
    { "type_declaration" : {
            "name" : "interpretation_t",
            "mode" : { "attr" : "rw",  "type" : "uint16_t", "cnt" : 1 },
            "unit" : { "attr" : "rw",  "type" : "uint16_t", "cnt" : 1 },
            "radiation_type" : { "attr" : "r_only",  "type" : "uint16_t", "cnt" : 1 },
            "average_alg" : { "attr" : "r_only",  "type" : "uint16_t", "cnt" : 1 }
        }
    },
    { "type_declaration" : {
            "name" : "counter_flags_t",
            "size" : 2,
            "bitfield" : [
                { "name" : "counter_error_flag", "size" : 1, "comment" : "some comment" },
                { "name" : "counter_overload_flag", "size" : 1, "comment" : "some comment" },
                { "name" : "counter_threshold_exceeded_flag", "size" : 10, "comment" : "some comment" }
            ]
        }
    },
    { "type_declaration" : {
            "name" : "dosimeter_flags_t",
            "size" : 2,
            "bitfield" : [
                { "name" : "dosimeter_error_flag", "size" : 1, "comment" : "some comment" },
                { "name" : "dosimeter_overload_flag", "size" : 1, "comment" : "some comment" },
                { "name" : "dosimeter_threshold_exceeded_flag", "size" : 10, "comment" : "some comment" }
            ]
        }
    },
    { "type_declaration" : {
            "name" : "radiometer_flags_t",
            "size" : 2,
            "bitfield" : [
                { "name" : "radiometer_error_flag", "size" : 1, "comment" : "some comment" },
                { "name" : "radiometer_overload_flag", "size" : 1, "comment" : "some comment" },
                { "name" : "radiometer_threshold_exceeded_flag", "size" : 10, "comment" : "some comment" }
            ]
        }
    },
    { "type_declaration": {
        "name": "calibration_point_t",
        "reference_val": {"attr": "rw_root", "type": "float", "cnt": 1},
        "average_val": {"attr": "rw_root", "type": "float", "cnt": 1},
        "RESERVED": {"attr": "rw_root", "type": "float", "cnt": 1 , "arraysize" : 10 }
        }
    },
    { "type_declaration": {
            "name" : "calibration_action_t",
            "size" : 2,
            "bitfield" : [
                { "name" : "calculate_1_action", "size" : 1, "comment" : "some comment" },
                { "name" : "calculate_2_action", "size" : 1, "comment" : "some comment" }
            ]
        }
    },
    { "type_declaration": {
        "name": "calibration_t",
        "point" :  { "attr" : "rw_root", "type" : "calibration_point_t", "cnt" : 10 },
        "action" : { "attr" : "r0w_root", "type" : "calibration_action_t", "cnt" : 1 }
        }
    }
]

