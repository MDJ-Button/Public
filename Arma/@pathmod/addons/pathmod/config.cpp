class CfgPatches {
  class pathmod_P {
    units[] = {};
    weapons[] = {};
    requiredAddons[] = {
      "cba_xeh"
    };
    requiredVersion = 0.1;
  };
};

class CfgFunctions {
  class pathmod {
    class pathmod_s {
      class pathmod_Scripts {
        file = "\pathmod\Init.sqf";
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
    Init_pathmod = "(_this select 0) call Initpathmod;";
  };
};
