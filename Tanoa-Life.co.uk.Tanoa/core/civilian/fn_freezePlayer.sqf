/*
	@File: fn_freezePlayer.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Toggles user input...
*/
#include "..\..\script_macros.hpp"
if !(params [["_admin", objNull, [objNull]], ["_msg", "", [""]]]) exitWith {};

life_frozen = !life_frozen;
disableUserInput life_frozen;
[format["Your input has been %2 by %1", _admin getVariable ["realname", name _admin], (["frozen", "unfrozen"] select (!life_frozen))],"red"] call PHX_fnc_notify;

[player, format ["%1 (%2) %3 %4 (%5).",_admin getVariable ["realname", name _admin], getPlayerUID _admin, (["froze", "unfroze"] select (!life_frozen)), profileName,getPlayerUID player], "1190766136980144168/qsI1qza0r3TUgQLmn9Hb84IQZCXfe2cXJFCEVbTc8cbmKCzjyXfxUtjdshtdK9bHROGU"] remoteExecCall (["fnc_sendHook", "PHXSRV"] call SOCK_fnc_getRemoteDestination);

[true, format[_msg, (_admin getVariable ["realname", name _admin]), (player getVariable ["realname", name player])]] call PHX(logUsage);