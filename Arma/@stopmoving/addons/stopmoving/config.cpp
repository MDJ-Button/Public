class CfgPatches {
  class STOP_P {
    units[] = {};
    weapons[] = {};
    requiredAddons[] = {
      "cba_xeh"
    };
    requiredVersion = 0.1;
  };
};

class CfgFunctions {
  class STOP {
    class MOVING {
      class STOP_MOVING_Scripts {
        file = "\stopmoving\initStop.sqf";
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
    Init_STOP_MOVING = "(_this select 0) call initStop;";
  };
};

#include "guidefines.hpp"
#include "control.hpp"