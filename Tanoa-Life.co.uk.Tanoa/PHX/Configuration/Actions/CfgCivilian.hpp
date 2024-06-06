/*
	@File: CfgCivilian.hpp
	@Author: Jack "Scarso" Farhall & Lewis Mackinnon
	@Description: Configures the contents of all map inits. crafting
*/
class cashpoint {
	actions[] = {
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "", "", 5 }
	};
};

class waterCooler {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Fill Cup", "life_fnc_waterCooler", "", "", 5 }
	};
};

class fridgeFood {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Get food", "life_fnc_fridgeFood", "", "", 5 }
	};
};

class crafting {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Crafting", "PHX_fnc_openCrafting", "", "!life_action_inUse", 5 }
	};
};

// General Stores
class generalStore {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> General Store", "life_fnc_weaponShopMenu", "general_store", "", 5 },
		{ "<t color='#ffe599'>[ALL]</t> General Market", "life_fnc_virt_menu", "general_market", "", 5 }
	};
};
class fuelStationStore {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV/TPLA]</t> Rob Fuel Station", "PHX_fnc_robStore", {"fuelStationWestOnly", "west"}, "(playerSide isEqualTo civilian || playerSide isEqualTo east) && { isNil {_this getVariable ""robbed""} }", 5 },
		{ "<t color='#ffe599'>[ALL]</t> Fuel Station Store", "life_fnc_weaponShopMenu", "fuel_station_Store", "", 5 },
		{ "<t color='#ffe599'>[ALL]</t> Fuel Station Market", "life_fnc_virt_menu", "fuel_station_market", "", 5 }
	};
};
class fuelStationStoreHAVOC {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Rob Fuel Station", "PHX_fnc_robStore", {"fuelStation", "east"}, "playerSide isEqualTo civilian && { isNil {_this getVariable ""robbed""} }", 5 },
		{ "<t color='#ffe599'>[ALL]</t> Fuel Station Store", "life_fnc_weaponShopMenu", "fuel_station_Store", "", 5 },
		{ "<t color='#ffe599'>[ALL]</t> Fuel Station Market", "life_fnc_virt_menu", "fuel_station_market", "", 5 }
	};
};
class cashHouse {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Rob Cash House", "PHX_fnc_robStore", {"cashHouse", "east"}, "playerSide isEqualTo civilian && { isNil {_this getVariable ""robbed""} }", 5 }
	};
};
class localBank {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Rob Local Bank", "PHX_fnc_robStore", {"localBank", "west"}, "(playerSide isEqualTo civilian || playerSide isEqualTo east) && { isNil {_this getVariable ""robbed""} }", 5 }
	};
};
class localTPLABank {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Rob Local Bank", "PHX_fnc_robStore", {"localTPLABank", "east"}, "playerSide isEqualTo civilian && { isNil {_this getVariable ""robbed""} }", 5 }
	};
}
class divingStore {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> License Store", "PHX_fnc_openLicenses", {"dive"}, "playerSide isEqualTo civilian && { !license_civ_dive }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Clothing Store", "Martinez_fnc_openClothingStore", "diving_store", "(playerSide isEqualTo civilian && license_civ_dive) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 }
	};
};
class goKartingStore {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> License Store", "PHX_fnc_openLicenses", {"karting"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Clothing Store", "Martinez_fnc_openClothingStore", "gokart_store", "(playerSide isEqualTo civilian && license_civ_karting) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Item Store", "life_fnc_weaponShopMenu", "go_karting_store", "(playerSide isEqualTo civilian && license_civ_karting) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"karting_dealership","civilian",{"civ_kart_1","civ_kart_2"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_karting) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 }
	};
};
class handgunStore {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> License Store", "PHX_fnc_openLicenses", {"gun"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Handgun Store", "life_fnc_weaponShopMenu", "handgun_store", "(playerSide isEqualTo civilian && license_civ_gun) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Clothing Store", "Martinez_fnc_openClothingStore", "handgun_clothing_store", "(playerSide isEqualTo civilian && license_civ_gun) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 }
	};
};
class smgStore {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> License Store", "PHX_fnc_openLicenses", {"SMG"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> SMG Store", "life_fnc_weaponShopMenu", "smg_store", "(playerSide isEqualTo civilian && license_civ_SMG) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 }
	};
};
class basicRebelStore {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> License Store", "PHX_fnc_openLicenses", {"rebel"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Rebel Market", "life_fnc_virt_menu", "rebel_market", "(playerSide isEqualTo civilian && license_civ_rebel) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Rebel Clothing", "Martinez_fnc_openClothingStore", "rebel_store", "(playerSide isEqualTo civilian && license_civ_rebel) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Basic Rebel Equipment", "life_fnc_weaponShopMenu", "basic_rebel", "(playerSide isEqualTo civilian && license_civ_rebel) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Loadouts", "Martinez_fnc_openLoadouts", "", "(playerSide isEqualTo civilian && license_civ_rebel) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5},
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "", "playerSide isEqualTo civilian", 5 }
	};
};
class advancedRebelStore {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> License Store", "PHX_fnc_openLicenses", {"rebel","PMC"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Rebel Market", "life_fnc_virt_menu", "rebel_market", "playerSide isEqualTo civilian && ((license_civ_rebel || license_civ_PMC)) || { (player getVariable ['isCID', false]) || {player getVariable ['isHSS', false]}}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Rebel Clothing", "Martinez_fnc_openClothingStore", "rebel_store", "(playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Basic Rebel Equipment", "life_fnc_weaponShopMenu", "basic_rebel", "(playerSide isEqualTo civilian && license_civ_rebel) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Advanced Rebel Equipment", "life_fnc_weaponShopMenu", "advanced_rebel", "(playerSide isEqualTo civilian && license_civ_PMC) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Loadouts", "Martinez_fnc_openLoadouts", "", "(playerSide isEqualTo civilian && license_civ_rebel) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5},
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "", "playerSide isEqualTo civilian", 5 }
	};
};

class captureHideout {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> License Store", "PHX_fnc_openLicenses", {"rebel","PMC"}, "playerSide isEqualTo civilian && ['hideout_flag'] call PHX_fnc_ownsObject", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Rebel Market", "life_fnc_virt_menu", "rebel_market", "playerSide isEqualTo civilian && ((license_civ_rebel || license_civ_PMC)) && ['hideout_flag'] call PHX_fnc_ownsObject", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Rebel Clothing", "Martinez_fnc_openClothingStore", "rebel_store", "(playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)) && ['hideout_flag'] call PHX_fnc_ownsObject", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Basic Rebel Equipment", "life_fnc_weaponShopMenu", "basic_rebel", "(playerSide isEqualTo civilian && license_civ_rebel) && ['hideout_flag'] call PHX_fnc_ownsObject", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Advanced Rebel Equipment", "life_fnc_weaponShopMenu", "advanced_rebel", "(playerSide isEqualTo civilian && license_civ_PMC) && ['hideout_flag'] call PHX_fnc_ownsObject", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Loadouts", "Martinez_fnc_openLoadouts", "", "(playerSide isEqualTo civilian && license_civ_rebel) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5},
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "", "playerSide isEqualTo civilian && ['hideout_flag'] call PHX_fnc_ownsObject", 5 }
	};
};
class captureHideout2 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> License Store", "PHX_fnc_openLicenses", {"rebel","PMC"}, "playerSide isEqualTo civilian && ['hideout_flag_2'] call PHX_fnc_ownsObject", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Rebel Market", "life_fnc_virt_menu", "rebel_market", "playerSide isEqualTo civilian && ((license_civ_rebel || license_civ_PMC)) && ['hideout_flag_2'] call PHX_fnc_ownsObject", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Rebel Clothing", "Martinez_fnc_openClothingStore", "rebel_store", "(playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)) && ['hideout_flag_2'] call PHX_fnc_ownsObject", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Basic Rebel Equipment", "life_fnc_weaponShopMenu", "basic_rebel", "(playerSide isEqualTo civilian && license_civ_rebel) && ['hideout_flag_2'] call PHX_fnc_ownsObject", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Advanced Rebel Equipment", "life_fnc_weaponShopMenu", "advanced_rebel", "(playerSide isEqualTo civilian && license_civ_PMC) && ['hideout_flag_2'] call PHX_fnc_ownsObject", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Loadouts", "Martinez_fnc_openLoadouts", "", "(playerSide isEqualTo civilian && license_civ_rebel) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5},
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "", "playerSide isEqualTo civilian && ['hideout_flag_2'] call PHX_fnc_ownsObject", 5 }
	};
};
class northEastBase {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Rebel Market", "life_fnc_virt_menu", "rebel_market", "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['NE'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Rebel Clothing", "Martinez_fnc_openClothingStore", "rebel_store", "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['NE'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Basic Rebel Equipment", "life_fnc_weaponShopMenu", "basic_rebel", "playerSide isEqualTo civilian && license_civ_rebel && { ['NE'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Advanced Rebel Equipment", "life_fnc_weaponShopMenu", "advanced_rebel", "playerSide isEqualTo civilian && license_civ_PMC && { ['NE'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Loadouts", "Martinez_fnc_openLoadouts", "", "(playerSide isEqualTo civilian && license_civ_rebel) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5},
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "{ ['NE'] call PHX_fnc_ownsBase }", "playerSide isEqualTo civilian", 5 }
	};
};
class northWestBase {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Rebel Market", "life_fnc_virt_menu", "rebel_market", "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['NW'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Rebel Clothing", "Martinez_fnc_openClothingStore", "rebel_store", "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['NW'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Basic Rebel Equipment", "life_fnc_weaponShopMenu", "basic_rebel", "playerSide isEqualTo civilian && license_civ_rebel && { ['NW'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Advanced Rebel Equipment", "life_fnc_weaponShopMenu", "advanced_rebel", "playerSide isEqualTo civilian && license_civ_PMC && { ['NW'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Loadouts", "Martinez_fnc_openLoadouts", "", "(playerSide isEqualTo civilian && license_civ_rebel) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5},
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "{ ['NW'] call PHX_fnc_ownsBase }", "playerSide isEqualTo civilian", 5 }
	};
};
class southWestBase {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Rebel Market", "life_fnc_virt_menu", "rebel_market", "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['SW'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Rebel Clothing", "Martinez_fnc_openClothingStore", "rebel_store", "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['SW'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Basic Rebel Equipment", "life_fnc_weaponShopMenu", "basic_rebel", "playerSide isEqualTo civilian && license_civ_rebel && { ['SW'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Advanced Rebel Equipment", "life_fnc_weaponShopMenu", "advanced_rebel", "playerSide isEqualTo civilian && license_civ_PMC && { ['SW'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Loadouts", "Martinez_fnc_openLoadouts", "", "(playerSide isEqualTo civilian && license_civ_rebel) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5},
        { "<t color='#ADFF2F'>[EvolvE]</t> Cashpoint", "PHX_fnc_atmMenu", "", "playerSide isEqualTo civilian && ['EvolvE', player] call PHX_fnc_inWhitelistGang", 5 }
	};
};
class evolveStore {
    actions[] = {
        { "<t color='#ff66ff'>[EvolvE]</t> Rebel Market", "life_fnc_virt_menu", "rebel_market", "playerSide isEqualTo civilian && ((license_civ_rebel || license_civ_PMC)) && ['EvolvE', player] call PHX_fnc_inWhitelistGang", 5 },
        { "<t color='#ff66ff'>[EvolvE]</t> Rebel Clothing", "Martinez_fnc_openClothingStore", "rebel_store", "(playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)) && ['EvolvE', player] call PHX_fnc_inWhitelistGang", 5 },
        { "<t color='#ff66ff'>[EvolvE]</t> Basic Rebel Equipment", "life_fnc_weaponShopMenu", "basic_rebel", "(playerSide isEqualTo civilian && license_civ_rebel) && ['EvolvE', player] call PHX_fnc_inWhitelistGang", 5 },
		{ "<t color='#ff66ff'>[EvolvE]</t> Loadouts", "Martinez_fnc_openLoadouts", "", "(playerSide isEqualTo civilian && license_civ_rebel) && ['EvolvE', player] call PHX_fnc_inWhitelistGang", 5},
		{ "<t color='#ff66ff'>[EvolvE]</t> Advanced Rebel Equipment", "life_fnc_weaponShopMenu", "advanced_rebel", "(playerSide isEqualTo civilian && license_civ_PMC) && ['EvolvE', player] call PHX_fnc_inWhitelistGang", 5 },
        { "<t color='#ADFF2F'>[EvolvE]</t> Cashpoint", "PHX_fnc_atmMenu", "", "playerSide isEqualTo civilian && ['EvolvE', player] call PHX_fnc_inWhitelistGang", 5 }
    };
};

class Cawdor {
	actions[] = {
		{ "<t color='#ff66ff'>[Cawdor]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"rebel_dealership","civilian",{"civ_cawdor_spawn"},"reb","Vehicle Store"}, "(playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)) && ['Cawdor', player] call PHX_fnc_inWhitelistGang", 5 },
		{ "<t color='#ff66ff'>[Cawdor]</t> Car Garage", "PHX_fnc_getGarage", {{"civ_cawdor_spawn"},"Car"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && ['Cawdor', player] call PHX_fnc_inWhitelistGang", 5 },
		{ "<t color='#ff66ff'>[Cawdor]</t> Air Garage", "PHX_fnc_getGarage", {{"civ_cawdor_spawn"},"Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && ['Cawdor', player] call PHX_fnc_inWhitelistGang", 5 },
		{ "<t color='#ff66ff'>[Cawdor]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car","Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && ['Cawdor', player] call PHX_fnc_inWhitelistGang", 5 },
		{ "<t color='#ff66ff'>[Cawdor]</t> Cashpoint", "PHX_fnc_atmMenu", "", "['Cawdor', player] call PHX_fnc_inWhitelistGang", 5 }
	};
};

class CawdorStore {
    actions[] = {
        { "<t color='#ff66ff'>[Cawdor]</t> Rebel Market", "life_fnc_virt_menu", "rebel_market", "playerSide isEqualTo civilian && ((license_civ_rebel || license_civ_PMC)) && ['Cawdor', player] call PHX_fnc_inWhitelistGang", 5 },
        { "<t color='#ff66ff'>[Cawdor]</t> Rebel Clothing", "Martinez_fnc_openClothingStore", "rebel_store", "(playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)) && ['Cawdor', player] call PHX_fnc_inWhitelistGang", 5 },
        { "<t color='#ff66ff'>[Cawdor]</t> Basic Rebel Equipment", "life_fnc_weaponShopMenu", "basic_rebel", "(playerSide isEqualTo civilian && license_civ_rebel) && ['Cawdor', player] call PHX_fnc_inWhitelistGang", 5 },
        { "<t color='#ff66ff'>[Cawdor]</t> Loadouts", "Martinez_fnc_openLoadouts", "", "(playerSide isEqualTo civilian && license_civ_rebel) && ['Cawdor', player] call PHX_fnc_inWhitelistGang", 5},
		{ "<t color='#ff66ff'>[Cawdor]</t> Advanced Rebel Equipment", "life_fnc_weaponShopMenu", "advanced_rebel", "(playerSide isEqualTo civilian && license_civ_rebel) && ['Cawdor', player] call PHX_fnc_inWhitelistGang", 5 },
        { "<t color='#b4a7d6'>[Cawdor]</t> Clothing Store", "Martinez_fnc_openClothingStore", "general_clothing", "playerSide isEqualTo civilian && ((license_civ_rebel || license_civ_PMC)) && ['Cawdor', player] call PHX_fnc_inWhitelistGang", 5 },
		{ "<t color='#ffe599'>[Cawdor]</t> Medical Assistance", "life_fnc_healHospital", "playerSide isEqualTo civilian && ((license_civ_rebel || license_civ_PMC)) && ['Cawdor', player] call PHX_fnc_inWhitelistGang", 5 },
		{ "<t color='#ADFF2F'>[Cawdor]</t> Cashpoint", "PHX_fnc_atmMenu", "", "playerSide isEqualTo civilian && ['Cawdor', player] call PHX_fnc_inWhitelistGang", 5 }
    };
};

// General Markets
class huntingMarket {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Hunting Market", "life_fnc_virt_menu", "hunting_market", "", 5 }
	};
};
class fishMarket {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Fish Market", "life_fnc_virt_menu", "fish_market", "", 5 }
	};
};
class coffeeShop {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Coffee Shop", "life_fnc_virt_menu", "coffee_shop", "", 5 }
	};
};
class redBurger {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Red Burger", "life_fnc_virt_menu", "red_burger", "", 5 }
	};
};
class cfkChicken {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> CFK Chicken", "life_fnc_virt_menu", "cfk_chicken", "", 5 }
	};
};
class localPub {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Local Pub", "life_fnc_virt_menu", "local_pub", "", 5 }
	};
};
class drugDealer {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Drug Dealer", "life_fnc_virt_menu", "drug_dealer", "", 5 },
		{ "<t color='#073763'>[NATO]</t> Question Dealer", "life_fnc_questionDealer", "", "playerSide isEqualTo west", 5 }
	};
};
class turtleDealer {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Turtle Dealer", "life_fnc_virt_menu", "turtle_dealer", "", 5 },
		{ "<t color='#073763'>[NATO]</t> Question Dealer", "life_fnc_questionDealer", "", "playerSide isEqualTo west", 5 }
	};
};
class moonshineDealer {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Moonshine Dealer", "life_fnc_virt_menu", "moonshine_dealer", "", 5 },
		{ "<t color='#274e13'>[HAVOC]</t> Question Dealer", "life_fnc_questionDealer", "", "playerSide isEqualTo east", 5 }
	};
};
class goldBuyer {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Gold Buyer", "life_fnc_virt_menu", "gold_buyer", "", 5 }
	};
};
class plutoniumTrader {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Plutonium Dealer", "life_fnc_virt_menu", "plutonium_trader", "", 5 }
	};
};
class antiqueTrader {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Antique Trader", "life_fnc_virt_menu", "antique_trader", "", 5 }
	};
};
class diamondTrader {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Diamond Trader", "life_fnc_virt_menu", "diamond_trader", "", 5 }
	};
};
class gemTrader {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Gem Trader", "life_fnc_virt_menu", "gem_trader", "", 5 }
	};
};
class uraniumDealer {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Uranium Dealer", "life_fnc_virt_menu", "uranium_trader", "", 5 }
	};
};
class oilTrader {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Oil Trader", "life_fnc_virt_menu", "oil_trader", "", 5 }
	};
};
class siliconExports {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Silicon Exports", "life_fnc_virt_menu", "silicon_trader", "", 5 }
	};
};
class metalTrader {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Metal Trader", "life_fnc_virt_menu", "metal_trader", "", 5 }
	};
};
class glassTrader {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Glass Trader", "life_fnc_virt_menu", "glass_trader", "", 5 }
	};
};
class saltTrader {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Salt Trader", "life_fnc_virt_menu", "salt_trader", "", 5 }
	};
};
class coralExports {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Coral Exports", "life_fnc_virt_menu", "coral_exports", "", 5 }
	};
};
class TobaccoExports {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Cigarette Exports", "life_fnc_virt_menu", "cigarette_exports", "", 5 },
		{ "<t color='#b4a7d6'>[ALL]</t> Cigar Exports", "life_fnc_virt_menu", "cigar_exports", "", 5 }
	};
};
class ephedrineDealer {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Ephedrine Dealer", "life_fnc_virt_menu", "ephedrine_dealer", "", 5 }
	};
};
class weaponParts1 {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Weapon Parts Trader", "life_fnc_virt_menu", "weapon_parts_1", "", 5 }
	};
};
class weaponParts2 {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Weapon Parts Trader", "life_fnc_virt_menu", "weapon_parts_2", "", 5 }
	};
};
class weapon_trader {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Weapon Trader", "life_fnc_virt_menu", "weapon_trader", "", 5 }
	};
};
// class methdispensary {
// 	actions[] = {
// 		{ "<t color='#ffe599'>[ALL]</t> Meth Dispensary", "life_fnc_virt_menu", "ephedrine_dealer", "", 5 }
// 	};
// };
class medicalSupplies {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Medical Assistance", "life_fnc_healHospital", "", "", 5 },
		{ "<t color='#ffe599'>[ALL]</t> Medical Supplies", "life_fnc_virt_menu", "medical_supplies", "", 5 }
	};
};
class hmpMarket {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Pay Bail", "life_fnc_postBail", "", "life_canpay_bail && life_is_arrested", 5 },
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "", "", 5 },
		{ "<t color='#ffe599'>[ALL]</t> HMP Market", "life_fnc_virt_menu", "hmp_market", "life_is_arrested", 5 },
		{ "<t color='#ffe599'>[ALL]</t> Rock Trader", "life_fnc_virt_menu", "hmp_rockmarket", "life_is_arrested", 5 }
	};
};
class gulagMarket {
	actions[] = {
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "", "", 5 },
		{ "<t color='#ffe599'>[ALL]</t> Gulag Market", "life_fnc_virt_menu", "gulag_market", "life_is_arrested", 5 },
		{ "<t color='#ffe599'>[ALL]</t> Rock Trader", "life_fnc_virt_menu", "gulag_rockmarket", "life_is_arrested", 5 }
	};
};
class hiddenStore {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Hidden Store", "life_fnc_virt_menu", "hidden_market", "", 5 }
	};
};

// Clothing Stores
class clothingStore {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Clothing Store", "Martinez_fnc_openClothingStore", "general_clothing", "playerSide isEqualTo civilian || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 }
	};
};

// Licencing Stores
class dvla {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> License Store", "PHX_fnc_openLicenses", {"driver","trucking","boat","pilot","dive","home",}, "playerSide isEqualTo civilian", 5 }
	};
};

class permitStore {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Permit Store", "PHX_fnc_openLicenses", {"cider","tobacco","copper","iron","silver","silicon","aluminium","sand","salt","oil","diamond"}, "playerSide isEqualTo civilian", 5 }
	};
}

// Sky dive
class skydive {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Skydive", "PHX_fnc_skyDive", "", "", 5 }
	};
};

// Hideout
class hideout {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Capture Hideout", "PHX_fnc_captureObject", {"hideout_flag","Rebel Hideout","rebel_hideout"}, "playerSide isEqualTo civilian", 5 }
	};
};

class hideout2 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Capture Hideout", "PHX_fnc_captureObject", {"hideout_flag_2","Rebel Hideout","rebel_hideout_2"}, "playerSide isEqualTo civilian", 5 }
	};
};

class civBlackjack {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Play Blackjack", "{createDialog 'RscBlackjack'}", "", "true", 5 }
	};
};
class civSlots {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Spins Slots", "{createDialog 'RscSlotMachine'}", "", "true", 5 }
	};
};
class civHigherOrLower {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Play Higher Or Lower", "{createDialog 'RscHigherOrLower'}", "", "true", 5 }
	};
};
class civRoulette {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Play Roulette", "{createDialog 'RscRoulette'}", "", "true", 5 }
	};
};
class KavalaLift {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Lift Up", "phx_fnc_elevator",{"Kavala","Up"}, "", 5 },
		{ "<t color='#ffe599'>[ALL]</t> Lift Down", "phx_fnc_elevator",{"Kavala","Down"}, "", 5 }
	};
};
class AthiraLift {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Lift Up", "phx_fnc_elevator",{"Athira","Up"}, "", 5 },
		{ "<t color='#ffe599'>[ALL]</t> Lift Down", "phx_fnc_elevator",{"Athira","Down"}, "", 5 }
	};
};
class PyrgosLift {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Lift Up", "phx_fnc_elevator",{"Pyrgos","Up"}, "", 5 },
		{ "<t color='#ffe599'>[ALL]</t> Lift Down", "phx_fnc_elevator",{"Pyrgos","Down"}, "", 5 }
	};
};

class medicSignOn {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Sign on", "Martinez_fnc_signOn","Medic", "", 5 },
		{ "<t color='#ffe599'>[ALL]</t> Sign off", "Martinez_fnc_signOff","Medic", "", 5 }
	};
};

// Vehicle Stores
class civCarLijnhaven {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"car_dealership","civilian",{"civ_car_spawn_Lijnhaven_1","civ_car_spawn_Lijnhaven_2"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_driver) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 }
	};
};
class civCarGeorgetown {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"car_dealership","civilian",{"civ_car_spawn_georgetown_1","civ_car_spawn_georgetown_2"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_driver) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 }
	};
};
class civCarAthira {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"car_dealership","civilian",{"civ_car_spawn_athira_1"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_driver) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 }
	};
};
class civCarPyrgos {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"car_dealership","civilian",{"civ_car_spawn_pyrgos_1"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_driver) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 }
	};
};
class civTruckLijnhaven {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"truck_dealership","civilian",{"Lijnhaven_truck_1"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_trucking) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "", "", 5 }
	};
};
class civTruckGeorgetown {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"truck_dealership","civilian",{"civ_truck_spawn_georgetown"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_trucking) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "", "", 5 }
	};
};
class civBoatLjinhaven {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"boat_dealership","civilian",{"civ_boat_spawn_Ljinhaven"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_boat) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Boat Garage", "PHX_fnc_getGarage", {{"civ_boat_spawn_Ljinhaven"},"Ship"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Ship","Car"}, "", 5 }
	};
};

class civBoatGeorgetown {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"boat_dealership","civilian",{"civ_boat_spawn_GeorgeTown"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_boat) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Boat Garage", "PHX_fnc_getGarage", {{"civ_boat_spawn_GeorgeTown"},"Ship"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Ship","Car"}, "", 5 }
	};
};

class civBoatHarcourt {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"boat_dealership","civilian",{"civ_boat_spawn_Harcourt"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_boat) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Boat Garage", "PHX_fnc_getGarage", {{"civ_boat_spawn_Harcourt"},"Ship"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Ship","Car"}, "", 5 }
	};
};

class civBoatBlerick {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"boat_dealership","civilian",{"civ_boat_spawn_Blerick"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_boat) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Boat Garage", "PHX_fnc_getGarage", {{"civ_boat_spawn_Blerick"},"Ship"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Ship","Car"}, "", 5 }
	};
};

class civBoatKatkoula {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"boat_dealership","civilian",{"civ_boat_spawn_Katkoula"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_boat) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Boat Garage", "PHX_fnc_getGarage", {{"civ_boat_spawn_Katkoula"},"Ship"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Ship","Car"}, "", 5 }
	};
};

class civBoatTavu {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"boat_dealership","civilian",{"civ_boat_spawn_Tavu"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_boat) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Boat Garage", "PHX_fnc_getGarage", {{"civ_boat_spawn_Tavu"},"Ship"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Ship","Car"}, "", 5 }
	};
};
class civBoatBelfort {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"boat_dealership","civilian",{"civ_boat_spawn_Belfort"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_boat) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Boat Garage", "PHX_fnc_getGarage", {{"civ_boat_spawn_Belfort"},"Ship"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Ship","Car"}, "", 5 }
	};
};

class civBoatRemnant {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"boat_dealership","civilian",{"civ_boat_spawn_Remnant"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_boat) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Boat Garage", "PHX_fnc_getGarage", {{"civ_boat_spawn_Remnant"},"Ship"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Ship","Car"}, "", 5 }
	};
};

class civBoatOumere {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"boat_dealership","civilian",{"civ_boat_spawn_Oumere"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_boat) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Boat Garage", "PHX_fnc_getGarage", {{"civ_boat_spawn_Oumere"},"Ship"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Ship","Car"}, "", 5 }
	};
};

class civBoatBa {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"boat_dealership","civilian",{"civ_boat_spawn_Ba"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_boat) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Boat Garage", "PHX_fnc_getGarage", {{"civ_boat_spawn_Ba"},"Ship"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Ship","Car"}, "", 5 }
	};
};
class civBoatLaRochelle {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"boat_dealership","civilian",{"civ_boat_spawn_La_Rochelle"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_boat) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Boat Garage", "PHX_fnc_getGarage", {{"civ_boat_spawn_La_Rochelle"},"Ship"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Ship","Car"}, "", 5 }
	};
};





class civAirLijnhaven {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"international_dealership","civilian",{"civ_Lijnhaven_Air_spawn_1","civ_Lijnhaven_Air_spawn_2"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_pilot) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Air Garage", "PHX_fnc_getGarage", {{"civ_Lijnhaven_Air_spawn_1"},"Air"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car","Air"}, "", 5 },
		{ "<t color='#ffe599'>[ALL]</t> Duty Free", "life_fnc_virt_menu", "air_general_market", "", 5 }
	};
};

class carGarageAirLijnhaven {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"civ_air_garage_Lijnhaven_spawn_1"},"Car"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};

class civInternational {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"international_dealership","civilian",{"civ_international_spawn_1","civ_international_spawn_2"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_pilot) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Air Garage", "PHX_fnc_getGarage", {{"civ_international_spawn_1"},"Air"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car","Air"}, "", 5 },
		{ "<t color='#ffe599'>[ALL]</t> Duty Free", "life_fnc_virt_menu", "air_general_market", "", 5 }
	};
};

class carGarageAirInternational {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"carGarageAirInternational"},"Car"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};

class civAirTuvanka {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"international_dealership","civilian",{"civ_Air_Tuvanka_spawn"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_pilot) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Air Garage", "PHX_fnc_getGarage", {{"civ_Air_Tuvanka_spawn"},"Air"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car","Air"}, "", 5 },
		{ "<t color='#ffe599'>[ALL]</t> Duty Free", "life_fnc_virt_menu", "air_general_market", "", 5 }
	};
};

class carGarageAirTuvanka {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"carGarageAirTuvanka"},"Car"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};

class civAirLaRuchelle {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"international_dealership","civilian",{"civ_Air_LaRuchelle_spawn"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_pilot) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Air Garage", "PHX_fnc_getGarage", {{"civ_Air_LaRuchelle_spawn"},"Air"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car","Air"}, "", 5 },
		{ "<t color='#ffe599'>[ALL]</t> Duty Free", "life_fnc_virt_menu", "air_general_market", "", 5 }
		
	};
};
class carGarageAirLaRuchelle {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"carGarageLaRuchelle"},"Car"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};

class carGarageAirBala {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"carGarageAirBala"},"Car"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};


class civAirBala {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"international_dealership","civilian",{"civ_international_bala"},"civ","Vehicle Store"}, "(playerSide isEqualTo civilian && license_civ_pilot) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Air Garage", "PHX_fnc_getGarage", {{"civ_international_bala"},"Air"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car","Air"}, "", 5 },
		{ "<t color='#ffe599'>[ALL]</t> Duty Free", "life_fnc_virt_menu", "air_general_market", "", 5 }
	};
};

class civRebel1 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"rebel_dealership","civilian",{"civ_rebel_spawn_1"},"reb","Vehicle Store"}, "(playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"civ_rebel_spawn_1"},"Car"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Air Garage", "PHX_fnc_getGarage", {{"civ_rebel_spawn_1"},"Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car","Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)", 5 },
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "", "", 5 }
	};
};

class civRebel2 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"rebel_dealership","civilian",{"civ_rebel_spawn_2"},"reb","Vehicle Store"}, "(playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"civ_rebel_spawn_2"},"Car"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Air Garage", "PHX_fnc_getGarage", {{"civ_rebel_spawn_2"},"Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car","Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)", 5 },
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "", "", 5 }
	
	};
};
class civRebel3 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"rebel_dealership","civilian",{"civ_rebel_spawn_3"},"reb","Vehicle Store"}, "(playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"civ_rebel_spawn_3"},"Car"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Air Garage", "PHX_fnc_getGarage", {{"civ_rebel_spawn_3"},"Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car","Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)", 5 },
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "", "", 5 }
	
	};
};
class civRebel4 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"rebel_dealership","civilian",{"civ_rebel_spawn_4"},"reb","Vehicle Store"}, "(playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)) || { (player getVariable ['isCID', false]) || (player getVariable ['isHSS', false])}", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"civ_rebel_spawn_4"},"Car"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Air Garage", "PHX_fnc_getGarage", {{"civ_rebel_spawn_4"},"Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car","Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)", 5 },
		{ "<t color='#ADFF2F'>[ATM]</t> Cashpoint", "PHX_fnc_atmMenu", "", "", 5 }
	
	};
};

class Evolve {
	actions[] = {
		{ "<t color='#ff66ff'>[EvolvE]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"rebel_dealership","civilian",{"civ_evolve_spawn"},"reb","Vehicle Store"}, "(playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)) && ['EvolvE', player] call PHX_fnc_inWhitelistGang", 5 },
		{ "<t color='#ff66ff'>[EvolvE]</t> Car Garage", "PHX_fnc_getGarage", {{"civ_evolve_spawn"},"Car"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && ['EvolvE', player] call PHX_fnc_inWhitelistGang", 5 },
		{ "<t color='#ff66ff'>[EvolvE]</t> Air Garage", "PHX_fnc_getGarage", {{"civ_evolve_spawn"},"Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && ['EvolvE', player] call PHX_fnc_inWhitelistGang", 5 },
		{ "<t color='#ff66ff'>[EvolvE]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car","Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && ['EvolvE', player] call PHX_fnc_inWhitelistGang", 5 },
		{ "<t color='#ff66ff'>[EvolvE]</t> Cashpoint", "PHX_fnc_atmMenu", "", "", 5 }
	};
};

class captureHideoutVeh {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"rebel_dealership","civilian",{"capture_hideout_veh_spawn"},"reb","Vehicle Store"}, "(playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)) && ['hideout_flag'] call PHX_fnc_ownsObject", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"capture_hideout_veh_spawn"},"Car"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && ['hideout_flag'] call PHX_fnc_ownsObject", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Air Garage", "PHX_fnc_getGarage", {{"capture_hideout_veh_spawn"},"Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && ['hideout_flag'] call PHX_fnc_ownsObject", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car","Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && ['hideout_flag'] call PHX_fnc_ownsObject", 5 }
	};
};

class captureHideoutVeh2 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"rebel_dealership","civilian",{"capture_hideout_veh_spawn_1"},"reb","Vehicle Store"}, "(playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC)) && ['hideout_flag_2'] call PHX_fnc_ownsObject", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"capture_hideout_veh_spawn_1"},"Car"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && ['hideout_flag_2'] call PHX_fnc_ownsObject", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Air Garage", "PHX_fnc_getGarage", {{"capture_hideout_veh_spawn_1"},"Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && ['hideout_flag_2'] call PHX_fnc_ownsObject", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car","Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && ['hideout_flag_2'] call PHX_fnc_ownsObject", 5 }
	};
};

class northEastBase1 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"rebel_dealership","civilian",{"ne_veh_spawn_1"},"reb","Vehicle Store"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['NE'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"ne_veh_spawn_1"},"Car"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['NE'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['NE'] call PHX_fnc_ownsBase }", 5 }
	};
};

class northEastBase2 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Air Garage", "PHX_fnc_getGarage", {{"ne_veh_spawn_2"},"Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['NE'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['NE'] call PHX_fnc_ownsBase }", 5 }
	};
};

class northWestBase1 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"rebel_dealership","civilian",{"nw_veh_spawn_1"},"reb","Vehicle Store"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['NW'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"nw_veh_spawn_1"},"Car"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['NW'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['NW'] call PHX_fnc_ownsBase }", 5 }
	};
};

class northWestBase2 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Air Garage", "PHX_fnc_getGarage", {{"nw_veh_spawn_2"},"Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['NW'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['NW'] call PHX_fnc_ownsBase }", 5 }
	};
};

class southWestBase1 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"rebel_dealership","civilian",{"sw_veh_spawn_1"},"reb","Vehicle Store"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['SW'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"sw_veh_spawn_1"},"Car"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['SW'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['SW'] call PHX_fnc_ownsBase }", 5 }
	};
};

class southWestBase2 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Air Garage", "PHX_fnc_getGarage", {{"sw_veh_spawn_2"},"Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['SW'] call PHX_fnc_ownsBase }", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Air"}, "playerSide isEqualTo civilian && (license_civ_rebel || license_civ_PMC) && { ['SW'] call PHX_fnc_ownsBase }", 5 }
	};
};

// Car Garages
class carGarageKavala {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"civ_car_garage_kavala_spawn_1"},"Car"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};
class carGarageAthira {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"civ_car_garage_athira_spawn_1"},"Car"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};
class carGaragePyrgos {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"civ_car_garage_pyrgos_spawn_1"},"Car"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};
class carGarageAgios {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"civ_car_garage_agios_spawn_1"},"Car"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};
class carGarageSofia {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"civ_car_garage_sofia_spawn_1"},"Car"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};
class carGarageNeochori {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"civ_car_garage_neochori_spawn_1"},"Car"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};
class carGarageCourt {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"civ_car_garage_court_spawn_1"},"Car"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};
class carGarageInternational {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"civ_car_garage_international_spawn_1"},"Car"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};
class carGarageAbandoned {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"civ_car_garage_abandoned_spawn_1"},"Car"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};

class personalGarageMax {
	actions[] = {
		{ "<t color='#ff66ff'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"personal_car_garage_max_spawn"},"Car"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#ff66ff'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};
class personalGarageRoy {
	actions[] = {
		{ "<t color='#ff66ff'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"personal_car_garage_roy_spawn"},"Car"}, "playerSide isEqualTo civilian && (getPlayerUID player) isEqualTo '76561198349852248'", 5 },
		{ "<t color='#ff66ff'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};
class personalGarageJamie {
	actions[] = {
		{ "<t color='#ff66ff'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"personal_car_garage_jamie_spawn"},"Car"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#ff66ff'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};
class personalGarageMax2 {
	actions[] = {
		{ "<t color='#ff66ff'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"personal_car_garage_max_spawn_2"},"Car"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#ff66ff'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};
class personalGarageProxy {
	actions[] = {
		{ "<t color='#ff0000'>[CIV]</t> Car Garage", "PHX_fnc_getGarage", {{"personal_car_garage_proxy_spawn"},"Car"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#ff0000'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Car"}, "playerSide isEqualTo civilian", 5 }
	};
};
class so1Island {
	actions[] = {
		{ "<t color='#073763'>[SO1]</t> Vehicle Store", "life_fnc_vehicleShopMenu", {"so1_car_1","west",{"so1_car_spawn_1"},"Car","Vehicle Store"}, "playerSide isEqualTo civilian && { player getVariable [""isSO1"", false] } && { license_civ_so1 }", 5 }
	};
};

// Air Garages
class airGarageCourt {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Air Garage", "PHX_fnc_getGarage", {{"civ_air_garage_court_spawn_1"},"Air"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Air"}, "playerSide isEqualTo civilian", 5 }
	};
};
class airGarageAbandoned {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Air Garage", "PHX_fnc_getGarage", {{"civ_air_garage_abandoned_spawn_1","civ_air_garage_abandoned_spawn_2"},"Air"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Air"}, "playerSide isEqualTo civilian", 5 }
	};
};
class airGarageMolos {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Air Garage", "PHX_fnc_getGarage", {{"civ_air_garage_molos_spawn_1"},"Air"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Store Vehicle", "life_fnc_storeVehicle", {"Air"}, "playerSide isEqualTo civilian", 5 }
	};
};
class airGarageJamie {
	actions[] = {
		{ "<t color='#b4a7d6'>[JAMIE]</t> Air Garage", "PHX_fnc_getGarage", {{"personal_air_garage_jamie_spawn_1","civ_air_garage_abandoned_spawn_2"},"Air"}, "playerSide isEqualTo civilian && (getPlayerUID player) isEqualTo '76561198271814932'", 5 },
		{ "<t color='#b4a7d6'>[JAMIE]</t> Store Vehicle", "life_fnc_storeVehicle", {"Air"}, "playerSide isEqualTo civilian && (getPlayerUID player) isEqualTo '76561198271814932'", 5 }
	};
};

// ID Actions
class civForger {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Create Fake ID", "PHX_fnc_createFakeID", "playerSide isEqualTo civilian", "playerSide isEqualTo civilian", 5 }
	};
};

// Chop Shops
class civChopShop {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Chop Shop", "life_fnc_chopShopMenu", "chop_shop_1", "playerSide isEqualTo civilian || playerSide isEqualTo east", 5 }
	};
};
class civChopShop2 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Chop Shop", "life_fnc_chopShopMenu", "chop_shop_2", "playerSide isEqualTo civilian || playerSide isEqualTo east", 5 }
	};
};
class civChopShop3 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Chop Shop", "life_fnc_chopShopMenu", "chop_shop_3", "playerSide isEqualTo civilian || playerSide isEqualTo east", 5 }
	};
};

// Service Stations
class ServiceStation1 {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Service Station", "life_fnc_serviceVehicle", "service_1", "", 5 }
	};
};
class ServiceStation2 {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Service Station", "life_fnc_serviceVehicle", "service_2", "", 5 }
	};
};

class ServiceStation3 {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Service Station", "life_fnc_serviceVehicle", "service_3", "", 5 }
	};
};

class ServiceStation4 {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Service Station", "life_fnc_serviceVehicle", "service_4", "", 5 }
	};
};
class ServiceStation5 {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Service Station", "life_fnc_serviceVehicle", "service_5", "", 5 }
	};
};

// Major Crimes
class hmHack {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Hack Vault", "PHX_fnc_hackObject", "HM", "playerSide in [civilian, east] && { isNil { _target getVariable ""inUse"" } }", 5 },
		{ "<t color='#073763'>[NATO]</t> Remove Malicious Software", "PHX_fnc_revertHack", "HM", "playerSide isEqualTo west && { isNil { _target getVariable ""inUse"" } }", 5 }
	};
};

class havocArmoury {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Drill into Vault", "PHX_fnc_drillObject", "Armoury", "playerSide in [civilian, west] && { isNil { _target getVariable ""inUse"" } }", 5 },
		{ "<t color='#274e13'>[HAVOC]</t> Fix Vault Lock", "PHX_fnc_fixVault", "Armoury", "playerSide isEqualTo east && { isNil { _target getVariable ""inUse"" } }", 5 }
	};
};

class desHack {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Hack Gates", "PHX_fnc_hackObject", "Destroyer", "playerSide in [civilian, west] && { isNil { _target getVariable ""inUse"" } }", 5 },
		{ "<t color='#274e13'>[HAVOC]</t> Remove Malicious Software", "PHX_fnc_revertHack", "Destroyer", "playerSide isEqualTo east && { isNil { _target getVariable ""inUse"" } }", 5 }
	};
};

class havocDestroyer {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Drill into Vault", "PHX_fnc_drillObject", "Destroyer", "playerSide in [civilian, west] && { isNil { _target getVariable ""inUse"" } }", 5 },
		{ "<t color='#274e13'>[HAVOC]</t> Fix Vault Lock", "PHX_fnc_fixVault", "Destroyer", "playerSide isEqualTo east && { isNil { _target getVariable ""inUse"" } }", 5 }
	};
};

class lockup {
	actions[] = {
		{ "<t color='#ffe599'>[ALL]</t> Hack Vault", "PHX_fnc_hackObject", "Evidence", "playerSide in [civilian, east] && { isNil { _target getVariable ""inUse"" } }", 5 },
		{ "<t color='#073763'>[NATO]</t> Remove Malicious Software", "PHX_fnc_revertHack", "Evidence", "playerSide isEqualTo west && { isNil { _target getVariable ""inUse"" } }", 5 }
	};
};

class enlist {
	actions[] = {
		{ "<t color='#b4a7d6'>[ALL]</t> Enlistment", "PHX_fnc_openEnlistment", "", "playerSide isEqualTo civilian", 5 }
	};
};

class tuningShop1 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Paint Shop", "PHX_fnc_openTuning", {0,"tuning_shop_1"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Upgrades", "PHX_fnc_openVehicleUpgradesList", "tuning_shop_1", "playerSide isEqualTo civilian", 5 }
	};
};

class tuningShop2 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Tuning Shop", "PHX_fnc_openTuning", {0,"tuning_shop_2"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Upgrades", "PHX_fnc_openVehicleUpgradesList", "tuning_shop_2", "playerSide isEqualTo civilian", 5 }
	};
};

class tuningShop3 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Tuning Shop", "PHX_fnc_openTuning", {0,"tuning_shop_3"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Upgrades", "PHX_fnc_openVehicleUpgradesList", "tuning_shop_3", "playerSide isEqualTo civilian", 5 }
	};
};

class tuningShop4 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Tuning Shop", "PHX_fnc_openTuning", {0,"tuning_shop_4"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Upgrades", "PHX_fnc_openVehicleUpgradesList", "tuning_shop_4", "playerSide isEqualTo civilian", 5 }
	};
};

class tuningShop5 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Tuning Shop", "PHX_fnc_openTuning", {0,"tuning_shop_5"}, "playerSide isEqualTo civilian", 5 },
		{ "<t color='#b4a7d6'>[CIV]</t> Vehicle Upgrades", "PHX_fnc_openVehicleUpgradesList", "tuning_shop_5", "playerSide isEqualTo civilian", 5 }
	};
};

class oilReserve {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Oil Reserve", "PHX_fnc_petrolMenu", "", "playerSide isEqualTo civilian", 5 }
	};
};

class smugglerCollect1 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Fill Cargo", "PHX_fnc_collectSmuggle", {"smugglerCollect1"}, "playerSide isEqualTo civilian", 5 }
	};
};

class smugglerCollect2 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Fill Cargo", "PHX_fnc_collectSmuggle", {"smugglerCollect2"}, "playerSide isEqualTo civilian", 5 }
	};
};

class smugglerSell1 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Empty Cargo", "PHX_fnc_deliverSmuggle", {"smugglerSell1"}, "playerSide isEqualTo civilian", 5 }
	};
};

class smugglerSell2 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Empty Cargo", "PHX_fnc_deliverSmuggle", {"smugglerSell2"}, "playerSide isEqualTo civilian", 5 }
	};
};

class smugglerSell3 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Empty Cargo", "PHX_fnc_deliverSmuggle", {"smugglerSell3"}, "playerSide isEqualTo civilian", 5 }
	};
};

class smugglerSell4 {
	actions[] = {
		{ "<t color='#b4a7d6'>[CIV]</t> Empty Cargo", "PHX_fnc_deliverSmuggle", {"smugglerSell4"}, "playerSide isEqualTo civilian", 5 }
	};
};
