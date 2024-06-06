/*
	File: fn_loadoutCamera.sqf
	Function: Martinez_fnc_loadoutCamera
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
		private _obj = _display getVariable ["Martinez_LoadoutCharacter", objNull];
		loadoutPreviewCamTarget = _postion;
		loadoutPreviewCam = "camera" camCreate [0, 0, 3];
		loadoutPreviewCam cameraEffect ["Internal", "BACK"];
		loadoutPreviewCam setVectorUp [0, 0, 0];
		loadoutPreviewCam camSetTarget (ASLToAGL loadoutPreviewCamTarget);
		loadoutPreviewCamDistance = _camDist;
		loadoutPreviewCam setPosASL (loadoutPreviewCamTarget vectorAdd [sin (getDir _obj), cos (getDir _obj), 0]);
		private _vector = loadoutPreviewCamTarget vectorFromTo (getPosASL loadoutPreviewCam);
		private _newPos = loadoutPreviewCamTarget vectorAdd (_vector vectorMultiply loadoutPreviewCamDistance);
		loadoutPreviewCam setPosASL _newPos;
		loadoutPreviewCam camCommit 0;
		loadoutPreviewCamCtrlDragging = false;

		loadoutPreviewCamCtrlDown = _display displayAddEventHandler  ["MouseButtonDown", {
			if (_this#2 < -0.656 || _this#2 > -0.1212 || _this#3 < -0.223 || _this#3 > 1.2313) then {
				loadoutPreviewCamCtrlDragging = true;
			};
		}];

		loadoutPreviewCamCtrlUp = _display displayAddEventHandler  ["MouseButtonUp", {loadoutPreviewCamCtrlDragging = false}];

		loadoutPreviewCamCtrlMouseMove = _display displayAddEventHandler ["MouseMoving", {
			params ["", "_dx", "_dy"];
			if (loadoutPreviewCamCtrlDragging) then {
				private _dir = getDir loadoutPreviewCam;
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
				private _vector = loadoutPreviewCamTarget vectorFromTo (getPosASL loadoutPreviewCam);
				_vector = matrixTranspose [_vector];
				_vector = [[cos _dx, -(sin _dx), 0], [sin _dx, cos _dx, 0], [0, 0, 1]] matrixMultiply _vector;
				_vector = [[cos _dy1, 0, sin _dy1], [0, 1, 0], [-(sin _dy1), 0, cos _dy1]] matrixMultiply _vector;
				_vector = [[1, 0, 0], [0, cos _dy2, -(sin _dy2)], [0, sin _dy2, cos _dy2]] matrixMultiply _vector;
				_vector = (matrixTranspose _vector)#0;
				private _newPos = loadoutPreviewCamTarget vectorAdd (_vector vectorMultiply loadoutPreviewCamDistance);
				if (_newPos#2 < loadoutPreviewCamTarget#2 + 0.1) then {
					_newPos set [2, loadoutPreviewCamTarget#2 + 0.1];
				};
				loadoutPreviewCam setPosASL _newPos;
				loadoutPreviewCam camCommit 0.05;
			};
		}];

		loadoutPreviewCamCtrlZoom = _display displayAddEventHandler ["MouseZChanged", {
			params ["", "_scroll"];
			loadoutPreviewCamDistance = loadoutPreviewCamDistance - _scroll;
			loadoutPreviewCamDistance = loadoutPreviewCamDistance min 4.25;
			loadoutPreviewCamDistance = loadoutPreviewCamDistance max 1.5;
			private _vector = loadoutPreviewCamTarget vectorFromTo (getPosASL loadoutPreviewCam);
			private _newPos = loadoutPreviewCamTarget vectorAdd (_vector vectorMultiply loadoutPreviewCamDistance);
			loadoutPreviewCam setPosASL _newPos;
			loadoutPreviewCam camCommit 0.15;
		}];
	};

	case "destroyCam": {
		loadoutPreviewCam cameraEffect ["TERMINATE", "BACK"];
		camDestroy loadoutPreviewCam;
	};
};
