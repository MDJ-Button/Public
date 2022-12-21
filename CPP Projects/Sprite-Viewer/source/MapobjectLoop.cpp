/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyCanvas.h"

void MyCanvas::MapobjectLoop()
{
    Data_Handler dh;

    if(dh.Object_Container[0].texture.loadFromFile(Load(dh.Object_Container[0].Texture)))
    {
        if(MDJS::bState_Error_Could_Not_Load_Texture)
        {
            MDJS::bState_Error_Could_Not_Load_Texture = false;
            MDJS::Status->SetStatusText(MDJS::State_Okay);
        }

        bDraw_Sprite = true;

        dh.Object_Container[0].sprite.setTexture(dh.Object_Container[0].texture);
        dh.Object_Container[0].sprite.setScale(dh.Object_Container[0].ScaleX, dh.Object_Container[0].ScaleY);
        dh.Object_Container[0].sprite.setPosition(this->getSize().x / 2
                                                  - dh.Object_Container[0].sprite.getGlobalBounds().width / 2,
                                                  this->getSize().y / 2
                                                  - dh.Object_Container[0].sprite.getGlobalBounds().height / 2);
        mAnimation_Player();
    }

    else
    {
        if(!MDJS::bState_Error_Could_Not_Load_Texture)
        {
            MDJS::bState_Error_Could_Not_Load_Texture = true;
            MDJS::Status->SetStatusText(MDJS::State_Error_Could_Not_Load_Texture(__func__, dh.Object_Container[0].Texture));
        }
    }
}
