/*
	File: fn_createLoadout.sqf
	Function: Martinez_fnc_createLoadout
	Author: Martinezzz

	Copyright (c) 2022 Martinezzz, Martinezzz Development
	All Rights Reserved
*/

["Recieve", [getPlayerUID player, str(playerSide)]] remoteExec ["MartinezSrv_fnc_loadoutServer", 2];
