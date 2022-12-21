/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyCanvas.h"
#include "MDJS.hpp"

void MyCanvas::mAnimation_Player()
{
    Data_Handler dh;

    dh.Texture_Container[0].mTime = Clock.getElapsedTime();
    std::cout << "Previous Time: " << dh.Texture_Container[0].Previous_mTime << "\n"
              << "Timer: " << dh.Texture_Container[0].mTime.asSeconds() << "\n";

    if(!dh.Texture_Container[0].mAnimation_Play)
    {
        Animation_Not_Playing();
    }

    else if(dh.Texture_Container[0].mAnimation_Play)
    {
        if(dh.Texture_Container[0].mTime.asSeconds() >= dh.Texture_Container[0].Previous_mTime + dh.Texture_Container[0].mAnimationSpeed)
        {
            std::cout << "\n\nTIMED\n\n";
            dh.Texture_Container[0].Previous_mTime = dh.Texture_Container[0].mTime.asSeconds();

            mAnimation_Play();
        }
    }

    dh.Object_Container[0].sprite.setTextureRect(dh.Object_Container[0].sprite_IntRect);
}
