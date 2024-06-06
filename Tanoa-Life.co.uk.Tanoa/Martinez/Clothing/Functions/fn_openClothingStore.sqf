/*
	File: fn_openClothingStore.sqf
	Function: Martinez_fnc_openClothingStore
	Author: Martinezzz

	Copyright (c) 2022 Martinezzz, Martinezzz Development
	All Rights Reserved

	Params:
		0: OBJECT
			- the object which the action is assigned to

		1: OBJECT
			- the unit that activated the action

		2: NUMBER
			- activated action's ID (same as addAction's return value)

		3: ANYTHING
			- arguments given to the script if you are using the extended syntax
*/

_this params ["_target", "_caller", "_actionId", "_StoreClass"];

Martinez_ClothingStore = "";
Martinez_ClothingStore = _storeClass;

private _exit = false;
private _shopSide = getText(missionConfigFile >> "CfgClothing" >> worldName >> _StoreClass >> "side");

if (_shopSide isNotEqualTo "") then {
	private _flag = call {
		if (playerSide isEqualTo west) exitWith {"cop"};
		if (playerSide isEqualTo east) exitWith {"hav"};
		if (player getVariable ["Faction_Medic", false]) exitWith {"med"};
		"civ";
	};

    if (_flag isNotEqualTo _shopSide) then {_exit = true;};
};

if (_exit) exitWith {};

createDialog "Martinez_ClothingStore";