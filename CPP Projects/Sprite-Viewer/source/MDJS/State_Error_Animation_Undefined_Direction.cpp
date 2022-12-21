/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MDJS.hpp"

std::string MDJS::State_Error_Animation_Undefined_Direction(std::string func, std::string Given_Input)
{
    return State_Error + " " + Given_Input + " given. Expected \"T\" or \"L\"! Calling from function -> " + func;
}

