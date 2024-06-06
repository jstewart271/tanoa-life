/*
	@File: fn_ProcessingLBChanged.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Update Processing Menu on Type Switch...
*/
#include "..\..\..\..\script_macros.hpp"
disableSerialization;

private _price = CONTROL_VALUE(5001);

private _text = switch (true) do {
	case (_price <= 0): { "<t size='0.8' font='RobotoCondensedLight'>Cost: <t color='#b2ec00'>Free (License)</t></t>" };
	case (CASH >= _price): { format["<t size='0.8' font='RobotoCondensedLight'>Cost: <t color='#b2ec00'>£%1</t></t>", [_price] call life_fnc_numberText] };
	default { format["<t size='0.8' font='RobotoCondensedLight'>Cost: <t color='#b70000'>£%1</t></t>", [_price] call life_fnc_numberText] };
};

if (CASH >= _price) then { ctrlEnable[5003, true] } else { ctrlEnable[5003, false] }; // Toggle "Process Button"...
(CONTROL(5000, 5002)) ctrlSetStructuredText parseText _text;