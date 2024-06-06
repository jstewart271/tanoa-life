/*
	@File: fn_openLicenses.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Opens the "Buy License" Menu...
*/
#include "..\..\..\..\script_macros.hpp"
disableSerialization;
private _licenses = _this select 3;

private _side = switch (true) do {
	case (playerSide isEqualTo west): {"cop"}; 
	case (player getVariable ["Faction_Medic", false]):{"med"}; 
	case (playerSide isEqualTo civilian): {"civ"}; 
	case (playerSide isEqualTo east): {"hav"};
};

if (life_is_processing || life_action_inUse) exitWith {}; // Already Processing or doing something...
if !(createDialog "RscLicensesShop") exitWith {};

private _list = CONTROL(4000, 4001);
lbClear _list;

{
	if !(LICENSE_VALUE(_x, _side)) then { 
		_list lbAdd M_CONFIG(getText, "CfgLicenses", _x, "displayName");
		_list lbSetData [(lbSize _list)-1, _x];
		_list lbSetValue [(lbSize _list)-1, M_CONFIG(getNumber, "CfgLicenses", _x, "price")];
	};
} forEach _licenses;

[4000, 4001, 4004, "setup"] call PHX(searchList);