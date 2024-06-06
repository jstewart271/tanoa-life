class CfgWhitelist {
	class Whitelists {
		class Staff {
			whitelistLvlAccess = "call life_adminlevel >= 4";
			databaseIndex = "adminlevel";
			callCode = "life_adminlevel";
			rankArr[] = {"None", "Support", "Admin", "Senior Admin", "Staff Lead", "CM", "CMT"};
		};

		class Donator {
			whitelistLvlAccess = "call life_adminlevel >= 1";
			databaseIndex = "donatorlevel";
			callCode = "life_donatorlevel";
			rankArr[] = {"None", "1"};
		};

		class NATO {
			whitelistLvlAccess = "call life_adminlevel >= 2 || call life_coplevel >= 9";
			databaseIndex = "coplevel";
			callCode = "life_coplevel";
			rankArr[] = {"None", "Private", "Lance Corporal", "Corporal", "Sergeant", "Staf Sergeant", "Warrant Officer Class 2", "Warrant Officer Class 1", "Lieutenant", "Captain", "Major", "Brigadier", "Colonel", "General"};

			class SubDivitions {
				class SOFCOM {
					databaseIndex = "ctulevel";
					callCode = "life_ctulevel";
					rankArr[] = {"None", "Tier 1", "Tier 2", "Tier 3", "Deputy", "Commander"};
				};
				class AC {
					databaseIndex = "npaslevel";
					callCode = "life_npaslevel";
					rankArr[] = {"None", "Tier 1", "Tier 2", "Tier 3", "Tier 4", "Tier 5", "Deputy", "Commander"};
				};
				class WC {
					databaseIndex = "mpulevel";
					callCode = "life_mpulevel";
					rankArr[] = {"None", "Tier 1", "Tier 2", "Tier 3", "Tier 4", "Tier 5", "Deputy", "Commander"};
				};
				class UC {
					databaseIndex = "mi5level";
					callCode = "life_cidlevel";
					rankArr[] = {"None", "Tier 1", "Tier 2", "Tier 3", "Tier 4", "Tier 5", "Deputy", "Commander"};
				};
			};
		};

		class IDAP {
			whitelistLvlAccess = "call life_adminlevel >= 2 || call life_mediclevel >= 6";
			databaseIndex = "mediclevel";
			callCode = "life_mediclevel";
			rankArr[] = {"None", "1", "2", "3", "4", "5", "6", "7", "8"};
			class SubDivitions {
				class SAR {
					databaseIndex = "sarlevel";
					callCode = "life_sarlevel";
					rankArr[] = {"None", "Level 1", "Level 2", "Level 3", "Level 4", "Level 5"};
				};
				
			};	
		};

		class TPLA {
			whitelistLvlAccess = "call life_adminlevel >= 2 || call life_havoclevel >= 9";
			databaseIndex = "havoclevel";
			callCode = "life_havoclevel";
			rankArr[] = {"None", "Private", "Private First Class", "Grenadier", "Sergeant", "Master Sergeant", "Warrant Officer", "Lieutenant", "Commodore", "Commander", "Brigadier", "Lieutenant Commissioner", "Deputy High Commissioner", "High Commissioner"};
			class SubDivitions {
				class HSF {
					databaseIndex = "hsflevel";
					callCode = "life_hsflevel";
					rankArr[] = {"None", "Tier 1", "Tier 2", "Tier 3", "Commander"};
				};
				class AC {
					databaseIndex = "hadlevel";
					callCode = "life_hadlevel";
					rankArr[] = {"None", "Tier 1", "Tier 2", "Tier 3", "Commander"};
				};
				class WC {
					databaseIndex = "hmulevel";
					callCode = "life_hmulevel";
					rankArr[] = {"None", "Tier 1", "Tier 2", "Tier 3", "Commander"};
				};
				class UC {
					databaseIndex = "hsslevel";
					callCode = "life_hsslevel";
					rankArr[] = {"None", "Tier 1", "Tier 2", "Tier 3", "Commander"};
				};
			};
		};
		class Gov {
			whitelistLvlAccess = "call life_adminlevel >= 2";
			databaseIndex = "isso1";
			callCode = "life_isso1";
			rankArr[] = {"None","SO1 Officer"};
		};
	};
};
