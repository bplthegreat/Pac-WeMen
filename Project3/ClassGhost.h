#ifndef CLASSGHOST_H
#define CLASSGHOST_H
#include "includes.h"
#include "ClassMovingTexture.h"
#include "GlobalDec.h"
#include "FunctionDec.h"
using namespace FunctionIdentfiers;
using namespace Global;


class ClassGhost : public ClassMovingTexture
{
    public:
        ClassGhost(Side SideFlag );
        ClassGhost(int x, int y, Side SideFlag );
        virtual ~ClassGhost();

      //  void Render(SDL_Renderer* Renderer);

        bool CheckCollisionWithPacmen();
        void SetVelocityX( int );
        void SetVelocityY( int );
        static PacmenDetail* GetPacmenDetailPointer( int i );

        void GetDistanceFromPacmen(int * , int * );
        void SetMyVelocity();

        Side Operate(SDL_Renderer *);
        void ProduceRegionConfinement();

    protected:

    private:
        bool ShouldIMove;
        Side MySide;
        static PacmenDetail PacmenData[2];
};

#endif // CLASSGHOST_H
