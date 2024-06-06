#include "..\..\script_macros.hpp"
/*

	Author: ToxicRageTv
	File: fn_busStart.sqf

*/
private ["_busDepotName"];
if ((lbCurSel 1500) isEqualTo -1) exitWith {hint "No destination selected";};

private _error = false;

busTo = lbData [ 1500, ( lbCurSel 1500 ) ]; 
busToMarker = getMarkerPos busTo;

disableSerialization;
closeDialog 0;

private _side = switch (true) do {
    case (playerSide isEqualTo west): {"Cop"};
    case (Player getVariable ['Faction_Medic']): {"Medic"};
    default {"Civilian"};
};

private _dis = round(busToMarker distance (getPos player));
private _multiplyer = getNumber(missionConfigFile >> "Toxic_Bus_Config" >> _side >> "multipler");
private _tripTotal = round(_multiplyer * _dis);

private _busStops = getArray(missionConfigFile >> "Toxic_Bus_Config" >> _side >> "stops");
private _payment = getText(missionConfigFile >> "Toxic_Bus_Config" >> "payment");
private _type = getNumber(missionConfigFile >> "Toxic_Bus_Config" >> "bus_3d");

{
	if (busTo isEqualTo (_x select 1)) then {
		_busDepotName = _x select 0;
	};
} forEach _busStops;

_result = [ format ["Are You Sure You Want To Travel To %1? It Will Cost You $%2", _busDepotName, _tripTotal], "Bus", "Yes", "No"] call BIS_fnc_guiMessage;
if !(_result) exitWith {
	hint "You Chose To Cancel Your Travel Plans";
};

switch (_payment) do {
	case "BANK": {
		if (BANK < _tripTotal) then {
			hint "You Dont Have Enough Money To Ride The Bus";
		} else {
			BANK = BANK - _tripTotal;
		};
	};

	case "CASH": {
		if (CASH < _tripTotal) then {
			hint "You Dont Have Enough Money To Ride The Bus";
		} else {
			CASH = CASH - _tripTotal;
		};
	};

	default {
		_error = true;
	};
};

if (_error) exitWith {hint "ERROR: Payment Config Not Setup!"};

[6] call SOCK_fnc_updatePartial;
hint "Enjoy You're Trip";

if (_type isEqualTo 1) then {
	showCinemaBorder true;
	player allowDamage false;
	_cam = "camera" camCreate (player modelToWorldVisual [-5,0,1.85]);
	_cam cameraEffect ["internal","back"];
	_cam camSetFov 9;
	_cam camSetTarget busToMarker;
	_cam camSetRelPos [(((getPosATL player) select 0) - ((getMarkerPos busTo) select 0)),(((getPosATL player) select 1) - ((getMarkerPos busTo) select 1)),(((getPosATL player) select 2) + 250)];
	_cam camCommit 3;
	waitUntil {camCommitted _cam};

	player setPos busToMarker;

	_cam camSetFov 9;
	_cam camSetTarget vehicle player;
	_cam camCommit 0;
	waitUntil {camCommitted _cam};	
	_cam camSetRelPos [0,0,250];
	_cam camCommit 5;
	waitUntil {camCommitted _cam};

	_cam camSetFOV 9;
	_cam camCommit 0;
	waitUntil {camCommitted _cam};	
	_cam camSetTarget vehicle player;
	_cam camSetRelPos [0,0,2];
	_cam camCommit 3;
	waitUntil {camCommitted _cam};

	_cam cameraEffect ["terminate","back"];
	showCinemaBorder false;
	hint "You Have Arrived At Your Destination";
	camDestroy _cam;
	player allowDamage true;
} else {
	showCinemaBorder true;
	player allowDamage false;
	_cam = "camera" camCreate (player modelToWorldVisual [-5,0,1.85]);
	_cam cameraEffect ["internal","back"];
	_cam camSetFov 9;
	_cam camSetTarget busToMarker;
	_cam camSetRelPos [(((getPosATL player) select 0) - ((getMarkerPos busTo) select 0)),(((getPosATL player) select 1) - ((getMarkerPos busTo) select 1)),(((getPosATL player) select 2) + 250)];
	_cam camCommit 3;
	waitUntil {camCommitted _cam};
	camDestroy _cam;
	_cam cameraEffect ["terminate","back"];

	showCinemaBorder true;

	createDialog "Toxic_Bus_Menu";
	_display = uiNamespace getVariable "Toxic_Bus_Menu";

	ctrlShow [1000,false];
	ctrlShow [1001,false];
	ctrlShow [2200,false];
	ctrlShow [1500,false];
	ctrlShow [2400,false];

	_map = _display displayCtrl 1919;

	sleep 0.5;
	
	player setPos busToMarker;

	_map ctrlMapAnimAdd[5,0.1,player];
	ctrlMapAnimCommit _map;
	sleep 5;

	showCinemaBorder true;
	closeDialog 0;

	_cam = "camera" camCreate (player modelToWorldVisual [0,0,250]);
	_cam cameraEffect ["internal","back"];


	_cam camSetFOV 9;
	_cam camCommit 0;
	waitUntil {camCommitted _cam};	
	_cam camSetTarget vehicle player;
	_cam camSetRelPos [0,0,2];
	_cam camCommit 3;
	waitUntil {camCommitted _cam};

	_cam cameraEffect ["terminate","back"];
	showCinemaBorder false;
	hint "You Have Arrived At Your Destination";
	camDestroy _cam;
	player allowDamage true;
};