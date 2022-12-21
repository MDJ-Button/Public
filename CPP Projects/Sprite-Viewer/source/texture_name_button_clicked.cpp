/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyFrame.hpp"
#include "Data_Handler.h"

void MyFrame::texture_name_button_clicked(wxCommandEvent& event)
{
    Data_Handler dh;
    std::string newvalue;
    newvalue = texture_name_textbox->GetValue();
    dh.Texture_Container[0].Name = newvalue;
    info_listbox->SetString(11, "Texture Name: " + dh.Texture_Container[0].Name);
}
