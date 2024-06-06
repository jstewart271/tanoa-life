/*
	File: fn_createLoadoutCharacter.sqf
	Function: Martinez_fnc_createLoadoutCharacter
	Author: Martinezzz

	Copyright (c) 2022 Martinezzz, Martinezzz Development
	All Rights Reserved

	Params:
		0: STRING
			- Type of the script

		1: DISPLAY
			- Display of the active dialog
*/

params [
	["_type", "", [""]],
	["_display", displayNull, [displayNull]]
];

switch (_type) do {
	case "Create": {
		private _pos = getPosATL Martinez_Point;
		private _tempObj = (typeOf player) createVehicleLocal _pos;
		if (primaryWeapon player isNotEqualTo "") then {_tempObj switchMove (selectRandom ["AidlPercMstpSrasWrflDnon_G01", "InBaseMoves_patrolling1"])};
		_tempObj setDir 225.975;
		_tempObj setPosATL _pos;
		_tempObj setUnitLoadout (getUnitLoadout [player, true]);

		_display setVariable ["Martinez_LoadoutCharacter", _tempObj];
	};

	case "Delete": {
		private _obj = _display getVariable ["Martinez_LoadoutCharacter", objNull];
		deleteVehicle _obj;

		_display setVariable ["Martinez_LoadoutCharacter", nil];
	};
};
