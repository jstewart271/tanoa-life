class RscPhyscialStore {
	idd = 38400;
	name = "RscPhyscialStore";
  	onLoad = "";

    class ControlsBackground {
        class Background : Life_RscBackground {
            idc = -1;
            colorBackground[] = {0.16,0.16,0.16,1};
            x = 0.407188 * safezoneW + safezoneX;
            y = 0.247 * safezoneH + safezoneY;
            w = 0.185625 * safezoneW;
            h = 0.506 * safezoneH;
        };

        class HeaderBackground : Life_RscBackground {
            idc = -1;
            moving = true; // Allows it to be dragged around
            colorBackground[] = {0.09,0.09,0.09,1};
            x = 0.407188 * safezoneW + safezoneX;
            y = 0.247 * safezoneH + safezoneY;
            w = 0.185625 * safezoneW;
            h = 0.022 * safezoneH;
        };

        class FooterBackground : Life_RscBackground {
            idc = -1;
            colorBackground[] = {0.102,0.102,0.102,1};
            x = 0.407188 * safezoneW + safezoneX;
            y = 0.72 * safezoneH + safezoneY;
            w = 0.185625 * safezoneW;
            h = 0.033 * safezoneH;
        };

		class Line : Life_RscText{
			idc = -1;
			x = 0.407188 * safezoneW + safezoneX;
            y = 0.72 * safezoneH + safezoneY;
			w = 0.185625 * safezoneW;
			h = safeZoneH * 0.00133334;
			colorBackground[] = {0,0,0,1};
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
		};

        class PageTitle : Life_RscText {
            idc = 38401;
            text = "Store Title";
            x = 0.407188 * safezoneW + safezoneX;
            y = 0.247 * safezoneH + safezoneY;
            w = 0.12375 * safezoneW;
            h = 0.022 * safezoneH;
        };

        class PriceBackground : Life_RscBackground {
            idc = -1;
            colorBackground[] = {0.09,0.09,0.09,1};
           	x = 0.412344 * safezoneW + safezoneX;
            y = 0.654 * safezoneH + safezoneY;
            w = 0.154687 * safezoneW;
            h = 0.022 * safezoneH;
        };

        class FilterBackground : Life_RscBackground {
            idc = -1;
            colorBackground[] = {0.09,0.09,0.09,1};
           	x = 0.412344 * safezoneW + safezoneX;
            y = 0.687 * safezoneH + safezoneY;
            w = 0.154687 * safezoneW;
            h = 0.022 * safezoneH;
        };
    };

    class Controls {
		class CloseButton : Life_RscButtonMenuIcon {
			onButtonClick = "closeDialog 0;";
			idc = -1;
			x = 0.577344 * safezoneW + safezoneX;
            y = 0.247 * safezoneH + safezoneY;
            w = 0.0154688 * safezoneW;
            h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
			tooltip = "Return"; 
			text = "a3\ui_f\data\gui\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

        class ListBox : Life_RscListBox {
            idc = 38403;
            x = safeZoneX + safeZoneW * 0.412344;
            y = safeZoneY + safeZoneH * 0.28;
            w = safeZoneW * 0.175313;
            h = safeZoneH * 0.363;
            color[] = {0.09,0.09,0.09,1};
			colorBackground[] = {0.09,0.09,0.09,1};
			colorText[] = {1,1,1,1};
			font = "PuristaLight";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			rowHeight = 0.1;
			soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1.0};
            onLBSelChanged = "_this call life_fnc_weaponShopSelection";
        };

        class PriceText : Life_RscStructuredText {
            idc = 38404;
            text = "Select an item above...";
            x = 0.412343 * safezoneW + safezoneX;
            y = 0.654 * safezoneH + safezoneY;
            w = 0.154687 * safezoneW;
            h = 0.022 * safezoneH;
        };

		class MagButton : Life_RscButtonMenuIcon {
			idc = 38406;
            onButtonClick = "_this call life_fnc_weaponShopMags; _this call life_fnc_weaponShopFilter";
			x = 0.572187 * safezoneW + safezoneX;
            y = 0.654 * safezoneH + safezoneY;
            w = 0.0154688 * safezoneW;
            h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {-1,-1,-1,0.9};
			text = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\cargoMagAll_ca.paa";
		};

		class AccButton : Life_RscButtonMenuIcon {
			idc = 38407;
            onButtonClick = "_this call life_fnc_weaponShopAccs; _this call life_fnc_weaponShopFilter";
			x = 0.572187 * safezoneW + safezoneX;
            y = 0.687 * safezoneH + safezoneY;
            w = 0.0154688 * safezoneW;
            h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {-1,-1,-1,0.9};
			text = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemAcc_ca.paa";
		};

		class BuySellButton : Life_RscButtonMenu {
			idc = 38405;
			x = safeZoneX + safeZoneW * 0.515469;
			y = safeZoneY + safeZoneH * 0.726;
			w = safeZoneW * 0.0721875;
			h = safeZoneH * 0.022;
			text = "Buy";
			onButtonClick = "[] spawn life_fnc_weaponShopBuySell; true";
			borderSize = 0;
			colorBackground[] = {0.09,0.09,0.09,1};
			colorText[] = {1,1,1,1};
			font = "PuristaLight";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
		};

		class FilterList: Life_RscCombo {
            idc = 38402;
            onLBSelChanged = "_this call life_fnc_weaponShopFilter";
			colorBackground[] = {0.09,0.09,0.09,1};
           	x = 0.412344 * safezoneW + safezoneX;
            y = 0.687 * safezoneH + safezoneY;
            w = 0.154687 * safezoneW;
            h = 0.022 * safezoneH;
        };
    };
};