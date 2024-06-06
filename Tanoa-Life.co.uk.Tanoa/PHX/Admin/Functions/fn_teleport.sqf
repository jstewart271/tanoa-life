/*
	@File: fn_teleport.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Does what it says on the tin...
*/
#include "..\..\..\script_macros.hpp"
params [["_msg", "", [""]]];

fnc_teleport = {
	params [["_pos", [], [[]]]];

	if (FETCH_CONST(life_adminlevel) < 0) exitWith { [format["Report this message to the dev team..."],"red"] call PHX_fnc_notify };

	(vehicle player) setPos _pos;

	onMapSingleClick "";
	openMap [false, false];

	[player, format ["%1 (%2) used teleport to gridref %3 ",profileName,getPlayerUID player,_this], "AdminLogs"] remoteExecCall (["fnc_sendHook", "PHXSRV"] call SOCK_fnc_getRemoteDestination);

	true
};

openMap [true, false]; 
onMapSingleClick "[_pos] call fnc_teleport";

[] spawn { waitUntil { !visibleMap }; onMapSingleClick ""; };

false