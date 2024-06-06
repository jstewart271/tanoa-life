/*
	File: fn_buyLocker.sqf
	Function: Martinez_fnc_buyLocker
	Author: Martinezzz

	Copyright (c) 2023 Martinezzz, Martinezzz Development
	All Rights Reserved
*/

if (life_action_inUse) exitWith {["You are already doing an action!", "red", "Error"] call PHX_fnc_notify};
if !(isNil 'Martinez_LockerData') exitWith {["You already have a locker!", "red", "Error"] call PHX_fnc_notify};

private _cfgBase = missionConfigFile >> "CfgLockers";
private _cfgBasePrice = getNumber(_cfgBase >> "baseCost");

private _action = [format ["Would you like to buy a locker for £%1, this will come out of your bank account!", [_cfgBasePrice] call life_fnc_numberText], "Faction Locker", "Yes", "No"] call PHX_fnc_confirmBox;

if (_action) then {
	if (PHX_ATMCash < _cfgBasePrice) exitWith {["You do not have enough money in your bank account!", "red", "Error"] call PHX_fnc_notify};
	[_cfgBasePrice, 1, 1, "Purchased Tier 1 Locker"] call PHX_fnc_handleMoney;

	["You have purchased a <t font='RobotoCondensedBold'>Tier 1 Locker</t> you can find where access it by looking for the <t font='RobotoCondensedBold'>Locker Map Marker<t/>!", "green"] call PHX_fnc_notify;

	["Create", [getPlayerUID player, playerSide]] remoteExec ["MartinezSrv_fnc_lockerServer", 2];
};
