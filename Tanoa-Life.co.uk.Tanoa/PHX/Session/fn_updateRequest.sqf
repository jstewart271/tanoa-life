#include "..\..\script_macros.hpp"
/*
    File: fn_updateRequest.sqf
    Author: Tonic

    Description:
    Passes ALL player information to the server to save player data to the database.
*/
if (player getVariable ["isAdmin", false] || { life_firstSpawn }) exitWith {};

private _packet = [getPlayerUID player, (profileName), playerSide, CASH, BANK];

private _array = [];
private _professions = [];
private _alive = alive player;
private _position = getPosATL player;
private _flag = switch (true) do {
	case (playerSide isEqualTo west): {"cop"}; 
	case (player getVariable ["Faction_Medic", false]):{"med"}; 
	case (playerSide isEqualTo civilian): {"civ"}; 
	case (playerSide isEqualTo east): {"hav"};
};

{
    _varName = LICENSE_VARNAME(configName _x,_flag);
    _array pushBack [_varName,LICENSE_VALUE(configName _x,_flag)];
} forEach (format ["getText(_x >> 'side') isEqualTo '%1'",_flag] configClasses (missionConfigFile >> "CfgLicenses"));

private _side = switch (true) do {
    case (playerSide isEqualTo west): {"NATO"}; 
    case (player getVariable ["Faction_Medic", false]):{"Medic"}; 
    case (playerSide isEqualTo civilian): {"Civilian"}; 
    case (playerSide isEqualTo east): {"TPLA"};
};

{
    _professions pushBack [(PROF_VARNAME(configName _x)),PROF_LVL(configName _x)];
} foreach (format ["'%1' in getArray(_x >> 'side')", _side] configClasses (missionConfigFile >> "CfgProfessions"));

_packet pushBack _array;

[] call life_fnc_saveGear;
_packet pushBack [GETGEAR, GEARCOL];

_packet pushBack [
    life_hunger,
    life_thirst,
    (damage player)
];

_packet pushBack _professions;

// Level Stuff...
_packet pushBack [PHX_Level, PHX_XP];

if (playerSide in [east, civilian]) then {
    _packet pushBack life_is_arrested_police;
    _packet pushBack life_is_arrested_havoc;
    _packet pushBack life_jail_time;
};

_packet remoteExecCall (["fnc_updateRequest", "DB"] call SOCK_fnc_getRemoteDestination);

[] call PHX_fnc_hudUpdate;