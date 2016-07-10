#ifndef CLASSMOTION_H
#define CLASSMOTION_H
#include "Includes.h"
#include "GlobalDec.h"
#include "FunctionDec.h"
#include "ClassTexture.h"

using namespace FunctionIdentfiers;
using namespace Global;

class ClassMotion
{
    public:
        ClassMotion();
        ClassMotion(int x, int y);
        virtual ~ClassMotion();
        void HandleEvent(MovementFlag);
        bool IsOutOfZone();
        SDL_Rect * Collider;
        void Move(SDL_Rect *);

    protected:
        int PositionX, PositionY;
        int VelocityX, VelocityY;


    private:
        static const int Velocity = 5;

};

#endif // CLASSMOTION_H
