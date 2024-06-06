
/*
	File: fn_loadLocker.sqf
	Function: Martinez_fnc_loadLocker
	Author: Martinezzz

	Copyright (c) 2023 Martinezzz, Martinezzz Development
	All Rights Reserved
*/

params [
	["_type", "", [""]],
	["_data", [], [[]]]
];

switch _type do {
	case "sendQuest": { ["Load", [getPlayerUID player, playerSide]] remoteExec ["MartinezSrv_fnc_lockerServer", 2]; };
	case "recieve": {
		((_data select 0) params ["_tier", "_physical", "_virtual"]);
		Martinez_LockerData = createHashMapFromArray [
			["Tier", _tier],
			["Physical", _physical],
			["Virtual", _virtual]
		];
	};
};