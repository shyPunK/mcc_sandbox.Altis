//===================================================================MCC_fnc_createIED======================================================================================
// Create an IED mechnic (should run on server only). 
//Example:[_this,_trapvolume,_IEDExplosionType,_IEDDisarmTime,_IEDJammable,_IEDTriggerType,_trapdistance,_iedside] spawn MCC_fnc_createIED
// Params: 
// 	IEDVolume: stirng, explosion radius - "small","medium","large"
//	IEDExplosionType: number, explosion type: 0-deadly, 1 - disabling (will cripple vehicles and soldiers but will not kill) 2 - Fake, will not or lightly wound soldiers. 
//	IEDDisarmTime: number, time in second it will take to disarm the IED
//	IEDJammable: boolean, true - if jammer vheicle (defined in MCC_IEDJammerVehicles) can jame this IED false if not
//	IEDTriggerType: number, 0- Proximity, will explode if unit from the targer side will move faster then a slow crouch, 1- radio will explode if unit from the targer side will get close to it, if assigned to spotter the spotter must be alive, 2- manual detontion, only mission maker
//	IEDdistance: number, minimum distance which target unit have to get close to the IED to set it off
//	IEDside: side, [west, east, resistance, civilian]
//==============================================================================================================================================================================	

//Made by Shay_Gman (c) 06.14
private ["_pos", "_trapvolume", "_IEDExplosionType", "_IEDDisarmTime", "_IEDJammable", "_IEDTriggerType", "_IEDAmbushGroup",
 "_trapdistance", "_iedside", "_fakeIed", "_dummy","_ok","_iedDir","_init","_isAmmo"]; 
disableSerialization;

if (!isServer) exitWIth {}; 

_fakeIed			= _this select 0; 
_trapvolume 		= _this select 1; 
_IEDExplosionType 	= _this select 2; 
_IEDDisarmTime 		= _this select 3; 
_IEDJammable 		= _this select 4;
_IEDTriggerType 	= _this select 5;
_trapdistance 		= _this select 6;
_iedside 			= _this select 7;

if (typeName _iedside == "STRING") then
{
	_iedside = switch (tolower _iedside) do
				{
				   case "west":	{west};
				   case "east":	{east};
				   case "guer":	{resistance}; 
				   case "civ":	{civilian};
				   default {west};
				};
};
			
_pos 	= getposatl _fakeIed;
_iedDir =  getdir _fakeIed;

//We have an ammo not an object 
_isAmmo = if ((_fakeIed getVariable ["IEDClass",""]) != "") then {true} else {false};

if (_isAmmo) then 
{
	_dummy 		= _fakeIed;
	_fakeIed 	= (_fakeIed getVariable ["IEDClass",""]) createVehicle _pos; 
} 
else 
{
	_dummy = MCC_dummy createVehicle _pos;
	_init = '_this hideobject true;';
	[[[netid _dummy,_dummy], _init], "MCC_fnc_setVehicleInit", true, true] spawn BIS_fnc_MP;
};

_dummy addEventHandler ["handleDamage",{_this call MCC_fnc_iedHit;0}];

if (_isAmmo) then
{
	
	_dummy addaction ["<t color=""#FF0000"">- Disarm IED -</t>",MCC_path + "mcc\general_scripts\traps\ied_disarm.sqf","",6,true,true,"_target distance _this < 5"];
	_fakeIed attachto [_dummy,[0,0,0]];
	if (!isnil "MCC_curator") then {MCC_curator addCuratorEditableObjects [[_dummy],false]}; 
}
else
{
	_fakeIed addaction ["<t color=""#FF0000"">- Disarm IED -</t>",MCC_path + "mcc\general_scripts\traps\ied_disarm.sqf","",6,true,true,"_target distance _this < 5"];
	_dummy attachto [_fakeIed,[0,0,0]];
};

[_fakeIed, _dummy] spawn
{
	private ["_fakeIedS"];
	_fakeIedS 	= _this select 0;
	_dummy 		= _this select 1;
	waituntil {!alive _fakeIedS || isnull _fakeIedS};
	sleep 1;
	deletevehicle _dummy;
};
	
_dummy setvariable ["fakeIed", _fakeIed ,true];
_dummy setvariable ["armed", true, true];
_dummy setvariable ["disarmTime", _IEDDisarmTime, true];
_dummy setvariable ["iedMarkerName", "IED", true];
_dummy setvariable ["iedTrigered", false, true]; 
_dummy setvariable ["iedAmbush", false, true];

//If it is radio IED
if (_IEDTriggerType == 1) then 
{
	_dummy setvariable ["iedTrigereRadio", true, true];
}
else
{
	_dummy setvariable ["iedTrigereRadio", false, true];
};	
	
_fakeIed setvariable ["realIed", _dummy ,true];

//Sync it with pre-sync IED
if (str (_fakeIed getVariable ["syncedObject", [0,0,0]]) != "[0,0,0]") then
{
	[[getpos _fakeIed , (_fakeIed getVariable ["syncedObject", [0,0,0]])],"MCC_fnc_iedSync",false,false] call BIS_fnc_MP;
};

//Spawn the IED script
_ok = [_dummy,_trapvolume,_IEDExplosionType,_IEDJammable,_IEDTriggerType,_trapdistance,_iedside] execVM MCC_path +"mcc\general_scripts\traps\IED.sqf";

		


[_dummy,_fakeIed];