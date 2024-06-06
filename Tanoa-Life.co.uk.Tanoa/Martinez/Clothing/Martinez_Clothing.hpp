/*
	File: Martinez_Clothing.hpp
	DialogHandle: Martinez_ClothingStore
	Author: Martinezzz

	Copyright (c) 2022 Martinezzz, Martinezzz Development
	All Rights Reserved
*/

class Martinez_ClothingStore {
    idd = 500000;
    name = "Martinez_ClothingStore";
    movingEnable = 0;
    enableSimulation = 1;

    onLoad = "['onLoad', _this] call Martinez_fnc_displayClothingStore;";
    onUnload = "['onUnload', _this] call Martinez_fnc_displayClothingStore;";

    class ControlsBackground {
        class BACKGROUND: Martinez_ctrlStatic {
        	idc                = -1;
			x = ((((15 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((235 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((420 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((598 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]  = {0.2,0.2,0.2,1};
        };

		class FOOTER: Martinez_ctrlStatic {
			colorBackground[] = {0.15, 0.15, 0.15, 1};
			x = ((((15 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((833 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((420 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((32 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
		};

        class HEADER: Martinez_ctrlStatic {
        	idc                = -1;
        	text               = "Clothing Store";
			x = ((((15 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((215 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((420 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
          	colorBackground[] = {0.09,0.09,0.09,1};
        };

		class TITLE_PRICE: Martinez_ctrlStatic {
        	idc                = -1;
        	text               = "PRICE:";
            style              = 0x02;
			x = ((((22 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((780 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((98 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]  = {0,0,0,0.5};
        };

        class TITLE_TOTALPRICE: Martinez_ctrlStatic {
        	idc                = -1;
        	text               = "TOTAL PRICE:";
            style              = 0x02;
			x = ((((22 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((806 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((98 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]  = {0,0,0,0.5};
        };

    };
    class Controls {
        class CloseBtn: Martinez_ctrlButtonClose {
        	x = ((((411 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((215 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((24 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
    	    colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

        class BUTTON_PURCHASE: Martinez_ctrlDefaultButton {
            idc                = 1;
            text               = "PURCHASE";
            sizeEx = (13 * 1.33) * ((((getResolution select 1)) / 1080) * PixelH));
			x = ((((320 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((839 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((108 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]  = {0,0,0,1};
            colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

        class BUTTON_UNIFORM: Martinez_ctrlButtonPictureKeepAspect {
            idc                = 3;
            text               = "a3\ui_f\data\gui\rsc\rscdisplayarsenal\uniform_ca.paa";
            tooltip            = "Uniforms";
            sizeEx = (13 * 1.33) * ((((getResolution select 1)) / 1080) * PixelH));
			x = ((((22 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((241 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((76 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]  = {0,0,0,0.5};
            colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

        class BUTTON_VEST: Martinez_ctrlButtonPictureKeepAspect {
            idc                = 4;
            text               = "a3\ui_f\data\gui\rsc\rscdisplayarsenal\vest_ca.paa";
            tooltip            = "Vests";
            sizeEx = (13 * 1.33) * ((((getResolution select 1)) / 1080) * PixelH));
			x = ((((104 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((241 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((77 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]  = {0,0,0,0.5};
            colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

        class BUTTON_BACKPACK: Martinez_ctrlButtonPictureKeepAspect {
            idc                = 5;
            text               = "a3\ui_f\data\gui\rsc\rscdisplayarsenal\backpack_ca.paa";
            tooltip            = "Backpacks";
            sizeEx = (13 * 1.33) * ((((getResolution select 1)) / 1080) * PixelH));
			x = ((((187 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((241 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((76 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]  = {0,0,0,0.5};
            colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

        class BUTTON_HEADGEAR: Martinez_ctrlButtonPictureKeepAspect {
            idc                = 6;
            text               = "a3\ui_f\data\gui\rsc\rscdisplayarsenal\headgear_ca.paa";
            tooltip            = "Headgear";
            sizeEx = (13 * 1.33) * ((((getResolution select 1)) / 1080) * PixelH));
			x = ((((269 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((241 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((77 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]  = {0,0,0,0.5};
            colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

        class BUTTON_GOGGLES: Martinez_ctrlButtonPictureKeepAspect {
            idc                = 7;
            text               = "a3\ui_f\data\gui\rsc\rscdisplayarsenal\goggles_ca.paa";
            tooltip            = "Goggles";
            sizeEx = (13 * 1.33) * ((((getResolution select 1)) / 1080) * PixelH));
			x = ((((352 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((241 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((76 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]  = {0,0,0,0.5};
            colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

        class TREE_EQUIPMENT: Martinez_ctrlTree {
            idc                = 8;
            idcSearch          = 9;
            sizeEx             = (17 * 1.33) * ((((getResolution select 1)) / 1080) * PixelH));
			x = ((((22 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((293 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((406 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((481 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]       = {0,0,0,0.5};
            colorSelect[]           = {0.95, 0.95, 0.95,1};
            colorSelectText[] = {0.05,0.05,0.05,1};
        };

        class INPUT_SEARCH: Martinez_ctrlEdit {
        	idc                = 9;
            x = ((((48 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((267 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((380 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
        	colorBackground[]  = {0,0,0,0.4};
        };

        class BUTTON_SEARCH_REFRESH: Martinez_ctrlButtonPictureKeepAspect {
        	idc                = 10;
            text               = "\a3\3DEN\Data\Cfg3DEN\History\rotateItems_ca.paa";
            tooltip            = "Refresh List";
			x = ((((22 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((267 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((24 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]  = {0,0,0,1};
            colorBackgroundActive[] = {0.5, 0.5, 0.5,1};
            colorFocused[]          = {0.5, 0.5, 0.5,1};
        };

        class TEXT_PRICE: Martinez_ctrlStatic {
            idc                = 11;
            text               = "";
            style              = 0x02;
			x = ((((127 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((780 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((301 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]  = {0,0,0,0.5};
        };

        class TEXT_TOTALPRICE: Martinez_ctrlStatic {
            idc                = 12;
            text               = "";
            style              = 0x02;
			x = ((((127 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX);
            y = ((((806 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY);
            w = ((((301 * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0));
            h = ((((20 * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
            colorBackground[]  = {0,0,0,0.5};
        };
    };
};
