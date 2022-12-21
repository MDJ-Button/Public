/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#ifndef MDJS_HPP
#define MDJS_HPP

#include <string>

#include <wx/statusbr.h>

#include <SFML/Graphics.hpp>

namespace MDJS
{
    extern wxStatusBar *Status;

    extern bool bFile_New;
    extern bool bFile_Loaded;
    extern bool bMFile_Loaded;

    extern bool bState_Error_Could_Not_Load_Texture;
    extern bool bState_Error_Animation_Undefined_Direction;

    extern bool bState_MAnimation_Playing;
    extern bool bState_Animation_Up_Playing;
    extern bool bState_Animation_Down_Playing;
    extern bool bState_Animation_Left_Playing;
    extern bool bState_Animation_Right_Playing;

    extern std::string State_Okay;
    extern std::string State_Error;
    extern std::string DialogPath;

    std::string State_Error_Could_Not_Load_Texture(std::string func, std::string Name_of_Texture);
    std::string State_Error_Animation_Undefined_Direction(std::string func, std::string Given_Input);

    std::string State_MAnimation_Playing(std::string func, bool Playing);
    std::string State_Animation_Up_Playing(std::string func, bool Playing);
    std::string State_Animation_Down_Playing(std::string func, bool Playing);
    std::string State_Animation_Left_Playing(std::string func, bool Playing);
    std::string State_Animation_Right_Playing(std::string func, bool Playing);

    extern sf::Clock Clock;
};

#endif // MDJS_HPP
