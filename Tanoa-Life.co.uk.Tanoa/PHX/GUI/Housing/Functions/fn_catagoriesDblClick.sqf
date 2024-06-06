/*
	File: fn_catagoriesDblClick.sqf
	Function: PHX_fnc_catagoriesDblClick
	Author: Martinezzz

	Copyright (c) 2023 Martinezzz, Martinezzz Development
	All Rights Reserved
*/

params ["_mode", "_this"];

switch _mode do {
    case "Inventory": {
        _this params ["_control", "_button", "_xPos", "_yPos", "_shift", "_ctrl", "_alt"];
        private _display = ctrlParent _control;
        private _ctrlInvEdit = _display displayCtrl 11011;
        private _ctrlAmount = _control lbValue (lbCurSel _control);
        private _text = format ["%1", _ctrlAmount];
        _ctrlInvEdit ctrlSetText _text;
    };

    case "House": {
        _this params ["_control", "_button", "_xPos", "_yPos", "_shift", "_ctrl", "_alt"];
        private _display = ctrlParent _control;
        private _ctrlHouseEdit = _display displayCtrl 11010;
        private _ctrlAmount = _control lbValue (lbCurSel _control);
        private _text = format ["%1", _ctrlAmount];
        _ctrlHouseEdit ctrlSetText _text;
    };
};