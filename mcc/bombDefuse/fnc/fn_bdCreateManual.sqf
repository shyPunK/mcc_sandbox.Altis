/*=================================================================MCC_fnc_bdCreateManual==================================================================================
  Create the bomb defuse manual
*/
private ["_difficulty","_modules","_noModules","_isEngineer","_disarmTime","_pos","_target"];

if !(hasInterface) exitWith {};
waituntil {alive player};

player createDiarySubject ["bombManual","Bomb Manual"];

player createDiaryRecord ["bombManual", ["Numpad Module","<font color='#add118' size=20>Numpad Module</font><br/>Punch the numpad buttons in the right order as their symbols appear from left to right.<br/><br/><font color='#add118' size=15>Serial Number Divided by 7</font><br/>[ ^ , p , 2 , P , M , N , 0 , n , o , % , # , ) , } , | , i , m , I ]<br/><br/><font color='#add118' size=15>Otherwise</font><br/>[ 0 , m , ) , o , | , # , ^ , n , P , i , N , 2 , I , M , % , p , } ]"]];

player createDiaryRecord ["bombManual", ["Checkbox Module","<font color='#add118' size=20>Checkbox Module</font><br/>Flag each checkbox according to the symbol above it and the type of bomb.<br/><br/><font color='#add118' size=15>Serial Number Divided by 3 And 7</font><br/>@ - off      1 - off<br/>^ - on       ~ - on<br/>) - on       ] - on<br/>( - off      [ - on<br/>| - on       \ - off<br/>/ - off      ? - off<br/>3 - off      % - off<br/>* - on       L - on<br/>8 - on       5 - off<br/>; - on      A - off<br/>a - on       g - off<br/>G - on       b - off<br/>B - on       p - off<br/>P - on       w - on <br/>W - off      m - on<br/>n - off      N - on<br/>M - off      t - on <br/>T - off       ` - on<br/>: - off       o - on <br/>0 - off<br/><br/><font color='#add118' size=15>Serial Number Divided By 3 Only</font><br/>@ - off      1 - off<br/>^ - off       ~ - on<br/>) - on       ] - on<br/>( - off      [ - on<br/>| - on       \ - off<br/>/ - off      ? - off<br/>3 - off      % - on <br/>* - off       L - on<br/>8 - off       5 - off<br/>; - on      A - on<br/>a - off       g - off<br/>G - on       b - on<br/>B - on       p - on<br/>P - off       w - on <br/>W - off      m - off<br/>n - off      N - off<br/>M - on      t - on <br/>T - on       ` - off<br/>: - off       o - on <br/>0 - off<br/><br/><font color='#add118' size=15>Otherwise</font><br/>@ - off      1 - off<br/>^ - on       ~ - off<br/>) - on       ] - off<br/>( - on      [ - off<br/>| - off       \ - off<br/>/ - off      ? - on<br/>3 - on      % - on <br/>* - on       L - on<br/>8 - on       5 - off<br/>; - off      A - off<br/>a - on       g - on<br/>G - off       b - off<br/>B - on       p - off<br/>P - off       w - off <br/>W - off      m - on<br/>n - off      N - on<br/>M - off      t - on <br/>T - off       ` - on<br/>: - off       o - off <br/>0 - off"]];

player createDiaryRecord ["bombManual", ["Wires Module","<font color='#add118' size=20>Wires Module</font><br/>Each wire module can have between 3-8 wires in different colors.<br/>You have to cut one wire to disarm the module<br/>Cutting the wrong wire will cost one strike.<br/><br/><font color='#add118' size=15>Serial Number divided by 3</font><br/><br/>3 wires:<br/>If there are no red wires, cut the first wire.<br/>Otherwise, If the last wire is green, cut the last wire<br/>Otherwise, if there is a blue wire, cut the blue wire<br/>Otherwise, if there is a black wire, cut the black wire<br/>Otherwise, cut the second wire.<br/><br/>4-5 wires:<br/>If there are no white wires, cut the second wire.<br/>Otherwise, If the last wire is black, cut the last wire<br/>Otherwise, if there is a green wire, cut the green wire<br/>Otherwise, if there is a red wire, cut the red wire<br/>Otherwise, cut the third wire.<br/><br/>6+ wires:<br/>If there are no green wires, cut the third wire.<br/>Otherwise, If the last wire is blue, cut the last wire<br/>Otherwise, if there is a black wire, cut the black wire<br/>Otherwise, if there is a white wire, cut the white wire<br/>Otherwise, cut the first wire.<br/><br/><font color='#add118' size=15>Serial Number not divided by 3</font><br/><br/>3 wires:<br/>If there are no green wires, cut the first wire.<br/>Otherwise, If the last wire is white, cut the last wire<br/>Otherwise, if there is a black wire, cut the black wire<br/>Otherwise, if there is a blue wire, cut the blue wire<br/>Otherwise, cut the second wire.<br/><br/>4-5 wires:<br/>If there are no blue wires, cut the second wire.<br/>Otherwise, If the last wire is white, cut the last wire<br/>Otherwise, if there is a red wire, cut the red wire<br/>Otherwise, if there is a blue wire, cut the blue wire<br/>Otherwise, cut the third wire.<br/><br/>6+ wires<br/>If there are no red wires, cut the third wire.<br/>Otherwise, If the last wire is black, cut the last wire<br/>Otherwise, if there is a white wire, cut the white wire<br/>Otherwise, if there is a green wire, cut the green wire<br/>Otherwise, cut the first wire."]];

player createDiaryRecord ["bombManual", ["General","<font color='#add118' size=20>Bombs </font><br/>Once the bomb timer has started you can't stop it.<br/>The bomb will explode when its countdown timer reaches zero or if you close the dialog or had 3 strikes.<br/>In-order to defuse the bomd you'll have to defuse each of its modules before the time runs out.<br/><br/><br/><font color='#add118' size=20>Modules</font><br/>Each bomb can have multiple modules depends on its difficulty. Each module have is discrete and can be disarmed in any given time - but you'll need to disarm all the modules before the clock ticks out to prevent the bomb from exploding.<br/>Since you can't close the dialog while disarming a bomb you'll have to really on another player who have the bomb manual open infront of him and he'll have to guide you in the process of disarming the modules.<br/><br/><font color='#add118' size=20>Serial Number</font><br/>Each bomb has its own unique serial number printed on the front. Pay attention to the serial number as it will effect the method of disarming the bomb."]];