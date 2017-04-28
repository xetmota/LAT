
[
    { "type_declaration" : { "name" : "float", "size" : 4 }
    },
    { "type_declaration" : { "name" : "uint8_t", "size" : 1	}},
    { "type_declaration" : { "name" : "uint16_t", "size" : 2 }},
    { "type_declaration" : { "name" : "uint32_t", "size" : 4 }},
    { "type_declaration" : { "name" : "int16_t", "size" : 2 }},
    { "type_declaration" : { "name" : "time_t", "size" : 6  }},
    { "type_declaration" : {
            "name" : "device_flags_t",
            "size" : 4,
            "bit" : "err_software",
            "bit" :	"err_clock",
            "bit" :	"err_calibration",
            "bit" :	"err_other_data",
            "bit" :	"err_congig_data",
            "bit" :	"err_calibration_spectrum",
            "bit" :	"err_general_spectrum",
            "bit" :	"err_rom",
            "bit" :	"err_eeprom",
            "bit" :	"err_fpga",
            "bit" :	"err_flash",
            "bit" :	"err_interrupt",
            "bit" :	"err_supply_voltage",
            "bit" :	"err_external_periph",
            "bit" :	"err_stabilization_sys",
            "bit" :	"err_io",
            "bit" :	"err_addr",
            "bit" :   "battery_discharged"
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
            "bit" : "signal_1",
            "bit" :	"signal_2",
            "bit" :	"signal_3",
            "bit" :	"signal_4",
            "bit" :	"signal_5",
            "bit" :	"signal_6",
            "bit" :	"signal_7",
            "bit" :	"signal_8",
            "bit" :	"signal_9",
            "bit" :	"signal_10",
            "bit" :	"signal_11",
            "bit" :	"signal_12",
            "bit" :	"signal_13",
            "bit" :	"signal_14",
            "bit" :	"signal_15",
            "bit" :	"signal_16",
            "bit" :	"signal_17",
            "bit" :	"signal_18",
            "bit" :	"signal_19",
            "bit" :	"signal_20"
        }
    },
    { "type_declaration" : {
            "name" : "device_mode_t",
            "size" : 4,
            "bit" : "root_permission"
        }
    },
    { "type_declaration" : {
            "name" : "device_actions_t",
            "size" : 4,
            "bit" : "device_pwr_on",
            "bit" : "device_pwr_off"
        }
    },
    { "type_declaration" : {
            "name" : "modbus_phy_layer_options_t",
            "size" : 4,
            "bit" : "parity",
            "bit" : "parity",
            "bit" : "parity",
            "bit" : "frame_size",
            "bit" : "frame_size",
            "bit" : "frame_size",
            "bit" : "stop_bits",
            "bit" : "stop_bits",
            "bit" : "stop_bits"
        }
    },
    { "type_declaration" : {
            "name" : "alarm_flags_t",
            "size" : 2,
            "bit" : "init",
            "bit" : "error"
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
            "bit" : "backgnd_substraction",
            "bit" : "search",
            "bit" : "spectrometer",
            "bit" : "low_power",
            "bit" : "setup",
            "bit" : "strobe",
            "bit" : "self_control",
            "bit" : "temperature_correction",
            "bit" : "auto_exposure_range",
            "bit" : "led_on_spectrum",
            "bit" : "search_sound",
            "bit" : "measurment_stoped",
            "bit" : "spectrum_accum"
        }
    },
    { "type_declaration" : {
            "name" : "radiation_detector_action_t",
            "size" : 4,
            "bit" : "restart_measurment",
            "bit" : "set_average_as_background",
            "bit" : "perform_stabization",
            "bit" : "clear_spectrum",
            "bit" : "store_spectrum",
            "bit" : "load_spectrum",
            "bit" : "clear_dose",
            "bit" : "set_average_as_base"
        }
    },
    { "type_declaration" : {
            "name" : "radiation_detector_configuration_t",
            "size" : 2,
            "bit" : "exposure_range",
            "bit" : "exposure_range",
            "bit" : "exposure_range",
            "bit" : "energy_range",
            "bit" : "energy_range",
            "bit" : "energy_range",
            "bit" : "measuring_circuit",
            "bit" : "measuring_circuit",
            "bit" : "measuring_circuit",
            "bit" : "counter",
            "bit" : "dosimeter",
            "bit" : "radiometer",
            "bit" : "spectrometer"
        }
    },
    { "type_declaration" : {
            "name" : "radiation_detector_flags_t",
            "size" : 2,
            "bit" : "initializing",
            "bit" : "error",
            "bit" : "overload",
            "bit" : "thrsh_exceded",
            "bit" : "hv_error",
            "bit" : "measuring_circuit",
            "bit" : "measuring_circuit",
            "bit" : "measuring_circuit",
            "bit" : "counter",
            "bit" : "dosimeter",
            "bit" : "radiometer",
            "bit" : "spectrometer",
            "bit" : "hvreg_error",
            "bit" : "led_error"
        }
    },
    { "type_declaration" : {
            "name" : "interpretation_t",
            "size" : 2,
            "bit" : "mode",
            "bit" :	"mode",
            "bit" :	"mode",
            "bit" :	"unit",
            "bit" :	"unit",
            "bit" :	"unit",
            "bit" :	"unit",
            "bit" : "type_radiation",
            "bit" :	"type_radiation",
            "bit" :	"type_radiation",
            "bit" :	"average_mode",
            "bit" :	"average_mode",
            "bit" :	"average_mode"
        }
    },
    { "type_declaration" : {
            "name" : "counter_flas_t",
            "size" : 2,
            "bit" : "error",
            "bit" :	"overload",
            "bit" :	"exceeded_threshold_1",
            "bit" :	"exceeded_threshold_2",
            "bit" :	"exceeded_threshold_3",
            "bit" :	"exceeded_threshold_4",
            "bit" :	"exceeded_threshold_5",
            "bit" :	"exceeded_threshold_6",
            "bit" :	"exceeded_threshold_7",
            "bit" :	"exceeded_threshold_8",
            "bit" :	"exceeded_threshold_9",
            "bit" :	"exceeded_threshold_10"
        }
    },
    { "type_declaration" : {
            "name" : "dosimeter_flas_t",
            "size" : 2,
            "bit" : "error",
            "bit" : "overload",
            "bit" : "exceeded_threshold_1",
            "bit" : "exceeded_threshold_2",
            "bit" : "exceeded_threshold_3",
            "bit" : "exceeded_threshold_4",
            "bit" : "exceeded_threshold_5",
            "bit" : "exceeded_threshold_6",
            "bit" : "exceeded_threshold_7",
            "bit" : "exceeded_threshold_8",
            "bit" : "exceeded_threshold_9",
            "bit" : "exceeded_threshold_10"
        }
    },
    { "type_declaration" : {
            "name" : "radiometer_flags_t",
            "size" : 2
        }
    }
]

