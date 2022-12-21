/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyCanvas.h"

void MyCanvas::Animation_Player()
{
    Data_Handler dh;

    dh.Texture_Container[0].Time_Up = Clock.getElapsedTime();
    std::cout << "Up Previous Time: " << dh.Texture_Container[0].Previous_Time_Up << "\n"
              << "Up Timer: " << dh.Texture_Container[0].Time_Up.asSeconds() << "\n\n";

    dh.Texture_Container[0].Time_Down = Clock.getElapsedTime();
    std::cout << "Down Previous Time: " << dh.Texture_Container[0].Previous_Time_Down << "\n"
              << "Down Timer: " << dh.Texture_Container[0].Time_Down.asSeconds() << "\n\n";

    dh.Texture_Container[0].Time_Left = Clock.getElapsedTime();
    std::cout << "Left Previous Time: " << dh.Texture_Container[0].Previous_Time_Left << "\n"
              << "Left Timer: " << dh.Texture_Container[0].Time_Left.asSeconds() << "\n\n";

    dh.Texture_Container[0].Time_Right = Clock.getElapsedTime();
    std::cout << "Right Previous Time: " << dh.Texture_Container[0].Previous_Time_Right << "\n"
              << "Right Timer: " << dh.Texture_Container[0].Time_Right.asSeconds() << "\n\n";


    if(!dh.Texture_Container[0].Animation_Move_Up_Play
    && !dh.Texture_Container[0].Animation_Move_Down_Play
    && !dh.Texture_Container[0].Animation_Move_Left_Play
    && !dh.Texture_Container[0].Animation_Move_Right_Play)
    {
        Animation_Not_Playing();
    }

    else if( dh.Texture_Container[0].Animation_Move_Up_Play
         && !dh.Texture_Container[0].Animation_Move_Down_Play
         && !dh.Texture_Container[0].Animation_Move_Left_Play
         && !dh.Texture_Container[0].Animation_Move_Right_Play)
    {
        if(dh.Texture_Container[0].Time_Up.asSeconds() >= dh.Texture_Container[0].Previous_Time_Up + dh.Texture_Container[0].AnimationSpeed_Up)
        {
            std::cout << "\n\nTIMED_UP\n\n";
            dh.Texture_Container[0].Previous_Time_Up = dh.Texture_Container[0].Time_Up.asSeconds();

            Animation_Move_Up_Play();
        }
    }

    else if(!dh.Texture_Container[0].Animation_Move_Up_Play
         &&  dh.Texture_Container[0].Animation_Move_Down_Play
         && !dh.Texture_Container[0].Animation_Move_Left_Play
         && !dh.Texture_Container[0].Animation_Move_Right_Play)
    {
        if(dh.Texture_Container[0].Time_Down.asSeconds() >= dh.Texture_Container[0].Previous_Time_Down + dh.Texture_Container[0].AnimationSpeed_Down)
        {
            std::cout << "\n\nTIMED_DOWN\n\n";
            dh.Texture_Container[0].Previous_Time_Down = dh.Texture_Container[0].Time_Down.asSeconds();

            Animation_Move_Down_Play();
        }
    }

    else if(!dh.Texture_Container[0].Animation_Move_Up_Play
         && !dh.Texture_Container[0].Animation_Move_Down_Play
         &&  dh.Texture_Container[0].Animation_Move_Left_Play
         && !dh.Texture_Container[0].Animation_Move_Right_Play)
    {
        if(dh.Texture_Container[0].Time_Left.asSeconds() >= dh.Texture_Container[0].Previous_Time_Left + dh.Texture_Container[0].AnimationSpeed_Left)
        {
            std::cout << "\n\nTIMED_LEFT\n\n";
            dh.Texture_Container[0].Previous_Time_Left = dh.Texture_Container[0].Time_Left.asSeconds();

            Animation_Move_Left_Play();
        }
    }

    else if(!dh.Texture_Container[0].Animation_Move_Up_Play
         && !dh.Texture_Container[0].Animation_Move_Down_Play
         && !dh.Texture_Container[0].Animation_Move_Left_Play
         &&  dh.Texture_Container[0].Animation_Move_Right_Play)
    {
        if(dh.Texture_Container[0].Time_Right.asSeconds() >= dh.Texture_Container[0].Previous_Time_Right + dh.Texture_Container[0].AnimationSpeed_Right)
        {
            std::cout << "\n\nTIMED_RIGHT\n\n";
            dh.Texture_Container[0].Previous_Time_Right = dh.Texture_Container[0].Time_Right.asSeconds();

            Animation_Move_Right_Play();
        }
    }

    dh.Object_Container[0].sprite.setTextureRect(dh.Object_Container[0].sprite_IntRect);
}
