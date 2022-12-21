/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyFrame.hpp"
#include "MDJS.hpp"

void MyFrame::texture_animation_move_right_button_clicked(wxCommandEvent& event)
{
    if(MDJS::bFile_Loaded && !MDJS::bMFile_Loaded)
    {
        Data_Handler dh;
        std::string newvalue;
        newvalue = texture_animation_move_right_textbox->GetValue();

        if(FileHandler::Prase::Line_Str_Array(newvalue, 0) == "L"
        || FileHandler::Prase::Line_Str_Array(newvalue, 0) == "T")
        {
            if(MDJS::bState_Error_Animation_Undefined_Direction)
            {
                MDJS::bState_Error_Animation_Undefined_Direction = false;
                MDJS::Status->SetStatusText(MDJS::State_Okay);
            }
            dh.Texture_Container[0].Animation_Move_Right_Direction = FileHandler::Prase::Line_Str_Array(newvalue, 0);
        }
        else
        {
            if(!MDJS::bState_Error_Animation_Undefined_Direction)
            {
                MDJS::bState_Error_Animation_Undefined_Direction = true;
                MDJS::Status->SetStatusText(MDJS::State_Error_Animation_Undefined_Direction(__func__, FileHandler::Prase::Line_Str_Array(newvalue, 0)));
            }
            dh.Texture_Container[0].Animation_Move_Right_Direction = "L";
        }

        dh.Texture_Container[0].Animation_Move_Right_Row       = FileHandler::Prase::Line_Int_Array(newvalue, 1);
        dh.Texture_Container[0].Animation_Move_Right_Reset     = FileHandler::Prase::Line_Int_Array(newvalue, 2);
        dh.Texture_Container[0].Animation_Move_Right_Add       = FileHandler::Prase::Line_Int_Array(newvalue, 3);
        dh.Texture_Container[0].Animation_Move_Right_Restart   = FileHandler::Prase::Line_Int_Array(newvalue, 4);
        dh.Texture_Container[0].Animation_Move_Right_Width     = FileHandler::Prase::Line_Int_Array(newvalue, 5);
        dh.Texture_Container[0].Animation_Move_Right_Height    = FileHandler::Prase::Line_Int_Array(newvalue, 6);
        dh.Texture_Container[0].AnimationSpeed_Right           = FileHandler::Prase::Line_Float_Array(newvalue, 7);

        dh.Texture_Container[0].Animation_Move_Right = dh.Texture_Container[0].Animation_Move_Right_Direction
                                                     + ", "
                                                     + std::to_string(dh.Texture_Container[0].Animation_Move_Right_Row)
                                                     + ", "
                                                     + std::to_string(dh.Texture_Container[0].Animation_Move_Right_Reset)
                                                     + ", "
                                                     + std::to_string(dh.Texture_Container[0].Animation_Move_Right_Add)
                                                     + ", "
                                                     + std::to_string(dh.Texture_Container[0].Animation_Move_Right_Restart)
                                                     + ", "
                                                     + std::to_string(dh.Texture_Container[0].Animation_Move_Right_Width)
                                                     + ", "
                                                     + std::to_string(dh.Texture_Container[0].Animation_Move_Right_Height)
                                                     + ", "
                                                     + std::to_string(dh.Texture_Container[0].AnimationSpeed_Right);

        info_listbox->SetString(20, "Animation_Move_Right: " + dh.Texture_Container[0].Animation_Move_Right);
    }
}



