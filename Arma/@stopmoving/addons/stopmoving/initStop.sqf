fnc_toggle_dialog = {
	[] execVM "\stopmoving\openDialog.sqf";
};

initStop = {
	["Stop Moving!", "stop_moving_key", "Bring Up Dialog", {_this call fnc_toggle_dialog}, "", [48, [false, true, false]]] call CBA_fnc_addKeybind;
}