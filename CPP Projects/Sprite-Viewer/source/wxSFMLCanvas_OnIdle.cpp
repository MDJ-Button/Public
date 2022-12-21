/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 * Link to tutorial: https://www.sfml-dev.org/tutorials/1.6/graphics-wxwidgets.php             *
 *---------------------------------------------------------------------------------------------*/

#include "wxSFMLCanvas.h"

void wxSFMLCanvas::OnIdle(wxIdleEvent&)
{
    Refresh();
}
