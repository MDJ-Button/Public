/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include <wx/window.h>
#include <wx/wxprec.h>
#include <wx/app.h>
#include <wx/image.h>
#include <wx/msgdlg.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <wx/filefn.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "SFML/Graphics.hpp"
#ifdef __WXGTK__
    #include <gdk/gdkx.h>
    #include <gtk/gtk.h>
#endif
