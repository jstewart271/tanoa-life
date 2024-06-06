#include "..\script_macros.hpp"
/*
    File: fn_survival.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    All survival? things merged into one thread.
*/
private ["_fnc_food","_fnc_water","_foodTime","_waterTime","_bp","_walkDis","_lastPos","_curPos"];

PHX_fnc_slowDeath = {
    if !(canSuspend) exitWith {};

    params [
        ["_var", "", [""]],
        ["_reason", "You died from unknown causes...", [""]]
    ];

    if (_var isEqualTo "") exitWith {};

    for "_i" from 0 to 1 step 0 do {
        if ((missionNamespace getVariable [_var, 0]) > 0) exitWith {}; // We're not longer dying...

        player setDamage ((damage player) + (random [0.05, 0.1, 0.15]));
        [] call PHX_fnc_hudUpdate;

        if (!alive player || { isDowned(player) }) exitWith {
            NOTIFY(_reason,"red");
        };

        NOTIFY("You feel a sharp pain in your stomach...","red");

        uiSleep (random [40, 80, 120]);
    };
};

_fnc_food =  {
    if (player getVariable ["isAdmin", false]) exitWith {};
    if !(isNull PHX_SlowDeath_Food) exitWith {};

    life_hunger = life_hunger - 10;
    [] call PHX_fnc_hudUpdate;

    if (life_hunger < 2) exitWith {
        PHX_SlowDeath_Food = ["life_hunger", "You have died from hunger."] spawn PHX_fnc_slowDeath;
    };

    switch (life_hunger) do  {
        case 30: {
            NOTIFY("You haven't eaten anything in awhile, You should find something to eat soon!","red");
        };
        case 20: {
            NOTIFY("You are starting to starve, you need to find something to eat otherwise you will die!","red");
        };
        case 10: {
            NOTIFY("You are now starving to death, you will die very soon if you don't eat something!","red");
        };
    };
};

_fnc_water = {
    if (player getVariable ["isAdmin", false]) exitWith {};
    if !(isNull PHX_SlowDeath_Water) exitWith {};

    life_thirst = life_thirst - 10;
    [] call PHX_fnc_hudUpdate;

    if (life_thirst < 2) exitWith {
        PHX_SlowDeath_Food = ["life_thirst", "You have died from dehydration."] spawn PHX_fnc_slowDeath;
    };

    switch (life_thirst) do  {
        case 30: {
            NOTIFY("You haven't drank anything in awhile, You should find something to drink soon.","red");
        };
        case 20: {
            NOTIFY("You haven't drank anything in along time, you should find something to drink soon or you'll start to die from dehydration.","red");
        };
        case 10: {
            NOTIFY("You are now suffering from severe dehydration find something to drink quickly!","red");
        };
    };
};

//Setup the time-based variables.
_foodTime = time;
_waterTime = time;
_walkDis = 0;
private _increase = 1;
_bp = "";
_lastPos = visiblePosition player;
_lastPos = (_lastPos select 0) + (_lastPos select 1);
_lastState = vehicle player;
_isMuscleman = false;

for "_i" from 0 to 1 step 0 do {
    /* Thirst / Hunger adjustment that is time based */
    if ((time - _waterTime) > 600) then {[] call _fnc_water; _waterTime = time;};
    if ((time - _foodTime) > 850) then {[] call _fnc_food; _foodTime = time;};

    _increase = [1, 1.25] select (HAS_PERK("muscleman"));
    
    /* Adjustment of carrying capacity based on backpack changes */
    if (backpack player isEqualTo "") then {
        life_maxWeight = floor((LIFE_SETTINGS(getNumber,"default_maxWeight")) * _increase);
        _bp = backpack player;
    } else {
        if (!(backpack player isEqualTo "") && {!(backpack player isEqualTo _bp) || { !(_isMuscleman isEqualTo (HAS_PERK("muscleman"))) }}) then {
            _bp = backpack player;
            _isMuscleman = (HAS_PERK("muscleman"));
            life_maxWeight = floor((LIFE_SETTINGS(getNumber,"default_maxWeight") + round(FETCH_CONFIG2(getNumber,"CfgVehicles",_bp,"maximumload") / 4)) * _increase);
        };
    };

    /* Check if the player's state changed? */
    if (!(vehicle player isEqualTo _lastState) || {!alive player}) then {
        [] call life_fnc_updateViewDistance;
        _lastState = vehicle player;
    };

    /* Check if the weight has changed and the player is carrying to much */
    if (life_carryWeight > life_maxWeight && {!isForcedWalk player}) then {
        player forceWalk true;
        if (LIFE_SETTINGS(getNumber,"player_fatigue") isEqualTo 1) then {player setFatigue 1;};

        if ((time - weightNotficiation) < 5) exitWith {};

        NOTIFY("You are over carrying your max weight! You will not be able to run or move fast till you drop some items!","red");
        weightNotficiation = time;
    } else {
        if (isForcedWalk player) then {
            player forceWalk false;
        };
    };

    /* Travelling distance to decrease thirst/hunger which is captured every second so the distance is actually greater then 650 */
    if (!alive player) then {_walkDis = 0;} else {
        _curPos = visiblePosition player;
        _curPos = (_curPos select 0) + (_curPos select 1);
        if (!(_curPos isEqualTo _lastPos) && {(isNull objectParent player)}) then {
            _walkDis = _walkDis + 1;
            if (_walkDis isEqualTo 650) then {
                _walkDis = 0;
                life_thirst = life_thirst - 5;
                life_hunger = life_hunger - 5;
                [] call PHX_fnc_hudUpdate;
            };
        };
        _lastPos = visiblePosition player;
        _lastPos = (_lastPos select 0) + (_lastPos select 1);
    };
    uiSleep 1;
};
