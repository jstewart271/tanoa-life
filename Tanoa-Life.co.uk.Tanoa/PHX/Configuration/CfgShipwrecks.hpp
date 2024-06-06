class CfgShipwrecks {

    shipwreckInterval = 1800;

	positions[] = {
        {652.404,13749,0},
        {3561.32,10390.9,0},
        {3803.72,5198.67,0},
        {7747.1,1476.51,0},
        {14242,6401.92,0},
        {13115.5,13312.7,0},
        {6965.83,14155,0},
        {5210.22,13708.5,0}
	};

    //Define the radius, in which the wreck randomly spawns around the given center position
    Radius = 26;

    //Define the possible sets of virtual items the user can loot from the wreck.
	shipLoot[] = {
        {"hackingdevice","fuelFull","chest","tbacon","lockpick","apple"},
        {"chest","chest","chest"},
        {"tbacon","lockpick","antique","tbacon","apple","apple"},
        {"tbacon","lockpick","antique","tbacon","apple","apple"},
        {"tbacon","lockpick","antique","tbacon","apple","apple"},
        {"tbacon","lockpick","antique","tbacon","apple","apple"},
        {"tbacon","lockpick","antique","tbacon","apple","apple"},
        {"chest","tbacon","antique","hackingdevice","apple","lockpick"},
        {"tbacon","fuelFull","antique","tbacon","apple","apple"},
        {"tbacon","antique","tbacon","antique","zipties","antique","fuelFull","lockpick","chest","hackingdevice","tbacon"},
        {"chest","antique","antique","antique","chest","antique","antique","antique","antique","chest"}
	};
};