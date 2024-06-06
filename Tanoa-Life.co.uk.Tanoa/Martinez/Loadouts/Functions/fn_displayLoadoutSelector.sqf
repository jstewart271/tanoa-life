/*
	File: fn_displayLoadoutSelector.sqf
	Function: Martinez_fnc_displayLoadoutSelectorSelector
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
		private _ctrlHeader = _display displayCtrl 3;
		private _ctrlButtonPurchase = _display displayCtrl 6;
		private _ctrlButtonDelete = _display displayCtrl 7;
		private _ctrlButtonCreate = _display displayCtrl 8;
		private _ctrlButtonCreateSub = _display displayCtrl 15;
		private _ctrlTree = _display displayCtrl 9;

		{(_display displayCtrl _x) ctrlShow false;} forEach [13,14,15,16];

		if (count Martinez_LoadoutsArray >= Martinez_MaxLoadouts) then {_ctrlButtonCreate ctrlEnable false};
		_ctrlButtonPurchase ctrlEnable false;

		['Create', _display] call Martinez_fnc_createLoadoutCharacter;
		['fillTree', [_display]] call Martinez_fnc_displayLoadoutSelector;

		_ctrlHeader ctrlSetText format ["Loadout Selector (%1/%2)", count Martinez_LoadoutsArray, Martinez_MaxLoadouts];
		_ctrlButtonPurchase		ctrlAddEventHandler ["ButtonDown",     {['onButtonDownPurchase',  _this]  call Martinez_fnc_displayLoadoutSelector}];
		_ctrlButtonDelete		ctrlAddEventHandler ["ButtonDown",     {['onButtonDownDelete',    _this]  call Martinez_fnc_displayLoadoutSelector}];
		_ctrlButtonCreate		ctrlAddEventHandler ["ButtonDown", 	   {['onButtonDownCreate',    _this]  call Martinez_fnc_displayLoadoutSelector}];
		_ctrlTree				ctrlAddEventHandler ["TreeSelChanged", {['onTreeSelChanged',      _this]  call Martinez_fnc_displayLoadoutSelector}];
		_ctrlButtonCreateSub	ctrlAddEventHandler ["ButtonDown",     {['onButtonDownCreateSub', _this] spawn Martinez_fnc_displayLoadoutSelector}];

		private _obj = _display getVariable ["Martinez_LoadoutCharacter", objNull];
		["setupCam", _display, (AGLToASL (_obj modelToWorld (_obj selectionPosition "head"))), 3.25] call Martinez_fnc_loadoutCamera;
		[_display getVariable ["Martinez_LoadoutCharacter", objNull]] call PHX_fnc_playerSkins;
	};

	case "onUnload": {
		private _display = _this select 0;
		['Delete', _display] call Martinez_fnc_createLoadoutCharacter;
		['destroyCam'] call Martinez_fnc_loadoutCamera;
	};

	case "fillTree": {
		private _display = _this select 0;
		private _ctrlTree = _display displayCtrl 9;
		private _ctrlHeader = _display displayCtrl 3;
		private _ctrlButtonCreate = _display displayCtrl 8;

		_ctrlHeader ctrlSetText format ["Loadout Selector (%1/%2)", count Martinez_LoadoutsArray, Martinez_MaxLoadouts];
		if (count Martinez_LoadoutsArray >= Martinez_MaxLoadouts) then {_ctrlButtonCreate ctrlEnable false};

		tvClear _ctrlTree;
		{
			_x params ["_loadoutName", "_loadoutID", "_loadoutPhysical", "_loadoutVirtual"];

			private _validLoadout = [_loadoutPhysical] call Martinez_fnc_validLoadout;
			private _validLoadoutIcon = ["a3\ui_f_orange\data\displays\rscdisplayaanarticle\lock_ca.paa", "textures\check.paa"] select (_validLoadout isEqualTo []);
			private _validLoadoutColor = [[1, 0.212, 0.804, 1], [1, 1, 1, 1]] select (_validLoadout isEqualTo []);

			private _arrayIndex = _forEachIndex;
			private _parentIndex = _ctrlTree tvAdd [[], _loadoutName];
			_ctrlTree tvSetData [[_parentIndex], str ([_loadoutName, _loadoutID, _loadoutPhysical, _loadoutVirtual])];
			_ctrlTree tvSetValue [[_parentIndex], (_arrayIndex + 1)];
			_ctrlTree tvSetPictureRight [[_parentIndex], _validLoadoutIcon];
			_ctrlTree tvSetColor [[_parentIndex], _validLoadoutColor];

			private _flatArray = [_loadoutPhysical] call Martinez_fnc_flattenLoadoutArray;
			{
				_x params ["_subName", "_array"];
				if (count _array > 0) then {
					private _subParentIndex = _ctrlTree tvAdd [[_parentIndex], _subName];
					_ctrlTree tvSetData [[_parentIndex, _subParentIndex], str ([_loadoutName, _loadoutID, _loadoutPhysical, _loadoutVirtual])];
					_ctrlTree tvSetValue [[_parentIndex, _subParentIndex], 0];

					if (_subName isEqualTo "Virtual") then {
						{
							_x params ["_varName", "_amount"];
							private _cfgVirtualDisplayName = (getText(missionConfigFile >> "CfgItems" >> _varName >> "displayName"));
							private _cfgIcon = format ["data\icons\%1", getText(missionConfigFile >> "CfgItems" >> _varName >> "icon")];
							private _formattedChildName = format ["%1x %2", _amount, _cfgVirtualDisplayName];

							private _childIndex = _ctrlTree tvAdd [[_parentIndex, _subParentIndex], _formattedChildName];
							_ctrlTree tvSetPicture [[_parentIndex, _subParentIndex, _childIndex], _cfgIcon];
							_ctrlTree tvSetData [[_parentIndex, _subParentIndex, _childIndex], str ([_loadoutName, _loadoutID, _loadoutPhysical, _loadoutVirtual])];
							_ctrlTree tvSetValue [[_parentIndex, _subParentIndex, _childIndex], 0];
						} forEach _array;
					} else {
						{
							_x params ["_className", "_amount"];
							if (_className isNotEqualTo "") then {
								private _validPicture = ["", "a3\ui_f_orange\data\displays\rscdisplayaanarticle\lock_ca.paa"] select (_className in _validLoadout);
								private _validColour = [[1, 1, 1, 1], [1, 0.212, 0.804, 1]] select (_className in _validLoadout);

								private _details = [_className] call life_fnc_fetchCfgDetails;
								private _cfgDisplayname = (_details select 1);
								private _cfgPicture = (_details select 2);
								private _formatted = format ["%1x %2", _amount, _cfgDisplayname];

								private _childIndex = _ctrlTree tvAdd [[_parentIndex, _subParentIndex], _formatted];
								_ctrlTree tvSetPicture [[_parentIndex, _subParentIndex, _childIndex], _cfgPicture];
								_ctrlTree tvSetData [[_parentIndex, _subParentIndex, _childIndex], str ([_loadoutName, _loadoutID, _loadoutPhysical, _loadoutVirtual])];
								_ctrlTree tvSetValue [[_parentIndex, _subParentIndex, _childIndex], 0];

								_ctrlTree tvSetPictureRight [[_parentIndex, _subParentIndex, _childIndex], _validPicture];
								_ctrlTree tvSetColor [[_parentIndex, _subParentIndex, _childIndex], _validColour];
							};
						} forEach _array;
					};
				};
			} forEach [["Physical", _flatArray], ["Virtual", _loadoutVirtual]];
		} forEach Martinez_LoadoutsArray;
	};

	case "onButtonDownPurchase": {
		_this params ["_control"];
		private _display = ctrlParent _control;
		private _ctrlTree = _display displayCtrl 9;
		if (tvCurSel _ctrlTree isEqualTo -1) exitWith {};

		private _data = parseSimpleArray (_ctrlTree tvData (tvCurSel _ctrlTree));
		_data params ["_loadoutName", "_loadoutID", "_loadoutPhysical", "_loadoutVirtual"];

		private _price = [_loadoutPhysical, _loadoutVirtual] call Martinez_fnc_getLoadoutPrice;

		[_price, 1, 1, (format["Purchased Loadout %1",_loadoutName])] call PHX_fnc_handleMoney;

		closeDialog 0;
		player setUnitLoadout _loadoutPhysical;
		{
			_x params ["_var", "_amount"];
			[true, _var, _amount] call life_fnc_handleInv;
		} forEach _loadoutVirtual;
		[format ["You have purchased '%1' for £%2", _loadoutName, [_price] call life_fnc_numberText], "green"] call PHX_fnc_notify;

		[player] call PHX_fnc_playerSkins;
		[1] call SOCK_fnc_updatePartial;
        [3] call SOCK_fnc_updatePartial;
	};

	case "onButtonDownDelete": {
		_this params ["_control"];
		private _display = ctrlParent _control;
		private _ctrlTree = _display displayCtrl 9;
		private _ctrlHeader = _display displayCtrl 3;
		private _ctrlButtonCreate = _display displayCtrl 8;
		_ctrlButtonCreate ctrlEnable true;

		if ((tvCurSel _ctrlTree) isEqualTo -1) exitWith {};
		private _data = parseSimpleArray (_ctrlTree tvData (tvCurSel _ctrlTree));
		_data params ["_loadoutName", "_loadoutID", "_loadoutPhysical", "_loadoutVirtual"];

		["Delete", [_loadoutID, getPlayerUID player]] remoteExec ["MartinezSrv_fnc_loadoutServer", 2];
		Martinez_LoadoutsArray deleteAt ((_ctrlTree tvValue (tvCurSel _ctrlTree)) - 1);
		['fillTree', [_display]] call Martinez_fnc_displayLoadoutSelector;

		_ctrlHeader ctrlSetText format ["Loadout Selector (%1/%2)", count Martinez_LoadoutsArray, 10];

		[format ["'%1' loadout has been deleted!", _loadoutName], "red"] call PHX_fnc_notify;

		_ctrlTree tvSetCurSel [0];
	};

	case "onButtonDownCreate": {
		_this params ["_control"];
		private _display = ctrlParent _control;
		if (count Martinez_LoadoutsArray >= Martinez_MaxLoadouts) exitWith {};

		{(_display displayCtrl _x) ctrlShow false;} forEach [1,2,3,4,5,6,7,8,9,10,11,12];
		{(_display displayCtrl _x) ctrlShow true;} forEach [13,14,15,16];

		private _obj = _display getVariable ["Martinez_LoadoutCharacter", objNull];
		_obj setUnitLoadout (getUnitLoadout player);
		[_obj] call PHX_fnc_playerSkins;
	};

	case "onButtonDownCreateSub": {
		_this params ["_control"];
		private _display = ctrlParent _control;
		private _ctrlInputName = _display displayCtrl 16;

		if (ctrlText _ctrlInputName isEqualTo "") exitWith {["You have to put a name for the loadout!", "red"] call PHX_fnc_notify;};
		if (count Martinez_LoadoutsArray >= Martinez_MaxLoadouts) exitWith {};

		private _virtualAllowedArray = switch (true) do {
			case (playerSide isEqualTo west): {getArray(missionConfigFile >> "CfgShops" >> "apc_market" >> "items")};
			case (playerSide isEqualTo east): {getArray(missionConfigFile >> "CfgShops" >> "hav_market" >> "items")};
			case (player getVariable ['Faction_Medic', false]): {getArray(missionConfigFile >> "CfgShops" >> "nhs_market" >> "items")};
			case (playerSide isEqualTo civilian): {getArray(missionConfigFile >> "CfgShops" >> "rebel_market" >> "items")};
		};

		private _virtualItems = [];
		{
			private _amount = missionNamespace getVariable [format ["life_inv_%1", getText(missionConfigFile >> "CfgItems" >> _x >> "variable")], 0];
			private _items = [];

			if (_amount > 0) then {
				_virtualItems pushBackUnique [getText(missionConfigFile >> "CfgItems" >> _x >> "variable"), _amount];
			};
		} forEach _virtualAllowedArray;

		["Create", [getPlayerUID player, ctrlText _ctrlInputName, str(playerSide), getUnitLoadout [player, true], _virtualItems]] remoteExec ["MartinezSrv_fnc_loadoutServer", 2];
		Martinez_LoadoutsArray = [];
		uiSleep 0.2;

		{ (_display displayCtrl _x) ctrlShow true; } forEach [1,2,3,4,5,6,7,8,9,10,11,12];
		{ (_display displayCtrl _x) ctrlShow false; } forEach [13,14,15,16];
		_ctrlInputName ctrlSetText "";
		waitUntil {Martinez_LoadoutsArray isNotEqualTo []};
		['fillTree', [_display]] call Martinez_fnc_displayLoadoutSelector;
	};

	case "onTreeSelChanged": {
		_this params ["_control", "_selectionPath"];
		private _display = ctrlParent _control;
		private _ctrlPrice = _display displayCtrl 12;
		private _ctrlPurchase = _display displayCtrl 6;
		private _obj = _display getVariable ["Martinez_LoadoutCharacter", objNull];
		private _data = parseSimpleArray (_control tvData (tvCurSel _control));
		_data params ["_loadoutName", "_loadoutID", "_loadoutPhysical", "_loadoutVirtual"];
		_obj setUnitLoadout _loadoutPhysical;

		[_obj] call PHX_fnc_playerSkins;
		private _validLoadout = [_loadoutPhysical] call Martinez_fnc_validLoadout;
		private _price = [_loadoutPhysical, _loadoutVirtual] call Martinez_fnc_getLoadoutPrice;
		private _cashColor = [[1, 0, 0,  1], [0, 1, 0, 1]] select (Martinez_ATMCash >= _price);

		if (_validLoadout isEqualTo []) then {
			_ctrlPrice ctrlSetText format ["£%1", [_price] call life_fnc_numberText];
			_ctrlPrice ctrlSetTextColor _cashColor;
			_ctrlPurchase ctrlEnable true;
		} else {
			_ctrlPrice ctrlSetText "INVALID LOADOUT";
			_ctrlPrice ctrlSetTextColor [1,0.212,0.804,1];
			_ctrlPurchase ctrlEnable false;
		};
	};
};

