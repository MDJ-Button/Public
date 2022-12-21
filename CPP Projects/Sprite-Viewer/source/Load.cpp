/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#include "MyCanvas.h"
#include "MDJS.hpp"

std::string MyCanvas::Load(std::string Object_Texture)
{
    Data_Handler dh;

    if(Object_Texture == dh.Texture_Container[0].Name)
    {
        bCannotLoadTexture = false;
        return dh.Texture_Container[0].texture_Path;
    }
    else if(!bCannotLoadTexture && !MDJS::bFile_New)
    {
        bCannotLoadTexture = true;
        wxLogError("Cannot find the texture named (" + wxString(Object_Texture) + ").", dh.Object_Container[0].VariableData);
    }

    return "Null";
}
