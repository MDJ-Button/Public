/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 * Link to tutorial: https://www.sfml-dev.org/tutorials/1.6/graphics-wxwidgets.php             *
 *---------------------------------------------------------------------------------------------*/

#ifndef MYCANVAS_H
#define MYCANVAS_H

#include "wxSFMLCanvas.h"

#include "MyFrame.hpp"
#include "Data_Handler.h"
#include "MDJS.hpp"

class MyCanvas : public wxSFMLCanvas
{
    public:

        MyCanvas(wxWindow*  Parent,
                 wxWindowID Id,
                 wxPoint   Position,
                 wxSize    Size,
                 long       Style = 0) :
        wxSFMLCanvas(Parent, Id, Position, Size, Style)
        {
            // Load an image and assign it to our sprite

            Data_Handler dh;

            //Texture set
            Data_Handler::Texture New_Texture;
            dh.Texture_Container.push_back(New_Texture);

            dh.Texture_Container[0].VariableName = "Nul";
            dh.Texture_Container[0].VariableData = "Nul";

            //Object set
            Data_Handler::Object New_Obj;
            dh.Object_Container.push_back(New_Obj);
        }

    private:

        bool bDraw_Sprite;

        bool bCannotLoadTexture;

        void Animation_Player();
        void Animation_Not_Playing();
        void Animation_Move_Up_Play();
        void Animation_Move_Down_Play();
        void Animation_Move_Left_Play();
        void Animation_Move_Right_Play();

        void mAnimation_Player();
        void mAnimation_Play();

        std::string Load(std::string Object_Texture);

        void objectLoop();
        void MapobjectLoop();

        sf::Clock Clock;
        sf::Time Timer;

        virtual void OnUpdate()
        {
            bDraw_Sprite = false;

            if(MDJS::bFile_Loaded) objectLoop();
            else if(MDJS::bMFile_Loaded) MapobjectLoop();

            if(MDJS::bFile_Loaded || MDJS::bMFile_Loaded)
            {
                //Update
                clear(sf::Color::Black);
                if(bDraw_Sprite) draw(Data_Handler::Object_Container[0].sprite);
            }
        }
};

#endif // MYCANVAS_H
