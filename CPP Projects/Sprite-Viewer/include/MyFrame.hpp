/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#ifndef MYFRAME_H
#define MYFRAME_H

#include "wx_headers_SFML.hpp"
#include "Data_Handler.h"
#include "FileHandler.h"

class MyFrame : public wxFrame
{
    public:
        MyFrame();

    private:
        void Func_File_Menu_New(wxCommandEvent& event);
        void Func_File_Menu_New_Map_Object(wxCommandEvent& event);
        void Func_File_Menu_Open(wxCommandEvent& event);
        void Func_File_Menu_Open_Map_Obj(wxCommandEvent& event);
        void Func_File_Menu_Save(wxCommandEvent& event);
        void Func_File_Menu_Exit(wxCommandEvent& event);

        void OnAbout(wxCommandEvent& event);

        void obj_name_button_clicked(wxCommandEvent& event);
        void obj_texture_button_clicked(wxCommandEvent& event);
        void obj_Death_Fx_button_clicked(wxCommandEvent& event);
        void obj_SoundIdle_button_clicked(wxCommandEvent& event);
        void obj_SoundMove_button_clicked(wxCommandEvent& event);
        void obj_scale_x_button_clicked(wxCommandEvent& event);
        void obj_scale_y_button_clicked(wxCommandEvent& event);
        void obj_movementSpeed_button_clicked(wxCommandEvent& event);

        void texture_name_button_clicked(wxCommandEvent& event);
        void texture_path_button_clicked(wxCommandEvent& event);
        void texture_rect_top_button_clicked(wxCommandEvent& event);
        void texture_rect_left_button_clicked(wxCommandEvent& event);
        void texture_rect_width_button_clicked(wxCommandEvent& event);
        void texture_rect_height_button_clicked(wxCommandEvent& event);
        void texture_animation_move_up_button_clicked(wxCommandEvent& event);
        void texture_animation_move_down_button_clicked(wxCommandEvent& event);
        void texture_animation_move_left_button_clicked(wxCommandEvent& event);
        void texture_animation_move_right_button_clicked(wxCommandEvent& event);
        void texture_animation_move_up_play_button_clicked(wxCommandEvent& event);
        void texture_animation_move_down_play_button_clicked(wxCommandEvent& event);
        void texture_animation_move_left_play_button_clicked(wxCommandEvent& event);
        void texture_animation_move_right_play_button_clicked(wxCommandEvent& event);

        void mtexture_animation_button_clicked(wxCommandEvent& event);
        void mtexture_animation_play_button_clicked(wxCommandEvent& event);

        wxListBox   *info_listbox                               = nullptr;

        wxStaticText *obj_name_staticText                       = nullptr;
        wxStaticText *obj_texture_staticText                    = nullptr;
        wxStaticText *obj_Death_Fx_staticText                   = nullptr;
        wxStaticText *obj_SoundIdle_staticText                  = nullptr;
        wxStaticText *obj_SoundMove_staticText                  = nullptr;
        wxStaticText *obj_scale_x_staticText                    = nullptr;
        wxStaticText *obj_scale_y_staticText                    = nullptr;
        wxStaticText *obj_movementSpeed_staticText              = nullptr;
        wxStaticText *texture_name_staticText                   = nullptr;
        wxStaticText *texture_path_staticText                   = nullptr;
        wxStaticText *texture_rect_top_staticText               = nullptr;
        wxStaticText *texture_rect_left_staticText              = nullptr;
        wxStaticText *texture_rect_width_staticText             = nullptr;
        wxStaticText *texture_rect_height_staticText            = nullptr;
        wxStaticText *texture_animation_move_up_staticText      = nullptr;
        wxStaticText *texture_animation_move_down_staticText    = nullptr;
        wxStaticText *texture_animation_move_left_staticText    = nullptr;
        wxStaticText *texture_animation_move_right_staticText   = nullptr;
        wxStaticText *mtexture_animation_staticText             = nullptr;

        wxTextCtrl  *obj_name_textbox                           = nullptr;
        wxTextCtrl  *obj_texture_textbox                        = nullptr;
        wxTextCtrl  *obj_Death_Fx_textbox                       = nullptr;
        wxTextCtrl  *obj_SoundIdle_textbox                      = nullptr;
        wxTextCtrl  *obj_SoundMove_textbox                      = nullptr;
        wxTextCtrl  *obj_scale_x_textbox                        = nullptr;
        wxTextCtrl  *obj_scale_y_textbox                        = nullptr;
        wxTextCtrl  *obj_movementSpeed_textbox                  = nullptr;
        wxTextCtrl  *texture_name_textbox                       = nullptr;
        wxTextCtrl  *texture_path_textbox                       = nullptr;
        wxTextCtrl  *texture_rect_top_textbox                   = nullptr;
        wxTextCtrl  *texture_rect_left_textbox                  = nullptr;
        wxTextCtrl  *texture_rect_width_textbox                 = nullptr;
        wxTextCtrl  *texture_rect_height_textbox                = nullptr;
        wxTextCtrl  *texture_animation_move_up_textbox          = nullptr;
        wxTextCtrl  *texture_animation_move_down_textbox        = nullptr;
        wxTextCtrl  *texture_animation_move_left_textbox        = nullptr;
        wxTextCtrl  *texture_animation_move_right_textbox       = nullptr;
        wxTextCtrl  *mtexture_animation_textbox                 = nullptr;

        wxButton    *obj_name_button                            = nullptr;
        wxButton    *obj_texture_button                         = nullptr;
        wxButton    *obj_Death_Fx_button                        = nullptr;
        wxButton    *obj_SoundIdle_button                       = nullptr;
        wxButton    *obj_SoundMove_button                       = nullptr;
        wxButton    *obj_scale_x_button                         = nullptr;
        wxButton    *obj_scale_y_button                         = nullptr;
        wxButton    *obj_movementSpeed_button                   = nullptr;
        wxButton    *texture_name_button                        = nullptr;
        wxButton    *texture_path_button                        = nullptr;
        wxButton    *texture_rect_top_button                    = nullptr;
        wxButton    *texture_rect_left_button                   = nullptr;
        wxButton    *texture_rect_width_button                  = nullptr;
        wxButton    *texture_rect_height_button                 = nullptr;
        wxButton    *texture_animation_move_up_button           = nullptr;
        wxButton    *texture_animation_move_down_button         = nullptr;
        wxButton    *texture_animation_move_left_button         = nullptr;
        wxButton    *texture_animation_move_right_button        = nullptr;
        wxButton    *texture_animation_move_up_play_button      = nullptr;
        wxButton    *texture_animation_move_down_play_button    = nullptr;
        wxButton    *texture_animation_move_left_play_button    = nullptr;
        wxButton    *texture_animation_move_right_play_button   = nullptr;
        wxButton    *mtexture_animation_button                  = nullptr;
        wxButton    *mtexture_animation_play_button             = nullptr;

        wxDECLARE_EVENT_TABLE();
};

enum
{
    File_Menu_New = 401,
    File_Menu_New_Map = 402,
    File_Menu_Open = 403,
    File_Menu_Open_Map_Obj = 404,
    File_Menu_Save = 405,
    File_Menu_Exit = 406
};

#endif // MYFRAME_H
