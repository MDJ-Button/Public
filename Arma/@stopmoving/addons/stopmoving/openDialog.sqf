createDialog "dialogTest";
//_crtl = (findDisplay 1234) displayCtrl 1500;

selectedUnitsList = [];
AIList = [];
AIListString = [];

{
	if(alive _x) then
	{
		_name = name _x;
		_role = [configFile >> "CfgVehicles" >> typeOf vehicle _x] call BIS_fnc_displayName;
		_path_enabled = "Can Move";
		_autocombat_enabled = "AutoCombat On";
		
		if(_x checkAIFeature "PATH") then 
		{ 
			_path_enabled = "Can Move";
		}
		else
		{
			_path_enabled = "Cannot Move";
		};
		
		if(_x checkAIFeature "AutoCombat") then 
		{ 
			_autocombat_enabled = "AutoCombat On";
		}
		else
		{
			_autocombat_enabled = "AutoCombat Off";
		};
		
		_ToAdd = _name + ": " + _role + ", " + _path_enabled + ", " + _autocombat_enabled;
		
		if(_name != name player) then
		{	
			AIList pushBack _x;
			AIListString pushBack lbAdd [1500, _ToAdd];
		}
	}

} forEach units player;