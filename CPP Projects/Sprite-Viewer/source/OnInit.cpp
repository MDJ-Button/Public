/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyApp.hpp"
#include "MyFrame.hpp"
#include "wxImagePanel.hpp"

void Change_Dir()
{
    wxMessageBox("Please select the working directory. An file dialog will open upon pressing OK.",
                     "Select a Working Directory", wxOK | wxICON_INFORMATION);

    wxDirDialog dlg(NULL, "Choose input directory", "",
                    wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST | wxDD_CHANGE_DIR);
    if(dlg.ShowModal() == wxID_CANCEL) return;
}

bool MyApp::OnInit()
{
    wxInitAllImageHandlers();
    MyFrame *frame = new MyFrame();
    wxImagePanel* drawLogo = new wxImagePanel( frame, wxT("logo_small.png"), wxBITMAP_TYPE_PNG, 0, 310, 505, 100, 12);
    frame->Show(true);

    Change_Dir();

    return true;
}

wxIMPLEMENT_APP(MyApp);
