/*
	File: fn_canWhitelist.sqf
	Function: Martinez_fnc_canWhitelist
	Author: Martinezzz

	Copyright (c) 2023 Martinezzz, Martinezzz Development
	All Rights Reserved
*/


private _canWhitelist = false;

{
	private _condition = getText(_x >> "whitelistLvlAccess");
	if (_canWhitelist) exitWith {};
	_canWhitelist = call compile _condition;
} forEach ("true" configClasses (missionConfigFile >> "CfgWhitelist" >> "Whitelists"));
_canWhitelist