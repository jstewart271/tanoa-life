#define true 1
#define false 0

class CfgHousing {
	class Altis {
		blacklistedHousing[] = {
            {"Land_i_Shed_Ind_F",{9436.99,7580.84,0}},
        }; // POS of "Blacklisted" Housing

        class Land_i_Garage_V1_F {
            price = 500000;
            rent = 6000; // Up keep... (£252,000 Weekly)
            storage = 0;
            isGarage = true;
			garageSettings[] = {{-11.5,0,0}, -90}; // POS, DIR
            lightPos[] = {2,0,3.5};
			restrictedPos[] = {0,1,2,3,4}; // All positions we won't spawn at...
        };

        class Land_i_Garage_V2_F : Land_i_Garage_V1_F {};

        class Land_i_Stone_Shed_V1_F {
            price = 2500000;
            rent = 5000; // Up keep... (£210,000 Weekly)
            storage = 2;
            isGarage = false;
			garageSettings[] = {{0,0,0}, 0}; // POS, DIR
            lightPos[] = {2,0,3.5};
			restrictedPos[] = {0,1,2,3,4}; // All positions we won't spawn at...
        };
        class Land_i_Stone_Shed_V2_F : Land_i_Stone_Shed_V1_F {};
        class Land_i_Stone_Shed_V3_F : Land_i_Stone_Shed_V1_F {};

        class Land_i_Stone_HouseSmall_V1_F { //  	Stone House (Grey)
            price = 5000000;
            rent = 5000; // Up keep... (£210,000 Weekly)
            storage = 2;
            isGarage = false;
			garageSettings[] = {{0,0,0}, 0}; // POS, DIR
            lightPos[] = {2,0,3.5};
			restrictedPos[] = {0,1,3,4}; // All positions we won't spawn at...
        };
        class Land_i_Stone_HouseSmall_V2_F : Land_i_Stone_HouseSmall_V1_F {};
        class Land_i_Stone_HouseSmall_V3_F : Land_i_Stone_HouseSmall_V1_F {};

		class Land_i_House_Big_01_V1_F {
            price = 2200000;
            rent = 30000; // Up keep... (£1,260,000 Weekly)
            storage = 5;
            isGarage = false;
			garageSettings[] = {{0,0,0}, 0}; // POS, DIR
            lightPos[] = {0,-2,3.8};
			restrictedPos[] = {2,3}; // All positions we won't spawn at...
        };
        class Land_i_House_Big_01_V2_F : Land_i_House_Big_01_V1_F {};
        class Land_i_House_Big_01_V3_F : Land_i_House_Big_01_V1_F {};

        class Land_i_Shed_Ind_F {
            price = 5000000;
            rent = 50000; // Up keep... (£2,100,000 Weekly)
            storage = 10;
            isGarage = false;
			garageSettings[] = {{-18.5,0,0}, 0}; // POS, DIR
            lightPos[] = {-3.3,1,2.5};
			restrictedPos[] = {0,1,2,3,4}; // All positions we won't spawn at...
        };
	};

    class Tanoa {
        blacklistedHousing[] = {
            {"Land_i_Shed_Ind_F",{9436.99,7580.84,0}}, // Uranium Trader
            {"Land_i_Shed_Ind_F",{7470.93,8517.27,0}}, // Silver Processing
            {"Land_i_Shed_Ind_F",{9014.31,13803.3,0}}, // Uranium Processing
            {"Land_i_Shed_Ind_F",{11253.6,5398.98,0}}, // Silicon Processing
        };
        class Land_House_Small_04_F { // Bungalow (Blue Roof)
            price = 5000000;
            rent = 50000; // Up keep... (£2,100,000 Weekly)
            storage = 2;
            isGarage = false;
			garageSettings[] = {{-18.5,0,0}, 0}; // POS, DIR
            lightPos[] = {-3.3,1,2.5};
			restrictedPos[] = {0,1,2,3,4}; // All positions we won't spawn at...
        }
        class Land_House_Small_05_F : Land_House_Small_04_F {};
        class Land_House_Small_03_F { // Bungalow (Turquoise)
            price = 5000000;
            rent = 50000; // Up keep... (£2,100,000 Weekly)
            storage = 2;
            isGarage = false;
			garageSettings[] = {{-18.5,0,0}, 0}; // POS, DIR
            lightPos[] = {-3.3,1,2.5};
			restrictedPos[] = {0,1,2,3,4}; // All positions we won't spawn at...
        }
        class Land_House_Small_06_F { //Bungalow (Yellow)
            price = 5000000;
            rent = 50000; // Up keep... (£2,100,000 Weekly)
            storage = 2;
            isGarage = false;
			garageSettings[] = {{-18.5,0,0}, 0}; // POS, DIR
            lightPos[] = {-3.3,1,2.5};
			restrictedPos[] = {0,1,2,3,4}; // All positions we won't spawn at...
        }
        class Land_House_Big_01_F { // Bungalow (Yellow, Large)
            price = 12500000;
            rent = 30000; // Up keep... (£1,260,000 Weekly)
            storage = 5;
            isGarage = false;
			garageSettings[] = {{0,0,0}, 0}; // POS, DIR
            lightPos[] = {0,-2,3.8};
			restrictedPos[] = {2,3}; // All positions we won't spawn at...
        }
        class Land_i_Garage_V1_F { // Garage (New)
            price = 2500000;
            rent = 6000; // Up keep... (£252,000 Weekly)
            storage = 0;
            isGarage = true;
			garageSettings[] = {{-11.5,0,0}, -90}; // POS, DIR
            lightPos[] = {2,0,3.5};
			restrictedPos[] = {0,1,2,3,4}; // All positions we won't spawn at...
        };

        class Land_i_Garage_V2_F : Land_i_Garage_V1_F {};

        class Land_i_Stone_HouseSmall_V1_F {
            price = 750000;
            rent = 5000; // Up keep... (£210,000 Weekly)
            storage = 2;
            isGarage = false;
			garageSettings[] = {{0,0,0}, 0}; // POS, DIR
            lightPos[] = {2,0,3.5};
			restrictedPos[] = {0,1,3,4}; // All positions we won't spawn at...
        };
        class Land_i_Stone_HouseSmall_V2_F : Land_i_Stone_HouseSmall_V1_F {};
        class Land_i_Stone_HouseSmall_V3_F : Land_i_Stone_HouseSmall_V1_F {};

        class Land_i_Shed_Ind_F { // Industrial Shed
            price = 25000000;
            rent = 50000; // Up keep... (£2,100,000 Weekly)
            storage = 6;
            isGarage = false;
			garageSettings[] = {{-18.5,0,0}, 0}; // POS, DIR
            lightPos[] = {-3.3,1,2.5};
			restrictedPos[] = {0,1,2,3,4}; // All positions we won't spawn at...
        };

        class Land_Slum_03_F { //  	Purple Shack (Large)
            price = 7500000;
            rent = 50000; // Up keep... (£2,100,000 Weekly)
            storage = 3;
            isGarage = false;
			garageSettings[] = {{-18.5,0,0}, 0}; // POS, DIR
            lightPos[] = {-3.3,1,2.5};
			restrictedPos[] = {0,1,2,3,4}; // All positions we won't spawn at...
        };

        class Land_House_Small_02_F { //  	Brick Bungalow
            price = 5000000;
            rent = 50000; // Up keep... (£2,100,000 Weekly)
            storage = 2;
            isGarage = false;
			garageSettings[] = {{-18.5,0,0}, 0}; // POS, DIR
            lightPos[] = {-3.3,1,2.5};
			restrictedPos[] = {}; // All positions we won't spawn at...
        };
        class Land_House_Big_02_F { // Bungalow (Large)
            price = 10000000;
            rent = 50000; // Up keep... (£2,100,000 Weekly)
            storage = 4;
            isGarage = false;
			garageSettings[] = {{-18.5,0,0}, 0}; // POS, DIR
            lightPos[] = {-3.3,1,2.5};
			restrictedPos[] = {9}; // All positions we won't spawn at...
        };

        class Land_Shed_04_F {
            price = 2500000;
            rent = 30000; // Up keep... (£2,100,000 Weekly)
            storage = 1;
            isGarage = false;
			garageSettings[] = {{-18.5,0,0}, 0}; // POS, DIR
            lightPos[] = {-3.3,1,2.5};
			restrictedPos[] = {9}; // All positions we won't spawn at...
        };
        
    };
};


