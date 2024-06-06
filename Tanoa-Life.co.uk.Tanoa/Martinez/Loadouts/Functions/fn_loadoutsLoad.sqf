/*
	File: fn_loadoutsLoad.sqf
	Function: Martinez_fnc_loadoutsLoad
	Author: Martinezzz

	Copyright (c) 2022 Martinezzz, Martinezzz Development
	All Rights Reserved

	Params:
		0: ARRAY
			- Data from the remote Execute
*/

params [
	["_data", [], [[]]]
];

Martinez_LoadoutsArray = [];
if (_data isEqualTo []) exitWith {};

private _mockArray = [];
{
	_x params ["_loadoutID", "_loadoutName", "_loadoutPhysical", "_loadoutVirutal"];
	_mockArray pushBack [
		_loadoutName,
		_loadoutID,
		_loadoutPhysical,
		_loadoutVirutal
	];
} forEach _data;
Martinez_LoadoutsArray = _mockArray;

Martinez_LoadoutAllowedGearHash = call Martinez_fnc_getAllowedLoadoutGear;
Martinez_LoadoutAllowedGearHash set ["ItemRadio", 0];