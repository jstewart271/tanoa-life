#include "..\..\script_macros.hpp"

/*
	File: fn_signOff.sqf
	Function: Martinez_fnc_signOff
	Author: Demolition

	Copyright (c) 2023 Demolition, Demolition Development Services
	All Rights Reserved
*/

_this select 3 params [
    "_faction"
];

if !(player getVariable [format ["Faction_%1", _faction], false]) exitWith {["You are not signed on!","red"] call PHX_fnc_notify;};

private _action = [
    format ["Would you like to sign off as %1!", _faction],
    "Faction Sign-Off",
    "Sign Off",
    "Cancel"
] call PHX_fnc_confirmBox;

if (_action) then {
    player setVariable [format ["Faction_%1", _faction], nil, true];
    player setVariable ["rank", nil, true];
    player setVariable ["realname", (format["%1%2", ([] call PHX(getPrefix)), profileName]),true];
    [format ["You have signed off as %1!", _faction],"green"] call PHX_fnc_notify;
};