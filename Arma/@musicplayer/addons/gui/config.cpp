class CfgPatches {
  class MusicPlayer_P {
    units[] = {};
    weapons[] = {};
    requiredAddons[] = {
      "cba_xeh"
    };
    requiredVersion = 0.1;
  };
};

class CfgFunctions {
  class MusicPlayer {
    class GUI {
      class MusicPlayer_Scripts {
        file = "\gui\initMusicPlayer.sqf";
        preInit = 1;
        postInit = 0;
        recompile = 0;
        ext = ".sqf";
      };
    };
  };
};

class Extended_Init_EventHandlers {
  class CAManBase {
    Init_Music_Player = "(_this select 0) call initMusicPlayer;";
  };
};

#include "guidefines.hpp"
#include "control.hpp"