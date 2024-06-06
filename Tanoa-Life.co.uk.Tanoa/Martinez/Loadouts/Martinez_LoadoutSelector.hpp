/*
	File: LoadoutSelector.hpp
	DialogHandle: Martinez_Loadouts
	Author: Martinezzz

	Copyright (c) 2022 Martinezzz, Martinezzz Development
	All Rights Reserved
*/

class Martinez_Loadouts {
    idd = 500001;
    name = "Martinez_Loadouts";
    movingEnable = 0;
    enableSimulation = 1;

    onLoad = "['onLoad', _this] call Martinez_fnc_displayLoadoutSelector;";
    onUnload = "['onUnload', _this] call Martinez_fnc_displayLoadoutSelector;";

    class ControlsBackground {
        class BACKGROUND: Martinez_ctrlStatic {
        	idc                = 1;
			x = ((((14 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((262 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((420 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((545 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]  = {0.2,0.2,0.2,1};
        };

		class FOOTER: Martinez_ctrlStatic {
            idc                 = 2;
			colorBackground[] = {0.15, 0.15, 0.15, 1};
			x = ((((14 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((807 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((420 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((32 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
		};

        class HEADER: Martinez_ctrlStatic {
        	idc                = 3;
        	text               = "Loadout Selector";
			x = ((((14 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((242 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((420 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
          	colorBackground[] = {0.09,0.09,0.09,1};
        };

		class TITLE_PRICE: Martinez_ctrlStatic {
        	idc                = 4;
        	text               = "PRICE:";
            style              = 0x02;
			x = ((((21 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((781 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((99 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]  = {0,0,0,0.5};
        };

        class BACKGROUNDCREATE: Martinez_ctrlStatic {
        	idc                = 13;
			x = ((((780 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((522 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((359 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((37 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]  = {0.2,0.2,0.2,1};
		};

        class HEADERCREATE: Martinez_ctrlStatic {
        	idc                = 14;
        	text               = "Create a name for your loadout!";
			x = ((((780 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((502 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((359 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
          	colorBackground[] = {0.09,0.09,0.09,1};
        };
    };
    class Controls {
        class BUTTON_CREATESUB: Martinez_ctrlButton {
            idc                = 15;
            text               = "CREATE";
            sizeEx = "(13 * 1.33) * ((((getResolution select 1)) / 1080) * PixelH))";
			x = ((((780 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((559 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((359 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]  = {0,0,0,1};
            colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

        class INPUT_NAMECREATE: Martinez_ctrlEdit {
        	idc                = 16;
            x = ((((786 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((528 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((347 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((25 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]  = {0,0,0,0.4};
        };

        class CloseBtn: Martinez_ctrlButtonClose {
            idc                = 5;
        	x = ((((414 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((242 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((20 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
    	    colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

        class BUTTON_PURCHASE: Martinez_ctrlDefaultButton {
            idc                = 6;
            text               = "PURCHASE";
            sizeEx = "(13 * 1.33) * ((((getResolution select 1)) / 1080) * PixelH))";
			x = ((((297 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((813 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((132 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]  = {0,0,0,1};
            colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

		class BUTTON_DELETE: Martinez_ctrlDefaultButton {
            idc                = 7;
            text               = "DELETE";
            sizeEx = "(13 * 1.33) * ((((getResolution select 1)) / 1080) * PixelH))";
			x = ((((159 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((813 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((132 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]  = {0,0,0,1};
            colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

		class BUTTON_CREATE: Martinez_ctrlDefaultButton {
            idc                = 8;
            text               = "CREATE";
            sizeEx = "(13 * 1.33) * ((((getResolution select 1)) / 1080) * PixelH))";
			x = ((((21 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((813 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((132 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]  = {0,0,0,1};
            colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

        class TREE_EQUIPMENT: Martinez_ctrlTree {
            idc                = 9;
            idcSearch          = 10;
            rowHeight          = 0.0639091;
            sizeEx             = (16 * 1.3) * ((((getResolution select 1)) / 1080) * PixelH));
			x = ((((20 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((294 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((408 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((481 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]       = {0, 0, 0, 0.5};
            colorSelect[]           = {0.95, 0.95, 0.95,1};
            colorSelectText[]       = {0.05, 0.05, 0.05, 1};
        };

        class INPUT_SEARCH: Martinez_ctrlEdit {
        	idc                = 10;
            x = ((((53 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((268 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((375 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]  = {0,0,0,0.4};
        };

        class BUTTON_SEARCH_REFRESH: Martinez_ctrlButtonPictureKeepAspect {
        	idc                = 11;
            text               = "\a3\3DEN\Data\Cfg3DEN\History\rotateItems_ca.paa";
            tooltip            = "Refresh List";
			x = ((((20 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((268 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((28 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]  = {0,0,0,1};
            colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

        class TEXT_PRICE: Martinez_ctrlStatic {
            idc                = 12;
            text               = "";
            style              = 0x02;
			x = ((((126 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((781 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((302 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]  = {0,0,0,0.5};
        };
    };
};
