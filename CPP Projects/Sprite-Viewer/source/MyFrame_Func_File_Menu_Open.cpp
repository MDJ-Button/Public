/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyFrame.hpp"
#include "FileHandler.h"
#include "MDJS.hpp"
#include <fstream>

void MyFrame::Func_File_Menu_Open(wxCommandEvent& event)
{
    std::cout << "\n\nLoading Object:\n\n";

    Data_Handler dh;

    //open dialog
    wxFileDialog
        openFileDialog(this, _("Open .object file"), "", "",
                       "Object files (*.object)|*.object", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if(openFileDialog.ShowModal() == wxID_CANCEL) return;

    wxFileInputStream input_stream(openFileDialog.GetPath());
    if(input_stream.IsOk())
    {
        dh.Object_Container[0].VariableName = "Nul";
        dh.Object_Container[0].VariableData = openFileDialog.GetPath();

        std::string line;
        std::ifstream File;
        File.open(openFileDialog.GetPath());
        while(getline(File, line))
        {
            //read object data
            std::cout << line;

            if(line.find("@Name") == 0)                 dh.Object_Container[0].Name          = FileHandler::Prase::Line(line, "Data");
            else if(line.find("@Texture") == 0)         dh.Object_Container[0].Texture       = FileHandler::Prase::Line(line, "Data");
            else if(line.find("@DeathFx") == 0)         dh.Object_Container[0].Death_Fx      = FileHandler::Prase::Line(line, "Data");
            else if(line.find("@ScaleX") == 0)          dh.Object_Container[0].ScaleX        = FileHandler::Prase::Line_Int(line, "Data");
            else if(line.find("@ScaleY") == 0)          dh.Object_Container[0].ScaleY        = FileHandler::Prase::Line_Int(line, "Data");
            else if(line.find("@MovementSpeed") == 0)   dh.Object_Container[0].MovementSpeed = FileHandler::Prase::Line_Float(line, "Data");
            else if(line.find("@SoundIdle") == 0)       dh.Object_Container[0].SoundIdle     = FileHandler::Prase::Line(line, "Data");
            else if(line.find("@SoundMove") == 0)       dh.Object_Container[0].SoundMove     = FileHandler::Prase::Line(line, "Data");
            else if(line.find("#") == 0)                continue;
            else if(line.empty())                       continue;
            else                                        wxLogError(wxString(line) + " is undefined! Please check the file and open it again to avoid issues.", openFileDialog.GetPath());

            std::cout << std::endl;
        }
        File.close();

        //inform user of another window opening
        wxMessageBox("Please open the texture file associated with this object. An file dialog will open upon pressing OK.",
                     "Need Texture File", wxOK | wxICON_INFORMATION);

        wxFileDialog
            openFileDialog(this, _("Open .texture file"), "", "",
                           "Texture files (*.texture)|*.texture", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
        if(openFileDialog.ShowModal() == wxID_CANCEL) return;

        wxFileInputStream input_stream_textures(openFileDialog.GetPath());
        if(input_stream.IsOk())
        {
            MDJS::DialogPath = openFileDialog.GetPath();

            std::string line;
            std::ifstream File;
            File.open(openFileDialog.GetPath());
            while(getline(File, line))
            {
                //read texture file
                std::cout << line;

                if(line.find("@Name") == 0)                     dh.Texture_Container[0].Name          = FileHandler::Prase::Line(line, "Data");
                else if(line.find("@Path") == 0)                dh.Texture_Container[0].texture_Path  = FileHandler::Prase::Line(line, "Data");
                else if(line.find("@TextureRect_L") == 0)       dh.Texture_Container[0].TextureRect_L = FileHandler::Prase::Line_Int(line, "Data");
                else if(line.find("@TextureRect_T") == 0)       dh.Texture_Container[0].TextureRect_T = FileHandler::Prase::Line_Int(line, "Data");
                else if(line.find("@TextureRect_W") == 0)       dh.Texture_Container[0].TextureRect_W = FileHandler::Prase::Line_Int(line, "Data");
                else if(line.find("@TextureRect_H") == 0)       dh.Texture_Container[0].TextureRect_H = FileHandler::Prase::Line_Int(line, "Data");

                else if(line.find("@Animation_Move_Up") == 0)
                {
                    dh.Texture_Container[0].Animation_Move_Up               = FileHandler::Prase::Line(line, "Data");
                    dh.Texture_Container[0].Animation_Move_Up_Direction     = FileHandler::Prase::Line_Str_Array(line, 0);
                    dh.Texture_Container[0].Animation_Move_Up_Row           = FileHandler::Prase::Line_Int_Array(line, 1);
                    dh.Texture_Container[0].Animation_Move_Up_Reset         = FileHandler::Prase::Line_Int_Array(line, 2);
                    dh.Texture_Container[0].Animation_Move_Up_Add           = FileHandler::Prase::Line_Int_Array(line, 3);
                    dh.Texture_Container[0].Animation_Move_Up_Restart       = FileHandler::Prase::Line_Int_Array(line, 4);
                    dh.Texture_Container[0].Animation_Move_Up_Width         = FileHandler::Prase::Line_Int_Array(line, 5);
                    dh.Texture_Container[0].Animation_Move_Up_Height        = FileHandler::Prase::Line_Int_Array(line, 6);
                    dh.Texture_Container[0].AnimationSpeed_Up               = FileHandler::Prase::Line_Float_Array(line, 7);
                }

                else if(line.find("@Animation_Move_Down") == 0)
                {
                    dh.Texture_Container[0].Animation_Move_Down             = FileHandler::Prase::Line(line, "Data");
                    dh.Texture_Container[0].Animation_Move_Down_Direction   = FileHandler::Prase::Line_Str_Array(line, 0);
                    dh.Texture_Container[0].Animation_Move_Down_Row         = FileHandler::Prase::Line_Int_Array(line, 1);
                    dh.Texture_Container[0].Animation_Move_Down_Reset       = FileHandler::Prase::Line_Int_Array(line, 2);
                    dh.Texture_Container[0].Animation_Move_Down_Add         = FileHandler::Prase::Line_Int_Array(line, 3);
                    dh.Texture_Container[0].Animation_Move_Down_Restart     = FileHandler::Prase::Line_Int_Array(line, 4);
                    dh.Texture_Container[0].Animation_Move_Down_Width       = FileHandler::Prase::Line_Int_Array(line, 5);
                    dh.Texture_Container[0].Animation_Move_Down_Height      = FileHandler::Prase::Line_Int_Array(line, 6);
                    dh.Texture_Container[0].AnimationSpeed_Down             = FileHandler::Prase::Line_Float_Array(line, 7);
                }

                else if(line.find("@Animation_Move_Left") == 0)
                {
                    dh.Texture_Container[0].Animation_Move_Left             = FileHandler::Prase::Line(line, "Data");
                    dh.Texture_Container[0].Animation_Move_Left_Direction   = FileHandler::Prase::Line_Str_Array(line, 0);
                    dh.Texture_Container[0].Animation_Move_Left_Row         = FileHandler::Prase::Line_Int_Array(line, 1);
                    dh.Texture_Container[0].Animation_Move_Left_Reset       = FileHandler::Prase::Line_Int_Array(line, 2);
                    dh.Texture_Container[0].Animation_Move_Left_Add         = FileHandler::Prase::Line_Int_Array(line, 3);
                    dh.Texture_Container[0].Animation_Move_Left_Restart     = FileHandler::Prase::Line_Int_Array(line, 4);
                    dh.Texture_Container[0].Animation_Move_Left_Width       = FileHandler::Prase::Line_Int_Array(line, 5);
                    dh.Texture_Container[0].Animation_Move_Left_Height      = FileHandler::Prase::Line_Int_Array(line, 6);
                    dh.Texture_Container[0].AnimationSpeed_Left             = FileHandler::Prase::Line_Float_Array(line, 7);
                }

                else if(line.find("@Animation_Move_Right") == 0)
                {
                    dh.Texture_Container[0].Animation_Move_Right            = FileHandler::Prase::Line(line, "Data");
                    dh.Texture_Container[0].Animation_Move_Right_Direction  = FileHandler::Prase::Line_Str_Array(line, 0);
                    dh.Texture_Container[0].Animation_Move_Right_Row        = FileHandler::Prase::Line_Int_Array(line, 1);
                    dh.Texture_Container[0].Animation_Move_Right_Reset      = FileHandler::Prase::Line_Int_Array(line, 2);
                    dh.Texture_Container[0].Animation_Move_Right_Add        = FileHandler::Prase::Line_Int_Array(line, 3);
                    dh.Texture_Container[0].Animation_Move_Right_Restart    = FileHandler::Prase::Line_Int_Array(line, 4);
                    dh.Texture_Container[0].Animation_Move_Right_Width      = FileHandler::Prase::Line_Int_Array(line, 5);
                    dh.Texture_Container[0].Animation_Move_Right_Height     = FileHandler::Prase::Line_Int_Array(line, 6);
                    dh.Texture_Container[0].AnimationSpeed_Right            = FileHandler::Prase::Line_Float_Array(line, 7);
                }

                else if(line.find("#") == 0)                continue;
                else if(line.empty())                       continue;
                else                                        wxLogError(wxString(line) + " is undefined! Please check the file and open it again to avoid issues.", openFileDialog.GetPath());

                std::cout << std::endl;
            }
            File.close();

            //no errors, set File_Loaded to true so that the SFML loop knows that it can render
            MDJS::bFile_New = false;
            MDJS::bFile_Loaded = true;
            MDJS::bMFile_Loaded = false;

            //Disable mapobject functions
            info_listbox->SetString(21, "Map Object Animation: N/A");
            mtexture_animation_textbox->Clear();
            mtexture_animation_textbox->AppendText("N/A");
            mtexture_animation_button->SetLabel("N/A");
            mtexture_animation_play_button->SetLabel("N/A");

            //Enable object functions
            texture_animation_move_up_button->SetLabel("Set");
            texture_animation_move_down_button->SetLabel("Set");
            texture_animation_move_left_button->SetLabel("Set");
            texture_animation_move_right_button->SetLabel("Set");
            texture_animation_move_up_play_button->SetLabel("Play");
            texture_animation_move_down_play_button->SetLabel("Play");
            texture_animation_move_left_play_button->SetLabel("Play");
            texture_animation_move_right_play_button->SetLabel("Play");

            //Set object data on the interface
            info_listbox->SetString(1, "Object Name: "      + dh.Object_Container[0].Name);
            info_listbox->SetString(2, "Object Texture: "   + dh.Object_Container[0].Texture);
            info_listbox->SetString(3, "Death Fx: "         + dh.Object_Container[0].Death_Fx);
            info_listbox->SetString(4, "Idle Sound: "       + dh.Object_Container[0].SoundIdle);
            info_listbox->SetString(5, "Move Sound: "       + dh.Object_Container[0].SoundMove);
            info_listbox->SetString(6, "Scale X: "          + std::to_string(dh.Object_Container[0].ScaleX));
            info_listbox->SetString(7, "Scale Y: "          + std::to_string(dh.Object_Container[0].ScaleY));
            info_listbox->SetString(8, "Movement Speed: "   + std::to_string(dh.Object_Container[0].MovementSpeed));

            obj_name_textbox->Clear();
            obj_texture_textbox->Clear();
            obj_Death_Fx_textbox->Clear();
            obj_SoundIdle_textbox->Clear();
            obj_SoundMove_textbox->Clear();
            obj_scale_x_textbox->Clear();
            obj_scale_y_textbox->Clear();
            obj_movementSpeed_textbox->Clear();

            obj_name_textbox->AppendText(dh.Object_Container[0].Name);
            obj_texture_textbox->AppendText(dh.Object_Container[0].Texture);
            obj_Death_Fx_textbox->AppendText(dh.Object_Container[0].Death_Fx);
            obj_SoundIdle_textbox->AppendText(dh.Object_Container[0].SoundIdle);
            obj_SoundMove_textbox->AppendText(dh.Object_Container[0].SoundMove);
            obj_scale_x_textbox->AppendText(std::to_string(dh.Object_Container[0].ScaleX));
            obj_scale_y_textbox->AppendText(std::to_string(dh.Object_Container[0].ScaleY));
            obj_movementSpeed_textbox->AppendText(std::to_string(dh.Object_Container[0].MovementSpeed));

            //Set texture data on the interface
            info_listbox->SetString(11,"Texture Name: "             + dh.Texture_Container[0].Name);
            info_listbox->SetString(12, "Texture Path: "            + dh.Texture_Container[0].texture_Path);
            info_listbox->SetString(13, "Rect Top: "                + std::to_string(dh.Texture_Container[0].TextureRect_T));
            info_listbox->SetString(14, "Rect Left: "               + std::to_string(dh.Texture_Container[0].TextureRect_L));
            info_listbox->SetString(15, "Rect Width: "              + std::to_string(dh.Texture_Container[0].TextureRect_W));
            info_listbox->SetString(16, "Rect Height: "             + std::to_string(dh.Texture_Container[0].TextureRect_H));
            info_listbox->SetString(17, "Animation_Move_Up: "       + dh.Texture_Container[0].Animation_Move_Up);
            info_listbox->SetString(18, "Animation_Move_Down: "     + dh.Texture_Container[0].Animation_Move_Down);
            info_listbox->SetString(19, "Animation_Move_Left: "     + dh.Texture_Container[0].Animation_Move_Left);
            info_listbox->SetString(20, "Animation_Move_Right: "    + dh.Texture_Container[0].Animation_Move_Right);

            texture_name_textbox->Clear();
            texture_path_textbox->Clear();
            texture_rect_top_textbox->Clear();
            texture_rect_left_textbox->Clear();
            texture_rect_width_textbox->Clear();
            texture_rect_height_textbox->Clear();
            texture_animation_move_up_textbox->Clear();
            texture_animation_move_down_textbox->Clear();
            texture_animation_move_left_textbox->Clear();
            texture_animation_move_right_textbox->Clear();

            texture_name_textbox->AppendText(dh.Texture_Container[0].Name);
            texture_path_textbox->AppendText(dh.Texture_Container[0].texture_Path);
            texture_rect_top_textbox->AppendText(std::to_string(dh.Texture_Container[0].TextureRect_T));
            texture_rect_left_textbox->AppendText(std::to_string(dh.Texture_Container[0].TextureRect_L));
            texture_rect_width_textbox->AppendText(std::to_string(dh.Texture_Container[0].TextureRect_W));
            texture_rect_height_textbox->AppendText(std::to_string(dh.Texture_Container[0].TextureRect_H));
            texture_animation_move_up_textbox->AppendText(dh.Texture_Container[0].Animation_Move_Up);
            texture_animation_move_down_textbox->AppendText(dh.Texture_Container[0].Animation_Move_Down);
            texture_animation_move_left_textbox->AppendText(dh.Texture_Container[0].Animation_Move_Left);
            texture_animation_move_right_textbox->AppendText(dh.Texture_Container[0].Animation_Move_Right);

            std::cout << "\n\n>> " << MDJS::DialogPath;
            std::cout << "\n\n>> " << dh.Texture_Container[0].texture_Path;
        }

        else
        {
            wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
            return;
        }
    }

    else
    {
        wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
        return;
    }
}

