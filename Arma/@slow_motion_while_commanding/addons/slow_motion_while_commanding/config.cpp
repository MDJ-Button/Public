class CfgPatches 
{
	class ADDON 
	{
			// Meta information for editor
			name = "Slow Motion While Commanding";
			author = "mdjbutton";
			url = "https://steamcommunity.com/id/mdjbutton/myworkshopfiles/?appid=107410";

			requiredVersion = 0.1; 
			requiredAddons[] = {"CBA_Extended_EventHandlers"};
			units[] = {};
			weapons[] = {};
	};
};

class Extended_PostInit_EventHandlers
{
	SMWC_init = "call compile preprocessFileLineNumbers 'slow_motion_while_commanding\init.sqf';";
};