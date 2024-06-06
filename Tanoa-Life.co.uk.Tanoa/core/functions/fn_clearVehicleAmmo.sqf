#include "..\..\script_macros.hpp"
/*
	@File: fn_clearVehicleAmmo.sqf
	@Author: Bryan "Tonic" Boardwine
	@Description: Removes the vehicle ammo from defined types.
*/

params [["_vehicle", objNull, [objNull]]];

if (isNull _vehicle) exitWith {};
private _veh = typeOf _vehicle;

clearWeaponCargoGlobal _vehicle;
clearMagazineCargoGlobal _vehicle;
clearItemCargoGlobal _vehicle;

if (_veh isEqualTo "B_Boat_Armed_01_minigun_F") exitWith {
    _vehicle removeMagazinesTurret ["96Rnd_40mm_G_belt",[0]];
};

if (_veh isEqualTo "B_T_Boat_Armed_01_minigun_F") exitWith {
    _vehicle removeMagazinesTurret ["96Rnd_40mm_G_belt",[0]];
    _vehicle removeMagazinesTurret ["2000Rnd_65x39_belt_Tracer_Red",[1]];
};

if (_veh isEqualTo "B_APC_Wheeled_01_cannon_F") exitWith {
    _vehicle removeMagazinesTurret ["60Rnd_40mm_GPR_Tracer_Red_shells",[0]];
    _vehicle removeMagazinesTurret ["200Rnd_762x51_Belt_Red", [0]];
    _vehicle removeMagazinesTurret ["40Rnd_40mm_APFSDS_Tracer_Red_shells",[0]];
};

if (_veh isEqualTo "O_Heli_Attack_02_black_F") exitWith {
    _vehicle removeMagazinesTurret ["250Rnd_30mm_APDS_shells",[0]];
    _vehicle removemagazinesTurret ["250Rnd_30mm_APDS_shells_Tracer_Green", [0]];
    _vehicle removeMagazinesTurret ["250Rnd_30mm_HE_shells_Tracer_Green",[0]];
    _vehicle removeMagazinesTurret ["8Rnd_LG_scalpel",[0]];
    _vehicle removeMagazinesTurret ["38Rnd_80mm_rockets",[0]];
};

if (_veh isEqualTo "I_Plane_Fighter_03_AA_F") exitWith {
    _vehicle removeMagazinesTurret ["300Rnd_20mm_shells",[0]];
    _vehicle removeMagazinesTurret ["2Rnd_AAA_missiles",[0]];
    _vehicle removeMagazinesTurret ["4Rnd_GAA_missiles",[0]];
    _vehicle removeWeaponTurret ["Twin_Cannon_20mm",[-1]];
    _vehicle removeWeaponTurret ["missiles_Zephyr",[-1]];
    _vehicle removeWeaponTurret ["missiles_ASRAAM",[-1]];
    _vehicle setVehicleAmmo 0;
    _vehicle setVehicleAmmoDef 0;
};

if (_veh isEqualTo "O_Plane_CAS_02_F") exitWith {
    _vehicle removeMagazinesTurret ["500Rnd_Cannon_30mm_Plane_CAS_02_F",[0]];
    _vehicle removeMagazinesTurret ["2Rnd_Missile_AA_03_F",[0]];
    _vehicle removeMagazinesTurret ["4Rnd_Missile_AGM_01_F",[0]];
    _vehicle removeMagazinesTurret ["2Rnd_Bomb_03_F",[0]];
    _vehicle removeMagazinesTurret ["20Rnd_Rocket_03_HE_F",[0]];
    _vehicle removeMagazinesTurret ["20Rnd_Rocket_03_AP_F",[0]];
    _vehicle removeWeaponTurret ["Cannon_30mm_Plane_CAS_02_F",[-1]];
    _vehicle removeWeaponTurret ["Missile_AA_03_Plane_CAS_02_F",[-1]];
    _vehicle removeWeaponTurret ["Missile_AGM_01_Plane_CAS_02_F",[-1]];
    _vehicle removeWeaponTurret ["Rocket_03_HE_Plane_CAS_02_F",[-1]];
    _vehicle removeWeaponTurret ["Rocket_03_AP_Plane_CAS_02_F",[-1]];
    _vehicle removeWeaponTurret ["Bomb_03_Plane_CAS_02_F",[-1]];
    _vehicle setVehicleAmmo 0;
    _vehicle setVehicleAmmoDef 0;
};

if (_veh isEqualTo "I_Heli_light_03_F") exitWith {
    _vehicle removeMagazinesTurret ["24Rnd_missiles",[-1]];
};

if (_veh isEqualTo "O_Heli_Light_02_dynamicLoadout_F") exitWith {
    _vehicle removeMagazinesTurret ["PylonRack_12Rnd_PG_missiles",[-1]];
};

if(_veh isEqualTo "B_Heli_Attack_01_F") exitWith {
    _vehicle removeMagazinesTurret ["4Rnd_AAA_missiles",[0]];
    _vehicle removeMagazinesTurret ["24Rnd_PG_missiles",[0]];
    _vehicle removeMagazinesTurret ["1000Rnd_20mm_shells",[0]];
};

if (_veh isEqualTo "B_Plane_Fighter_01_F") exitWith {
    _vehicle removeMagazinesTurret ["magazine_Fighter01_Gun20mm_AA_x450",[0]];
    _vehicle setVehicleAmmo 0;
};

if (_veh isEqualTo "B_Plane_Fighter_01_Stealth_F") exitWith {
    _vehicle removeMagazinesTurret ["magazine_Fighter01_Gun20mm_AA_x450",[0]];
    _vehicle setVehicleAmmo 0;
};

if (_veh isEqualTo "I_Plane_Fighter_04_F") exitWith {
    _vehicle setVehicleAmmo 0;
    _vehicle setVehicleAmmoDef 0;
    _vehicle setAmmoCargo 0;
};

if (_veh isEqualTo "O_Plane_Fighter_02_F") exitWith {
    _vehicle removeMagazinesTurret ["magazine_Fighter02_Gun30mm_AA_x180",[0]];
    _vehicle setVehicleAmmo 0;
};

if (_veh isEqualTo "O_Plane_Fighter_02_Stealth_F") exitWith {
    _vehicle removeMagazinesTurret ["magazine_Fighter02_Gun30mm_AA_x180",[0]];
    _vehicle setVehicleAmmo 0;
};

if (_veh isEqualTo "B_Heli_Transport_03_F") exitWith {
    _vehicle removeMagazinesTurret ["2000Rnd_65x39_Belt_Tracer_Red",[0]];
    _vehicle setVehicleAmmo 0;
};

if (_veh isEqualTo "I_APC_Wheeled_03_cannon_F" || _veh isEqualTo "B_APC_Wheeled_03_cannon_F") exitWith {
    _vehicle removeMagazinesTurret ["140Rnd_30mm_MP_shells_Tracer_Yellow",[0]];
    _vehicle removeMagazinesTurret ["60Rnd_30mm_APFSDS_shells_Tracer_Yellow",[0]];
    _vehicle removeMagazinesTurret ["1000Rnd_65x39_Belt_Yellow",[0]];
    _vehicle removeMagazinesTurret ["2Rnd_GAT_missiles",[0]];
    _vehicle removeMagazinesTurret ["200Rnd_762x51_Belt_Yellow",[0]];
};

if (_veh isEqualTo "B_Plane_CAS_01_F") exitWith {
    _vehicle removeMagazinesTurret ["Gatling_30mm_Plane_CAS_01_F",[0]];
    _vehicle removeMagazinesTurret ["Missile_AA_04_Plane_CAS_01_F",[0]];
    _vehicle removeMagazinesTurret ["Missile_AGM_02_Plane_CAS_01_F",[0]];
    _vehicle removeMagazinesTurret ["Rocket_04_HE_Plane_CAS_01_F",[0]];
    _vehicle removeMagazinesTurret ["Rocket_04_AP_Plane_CAS_01_F",[0]];
    _vehicle removeMagazinesTurret ["Bomb_04_Plane_CAS_01_F",[0]];
    _vehicle setVehicleAmmo 0;
    _vehicle animate ["HideTurret",1];
};

if (_veh isEqualTo "O_T_VTOL_02_infantry_grey_F" || _veh isEqualTo "O_T_VTOL_02_vehicle_hex_F" || _veh isEqualTo "O_T_VTOL_02_vehicle_grey_F") exitWith {
    _vehicle removeMagazinesTurret ["250Rnd_30mm_HE_shells_Tracer_Green",[0]];
    _vehicle removeMagazinesTurret ["250Rnd_30mm_APDS_shells_Tracer_Green",[0]];
    _vehicle removeMagazinesTurret ["8Rnd_LG_scalpel",[0]];
    _vehicle removeMagazinesTurret ["38Rnd_80mm_rockets",[0]];
    _vehicle setVehicleAmmo 0;
};

if (_veh isEqualTo "I_LT_01_cannon_F") exitWith {
    _vehicle animate ["showBags", 1];
    _vehicle animate ["showBags2", 1];
    _vehicle animate ["HideTurret",1];
    _vehicle animate ["showCAmonetPlates1",1];
    _vehicle animate ["showCAmonetPlates2",1];
    _vehicle animate ["showCAmonetHULL",0];
    _vehicle setVehicleAmmo 0;
    _vehicle setVehicleAmmoDef 0;
    _vehicle setAmmoCargo 0;
};

if (_veh isEqualTo "B_Heli_Transport_01_camo_F") exitWith {
    _vehicle setVehicleAmmo 0;
    _vehicle setVehicleAmmoDef 0;
    _vehicle setAmmoCargo 0;
    _vehicle removeMagazinesTurret ["2000Rnd_65x39_Belt_Tracer_Red",[0]];
};

if (_veh isEqualTo "B_AFV_Wheeled_01_cannon_F") exitWith {
    _vehicle removeMagazinesTurret ["12Rnd_120mm_APFSDS_shells_Tracer_Red",[0]];
    _vehicle removeMagazinesTurret ["8Rnd_120mm_HE_shells_Tracer_Red",[0]];
    _vehicle removeMagazinesTurret ["8Rnd_120mm_HEAT_MP_T_Red",[0]];
    _vehicle removeMagazinesTurret ["200Rnd_338_Mag",[0]];
    _vehicle removeMagazinesTurret ["4Rnd_120mm_LG_cannon_missiles",[0]];
};

if (_veh isEqualTo "I_Plane_Fighter_03_dynamicLoadout_F") exitWith {
    _vehicle setVehicleAmmo 0;
    _vehicle setVehicleAmmoDef 0;
    _vehicle setAmmoCargo 0;
};

if (_veh in ["O_T_VTOL_02_infantry_F","O_T_VTOL_02_vehicle_F","O_T_VTOL_02_vehicle_grey_F"]) exitWith {
    _vehicle setVehicleAmmo 0;
    _vehicle setVehicleAmmoDef 0;
    _vehicle setAmmoCargo 0;
    _vehicle removeMagazinesTurret ["250Rnd_30mm_HE_shells_Tracer_Green",[0]];
    _vehicle removeMagazinesTurret ["250Rnd_30mm_APDS_shells_Tracer_Green",[0]];
    _vehicle removeMagazinesTurret ["8Rnd_LG_scalpel",[0]];
    _vehicle removeMagazinesTurret ["38Rnd_80mm_rockets",[0]];
};

if (_veh isEqualTo "I_Plane_Fighter_03_CAS_F") exitWith {
    _vehicle setVehicleAmmo 0;
    _vehicle setVehicleAmmoDef 0;
    _vehicle setAmmoCargo 0;
};