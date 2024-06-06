/*
	@File: fn_vehicleEject.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Ejects the target out of their vehicle...
*/
#include "..\..\..\script_macros.hpp"
#include "..\..\GUI\Tablet\macros.hpp"
params [["_msg", "", [""]], ["_refuel", false, [true]]];

private _target = ((CONTROL_DATA(IDC_ADMIN_LIST)) call PHX(unitByUID));

if (isNil "_target" || { isNull _target }) exitWith { NOTIFY("This target is invalid","red"); false};
if (isNull objectParent _target) exitWith { NOTIFY("This player is not currently within a vehicle","red"); false};

moveOut _target;
[player, format ["%1 (%2) used Vehicle Eject on %3",profileName,getPlayerUID player,name _target], "AdminLogs"] remoteExecCall (["fnc_sendHook", "PHXSRV"] call SOCK_fnc_getRemoteDestination);
format[_msg, player getVariable ["realname", name player], _target getVariable ["realname", name _target]]
