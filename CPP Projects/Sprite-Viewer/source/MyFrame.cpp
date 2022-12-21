/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyFrame.hpp"
#include "MyApp.hpp"

#include "MyCanvas.h"
#include "MDJS.hpp"
#include "../version.h"

#include <string>
#include <windows.h>

//events - if button with the id 1 is clicked then name_button_clicked() function will execute

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_BUTTON(1,  obj_name_button_clicked)
    EVT_BUTTON(2,  obj_texture_button_clicked)
    EVT_BUTTON(3,  obj_Death_Fx_button_clicked)
    EVT_BUTTON(4,  obj_SoundIdle_button_clicked)
    EVT_BUTTON(5,  obj_SoundMove_button_clicked)
    EVT_BUTTON(6,  obj_scale_x_button_clicked)
    EVT_BUTTON(7,  obj_scale_y_button_clicked)
    EVT_BUTTON(8,  obj_movementSpeed_button_clicked)
    EVT_BUTTON(9,  texture_name_button_clicked)
    EVT_BUTTON(10, texture_path_button_clicked)
    EVT_BUTTON(11, texture_rect_top_button_clicked)
    EVT_BUTTON(12, texture_rect_left_button_clicked)
    EVT_BUTTON(13, texture_rect_width_button_clicked)
    EVT_BUTTON(14, texture_rect_height_button_clicked)
    EVT_BUTTON(15, texture_animation_move_up_button_clicked)
    EVT_BUTTON(16, texture_animation_move_down_button_clicked)
    EVT_BUTTON(17, texture_animation_move_left_button_clicked)
    EVT_BUTTON(18, texture_animation_move_right_button_clicked)
    EVT_BUTTON(19, texture_animation_move_up_play_button_clicked)
    EVT_BUTTON(20, texture_animation_move_down_play_button_clicked)
    EVT_BUTTON(21, texture_animation_move_left_play_button_clicked)
    EVT_BUTTON(22, texture_animation_move_right_play_button_clicked)
    EVT_BUTTON(23, mtexture_animation_button_clicked)
    EVT_BUTTON(24, mtexture_animation_play_button_clicked)
wxEND_EVENT_TABLE()

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, std::string("Object Editor - ") + AutoVersion::STATUS + " " + AutoVersion::FULLVERSION_STRING + " build count " + std::to_string(AutoVersion::BUILDS_COUNT), wxDefaultPosition, wxSize(600, 600))
{
    SetIcon(wxICON(frame_icon));

    //create file menu

    wxMenu *menuFile = new wxMenu;
    menuFile->Append(File_Menu_New, "&New .object");
    menuFile->Append(File_Menu_New_Map, "&New .mapobject");
    menuFile->Append(File_Menu_Open, "&Open .object");
    menuFile->Append(File_Menu_Open_Map_Obj, "&Open .mapobject");
    menuFile->Append(File_Menu_Save, "&Save file");
    menuFile->AppendSeparator();
    menuFile->Append(File_Menu_Exit, "&Quit");

    //create help menu

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    //create menu bar and append file and help to it

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    //set menu bar

    SetMenuBar(menuBar);

    MDJS::Status = new wxStatusBar(this, wxID_ANY);
    MDJS::Status->SetStatusText(MDJS::State_Okay);
    SetStatusBar(MDJS::Status);

    //Create info box and sprite window

    info_listbox                                = new wxListBox(this, wxID_ANY,                                                                 wxPoint(5, 0), wxSize(300, 260));
                                                  new MyCanvas(this, wxID_ANY,                                                                  wxPoint(5, 265), wxSize(300, 255));

    //Create static text

    obj_name_staticText                         = new wxStaticText(this, wxID_ANY, "Object Name",                                               wxPoint(310, 0), wxSize(100, 20), wxALIGN_LEFT);
    obj_texture_staticText                      = new wxStaticText(this, wxID_ANY, "Object Texture",                                            wxPoint(310, 20), wxSize(100, 20), wxALIGN_LEFT);
    obj_Death_Fx_staticText                     = new wxStaticText(this, wxID_ANY, "Death Fx",                                                  wxPoint(310, 40), wxSize(100, 20), wxALIGN_LEFT);
    obj_SoundIdle_staticText                    = new wxStaticText(this, wxID_ANY, "Idle Sound",                                                wxPoint(310, 60), wxSize(100, 20), wxALIGN_LEFT);
    obj_SoundMove_staticText                    = new wxStaticText(this, wxID_ANY, "Move Sound",                                                wxPoint(310, 80), wxSize(100, 20), wxALIGN_LEFT);
    obj_scale_x_staticText                      = new wxStaticText(this, wxID_ANY, "Scale X",                                                   wxPoint(310, 100), wxSize(100, 20), wxALIGN_LEFT);
    obj_scale_y_staticText                      = new wxStaticText(this, wxID_ANY, "Scale Y",                                                   wxPoint(310, 120), wxSize(100, 20), wxALIGN_LEFT);
    obj_movementSpeed_staticText                = new wxStaticText(this, wxID_ANY, "Movement Speed",                                            wxPoint(310, 140), wxSize(100, 20), wxALIGN_LEFT);

    texture_name_staticText                     = new wxStaticText(this, wxID_ANY, "Texture Name",                                              wxPoint(310, 180), wxSize(100, 20), wxALIGN_LEFT);
    texture_path_staticText                     = new wxStaticText(this, wxID_ANY, "Texture Path",                                              wxPoint(310, 200), wxSize(100, 20), wxALIGN_LEFT);
    texture_rect_top_staticText                 = new wxStaticText(this, wxID_ANY, "Rect Top",                                                  wxPoint(310, 220), wxSize(100, 20), wxALIGN_LEFT);
    texture_rect_left_staticText                = new wxStaticText(this, wxID_ANY, "Rect Left",                                                 wxPoint(310, 240), wxSize(100, 20), wxALIGN_LEFT);
    texture_rect_width_staticText               = new wxStaticText(this, wxID_ANY, "Rect Width",                                                wxPoint(310, 260), wxSize(100, 20), wxALIGN_LEFT);
    texture_rect_height_staticText              = new wxStaticText(this, wxID_ANY, "Rect Height",                                               wxPoint(310, 280), wxSize(100, 20), wxALIGN_LEFT);
    texture_animation_move_up_staticText        = new wxStaticText(this, wxID_ANY, "Move Up Animation Array",                                   wxPoint(310, 300), wxSize(200, 20), wxALIGN_LEFT);
    texture_animation_move_down_staticText      = new wxStaticText(this, wxID_ANY, "Move Down Animation Array",                                 wxPoint(310, 340), wxSize(200, 20), wxALIGN_LEFT);
    texture_animation_move_left_staticText      = new wxStaticText(this, wxID_ANY, "Move Left Animation Array",                                 wxPoint(310, 380), wxSize(200, 20), wxALIGN_LEFT);
    texture_animation_move_right_staticText     = new wxStaticText(this, wxID_ANY, "Move Right Animation Array",                                wxPoint(310, 420), wxSize(200, 20), wxALIGN_LEFT);

    mtexture_animation_staticText               = new wxStaticText(this, wxID_ANY, "Map Object Animation Array",                                wxPoint(310, 460), wxSize(200, 20), wxALIGN_LEFT);

    //create text boxes

    obj_name_textbox                            = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(410, 0),  wxSize(120, 20));
    obj_texture_textbox                         = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(410, 20), wxSize(120, 20));
    obj_Death_Fx_textbox                        = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(410, 40), wxSize(120, 20));
    obj_SoundIdle_textbox                       = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(410, 60), wxSize(120, 20));
    obj_SoundMove_textbox                       = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(410, 80), wxSize(120, 20));
    obj_scale_x_textbox                         = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(410, 100), wxSize(120, 20));
    obj_scale_y_textbox                         = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(410, 120), wxSize(120, 20));
    obj_movementSpeed_textbox                   = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(410, 140), wxSize(120, 20));

    texture_name_textbox                        = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(410, 180), wxSize(120, 20));
    texture_path_textbox                        = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(410, 200), wxSize(120, 20));
    texture_rect_top_textbox                    = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(410, 220), wxSize(120, 20));
    texture_rect_left_textbox                   = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(410, 240), wxSize(120, 20));
    texture_rect_width_textbox                  = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(410, 260), wxSize(120, 20));
    texture_rect_height_textbox                 = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(410, 280), wxSize(120, 20));
    texture_animation_move_up_textbox           = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(310, 320), wxSize(200, 20));
    texture_animation_move_down_textbox         = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(310, 360), wxSize(200, 20));
    texture_animation_move_left_textbox         = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(310, 400), wxSize(200, 20));
    texture_animation_move_right_textbox        = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(310, 440), wxSize(200, 20));

    mtexture_animation_textbox                  = new wxTextCtrl(this, wxID_ANY, "",                                                            wxPoint(310, 480), wxSize(200, 20));

    //create buttons

    obj_name_button                             = new wxButton(this, 1, "Set",                                                                  wxPoint(530, 0),   wxSize(50, 20));
    obj_texture_button                          = new wxButton(this, 2, "Set",                                                                  wxPoint(530, 20),  wxSize(50, 20));
    obj_Death_Fx_button                         = new wxButton(this, 3, "Set",                                                                  wxPoint(530, 40),  wxSize(50, 20));
    obj_SoundIdle_button                        = new wxButton(this, 4, "Set",                                                                  wxPoint(530, 60),  wxSize(50, 20));
    obj_SoundMove_button                        = new wxButton(this, 5, "Set",                                                                  wxPoint(530, 80),  wxSize(50, 20));
    obj_scale_x_button                          = new wxButton(this, 6, "Set",                                                                  wxPoint(530, 100), wxSize(50, 20));
    obj_scale_y_button                          = new wxButton(this, 7, "Set",                                                                  wxPoint(530, 120), wxSize(50, 20));
    obj_movementSpeed_button                    = new wxButton(this, 8, "Set",                                                                  wxPoint(530, 140), wxSize(50, 20));

    texture_name_button                         = new wxButton(this, 9, "Set",                                                                  wxPoint(530, 180), wxSize(50, 20));
    texture_path_button                         = new wxButton(this, 10, "Set",                                                                 wxPoint(530, 200), wxSize(50, 20));
    texture_rect_top_button                     = new wxButton(this, 11, "Set",                                                                 wxPoint(530, 220), wxSize(50, 20));
    texture_rect_left_button                    = new wxButton(this, 12, "Set",                                                                 wxPoint(530, 240), wxSize(50, 20));
    texture_rect_width_button                   = new wxButton(this, 13, "Set",                                                                 wxPoint(530, 260), wxSize(50, 20));
    texture_rect_height_button                  = new wxButton(this, 14, "Set",                                                                 wxPoint(530, 280), wxSize(50, 20));
    texture_animation_move_up_button            = new wxButton(this, 15, "Set",                                                                 wxPoint(510, 320), wxSize(30, 20));
    texture_animation_move_down_button          = new wxButton(this, 16, "Set",                                                                 wxPoint(510, 360), wxSize(30, 20));
    texture_animation_move_left_button          = new wxButton(this, 17, "Set",                                                                 wxPoint(510, 400), wxSize(30, 20));
    texture_animation_move_right_button         = new wxButton(this, 18, "Set",                                                                 wxPoint(510, 440), wxSize(30, 20));
    texture_animation_move_up_play_button       = new wxButton(this, 19, "Play",                                                                wxPoint(540, 320), wxSize(40, 20));
    texture_animation_move_down_play_button     = new wxButton(this, 20, "Play",                                                                wxPoint(540, 360), wxSize(40, 20));
    texture_animation_move_left_play_button     = new wxButton(this, 21, "Play",                                                                wxPoint(540, 400), wxSize(40, 20));
    texture_animation_move_right_play_button    = new wxButton(this, 22, "Play",                                                                wxPoint(540, 440), wxSize(40, 20));

    mtexture_animation_button                   = new wxButton(this, 23, "Set",                                                                 wxPoint(510, 480), wxSize(30, 20));
    mtexture_animation_play_button              = new wxButton(this, 24, "Play",                                                                wxPoint(540, 480), wxSize(40, 20));

    //Append data to info listbox

    info_listbox->Append("Object Information ------------------------------------");    //0
    info_listbox->Append("Object Name: ");                                              //1
    info_listbox->Append("Object Texture: ");                                           //2
    info_listbox->Append("Death Fx: ");                                                 //3
    info_listbox->Append("Idle Sound: ");                                               //4
    info_listbox->Append("Move Sound: ");                                               //5
    info_listbox->Append("Scale X: ");                                                  //6
    info_listbox->Append("Scale Y: ");                                                  //7
    info_listbox->Append("Movement Speed: ");                                           //8
    info_listbox->Append("");                                                           //9
    info_listbox->Append("Texture Information ------------------------------------");   //10
    info_listbox->Append("Texture Name: ");                                             //11
    info_listbox->Append("Texture Path: ");                                             //12
    info_listbox->Append("Rect Top: ");                                                 //13
    info_listbox->Append("Rect Left: ");                                                //14
    info_listbox->Append("Rect Width: ");                                               //15
    info_listbox->Append("Rect Height: ");                                              //16
    info_listbox->Append("Animation_Move_Up: ");                                        //17
    info_listbox->Append("Animation_Move_Down: ");                                      //18
    info_listbox->Append("Animation_Move_Left: ");                                      //19
    info_listbox->Append("Animation_Move_Right: ");                                     //20
    info_listbox->Append("Map Object Animation: ");                                     //21

    //Set Colors

    this->SetBackgroundColour(wxColor(*wxWHITE));

    obj_name_staticText->SetForegroundColour(wxColor(*wxBLACK));
    obj_texture_staticText->SetForegroundColour(wxColor(*wxBLACK));
    obj_Death_Fx_staticText->SetForegroundColour(wxColor(*wxBLACK));
    obj_SoundIdle_staticText->SetForegroundColour(wxColor(*wxBLACK));
    obj_SoundMove_staticText->SetForegroundColour(wxColor(*wxBLACK));
    obj_scale_x_staticText->SetForegroundColour(wxColor(*wxBLACK));
    obj_scale_y_staticText->SetForegroundColour(wxColor(*wxBLACK));
    obj_movementSpeed_staticText->SetForegroundColour(wxColor(*wxBLACK));

    texture_name_staticText->SetForegroundColour(wxColor(*wxBLACK));
    texture_path_staticText->SetForegroundColour(wxColor(*wxBLACK));
    texture_rect_top_staticText->SetForegroundColour(wxColor(*wxBLACK));
    texture_rect_left_staticText->SetForegroundColour(wxColor(*wxBLACK));
    texture_rect_width_staticText->SetForegroundColour(wxColor(*wxBLACK));
    texture_rect_height_staticText->SetForegroundColour(wxColor(*wxBLACK));
    texture_animation_move_up_staticText->SetForegroundColour(wxColor(*wxBLACK));
    texture_animation_move_down_staticText->SetForegroundColour(wxColor(*wxBLACK));
    texture_animation_move_left_staticText->SetForegroundColour(wxColor(*wxBLACK));
    texture_animation_move_right_staticText->SetForegroundColour(wxColor(*wxBLACK));

    mtexture_animation_staticText->SetForegroundColour(wxColor(*wxBLACK));

    info_listbox->SetBackgroundColour(wxColor(*wxWHITE));

    //bind events

    Bind(wxEVT_MENU, &MyFrame::Func_File_Menu_New, this, File_Menu_New);
    Bind(wxEVT_MENU, &MyFrame::Func_File_Menu_New_Map_Object, this, File_Menu_New_Map);
    Bind(wxEVT_MENU, &MyFrame::Func_File_Menu_Open, this, File_Menu_Open);
    Bind(wxEVT_MENU, &MyFrame::Func_File_Menu_Open_Map_Obj, this, File_Menu_Open_Map_Obj);
    Bind(wxEVT_MENU, &MyFrame::Func_File_Menu_Save, this, File_Menu_Save);
    Bind(wxEVT_MENU, &MyFrame::Func_File_Menu_Exit, this, File_Menu_Exit);

    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
}
