class dialogTest
{
	idd = 1234;

	class controls
	{
		class listbox_selected_units: RscListBox
		{
			idc = 1500;
			//style = "0x20";
			x = 0.01 * safezoneW + safezoneX;
			y = 0.01 * safezoneH + safezoneY;
			w = 0.4 * safezoneW;
			h = 0.4 * safezoneH;
		};
		class text: RscText
		{
			idc = 1000;
			text = "For Selected Unit/Units"; //--- ToDo: Localize;
			x = 0.01 * safezoneW + safezoneX;
			y = 0.41 * safezoneH + safezoneY;
			w = 0.25 * safezoneW;
			h = 0.05 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class btn_toggle_move: RscButton
		{
			idc = 1600;
			text = "Toggle Movement"; //--- ToDo: Localize;
			x = 0.01 * safezoneW + safezoneX;
			y = 0.459 * safezoneH + safezoneY;
			w = 0.15 * safezoneW;
			h = 0.05 * safezoneH;
			colorBackground[] = {255,165,0,0.5};
			action = "execVM '\stopmoving\togglepath.sqf'";
		};
		class btn_toggle_autocombat: RscButton
		{
			idc = 1601;
			text = "Toggle AutoCombat"; //--- ToDo: Localize;
			x = 0.01 * safezoneW + safezoneX;
			y = 0.509 * safezoneH + safezoneY;
			w = 0.15 * safezoneW;
			h = 0.05 * safezoneH;
			colorBackground[] = {255,165,0,0.5}; 
			action = "execVM '\stopmoving\toggleautocombat.sqf'";
		};
		class btn_select_all: RscButton
		{
			idc = 1603;
			text = "Select All"; //--- ToDo: Localize;
			x = 0.16 * safezoneW + safezoneX;
			y = 0.459 * safezoneH + safezoneY;
			w = 0.15 * safezoneW;
			h = 0.05 * safezoneH;
			colorBackground[] = {255,165,0,0.5};
			action = "execVM '\stopmoving\selectall.sqf'";
		};
		class btn_deselect_all: RscButton
		{
			idc = 1604;
			text = "Deselect All"; //--- ToDo: Localize;
			x = 0.16 * safezoneW + safezoneX;
			y = 0.509 * safezoneH + safezoneY;
			w = 0.15 * safezoneW;
			h = 0.05 * safezoneH;
			colorBackground[] = {255,165,0,0.5};
			action = "execVM '\stopmoving\deselectall.sqf'";
		};
		class btn_select_unit: RscButton
		{
			idc = 1605;
			text = "Select Unit"; //--- ToDo: Localize;
			x = 0.31 * safezoneW + safezoneX;
			y = 0.459 * safezoneH + safezoneY;
			w = 0.10 * safezoneW;
			h = 0.05 * safezoneH;
			colorBackground[] = {255,165,0,0.5};
			action = "execVM '\stopmoving\select.sqf'";
		};
		class btn_deselect_unit: RscButton
		{
			idc = 1606;
			text = "Deselect Unit"; //--- ToDo: Localize;
			x = 0.31 * safezoneW + safezoneX;
			y = 0.509 * safezoneH + safezoneY;
			w = 0.10 * safezoneW;
			h = 0.05 * safezoneH;
			colorBackground[] = {255,165,0,0.5};
			action = "execVM '\stopmoving\deselect.sqf'";
		};
		class btn_set_careless: RscButton
		{
			idc = 1607;
			text = "Set To Careless"; //--- ToDo: Localize;
			x = 0.26 * safezoneW + safezoneX;
			y = 0.41 * safezoneH + safezoneY;
			w = 0.15 * safezoneW;
			h = 0.05 * safezoneH;
			colorBackground[] = {255,165,0,0.5};
			action = "execVM '\stopmoving\setcareless.sqf'";
		};
	};
};
