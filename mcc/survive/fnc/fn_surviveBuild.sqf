/*=================================================================MCC_fnc_surviveBuild=================================================================================
  Build a vehicle class infront of the player
  <In>
  		_itemCLass: 		STRING object/magazine class .
  		_buildClass: 		STRING vehicle class object will be spawned infront of the player
  		_removeObject:		STRING magazine class that will be removed also. Leave "" for not effect
  		_removeMainObject:  BOOLEAN if true - will remove _itemCLass
*/
private ["_returnItem","_buildClass","_removeObject","_removeMainObject"];
_itemClass =  param [0,"",[""]];
_buildClass =  param [1,"",[""]];
_removeObject =  param [2,"",[""]];
_removeMainObject =  param [3,false,[true]];

if (_removeObject != "") then {
	player removeMagazine _removeObject;
};

if (_removeMainObject) then {
	player removeMagazine _itemClass;
};

_buildClass createVehicle (player modelToWorld [0,1,0]);