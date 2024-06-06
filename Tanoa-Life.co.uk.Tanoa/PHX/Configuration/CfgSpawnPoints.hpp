#define gangBase(name) #[name] call PHX_fnc_ownsBase

class CfgSpawnPoints {
    class Altis {
        class Civilian {
            // Standard Locations
            class Kavala {
                displayName = "Lijnhaven";
                spawnMarker = "civ_spawn_1";
                icon = "data\icons\ico_Kavala.paa";
                conditions = "";
            };
            class Athira {
                displayName = "Saint-George Airport";
                spawnMarker = "civ_spawn_3";
                icon = "data\icons\ico_Athira.paa";
                conditions = "";
            };
            class Pyrgos {
                displayName = "Georgetown";
                spawnMarker = "civ_spawn_2";
                icon = "data\icons\ico_Pyrgos.paa";
                conditions = "";
            };

            // Job Locations
            class government_offices {
                displayName = "Government Offices";
                spawnMarker = "so1_offices_spawn";
                icon = "\a3\ui_f\data\map\MapControl\watertower_ca.paa";
                conditions = "PHX_isPM || license_civ_SO1";
            };
            class governors_residence {
                displayName = "Governor's Residence";
                spawnMarker = "governors_residence";
                icon = "data\icons\ico_House.paa";
                conditions = "PHX_isPM || license_civ_SO1";
            };
             class So1Island {
                displayName = "Government Island";
                spawnMarker = "so1_spawnisland";
                icon = "\a3\ui_f\data\map\MapControl\watertower_ca.paa";
                conditions = "PHX_isPM || license_civ_SO1";
            };

            class TaxiHQ {
                displayName = "Taxi HQ";
                spawnMarker = "civ_spawn_TaxiHQ";
                icon = "data\ui\taxi.paa";
                conditions = "license_civ_taximan";
            };
            class RepairHQ {
                displayName = "Altis Services HQ";
                spawnMarker = "civ_spawn_repairhq";
                icon = "data\icons\ico_Repair.paa";
                conditions = "license_civ_repair";
            };
            class LawyerHQ {
                displayName = "Altis Lawyers HQ";
                spawnMarker = "civ_spawn_lawyer";
                icon = "data\ui\lawyer.paa";
                conditions = "license_civ_lawyer";
            };
            class AltisNews {
                displayName = "Altis News";
                spawnMarker = "altisnews_spawn";
                icon = "data\icons\ico_News.paa";
                conditions = "license_civ_news";
            };

            // Traveler Perk Locations
            class Sofia {
                displayName = "Sofia";
                spawnMarker = "civ_spawn_4";
                icon = "data\icons\ico_Sofia.paa";
                conditions = "(PHX_Perks findIf { _x isEqualTo ""wideTraveller"" }) > -1";
            };

            class Agios {
                displayName = "Agios";
                spawnMarker = "civ_spawn_5";
                icon = "data\icons\ico_Agios.paa";
                conditions = "(PHX_Perks findIf { _x isEqualTo ""wideTraveller"" }) > -1";
            };

            class Neochori {
                displayName = "Neochori";
                spawnMarker = "civ_spawn_6";
                icon = "data\icons\ico_Agios.paa";
                conditions = "(PHX_Perks findIf { _x isEqualTo ""wideTraveller"" }) > -1";
            };

            class NWBase {
                displayname = "Gang Base";
                spawnMarker = "buy_spawn_1";
                icon = "\a3\ui_f\data\map\MapControl\bunker_ca.paa";
                conditions = gangBase("NW");
            };
            class NEBase {
                displayname = "Gang Base";
                spawnMarker = "buy_Spawn_2";
                icon = "\a3\ui_f\data\map\MapControl\bunker_ca.paa";
                conditions = gangBase("NE");
            };
            class SWBase {
                displayname = "Gang Base";
                spawnMarker = "buy_Spawn_3";
                icon = "\a3\ui_f\data\map\MapControl\bunker_ca.paa";
                conditions = gangBase("SW");
            };

            // Undercover Spawns
            class cid {
                displayname = "CID Base";
                spawnMarker = "cid_spawn";
                icon = "\a3\ui_f\data\map\MapControl\bunker_ca.paa";
                conditions = "player getVariable ['isCID', false]";
            };
            class hss {
                displayname = "HSS Base";
                spawnMarker = "hss_spawn";
                icon = "\a3\ui_f\data\map\MapControl\bunker_ca.paa";
                conditions = "player getVariable ['isHSS', false]";
            };
        };

        class Cop {
            class Kavala {
                displayName = "Test Station";
                spawnMarker = "cop_spawn_1";
                icon = "data\icons\ico_Kavala.paa";
                conditions = "";
            };
            class Athira {
                displayName = "Athira Station";
                spawnMarker = "cop_spawn_3";
                icon = "data\icons\ico_Athira.paa";
                conditions = "";
            };
            class Agios {
                displayName = "Agios Station";
                spawnMarker = "cop_spawn_2";
                icon = "data\icons\ico_Agios.paa";
                conditions = "";
            };
            class Sofia {
                displayName = "Sofia Station";
                spawnMarker = "cop_spawn_4";
                icon = "data\icons\ico_Agios.paa";
                conditions = "";
            };
            class MPU {
                displayName = "MPU HQ";
                spawnMarker = "apc_spawn_MPU";
                icon = "\a3\ui_f\data\map\MapControl\watertower_ca.paa";
                conditions = "call life_mpulevel >= 1";
            };
            class specunits {
                displayName = "Spec. Unit HQ";
                spawnMarker = "apc_spec_spawn";
                icon = "\a3\ui_f\data\map\MapControl\watertower_ca.paa";
                conditions = "call life_npaslevel >= 1 || call life_mpulevel >= 1 || call life_tpulevel >= 1 || call life_ctulevel >= 1";
            };
        };

        class Medic {
            class Kavala {
                displayName = "Lijnhaven Hospital";
                spawnMarker = "medic_spawn_1";
                icon = "data\icons\ico_Kavala.paa";
                conditions = "";
            };
            class specunits {
                displayName = "Spec. Unit HQ";
                spawnMarker = "medic_spawn_2";
                icon = "\a3\ui_f\Data\map\vehicleIcons\iconHelicopter_ca.paa";
                conditions = "call life_sarlevel >= 1";
            };
        };

        class HAVOC {
            class Base {
                displayName = "Molos HQ";
                spawnMarker = "havoc_basespawn";
                icon = "\a3\ui_f\data\map\MapControl\bunker_ca.paa";
                conditions = "";
            };
            class sFob {
                displayName = "Units HQ";
                spawnMarker = "havoc_fob_spawn";
                icon = "\a3\ui_f\data\map\MapControl\bunker_ca.paa";
                conditions = "";
            };
            class CP {
                displayName = "Checkpoint";
                spawnMarker = "havoc_cpspawn";
                icon = "\a3\ui_f\data\map\MapControl\bunker_ca.paa";
                conditions = "";
            };
        };
    };

    class Tanoa {
        class NATO {

            class NATO {
                displayName = "NATO HQ";
                spawnMarker = "cop_spawn_0";
                icon = "data\icons\ico_Kavala.paa";
                conditions = "";
            };

            class Georgetown {
                displayName = "Georgetown Station";
                spawnMarker = "cop_spawn_1";
                icon = "data\icons\ico_Agios.paa";
                conditions = "";
            };
            class AirCommand {
                displayName = "Air Command HQ";
                spawnMarker = "apc_spawn_AC";
                icon = "\a3\ui_f\Data\map\vehicleIcons\iconHelicopter_ca.paa";
                conditions = "call life_npaslevel >= 1 ";
            };

        };
        class Civilian {
            // Standard Locations
            class Georgetown {
                displayName = "Georgetown";
                spawnMarker = "civ_spawn_2";
                icon = "data\icons\ico_Kavala.paa";
                conditions = "";
            };
            class Lijnhaven {
                displayName = "Lijnhaven";
                spawnMarker = "civ_spawn_1";
                icon = "data\icons\ico_Athira.paa";
                conditions = "";
            };
            
            class governors_residence {
                displayName = "Governor's Residence";
                spawnMarker = "governors_residence";
                icon = "data\icons\ico_House.paa";
                conditions = "PHX_isPM || license_civ_SO1";
            };

            class governors_Office {
                displayName = "Governor's Office";
                spawnMarker = "governors_office";
                icon = "data\icons\ico_House.paa";
                conditions = "PHX_isPM || license_civ_SO1";
            };

            class TaxiHQ {
                displayName = "Taxi HQ";
                spawnMarker = "civ_spawn_TaxiHQ";
                icon = "data\ui\taxi.paa";
                conditions = "license_civ_taximan";
            };

            class EvolvE {
                displayName = "Evolve Gang Base";
                spawnMarker = "evolve_gang_base";
                icon = "data\icons\ico_Kavala.paa";
                conditions = "['EvolvE', player] call PHX_fnc_inWhitelistGang";
            };
            class Cawdor {
                displayName = "Cawdor Gang Base";
                spawnMarker = "Cawdor_gang_base";
                icon = "data\icons\ico_Kavala.paa";
                conditions = "['Cawdor', player] call PHX_fnc_inWhitelistGang";
            };

    };

    class Medic {
            class Lijnhaven {
                displayName = "Lijnhaven Hospital";
                spawnMarker = "medic_spawn_1";
                icon = "data\icons\ico_Kavala.paa";
                conditions = "";
            };
            class Georgetown {
                displayName = "Georgetown Hospital";
                spawnMarker = "medic_spawn_3";
                icon = "data\icons\ico_Athira.paa";
                conditions = "";
                
            }
            class MAS {
                displayName = "Spec. Unit HQ";
                spawnMarker = "medic_spawn_2";
                icon = "\a3\ui_f\Data\map\vehicleIcons\iconHelicopter_ca.paa";
                conditions = "call life_sarlevel >= 1";
            };
        };


    
        class TPLA {
            class Base {
                displayName = "TPLA HQ";
                spawnMarker = "havoc_basespawn";
                icon = "\a3\ui_f\data\map\MapControl\bunker_ca.paa";
                conditions = "";
            };
            class sFob {
                displayName = "TPLA Units HQ";
                spawnMarker = "TPLA_spec_spawn";
                icon = "\a3\ui_f\data\map\MapControl\bunker_ca.paa";
                conditions = "";
            };
            class CP {
                displayName = "TPLA Lijnhaven HQ";
                spawnMarker = "havoc_cpspawn";
                icon = "\a3\ui_f\data\map\MapControl\bunker_ca.paa";
                conditions = "";
            };
        };

};
};
