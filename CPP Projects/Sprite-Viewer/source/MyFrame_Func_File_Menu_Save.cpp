/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyFrame.hpp"
#include "MDJS.hpp"
#include "Data_Handler.h"
#include <fstream>

void MyFrame::Func_File_Menu_Save(wxCommandEvent& event)
{
    std::cout << "\n\nSaving ";

    //------------------------------------------------------------------------------------------------------object file
    if(MDJS::bFile_Loaded && !MDJS::bMFile_Loaded)
    {
        wxFileDialog
            saveFileDialog(this, _("Open .object file"), "", "",
                                   "Object files (*.object)|*.object", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
        if(saveFileDialog.ShowModal() == wxID_CANCEL) return;

        wxFileOutputStream output_stream(saveFileDialog.GetPath());
        if(!output_stream.IsOk())
        {
            wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
            return;
        }

        else
        {
            std::fstream my_file;
            my_file.open(saveFileDialog.GetPath(), std::ios::out);
            if(!my_file)
            {
                std::cout << "File not created!";
            }
            else
            {
                std::cout << "File created successfully!";

                std::fstream my_file;
                my_file.open(saveFileDialog.GetPath(), std::ios::out);
                if(!my_file)
                {
                    std::cout << "File not created!";
                }
                else
                {
                    std::cout << "File created successfully!";

                    std::string name;
                    std::string texture;
                    std::string deathfx;
                    std::string idlesound;
                    std::string movesound;
                    std::string scalex;
                    std::string scaley;
                    std::string movementspeed;

                    name = obj_name_textbox->GetValue();
                    texture = obj_texture_textbox->GetValue();
                    deathfx = obj_Death_Fx_textbox->GetValue();
                    scalex = obj_scale_x_textbox->GetValue();
                    scaley = obj_scale_y_textbox->GetValue();
                    movementspeed = obj_movementSpeed_textbox->GetValue();
                    idlesound = obj_SoundIdle_textbox->GetValue();
                    movesound = obj_SoundMove_textbox->GetValue();

                    my_file << "@Name:" << "\"" << name << "\"" << ";\n";
                    my_file << "@Texture:" << "\"" << texture << "\"" << ";\n";
                    my_file << "@DeathFx:" << "\"" << deathfx << "\"" << ";\n";
                    my_file << "@ScaleX:" << "\"" << scalex << "\"" << ";\n";
                    my_file << "@ScaleY:" << "\"" << scaley << "\"" << ";\n";
                    my_file << "@MovementSpeed:" << "\"" << movementspeed << "\"" << ";\n";
                    my_file << "@SoundIdle:" << "\"" << idlesound << "\"" << ";\n";
                    my_file << "@SoundMove:" << "\"" << movesound << "\"" << ";\n";

                    my_file.close();

                    wxMessageBox("Please save the texture file associated with this object. An file dialog will open upon pressing OK.",
                                 "Save Texture File", wxOK | wxICON_INFORMATION);

                    wxFileDialog
                        saveFileDialog(this, _("Open .texture file"), "", "",
                                               "Object Texture files (*.texture)|*.texture", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
                    if(saveFileDialog.ShowModal() == wxID_CANCEL) return;

                    wxFileOutputStream output_stream(saveFileDialog.GetPath());
                    if(!output_stream.IsOk())
                    {
                        wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
                        return;
                    }

                    else
                    {
                        std::fstream my_file;
                        my_file.open(saveFileDialog.GetPath(), std::ios::out);
                        if(!my_file)
                        {
                            std::cout << "File not created!";
                        }
                        else
                        {
                            std::cout << "File created successfully!";

                            std::string name;
                            std::string texturepath;
                            std::string rect_l;
                            std::string rect_t;
                            std::string rect_w;
                            std::string rect_h;
                            std::string animation_up;
                            std::string animation_down;
                            std::string animation_left;
                            std::string animation_right;

                            name = texture_name_textbox->GetValue();
                            texturepath = texture_path_textbox->GetValue();
                            rect_l = texture_rect_left_textbox->GetValue();
                            rect_t = texture_rect_top_textbox->GetValue();
                            rect_w = texture_rect_width_textbox->GetValue();
                            rect_h = texture_rect_height_textbox->GetValue();
                            animation_up = texture_animation_move_up_textbox->GetValue();
                            animation_down = texture_animation_move_down_textbox->GetValue();
                            animation_left = texture_animation_move_left_textbox->GetValue();
                            animation_right = texture_animation_move_right_textbox->GetValue();

                            my_file << "@Name:" << "\"" << name << "\"" << ";\n";
                            my_file << "@Path:" << "\"" << texturepath << "\"" << ";\n";
                            my_file << "@TextureRect_L:" << "\"" << rect_l << "\"" << ";\n";
                            my_file << "@TextureRect_T:" << "\"" << rect_t << "\"" << ";\n";
                            my_file << "@TextureRect_W:" << "\"" << rect_w << "\"" << ";\n";
                            my_file << "@TextureRect_H:" << "\"" << rect_h << "\"" << ";\n";
                            my_file << "@Animation_Move_Up:" << "\"" << animation_up << "\"" << ";\n";
                            my_file << "@Animation_Move_Down:" << "\"" << animation_down << "\"" << ";\n";
                            my_file << "@Animation_Move_Left:" << "\"" << animation_left << "\"" << ";\n";
                            my_file << "@Animation_Move_Right:" << "\"" << animation_right << "\"" << ";\n";

                            my_file.close();
                        }
                    }
                }
            }
        }
    }

    //------------------------------------------------------------------------------------------------------map file
    else if(!MDJS::bFile_Loaded && MDJS::bMFile_Loaded)
    {
        wxFileDialog
            saveFileDialog(this, _("Save .mapobject file"), "", "",
                                   "Map Object files (*.mapobject)|*.mapobject", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
        if(saveFileDialog.ShowModal() == wxID_CANCEL) return;

        wxFileOutputStream output_stream(saveFileDialog.GetPath());
        if(!output_stream.IsOk())
        {
            wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
            return;
        }

        else
        {
            std::fstream my_file;
            my_file.open(saveFileDialog.GetPath(), std::ios::out);
            if(!my_file)
            {
                std::cout << "File not created!";
            }
            else
            {
                std::cout << "File created successfully!";

                std::string name;
                std::string texture;
                std::string deathfx;
                std::string idlesound;
                std::string scalex;
                std::string scaley;

                name = obj_name_textbox->GetValue();
                texture = obj_texture_textbox->GetValue();
                deathfx = obj_Death_Fx_textbox->GetValue();
                idlesound = obj_SoundIdle_textbox->GetValue();
                scalex = obj_scale_x_textbox->GetValue();
                scaley = obj_scale_y_textbox->GetValue();

                my_file << "@Name:" << "\"" << name << "\"" << ";\n";
                my_file << "@Texture:" << "\"" << texture << "\"" << ";\n";
                my_file << "@DeathFx:" << "\"" << deathfx << "\"" << ";\n";
                my_file << "@Sound:" << "\"" << idlesound << "\"" << ";\n";
                my_file << "@ScaleX:" << "\"" << scalex << "\"" << ";\n";
                my_file << "@ScaleY:" << "\"" << scaley << "\"" << ";\n";

                my_file.close();

                wxMessageBox("Please save the texture file associated with this mapobject. An file dialog will open upon pressing OK.",
                             "Save Texture File", wxOK | wxICON_INFORMATION);

                wxFileDialog
                    saveFileDialog(this, _("Open .mtexture file"), "", "",
                                           "Map Object Texture files (*.mtexture)|*.mtexture", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
                if(saveFileDialog.ShowModal() == wxID_CANCEL) return;

                wxFileOutputStream output_stream(saveFileDialog.GetPath());
                if(!output_stream.IsOk())
                {
                    wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
                    return;
                }

                else
                {
                    std::fstream my_file;
                    my_file.open(saveFileDialog.GetPath(), std::ios::out);
                    if(!my_file)
                    {
                        std::cout << "File not created!";
                    }
                    else
                    {
                        std::cout << "File created successfully!";

                        std::string name;
                        std::string texturepath;
                        std::string rect_l;
                        std::string rect_t;
                        std::string rect_w;
                        std::string rect_h;
                        std::string animation;

                        name = texture_name_textbox->GetValue();
                        texturepath = texture_path_textbox->GetValue();
                        rect_l = texture_rect_left_textbox->GetValue();
                        rect_t = texture_rect_top_textbox->GetValue();
                        rect_w = texture_rect_width_textbox->GetValue();
                        rect_h = texture_rect_height_textbox->GetValue();
                        animation = mtexture_animation_textbox->GetValue();

                        my_file << "@Name:" << "\"" << name << "\"" << ";\n";
                        my_file << "@Path:" << "\"" << texturepath << "\"" << ";\n";
                        my_file << "@TextureRect_L:" << "\"" << rect_l << "\"" << ";\n";
                        my_file << "@TextureRect_T:" << "\"" << rect_t << "\"" << ";\n";
                        my_file << "@TextureRect_W:" << "\"" << rect_w << "\"" << ";\n";
                        my_file << "@TextureRect_H:" << "\"" << rect_h << "\"" << ";\n";
                        my_file << "@Animation:" << "\"" << animation << "\"" << ";\n";

                        my_file.close();
                    }
                }
            }
        }
    }
}

