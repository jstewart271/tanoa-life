#include "..\..\..\script_macros.hpp"
/*
    File: fn_initCiv.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Initializes the civilian.
*/
private _altisArray = ["Land_i_Shop_01_V1_F","Land_i_Shop_01_V2_F","Land_i_Shop_01_V3_F","Land_i_Shop_02_V1_F","Land_i_Shop_02_V2_F","Land_i_Shop_02_V3_F"];
private _tanoaArray = ["Land_House_Small_01_F","Land_Shop_City_01_F","Land_Shop_City_02_F","Land_House_Big_04_F","Land_Warehouse_03_F","Land_Hotel_01_F","Land_Hotel_02_F"];
private _spawnBuildings = _tanoaArray;

civ_spawn_1 = nearestObjects[getMarkerPos  "civ_spawn_1", _spawnBuildings,550];
civ_spawn_2 = nearestObjects[getMarkerPos  "civ_spawn_2", _spawnBuildings,350];
civ_spawn_3 = nearestObjects[getMarkerPos  "civ_spawn_3", _spawnBuildings,350];
civ_spawn_4 = nearestObjects[getMarkerPos  "civ_spawn_4", _spawnBuildings,350];

PHX_DEFAULT_GEAR = "civ_gear";