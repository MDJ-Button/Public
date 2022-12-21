/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyFrame.hpp"
#include "Data_Handler.h"

void MyFrame::obj_scale_x_button_clicked(wxCommandEvent& event)
{
    Data_Handler dh;
    std::string newvalue;
    newvalue = obj_scale_x_textbox->GetValue();
    dh.Object_Container[0].ScaleX = std::stoi(newvalue);
    info_listbox->SetString(6, "Scale X: " + std::to_string(dh.Object_Container[0].ScaleX));
}
