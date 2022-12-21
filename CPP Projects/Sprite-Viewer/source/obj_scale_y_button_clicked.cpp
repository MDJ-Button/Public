/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyFrame.hpp"
#include "Data_Handler.h"

void MyFrame::obj_scale_y_button_clicked(wxCommandEvent& event)
{
    Data_Handler dh;
    std::string newvalue;
    newvalue = obj_scale_y_textbox->GetValue();
    dh.Object_Container[0].ScaleY = std::stoi(newvalue);
    info_listbox->SetString(7, "Scale Y: " + std::to_string(dh.Object_Container[0].ScaleY));
}
