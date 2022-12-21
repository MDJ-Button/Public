/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyFrame.hpp"
#include "MDJS.hpp"

void MyFrame::Func_File_Menu_New(wxCommandEvent& event)
{
    Data_Handler dh;

    MDJS::bFile_New = true;
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
}

