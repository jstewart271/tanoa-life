/*
	@File: fn_copLoadout.sqf
  
	@Author: Farhall + Knight
  
	@Description: Loads default gear for the APC faction...
*/
#include "..\..\script_macros.hpp"

call life_fnc_stripDownPlayer;

player forceAddUniform (["U_B_CombatUniform_mcam_worn"] select (call life_coplevel <= 1));
player addBackpack "B_Carryall_cbr";
player linkItem "ItemMap";
player linkItem "ItemCompass";
player linkItem "ItemWatch";
player linkItem "ItemGPS";
player linkItem "ItemRadio";

if (HAS_PERK("mindfulPlanner")) then { 
    player addGoggles "G_Tactical_Clear";
	player addWeapon "Rangefinder";
} else {
	player addWeapon "Binocular";
};

[] call PHX(playerSkins);
[] call life_fnc_saveGear;