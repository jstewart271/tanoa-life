/*
	File: fn_getPhysicalItemMass.sqf
	Function: Martinez_fnc_getPhysicalItemMass
	Author: Martinezzz

	Copyright (c) 2023 Martinezzz, Martinezzz Development
	All Rights Reserved
*/

params ["_className"];

private _cfgBase = switch (true) do {
	case (isClass(configFile >> "CfgMagazines" >> _className)): {"CfgMagazines"};
	case (isClass(configFile >> "CfgWeapons" >> _className)): {"CfgWeapons"};
	case (isClass(configFile >> "CfgVehicles" >> _className)): {"CfgVehicles"};
	case (isClass(configFile >> "CfgGlasses" >> _className)): {"CfgGlasses"};
};

private _itemCfg = configFile >> _cfgBase >> _className;

if (isNumber(_itemCfg >> "mass")) exitWith { getNumber(_itemCfg >> "mass"); }; 
if (isNumber(_itemCfg >> "ItemInfo" >> "mass")) exitWith { getNumber(_itemCfg >> "ItemInfo" >> "mass"); }; 
if (isNumber(_itemCfg >> "WeaponSlotsInfo" >> "mass")) exitWith { getNumber(_itemCfg >> "WeaponSlotsInfo" >> "mass"); }; 
  