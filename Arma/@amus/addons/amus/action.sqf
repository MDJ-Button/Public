if(ShowHints == 1) then { hint "Adding units"; };		// For testing.

{ addSwitchableUnit _x } forEach units player;			// Makes all group members under the player's control switchable.