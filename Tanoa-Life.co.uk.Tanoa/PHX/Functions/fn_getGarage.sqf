/*
	@File: fn_getGarage.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Actually does the garage setup...
*/
#include "..\..\script_macros.hpp"
private _params = _this # 3;
_params params [
	["_spawmpoint", "", ["",[]]],
	["_type", "", [""]]
];

if (_type isEqualTo "" || {_spawmpoint isEqualTo ""}) exitWith { systemChat "Garage Failuire" };

life_garage_sp = _spawmpoint;
life_garage_type = _type;
life_garage_spawn = false;

private _playerSide = call {
    if (playerSide isEqualTo west) exitWith {"cop"};
    if (playerSide isEqualTo east) exitWith {"hav"};
    if (playerSide isEqualTo civilian && {player getVariable ['Faction_Medic', false]}) exitWith {"med"};
    "civ";
};

[getPlayerUID player,_playerSide,_type] remoteExecCall (["fnc_getVehicles","TON"] call SOCK_fnc_getRemoteDestination);

createDialog "RscDisplayGarage";

disableSerialization;
ctrlSetText[2802,"Fetching Vehicles...."];