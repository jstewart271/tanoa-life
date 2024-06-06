#include "..\..\..\..\script_macros.hpp"
/*
 *  @File: fn_deletePlaceables.sqf
 *  @Author: Maximum
 *	@Modified: blackfisch, Zyn
 *
 *  Description:
 *  Handles deleting placeables
*/

params [
    ["_object",objNull,[objNull]]
];

if ((((playerSide in [west, east]) || player getVariable ['Faction_Medic', false]) && (isClass (missionConfigFile >> "CfgPlaceables" >> (typeOf _object)))) || player getVariable ["isAdmin",false]) then {
	deleteVehicle _object;
};