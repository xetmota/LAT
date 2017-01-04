
{
    "identification" : {
    "lat_ver"      : { "attr" : "r_only", "type" : "uint32_t", "cnt" :	1 },
    "device_code"  : { "attr" : "r_only", "type" : "uint32_t", "cnt" :	1 },
    "firmware_ver" : { "attr" : "r_only", "type" : "uint32_t", "cnt" :	1 },
    "hardware_ver" : { "attr" : "r_only", "type" : "uint32_t", "cnt" :	1 },
    "rom_ver"	   : { "attr" : "r_only", "type" : "uint32_t", "cnt" :	1 },
    "serial_num"   : { "attr" : "rw_root", "type" : "uint32_t", "cnt" :	1 },
    "manufacture_num" : { "attr" : "rw_root", "type" : "uint32_t", "cnt" : 1 },
    "RESERVED_R_ONLY" : { "attr" : "r_only", "type" : "uint16_t", "arraysize" : 5, "cnt" : 1 },
    "RESERVED_RW_ROOT" : { "attr" : "rw_root", "type" : "uint16_t", "arraysize" : 5, "cnt" : 1 }
    },
	"hashsum" : {
		"reference_val" :  { "attr" : "r_only", "type" : "uint8_t", "arraysize" : 512, "cnt" : 1 },
		"calulated_val" :  { "attr" : "r_only", "type" : "uint8_t", "arraysize" : 512, "cnt" : 1 },
		"length" :    { "attr" : "r_only", "type" : "uint16_t", "arraysize" : 1, "cnt" : 1 },
		"algorithm" : { "attr" : "r_only", "type" : "uint32_t", "arraysize" : 1, "cnt" : 1 },
        "RESERVED_R_ONLY" : { "attr" : "r_only", "type" : "uint16_t", "arraysize" : 5, "cnt" : 1 }
	},
	"status" : {
		"mode" :    { "attr" : "r_only", "type" : "device_mode_t", "arraysize" : 1, "cnt" : 1 },
		"flags" :   { "attr" : "r_only", "type" : "device_flags_t", "cnt" : 1 },
		"signals" : { "attr" : "r_only", "type" : "device_signals_t", "cnt" : 1 },
		"access" :  { "attr" : "r_only", "type" : "device_access_t", "cnt" : 1 },
		"battery_charge" : { "attr" : "r_only", "type" : "uint16_t", "cnt" : 1 },
        "RESERVED_R_ONLY" : { "attr" : "r_only", "type" : "uint16_t", "arraysize" : 5, "cnt" : 1 }
	},
	"control" : {
		"action" : 	   { "attr" : "r0w", "type" : "device_actions_t", "cnt" : 1 },
		"mode_on" :	   { "attr" : "r0w", "type" : "device_mode_t", "cnt" : 1 },
		"mode_off" :   { "attr" : "r0w", "type" : "device_mode_t", "cnt" : 1 },
		"signal_on" :  { "attr" : "r0w", "type" : "device_signals_t", "cnt" : 1 },
		"signal_off" : { "attr" : "r0w", "type" : "device_signals_t", "cnt" : 1 },
        "password" :   { "attr" : "r0w", "type" : "uint8_t", "cnt" : 1, "arraysize" : 32 },
        "RESERVED_R0W" :   { "attr" : "r0w", "type" : "uint16_t", "arraysize" : 5, "cnt" : 1 }
	},
  	"radiation_detector" : {
		"counter" : {
			"results" : {
				"instant_count_rate" :    { "attr" : "r_only", "type" : "float", "cnt" : 1 },
				"average_count_rate" :    { "attr" : "r_only", "type" : "float", "cnt" : 1 },
				"average_sko" : 		  { "attr" : "r_only", "type" : "float", "cnt" : 1 },
				"background_count_rate" : { "attr" : "r_only", "type" : "float", "cnt" : 1 },
				"background_sko" : 		  { "attr" : "r_only", "type" : "float", "cnt" : 1 },
				"RESERVED_R_ONLY" :   	  { "attr" : "r_only", "type" : "float", "cnt" : 1, "arraysize" : 10 }
			},
			"flags" : {
				"attr" : "r_only",
				"type" : "uint16_t",
				"cnt"  : 1
			},
			"threshold" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
            "interpretation" : { "type" : "interpretation_t", "cnt" : 1 }
		},
		"dosimeter" : {
			"results" : {
				"instant_drate" : 	{ "attr" :	"r_only", "type" : "float", "cnt" : 1 },
				"average_drate" : 	{ "attr" :	"r_only", "type" : "float", "cnt" : 1 },
				"average_sko" : 	{ "attr" :	"r_only", "type" : "float", "cnt" : 1 },
				"backgnd_drate" : 	{ "attr" :	"r_only", "type" : "float", "cnt" : 1 },
				"backgnd_sko" : 	{ "attr" :	"r_only", "type" : "float", "cnt" : 1 },
				"measurment_dose" : { "attr" :	"r_only", "type" : "float", "cnt" : 1 },
				"pwron_dose" : 		{ "attr" :	"r_only", "type" : "float", "cnt" : 1 },
				"lifetime_dose" : 	{ "attr" :	"r_only", "type" : "float", "cnt" : 1 },
                "RESERVED_R_ONLY" :   { "attr" : "r_only", "type" : "float", "cnt" : 1, "arraysize" : 8 }
			},
			"flags" : { "attr" : "r_only", "type" :	"uint16_t", "cnt" : 1 },
			"threshold" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
			"interpretation" : { "type" : "interpretation_t", "cnt" : 1 },
            "calibration" : { "type" : "calibration_t", "cnt" : 1 }
		},
		"radiometer" : {
			"result" : {
				"instant_activity" : {"attr": "r_only", "type": "float", "cnt": 1 },
				"average_activity" : {"attr": "r_only", "type": "float", "cnt": 1 },
				"backgnd_activity" : {"attr": "r_only", "type": "float", "cnt": 1 },
				"instant_fluence"  : {"attr": "r_only", "type": "float", "cnt": 1 },
				"average_fluence"  : {"attr": "r_only", "type": "float", "cnt": 1 },
				"backgnd_fluence"  : {"attr": "r_only", "type": "float", "cnt": 1 },
				"instant_flux_density" : {"attr": "r_only", "type": "float", "cnt": 1 },
				"average_flux_density" : {"attr": "r_only", "type": "float", "cnt": 1 },
				"backgnd_flux_density" : {"attr": "r_only", "type": "float", "cnt": 1 },
                "RESERVED_R_ONLY" :      { "attr" : "r_only", "type" : "float", "cnt" : 1, "arraysize" : 10 }
			},
			"threshold": {
				"instant_activity" : {"attr": "rw", "type": "float", "cnt": 1 },
				"average_activity" : {"attr": "rw", "type": "float", "cnt": 1 },
				"instant_fluence" : {"attr": "rw", "type": "float", "cnt": 1 },
				"average_fluence" : {"attr": "rw", "type": "float", "cnt": 1 },
				"instant_flux_density" : {"attr": "rw", "type": "float", "cnt": 1 },
				"average_flux_density" : {"attr": "rw", "type": "float", "cnt": 1 },
				"RESERVED_RW" : {"attr": "rw", "type": "float", "cnt": 1, "arraysize" : 10 }
			},
			"flags": { "attr" : "r_only", "type" : "radiometer_flags_t", "cnt" : 1},
			"interpretation" : { "type" : "interpretation_t", "cnt" : 1},
            "calibration" : { "type" : "calibration_t", "cnt" : 1 }
		},
		"spectrometer" : {
		    "results" : { "attr" : "r_only", "type" : "uint8_t", "cnt" : 1, "arraysize" : 4200 },
            "options" : { "attr" : "rw", "type" : "uint8_t", "cnt" : 1, "arraysize" : 120 },
            "interpretation" : { "type" : "interpretation_t", "cnt" : 1}
        },
		"coefficients" : { "attr" : "rw_root", "type" : "float", "cnt" : 30 },
		"capabilities" : {
            "configuration" :  { "attr" : "r_only", "type" : "radiation_detector_configuration_t", "cnt" : 1 },
		  	"rd_sub_devices" : { "attr" : "r_only", "type" : "radiation_detector_configuration2_t", "cnt" : 1 },
            "RESERVED_R_ONLY" : { "attr" : "r_only", "type" : "uint8_t", "cnt" : 1, "arraysize" : 160 }
		},
		"control" : {
		  	"mode_on" :  { "attr" : "r0w", "type" : "radiation_detector_mode_t", "cnt" : 1 },
		  	"mode_off" : { "attr" : "r0w", "type" : "radiation_detector_mode_t", "cnt" : 1 },
		  	"action" :   { "attr" : "r0w", "type" : "radiation_detector_action_t", "cnt" : 1 }
		},
        "options" : {
            "configuration" :   { "attr" : "rw", "type" : "radiation_detector_configuration_t", "cnt" : 1 },
            "average_win" :     { "attr" : "rw", "type" : "uint32_t", "cnt" : 1, "units" : "sec" },
            "measurment_freq" : { "attr" : "rw", "type" : "uint32_t", "cnt" : 1, "units" : "sec" }
        },
		"status" : {
		  	"flags" : { "attr" : "r_only", "type" : "radiation_detector_flags_t", "cnt" : 1 },
		  	"mode" :  { "attr" : "r_only", "type" : "radiation_detector_mode_t", "cnt" : 1 }
		},
		"log" : {
            "RESERVED_R_ONLY" : { "attr" : "r_only", "type" : "uint8_t", "cnt" : 1, "arraysize" : 10 },
            "RESERVED_RW" :     { "attr" : "rw", "type" : "uint8_t", "cnt" : 1, "arraysize" : 20 }
        }
  	},
  	"clocks" : {
		"time" :             { "attr" : "rw",      "type" : "time_t", "cnt" : 1 },
		"calibration_time" : { "attr" : "rw_root", "type" : "time_t", "cnt" : 1 },
		"manufacture_time" : { "attr" : "rw_root", "type" : "time_t", "cnt" : 1 },
		"pwron_time" :       { "attr" : "r_only",  "type" : "time_t", "cnt" : 1 },
		"life_time" :        { "attr" : "r_only",  "type" : "time_t", "cnt" : 1 },
		"meas_duration" :    { "attr" : "r_only",  "type" : "time_t", "cnt" : 1 },
		"flags" :            { "attr" : "r_only",  "type" : "alarm_flags_t", "cnt" : 1 },
        "RESERVED_R_ONLY" :  { "attr" : "r_only",  "type" : "time_t", "cnt" : 1, "arraysize" : 3 },
        "RESERVED_RW" :      { "attr" : "rw",      "type" : "time_t", "cnt" : 1, "arraysize" : 3 },
        "RESERVED_RW_ROOT" : { "attr" : "rw_root", "type" : "time_t", "cnt" : 1, "arraysize" : 3 }
  	},
  	"temperature_sensor" : { "type" : "temperature_sensor_t", "cnt" : 1 },
  	"alarm" : { "type" : "alarm_t", "cnt" : 2 },
    "modbus" : {
        "config" : {
            "phy_layer" : {
                "baudrate" : { "attr" : "rw", "type" : "uint32_t", "cnt" : 1 },
                "parity" : { "attr" : "rw", "type" : "uint16_t", "cnt" : 1 },
                "frame_size" : { "attr" : "rw", "type" : "uint16_t", "cnt" : 1 },
                "stop_bits" : { "attr" : "rw", "type" : "uint16_t", "cnt" : 1 }
            },
            "channel_layer" : {
                "tmode" :   { "attr" : "rw", "type" : "uint16_t", "cnt" : 1 },
                "address" : { "attr" : "rw", "type" :	"uint16_t", "cnt" :	1 }
            }
        },
        "statistics" : {
            "cnt_message_all" : 	 { "attr" : "r_only", "type" : "uint32_t", "cnt" : 1 },
            "cnt_message_addressed" :{ "attr" : "r_only", "type" : "uint32_t", "cnt" : 1 },
            "cnt_answer_timeout" : 	 { "attr" : "r_only", "type" : "uint32_t", "cnt" : 1 },
            "cnt_message_badcrc" :   { "attr" : "r_only", "type" : "uint32_t", "cnt" : 1 },
            "cnt_message_nak" :      { "attr" : "r_only", "type" : "uint32_t", "cnt" : 1 },
            "cnt_message_overrun" :  { "attr" : "r_only", "type" : "uint32_t", "cnt" : 1 },
            "cnt_message_othererr" : { "attr" : "r_only", "type" : "uint32_t", "cnt" : 1 }
        }
    }
};


