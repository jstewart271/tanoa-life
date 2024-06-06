/*
	@File: fn_getPaycheck.sqf
	@Author: Jack "Scarso" Farhall
	@Description:
*/
#include "..\..\script_macros.hpp"

private _pay = -1;

_pay = switch (true) do {
	case (playerSide isEqualTo west): {
		private _basePay = switch(FETCH_CONST(life_coplevel)) do {
			case 1: {
				round (25000 * (1 - (PHX_TaxRate/100)));
			};
			case 2: {
				round (32500 * (1 - (PHX_TaxRate/100)));
			};
			case 3: {
				round (40000 * (1 - (PHX_TaxRate/100)));
			};
			case 4: {
				round (50000 * (1 - (PHX_TaxRate/100)));
			};
			case 5: {
				round (60000 * (1 - (PHX_TaxRate/100)));
			};
			case 6: {
				round (70000 * (1 - (PHX_TaxRate/100)));
			};
			case 7: {
				round (80000 * (1 - (PHX_TaxRate/100)));
			};
			case 8: {
				round (90000 * (1 - (PHX_TaxRate/100)));
			};
			case 9: {
				round (105000 * (1 - (PHX_TaxRate/100)));
			};
			case 10: {
				round (115000 * (1 - (PHX_TaxRate/100)));
			};
			case 11: {
				round (125000 * (1 - (PHX_TaxRate/100)));
			};
			case 12: {
				round (135000 * (1 - (PHX_TaxRate/100)));
			};
			case 13: {
				round (150000 * (1 - (PHX_TaxRate/100)));
			};
			default {
				PHX_PaycheckRate;
			};
		};

		private _acadLvl = (FETCH_CONST(life_academylevel));
		if (_acadLvl > 0) then {
			_basePay = _basePay * (1 + (_acadLvl / 10));
		};

		_basePay
	};

	case (player getVariable ["Faction_Medic", false]): {
		switch(FETCH_CONST(life_mediclevel)) do {
			case 1: {
				round (25000 * (1 - (PHX_TaxRate/100)));
			};
			case 2: {
				round (30000 * (1 - (PHX_TaxRate/100)));
			};
			case 3: {
				round (35000 * (1 - (PHX_TaxRate/100)));
			};
			case 4: {
				round (40000 * (1 - (PHX_TaxRate/100)));
			};
			case 5: {
				round (45000 * (1 - (PHX_TaxRate/100)));
			};
			case 6: {
				round (50000 * (1 - (PHX_TaxRate/100)));
			};
			case 7: {
				round (55000 * (1 - (PHX_TaxRate/100)));
			};
			case 8: {
				round (60000 * (1 - (PHX_TaxRate/100)));
			};
			default {
				PHX_PaycheckRate;
			};
		};
	};

	case (playerSide isEqualTo east): {
		switch(FETCH_CONST(life_havoclevel)) do {
			case 1: {
				round (25000 * (1 - (PHX_TaxRate/100)));
			};
			case 2: {
				round (32500 * (1 - (PHX_TaxRate/100)));
			};
			case 3: {
				round (40000 * (1 - (PHX_TaxRate/100)));
			};
			case 4: {
				round (50000 * (1 - (PHX_TaxRate/100)));
			};
			case 5: {
				round (60000 * (1 - (PHX_TaxRate/100)));
			};
			case 6: {
				round (70000 * (1 - (PHX_TaxRate/100)));
			};
			case 7: {
				round (80000 * (1 - (PHX_TaxRate/100)));
			};
			case 8: {
				round (90000 * (1 - (PHX_TaxRate/100)));
			};
			case 9: {
				round (105000 * (1 - (PHX_TaxRate/100)));
			};
			case 10: {
				round (115000 * (1 - (PHX_TaxRate/100)));
			};
			case 11: {
				round (125000 * (1 - (PHX_TaxRate/100)));
			};
			case 12: {
				round (135000 * (1 - (PHX_TaxRate/100)));
			};
			case 13: {
				round (150000 * (1 - (PHX_TaxRate/100)));
			};
			default {
				PHX_PaycheckRate;
			};
		};
	};

	case (playerSide isEqualTo civilian): {
		if (isCID(player)) exitWith {
			switch(FETCH_CONST(life_cidlevel)) do {
				case 1: {
					round (17000 * (1 - (PHX_TaxRate/100)));
				};
				case 2: {
					round (20000 * (1 - (PHX_TaxRate/100)));
				};
				case 3: {
					round (20000 * (1 - (PHX_TaxRate/100)));
				};
				case 4: {
					round (22500 * (1 - (PHX_TaxRate/100)));
				};
				case 5: {
					round (27500 * (1 - (PHX_TaxRate/100)));
				};
				default {
					round (17000 * (1 - (PHX_TaxRate/100)));
				};
			};
		};

		if (isHSS(player)) exitWith {
			65000
		};

		if (PHX_isPM) then {
			round (40000 * (1 - (PHX_TaxRate/100)));
		} else {
			switch true do {
				// Job pay out...
				case ((isNEW(player)) ||
				{
					(isLAW(player))
				} ||
				{
					(isTAX(player))
				} ||
				{
					(isSER(player))
				} ||
				{
					(isSO1(player))
				}
				): {
					round (15000 * (1 - (PHX_TaxRate/100)));
				};
				default {
					PHX_PaycheckRate;
				};
			};
		};
	};
};

if IS_GOAL then {
	_pay = round (_pay * (LIFE_SETTINGS(getNumber, "donation_goal_paycheck_multiplier")))
};

_pay;