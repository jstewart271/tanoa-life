/*
	@File: CfgHAV.hpp
	@Author: Jack "Scarso" Farhall & Lewis Mackinnon
	@Description: Configures the contents of all map inits.
*/

// General Stores
class havocGeneral {
	actions[] = { 
		{ "<t color='#274e13'>[TPLA]</t> Item Market", "life_fnc_virt_menu", "hav_market", "playerSide isEqualTo east", 5 },
		{ "<t color='#274e13'>[TPLA]</t> Command Market", "life_fnc_virt_menu", "havoc_command_market", "playerSide isEqualTo east && call life_havoclevel >= 11", 5 },
		{ "<t color='#274e13'>[TPLA]</t> Loadouts", "Martinez_fnc_openLoadouts", "", "playerSide isEqualTo east", 5 },	
		{ "<t color='#274e13'>[TPLA]</t> Clothing Store", "Martinez_fnc_openClothingStore", "havoc_clothing", "playerSide isEqualTo east", 5 },
		{ "<t color='#274e13'>[TPLA]</t> Equipment Store", "life_fnc_weaponShopMenu", "havoc_general_store", "playerSide isEqualTo east", 5 },
		//{ "<t color='#274e13'>[TPLA]</t> Get Patrol Mission", "PHX_fnc_getPatrol", "", "playerSide isEqualTo east && { !PHX_DoingMission }", 5 },
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "", "playerSide isEqualTo east", 5 }
	};
};
class havocHSS {
	actions[] = {
		{ "<t color='#000000'>[SSP]</t> License Store", "PHX_fnc_openLicenses", {"rebel","PMC"}, "player getVariable ['isHSS', false]", 5 },
		{ "<t color='#000000'>[SSP]</t> Rebel Market", "life_fnc_virt_menu", "rebel_market", "player getVariable ['isHSS', false]", 5 },
		{ "<t color='#000000'>[SSP]</t> Rebel Clothing", "Martinez_fnc_openClothingStore", "rebel_store", "player getVariable ['isHSS', false]", 5 },
		{ "<t color='#000000'>[SSP]</t> Basic Rebel Equipment", "life_fnc_weaponShopMenu", "basic_rebel", "player getVariable ['isHSS', false]", 5 },
		{ "<t color='#000000'>[SSP]</t> Advanced Rebel Equipment", "life_fnc_weaponShopMenu", "advanced_rebel", "player getVariable ['isHSS', false]", 5 },
		{ "<t color='#000000'>[SSP]</t> Loadouts", "Martinez_fnc_openLoadouts", "", "player getVariable ['isHSS', false]", 5 },
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "", "player getVariable ['isHSS', false]", 5 }
	};
};

class tplaLocker {
    actions[] = {
        { "<t color='#274e13'>[TPLA]</t> Buy Locker", "Martinez_fnc_buyLocker", "", "playerSide isEqualTo east && {(isNil 'Martinez_LockerData')}", 5 },
        { "<t color='#274e13'>[TPLA]</t> Open Locker", "Martinez_fnc_openLocker", "", "playerSide isEqualTo east && {!(isNil 'Martinez_LockerData')}", 5 }
    };
};
class havocHSSveh {
	actions[] = {
		{ "<t color='#000000'>[SSP]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"rebel_dealership","civilian",{"hss_car_spawn"},"reb","Vehicle Store"}, "(player getVariable ['isHSS', false])", 5 }
	};
};

// Vehicle Stores
class havocCarsKatkoula {
	actions[] = {
		{ "<t color='#274e13'>[TPLA]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"havoc_ground_store","east",{"TPLA_car_Spawn_Katkoula_1","TPLA_car_Spawn_Katkoula_2"},"havoc","Vehicle Store"}, "playerSide isEqualTo east", 5 }
	};
};

class havocLijnhaven {
	actions[] = {
		{ "<t color='#274e13'>[TPLA]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"havoc_ground_store","east",{"havoc_car_spawn_lijnhaven_1","havoc_car_spawn_lijnhaven_2"},"havoc","Vehicle Store"}, "playerSide isEqualTo east", 5 }
	};
};

class havocCarsGulag {
	actions[] = {
		{ "<t color='#274e13'>[TPLA]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"havoc_ground_store","east",{"TPLA_car_Spawn_Gulag"},"havoc","Vehicle Store"}, "playerSide isEqualTo east", 5 }
	};
};

class havocLijnhavenSea {
	actions[] = {
		{ "<t color='#274e13'>[TPLA]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"havoc_sea_store","east",{"havoc_Lijnhaven_sea_spawn_1"},"havoc","Vehicle Store"}, "playerSide isEqualTo east && call life_hmulevel >= 1", 5 }
	};
};

class havocHQSea {
	actions[] = {
		{ "<t color='#274e13'>[TPLA]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"havoc_sea_store","east",{"havoc_HQ_sea_spawn_1"},"havoc","Vehicle Store"}, "playerSide isEqualTo east && call life_hmulevel >= 1", 5 }
	};
};

class havocCarAir {
	actions[] = {
		{ "<t color='#274e13'>[TPLA]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"havoc_ground_store","east",{"havoc_car_spawn_Air_1","havoc_car_spawn_Air_2"},"havoc","Vehicle Store"}, "playerSide isEqualTo east", 5 }
	};
};


class havocAirKatkoula {
	actions[] = {
		{ "<t color='#274e13'>[TPLA]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"havoc_air_store","east",{"TPLA_air_Spawn_Katkoula_1","TPLA_air_Spawn_Katkoula_2"},"havoc","Vehicle Store"}, "playerSide isEqualTo east && call life_hadlevel >= 1", 5 }
	};
};
class havocAirUnits {
	actions[] = {
		{ "<t color='#274e13'>[TPLA]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"havoc_air_store","east",{"TPLA_air_Spawn_1","TPLA_air_Spawn_2"},"havoc","Vehicle Store"}, "playerSide isEqualTo east && call life_hadlevel >= 1", 5 }
	};
};
class havocAirCheckpoint {
	actions[] = {
		{ "<t color='#274e13'>[TPLA]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"havoc_air_store","east",{"havoc_cp_air_spawn_1"},"havoc","Vehicle Store"}, "playerSide isEqualTo east && call life_hadlevel >= 1", 5 }
	};
};
class havocSeaPyrgos {
	actions[] = {
		{ "<t color='#274e13'>[TPLA]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"havoc_sea_store","east",{"havoc_cp_sea_spawn_1","havoc_cp_sea_spawn_2"},"havoc","Vehicle Store"}, "playerSide isEqualTo east && call life_hmulevel >= 1", 5 }
	};
};