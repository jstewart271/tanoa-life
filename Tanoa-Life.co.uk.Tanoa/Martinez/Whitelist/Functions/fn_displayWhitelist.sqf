/*
	File: fn_displayWhitelist.sqf
	Function: Martinez_fnc_displayWhitelist
	Author: Martinezzz

	Copyright (c) 2023 Martinezzz, Martinezzz Development
	All Rights Reserved

	Params:
		0: STRING
			- Mode of the script
		
		1: ARRAY
			- _this of the script
*/

#define CfgBase missionConfigFile >> "CfgWhitelist" >> "Whitelists"

params [
	["_mode", "", [""]],
	"_this"
];

switch _mode do {
	case "onLoad": {
		private _display = _this select 0;
		private _ctrlInputSearch = _display displayCtrl 50;
		private _ctrlWhitelistBtn = _display displayCtrl 51;
		private _ctrlSearchBtn = _display displayCtrl 61;
		private _ctrlStructuredInfo = _display displayCtrl 52;
		private _ctrlLivePlayersCombo = _display displayCtrl 67;

		private _ctrlTypeCombo = _display displayCtrl 53;
		private _ctrlMainCombo = _display displayCtrl 54;
		private _ctrlSubOneCombo = _display displayCtrl 55;
		private _ctrlSubTwoCombo = _display displayCtrl 56;
		private _ctrlSubThreeCombo = _display displayCtrl 57;
		private _ctrlSubFourCombo = _display displayCtrl 58;
		private _ctrlSubFiveCombo = _display displayCtrl 59;
		private _ctrlSubSixCombo = _display displayCtrl 60;

		[_ctrlTypeCombo, _ctrlMainCombo, _ctrlSubOneCombo, _ctrlSubTwoCombo, _ctrlSubThreeCombo, _ctrlSubFourCombo, _ctrlSubFiveCombo, _ctrlSubSixCombo] apply {_x ctrlShow false};
		_ctrlWhitelistBtn ctrlEnable false;
		_ctrlInputSearch ctrlSetText "Please Input SteamID";
		_ctrlStructuredInfo ctrlSetStructuredText parseText format ["<t align='center'>Please Input SteamID Above to Show Data!</t>"];

		{
			_ctrlLivePlayersCombo lbAdd format ["%1", _x getVariable ["realname", name _x]];
			_ctrlLivePlayersCombo lbSetData [_forEachIndex, getPlayerUID _x];
		} forEach playableUnits;

		_ctrlSearchBtn ctrlAddEventHandler ["ButtonDown", {['onButtonDownSearch', _this] call Martinez_fnc_displayWhitelist}];
		_ctrlWhitelistBtn ctrlAddEventHandler ["ButtonDown", {['onButtonDownWhitelist', _this] spawn Martinez_fnc_displayWhitelist}];
		_ctrlTypeCombo ctrlAddEventHandler ["LBSelChanged", {['onLBListSelChangedType', _this] spawn Martinez_fnc_displayWhitelist}];

		_ctrlLivePlayersCombo ctrlAddEventHandler ["LBSelChanged", {['onLBSelChangedLive', _this] spawn Martinez_fnc_displayWhitelist}];

		WhitelistPanelHashData = createHashMap;
		WhitelistPanelLog = [];
		WhitelistSection = "";
		Martinez_ActiveWhitelistData = [];
	};

	case "onButtonDownSearch": {
		_this params ["_control"];

		private _display = ctrlParent _control;
		private _ctrlInputSearch = _display displayCtrl 50;
		private _text = ctrlText _ctrlInputSearch;

		["searchSteamID", [_text]] remoteExecCall ["MartinezSrv_fnc_whitelistServer",2];
	};

	case "searchReturn": {
		_this params ["_whitelistArray"];
		private _display = findDisplay 500002;
		private _ctrlStructuredInfo = _display displayCtrl 52;
		private _ctrlTypeCombo = _display displayCtrl 53;


		if (isNil "_whitelistArray") exitWith {
			_ctrlStructuredInfo ctrlSetStructuredText parseText format ["<t align='center'><br/>No Whitelist Data Shown!</t>"];
		};

		_whitelistArray params [
			"_adminLvl", "_copLvl", "_medicLvl", "_sarLvl", "_npasLvl", 
			"_tpuLvl", "_ctuLvl", "_cidLvl", "_acadlvl", "_mpuLvl", 
			"_donatorLvl", "_lastKnownName", "_havocLevel", "_hadLevel", 
			"_hsflevel", "_hmulevel", "_hsslevel"
		];
		
		Martinez_ActiveWhitelistData = createHashMapFromArray [
			["Staff", _adminLvl], ["Donator", _donatorLvl], ["Name", _lastKnownName],
			["NATO", _coplvl], ["AC", _npasLvl], ["SOFCOM", _ctulvl], ["WC", _mpuLvl], ["UC", _cidLvl],
			["TPLA", _havocLevel], ["AC", _hadLevel], ["HSF", _hsflevel], ["WC", _hmulevel], ["UC", _hsslevel],
			["NHS", _medicLvl], ["One", _sarLvl]
		];

		private _lbName = _ctrlTypeCombo lbText (lbCurSel _ctrlTypeCombo);
		private _whitelistSectionsText = call {
			if (_lbName isEqualTo "Police") exitWith { format ["<br/><br/>Police Rank: %1<br/>NPAS Tier %2<br/>NCA Tier %3<br/>CTU Tier: %4<br/>CID Rank: %5<br/>Academy Rank: %6<br/>", _copLvl, _npasLvl, _ncaLvl, _ctuLvl, _cidLvl, _acadlvl]; };
			if (_lbName isEqualTo "NHS") exitWith { format ["<br/><br/>NHS Rank: %1<br/>SAR Tier %2", _medicLvl, _sarLvl]; };
			if (_lbName isEqualTo "HAVOC") exitWith { format ["<br/><br/>HAVOC Rank: %1<br/>HAD Tier %2<br/>HSF Tier: %3<br/>HMU Tier: %4<br/>HSS Tier: %5", _havocLevel, _hadLevel, _hsflevel, _hmulevel, _hsslevel]; };
			"";
		};

		_ctrlStructuredInfo ctrlSetStructuredText parseText format ["<t align='center'><t size='1.4'><br/>Whitelist Information</t><br/><br/>Last Known Name: %3<br/>Administrator Lvl: %1<br/>Donator Lvl: %2 %4",
			_adminLvl, _donatorLvl, _lastKnownName, _whitelistSectionsText
		];

		lbClear _ctrlTypeCombo;
		{
			private _condition = getText(_x >> "whitelistLvlAccess");
			if (call compile _condition) then {
				_ctrlTypeCombo lbAdd configName _x;
			};
		} forEach ("true" configClasses (missionConfigFile >> "CfgWhitelist" >> "Whitelists"));
		_ctrlTypeCombo ctrlShow true;
	};

	case "onLBListSelChangedType": {
		_this params ["_control", "_selectedIndex"];

		private _display = ctrlParent _control;
		private _ctrlWhitelistBtn = _display displayCtrl 51;
		private _ctrlStructuredInfo = _display displayCtrl 52;

		private _ctrlMainCombo = _display displayCtrl 54;
		private _ctrlSubOneCombo = _display displayCtrl 55;
		private _ctrlSubTwoCombo = _display displayCtrl 56;
		private _ctrlSubThreeCombo = _display displayCtrl 57;
		private _ctrlSubFourCombo = _display displayCtrl 58;
		private _ctrlSubFiveCombo = _display displayCtrl 59;
		private _ctrlSubSixCombo = _display displayCtrl 60;

		[_ctrlMainCombo, _ctrlSubOneCombo, _ctrlSubTwoCombo, _ctrlSubThreeCombo, _ctrlSubFourCombo, _ctrlSubFiveCombo, _ctrlSubSixCombo] apply {_x ctrlRemoveAllEventHandlers "LBSelChanged"};

		private _lbName = _control lbText _selectedIndex;

		private _whitelistSectionsText = call {
			if (_lbName isEqualTo "Police") exitWith { format ["<br/><br/>Police Rank: %1<br/>NPAS Tier %2<br/>NCA Tier %3<br/>CTU Tier: %4<br/>CID Rank: %5<br/>Academy Rank: %6<br/>", Martinez_ActiveWhitelistData get "Police", Martinez_ActiveWhitelistData get "NPAS", Martinez_ActiveWhitelistData get "NCA", Martinez_ActiveWhitelistData get "CTU", Martinez_ActiveWhitelistData get "CID", Martinez_ActiveWhitelistData get "Academy"]; };
			if (_lbName isEqualTo "NHS") exitWith { format ["<br/><br/>NHS Rank: %1<br/>SAR Tier %2", Martinez_ActiveWhitelistData get "NHS", Martinez_ActiveWhitelistData get "SAR"]; };
			if (_lbName isEqualTo "HAVOC") exitWith { format ["<br/><br/>HAVOC Rank: %1<br/>HAD Tier %2<br/>HSOS Tier: %3<br/>HMU Tier: %4<br/>HSS Tier: %5", Martinez_ActiveWhitelistData get "HAVOC", Martinez_ActiveWhitelistData get "HAD", Martinez_ActiveWhitelistData get "HSOS", Martinez_ActiveWhitelistData get "HMU", Martinez_ActiveWhitelistData get "HSS"]; };
			"";
		};

		_ctrlStructuredInfo ctrlSetStructuredText parseText format ["<t align='center'><t size='1.4'><br/>Whitelist Information</t><br/><br/>Last Known Name: %3<br/>Administrator Lvl: %1<br/>Donator Lvl: %2 %4",
			Martinez_ActiveWhitelistData get "Staff", 
			Martinez_ActiveWhitelistData get "Donator", 
			Martinez_ActiveWhitelistData get "Name", 
			_whitelistSectionsText
		];

		private _cfgMain = CfgBase >> _lbName;
		private _cfgCondition = getArray(_cfgMain >> "whitelistLvlAccess");
		_cfgCondition params ["_conditionName", "_conditionLevel"];
		private _cfgRanks = getArray(_cfgMain >> "rankArr");
		private _cfgWhitelistIndex = getText(_cfgMain >> "databaseIndex");
		private _cfgCallCode = getText(_cfgMain >> "callCode");

		_ctrlMainCombo ctrlShow true;
		lbClear _ctrlMainCombo;
		{
			_index = _ctrlMainCombo lbAdd _x;
			_ctrlMainCombo lbSetData [_index, (str[(configName _cfgMain), _cfgWhitelistIndex])];
			_ctrlMainCombo lbSetValue [_index, _forEachIndex];

			_ctrlMainCombo lbSetCurSel (Martinez_ActiveWhitelistData get (configName _cfgMain));
		} forEach _cfgRanks;

		[_ctrlSubOneCombo, _ctrlSubTwoCombo, _ctrlSubThreeCombo, _ctrlSubFourCombo, _ctrlSubFiveCombo, _ctrlSubSixCombo] apply {_x ctrlShow false};
		private _cfgSubdivitions = ("true" configClasses (_cfgMain >> "SubDivitions"));
		for "_i" from 0 to (count(_cfgSubdivitions) -1) do {
			private _idc = (55 + _i);
			ctrlShow [_idc, true];
			((_display displayCtrl _idc) setVariable ["subDivision", configName(_cfgSubdivitions select _i)]);

			private _cfgSubWhitelistIndex = getText(_cfgMain >> "SubDivitions" >> (configName(_cfgSubdivitions select _i)) >> "databaseIndex");
			(lbClear (_display displayCtrl _idc));
			{
				_index = ((_display displayCtrl _idc) lbAdd format ["%1 %2", (configName(_cfgSubdivitions select _i)), _x]);
				((_display displayCtrl _idc) lbSetData [_index, str[(configName(_cfgSubdivitions select _i)), _cfgSubWhitelistIndex]]);
				((_display displayCtrl _idc) lbSetValue [_index, _forEachIndex]);

				((_display displayCtrl _idc) lbSetCurSel (Martinez_ActiveWhitelistData get (configName(_cfgSubdivitions select _i))));
			} forEach (getArray (_cfgMain >> "SubDivitions" >> (configName(_cfgSubdivitions select _i)) >> "rankArr"));
		};

		_ctrlMainCombo ctrlAddEventHandler     ["LBSelChanged", {['onLBSelChangedWhitelist', _this] call Martinez_fnc_displayWhitelist}];
		_ctrlSubOneCombo ctrlAddEventHandler   ["LBSelChanged", {['onLBSelChangedWhitelist', _this] call Martinez_fnc_displayWhitelist}];
		_ctrlSubTwoCombo ctrlAddEventHandler   ["LBSelChanged", {['onLBSelChangedWhitelist', _this] call Martinez_fnc_displayWhitelist}];
		_ctrlSubThreeCombo ctrlAddEventHandler ["LBSelChanged", {['onLBSelChangedWhitelist', _this] call Martinez_fnc_displayWhitelist}];
		_ctrlSubFourCombo ctrlAddEventHandler  ["LBSelChanged", {['onLBSelChangedWhitelist', _this] call Martinez_fnc_displayWhitelist}];
		_ctrlSubFiveCombo ctrlAddEventHandler  ["LBSelChanged", {['onLBSelChangedWhitelist', _this] call Martinez_fnc_displayWhitelist}];
		_ctrlSubSixCombo ctrlAddEventHandler   ["LBSelChanged", {['onLBSelChangedWhitelist', _this] call Martinez_fnc_displayWhitelist}];
	};

	case "onLBSelChangedWhitelist": {
		_this params ["_control", "_selectedIndex"];
		
		private _display = ctrlParent _control;
		private _lbData = parseSimpleArray (_control lbData _selectedIndex);
		_lbData params ["_whitelistTag", "_whitelistIndex"];
		private _lbValue = _control lbValue _selectedIndex;
		private _ctrlWhitelistBtn = _display displayCtrl 51;
		private _ctrlInputSearch = _display displayCtrl 50;
		private _text = ctrlText _ctrlInputSearch;

		if !(ctrlEnabled _ctrlWhitelistBtn) then {_ctrlWhitelistBtn ctrlEnable true;};

		WhitelistPanelHashData set [_whitelistIndex, _lbValue];
		WhitelistPanelLog pushBack (format ["Whitelisted %1 for %2 Level/Tier %3", _text, _whitelistTag, _lbValue]);

		['refreshListbox', [_display]] call Martinez_fnc_displayWhitelist;
	};

	case "onLBSelChangedLive": {
		_this params ["_control", "_selectedIndex"];
		
		private _display = ctrlParent _control;
		private _lbData = _control lbData _selectedIndex;
		private _ctrlInputSearch = _display displayCtrl 50;

		_ctrlInputSearch ctrlSetText _lbData;
		['onButtonDownSearch', [_control]] call Martinez_fnc_displayWhitelist;
	};

	case "onButtonDownWhitelist": {
		_this params ["_control"];

		private _display = ctrlParent _control;
		private _ctrlInputSearch = _display displayCtrl 50;
		private _text = ctrlText _ctrlInputSearch;
		private _ctrlSearchBtn = _display displayCtrl 61;
		private _ctrlTypeCombo = _display displayCtrl 53;
		if ((count WhitelistPanelHashData) isEqualTo 0) exitWith {};

		["updateWhitelists", [_text, WhitelistPanelHashData]] remoteExecCall ["MartinezSrv_fnc_whitelistServer", 2];
		uiSleep 0.3;
		['onButtonDownSearch', _ctrlSearchBtn] call Martinez_fnc_displayWhitelist;

		[format ["You have updated '%1' whitelist!", _text], 'green'] call PHX_fnc_notify;
		[player, format ["%1 (%2) has updated %3 (%4) whitelists, heres the log %5",profileName, (getPlayerUID player), (Martinez_ActiveWhitelistData get "Name"), _text, WhitelistPanelLog], "WhitelistLogs"] remoteExecCall (["fnc_sendHook", "PHXSRV"] call SOCK_fnc_getRemoteDestination);
	
		if ((_ctrlTypeCombo lbText (lbCurSel _ctrlTypeCombo)) isEqualTo "TPLA") then {
			[player, format ["%1 (%2) has updated %3 (%4) whitelists, heres the log %5",profileName, (getPlayerUID player), (Martinez_ActiveWhitelistData get "Name"), _text, WhitelistPanelLog], "APCWhitelistLogs"] remoteExecCall (["fnc_sendHook", "PHXSRV"] call SOCK_fnc_getRemoteDestination);
		};
	};

	case "refreshListbox": {
		_this params ["_display"];

		private _ctrlListbox = _display displayCtrl 68;
		lbClear _ctrlListbox;

		if (WhitelistPanelLog isEqualTo []) then {
			_ctrlListbox lbAdd "Nothing";
		} else {
			WhitelistPanelLog apply {_ctrlListbox lbAdd _x};
		};
	};
};
