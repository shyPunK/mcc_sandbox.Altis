private ["_targets","_null","_selected","_objects","_dir","_target","_vehiclePlayer","_airports","_counter","_searchArray","_sides",
		 "_positionStart","_positionEnd","_pointIntersect","_break"];
_break = false; 

//Do not fire while inside a dialog 
if (dialog) exitWith {}; 
sleep 0.3;
MCC_interactionKey_holding =  if (MCC_interactionKey_down) then {true} else {false};
//Fails safe if ui get stuck
if (time > (player getVariable ["MCC_interactionActiveTime",time-5])) then {player setVariable ["MCC_interactionActive",false]};

//If we are busy quit
if ((player getVariable ["MCC_interactionActive",false]) || (time < (player getVariable ["MCC_interactionActiveTime",time-5])+2)) exitWith {};
player setVariable ["MCC_interactionActive",true];   
player setVariable ["MCC_interactionActiveTime",time];

//Outside of vehicle
if (vehicle player == player) then
{
	//Handle man
	_target = cursorTarget;
	player sidechat str _target;
	if (_target isKindof "CAManBase" && (player distance _target < 30)) exitWith
	{
		//_null= [_target, player] call MCC_fnc_interactMan;
		_null= [_target,player] execvm "mcc\fnc\interaction\fn_interactMan.sqf";
		player setVariable ["MCC_interactionActive",false];  
		_break = true;
	};
	
	if (_break) exitWith {}; 
	
	_objects = player nearObjects [MCC_dummy,10];
	
	//Handle Objects
	if (count _objects > 0) then
	{
		_selected = ([_objects,[],{player distance _x},"ASCEND"] call BIS_fnc_sortBy) select 0;
		_dir	  = [player, _selected] call BIS_fnc_relativeDirTo;
		if (_dir>340 || _dir < 20) exitWith 
		{
			//IED
			if (((_selected getVariable ["MCC_IEDtype",""]) == "ied") && !(_selected getVariable ["MCC_isInteracted",false])) then
			{
				_null= [player,_selected] call MCC_fnc_interactIED;
				//_null= [player,_selected] execvm "mcc\fnc\interaction\fn_interactIED.sqf";
				_break = true; 
			};
		};
	};
	
	if (_break) exitWith {}; 
	
	//Not MCC object
	_positionStart 	= eyePos player;
	_positionEnd 	= ATLtoASL screenToWorld [0.5,0.5];
	_pointIntersect = lineIntersectsWith [_positionStart, _positionEnd, player, objNull, true];
	if (count _pointIntersect > 0) then
	{
		_selected = _pointIntersect select ((count _pointIntersect)-1);
		if (player distance _selected < 3) exitWith
		{
			player sidechat str _selected;
			copyToClipboard str _selected;
			_null= [player,_selected] execvm "mcc\fnc\interaction\fn_interactObject.sqf";
			_break = true;
		};
	};
	
	if (_break) exitWith {}; 
	
	//Handle house
	if (_target isKindof "house" || _target isKindof "AllVehicles") exitWith
	{
		//[_target] execvm "mcc\fnc\interaction\fn_interactDoor.sqf";
		[_target] call MCC_fnc_interactDoor
	};
	
	/*
	//Shout around if no interaction found
	if (!MCC_interactionKey_holding) then
	{
		[[[netid player,player], format ["dontmove%1",floor (random 20)]], "MCC_fnc_globalSay3D", true, false] spawn BIS_fnc_MP;
		sleep _waitTime; 
		player setVariable ["MCC_interactionActive",false];  
	};
	*/
}
else
{
	_vehiclePlayer = vehicle player;
	
	//Logistics
	if ((typeof _vehiclePlayer in MCC_supplyTracks) && (player == driver _vehiclePlayer) && (speed _vehiclePlayer < 10) && MCC_allowlogistics) then
	{
		_null = [player] execVm format ["%1mcc\general_scripts\logistics\load.sqf",MCC_path];
	};
	
	//MCC ILS
	if ((_vehiclePlayer isKindOf "Plane") && (player == Driver _vehiclePlayer)) then
	{
		_airports = []; 
		_counter = 0;
		_searchArray = if (MCC_isMode) then {allMissionObjects "mcc_sandbox_moduleILS"} else {allMissionObjects "logic"}; 

		{
			_sides = _x getVariable ["MCC_runwaySide",-1];
			_sides = if (_sides == -1) then {[east,west,resistance,civilian]} else {[_sides call bis_fnc_sideType]}; 
			
			if (((_x getVariable ["MCC_runwayDis",0])>0) && (playerside in _sides)) then
			{
				_airports set [_counter,[_x,(_x getVariable ["MCC_runwayName","Runway"]),(_x getVariable ["MCC_runwayDis",0]),(_x getVariable ["MCC_runwayAG",false])]]; 
				_counter = _counter +1;
			};
		} foreach _searchArray;

		if (count _airports > 0) then
		{
			[player] call MCC_fnc_ilsMain;
		};
	};

};
if !(_break) then
{
	player setVariable ["MCC_interactionActive",false]; 
};