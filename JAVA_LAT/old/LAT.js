{
	"hashsum" : {
		"reference_val" :  { "attr" : "r_only", "type" : "uint8_t", "arraysize" : 512, "cnt" : 1 },
		"calulated_val" :  { "attr" : "r_only", "type" : "uint8_t", "arraysize" : 512, "cnt" : 1 },
		"hash_length" :    { "attr" : "r_only", "type" : "uint16_t", "arraysize" : 1, "cnt" : 1 },
		"hash_algorithm" : { "attr" : "r_only", "type" : "uint32_t", "arraysize" : 1, "cnt" : 1 }
	},
	"status" : {
		"mode" :    { "attr" : "r_only", "type" : "device_mode_t", "arraysize" : 1, "cnt" : 1 },
		"flags" :   { "attr" : "r_only", "type" : "device_flags_t", "cnt" : 1 },
		"signals" : { "attr" : "r_only", "type" : "device_signals_t", "cnt" : 1 },
		"access" :  { "attr" : "r_only", "type" : "device_access_t", "cnt" : 1 }
	},
	"control" : {
		"action" : 	   { "attr" : "r0w", "type" : "device_actions_t", "cnt" : 1 },
		"mode_on" :	   { "attr" : "r0w", "type" : "device_mode_t", "cnt" : 1 },
		"mode_off" :   { "attr" : "r0w", "type" : "device_mode_t", "cnt" : 1 },
		"signal_on" :  { "attr" : "r0w", "type" : "device_signals_t", "cnt" : 1 },
		"signal_off" : { "attr" : "r0w", "type" : "device_signals_t", "cnt" : 1 },
        "password" :   { "attr" : "r0w", "type" : "uint8_t", "cnt" : 32 }
	},
	"identification" : {
		"device_code"  : { "attr" : "r_only", "type" : "uint32_t", "cnt" :	1 },
		"firmware_ver" : { "attr" : "r_only", "type" : "uint32_t", "cnt" :	1 },
		"hardware_ver" : { "attr" : "r_only", "type" : "uint32_t", "cnt" :	1 },
		"rom_ver"	   : { "attr" : "r_only", "type" : "uint32_t", "cnt" :	1 },
		"lat_ver"      : { "attr" : "r_only", "type" : "uint32_t", "cnt" :	1 },
		"serial_num"   : { "attr" : "rw_root", "type" : "uint32_t", "cnt" :	1 },
        "manufacture_num" : { "attr" : "rw_root", "type" : "uint32_t", "cnt" : 1 }
  	},
	"modbus" : {
		"config" : {
			"phy_layer" : {
				"baudrate" : { "attr" : "rw", "type" : "uint32_t", "cnt" : 1 },
				"options" :  { "attr" : "rw", "type" : "modbus_phy_layer_options_t", "cnt" : 1 }
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
	},
	"radiation_detector" : {
		"counter" : {
			"results" : {
				"instant_count_rate" :    { "attr" : "r_only", "type" : "float", "cnt" : 1 },
				"average_count_rate" :    { "attr" : "r_only", "type" : "float", "cnt" : 1 },
				"average_sko" : 		  { "attr" : "r_only", "type" : "float", "cnt" : 1 },
				"background_count_rate" : { "attr" : "r_only", "type" : "float", "cnt" : 1 },
				"background_sko" : 		  { "attr" : "r_only", "type" : "float", "cnt" : 1 },
				"count_rate" :  		  { "attr" : "r_only", "type" : "float", "cnt" : 9 }
			},
			"flags" : {
				"attr" : "r_only",
				"type" : "uint16_t",
				"cnt"  : 1
			},
			"threshold" : {
				"0" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
				"1" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
				"2" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
				"3" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
				"4" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
				"5" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
				"6" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
				"7" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
				"8" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
				"9" : { "attr" : "rw", "type" : "float", "cnt" : 10 }
			}
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
				"drate" : 			{ "attr" :	"r_only", "type" : "float", "cnt" : 4 },
				"dose" : 			{ "attr" :	"r_only", "type" : "float", "cnt" : 4 }
			},
			"flags" : { "attr" : "r_only", "type" :	"uint16_t", "cnt" : 1 },
			"threshold" : {
				"0" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
			    "1" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
				"2" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
				"3" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
				"4" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
				"5" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
				"6" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
				"7" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
				"8" : { "attr" : "rw", "type" : "float", "cnt" : 10 },
				"9" : { "attr" : "rw", "type" : "float", "cnt" : 10 }
			},
			"interpretation" : { "attr" : "rw_root", "type" : "uint16_t", "cnt" : 1 }
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
				"reserved" : {"attr": "r_only", "type": "float", "cnt": 11 }
			},
			"threshold": {
				"instant_activity" : {"attr": "rw", "type": "float", "cnt": 1 },
				"average_activity" : {"attr": "rw", "type": "float", "cnt": 1 },
				"instant_fluence" : {"attr": "rw", "type": "float", "cnt": 1 },
				"average_fluence" : {"attr": "rw", "type": "float", "cnt": 1 },
				"instant_flux_density" : {"attr": "rw", "type": "float", "cnt": 1 },
				"average_flux_density" : {"attr": "rw", "type": "float", "cnt": 1 },
				"reserverd" : {"attr": "rw", "type": "float", "cnt": 14 }
			},
			"flags": {"attr" : "r_only", "type" : "radiometer_flags_t", "cnt" : 1},
			"interpretation" : {"attr" : "rw_root", "type" : "uint16_t", "cnt" : 1}
		},
		"spectrometer" : { "attr" : "r_only", "type" : "uint8_t", "cnt" : 4150 },
		"coefficients" : { "attr" : "rw_root", "type" : "float", "cnt" : 30 },
		"capabilities" : {
			"configuration" : { "attr" : "r_only", "type" : "radiation_detector_configuration_t", "cnt"  : 1 },
		  	"energy_range" : { "attr" : "r_only", "type" : "radiation_detector_configuration_t", "cnt"  : 1 },
		  	"exposure_range" : { "attr" : "r_only", "type" : "radiation_detector_configuration_t", "cnt"  : 1 },
		  	"measuring_circuit" : { "attr" : "r_only", "type" : "radiation_detector_configuration_t", "cnt"  : 1 }
		},
		"control" : {
		  	"mode_on" :  { "attr" : "r0w", "type" : "radiation_detector_mode_t", "cnt" : 1 },
		  	"mode_off" : { "attr" : "r0w", "type" : "radiation_detector_mode_t", "cnt" : 1 },
		  	"action" :   { "attr" : "r0w", "type" : "radiation_detector_action_t", "cnt" : 1 },
            "configuration" :   { "attr" : "r0w", "type" : "radiation_detector_configuration_t", "cnt" : 1 },
            "average_win" :     { "attr" : "rw", "type" : "uint32_t", "cnt" : 1, "units" : "sec" },
			"measurment_freq" : { "attr" : "rw", "type" : "uint32_t", "cnt" : 1, "units" : "sec" }
		},
		"status" : {
		  	"flags" :         { "attr" : "r_only", "type" : "radiation_detector_flags_t", "cnt" : 1 },
		  	"mode" :          { "attr" : "r_only", "type" : "radiation_detector_mode_t", "cnt" : 1 },
		  	"configuration" : { "attr" : "r_only", "type" : "radiation_detector_configuration_t", "cnt" : 1 }
		},
		"log" : { "attr" : "rw", "type" : "uint32_t", "cnt" : 1, "units" : "sec" }
  	},
  	"clocks" : {
		"time" :             { "attr" : "rw",      "type" : "time_t", "cnt" : 1 },
		"calibration_time" : { "attr" : "rw_root", "type" : "time_t", "cnt" : 1 },
		"manufacture_time" : { "attr" : "rw_root", "type" : "time_t", "cnt" : 1 },
		"pwron_time" :       { "attr" : "r_only",  "type" : "time_t", "cnt" : 1 },
		"life_time" :        { "attr" : "r_only",  "type" : "time_t", "cnt" : 1 },
		"meas_duration" :    { "attr" : "r_only",  "type" : "time_t", "cnt" : 1 },
		"flags" :            { "attr" : "r_only",  "type" : "alarm_flags_t", "cnt" : 1 }
  	},
  	"temperature_sensor" : { "attr" : "r_only", "type" : "temperature_sensor_t", "cnt" : 1 },
  	"alarm" : { "attr" : "r_only", "type" : "alarm_t", "cnt" : 2 }
};
