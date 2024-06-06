/*
	@File: CfgAPC.hpp
	@Author: Jack "Scarso" Farhall & Lewis Mackinnon
	@Description: Configures the contents of all map inits.
*/

// General Stores
class apcGeneral {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Item Market", "life_fnc_virt_menu", "apc_market", "playerSide isEqualTo west || player getVariable ['isCID', false]", 5 },
		{ "<t color='#073763'>[NATO]</t> Command Market", "life_fnc_virt_menu", "apc_command_market", "playerSide isEqualTo west && call life_coplevel >= 11", 5 },
		{ "<t color='#073763'>[NATO]</t> Loadouts", "Martinez_fnc_openLoadouts", "", "playerSide isEqualTo west", 5 },	
		{ "<t color='#073763'>[NATO]</t> Clothing Store", "Martinez_fnc_openClothingStore", "apc_clothing", "playerSide isEqualTo west", 5 },
		{ "<t color='#073763'>[NATO]</t> Equipment Store", "life_fnc_weaponShopMenu", "apc_general_Store", "playerSide isEqualTo west", 5 },
		//{ "<t color='#073763'>[NATO]</t> SOFCOM Equipment Store", "life_fnc_weaponShopMenu", "ctu_general_Store", "playerSide isEqualTo west && call life_ctulevel >= 1", 5 },
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "", "playerSide isEqualTo west || player getVariable ['isCID', false]", 5 }
		//{ "<t color='#073763'>[NATO]</t> Get Patrol Mission", "PHX_fnc_getPatrol", "", "playerSide isEqualTo west && { !PHX_DoingMission }", 5 },
		//{ "<t color='#073763'>[NATO]</t> MPU Equipment Store", "life_fnc_weaponShopMenu", "mpu_general_Store", "playerSide isEqualTo west && call life_mpulevel >= 1", 5 },
	};
};
class cidGeneral {
	actions[] = {
		{ "<t color='#073763'>[CID]</t> Item Market", "life_fnc_virt_menu", "apc_market", "player getVariable ['isCID', false]", 5 },
		{ "<t color='#000000'>[CID]</t> Civilian Clothing Store", "Martinez_fnc_openClothingStore", "general_clothing", "player getVariable ['isCID', false]", 5 },
		{ "<t color='#000000'>[CID]</t> Civilian Diving Store", "Martinez_fnc_openClothingStore", "diving_store", "player getVariable ['isCID', false]", 5 },
		{ "<t color='#000000'>[CID]</t> Rebel Clothing Store", "Martinez_fnc_openClothingStore", "rebel_store", "player getVariable ['isCID', false]", 5 },
		{ "<t color='#000000'>[CID]</t> Equipment Store", "life_fnc_weaponShopMenu", "cid_general_store", "player getVariable ['isCID', false]", 5 },
		{ "<t color='#274e13'>[CID]</t> Loadouts", "Martinez_fnc_openLoadouts", "", "playerSide isEqualTo west", 5 },		
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "", "player getVariable ['isCID', false]", 5 }
	};
};
class NATOLocker {
    actions[] = {
        { "<t color='#073763'>[NATO]</t> Buy Locker", "Martinez_fnc_buyLocker", "", "playerSide isEqualTo west && {(isNil 'Martinez_LockerData')}", 5 },
        { "<t color='#073763'>[NATO]</t> Open Locker", "Martinez_fnc_openLocker", "", "playerSide isEqualTo west && {!(isNil 'Martinez_LockerData')}", 5 }
    };
};

class cidVeh {
	actions[] = {
		{ "<t color='#000000'>[CID]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"rebel_dealership","civilian",{"cid_car_spawn_1","cid_car_spawn_2"},"reb","Vehicle Store"}, "(player getVariable ['isCID', false])", 5 }
	};
};
class SOFCOMAirHQ {
actions[] = {
		{ "<t color='#073763'>[SOFCOM]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_air_store","west",{"SOFCOM_MULTI_1"},"cop","Vehicle Store"}, "playerSide isEqualTo west && call life_npaslevel >= 1", 5 },
		{ "<t color='#073763'>[SOFCOM]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_ground_store","west",{"SOFCOM_MULTI_1","apc_car_spawn_HQ_2"},"cop","Vehicle Store"}, "playerSide isEqualTo west", 5 }

	};
};

class apcLoadout {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Restore Default Loadout", "life_fnc_copLoadout", "", "playerSide isEqualTo west", 5 }
	};
};

// Vehicle Stores
class NATOCarHQ {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_ground_store","west",{"apc_car_spawn_HQ_1","apc_car_spawn_HQ_2"},"cop","Vehicle Store"}, "playerSide isEqualTo west", 5 }
	};
};

class NATOAirHQ {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_air_store","west",{"apc_air_spawn_HQ_1"},"cop","Vehicle Store"}, "playerSide isEqualTo west && call life_npaslevel >= 1", 5 }
	};
};

class NATOAirCarCommand {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_ground_store","west",{"apc_car_spawn_Air_1","apc_car_spawn_Air_2"},"cop","Vehicle Store"}, "playerSide isEqualTo west", 5 }
	};
};

class NATOAirCommad {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_air_store","west",{"apc_air_spawn_AIR_1"},"cop","Vehicle Store"}, "playerSide isEqualTo west && call life_npaslevel >= 1", 5 }
	};
};;

class apcCarKavala {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_ground_store","west",{"apc_car_spawn_kavala_1","apc_car_spawn_kavala_2"},"cop","Vehicle Store"}, "playerSide isEqualTo west", 5 }
	};
};
class apcCarAthira {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_ground_store","west",{"apc_car_spawn_athira_1","apc_car_spawn_athira_2"},"cop","Vehicle Store"}, "playerSide isEqualTo west", 5 }
	};
};
class apcCarAgios {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_ground_store","west",{"apc_car_spawn_agios_1","apc_car_spawn_agios_2"},"cop","Vehicle Store"}, "playerSide isEqualTo west", 5 }
	};
};
class apcCarSofia {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_ground_store","west",{"apc_car_spawn_sofia_1","apc_car_spawn_sofia_2"},"cop","Vehicle Store"}, "playerSide isEqualTo west", 5 }
	};
};
class apcCarSpec {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_ground_store","west",{"apc_car_spawn_spec_1","apc_car_spawn_spec_2","apc_car_spawn_spec_3"},"cop","Vehicle Store"}, "playerSide isEqualTo west", 5 }
	};
};
class apcCarMPU {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_ground_store","west",{"apc_car_spawn_MPU_1","apc_car_spawn_MPU_2"},"cop","Vehicle Store"}, "playerSide isEqualTo west", 5 }
	};
};
class apcCarNPAS {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_ground_store","west",{"apc_car_spawn_Air_1","apc_car_spawn_Air_2"},"cop","Vehicle Store"}, "playerSide isEqualTo west", 5 }
	};
};
class apcAirKavala {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_air_store","west",{"apc_air_spawn_kavala_1","apc_air_spawn_kavala_2"},"cop","Vehicle Store"}, "playerSide isEqualTo west && call life_npaslevel >= 1", 5 }
	};
};
class apcAirAthira {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_air_store","west",{"apc_air_spawn_athira_1"},"cop","Vehicle Store"}, "playerSide isEqualTo west && call life_npaslevel >= 1", 5 }
	};
};
class apcAirAgios {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_air_store","west",{"apc_air_spawn_agios_1"},"cop","Vehicle Store"}, "playerSide isEqualTo west && call life_npaslevel >= 1", 5 }
	};
};

class apcCarPrison {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_ground_store","west",{"apc_car_spawn_prison_1"},"cop","Vehicle Store"}, "playerSide isEqualTo west && call life_npaslevel >= 1", 5 }
	};
}

class apcAirPrison {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_air_store","west",{"apc_air_spawn_Prison_1"},"cop","Vehicle Store"}, "playerSide isEqualTo west && call life_npaslevel >= 1", 5 }
	};
}


class apcAirSofia {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_air_store","west",{"apc_air_spawn_sofia_1"},"cop","Vehicle Store"}, "playerSide isEqualTo west && call life_npaslevel >= 1", 5 }
	};
};
class apcAirSpec {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"apc_air_store","west",{"apc_air_spawn_spec_1"},"cop","Vehicle Store"}, "playerSide isEqualTo west && call life_npaslevel >= 1", 5 }
	};
};
class apcSeaKavala {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"cop_sea_store","west",{"apc_sea_spawn_kavala_1","apc_sea_spawn_kavala_2"},"cop","Vehicle Store"}, "playerSide isEqualTo west && call life_mpulevel >= 1", 5 }
	};
};
class apcSeaSpec {
	actions[] = {
		{ "<t color='#073763'>[NATO]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"cop_sea_store","west",{"apc_sea_spawn_spec_2"},"cop","Vehicle Store"}, "playerSide isEqualTo west && call life_mpulevel >= 1", 5 }
	};
};
