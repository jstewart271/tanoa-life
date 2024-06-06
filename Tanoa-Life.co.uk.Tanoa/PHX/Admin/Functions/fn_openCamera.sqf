/*
	@File: fn_openCamera.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Opens the BIS Camera...
*/
[] spawn BIS_fnc_Camera;
[player, format ["%1 (%2) Opened Their Camera",profileName,(getPlayerUID player)], "AdminLogs"] remoteExecCall (["fnc_sendHook", "PHXSRV"] call SOCK_fnc_getRemoteDestination);

format[_msg, player getVariable ["realname", name player]]

