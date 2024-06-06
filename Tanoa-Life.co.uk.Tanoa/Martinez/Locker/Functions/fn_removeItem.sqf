/*
	File: fn_removeItem.sqf
	Function: Martinez_fnc_removeItem
	Author: Martinezzz

	Copyright (c) 2023 Martinezzz, Martinezzz Development
	All Rights Reserved

	Params:
		0: STRING
			- Mode of the script

		1: ARRAY
			- _this of the script
*/

params [
["_item", "", [""]]
];

private _complete = false;

switch true do {
	case (_item isEqualTo (uniform player)): {
		if (uniformItems player isEqualTo []) then {
			removeUniform player; _complete = true;
		} else {
			["Your uniform must be empty before storing it...", "red", "Error"] spawn PHX_fnc_notify; _complete = false;
		};
	};
	case (_item isEqualTo (vest player)): {
		if (vestItems player isEqualTo []) then {
			removeVest player; _complete = true;
		} else {
			["Your vest must be empty before storing it...", "red", "Error"] spawn PHX_fnc_notify; _complete = false;
		};
		
	};
	case (_item isEqualTo (backpack player)): {
		if (backpackItems player isEqualTo []) then {
			removeBackpack player; _complete = true;
		} else {
			["Your backpack must be empty before storing it...", "red", "Error"] spawn PHX_fnc_notify; _complete = false;
		};
	};
	case (((primaryWeaponMagazine player) select 0) isEqualTo _item): {player removePrimaryWeaponItem _item; _complete = true;};
	case (((handgunMagazine player) select 0) isEqualTo _item): {player removeSecondaryWeaponItem _item; _complete = true;};
	case (_item isEqualTo (goggles player)): {removeGoggles player; _complete = true;};
	case (_item isEqualTo (headgear player)): {removeHeadgear player; _complete = true;};
	case (_item isEqualTo (binocular player)): {player removeWeapon (binocular player); _complete = true;};
	case (_item in (assignedItems player)): {player unlinkItem _item; _complete = true;};
	case (_item isEqualTo (primaryWeapon player)): {player removeWeapon _item; _complete = true;};
	case (_item isEqualTo (secondaryWeapon player)): {player removeWeapon _item; _complete = true;};
	case (_item isEqualTo (handgunWeapon player)): {player removeWeapon _item; _complete = true;};
	case (_item in (primaryWeaponItems player)): {player removePrimaryWeaponItem _item; _complete = true;};
	case (_item in (secondaryWeaponItems player)): {player removeSecondaryWeaponItem _item; _complete = true;};
	case (_item in (handgunItems player)): {player removeHandgunItem _item; _complete = true;};
	case (_item in (uniformItems player)): {player removeItemFromUniform _item; _complete = true;};
	case (_item in (vestItems player)): {player removeItemFromVest _item; _complete = true;};
	case (_item in (backpackItems player)): {player removeItemFromBackpack _item; _complete = true;};
}; 

_complete;
