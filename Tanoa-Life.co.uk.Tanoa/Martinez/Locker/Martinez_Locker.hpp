/*
	File: Martinez_Locker.hpp
	DialogHandle: Martinez_Locker
	Author: Martinezzz

	Copyright (c) 2023 Martinezzz, Martinezzz Development
	All Rights Reserved
*/

class Martinez_Locker {
    idd = 500003;
    name = "Martinez_Locker";
    movingEnable = 0;
    enableSimulation = 1;

    onLoad = "['onLoad', _this] call Martinez_fnc_displayLocker;";
    onUnload = "['onUnload', _this] call Martinez_fnc_displayLocker;";

    class ControlsBackground {
        class BACKGROUND: Martinez_ctrlStatic {
        	idc                = 1;
			x = "((((648 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX)";
            y = "((((305 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY)";
            w = "((((624 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0))";
            h = "((((476 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1))";
        	colorBackground[]  = {0.2,0.2,0.2,1};
        };

		class FOOTER: Martinez_ctrlStatic {
            idc                 = 2;
			colorBackground[] = {0.15, 0.15, 0.15, 1};
			x = "((((648 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX)";
            y = "((((763 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY)";
            w = "((((624 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0))";
            h = "((((32 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1))";
		};

        class HEADER: Martinez_ctrlStatic {
        	idc                = 3;
        	text               = "Faction Locker - Tier 1";
			x = "((((648 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX)";
            y = "((((285 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY)";
            w = "((((624 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0))";
            h = "((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1))";
          	colorBackground[] = {0.09,0.09,0.09,1};
        };

        class BACKGROUNDUPGRADE: Martinez_ctrlStatic {
        	idc                = 14;
			x = "((((780 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX)";
            y = "((((522 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY)";
            w = "((((359 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0))";
            h = "((((37 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1))";
        	colorBackground[]  = {0.2,0.2,0.2,1};
		};

        class HEADERUPGRADE: Martinez_ctrlStatic {
        	idc                = 15;
        	text               = "Select what tier you want to upgrade to?";
			x = "((((780 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX)";
            y = "((((502 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY)";
            w = "((((359 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0))";
            h = "((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1))";
          	colorBackground[] = {0.09,0.09,0.09,1};
        };
    };
    class Controls {
        class BUTTON_TAKE: Martinez_ctrlButton {
            idc                = 4;
            text               = "TAKE";
            sizeEx = "(13 * 1.33) * ((((getResolution select 1)) / 1080) * PixelH))";
			x = "((((1044 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX)";
            y = "((((769 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY)";
            w = "((((108 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0))";
            h = "((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1))";
            colorBackground[]  = {0,0,0,1};
			colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

		class BUTTON_STORE: Martinez_ctrlButton {
            idc                = 5;
            text               = "STORE";
            sizeEx = "(13 * 1.33) * ((((getResolution select 1)) / 1080) * PixelH))";
			x = "((((1158 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX)";
            y = "((((769 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY)";
            w = "((((108 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0))";
            h = "((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1))";
            colorBackground[]  = {0,0,0,1};
			colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

        class INPUT_TEXT: Martinez_ctrlEdit {
        	idc                = 6;
            x = "((((654 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX)";
            y = "((((311 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY)";
            w = "((((303 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0))";
            h = "((((22 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1))";
        	colorBackground[]  = {0,0,0,0.4};
        };

        class CloseBtn: Martinez_ctrlButtonClose {
            idc                = 7;
        	x = "((((1252 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX)";
            y = "((((285 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY)";
            w = "((((20 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0))";
            h = "((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1))";
			colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
    	};

        class LOCKER_TREE_EQUIPMENT: Martinez_ctrlTree {
            idc                = 8;
            idcSearch          = 6;
            rowHeight          = 0.0639091;
            sizeEx             = (16 * 1.3) * ((((getResolution select 1)) / 1080) * PixelH));
			x = "((((654 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX)";
            y = "((((339 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY)";
            w = "((((303 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0))";
            h = "((((390 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1))";
            colorBackground[]  = {0,0,0,0.5};
            colorSearch[] = {0.2, 0.2, 0.2, 1};
            colorSelect[] = {0.2, 0.2, 0.2, 1};
            colorMarked[] = {0.2, 0.2, 0.2, 1};
            colorMarkedSelected[] = {0.2, 0.2, 0.2, 1};
        };

		class UNIT_TREE_EQUIPMENT: Martinez_ctrlTree {
            idc                = 9;
            rowHeight          = 0.0639091;
            sizeEx             = (16 * 1.3) * ((((getResolution select 1)) / 1080) * PixelH));
			x = "((((963 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX)";
            y = "((((339 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY)";
            w = "((((303 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0))";
            h = "((((390 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1))";
            colorBackground[]  = {0,0,0,0.5};
            colorSearch[] = {0.2, 0.2, 0.2, 1};
            colorSelect[] = {0.2, 0.2, 0.2, 1};
            colorMarked[] = {0.2, 0.2, 0.2, 1};
            colorMarkedSelected[] = {0.2, 0.2, 0.2, 1};
        };

        // class BUTTON_SEARCH_REFRESH: Martinez_ctrlButtonPictureKeepAspect {
        // 	idc                = 10;
        //     text               = "\a3\3DEN\Data\Cfg3DEN\History\rotateItems_ca.paa";
        //     tooltip            = "Refresh List";
		// 	x = "((((935 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX)";
        //     y = "((((311 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY)";
        //     w = "((((22 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0))";
        //     h = "((((22 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1))";
        //     colorBackground[]  = {0,0,0,1};
		// 	colorBackgroundActive[] = {0.2, 0.2, 0.2, 1};
		// 	colorFocused[] = {0.2, 0.2, 0.2, 1};
        // };

        class BUTTON_HEADER_UPGRADE: Martinez_ctrlButtonPictureKeepAspect {
        	idc                = 11;
            text               = "a3\modules_f\data\iconunlock_ca.paa";
            tooltip            = "Upgrade Locker";
			x = "((((1230 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX)";
            y = "((((285 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY)";
            w = "((((20 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0))";
            h = "((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1))";
            colorBackground[]  = {0,0,0,1};
			colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
            colorBackgroundDisabled[] = {0.1, 0.1, 0.1, 1};
        };

        class ProgressBarLockerPhysical: Life_RscProgress {
            idc = 18;
            x 				   = "((((654 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);";
            y 				   = "((((735 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);";
            w 				   = "((((303 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));";
            h 				   = "((((22 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));";
			colorBar[] = {0, 0, 0, 0.5};
			colorFrame[] = {0, 0, 0, 0.4};
        };
        
        class LockerPhysical: Martinez_ctrlStructuredText {
            idc                = 12;
            text               = "";
            style              = 0x02;
            x 				   = "((((654 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);";
            y 				   = "((((735 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);";
            w 				   = "((((303 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));";
            h 				   = "((((22 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));";
            colorBackground[]       = {0,0,0,0};
        };

        class ProgressBarLockerVirutal: Life_RscProgress {
            idc = 19;
            x 				   = "((((963 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);";
            y 				   = "((((735 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);";
            w 				   = "((((303 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));";
            h 				   = "((((22 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));";
			colorBar[] = {0, 0, 0, 0.5};
			colorFrame[] = {0, 0, 0, 0.4};
        };

        class LockerVirutal: Martinez_ctrlStructuredText {
            idc                = 13;
            text               = "";
            style              = 0x02;
            x 				   = "((((963 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);";
            y 				   = "((((735 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);";
            w 				   = "((((303 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));";
            h 				   = "((((22 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));";
            colorBackground[]       = {0,0,0,0};
        };

        class BUTTON_UPGRADE: Martinez_ctrlButton {
            idc                = 16;
            text               = "UPGRADE";
            sizeEx = "(13 * 1.33) * ((((getResolution select 1)) / 1080) * PixelH))";
			x = "((((780 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX)";
            y = "((((559 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY)";
            w = "((((359 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0))";
            h = "((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1))";
            colorBackground[]  = {0,0,0,1};
            colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

        class COMBO: Martinez_ctrlCombo {
        	idc                = 17;
            x = "((((786 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX)";
            y = "((((528 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY)";
            w = "((((347 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0))";
            h = "((((25 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1))";
        	colorBackground[]       = {0, 0, 0, 0.5};
            colorSelect[]           = {0.05, 0.05, 0.05, 1};
            colorSelectBackground[] = {0.95, 0.95, 0.95, 1};
        };

        class INPUT_AMOUNT: Martinez_ctrlEdit {
        	idc                = 20;
            text               = "1";
            x = "((((654 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX)";
            y = "((((768 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY)";
            w = "((((121 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0))";
            h = "((((22 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1))";
        	colorBackground[]  = {0, 0, 0, 0.25};
        };

    };
};
