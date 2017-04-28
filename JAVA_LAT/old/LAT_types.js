
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
                {"name": "err_software", "size": 1, "comment": "some comment"},
                {"name": "err_clock", "size": 1, "comment": "some comment"},
                {"name": "err_calibration", "size": 1, "comment": "some comment"},
                {"name": "err_other_data", "size": 1, "comment": "some comment"},
                {"name": "err_config_data", "size": 1, "comment": "some comment"},
                {"name": "err_calibration_spectrum", "size": 1, "comment": "some comment"},
                {"name": "err_general_spectrum", "size": 1, "comment": "some comment"},
                {"name": "err_rom", "size": 1, "comment": "some comment"},
                {"name": "err_rom", "size": 1, "comment": "some comment"},
                {"name": "err_eeprom", "size": 1, "comment": "some comment"},
                {"name": "err_fpga", "size": 1, "comment": "some comment"},
                {"name": "err_flash", "size": 1, "comment": "some comment"},
                {"name": "err_interrupt", "size": 1, "comment": "some comment"},
                {"name": "err_supply_voltage", "size": 1, "comment": "some comment"},
                {"name": "err_external_periph", "size": 1, "comment": "some comment"},
                {"name": "err_stabilization_sys", "size": 1, "comment": "some comment"},
                {"name": "err_io", "size": 1, "comment": "some comment"},
                {"name": "err_addr", "size": 1, "comment": "some comment"},
                {"name": "battery_discharged", "size": 1, "comment": "some comment"}
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
            "bitfield" : { "name" : "signal", "size" : 20, "comment" : "some comment" }
        }
    },
    { "type_declaration" : {
            "name" : "device_mode_t",
            "size" : 4,
            "bitfield" : { "name" : "root_permission", "size" : 1, "comment" : "some comment" }
        }
    },
    { "type_declaration" : {
            "name" : "device_actions_t",
            "size" : 4,
            "bitfield" : [
                { "name" : "device_pwr_on", "size" : 1, "comment" : "some comment" },
                { "name" : "device_pwr_off", "size" : 1, "comment" : "some comment" }
            ]
        }
    },
    { "type_declaration" : {
            "name" : "modbus_phy_layer_options_t",
            "size" : 4,
            "bitfield" : { "name" : "parity", "size" : 3, "comment" : "some comment" },
            "bitfield" : { "name" : "frame_size", "size" : 3, "comment" : "some comment" },
            "bitfield" : { "name" : "stop_bits", "size" : 3, "comment" : "some comment" }
        }
    },
    { "type_declaration" : {
            "name" : "alarm_flags_t",
            "size" : 2,
            "bitfield" : [
                { "name" : "init", "size" : 1, "comment" : "some comment" },
                { "name" : "error", "size" : 1, "comment" : "some comment" }
            ]
        }
    },
    { "type_declaration" : {
            "name"        : "alarm_t",
            "flags"       : { "attr" : "r_only",  "type" : "alarm_flags_t", "cnt" : 1 },
            "accum_dose"  : { "attr" : "r_only",  "type" : "float", "cnt" : 1 },
            "max_drate"   : { "attr" : "r_only",  "type" : "float", "cnt" : 1 },
            "on_time"     : { "attr" : "r_only",  "type" : "time_t", "cnt" : 1 },
            "on_duration" : { "attr" : "r_only",  "type" : "time_t", "cnt" : 1 }
        }
    },
    { "type_declaration" : {
            "name": "temperature_sensor_t",
            "size": 4,
            "temperature": {"attr": "r_only", "type": "int16_t", "cnt": 1},
            "flags": {"attr": "r_only", "type": "alarm_flags_t", "cnt": 1}
        }
    },
    { "type_declaration" : {
            "name" : "radiation_detector_mode_t",
            "size" : 4,
            "bitfield" : [
                { "name" : "backgnd_substraction", "size" : 1, "comment" : "some comment" },
                { "name" : "search", "size" : 1, "comment" : "some comment" },
                { "name" : "spectrometer", "size" : 1, "comment" : "some comment" },
                { "name" : "low_power", "size" : 1, "comment" : "some comment" },
                { "name" : "setup", "size" : 1, "comment" : "some comment" },
                { "name" : "strobe", "size" : 1, "comment" : "some comment" },
                { "name" : "self_control", "size" : 1, "comment" : "some comment" },
                { "name" : "temperature_correction", "size" : 1, "comment" : "some comment" },
                { "name" : "auto_exposure_range", "size" : 1, "comment" : "some comment" },
                { "name" : "led_on_spectrum", "size" : 1, "comment" : "some comment" },
                { "name" : "search_sound", "size" : 1, "comment" : "some comment" },
                { "name" : "measurment_stoped", "size" : 1, "comment" : "some comment" },
                { "name" : "spectrum_accum", "size" : 1, "comment" : "some comment" } ]
        }
    },
    { "type_declaration" : {
            "name" : "radiation_detector_action_t",
            "size" : 4,
            "bitfield" : [
                { "name" : "restart_measurment", "size" : 1, "comment" : "some comment" },
                { "name" : "set_average_as_background", "size" : 1, "comment" : "some comment" },
                { "name" : "perform_stabization", "size" : 1, "comment" : "some comment" },
                { "name" : "clear_spectrum", "size" : 1, "comment" : "some comment" },
                { "name" : "store_spectrum", "size" : 1, "comment" : "some comment" },
                { "name" : "load_spectrum", "size" : 1, "comment" : "some comment" },
                { "name" : "clear_dose", "size" : 1, "comment" : "some comment" },
                { "name" : "set_average_as_base", "size" : 1, "comment" : "some comment" }
            ]
        }
    },
    { "type_declaration" : {
            "name" : "radiation_detector_configuration_t",
            "size" : 4,
            "bitfield" : [
                { "name" : "exposure_range", "size" : 3, "comment" : "some comment" },
                { "name" : "energy_range", "size" : 3, "comment" : "some comment" },
                { "name" : "measuring_circuit", "size" : 3, "comment" : "some comment" },
                { "name" : "measuring_mode", "size" : 3, "comment" : "some comment" },
                { "name" : "counter", "size" : 1, "comment" : "some comment" },
                { "name" : "dosimeter", "size" : 1, "comment" : "some comment" },
                { "name" : "radiometer", "size" : 1, "comment" : "some comment" },
                { "name" : "spectrometer", "size" : 1, "comment" : "some comment" }
            ]
        }
    },
    { "type_declaration" : {
            "name" : "radiation_detector_flags_t",
            "size" : 2,
            "bitfield" : [
                { "name" : "initializing", "size" : 1, "comment" : "some comment" },
                { "name" : "error", "size" : 1, "comment" : "some comment" },
                { "name" : "overload", "size" : 1, "comment" : "some comment" },
                { "name" : "thrsh_exceded", "size" : 1, "comment" : "some comment" },
                { "name" : "hv_error", "size" : 1, "comment" : "some comment" },
                { "name" : "hvreg_error", "size" : 1, "comment" : "some comment" },
                { "name" : "led_error", "size" : 1, "comment" : "some comment" }
            ]
        }
    },
    { "type_declaration" : {
            "name" : "interpretation_t",
            "size" : 2,
            "bitfield" : [
                { "name" : "mode", "size" : 3, "comment" : "some comment" },
                { "name" : "unit", "size" : 4, "comment" : "some comment" },
                { "name" : "radiation_type", "size" : 3, "comment" : "some comment" },
                { "name" : "average_mode", "size" : 3, "comment" : "some comment" }
            ]
        }
    },
    { "type_declaration" : {
            "name" : "counter_flags_t",
            "size" : 2,
            "bitfield" : [
                { "name" : "error", "size" : 1, "comment" : "some comment" },
                { "name" : "overload", "size" : 1, "comment" : "some comment" },
                { "name" : "exceeded_threshold", "size" : 10, "comment" : "some comment" }
            ]
        }
    },
    { "type_declaration" : {
            "name" : "dosimeter_flags_t",
            "size" : 2,
            "bitfield" : [
                { "name" : "error", "size" : 1, "comment" : "some comment" },
                { "name" : "overload", "size" : 1, "comment" : "some comment" },
                { "name" : "exceeded_threshold", "size" : 10, "comment" : "some comment" }
            ]
        }
    },
    { "type_declaration" : {
            "name" : "radiometer_flags_t",
            "size" : 2,
            "bitfield" : [
                { "name" : "error", "size" : 1, "comment" : "some comment" },
                { "name" : "overload", "size" : 1, "comment" : "some comment" }
            ]
        }
    }
]

