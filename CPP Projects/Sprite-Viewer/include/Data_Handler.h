/***********************************************************************************************
 * Project Name: Sprite Viewer                                                                 *
 * Programmer: Martin De Jonge                                                                 *
 * Last Update: 12 June 2021                                                                   *
 * Github:https://github.com/MDJ-Button                                                        *
 *---------------------------------------------------------------------------------------------*/

#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

#include <vector>
#include <string>
#include "wxSFMLCanvas.h"

class Data_Handler
{
    public:
        class Object
        {
            public:
                std::string VariableName;
                std::string VariableData;
                std::string Name;
                std::string Texture;
                std::string Death_Fx;
                std::string SoundIdle;
                std::string SoundMove;
                int ScaleX;
                int ScaleY;
                float MovementSpeed;
                sf::Texture  texture;
                sf::Sprite   sprite;
                sf::IntRect  sprite_IntRect;
        };
        static std::vector<Object> Object_Container;

        class Texture
        {
            public:

            std::string VariableName;
            std::string VariableData;

            std::string Name;
            std::string texture_Path;

            int TextureRect_L;
            int TextureRect_T;
            int TextureRect_W;
            int TextureRect_H;

            std::string mAnimation;
            std::string mAnimation_Direction;
            int mAnimation_Row;
            int mAnimation_Reset;
            int mAnimation_Add;
            int mAnimation_Restart;
            int mAnimation_Width;
            int mAnimation_Height;
            bool mAnimation_Repeat;
            bool mAnimation_Play = false;
            float mAnimationSpeed;
            float Previous_mTime;
            sf::Time mTime;

            std::string Animation_Move_Up;
            std::string Animation_Move_Up_Direction;
            int Animation_Move_Up_Row;
            int Animation_Move_Up_Reset;
            int Animation_Move_Up_Add;
            int Animation_Move_Up_Restart;
            int Animation_Move_Up_Width;
            int Animation_Move_Up_Height;
            bool Animation_Move_Up_Play = false;
            float AnimationSpeed_Up;
            float Previous_Time_Up;
            sf::Time Time_Up;

            std::string Animation_Move_Down;
            std::string Animation_Move_Down_Direction;
            int Animation_Move_Down_Row;
            int Animation_Move_Down_Reset;
            int Animation_Move_Down_Add;
            int Animation_Move_Down_Restart;
            int Animation_Move_Down_Width;
            int Animation_Move_Down_Height;
            bool Animation_Move_Down_Play = false;
            float AnimationSpeed_Down;
            float Previous_Time_Down;
            sf::Time Time_Down;

            std::string Animation_Move_Left;
            std::string Animation_Move_Left_Direction;
            int Animation_Move_Left_Row;
            int Animation_Move_Left_Reset;
            int Animation_Move_Left_Add;
            int Animation_Move_Left_Restart;
            int Animation_Move_Left_Width;
            int Animation_Move_Left_Height;
            bool Animation_Move_Left_Play = false;
            float AnimationSpeed_Left;
            float Previous_Time_Left;
            sf::Time Time_Left;

            std::string Animation_Move_Right;
            std::string Animation_Move_Right_Direction;
            int Animation_Move_Right_Row;
            int Animation_Move_Right_Reset;
            int Animation_Move_Right_Add;
            int Animation_Move_Right_Restart;
            int Animation_Move_Right_Width;
            int Animation_Move_Right_Height;
            bool Animation_Move_Right_Play = false;
            float AnimationSpeed_Right;
            float Previous_Time_Right;
            sf::Time Time_Right;
        };
        static std::vector<Texture> Texture_Container;

    private:

};

#endif // DATA_HANDLER_H
