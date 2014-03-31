//===================================================================MCC_fnc_sync=========================================================================================
// Sync the player with the server
// Example: [] spawn MCC_fnc_sync;
// Params:
// 	NONE
//==============================================================================================================================================================================	
private ["_ok"];
if (!isnil "MCC_Overcast") then {0 setOvercast MCC_Overcast};
if (!isnil "MCC_WindForce") then {0 setWindForce MCC_WindForce};
if (!isnil "MCC_Waves") then {0 setWaves MCC_Waves};
if (!isnil "MCC_Rain") then {0 setRain MCC_Rain};
if (!isnil "MCC_Lightnings") then {0 setLightnings MCC_Lightnings};
if (!isnil "MCC_Fog") then {0 setFog MCC_Fog};

skipTime 1;
skipTime -1;
sleep 5;

if (!isnil "MCC_date") then {setDate MCC_date};
if (!isnil "MCC_sync") then 
{
	_ok = [] spawn compile MCC_sync;
	waituntil {scriptdone _ok};
};

if (!isnil "MCC_zones_numbers") then 
{
	{
		_zone = createMarkerLocal [str _x, mcc_zone_pos select _x]; 
		_zone setMarkerShapeLocal "RECTANGLE";
		_zone setMarkerColorLocal "colorBlack";
		_zone setMarkerBrushLocal "Solid";
		_zone setMarkerAlphalocal 0.4; 
		_zone setMarkerDirLocal (mcc_zone_dir select _x);
		_zone setMarkerSizeLocal (mcc_zone_size select _x);
	} foreach MCC_zones_numbers;
};

mcc_sync_status = true; 

sleep 1; 
skipTime +1;
