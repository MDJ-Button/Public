/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyFrame.hpp"
#include "Data_Handler.h"

void MyFrame::obj_SoundIdle_button_clicked(wxCommandEvent& event)
{
    Data_Handler dh;
    std::string newvalue;
    newvalue = obj_SoundIdle_textbox->GetValue();
    dh.Object_Container[0].SoundIdle = newvalue;
    info_listbox->SetString(4, "Idle Sound: " + dh.Object_Container[0].SoundIdle);
}
