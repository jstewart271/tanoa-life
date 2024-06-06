#include "..\..\script_macros.hpp"
/*
    File: fn_vehicleShopLBChange.sqf
    Author: Bryan "Tonic" Boardwine
    Modified : NiiRoZz

    Description:
    Called when a new selection is made in the list box and
    displays various bits of information about the vehicle.
*/
disableSerialization;
private ["_className","_classNameLife","_initalPrice","_buyMultiplier","_rentMultiplier","_vehicleInfo","_colorArray","_ctrl","_trunkSpace","_maxspeed","_horsepower","_passengerseats","_fuel","_armor"];

//Fetch some information.
_className = (_this select 0) lbData (_this select 1);
_classNameLife = _className;
_vIndex = (_this select 0) lbValue (_this select 1);

_initalPrice = M_CONFIG(getNumber,"LifeCfgVehicles",_classNameLife,"price");
if (HAS_PERK("haggler")) then { _initalPrice  = _initalPrice  * 0.9 };

_buyMultiplier = 1;
_rentMultiplier = LIFE_SETTINGS(getNumber,"vehicle_rental_multiplier");

_vehicleInfo = [_className] call life_fnc_fetchVehInfo;
_trunkSpace = [_className] call life_fnc_vehicleWeightCfg;
_maxspeed = (_vehicleInfo select 8);
_horsepower = (_vehicleInfo select 11);
_passengerseats = (_vehicleInfo select 10);
_fuel = (_vehicleInfo select 12);
_armor = (_vehicleInfo select 9);
[_className] call life_fnc_3dPreviewDisplay;

_rPrice = format["£%1", [round(_initalPrice * _rentMultiplier)] call life_fnc_numberText];
_bPrice = format["£%1", [round(_initalPrice * _buyMultiplier)] call life_fnc_numberText];

if (playerSide in [west, east] || { isCID(player) || isHSS(player) || player getVariable ['Faction_Medic', false]}) then {
    _bPrice = "<t color='#8cff9b'>£0</t>";
    _rPrice = "<t color='#8cff9b'>£0</t>";
};

ctrlShow [2330,true];
(CONTROL(2300,2303)) ctrlSetStructuredText parseText format [
    "<t font='RobotoCondensedLight' size='0.8'>Rental Price:<t align='right'>%1</t><br/></t>" +
    "<t font='RobotoCondensedLight' size='0.8'>Ownership Price:<t align='right'>%2</t><br/></t>" +
    "<t font='RobotoCondensedLight' size='0.8'>Max Speed:<t align='right'>%3 km/h</t><br/></t>" +
    "<t font='RobotoCondensedLight' size='0.8'>Horse Power:<t align='right'>%4</t><br/></t>" +
    "<t font='RobotoCondensedLight' size='0.8'>Passenger Seats:<t align='right'>%5</t><br/></t>" +
    "<t font='RobotoCondensedLight' size='0.8'>Trunk Capacity:<t align='right'>%6<br/></t>" +
    "<t font='RobotoCondensedLight' size='0.8'>Fuel Capacity:<t align='right'>%7</t><br/></t>" +
    "<t font='RobotoCondensedLight' size='0.8'>Armour Rating:<t align='right'>%8</t></t>",
    _rPrice,
    _bPrice,
    _maxspeed,
    _horsepower,
    _passengerseats,
    if (_trunkSpace isEqualTo -1) then {"None"} else {_trunkSpace},
    _fuel,
    _armor
];

_ctrl = CONTROL(2300,2304);
lbClear _ctrl;

if (!isClass (missionConfigFile >> "LifeCfgVehicles" >> _classNameLife)) then {
    _classNameLife = "Default"; //Use Default class if it doesn't exist
    diag_log format ["%1: LifeCfgVehicles class doesn't exist",_className];
};
_colorArray = M_CONFIG(getArray,"LifeCfgVehicles",_classNameLife,"textures");

{
    _flag = (_x select 1);
    _textureName = (_x select 0);
    if ((life_veh_shop select 2) isEqualTo _flag) then {
        _x params ["_texture"];
        private _toShow = [_x] call life_fnc_levelCheck;
        if (_toShow) then {
            _ctrl lbAdd _textureName;
            _ctrl lbSetValue [(lbSize _ctrl)-1,_forEachIndex];
        };
    };
} forEach _colorArray;

_numberindexcolorarray = [];
for "_i" from 0 to (count(_colorArray) - 1) do {
    _numberindexcolorarray pushBack _i;
};
_indexrandom = _numberindexcolorarray call BIS_fnc_selectRandom;
_ctrl lbSetCurSel _indexrandom;

if (_className in (LIFE_SETTINGS(getArray,"vehicleShop_rentalOnly"))) then {
    ctrlEnable [2309,false];
} else {
    if (!(life_veh_shop select 3)) then {
        ctrlEnable [2309,true];
    };
};

if !((lbSize _ctrl)-1 isEqualTo -1) then {
    ctrlShow[2304,true];
} else {
    ctrlShow[2304,false];
};

if !(playerSide isEqualTo civilian) then {
    ctrlEnable[2309,false]
};

true;
