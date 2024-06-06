/*
	@File: fn_getPatrol.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Gives the player a patrol mission to complete.
*/
#include "..\..\script_macros.hpp"
scopeName "getPatrol";

private _type = [
	["patrol", "response"] select (player getVariable ["Faction_Medic", false]),
	["patrol", "responsed to"] select (player getVariable ["Faction_Medic", false])
];

_type params ["_pType", "_pReason"];

if (PHX_DoingMission) exitwith { [format["You must complete your current %1 mission before getting a new one!", _pType]] spawn PHX(notify) };

private _side = switch (true) do {
    case (playerSide isEqualTo west): {"NATO_Missions"};
    case (playerSide isEqualTo east): {"TPLA_Missions"};
	case (player getVariable ["Faction_Medic", false]): {"NHS_Missions"};
    [format["Only NATO & TPLA can accept %1 missions!", _pType]] spawn PHX(notify);
	breakOut "getPatrol";
};

private _patrolPoint = LIFE_SETTINGS(getArray,_side);
if (_patrolPoint isEqualTo []) exitWith {[format["They're are no %1 assignments available at this time.", _pType]] spawn PHX(notify) };

if !(_patrolPoint isEqualTo []) then {
	_patrolPoint deleteAt (_patrolPoint find PHX_LastPatrol); // Remove the already completed mission
};

_patrolPoint = selectRandom _patrolPoint;

_patrolPoint params ["_pName", "_pPos"];

_dis = round((getPos player) distance (_pPos));
PHX_Patrol_Reward = round(10 * _dis);

life_cur_task = player createSimpleTask [format ["Patrol_%1", _pName]];
life_cur_task setSimpleTaskDestination (_pPos);
life_cur_task setSimpleTaskDescription [format ["You are to %2 %1", _pName, _pReason],"Faction Assignment",""];
life_cur_task setTaskState "Assigned";
player setCurrentTask life_cur_task;
PHX_DoingMission = true;

PHX_Cur_Patrol = _patrolPoint;
PHX_LastPatrol = []; // Reset...

[format["You have been requested to %2 %1", _pName, _pReason]] spawn PHX(notify);
[] spawn PHX(trackPatrol);