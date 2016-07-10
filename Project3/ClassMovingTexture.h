#ifndef CLASSMOVINGTEXTURE_H
#define CLASSMOVINGTEXTURE_H

#include "Includes.h"
#include "ClassTexture.h"
#include "ClassTargets.h"
#include "GlobalDec.h"
#include "FunctionDec.h"
using namespace Global;
using namespace FunctionIdentfiers;

class ClassMovingTexture : public ClassTexture, public ClassTargets
{
    public:
        ClassMovingTexture();
        ClassMovingTexture(int , int);
        virtual ~ClassMovingTexture();
        void Render(SDL_Renderer *);
        void HandleEvent(MovementFlag);
        bool CheckCollision(SDL_Rect *);
        bool IsOutOfZone();
        void Move(bool  DOYOUREALLYWANTTOMOVE = true);
        void GetCollisionTargets();
        Region GetCurrentRegion();
        void CheckCollision (SDL_Rect *, int, int *);
        Region AssignRegion();
        void SetCollisionTargets();
        SDL_Rect *CurrentCollisionTargets;
        void SetPositionX(int);
    protected:
        int PositionX, PositionY;
        int VelocityX, VelocityY;
        Region CurrentRegion;
        static const int Velocity = 3;
    private:

        //SDL_Rect *CurrentCollisionTargets;

};

#endif // CLASSMOVINGTEXTURE_H
