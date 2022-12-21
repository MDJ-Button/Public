/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MDJS.hpp"

sf::Clock Clock;

wxStatusBar *MDJS::Status;
bool MDJS::bFile_New = false;
bool MDJS::bFile_Loaded = false;
bool MDJS::bMFile_Loaded = false;

bool MDJS::bState_Error_Could_Not_Load_Texture;
bool MDJS::bState_Error_Animation_Undefined_Direction;

bool MDJS::bState_MAnimation_Playing = false;
bool MDJS::bState_Animation_Up_Playing = false;
bool MDJS::bState_Animation_Down_Playing = false;
bool MDJS::bState_Animation_Left_Playing = false;
bool MDJS::bState_Animation_Right_Playing = false;

std::string MDJS::State_Okay  = "All good!";
std::string MDJS::State_Error = "Error!";

std::string MDJS::DialogPath;
