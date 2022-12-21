class CfgPatches {
  class AMUS_P {
    units[] = {};
    weapons[] = {};
    requiredAddons[] = {
      "cba_xeh"
    };
    requiredVersion = 0.1;
  };
};

class CfgFunctions {
  class AMUS {
    class TeamSwitch {
      class AMUS_Scripts {
        file = "\amus\Init.sqf";
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
    Init_AMUS_TeamSwitch = "(_this select 0) call InitAMUS;";
  };
};
