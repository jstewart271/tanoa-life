#define CT_STATIC           0
#define CT_BUTTON           1
#define CT_EDIT             2
#define CT_SLIDER           3
#define CT_COMBO            4
#define CT_LISTBOX          5
#define CT_TOOLBOX          6
#define CT_CHECKBOXES       7
#define CT_PROGRESS         8
#define CT_HTML             9
#define CT_STATIC_SKEW      10
#define CT_ACTIVETEXT       11
#define CT_TREE             12
#define CT_STRUCTURED_TEXT  13
#define CT_CONTEXT_MENU     14
#define CT_CONTROLS_GROUP   15
#define CT_SHORTCUTBUTTON   16
#define CT_XKEYDESC         40
#define CT_XBUTTON          41
#define CT_XLISTBOX         42
#define CT_XSLIDER          43
#define CT_XCOMBO           44
#define CT_ANIMATED_TEXTURE 45
#define CT_MENU             46 // Arma 3 (EDEN)
#define CT_MENU_STRIP       47 // Arma 3 (EDEN)
#define CT_CHECKBOX         77 // Arma 3
#define CT_OBJECT           80
#define CT_OBJECT_ZOOM      81
#define CT_OBJECT_CONTAINER 82
#define CT_OBJECT_CONT_ANIM 83
#define CT_LINEBREAK        98
#define CT_ANIMATED_USER    99
#define CT_MAP              100
#define CT_MAP_MAIN         101
#define CT_LISTNBOX         102
#define CT_ITEMSLOT         103

#define ST_POS            0x0F
#define ST_HPOS           0x03
#define ST_VPOS           0x0C
#define ST_LEFT           0x00
#define ST_RIGHT          0x01
#define ST_CENTER         0x02
#define ST_DOWN           0x04
#define ST_UP             0x08
#define ST_VCENTER        0x0c
#define ST_UPPERCASE      192
#define ST_VERTICAL       0x01

#define ST_TYPE           0xF0
#define ST_SINGLE         0
#define ST_MULTI          16
#define ST_TITLE_BAR      32
#define ST_PICTURE        48
#define ST_FRAME          64
#define ST_BACKGROUND     80
#define ST_GROUP_BOX      96
#define ST_GROUP_BOX2     112
#define ST_HUD_BACKGROUND 128
#define ST_TILE_PICTURE   144
#define ST_WITH_RECT      160
#define ST_LINE           176

#define ST_SHADOW             0x100
#define ST_NO_RECT            0x200
#define ST_KEEP_ASPECT_RATIO  0x800

class Martinez_ctrlDefault {
    access = 0;
    idc = -1;
    style = 0;
    default = 0;
    show = 1;
    fade = 0;
    blinkingPeriod = 0;
    deletable = 0;
    x = 0;
    y = 0;
    w = 0;
    h = 0;
    tooltip = "";
    tooltipMaxWidth = 0.5;
    tooltipColorShade[] = {0,0,0,1};
    tooltipColorText[] = {1,1,1,1};
    tooltipColorBox[] = {0,0,0,0};
    class ScrollBar {
        width = 0;
        height = 0;
        scrollSpeed = 0.06;
        arrowEmpty = "\a3\3DEN\Data\Controls\ctrlDefault\arrowEmpty_ca.paa";
        arrowFull = "\a3\3DEN\Data\Controls\ctrlDefault\arrowFull_ca.paa";
        border = "\a3\3DEN\Data\Controls\ctrlDefault\border_ca.paa";
        thumb = "\a3\3DEN\Data\Controls\ctrlDefault\thumb_ca.paa";
        color[] = {1,1,1,1};
    };
};

class Martinez_ctrlDefaultText: Martinez_ctrlDefault {
    sizeEx = "4.32 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
    font = "RobotoCondensedLight";
    shadow = 1;
};

class Martinez_ctrlStatic: Martinez_ctrlDefaultText {
    idc                     = -1;
    type                    = CT_STATIC;
    colorBackground[]       = {0, 0, 0, 0};
    text                    = "";
    lineSpacing             = 1;
    fixedWidth              = 0;
    colorText[]             = {1, 1, 1, 1};
    colorShadow[]           = {0, 0, 0, 1};
    moving                  = 0;
    autoplay                = 0;
    loops                   = 0;
    tileW                   = 1;
    tileH                   = 1;
    onCanDestroy            = "";
    onDestroy               = "";
    onMouseEnter            = "";
    onMouseExit             = "";
    onSetFocus              = "";
    onKillFocus             = "";
    onKeyDown               = "";
    onKeyUp                 = "";
    onMouseButtonDown       = "";
    onMouseButtonUp         = "";
    onMouseButtonClick      = "";
    onMouseButtonDblClick   = "";
    onMouseZChanged         = "";
    onMouseMoving           = "";
    onMouseHolding          = "";
    onVideoStopped          = "";
    shadow                  = 0;
};

class Martinez_ctrlDefaultButton0: Martinez_ctrlDefaultText {
    soundClick[] = 		{"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
    soundEnter[] = 		{"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
    soundPush[] = 		{"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
    soundEscape[] = 	{"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
};

class Martinez_ctrlDefaultButton: Martinez_ctrlDefaultButton0 {
    type						= CT_BUTTON;
    style 						= ST_CENTER;
    sizeEx 						= "0.018 * safezoneH";
    colorBackground[] 			= {0, 0, 0, 0.6};
    colorBackgroundActive[] 	= {0.945, 0.133, 0.133,1};
    colorBackgroundDisabled[] 	= {0, 0, 0, 0.5};
    font 						= "PuristaLight";
    h                 			= "0.0198 * safezoneH";
	text = "";
    borderSize 					= 0;
    colorBorder[] 				= {0, 0, 0, 0};
    colorShadow[] 				= {0, 0, 0, 1};
    shadow						= 0;
    colorText[]					= {0.9, 0.9, 0.9, 1};
    colorDisabled[]	         	= {0.8, 0.8, 0.8, 1};
    colorFocused[] 				= {0.945, 0.133, 0.133,1};
    offsetX 					= 0;
    offsetY 					= 0;
    offsetPressedX 				= pixelW;
    offsetPressedY 				= pixelH;
    test = "";
};

class Martinez_ctrlButton: Martinez_ctrlDefaultButton {
    type = 1;
    style = "0x02 + 0xC0";
    colorBackground[] = {0, 0, 0, 1};
    colorBackgroundDisabled[] = {0, 0, 0, 0.5};
    colorBackgroundActive[] = {0.945, 0.133, 0.133,1};
    colorFocused[] = {0.945, 0.133, 0.133,1};
    font = "PuristaLight";
    text = "";
    colorText[] = {1,1,1,1};
    colorDisabled[] = {1,1,1,0.25};
    borderSize = 0;
    colorBorder[] = {0,0,0,0};
    colorShadow[] = {0,0,0,0};
    offsetX = 0;
    offsetY = 0;
    offsetPressedX = "pixelW";
    offsetPressedY = "pixelH";
    period = 0;
    periodFocus = 2;
    periodOver = 0.5;
    class KeyHints
    {
        class A
        {
            key = "0x00050000 + 0";
            hint = "KEY_XBOX_A";
        };
    };
    onCanDestroy = "";
    onDestroy = "";
    onMouseEnter = "";
    onMouseExit = "";
    onSetFocus = "";
    onKillFocus = "";
    onKeyDown = "";
    onKeyUp = "";
    onMouseButtonDown = "";
    onMouseButtonUp = "";
    onMouseButtonClick = "";
    onMouseButtonDblClick = "";
    onMouseZChanged = "";
    onMouseMoving = "";
    onMouseHolding = "";
    onButtonClick = "";
    onButtonDown = "";
    onButtonUp = "";
    h = "0.0198 * safezoneH";
};

class Martinez_ctrlButtonPictureKeepAspect: Martinez_ctrlButton {
    style = ST_CENTER + ST_MULTI + ST_TITLE_BAR + ST_KEEP_ASPECT_RATIO;
};

class Martinez_ctrlEdit: Martinez_ctrlDefaultText {
	type                   = CT_EDIT;
	style				   = ST_LEFT + ST_FRAME;
	colorBackground[]      = {0, 0, 0, 0.3};
	text                   = "";
	colorText[]            = {1, 1, 1, 1};
	colorDisabled[]        = {1, 1, 1, 0.25};
	colorSelection[]       = {0.945, 0.133, 0.133,1};
	canModify              = 1;
	autocomplete           = "";
	onCanDestroy           = "";
	onDestroy              = "";
	onSetFocus             = "";
	onKillFocus            = "";
	onKeyDown              = "";
	onKeyUp                = "";
	onMouseButtonDown      = "";
	onMouseButtonUp        = "";
	onMouseButtonClick     = "";
	onMouseButtonDblClick  = "";
	onMouseZChanged        = "";
	onMouseMoving          = "";
	onMouseHolding         = "";
};

class Martinez_ctrlTree: Martinez_ctrlDefaultText {
	type = 12;
    rowHeight = 0.0439091;
	colorBorder[] = {0,0,0,0};
	colorLines[] = {0,0,0,0};
	colorBackground[] = {0,0,0,0};
	colorSelect[] = {0.945, 0.133, 0.133,1};
	colorMarked[] = {0.945, 0.133, 0.133,1};
	colorMarkedSelected[] = {0.945, 0.133, 0.133,1};
	colorText[] = {1,1,1,1};
	colorSelectText[] = {1,1,1,1};
	colorMarkedText[] = {1,1,1,1};
	colorSearch[] = {1,1,1,1};
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictureDisabled[] = {1,1,1,0.25};
	colorPictureRight[] = {1,1,1,1};
	colorPictureRightSelected[] = {1,1,1,1};
	colorPictureRightDisabled[] = {1,1,1,0.25};
	multiselectEnabled = 0;
	expandOnDoubleclick = 1;
	hiddenTexture = "\a3\3DEN\Data\Controls\ctrlTree\hiddenTexture_ca.paa";
	expandedTexture = "\a3\3DEN\Data\Controls\ctrlTree\expandedTexture_ca.paa";
	maxHistoryDelay = 1;
	disableKeyboardSearch = 0;
	class ScrollBar: ScrollBar
	{
		scrollSpeed = 0.05;
	};
	colorDisabled[] = {0,0,0,0};
	colorArrow[] = {0,0,0,0};
	onCanDestroy = "";
	onDestroy = "";
	onMouseEnter = "";
	onMouseExit = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onTreeSelChanged = "";
	onTreeLButtonDown = "";
	onTreeDblClick = "";
	onTreeExpanded = "";
	onTreeCollapsed = "";
	onTreeMouseExit = "";
};

class Martinez_ctrlButtonToolbar: Martinez_ctrlButtonPictureKeepAspect {
    colorBackground[]           = {0, 0, 0, 0};
    colorBackgroundDisabled[]   = {0, 0, 0, 0};
    shadow                      = 0;
    colorShadow[]               = {0, 0, 0, 0};
};

class Martinez_ctrlButtonSearch: Martinez_ctrlButton {
    style       = "0x02 + 0x30 + 0x800";
    text        = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
    textSearch  = "\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa";
    tooltip     = "Reload Search";
    w           = "5 * (pixelW * pixelGrid * 	0.50)";
    h           = "5 * (pixelH * pixelGrid * 	0.50)";
};

class Martinez_ctrlButtonExpandAll: Martinez_ctrlButtonToolbar {
    style       = "0x02 + 0x30 + 0x800";
    text        = "\a3\3DEN\Data\Displays\Display3DEN\tree_expand_ca.paa";
    tooltip     = "Expand All";
    w           = "5 * (pixelW * pixelGrid * 0.50)";
    h           = "5 * (pixelH * pixelGrid * 0.50)";
};

class Martinez_ctrlButtonCollapseAll: Martinez_ctrlButtonToolbar {
    style       = "0x02 + 0x30 + 0x800";
    text        = "\a3\3DEN\Data\Displays\Display3DEN\tree_collapse_ca.paa";
    tooltip     = "Collapse All";
    w           = "5 * (pixelW * pixelGrid * 0.50)";
    h           = "5 * (pixelH * pixelGrid * 0.50)";
};

class Martinez_ctrlButtonClose: Martinez_ctrlButtonToolbar {
    idc            = -1;
    style          = "0x02 + 0x30 + 0x800";
    text           = "\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa";
    tooltip        = "Close Display";
    onButtonClick  = "(ctrlParent (_this select 0)) closeDisplay 2";
    offsetPressedX = 0;
    offsetPressedY = 0;
};

class Martinez_RscPicture {
	idc = -1;
	shadow 					= 0;
	colorText[] 			= {1, 1, 1, 1};
	colorBackground[] 		= {-1, -1, -1, -1};
	style 					= 48;
	x 						= 0;
	y 						= 0;
	w 						= 0.2;
	h 						= 0.15000001;
	type 					= 0;
	tooltipColorText[] 		= {1, 1, 1, 1};
	tooltipColorBox[] 		= {1, 1, 1, 1};
	tooltipColorShade[] 	= {0, 0, 0, 0.64999998};
	font 					= "PuristaMedium";
	sizeEx 					= -1;
	text = "";
};

class Martinez_RscPictureKeepAspect: Martinez_RscPicture {
	style = "0x30 + 0x800";
	text = "";
};

class Martinez_ctrlStructuredText: Martinez_ctrlDefaultText {
    type               = 13;
    style 			   = 0;
    colorBackground[]  = {0, 0, 0, 0};
    colorText[]             = {1, 1, 1, 1};
    colorShadow[]           = {0, 0, 0, 1};
    size               = "4.32 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
    text               = "";
    tileW                   = 1;
    tileH                   = 1;
    class Attributes {
        align     = "left";
        color     = "#ffffff";
        colorLink = "";
        size      = 1;
        font      = "RobotoCondensedLight";
    };
    onCanDestroy            = "";
    onDestroy               = "";
    onMouseEnter            = "";
    onMouseExit             = "";
    onSetFocus              = "";
    onKillFocus             = "";
    onKeyDown               = "";
    onKeyUp                 = "";
    onMouseButtonDown       = "";
    onMouseButtonUp         = "";
    onMouseButtonClick      = "";
    onMouseButtonDblClick   = "";
    onMouseZChanged         = "";
    onMouseMoving           = "";
    onMouseHolding          = "";
    onVideoStopped          = "";
    shadow                  = 0;
};

class Martinez_ctrlListNBox: Martinez_ctrlDefaultText {
	type = 102;
	style = "0x00 + 0x10";
	colorSelectBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
	colorSelectBackground2[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	colorSelect[] = {1,1,1,1};
	colorSelect2[] = {1,1,1,1};
	colorShadow[] = {0,0,0,0.5};
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictureDisabled[] = {1,1,1,0.25};
	columns[] = {0};
	drawSideArrows = 0;
	idcLeft = -1;
	idcRight = -1;
	period = 1;
	disableOverflow = 0;
	rowHeight = "4.32 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
	maxHistoryDelay = 1;
	soundSelect[] = {"",0.1,1};
	class ListScrollBar: ScrollBar{};
	onCanDestroy = "";
	onDestroy = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onLBSelChanged = "";
	onLBDblClick = "";
};

class Martinez_ctrlCombo: Martinez_ctrlDefaultText {
	type = 4;
	style = "0x00 + 0x10 + 0x200";
	colorBackground[] = {0.05,0.05,0.05,1};
	colorSelectBackground[] = {0.945, 0.133, 0.133,1};
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	colorSelect[] = {0,0,0,1};
	colorTextRight[] = {1,1,1,1};
	colorSelectRight[] = {1,1,1,0.25};
	colorSelect2Right[] = {1,1,1,1};
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictureDisabled[] = {1,1,1,0.25};
	colorPictureRight[] = {1,1,1,1};
	colorPictureRightSelected[] = {1,1,1,1};
	colorPictureRightDisabled[] = {1,1,1,0.25};
	arrowEmpty = "\a3\3DEN\Data\Controls\ctrlCombo\arrowEmpty_ca.paa";
	arrowFull = "\a3\3DEN\Data\Controls\ctrlCombo\arrowFull_ca.paa";
	wholeHeight = "12 * 5 * (pixelH * pixelGrid * 0.50)";
	maxHistoryDelay = 1;
	soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand",0.1,1};
	soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse",0.1,1};
	soundSelect[] = {"",0.1,1};
	class ComboScrollBar
	{
		width = 0;
		height = 0;
		scrollSpeed = 0.01;
		arrowEmpty = "\a3\3DEN\Data\Controls\ctrlDefault\arrowEmpty_ca.paa";
		arrowFull = "\a3\3DEN\Data\Controls\ctrlDefault\arrowFull_ca.paa";
		border = "\a3\3DEN\Data\Controls\ctrlDefault\border_ca.paa";
		thumb = "\a3\3DEN\Data\Controls\ctrlDefault\thumb_ca.paa";
		color[] = {1,1,1,1};
	};
	onCanDestroy = "";
	onDestroy = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onLBSelChanged = "";
};

class Martinez_ScrollBar {
	color[] 			= {1, 1, 1, 0.6};
	colorActive[] 		= {1, 1, 1, 1};
	colorDisabled[] 	= {1, 1, 1, 0.3};
	thumb 				= "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
	arrowEmpty 			= "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
	arrowFull 			= "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
	border 				= "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
	shadow 				= 0;
	scrollSpeed 		= 0.06;
	width 				= 0;
	height 				= 0;
	autoScrollEnabled 	= 0;
	autoScrollSpeed 	= -1;
	autoScrollDelay 	= 5;
	autoScrollRewind 	= 0;
};

class Martinez_ctrlListbox: Martinez_ctrlDefaultText {
	type = 5;
	style = "0x00";
	colorBackground[] = {0,0,0,0.5};
	colorSelectBackground[] = {0.945, 0.133, 0.133,1};
	colorSelectBackground2[] = {0.945, 0.133, 0.133,1};
	colorDisabled[] = {1,1,1,0.25};
	colorText[] = {1,1,1,1};
	colorSelect[] = {1,1,1,1};
	colorSelect2[] = {1,1,1,1};
	colorTextRight[] = {1,1,1,1};
	colorSelectRight[] = {1,1,1,1};
	colorSelect2Right[] = {1,1,1,1};
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictureDisabled[] = {1,1,1,0.25};
	rowHeight = "4.32 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
	itemSpacing = 0;
	maxHistoryDelay = 1;
	canDrag = 0;
	soundSelect[] = {"",0.1,1};
	class ListScrollBar: ScrollBar {};
	onCanDestroy = "";
	onDestroy = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onLBSelChanged = "";
	onLBDblClick = "";
	onLBDrag = "";
	onLBDragging = "";
	onLBDrop = "";
};

class Martinez_RscListBox {
	x 								= 0;
	y 								= 0;
	w 								= 0.30000001;
	h 								= 0.30000001;
	style 							= 16;
	type							= 5;
	rowHeight 						= 0.04;
	font 							= "PuristaLight";
	sizeEx 							= "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	shadow 							= 0;
	colorShadow[] 					= {0, 0, 0, 0.5};
	colorText[] 					= {1, 1, 1, 1};
	colorDisabled[] 				= {1, 1, 1, 0.25};
	colorScrollbar[] 				= {1, 0, 0, 0};
	colorSelect[] 					= {0, 0, 0, 1};
	colorSelectBackground[]			= {0.94999999, 0.94999999, 0.94999999, 1};
	period							= 1.2;
	colorBackground[]				= {0, 0, 0, 0.30000001};
	maxHistoryDelay					= 1;
	colorPicture[]					= {1, 1, 1, 1};
	colorPictureSelected[]			= {1, 1, 1, 1};
	colorPictureDisabled[]			= {1, 1, 1, 0.25};
	colorPictureRight[]				= {1, 1, 1, 1};
	colorPictureRightSelected[]     = {1, 1, 1, 1};
	colorPictureRightDisabled[]     = {1, 1, 1, 0.25};
	colorTextRight[]				= {1, 1, 1, 1};
	colorSelectRight[]				= {0, 0, 0, 1};
	tooltipColorText[]				= {1, 1, 1, 1};
	tooltipColorBox[]				= {1, 1, 1, 1};
	tooltipColorShade[]				= {0, 0, 0, 0.64999998};
	soundSelect[] = {"",0.1,1};
	class ListScrollBar: Martinez_ScrollBar { color[] = {1,1,1,1}; autoScrollEnabled = 1;};
};

class Martinez_RscCheckBox {
	idc 							= -1;
	type 							= CT_CHECKBOX;
	deletable 						= 0;
	style 							= 0;
	checked 						= 1;
	x 								= "0.375 * safezoneW + safezoneX";
	y 								= "0.36 * safezoneH + safezoneY";
	w 								= "0.025 * safezoneW";
	h 								= "0.04 * safezoneH";
	color[] 						= {1, 1, 1, 0.7};
	colorFocused[] 					= {1, 1, 1, 1};
	colorHover[] 					= {1, 1, 1, 1};
	colorPressed[] 					= {1, 1, 1, 1};
	colorDisabled[] 				= {1, 1, 1, 0.2};
	colorBackground[] 				= {0, 0, 0, 0};
	colorBackgroundFocused[] 		= {0, 0, 0, 0};
	colorBackgroundHover[] 			= {0, 0, 0, 0};
	colorBackgroundPressed[] 		= {0, 0, 0, 0};
	colorBackgroundDisabled[] 		= {0, 0, 0, 0};
	textureChecked 					= "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureUnchecked				= "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	textureFocusedChecked 			= "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureFocusedUnchecked 		= "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	textureHoverChecked 			= "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureHoverUnchecked 			= "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	texturePressedChecked 			= "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	texturePressedUnchecked 		= "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	textureDisabledChecked 			= "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureDisabledUnchecked		= "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	tooltipColorText[] 				= {1, 1, 1, 1};
	tooltipColorBox[] 				= {1, 1, 1, 1};
	tooltipColorShade[] 			= {0, 0, 0, 0.65};
	soundEnter[] 					= {"\A3\ui_f\data\sound\RscButtonMenuOK\soundPush", 0.09, 1};
	soundPush[] 					= {"\A3\ui_f\data\sound\RscButtonMenuOK\soundPush", 0.09, 1};
	soundClick[] 					= {"\A3\ui_f\data\sound\RscButtonMenuOK\soundPush", 0.09, 1};
	soundEscape[] 					= {"\A3\ui_f\data\sound\RscButtonMenuOK\soundPush", 0.09, 1};
};

class Martinez_RscProgress {
	type 				= 8;
	style 				= 0;
	x 					= 0.344;
	y 					= 0.619;
	w 					= 0.313726;
	h 					= 0.0261438;
	texture				= "";
	shadow 				= 0;
	colorFrame[] 		= {0, 0, 0, 1};
	colorBackground[] 	= {0, 0, 0, 0.7};
	colorBar[] 			= {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
};

class Martinez_ctrlMap: Martinez_ctrlDefault {
	type = 101;
	style = 48;
	widthRailWay = 1;
	x = "safezoneXAbs";
	y = "safezoneY";
	w = "safezoneWAbs";
	h = "safezoneH";
	sizeEx = 0.05;
	font = "RobotoCondensedLight";
	colorText[] = {0,0,0,1};
	moveOnEdges = 1;
	ptsPerSquareSea = 5;
	ptsPerSquareTxt = 20;
	ptsPerSquareCLn = 10;
	ptsPerSquareExp = 10;
	ptsPerSquareCost = 10;
	ptsPerSquareFor = 9;
	ptsPerSquareForEdge = 9;
	ptsPerSquareRoad = 6;
	ptsPerSquareObj = 9;
	scaleMin = 0.0001;
	scaleMax = 1.0;
	scaleDefault = 0.16;
	maxSatelliteAlpha = 0.85;
	alphaFadeStartScale = 2;
	alphaFadeEndScale = 2;
	text = "#(argb,8,8,3)color(1,1,1,1)";
	colorBackground[] = {0.969,0.957,0.949,1.0};
	colorOutside[] = {0.2, 0.2, 0.2, 1};
	colorSea[] = {0.467,0.631,0.851,0.5};
	colorForest[] = {0.624,0.78,0.388,0.5};
	colorForestBorder[] = {0.0,0.0,0.0,0.0};
	colorRocks[] = {0.0,0.0,0.0,0.3};
	colorRocksBorder[] = {0.0,0.0,0.0,0.0};
	colorLevels[] = {0.286,0.177,0.094,0.5};
	colorMainCountlines[] = {0.572,0.354,0.188,0.5};
	colorCountlines[] = {0.572,0.354,0.188,0.25};
	colorMainCountlinesWater[] = {0.491,0.577,0.702,0.6};
	colorCountlinesWater[] = {0.491,0.577,0.702,0.3};
	colorPowerLines[] = {0.1,0.1,0.1,1.0};
	colorRailWay[] = {0.8,0.2,0.0,1.0};
	colorNames[] = {0.1,0.1,0.1,0.9};
	colorInactive[] = {1.0,1.0,1.0,0.5};
	colorTracks[] = {0.84,0.76,0.65,0.15};
	colorTracksFill[] = {0.84,0.76,0.65,1.0};
	colorRoads[] = {0.7,0.7,0.7,1.0};
	colorRoadsFill[] = {1.0,1.0,1.0,1.0};
	colorMainRoads[] = {0.9,0.5,0.3,1.0};
	colorMainRoadsFill[] = {1.0,0.6,0.4,1.0};
	colorTrails[] = {0.84,0.76,0.65,0.15};
	colorTrailsFill[] = {0.84,0.76,0.65,0.65};
	colorGrid[] = {0.1,0.1,0.1,0.6};
	colorGridMap[] = {0.1,0.1,0.1,0.6};
	fontLabel = "RobotoCondensedLight";
	sizeExLabel = 0.05;
	fontGrid = "TahomaB";
	sizeExGrid = 0.02;
	fontUnits = "TahomaB";
	sizeExUnits = 0.05;
	fontNames = "EtelkaNarrowMediumPro";
	sizeExNames = 0.05;
	fontInfo = "RobotoCondensedLight";
	sizeExInfo = 0.05;
	fontLevel = "TahomaB";
	sizeExLevel = 0.02;
	showCountourInterval = 0;
	idcMarkerColor = -1;
	idcMarkerIcon = -1;
	textureComboBoxColor = "#(argb,8,8,3)color(1,1,1,1)";
	showMarkers = "true";
	class LineMarker
	{
		lineWidthThin = 0.008;
		lineWidthThick = 0.014;
		lineDistanceMin = 3e-005;
		lineLengthMin = 5;
	};
	class Legend
	{
		x = 0.5;
		y = 0.5;
		w = 0.4;
		h = 0.1;
		color[] = {0,0,0,1};
		colorBackground[] = {1,1,1,0.5};
		font = "RobotoCondensedLight";
		sizeEX = "3.96 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
	};
	class Task
	{
		icon = "\A3\ui_f\data\map\mapcontrol\taskIcon_CA.paa";
		color[] = {1,1,1,1};
		iconCreated = "\A3\ui_f\data\map\mapcontrol\taskIconCreated_CA.paa";
		colorCreated[] = {1,1,0,1};
		iconCanceled = "\A3\ui_f\data\map\mapcontrol\taskIconCanceled_CA.paa";
		colorCanceled[] = {0.7,0.7,0.7,1};
		iconDone = "\A3\ui_f\data\map\mapcontrol\taskIconDone_CA.paa";
		colorDone[] = {0.7,1,0.3,1};
		iconFailed = "\A3\ui_f\data\map\mapcontrol\taskIconFailed_CA.paa";
		colorFailed[] = {1,0.3,0.2,1};
		size = 27;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};
	class ActiveMarker
	{
		color[] = {0,0,0,1};
		size = 2;
	};
	class Waypoint
	{
		coefMax = 1;
		coefMin = 1;
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\waypoint_ca.paa";
		importance = 1;
		size = 24;
	};
	class WaypointCompleted: Waypoint
	{
		icon = "\A3\ui_f\data\map\mapcontrol\waypointCompleted_ca.paa";
	};
	class CustomMark: Waypoint
	{
		icon = "\A3\ui_f\data\map\mapcontrol\custommark_ca.paa";
	};
	class Command: Waypoint
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\waypoint_ca.paa";
		size = 18;
	};
	class Bush: Waypoint
	{
		coefMax = 4;
		coefMin = 0.25;
		color[] = {0.45,0.64,0.33,0.4};
		icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
		importance = 0.007;
		size = 7;
	};
	class SmallTree: Bush
	{
		icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
		importance = 0.36;
		size = 12;
	};
	class Tree: SmallTree
	{
		icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
		importance = 0.72;
	};
	class Rock: SmallTree
	{
		color[] = {0.1,0.1,0.1,0.8};
		icon = "\A3\ui_f\data\map\mapcontrol\rock_ca.paa";
		importance = 0.3;
	};
	class BusStop: Bush
	{
		color[] = {0.45,0.64,0.33,0.4};
		icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
	};
	class FuelStation: Waypoint
	{
		coefMax = 1;
		coefMin = 0.85;
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\fuelstation_CA.paa";
	};
	class Hospital: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\hospital_CA.paa";
	};
	class Church: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\church_CA.paa";
	};
	class Lighthouse: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\lighthouse_CA.paa";
	};
	class Power: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\power_CA.paa";
	};
	class PowerSolar: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\powersolar_CA.paa";
	};
	class PowerWave: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\powerwave_CA.paa";
	};
	class PowerWind: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\powerwind_CA.paa";
	};
	class Quay: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\quay_CA.paa";
	};
	class Transmitter: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\transmitter_CA.paa";
	};
	class Watertower: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\watertower_CA.paa";
	};
	class Cross: Waypoint
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\Cross_CA.paa";
	};
	class Chapel: Cross
	{
		icon = "\A3\ui_f\data\map\mapcontrol\Chapel_CA.paa";
	};
	class Shipwreck: Cross
	{
		icon = "\A3\ui_f\data\map\mapcontrol\Shipwreck_CA.paa";
	};
	class Bunker: Waypoint
	{
		coefMax = 4;
		coefMin = 0.25;
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\bunker_ca.paa";
		importance = 1.05;
		size = 14;
	};
	class Fortress: Bunker
	{
		icon = "\A3\ui_f\data\map\mapcontrol\bunker_ca.paa";
		importance = 1.6;
		size = 16;
	};
	class Fountain: Bunker
	{
		icon = "\A3\ui_f\data\map\mapcontrol\fountain_ca.paa";
		importance = 0.6;
		size = 11;
	};
	class Ruin: Waypoint
	{
		coefMax = 4;
		coefMin = 1;
		icon = "\A3\ui_f\data\map\mapcontrol\ruin_ca.paa";
		importance = 0.96;
		size = 16;
	};
	class Stack: Waypoint
	{
		coefMax = 2;
		coefMin = 0.4;
		icon = "\A3\ui_f\data\map\mapcontrol\stack_ca.paa";
		importance = 1.6;
		size = 16;
	};
	class Tourism: Waypoint
	{
		coefMax = 4;
		coefMin = 0.7;
		icon = "\A3\ui_f\data\map\mapcontrol\tourism_ca.paa";
		importance = 2.8;
		size = 16;
	};
	class ViewTower: Waypoint
	{
		coefMax = 4;
		coefMin = 0.5;
		icon = "\A3\ui_f\data\map\mapcontrol\viewtower_ca.paa";
		importance = 2;
		size = 16;
	};
	onCanDestroy = "";
	onDestroy = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onDraw = "";
};