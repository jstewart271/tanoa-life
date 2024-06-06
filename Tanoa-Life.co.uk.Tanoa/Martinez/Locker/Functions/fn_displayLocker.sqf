#include "..\..\..\script_macros.hpp"

/*
	File: fn_displayLocker.sqf
	Function: Martinez_fnc_displayLocker
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
	["_mode", "", [""]],
	"_this"
];

switch _mode do {
	case "onLoad": {
		private _display = _this select 0;
		private _ctrlHeader = _display displayCtrl 3;
		private _ctrlButtonUpgrade = _display displayCtrl 11;
		private _ctrlButtonUpgradeSub = _display displayCtrl 16;
		private _ctrlButtonTake = _display displayCtrl 4;
		private _ctrlButtonStore = _display displayCtrl 5;

		{(_display displayCtrl _x) ctrlShow false;} forEach [14,15,16,17]; // Upgrade Layer

		['fillTreeLocker', [_display]] call Martinez_fnc_displayLocker;
		['fillTreeUnit', [_display]] call Martinez_fnc_displayLocker;

		_ctrlHeader ctrlSetText format ["Faction Locker - Tier %1", Martinez_LockerData get "Tier"];
		_ctrlButtonUpgrade ctrlAddEventHandler ['ButtonDown', {['onButtonDownUpgradeHeader', _this] call Martinez_fnc_displayLocker}];
		_ctrlButtonUpgradeSub ctrlAddEventHandler ['ButtonDown', {['onButtonDownUpgradeSub', _this] call Martinez_fnc_displayLocker}];
		_ctrlButtonTake ctrlAddEventHandler ["ButtonDown", {["onButtonDownTake", _this] spawn Martinez_fnc_displayLocker}];
		_ctrlButtonStore ctrlAddEventHandler ["ButtonDown", {["onButtonDownStore", _this] spawn Martinez_fnc_displayLocker}];
		
		if ((Martinez_LockerData get "Tier") isEqualTo 4) then {_ctrlButtonUpgrade ctrlEnable false;};
	};

	case "onUnload": {
		private _display = _this select 0;
		["UpgradeItems", [getPlayerUID player, Martinez_LockerData, playerSide]] remoteExec ["MartinezSrv_fnc_lockerServer", 2];
		call SOCK_fnc_updateRequest;
	};

	case "fillTreeLocker": {
		private _display = _this select 0;
		private _ctrlTree = _display displayCtrl 8;
		private _weightPhysical = 0;
		private _weightVirtual = 0;

		tvClear _ctrlTree;
		{
			private _name = _x;
			private _array = Martinez_LockerData get _name;

			private _parentIndex = _ctrlTree tvAdd [[], format ["%1 - Locker", _name]];
			_ctrlTree tvSetData [[_parentIndex], ""];
			_ctrlTree tvSetValue [[_parentIndex], 0];
			_ctrlTree tvSetPicture [[_parentIndex], "data\ui\Locker.paa"];
				
			if (count _array > 0) then {
				if (_name isEqualTo "Virtual") then {
					{
						_x params ["_varName", "_amount"];
						private _cfgVirtualDisplayName = getText(missionConfigFile >> "CfgItems" >> _varName >> "displayName");
						private _cfgIcon = format ["data\icons\%1", getText(missionConfigFile >> "CfgItems" >> _varName >> "icon")];
						private _cfgWeight = getNumber(missionConfigFile >> "CfgItems" >> _varName >> "weight");
						private _formattedChildName = format ["%1x %2", _amount, _cfgVirtualDisplayName];

						private _subParentIndex = _ctrlTree tvAdd [[_parentIndex], _formattedChildName];
						_ctrlTree tvSetPicture [[_parentIndex, _subParentIndex], _cfgIcon];
						_ctrlTree tvSetData [[_parentIndex, _subParentIndex], _varName];
						_ctrlTree tvSetValue [[_parentIndex, _subParentIndex], _amount];
						_ctrlTree tvSetTooltip [[_parentIndex, _subParentIndex], _cfgVirtualDisplayName];

						_weightVirtual = _weightVirtual + (_cfgWeight * _amount);
					} forEach _array;
				} else {
					{
						_x params ["_className", "_amount"];
						if (_className isNotEqualTo "") then {
							private _details = [_className] call life_fnc_fetchCfgDetails;
							private _cfgDisplayname = (_details select 1);
							private _cfgPicture = (_details select 2);
							private _formatted = format ["%1x %2", _amount, _cfgDisplayname];
							private _mass = ([_className] call Martinez_fnc_getPhysicalItemMass);

							private _subParentIndex = _ctrlTree tvAdd [[_parentIndex], _formatted];
							_ctrlTree tvSetPicture [[_parentIndex, _subParentIndex], _cfgPicture];
							_ctrlTree tvSetData [[_parentIndex, _subParentIndex], _className];
							_ctrlTree tvSetValue [[_parentIndex, _subParentIndex], _amount];
							_ctrlTree tvSetTooltip [[_parentIndex, _subParentIndex], format ["%1\nMass: %2", _cfgDisplayname, _mass]];

							_weightPhysical = _weightPhysical + (_mass * _amount);
						};
					} forEach (_array);
				};
			};
		} forEach ["Physical", "Virtual"];

		Martinez_LockerData set ["PhysicalWeight", _weightPhysical];
		Martinez_LockerData set ["VirtualWeight", _weightVirtual];

		tvExpandAll _ctrlTree;
	};

	case "fillTreeUnit": {
		private _display = _this select 0;
		private _ctrlTree = _display displayCtrl 9;

		tvClear _ctrlTree;
		{
			private _name = _x;
			private _parentIndex = _ctrlTree tvAdd [[], _name];
			_ctrlTree tvSetData [[_parentIndex], ""];
			_ctrlTree tvSetValue [[_parentIndex], 0];
			_ctrlTree tvSetPicture [[_parentIndex], "a3\ui_f\data\gui\rsc\rscdisplaymain\menu_singleplayer_ca.paa"];

			if (_name isEqualTo "Virtual") then {
				{
					if(ITEM_VALUE(configName _x) > 0) then {
						private _cfgVirtualDisplayName = getText(missionConfigFile >> "CfgItems" >> (configName _x) >> "displayName");
						private _cfgIcon = format ["data\icons\%1", getText(missionConfigFile >> "CfgItems" >> (configName _x) >> "icon")];
						private _formattedChildName = format ["%1x %2", ITEM_VALUE(configName _x), _cfgVirtualDisplayName];

						private _subParentIndex = _ctrlTree tvAdd [[_parentIndex], _formattedChildName];
						_ctrlTree tvSetPicture [[_parentIndex, _subParentIndex], _cfgIcon];
						_ctrlTree tvSetData [[_parentIndex, _subParentIndex], configName _x];
						_ctrlTree tvSetValue [[_parentIndex, _subParentIndex], ITEM_VALUE(configName _x)];
						_ctrlTree tvSetTooltip [[_parentIndex, _subParentIndex], _cfgVirtualDisplayName];
					};
				} forEach ("true" configClasses (missionConfigFile >> "CfgItems"));
			} else {
				{
					_x params [
						"_header", 
						["_childClass", []]
					];
					
					if (_header isNotEqualTo "") then {
						private _details = [_header] call life_fnc_fetchCfgDetails;
						private _cfgDisplayname = (_details select 1);
						private _cfgPicture = (_details select 2);
						private _formatted = format ["%1x %2", "1", _cfgDisplayname];
						private _mass = ([_header] call Martinez_fnc_getPhysicalItemMass);

						private _subParentIndex = _ctrlTree tvAdd [[_parentIndex], _formatted];
						_ctrlTree tvSetPicture [[_parentIndex, _subParentIndex], _cfgPicture];
						_ctrlTree tvSetData [[_parentIndex, _subParentIndex], _header];
						_ctrlTree tvSetValue [[_parentIndex, _subParentIndex], 1];
						_ctrlTree tvSetTooltip [[_parentIndex, _subParentIndex], format ["%1\nMass: %2", _cfgDisplayname, _mass]];

						private _inTree = [];

						if (_childClass isNotEqualTo []) then {
							{
								private _childClassItem = _x;


								if (!(_childClassItem in _inTree) && (_childClassItem isNotEqualTo "")) then {
									private _itemCount = {_childClassItem isEqualTo _x} count _childClass;
									_inTree pushBack _childClassItem;

									private _details = [_childClassItem] call life_fnc_fetchCfgDetails;
									private _cfgDisplayname = (_details select 1);
									private _cfgPicture = (_details select 2);
									private _formatted = format ["%1x %2", _itemCount, _cfgDisplayname];
									private _mass = ([_childClassItem] call Martinez_fnc_getPhysicalItemMass);

									private _childIndex = _ctrlTree tvAdd [[_parentIndex, _subParentIndex], _formatted];
									_ctrlTree tvSetPicture [[_parentIndex, _subParentIndex, _childIndex], _cfgPicture];
									_ctrlTree tvSetData [[_parentIndex, _subParentIndex, _childIndex], _childClassItem];
									_ctrlTree tvSetValue [[_parentIndex, _subParentIndex, _childIndex], _itemCount];
									_ctrlTree tvSetTooltip [[_parentIndex, _subParentIndex, _childIndex], format ["%1\nMass: %2", _cfgDisplayname, _mass]];
								};
							} forEach _childClass;
						};
					};
				} forEach ([
					[primaryWeapon player, (primaryWeaponItems player + primaryWeaponMagazine player)],
					[handgunWeapon player, (handgunItems player + handgunMagazine player)],
					[secondaryWeapon player, (secondaryWeaponItems player + secondaryWeaponMagazine player)],
					[uniform player, uniformItems player],
					[vest player, vestItems player],
					[backpack player, backpackitems player],
					headgear player, goggles player
				]);
			};
		} forEach ["Physical", "Virtual"];

		tvExpandAll _ctrlTree;
		["updatePhysicalProgressBar", [_display, Martinez_LockerData get "PhysicalWeight"]] call Martinez_fnc_displayLocker;
		["updateVirtualProgressBar", [_display, Martinez_LockerData get "VirtualWeight"]] call Martinez_fnc_displayLocker;
	};

	case "onButtonDownUpgradeHeader": {
		_this params ["_control"];
		private _display = ctrlParent _control;
		private _ctrlCombo = _display displayCtrl 17;

		{(_display displayCtrl _x) ctrlShow false;} forEach [1,2,3,4,5,6,7,8,9,10,11,12,13,18,19,20]; // Standard Layer
		{(_display displayCtrl _x) ctrlShow true;} forEach [14,15,16,17]; // Upgrade Layer

		lbClear _ctrlCombo;
		{
			private _cfgPrice = getNumber(missionConfigFile >> "CfgLockers" >> ((_x splitString " ") joinString "") >> "upgradeCost");
			private _cfgvirtualStorage = getNumber(missionConfigFile >> "CfgLockers" >> ((_x splitString " ") joinString "") >> "virtualStorage");
			private _cfgPhyscialStorage = getNumber(missionConfigFile >> "CfgLockers" >> ((_x splitString " ") joinString "") >> "physicalStorage");

			private _index = _ctrlCombo lbAdd _x; 
			_ctrlCombo lbSetData [_index, _x];
			_ctrlCombo lbSetTooltip [_index, format ["%1 \nPrice: £%2 \nVirtual Storage: %3 \nPhyscial Storage: %4", _x, [_cfgPrice] call life_fnc_numberText, [_cfgvirtualStorage] call life_fnc_numberText, [_cfgPhyscialStorage] call life_fnc_numberText]];
		} forEach ["Tier 2", "Tier 3", "Tier 4"];
	};

	case "onButtonDownUpgradeSub": {
		_this params ["_control"];
		private _display = ctrlParent _control;
		private _ctrlCombo = _display displayCtrl 17;
		private _lbData = _ctrlCombo lbData (lbCurSel _ctrlCombo);
		private _ctrlHeader = _display displayCtrl 3;
		private _ctrlButtonUpgrade = _display displayCtrl 11;
		
		private _cfgPrice = getNumber(missionConfigFile >> "CfgLockers" >> ((_lbData splitString " ") joinString "") >> "upgradeCost");
		if (PHX_ATMCash < _cfgPrice) exitWith {["You do not have enough money in your bank account!", "red", "Error"] call PHX_fnc_notify};
		[_cfgPrice, 1, 1, format ["Upgrade Locker to %1", _lbData]] call PHX_fnc_handleMoney;
		[format ["You have upgraded you locker to <t font='RobotoCondensedBold'>%1</t>!", _lbData], "green"] call PHX_fnc_notify;

		private _trim = _lbData trim [" Tier", 0];
		Martinez_LockerData set ["Tier", (parseNumber _trim)];
		["UpgradeTier", [getPlayerUID player, (parseNumber _trim), playerSide]] remoteExec ["MartinezSrv_fnc_lockerServer", 2];

		{(_display displayCtrl _x) ctrlShow true;} forEach [1,2,3,4,5,6,7,8,9,10,11,12,13,18,19,20]; // Standard Layer
		{(_display displayCtrl _x) ctrlShow false;} forEach [14,15,16,17]; // Upgrade Layer

		_ctrlHeader ctrlSetText format ["Faction Locker - Tier %1", Martinez_LockerData get "Tier"];
		if ((Martinez_LockerData get "Tier") isEqualTo 4) then {_ctrlButtonUpgrade ctrlEnable false;};
	};

	case "updatePhysicalProgressBar": {
		_this params ["_display", "_weight"];
		private _ctrlProgressBar = _display displayCtrl 18;
		private _ctrlProgressBarText = _display displayCtrl 12;

		private _cfgBase = missionConfigFile >> "CfgLockers" >> (format ["Tier%1", Martinez_LockerData get "Tier"]);
		private _cfgWeight = getNumber(_cfgBase >> "physicalStorage");
		private _weight = Martinez_LockerData get "PhysicalWeight";

		_ctrlProgressBar progressSetPosition (_weight/_cfgWeight);
		_ctrlProgressBarText ctrlSetStructuredText parseText format ["<t align='center' size='0.8'>Physical Weight: %1kg / %2kg", [_weight] call life_fnc_numberText, [_cfgWeight] call life_fnc_numberText]
	};

	case "updateVirtualProgressBar": {
		_this params ["_display", "_weight"];
		private _ctrlProgressBar = _display displayCtrl 19;
		private _ctrlProgressBarText = _display displayCtrl 13;

		private _cfgBase = missionConfigFile >> "CfgLockers" >> (format ["Tier%1", Martinez_LockerData get "Tier"]);
		private _cfgWeight = getNumber(_cfgBase >> "virtualStorage");

		_ctrlProgressBar progressSetPosition (_weight/_cfgWeight);
		_ctrlProgressBarText ctrlSetStructuredText parseText format ["<t align='center' size='0.8'>Virtual Weight: %1kg / %2kg", [_weight] call life_fnc_numberText, [_cfgWeight] call life_fnc_numberText]

	};

	case "onButtonDownTake": {
		_this params ["_control"];
		private _display = ctrlParent _control;
		private _ctrlTree = _display displayCtrl 8;
		private _ctrlAmount = parseNumber(ctrlText 20);
		private _lockerInvtvData = _ctrlTree tvData (tvCurSel _ctrlTree);
		private _lockerInvtvValue = _ctrlTree tvValue (tvCurSel _ctrlTree);
		if (_lockerInvtvData isEqualTo "") exitWith {["You can not take items from your personel inventory!", "red", "Error"] call PHX_fnc_notify};
		if ((_ctrlAmount > _lockerInvtvValue) OR _ctrlAmount < 1) exitWith {["You do not have enough items to take!", "red", "Error"] call PHX_fnc_notify};
		private _virtualItem = isClass (missionConfigFile >> "CfgItems" >> _lockerInvtvData);

		if (_virtualItem) then {
			if !([true, _lockerInvtvData, _ctrlAmount] call life_fnc_handleInv) exitWith {["You do not have enough virtual inventory space!", "red", "Error"] call PHX_fnc_notify};

			private _virtualHashmap = Martinez_LockerData get "Virtual";
			private _index = [_lockerInvtvData, _virtualHashmap] call LIFE_fnc_index;
			private _takenArry = (_virtualHashmap select _index);
			_takenArry params ["_var", "_amount"];
			_amount = _amount - _ctrlAmount;
			
			if (_amount isEqualTo 0) then { 
				_virtualHashmap deleteAt _index; 
			} else {
				_virtualHashmap set [_index, [_var, _amount]];
			};
		} else {
			private _physicalHashmap = Martinez_LockerData get "Physical";
			private _index = [_lockerInvtvData, _physicalHashmap] call LIFE_fnc_index;
			private _takenArry = (_physicalHashmap select _index);
			_takenArry params ["_classname", "_amount"];

			for "_i" from 1 to _ctrlAmount do {
				if !([_classname, false] call PHX_fnc_handleGear) exitWith {["You have taken out as many as you can!", "red", "Error"] call PHX_fnc_notify};
				_amount = _amount - 1;

				if (_amount isEqualTo 0) then { 
					_physicalHashmap deleteAt _index; 
				} else {
					_physicalHashmap set [_index, [_classname, _amount]];
				};
			};
		};

		['fillTreeLocker', [_display]] call Martinez_fnc_displayLocker;
		['fillTreeUnit', [_display]] call Martinez_fnc_displayLocker;

		["updatePhysicalProgressBar", [_display, Martinez_LockerData get "PhysicalWeight"]] call Martinez_fnc_displayLocker;
		["updateVirtualProgressBar", [_display, Martinez_LockerData get "VirtualWeight"]] call Martinez_fnc_displayLocker;
	};

	case "onButtonDownStore": {
		_this params ["_control"];
		private _display = ctrlParent _control;
		private _ctrlTree = _display displayCtrl 9;
		private _ctrlAmount = parseNumber(ctrlText 20);
		private _unitInvtvData = _ctrlTree tvData (tvCurSel _ctrlTree);
		private _unitInvtvValue = _ctrlTree tvValue (tvCurSel _ctrlTree);
		if ((_ctrlAmount > _unitInvtvValue) OR _ctrlAmount < 1) exitWith {["You do not have enough items to store!", "red", "Error"] call PHX_fnc_notify};
		if (_unitInvtvData isEqualTo "") exitWith {["You can not store items from a locker!", "red", "Error"] call PHX_fnc_notify};
		private _virtualItem = isClass (missionConfigFile >> "CfgItems" >> _unitInvtvData);

		if (_virtualItem) then {
			private _cfgWeightVirt = (getNumber(missionConfigFile >> "CfgItems" >> _unitInvtvData >> "Weight")) * _ctrlAmount;
			private _lockerWeight = Martinez_LockerData get "VirtualWeight";
			private _cfgBase = missionConfigFile >> "CfgLockers" >> (format ["Tier%1", Martinez_LockerData get "Tier"]);
			private _cfgWeightLocker = getNumber(_cfgBase >> "virtualStorage");
			private _virtualLocker = Martinez_LockerData get "Virtual";
			private _index = [_unitInvtvData, _virtualLocker] call LIFE_fnc_index;

			if ((_lockerWeight + _cfgWeightVirt) > _cfgWeightLocker) exitWith {["Your locker has ran out of weight!", "red", "Error"] call PHX_fnc_notify};
			if !([false, _unitInvtvData, _ctrlAmount] call life_fnc_handleInv) exitWith {["You do not have any of the selected item on your person!", "red", "Error"] call PHX_fnc_notify};

			if (_index isEqualTo -1) then {
				_virtualLocker pushBack [_unitInvtvData, _ctrlAmount];
			} else {
				(_virtualLocker select _index) params ["_var", "_amount"];
				_amount = _amount + _ctrlAmount;
				_virtualLocker set [_index, [_var, _amount]];
			};
		} else {
			private _cfgMass = ([_unitInvtvData] call Martinez_fnc_getPhysicalItemMass) * _ctrlAmount;
			private _lockerWeight = Martinez_LockerData get "PhysicalWeight";
			private _cfgBase = missionConfigFile >> "CfgLockers" >> (format ["Tier%1", Martinez_LockerData get "Tier"]);
			private _cfgWeightLocker = getNumber(_cfgBase >> "PhysicalStorage");
			private _physicalLocker = Martinez_LockerData get "Physical";
			private _flattenLoadout = [getUnitLoadout [player, true]] call Martinez_fnc_flattenLoadoutArray;
			private _index = [_unitInvtvData, _physicalLocker] call LIFE_fnc_index;

			if ((_lockerWeight + _cfgMass) > _cfgWeightLocker) exitWith {["Your locker has ran out of weight!", "red", "Error"] call PHX_fnc_notify};
			private _exit = false;
			for "_i" from 1 to _ctrlAmount do {
				if !([_unitInvtvData] call Martinez_fnc_removeItem) exitWith {_exit = true;};
			};
			if (_exit) exitWith {};

			if (_index isEqualTo -1) then {
				_physicalLocker pushBack [_unitInvtvData, _ctrlAmount];
			} else {
				(_physicalLocker select _index) params ["_classname", "_amount"];
				_amount = _amount + _ctrlAmount;
				_physicalLocker set [_index, [_classname, _amount]];
			};
		};

		['fillTreeLocker', [_display]] call Martinez_fnc_displayLocker;
		['fillTreeUnit', [_display]] call Martinez_fnc_displayLocker;

		["updatePhysicalProgressBar", [_display, Martinez_LockerData get "PhysicalWeight"]] call Martinez_fnc_displayLocker;
		["updateVirtualProgressBar", [_display, Martinez_LockerData get "VirtualWeight"]] call Martinez_fnc_displayLocker;
	};
};

