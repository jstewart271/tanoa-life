#include "..\..\script_macros.hpp"

/*
	File: fn_signOn.sqf
	Function: Martinez_fnc_signOn
	Author: Demolition

	Copyright (c) 2023 Demolition, Demolition Development Services
	All Rights Reserved
*/

_this select 3 params [ "_faction" ];

private _cfgFactionWhitelist = getText(missionConfigFile >> "CfgFactions" >> _faction >> "factionWhitelist");
_cfgFactionWhitelist = call compile format ["%1", _cfgFactionWhitelist];
if (call _cfgFactionWhitelist < 1) exitWith {["You do not have the correct whitelist level!","red"] call PHX_fnc_notify;};
if (player getVariable [format ["Faction_%1", _faction], false]) exitWith {["You are already signed on!","red"] call PHX_fnc_notify;};

private _action = [
    format ["Would you like to sign on as %1!", _faction],
    "Faction Sign-On",
    "Sign On",
    "Cancel"
] call PHX_fnc_confirmBox;

if (_action) then {
    player setVariable [format ["Faction_%1", _faction], true, true];
    player setVariable ["rank", (call _cfgFactionWhitelist), true];
    player setVariable ["realname", (format["%1%2", ([] call PHX(getPrefix)), profileName]),true];
    [format ["You have signed on as %1!", _faction],"green"] call PHX_fnc_notify;
};