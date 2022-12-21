while {true} do 
{
	if(ShowHints == 1) then { hint "Addon Active"; };

	sleep 2;														// A short delay.
	_availableUnits = count switchableUnits; 						// Counts the number of switchable units.
	_teamsize = {alive _x} count units player;						// Counts all the alive units in the player's group.

	if(_availableUnits != _teamsize) then 							// Checks if the number of switchable units is unequal to the player's group size.
	{
		if(ShowHints == 1) then { hint "Removing units"; };			// For testing.
		{  removeSwitchableUnit _x } forEach units side player;		// Removes all switchable units.
		
		[] execVM "amus\action.sqf"; 								// Calls the action.sqf script to make the units switchable again.
	};
	
	onTeamSwitch 													// Activates when the player switches to another unit.
	{ 	
		if(ShowHints == 1) then { hint "switch"; };					// For testing.
		{  removeSwitchableUnit _x } forEach units side player;		// Removes all switchable units.
		
		[] execVM "amus\action.sqf"; 								// Calls the action.sqf script to make the units switchable again.
	}
};