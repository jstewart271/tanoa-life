#include "..\..\script_macros.hpp"
/*
    File: fn_seizeMoney.sqf
    Author: Conner Merlin
    Description: Sets players money to £0
*/
params [
    ["_unit",objNull,[objNull]]
];

if (isNull _unit || {isNil "_unit"} || {!isPlayer _unit} || {!(isRestrained(_unit))} || {(_unit getVariable "isAdmin")} || {isNil "_unit"}) exitWith {};

[_unit,player] remoteExecCall ["PHX_fnc_removeMoneyClient",_unit];

[format["You have placed all of %1's cash into evidence!",_unit getVariable ["realname",name _unit]],"cyan"] call PHX_fnc_notify;
[player, format ["%1 (%2) Has seized all of %3 (%4) cash",profileName,(getPlayerUID player),_unit getVariable ["realname",name _unit],(getPlayerUID _unit)], "1190766139408658532/GUQE-h5y5rwNDxYqAtLEktGjyTwxE-AKuSuM81RG9KM3L7coK60JBLfq2yCbZ_W_NeOR"] remoteExecCall (["fnc_sendHook", "PHXSRV"] call SOCK_fnc_getRemoteDestination);
