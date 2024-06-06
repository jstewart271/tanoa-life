/*
	File: fn_clothingCamera.sqf
	Function: Martinez_fnc_clothingCamera
	Author: Martinezzz

	Copyright (c) 2022 Martinezzz, Martinezzz Development
	All Rights Reserved

	Params:
		0: STRING
			- Mode of the script

		1: DISPLAY
			- Display of the active dialog

		2: ARRAY
			- Position of the camera

		4: NUMBER
			- Camera distance
*/

params [
	["_mode", "", [""]],
	["_display", displayNull, [displayNull]],
	["_postion", [], [[]]],
	["_camDist", -1, [0]]
];

switch _mode do {
	case "setupCam": {
		showCinemaBorder false;
		private _obj = _display getVariable ["Martinez_ClothingCharacter", objNull];
		clothingPreviewCamTarget = _postion;
		clothingPreviewCam = "camera" camCreate [0, 0, 3];
		clothingPreviewCam cameraEffect ["Internal", "BACK"];
		clothingPreviewCam setVectorUp [0, 0, 0];
		clothingPreviewCam camSetTarget (ASLToAGL clothingPreviewCamTarget);
		clothingPreviewCamDistance = _camDist;
		clothingPreviewCam setPosASL (clothingPreviewCamTarget vectorAdd [sin (getDir _obj), cos (getDir _obj), 0]);
		private _vector = clothingPreviewCamTarget vectorFromTo (getPosASL clothingPreviewCam);
		private _newPos = clothingPreviewCamTarget vectorAdd (_vector vectorMultiply clothingPreviewCamDistance);
		clothingPreviewCam setPosASL _newPos;
		clothingPreviewCam camCommit 0;
		clothingPreviewCamCtrlDragging = false;

		clothingPreviewCamCtrlDown = _display displayAddEventHandler  ["MouseButtonDown", {
			if (_this#2 < -0.656 || _this#2 > -0.1212 || _this#3 < -0.223 || _this#3 > 1.2313) then {
				clothingPreviewCamCtrlDragging = true;
			};
		}];

		clothingPreviewCamCtrlUp = _display displayAddEventHandler  ["MouseButtonUp", {clothingPreviewCamCtrlDragging = false}];

		clothingPreviewCamCtrlMouseMove = _display displayAddEventHandler ["MouseMoving", {
			params ["", "_dx", "_dy"];
			if (clothingPreviewCamCtrlDragging) then {
				private _dir = getDir clothingPreviewCam;
				private _myDir = _dir;
				private _anglePart = floor (_myDir / 180);
				_myDir = _myDir - 180 * _anglePart;
				if (_myDir > 90) then {_myDir = 180 - _myDir};
				_myDir = _myDir / 90;
				_dy1 = _dy * _myDir;
				_dy2 = _dy * ([_myDir + 0.5, _myDir - 0.5] select (_myDir > 0.3));
				if (_dir > 180) then {_dy1 = _dy1 * -1};
				if (_dir < 90 || _dir > 270) then {_dy2 = _dy2 * -1;};
				_dy1 = _dy1 * 2;
				_dy2 = _dy2 * 2;
				_dx = _dx * -2;
				private _vector = clothingPreviewCamTarget vectorFromTo (getPosASL clothingPreviewCam);
				_vector = matrixTranspose [_vector];
				_vector = [[cos _dx, -(sin _dx), 0], [sin _dx, cos _dx, 0], [0, 0, 1]] matrixMultiply _vector;
				_vector = [[cos _dy1, 0, sin _dy1], [0, 1, 0], [-(sin _dy1), 0, cos _dy1]] matrixMultiply _vector;
				_vector = [[1, 0, 0], [0, cos _dy2, -(sin _dy2)], [0, sin _dy2, cos _dy2]] matrixMultiply _vector;
				_vector = (matrixTranspose _vector)#0;
				private _newPos = clothingPreviewCamTarget vectorAdd (_vector vectorMultiply clothingPreviewCamDistance);
				if (_newPos#2 < clothingPreviewCamTarget#2 + 0.1) then {
					_newPos set [2, clothingPreviewCamTarget#2 + 0.1];
				};
				clothingPreviewCam setPosASL _newPos;
				clothingPreviewCam camCommit 0.05;
			};
		}];

		clothingPreviewCamCtrlZoom = _display displayAddEventHandler ["MouseZChanged", {
			params ["", "_scroll"];
			clothingPreviewCamDistance = clothingPreviewCamDistance - _scroll;
			clothingPreviewCamDistance = clothingPreviewCamDistance min 4.25;
			clothingPreviewCamDistance = clothingPreviewCamDistance max 1.5;
			private _vector = clothingPreviewCamTarget vectorFromTo (getPosASL clothingPreviewCam);
			private _newPos = clothingPreviewCamTarget vectorAdd (_vector vectorMultiply clothingPreviewCamDistance);
			clothingPreviewCam setPosASL _newPos;
			clothingPreviewCam camCommit 0.15;
		}];
	};

	case "destroyCam": {
		clothingPreviewCam cameraEffect ["TERMINATE", "BACK"];
		camDestroy clothingPreviewCam;
	};
};
