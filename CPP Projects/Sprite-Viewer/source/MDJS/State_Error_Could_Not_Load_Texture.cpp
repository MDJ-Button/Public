/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MDJS.hpp"

std::string MDJS::State_Error_Could_Not_Load_Texture(std::string func, std::string Name_of_Texture)
{
    return State_Error + " " + Name_of_Texture + " could not be loaded or is missing! Calling from function -> " + func;
}
