#include "..\..\script_macros.hpp"
/*
    File: fn_spikeStrip.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Creates a spike strip and preps it.
*/
params [
  ["_delay", 1, [0]]
];

if (!isNull objectParent player) exitWith {};
[false,"spikeStrip",1] call life_fnc_handleInv;

//--- Adds delay for hotkey
sleep _delay;

private _spikeStrip = "Land_Razorwire_F" createVehicle [0,0,0];
_spikeStrip attachTo[player,[0,5.5,0]];
_spikeStrip setDir 90;
_spikeStrip setVariable ["item","spikeDeployed",true];

life_action_spikeStripDeploy = player addAction["Place Spike Strip",{if (!isNull life_spikestrip) then {detach life_spikeStrip; life_spikeStrip = ObjNull;}; player removeAction life_action_spikeStripDeploy; life_action_spikeStripDeploy = nil;},"",999,false,false,"",'!isNull life_spikestrip'];
life_spikestrip = _spikeStrip;
waitUntil {isNull life_spikeStrip};

if (!isNil "life_action_spikeStripDeploy") then {player removeAction life_action_spikeStripDeploy;};
if (isNull _spikeStrip) exitWith {life_spikestrip = ObjNull;};
_spikeStrip setPos [(getPos _spikeStrip select 0),(getPos _spikeStrip select 1),0];
_spikeStrip setDamage 1;

life_action_spikeStripPickup = player addAction["Pick up Spike Strip",life_fnc_packupSpikes,"",0,false,false,"",' _spikes = nearestObjects[getPos player,["Land_Razorwire_F"],8] select 0; !isNil "_spikes" && !isNil {(_spikes getVariable "item")}'];

[_spikeStrip] remoteExec ["TON_fnc_spikeStrip",RSERV];
