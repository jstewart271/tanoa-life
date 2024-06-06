/*
	File: fn_flattenLoadoutArray.sqf
	Function: Martinez_fnc_flattenLoadoutArray
	Author: Martinezzz

	Copyright (c) 2022 Martinezzz, Martinezzz Development
	All Rights Reserved

	Params:
		0: ARRAY
			- Physical Loadout

		1: ARRAY
			- Virtual Loadout
*/

params ["_physical", "_virtual"];

private _flatArray = [_physical] call Martinez_fnc_flattenLoadoutArray;
private _totalPrice = 0;
private _match = false;

{
	_x params ["_className", "_qty"];

	if (_className isNotEqualTo "") then {
		_match = false;
		if (Martinez_LoadoutAllowedGearHash getOrDefault [_className, false] isNotEqualTo false) then {
			_totalPrice = _totalPrice + ((Martinez_LoadoutAllowedGearHash get _className) * _qty);
			_match = true;
		};

		if !(_match) then {diag_Log format ["[LOADOUT-ERROR]: classname '%1' is not allowed in your loadouts", _className];};
	};
} forEach _flatArray;

private _virtualPrice = 0;
{
	_x params ["_varName", "_amount"];

	private _cfgPrice = getNumber(missionConfigFIle >> "CfgItems" >> _varName >> "buyPrice");
	_virtualPrice = _virtualPrice + (_cfgPrice * _amount);
} forEach _virtual;

_totalPrice + _virtualPrice
