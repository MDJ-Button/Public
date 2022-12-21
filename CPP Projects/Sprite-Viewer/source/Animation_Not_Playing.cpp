/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyCanvas.h"

void MyCanvas::Animation_Not_Playing()
{
    Data_Handler dh;

    dh.Object_Container[0].sprite_IntRect.top = dh.Texture_Container[0].TextureRect_T;
    dh.Object_Container[0].sprite_IntRect.left = dh.Texture_Container[0].TextureRect_L;
    dh.Object_Container[0].sprite_IntRect.width = dh.Texture_Container[0].TextureRect_W;
    dh.Object_Container[0].sprite_IntRect.height = dh.Texture_Container[0].TextureRect_H;
}
