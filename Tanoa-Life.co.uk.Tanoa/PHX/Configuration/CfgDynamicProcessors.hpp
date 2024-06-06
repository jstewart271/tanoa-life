/*
	File: CfgDynamicProcessors.hpp
	Author: Demolition

	Copyright (c) 2023 Demolition, Demolition Development Services
	All Rights Reserved
*/

class CfgDynamicProcessors {
    class uranium {
        markerColour = "colorOPFOR";
        markerName = "Uranium Processing";
        markerIcon = "mil_box";
        positions[] = { // {{Marker Position}, {Object Position}, Object Dir}
            {{9014.62,13799.8}, {9014.62,13799.8}, 0.300036 , 91.048},
            {{6610.36,13450.6}, {6610.36,13450.6}, 1.535, 102.416},
            {{5163.29,9976.19}, {5163.29,9976.19}, 0, 90}
        };
    };

    class diamond {
        markerColour = "colorCivilian";
        markerName = "Diamond Processing";
        markerIcon = "mil_box";
        positions[] = { // {{Marker Position}, {Object Position}, Object Dir}
            {{4201.44,8450.85}, {4201.44,8450.85}, 0, 181.115},
            {{5163,8656.26}, {5163,8656.26}, 0.0550547,181.115},
            {{8582.78,7734.69}, {8582.78,7734.69}, 0,181.115}
        };
    };

    class weapon {
        markerColour = "colorOPFOR";
        markerName = "Weapon Parts Processing";
        markerIcon = "mil_box";
        positions[] = { // {{Marker Position}, {Object Position}, Object Dir}
            {{11375.4,2278,0}, {11375.4,2278,0},0.686,187.163},
            {{12872.8,4858.37}, {12872.8,4858.37},0 ,324.403}, 
            {{12662.4,6646.5}, {12662.4,6646.5}, 0,346.455}
        };
    };

    class weed {
        markerColour = "colorOPFOR";
        markerName = "Weed Processing";
        markerIcon = "mil_box";
        positions[] = { // {{Marker Position}, {Object Position}, Object Dir}
            {{7923.62,12421}, {7923.62,12421},0.210327 ,129.964},
            {{8228.46,11071.4}, {8228.46,11071.4}, 0.670616,35.857},
            {{6474.08,11230.7}, {6474.08,11230.7},0.072 ,356.352}
        };
    };
    
    class cocaine {
        markerColour = "colorOPFOR";
        markerName = "Cocaine Processing";
        markerIcon = "mil_box";
        positions[] = { // {{Marker Position}, {Object Position}, Object Dir}
            {{10307.1,6795.01}, {10307.1,6795.01}, 0,79.284}, // [,0]
            {{11309.9,6729.84}, {11309.9,6729.84}, 0.636,94.344},
            {{9933.05,6732.44}, {9933.05,6732.44},0 ,94.344}
        };
    };

    class ecstasy {
        markerColour = "colorOPFOR";
        markerName = "Ecstasy Processing";
        markerIcon = "mil_box";
        positions[] = { // {{Marker Position}, {Object Position}, Object Dir}
            {{9160.86,8735.75}, {9160.86,8735.75}, 0.0665283,265.201},
            {{9981.75,9326.49}, {9981.75,9326.49},0.35379 ,302.353},
            {{10969.3,9698.38}, {10969.3,9698.38},0 ,302.353}
        };
    };

    class moonshine {
        markerColour = "colorOPFOR";
        markerName = "Moonshine Processing";
        markerIcon = "mil_box";
        positions[] = { // {{Marker Position}, {Object Position}, Object Dir}
            {{7874.24,13554}, {7874.24,13554},0 ,244.546},
            {{10366.7,13229.5}, {10366.7,13229.5}, 0.562798,71.865},
            {{12800.8,12526.6}, {12800.8,12526.6}, 0.440724,71.865}
        };
    }
};