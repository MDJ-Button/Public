/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyCanvas.h"

void MyCanvas::Animation_Move_Right_Play()
{
    Data_Handler dh;

    if(dh.Texture_Container[0].Animation_Move_Right_Direction == "L")
    {
        dh.Object_Container[0].sprite_IntRect.top      = dh.Texture_Container[0].Animation_Move_Right_Row;
        dh.Object_Container[0].sprite_IntRect.width    = dh.Texture_Container[0].Animation_Move_Right_Width;
        dh.Object_Container[0].sprite_IntRect.height   = dh.Texture_Container[0].Animation_Move_Right_Height;

        if(dh.Object_Container[0].sprite_IntRect.left
        >= dh.Texture_Container[0].Animation_Move_Right_Reset)
        {
            dh.Object_Container[0].sprite_IntRect.left = dh.Texture_Container[0].Animation_Move_Right_Restart;
        }
        else dh.Object_Container[0].sprite_IntRect.left += dh.Texture_Container[0].Animation_Move_Right_Add;
    }

    else if(dh.Texture_Container[0].Animation_Move_Right_Direction == "T")
    {
        dh.Object_Container[0].sprite_IntRect.left     = dh.Texture_Container[0].Animation_Move_Right_Row;
        dh.Object_Container[0].sprite_IntRect.width    = dh.Texture_Container[0].Animation_Move_Right_Width;
        dh.Object_Container[0].sprite_IntRect.height   = dh.Texture_Container[0].Animation_Move_Right_Height;

        if(dh.Object_Container[0].sprite_IntRect.top
        >= dh.Texture_Container[0].Animation_Move_Right_Reset)
        {
            dh.Object_Container[0].sprite_IntRect.top = dh.Texture_Container[0].Animation_Move_Right_Restart;
        }
        else dh.Object_Container[0].sprite_IntRect.top += dh.Texture_Container[0].Animation_Move_Right_Add;
    }
}
