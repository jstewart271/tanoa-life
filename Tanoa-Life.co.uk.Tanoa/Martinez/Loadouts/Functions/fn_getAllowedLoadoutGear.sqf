/*
	File: fn_getAllowedLoadoutGear.sqf
	Function: Martinez_fnc_getAllowedLoadoutGear
	Author: Martinezzz

	Copyright (c) 2022 Martinezzz, Martinezzz Development
	All Rights Reserved
*/

private _allowedItemsArray = [];

switch (playerSide) do {
	case east: {
		// Weapons
		{
			private _cfg = getArray(missionConfigFile >> "CfgWeapons" >> "Tanoa" >> "havoc_general_store" >> _x);
			{
				_x params [
					["_className", "", [""]],
					["_displayName", "", [""]],
					["_buyPrice", 0, [0]],
					["_sellPrice", 0, [0]],
					["_condition", "", [""]]
				];

				if ((_condition isEqualTo "" || {call compile _condition}) && {_className isNotEqualTo "NONE"}) then {
					_allowedItemsArray pushBackUnique [_className, _buyPrice];
				};
			} forEach _cfg;
		} forEach ["weps", "mags", "accs", "items"];

		// Clothing
		{
			private _cfg = getArray(missionConfigFile >> "CfgClothing" >> "Tanoa" >> "havoc_clothing" >> _x);
			{
				_x params [
					["_className", "", [""]],
					["_displayName", "", [""]],
					["_buyPrice", 0, [0]],
					["_condition", "", [""]]
				];

				if ((_condition isEqualTo "" || {call compile _condition}) && {_className isNotEqualTo "NONE"}) then {
					_allowedItemsArray pushBackUnique [_className, _buyPrice];
				};
			} forEach _cfg;
		} forEach ["uniforms", "headgear", "goggles", "vests", "backpacks"];
	};

	case west: {
		{
			private _cfg = getArray(missionConfigFile >> "CfgWeapons" >> "Tanoa" >> "apc_general_Store" >> _x);
			{
				_x params [
					["_className", "", ["", 0]],
					["_displayName", "", ["", 0]],
					["_buyPrice", 0, [0]],
					["_sellPrice", 0, [0]],
					["_condition", "", [""]]
				];

				if ((_condition isEqualTo "" || {call compile _condition}) && {_className isNotEqualTo "NONE"}) then {
					_allowedItemsArray pushBackUnique [_className, _buyPrice];
				};
			} forEach _cfg;
		} forEach ["weps", "mags", "accs", "items"];

		// Clothing
		{
			private _cfg = getArray(missionConfigFile >> "CfgClothing" >> "Tanoa" >> "apc_clothing" >> _x);
			{
				_x params [
					["_className", "", [""]],
					["_displayName", "", [""]],
					["_buyPrice", 0, [0]],
					["_condition", "", [""]]
				];

				if ((_condition isEqualTo "" || {call compile _condition}) && {_className isNotEqualTo "NONE"}) then {
					_allowedItemsArray pushBackUnique [_className, _buyPrice];
				};
			} forEach _cfg;
		} forEach ["uniforms", "headgear", "goggles", "vests", "backpacks"];
	};


	case civilian: {
		// Weapons
		{
			private _store = _x;
			{
				private _cfg = getArray(missionConfigFile >> "CfgWeapons" >> "Tanoa" >> _store >> _x);
				{
					_x params [
						["_className", "", [""]],
						["_displayName", "", [""]],
						["_buyPrice", 0, [0]],
						["_sellPrice", 0, [0]],
						["_condition", "", [""]]
					];

					if ((_condition isEqualTo "" || {call compile _condition}) && {_className isNotEqualTo "NONE"}) then {
						_allowedItemsArray pushBackUnique [_className, _buyPrice];
					};
				} forEach _cfg;
			} forEach ["weps", "mags", "accs", "items"];
		} forEach ["black_market", "advanced_rebel", "basic_rebel", "smg_store", "handgun_store", "general_store"];

		// Clothing
		{
			private _store = _x;
			{
				private _cfg = getArray(missionConfigFile >> "CfgClothing" >> "Tanoa" >> _store >> _x);
				{
					_x params [
						["_className", "", [""]],
						["_displayName", "", [""]],
						["_buyPrice", 0, [0]],
						["_condition", "", [""]]
					];

					if ((_condition isEqualTo "" || {call compile _condition}) && {_className isNotEqualTo "NONE"}) then {
						_allowedItemsArray pushBackUnique [_className, _buyPrice];
					};
				} forEach _cfg;
			} forEach ["uniforms", "headgear", "goggles", "vests", "backpacks"];
		} forEach ["general_clothing", "diving_store", "gokart_store", "handgun_clothing_store", "rebel_store"];
	};
};
_allowedItemsArray = createHashMapfromArray _allowedItemsArray;
_allowedItemsArray;
