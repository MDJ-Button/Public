/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyFrame.hpp"
#include "Data_Handler.h"

void MyFrame::texture_rect_left_button_clicked(wxCommandEvent& event)
{
    Data_Handler dh;
    std::string newvalue;
    newvalue = texture_rect_left_textbox->GetValue();
    dh.Texture_Container[0].TextureRect_L = std::stoi(newvalue);
    info_listbox->SetString(14, "Rect Left: " + std::to_string(dh.Texture_Container[0].TextureRect_L));
}
