/*
    File: fn_numberText.sqf
    Author: Karel Moricky

    Description:
    Convert a number into string (avoiding scientific notation)

    Parameter(s):
    _this: NUMBER

    Returns:
    STRING
*/
params [["_number", 0, [0]], ["_mod", 3, [0]]];

private _digits = _number call BIS_fnc_numberDigits;
private _digitsCount = count _digits - 1;

private _modBase = _digitsCount % _mod;
private _numberText = "";

{
    _numberText = _numberText + str _x;
    if ((_forEachIndex - _modBase) % _mod isEqualTo 0 && !(_forEachIndex isEqualTo _digitsCount)) then {_numberText = _numberText + ",";};
} forEach _digits;

_numberText