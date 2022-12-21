/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 * Link to tutorial: https://www.sfml-dev.org/tutorials/1.6/graphics-wxwidgets.php             *
 *---------------------------------------------------------------------------------------------*/

#ifndef WXSFMLCANVAS_H
#define WXSFMLCANVAS_H

#include "wx_headers_SFML.hpp"

class wxSFMLCanvas : public wxControl, public sf::RenderWindow
{
    public :

        wxSFMLCanvas(wxWindow* Parent = NULL, wxWindowID Id = -1, const wxPoint& Position = wxDefaultPosition,
                     const wxSize& Size = wxDefaultSize, long Style = 0);

        virtual ~wxSFMLCanvas() {};

    private :

        DECLARE_EVENT_TABLE()

        virtual void OnUpdate() {};

        void OnIdle(wxIdleEvent&);

        void OnPaint(wxPaintEvent&);

        void OnEraseBackground(wxEraseEvent&) {};
};

#endif // WXSFMLCANVAS_H
