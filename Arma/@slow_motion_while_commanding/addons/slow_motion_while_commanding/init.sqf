[] call compileFinal preprocessFileLineNumbers "\slow_motion_while_commanding\fnc\setGameSpeed.sqf";

[] spawn 
{
	while {true} do 
	{
		if(commandingMenu != "") then 
		{ 
			0.05 call setGameSpeed
		}
		else
		{
			if(commandingMenu == "") then 
			{ 
				1 call setGameSpeed
			};
		};

		uiSleep 0.001;
	};
};
