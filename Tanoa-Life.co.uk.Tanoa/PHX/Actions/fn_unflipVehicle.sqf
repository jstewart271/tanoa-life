/*
	@File: fn_unflipVehicle.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Waits 3 seconds before flipping our target vehicle...

	@Parameters:
		0 - TYPE: OBJECT - DES: The vehicle we're unflipping...
*/
#include "..\..\script_macros.hpp"
if !(params [["_vehicle", objNull, [objNull]]]) exitWith {}; // You what??

if !(canSuspend) exitWith { _this spawn PHX(unflipVehicle) };

NOTIFY("Your vehicle will be unflipped in 3 seconds.","cyan");

sleep 3;

_vehicle allowDamage false;
_vehicle setPos [getPos _vehicle select 0, getPos _vehicle select 1, (getPos _vehicle select 2)+0.9];

sleep 2;
_vehicle allowDamage true;

NOTIFY("Your vehicle is now unflipped","green");