class MusicPlayer
{
	idd = 1234;

	class Controls
	{
		class Title: RscText
		{
			idc = 1000;
			text = "Music Player"; //--- ToDo: Localize;
			x = 0.02 * safezoneW + safezoneX;
			y = 0.02 * safezoneH + safezoneY;
			w = 0.2 * safezoneW;
			h = 0.05 * safezoneH;
			colorBackground[] = {0,0,0,0.8};
		};

		class ListBox: RscListbox
		{
			idc = 1500;
			x = 0.02 * safezoneW + safezoneX;
			y = 0.07 * safezoneH + safezoneY;
			w = 0.2 * safezoneW;
			h = 0.5 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
			style = "0";

			class ListScrollBar
			{
				color[] = {255,255,255,1};
				autoScrollEnabled = 1;
			};
		};

		class PlayBtn: RscButton
		{
			idc = 1600;
			text = "Play"; //--- ToDo: Localize;
			x = 0.02 * safezoneW + safezoneX;
			y = 0.571 * safezoneH + safezoneY;
			w = 0.2 * safezoneW;
			h = 0.05 * safezoneH;
			colorBackground[] = {0,0,0,0.8};
			action = "execVM '\gui\play.sqf'";
		};
		class StopBtn: RscButton
		{
			idc = 1601;
			text = "Stop"; //--- ToDo: Localize;
			x = 0.02 * safezoneW + safezoneX;
			y = 0.62 * safezoneH + safezoneY;
			w = 0.2 * safezoneW;
			h = 0.05 * safezoneH;
			colorBackground[] = {0,0,0,0.8};
			action = "execVM '\gui\stop.sqf'";
		};
		class TurnUpVolumeBtn: RscButton
		{
			idc = 1602;
			text = "Turn Up Volume"; //--- ToDo: Localize;
			x = 0.02 * safezoneW + safezoneX;
			y = 0.67 * safezoneH + safezoneY;
			w = 0.2 * safezoneW;
			h = 0.05 * safezoneH;
			colorBackground[] = {0,0,0,0.8};
			action = "execVM '\gui\turnupvolume.sqf'";
		};
		class TurnDownVolumeBtn: RscButton
		{
			idc = 1603;
			text = "Turn Down Volume"; //--- ToDo: Localize;
			x = 0.02 * safezoneW + safezoneX;
			y = 0.719 * safezoneH + safezoneY;
			w = 0.2 * safezoneW;
			h = 0.05 * safezoneH;
			colorBackground[] = {0,0,0,0.8};
			action = "execVM '\gui\turndownvolume.sqf'";
		};
	};
};
