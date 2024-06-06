/*
	File: fn_displayClothingStore.sqf
	Function: Martinez_fnc_displayClothingStore
	Author: Martinezzz

	Copyright (c) 2022 Martinezzz, Martinezzz Development
	All Rights Reserved

	Params:
		0: STRING
			- Mode of the script

		1: ARRAY
			- _this of the script
*/

params [
	["_mode", "", [""]],
	"_this"
];

switch _mode do {
	case "onLoad": {
		private _display = _this select 0;
		private _ctrlPurchaseButton = _display displayCtrl 1;
		private _ctrlUniformButton = _display displayCtrl 3;
		private _ctrlVestButton = _display displayCtrl 4;
		private _ctrlBackpackButton = _display displayCtrl 5;
		private _ctrlHeadgearButton = _display displayCtrl 6;
		private _ctrlGogglesButton = _display displayCtrl 7;
		private _ctrlTree = _display displayCtrl 8;

		Martinez_ClothingStorePurchase = [-1, -1, -1, -1, -1];

		['fillTree', [_display]] call Martinez_fnc_displayClothingStore;

		private _cfgBase = missionConfigFile >> "CfgClothing" >> worldName >> Martinez_ClothingStore;
		private _cfgUniformArray = getArray(_cfgBase >> "uniforms");
		if (_cfgUniformArray isEqualTo []) then {_ctrlUniformButton ctrlEnable false;};

		private _cfgVestArray = getArray(_cfgBase >> "vests");
		if (_cfgVestArray isEqualTo []) then {_ctrlVestButton ctrlEnable false;};

		private _cfgBackpackArray = getArray(_cfgBase >> "backpacks");
		if (_cfgBackpackArray isEqualTo []) then {_ctrlBackpackButton ctrlEnable false;};

		private _cfgHeadgearArray = getArray(_cfgBase >> "headgear");
		if (_cfgHeadgearArray isEqualTo []) then {_ctrlHeadgearButton ctrlEnable false;};

		private _cfgGogglesArray = getArray(_cfgBase >> "goggles");
		if (_cfgGogglesArray isEqualTo []) then {_ctrlGogglesButton ctrlEnable false;};

		_ctrlPurchaseButton ctrlAddEventHandler ["ButtonDown", 		{['onButtonDownPurchase', 	_this] call Martinez_fnc_displayClothingStore}];
		_ctrlUniformButton 	ctrlAddEventHandler ["ButtonDown", 		{['onButtonDownUniform',  	_this] call Martinez_fnc_displayClothingStore}];
		_ctrlVestButton 	ctrlAddEventHandler ["ButtonDown", 		{['onButtonDownVest', 	 	_this] call Martinez_fnc_displayClothingStore}];
		_ctrlBackpackButton ctrlAddEventHandler ["ButtonDown", 		{['onButtonDownBackpack', 	_this] call Martinez_fnc_displayClothingStore}];
		_ctrlHeadgearButton ctrlAddEventHandler ["ButtonDown", 		{['onButtonDownHeadgear', 	_this] call Martinez_fnc_displayClothingStore}];
		_ctrlGogglesButton 	ctrlAddEventHandler ["ButtonDown", 		{['onButtonDownGoggles',  	_this] call Martinez_fnc_displayClothingStore}];
		_ctrlTree 			ctrlAddEventHandler ["TreeSelChanged",  {['onTreeSelChanged',  		_this] call Martinez_fnc_displayClothingStore}];

		['Create', _display] call Martinez_fnc_createClothingCharacter;
		private _obj = _display getVariable ["Martinez_ClothingCharacter", objNull];
		["setupCam", _display, (AGLToASL (_obj modelToWorld (_obj selectionPosition "head"))), 3.25] call Martinez_fnc_clothingCamera;
	};

	case "onUnload": {
		private _display = _this select 0;
		['Delete', _display] call Martinez_fnc_createClothingCharacter;
		['destroyCam'] call Martinez_fnc_clothingCamera;
	};

	case "fillTree": {
		private _display = _this select 0;
		private _ctrlTree = _display displayCtrl 8;
		private _ctrlPriceText = _display displayCtrl 11;
		_ctrlPriceText ctrlSetText "";

		tvClear _ctrlTree;

		private _shopMode = _display getVariable ["StoreMode", 0];
		private _storeConfigBase = missionConfigFile >> "CfgClothing" >> worldName >> Martinez_ClothingStore;
		private _storeData = getArray(_storeConfigBase >> (["uniforms", "vests", "backpacks", "headgear", "goggles"] select (_shopMode)));

		{
			_x params ["_className", "_customName", "_buyPrice", "_condition"];

			if ([_condition] call life_fnc_levelCheck) then {
				private _cfgDetails = [_className] call life_fnc_fetchCfgDetails;
				if (_cfgDetails isEqualTo []) exitWith {diag_log format ["[CLOTHINGSTORE]: There is something wrong with %1 in %2 store!", _className, Martinez_ClothingStore]};

				private _cfgDisplayName = _cfgDetails select 1;
				private _cfgPicture = _cfgDetails select 2;
				if (_className isEqualTo "NONE") then {_cfgPicture = ""};
				
				private _tvDisplayName = [_cfgDisplayName, _customName] select (_customName isNotEqualTo "");
				_tvDisplayName = _tvDisplayName regexReplace ['"', ''];
				_tvDisplayName = _tvDisplayName regexReplace ["'", ''];

				private _parentIndex = _ctrlTree tvAdd [[], _tvDisplayName];
				_ctrlTree tvSetData [[_parentIndex], str([_className, _customName, _buyPrice, _condition])];
				_ctrlTree tvSetPicture [[_parentIndex], _cfgPicture];
				_ctrlTree tvSetTooltip [[_parentIndex], format ["Name: %1\nPrice: £%2", _tvDisplayName, [_buyPrice] call life_fnc_numberText]];
			};
		} forEach _storeData;
	};

	case "onTreeSelChanged": {
		_this params ["_control", "_selectionPath"];
		private _display = ctrlParent _control;
		private _ctrlPrice = _display displayCtrl 11;
		private _ctrlTotalPrice = _display displayCtrl 12;
		private _ctrlPurchase = _display displayCtrl 1;

		private _obj = _display getVariable ["Martinez_ClothingCharacter", objNull];
		private _data = parseSimpleArray (_control tvData (tvCurSel _control));
		_data params ["_className", "_customName", "_buyPrice", "_condition"];

		private _shopMode = _display getVariable ["StoreMode", 0];
		switch (_shopMode) do {
			case 0: {private _clothingItems =  uniformItems player; _obj forceAddUniform _className; _clothingItems apply {_obj addItemToUniform _x}; };
			case 1: {private _vestItems =  vestItems player; _obj addVest _className; _vestItems apply {_obj addItemToVest _x}; };
			case 2: {private _backpackItems =  backpackItems player; removeBackpack _obj; _obj addBackpack _className; _backpackItems apply {_obj addItemToBackpack _x};};
			case 3: {_obj addHeadgear _className};
			case 4: {_obj addGoggles _className};
		};

		Martinez_ClothingStorePurchase set [_shopMode, _buyPrice];

		private _totalPrice = 0;
		{
			if (_x isNotEqualTo -1) then {
				_totalPrice = _totalPrice + _x;
			};
		} forEach Martinez_ClothingStorePurchase;

		private _priceColor = [[1, 0, 0,  1], [0, 1, 0, 1]] select (PHX_Cash >= _buyPrice);
		_ctrlPrice ctrlSetText format ["£%1", [_buyPrice] call life_fnc_numberText];
		_ctrlPrice ctrlSetTextColor _priceColor;

		private _totalPriceColor = [[1, 0, 0,  1], [0, 1, 0, 1]] select (PHX_Cash >= _totalPrice);
		_ctrlTotalPrice ctrlSetText format ["£%1", [_totalPrice] call life_fnc_numberText];
		_ctrlTotalPrice ctrlSetTextColor _totalPriceColor;

		[_obj] call PHX_fnc_playerSkins;
	};

	case "onButtonDownPurchase": {
		_this params ["_control"];
		private _display = ctrlParent _control;
        private _ctrlTree = _display displayCtrl 8;

		private _totalPrice = 0;
		{
			if (_x isNotEqualTo -1) then {
				_totalPrice = _totalPrice + _x;
			};
		} forEach Martinez_ClothingStorePurchase;

		if (_totalPrice > PHX_Cash) exitWith {titleText["You do not have enough money!","PLAIN"];};
		[_totalPrice, 1, 0, "Purchased Clothing"] call PHX_fnc_handleMoney;

		private _obj = _display getVariable ["Martinez_ClothingCharacter", objNull];
		private _objLoadout = getUnitLoadout [_obj, true];

		player setUnitLoadout _objLoadout;

		[] call PHX_fnc_playerSkins;
	};

	case "onButtonDownUniform": {
		_this params ["_control"];
		private _display = ctrlParent _control;

		_display setVariable ["StoreMode", 0];
		['fillTree', [_display]] call Martinez_fnc_displayClothingStore;
	};

	case "onButtonDownVest": {
		_this params ["_control"];
		private _display = ctrlParent _control;

		_display setVariable ["StoreMode", 1];
		['fillTree', [_display]] call Martinez_fnc_displayClothingStore;
	};

	case "onButtonDownBackpack": {
		_this params ["_control"];
		private _display = ctrlParent _control;

		_display setVariable ["StoreMode", 2];
		['fillTree', [_display]] call Martinez_fnc_displayClothingStore;
	};

	case "onButtonDownHeadgear": {
		_this params ["_control"];
		private _display = ctrlParent _control;

		_display setVariable ["StoreMode", 3];
		['fillTree', [_display]] call Martinez_fnc_displayClothingStore;
	};

	case "onButtonDownGoggles": {
		_this params ["_control"];
		private _display = ctrlParent _control;

		_display setVariable ["StoreMode", 4];
		['fillTree', [_display]] call Martinez_fnc_displayClothingStore;
	};
};
