InitAMUS = {
	// Sets the script up and starts the loop

	// ShowHints = 0 is false and will not hint the test messages.
	// ShowHints = 1 is true and will hint the test messages.
	ShowHints = 0;

	[] execVM "amus\action.sqf";
	[] execVM "amus\loop.sqf"; 
}