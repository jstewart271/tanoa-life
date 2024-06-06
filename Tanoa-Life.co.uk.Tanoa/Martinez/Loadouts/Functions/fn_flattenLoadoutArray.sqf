/*
	File: fn_flattenLoadoutArray.sqf
	Function: Martinez_fnc_flattenLoadoutArray
	Author: Martinezzz

	Copyright (c) 2022 Martinezzz, Martinezzz Development
	All Rights Reserved

	Params:
		0: ARRAY
			- Physical Loadout
*/

params ["_physical"];

private _flatArray = [];
{
	if (_x isEqualType []) then {
		{
			if (_x isEqualType []) then {
				{
					if (_x isEqualType []) then {
						if ((_x isEqualTo [["Binocular","","","",[],[],""],1]) || (_x isEqualTo [["Rangefinder","","","",[],[],""],1])) then {
							_flatArray pushBack [((_x select 0) select 0), _x select 1];
						} else {
							if (_x isEqualType []) then {
								_flatArray pushBack [_x select 0, _x select 1];
							} else {
								_flatArray pushBack [_x, 1];
							};
						};
					} else {
						if (typeName _x != "SCALAR") then {
							_flatArray pushBack [_x, 1];
						};
					};
				} forEach _x;
			} else {
				if (_x isEqualType []) then {
					_flatArray pushBack [_x select 0, 1];
				} else {
					_flatArray pushBack [_x, 1];
				};
			};
		} forEach _x;
	} else {
		_flatArray pushBack [_x, 1];
	};
} forEach _physical;
_flatArray
