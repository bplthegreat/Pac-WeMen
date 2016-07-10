/*
    This Class Inherits the Texture class and is used to create food objects.
    The food objects are capable of Checking collision with Pacmen,
    Decide its Side and generate Exception for CollisionTrue with pacmen of another side
*/

#ifndef CLASSFOOD_H
#define CLASSFOOD_H

#include "Includes.h"
#include "ClassTexture.h"
#include "GlobalDec.h"
#include "FunctionDec.h"
#include "GlobalDec.h"
#include "ClassPacmenData.h"

using namespace Global;
using namespace FunctionIdentfiers;


class ClassFood : public ClassTexture
{
    public:
        ClassFood();
        virtual ~ClassFood();
        static int GetTotalFood();
        int GetRemainingFood();
        int GetNoOfEatenFood();
        void Render(SDL_Renderer* Renderer);
        Side CheckCollisionWithPacmen();
        static PacmenDetail* GetPacmenDetailPointer( int i );
        Side Operate( SDL_Renderer* );

        void SetLocation(int x, int y);
        void SetSideFlag(Side);

        static ClassFood * InitialiseFoods();
        void ShowFoodDetail();
        friend void SetFoodLocation( ClassFood *Food);



    protected:

    private:
        static int TotalNoOfFood;
        static int NoOfEatenFood;
        static int Side_AFood;
        static int Side_BFood;

        static PacmenDetail PacmenData[2];
        int PositionX, PositionY;
        bool EatenFlag;
        Side MySide;
};

#endif // CLASSFOOD_H
