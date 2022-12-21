_showDebugMessages = 0;

if(MusicPlayer_Volume != 5) then 
{
	MusicPlayer_Volume = MusicPlayer_Volume + 1;
	0 fadeMusic MusicPlayer_Volume;
};

if(_showDebugMessages == 1) then { systemChat format["%1, %2", str musicVolume, MusicPlayer_Volume]; };