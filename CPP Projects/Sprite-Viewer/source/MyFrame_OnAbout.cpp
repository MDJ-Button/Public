/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyFrame.hpp"

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("Created by Martin De Jonge",
                 "About", wxOK | wxICON_INFORMATION);
}
