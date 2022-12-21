_showDebugMessages = 0;

createDialog "MusicPlayer";
_crtl = (findDisplay 1234) displayCtrl 1500;

_onlyShowCustomTracks = 0;

SongList = [];
SongCount = [1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
			 11, 12, 13, 14, 15, 16, 17, 18, 19, 20];

subclasses = [configFile >> "CfgMusic"] call Bis_fnc_getCfgSubClasses; 
 
{
	if(_onlyShowCustomTracks == 1) then
	{
		for "_i" from 1 to count SongCount do
		{
			_y = "Custom_Track" + str _i;
			if(str _x == str _y) then
			{
				if(_showDebugMessages == 1) then { systemChat format["%1 == %2 is true.", str _x, str _y]; };
				SongList pushBack lbAdd [1500, _x];
			}
			else
			{
				if(_showDebugMessages == 1) then { systemChat format["%1 == %2 is false.", str _x, str _y]; };
			};	  
		};
	}
	else
	{
		SongList pushBack lbAdd [1500, _x];
	};
} forEach subclasses;