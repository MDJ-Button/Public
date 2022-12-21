MusicPlayer_Volume = 2;
1 fadeMusic MusicPlayer_Volume;

fnc_toggle_musicplayer = {
	[] execVM "\gui\openDialog.sqf";
};

initMusicPlayer = {
	["Music Player", "musicplayer_key", "Bring Up Music Player", {[] call fnc_toggle_musicplayer}, {}, [25, [false, true, false]], false] call CBA_fnc_addKeybind;
}