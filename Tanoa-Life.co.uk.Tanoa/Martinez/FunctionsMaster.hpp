class Martinez {
    tag = "Martinez";

    class ClothingStore {
        file = "Martinez\Clothing\Functions";
        class clothingCamera {};
        class createClothingCharacter {};
        class displayClothingStore {};
		class openClothingStore {};
    };

    class Faction {
        file = "Martinez\Faction";
        class signOn {};
        class signOff {};
    };

    class Loadouts {
        file = "Martinez\Loadouts\Functions";
        class createLoadout {};
        class createLoadoutCharacter {};
        class displayLoadoutSelector {};
		class flattenLoadoutArray {};
        class getAllowedLoadoutGear {};
        class getLoadoutPrice {};
        class loadoutCamera {};
        class loadoutsLoad {};
        class openLoadouts {};
        class validLoadout {};
    };

    class Locker {
        file = "Martinez\Locker\Functions";
        class buyLocker {};
        class displayLocker {};
        class getPhysicalItemMass {};
		class loadLocker {};
        class openLocker {};
        class removeItem {};
    };

    class Whitelist {
        file = "Martinez\Whitelist\Functions";
        class canWhitelist {};
        class displayWhitelist {};
    };
};