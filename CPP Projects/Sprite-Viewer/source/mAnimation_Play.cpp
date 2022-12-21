/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyCanvas.h"

void MyCanvas::mAnimation_Play()
{
    Data_Handler dh;

    if(dh.Texture_Container[0].mAnimation_Direction == "L")
    {
        dh.Object_Container[0].sprite_IntRect.top      = dh.Texture_Container[0].mAnimation_Row;
        dh.Object_Container[0].sprite_IntRect.width    = dh.Texture_Container[0].mAnimation_Width;
        dh.Object_Container[0].sprite_IntRect.height   = dh.Texture_Container[0].mAnimation_Height;

        if(dh.Object_Container[0].sprite_IntRect.left
        >= dh.Texture_Container[0].mAnimation_Reset)
        {
            dh.Object_Container[0].sprite_IntRect.left = dh.Texture_Container[0].mAnimation_Restart;
        }
        else dh.Object_Container[0].sprite_IntRect.left += dh.Texture_Container[0].mAnimation_Add;
    }

    else if(dh.Texture_Container[0].mAnimation_Direction == "T")
    {
        dh.Object_Container[0].sprite_IntRect.left     = dh.Texture_Container[0].mAnimation_Row;
        dh.Object_Container[0].sprite_IntRect.width    = dh.Texture_Container[0].mAnimation_Width;
        dh.Object_Container[0].sprite_IntRect.height   = dh.Texture_Container[0].mAnimation_Height;

        if(dh.Object_Container[0].sprite_IntRect.top
        >= dh.Texture_Container[0].mAnimation_Reset)
        {
            dh.Object_Container[0].sprite_IntRect.top = dh.Texture_Container[0].mAnimation_Restart;
        }
        else dh.Object_Container[0].sprite_IntRect.top += dh.Texture_Container[0].mAnimation_Add;
    }
}
