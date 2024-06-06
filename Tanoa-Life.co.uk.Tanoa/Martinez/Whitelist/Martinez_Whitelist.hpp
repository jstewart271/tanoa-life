/*
	File: Martinez_Whitelist.hpp
	DialogHandle: WhitelistPanel
	Author: Martinezzz

	Copyright (c) 2023 Martinezzz, Martinezzz Development
	All Rights Reserved
*/

class WhitelistPanel {
    idd                             = 500002;
    name                            = "WhitelistPanel";
    movingEnable                    = 0;
    enableSimulation                = 1;
    onLoad                          = "['onLoad',   _this] call Martinez_fnc_displayWhitelist;";

    class ControlsBackground {
        class BACKGROUND: Martinez_ctrlStatic {
        	idc                     = -1;
			x 						= ((((532 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y 						= ((((322 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w 						= ((((852 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h 						= ((((431 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]       = {0.2, 0.2, 0.2, 1};
        };

        class FOOTER: Martinez_ctrlStatic {
			colorBackground[] = {0.15, 0.15, 0.15, 1};
			x = ((((532 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((752 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((852 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((32 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
		};

        class HEADER: Martinez_ctrlStatic {
        	idc                     = -1;
        	text                    = "Whitelist Panel";
            sizeEx 					= (17 * 1.33) * ((((getResolution select 1)) / 1080) * PixelH));
			x 						= ((((532 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y 						= ((((302 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w 						= ((((852 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h 						= ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
          	colorBackground[]       = {0.09,0.09,0.09,1};
        };
    };

    class Controls {
        class INPUT_SEARCH: Martinez_ctrlEdit {
        	idc                     = 50;
            x                       = ((((538 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y 						= ((((328 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w                       = ((((275 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h                       = ((((22 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]       = {0, 0, 0, 0.5};
        };

        class BUTTON_SEARCH: Martinez_ctrlButtonPictureKeepAspect {
        	idc                     = 61;
            text                    = "\a3\3den\data\displays\display3den\search_start_ca.paa";
            tooltip                 = "Search";
			x                       = ((((819 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y                       = ((((328 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w                       = ((((22 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h                       = ((((22 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]       = {0, 0, 0, 1};
            colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

        class LIVE_PLAYERS: Martinez_ctrlCombo {
        	idc                     = 67;
            x 						= ((((538 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y 						= ((((356 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w 						= ((((303 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h 						= ((((22 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]       = {0,0,0,0.5};
            colorSelect[]           = {0.05,0.05,0.05,1};
            colorSelectBackground[] = {0.95, 0.95, 0.95,1};
        };

        class CloseBtn: Martinez_ctrlButtonClose {
            idc                     = -1;
        	x 						= ((((1364 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y 						= ((((302 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w 						= ((((20 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h 						= ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
    	};

        class BUTTON_WHITELIST: Martinez_ctrlDefaultButton {
            idc                = 51;
            text               = "WHITELIST";
            sizeEx = (13 * 1.33) * ((((getResolution select 1)) / 1080) * PixelH));
			x = ((((1270 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((758 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((108 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]  = {0,0,0,1};
            colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

        class INFORMATION: Martinez_ctrlStructuredText {
            idc                = 52;
            text               = "";
            style              = 0x02;
            x 				   = ((((538 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y 				   = ((((384 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w 				   = ((((303 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h 				   = ((((362 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]       = {0,0,0,0.5};
        };

        class TYPE: Martinez_ctrlCombo {
        	idc                     = 53;
            x 						= ((((1004 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y 						= ((((356 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w 						= ((((211 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h 						= ((((22 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]       = {0,0,0,0.5};
            colorSelect[]           = {0.05,0.05,0.05,1};
            colorSelectBackground[] = {0.95, 0.95, 0.95,1};
        };

        class MAIN: Martinez_ctrlCombo {
        	idc                     = 54;
            x 						= ((((874 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y 						= ((((410 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w 						= ((((478 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h 						= ((((22 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]       = {0,0,0,0.5};
            colorSelect[]           = {0.05,0.05,0.05,1};
            colorSelectBackground[] = {0.95, 0.95, 0.95,1};
        };

        class SUB_ONE: Martinez_ctrlCombo {
        	idc                     = 55;
            x 						= ((((874 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y 						= ((((449 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w 						= ((((230 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h 						= ((((22 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]       = {0,0,0,0.5};
            colorSelect[]           = {0.05,0.05,0.05,1};
            colorSelectBackground[] = {0.95, 0.95, 0.95,1};
        };

        class SUB_TWO: Martinez_ctrlCombo {
        	idc                     = 56;
            x 						= ((((1122 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y 						= ((((449 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w 						= ((((230 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h 						= ((((22 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]       = {0,0,0,0.5};
            colorSelect[]           = {0.05,0.05,0.05,1};
            colorSelectBackground[] = {0.95, 0.95, 0.95,1};
        };

        class SUB_THREE: Martinez_ctrlCombo {
        	idc                     = 57;
            x 						= ((((874 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y 						= ((((488 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w 						= ((((230 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h 						= ((((22 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]       = {0,0,0,0.5};
            colorSelect[]           = {0.05,0.05,0.05,1};
            colorSelectBackground[] = {0.95, 0.95, 0.95,1};
        };

        class SUB_FOUR: Martinez_ctrlCombo {
        	idc                     = 58;
            x 						= ((((1122 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y 						= ((((488 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w 						= ((((230 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h 						= ((((22 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]       = {0,0,0,0.5};
            colorSelect[]           = {0.05,0.05,0.05,1};
            colorSelectBackground[] = {0.95, 0.95, 0.95,1};
        };

        class SUB_FIVE: Martinez_ctrlCombo {
        	idc                     = 59;
            x 						= ((((874 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y 						= ((((527 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w 						= ((((230 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h 						= ((((22 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]       = {0,0,0,0.5};
            colorSelect[]           = {0.05,0.05,0.05,1};
            colorSelectBackground[] = {0.95, 0.95, 0.95,1};
        };

        class SUB_SIX: Martinez_ctrlCombo {
        	idc                     = 60;
            x 						= ((((1122 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y 						= ((((527 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w 						= ((((230 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h 						= ((((22 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]       = {0,0,0,0.5};
            colorSelect[]           = {0.05,0.05,0.05,1};
            colorSelectBackground[] = {0.95, 0.95, 0.95,1};
        };

        class LISTBOX: Martinez_RscListBox {
        	idc                     = 68;
			x 						= ((((847 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y 						= ((((566 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w 						= ((((531 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h 						= ((((180 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            rowHeight 				= (10 * 1.33) * ((((getResolution select 1)) / 1080) * PixelH));
            colorBackground[]       = {0, 0, 0, 0.5};
            colorSelect[]           = {0.05,0.05,0.05,1};
            colorSelectBackground[] = {0.95, 0.95, 0.95,1};
        };
    };
};
