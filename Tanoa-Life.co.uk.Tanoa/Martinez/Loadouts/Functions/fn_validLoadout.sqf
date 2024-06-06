/*
	File: fn_validLoadout.sqf
	Function: Martinez_fnc_validLoadout
	Author: Martinezzz

	Copyright (c) 2022 Martinezzz, Martinezzz Development
	All Rights Reserved

	Params:
		0: ARRAY
			- Physical Loadout
*/

params ["_loadout"];
private _flatArray = [_loadout] call Martinez_fnc_flattenLoadoutArray;
private _match = false;
private _notValidEquipment = [];

{
	_x params ["_className", "_qty"];

	if (_className isNotEqualTo "") then {
		_match = false;

		if (Martinez_LoadoutAllowedGearHash getOrDefault [_className, false] isNotEqualTo false) then {
			_match = true;
		};

		if !(_match) exitWith {_notValidEquipment pushBackUnique _className};
	};
} forEach _flatArray;

_notValidEquipment;
