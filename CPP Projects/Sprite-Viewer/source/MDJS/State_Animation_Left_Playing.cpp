/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MDJS.hpp"

std::string MDJS::State_Animation_Left_Playing(std::string func, bool Playing)
{
    std::string State = "Not Playing";
    if(Playing) State = "Playing";
    return "Animation Left " + State + ". Calling from function -> " + func;
}

