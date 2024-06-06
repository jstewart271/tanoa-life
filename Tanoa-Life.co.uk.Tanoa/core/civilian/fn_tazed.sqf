#include "..\..\script_macros.hpp"
/*
    File: fn_tazed.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Starts the tazed animation and broadcasts out what it needs to.
*/
params [
    ["_unit",objNull,[objNull]],
    ["_shooter",objNull,[objNull]]
];

if (isNull _unit || isNull _shooter) exitWith {player allowDamage true; life_istazed = false;};

if (_shooter isKindOf "CAManBase" && (alive player && !(isDowned(player)))) then {
    if (!life_istazed) then {
        life_istazed = true;

        if (!(player getVariable ["Escorting",false])) then {
            detach player;
        };

        // Blurry effect...
		_effectBlur = ppEffectCreate ["DynamicBlur", 300];
		_effectBlur ppEffectEnable true;
		_effectBlur ppEffectAdjust [2.5];
		_effectBlur ppEffectCommit 3;
		PHX_effects pushBack [_effectBlur];

        disableUserInput true;
        player setUnconscious true;
        player setVariable ["isTazed", life_istazed, true];

        [0,format["%1 was tased by %2.",profileName, _shooter getVariable ["realname",name _shooter]]] remoteExecCall ["life_fnc_broadcast",RCLIENT];

        [_unit, "tazed"] remoteExecCall  ["life_fnc_say3D",0];

        sleep 10;
    
        life_istazed = false;
        player setUnconscious false;
        player setVariable ["isTazed", life_istazed, true];
        disableUserInput false;

        {ppEffectDestroy _x} forEach PHX_effects; // Remove Effects...

        player playMoveNow "amovppnemstpsraswrfldnon";
    };
} else {
    _unit allowDamage true;
    life_istazed = false;
};
