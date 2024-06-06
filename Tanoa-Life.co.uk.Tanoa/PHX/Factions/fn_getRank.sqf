/*
	    @File: fn_getRank.sqf
	    @Author: Jack "Scarso" Farhall
	    @Description: Returns an array with the rank title and icon...
*/
#include "..\..\script_macros.hpp"

private _return = ["", ""];

if (!params [["_player", objNull, [objNull]]] || isNull _player) exitWith {
	_return;
};

_return = call {
	if (isFactionOnDuty(_player, "Medic")) exitWith {
		switch (_player getVariable ["rank", 0]) do {
			case 2: { ["First Aider", INSIGNIA("nhs\fa.paa")] };
			case 3: { ["Paramedic", INSIGNIA("nhs\nurse.paa")] };
			case 4: { ["Doctor", INSIGNIA("nhs\seniornurse.paa")] };
			case 5: { ["General Practitioner", INSIGNIA("nhs\consultant.paa")] };
			case 6: { ["Surgeon", INSIGNIA("nhs\gp.paa")] };
			case 7: { ["Consultant", INSIGNIA("nhs\cm.paa")] };
			case 8: { ["Chief Medical Officer", INSIGNIA("nhs\md.paa")] };
			default { ["Student", INSIGNIA("nhs\paramedic.paa")] };
		};
	};

	if ((side _player) isEqualTo east) exitWith {
		switch (_player getVariable ["rank", 0]) do {
			case 2: {
				["Private First Class", INSIGNIA("tpla\Private_First_Class.paa"), "PFC"]
			};
			case 3: {
				["Grenadier", INSIGNIA("tpla\Gren.paa"), "GRD"]
			};
			case 4: {
				["Sergeant", INSIGNIA("tpla\Sergeant.paa"), "SGT"]
			};
			case 5: {
				["Master Sergeant", INSIGNIA("tpla\Master_Sergeant.paa"), "MSGT"]
			};
			case 6: {
				["Warrant Officer", INSIGNIA("tpla\Private.paa"), "WO"]
			};
			case 7: {
				["Lieutenant", INSIGNIA("tpla\Lieutenant.paa"), "LT"]
			};
			case 8: {
				["Commodore", INSIGNIA("tpla\Commodore.paa"), "COM"]
			};
			case 9: {
				["Commander", INSIGNIA("tpla\Commander.paa"), "CMD"]
			};
			case 10: {
				["Brigadier", INSIGNIA("tpla\Brigadier.paa"), "BRG"]
			};
			case 11: {
				["Lieutenant Commissioner", INSIGNIA("tpla\Lieutenant_Commissioner.paa"), "LTC"]
			};
			case 12: {
				["Deputy High Commissioner", INSIGNIA("tpla\Deputy_High_Commissioner.paa"), "DHC"]
			};
			case 13: {
				["High Commissioner", INSIGNIA("tpla\High Commissioner.paa"), "HC"]
			};
			default {
				["Private", INSIGNIA("tpla\Private.paa"), "PVT"]
			};
		};
	};

	if (isCID(_player)) then {
		switch (_player getVariable ["rank", 0]) do {
			case 2: {
				["Lance Corporal", INSIGNIA("havoc\lcpl.paa"), "L/Cpl"]
			};
			case 3: {
				["Corporal", INSIGNIA("havoc\cpl.paa"), "Cpl"]
			};
			case 4: {
				["Sergeant", INSIGNIA("havoc\sgt.paa"), "Sgt"]
			};
			case 5: {
				["Staff Sergeant", INSIGNIA("havoc\ssgt.paa"), "SSgt"]
			};
			case 6: {
				["Warrant Officer Class 2", INSIGNIA("havoc\wo.paa"), "WO2"]
			};
			case 7: {
				["Warrant Officer Class 1", INSIGNIA("havoc\2lt.paa"), "WO1"]
			};
			case 8: {
				["Lieutenant", INSIGNIA("havoc\lt.paa"), "Lt"]
			};
			case 9: {
				["Captain", INSIGNIA("havoc\cap.paa"), "Capt"]
			};
			case 10: {
				["Major", INSIGNIA("havoc\maj.paa"), "Maj"]
			};
			case 11: {
				["Brigadier", INSIGNIA("havoc\brig.paa"), "Brig"]
			};
			case 12: {
				["Colonel", INSIGNIA("havoc\col.paa"), "Col"]
			};
			case 13: {
				["General", INSIGNIA("havoc\gen.paa"), "Gen"]
			};
			default {
				["Private", INSIGNIA("havoc\pvt.paa"), "Pvt"]
			};
		};
	} else {
		switch (_player getVariable ["rank", 0]) do {
			case 2: {
				["Lance Corporal", INSIGNIA("havoc\lcpl.paa"), "L/Cpl"]
			};
			case 3: {
				["Corporal", INSIGNIA("havoc\cpl.paa"), "Cpl"]
			};
			case 4: {
				["Sergeant", INSIGNIA("havoc\sgt.paa"), "Sgt"]
			};
			case 5: {
				["Staff Sergeant", INSIGNIA("havoc\ssgt.paa"), "SSgt"]
			};
			case 6: {
				["Warrant Officer Class 2", INSIGNIA("havoc\wo.paa"), "WO2"]
			};
			case 7: {
				["Warrant Officer Class 1", INSIGNIA("havoc\2lt.paa"), "WO1"]
			};
			case 8: {
				["Lieutenant", INSIGNIA("havoc\lt.paa"), "Lt"]
			};
			case 9: {
				["Captain", INSIGNIA("havoc\cap.paa"), "Capt"]
			};
			case 10: {
				["Major", INSIGNIA("havoc\maj.paa"), "Maj"]
			};
			case 11: {
				["Brigadier", INSIGNIA("havoc\brig.paa"), "Brig"]
			};
			case 12: {
				["Colonel", INSIGNIA("havoc\col.paa"), "Col"]
			};
			case 13: {
				["General", INSIGNIA("havoc\gen.paa"), "Gen"]
			};
			default {
				["Private", INSIGNIA("havoc\pvt.paa"), "Pvt"]
			};
		};
	};
};

_return;