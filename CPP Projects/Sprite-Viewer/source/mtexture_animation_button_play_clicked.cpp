/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyFrame.hpp"
#include "MDJS.hpp"

void MyFrame::mtexture_animation_play_button_clicked(wxCommandEvent& event)
{
    if(!MDJS::bFile_Loaded && MDJS::bMFile_Loaded)
    {
        Data_Handler dh;

        if(!dh.Texture_Container[0].mAnimation_Play)
        {
            MDJS::bState_MAnimation_Playing = true;
            dh.Texture_Container[0].mAnimation_Play = true;
        }
        else
        {
            MDJS::bState_MAnimation_Playing = false;
            dh.Texture_Container[0].mAnimation_Play = false;
        }

        MDJS::Status->SetStatusText(MDJS::State_MAnimation_Playing(__func__, MDJS::bState_MAnimation_Playing));
    }
}

