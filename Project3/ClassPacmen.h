#ifndef CLASSPACMEN_H
#define CLASSPACMEN_H


#include "GlobalDec.h"
#include "FunctionDec.h"
#include "ClassMovingTexture.h"

using namespace Global;
using namespace FunctionIdentfiers;


class ClassPacmen
{
    public:
        ClassPacmen(Side SideFlag = SIDE_A);
        ClassPacmen(int x, int y, Side SideFlag = SIDE_A  );
        virtual ~ClassPacmen();
        void SetModeFlag();
        void SetRegion();

        void Render(SDL_Renderer *);

        Side Operate(SDL_Renderer * , int );
        int CreateTexture(SDL_Renderer * , std::string, Mode);

        void SetCollisionTargets();
        void HandleEvent(MovementFlag);
        void Move();
        void GetPacmenData( PacmenDetail *);
        Side GetMySide();
        bool CheckCollisionWithPacmen();
        void PublishPacmenInformation(int);
        void ProduceRegionConfinement();


    protected:

    private:
        ClassMovingTexture PacmenMode;
        ClassMovingTexture GhostMode;
        Region CurrentRegion;
        Mode ModeFlag;
        const Side MySide;
        static PacmenDetail PacmenData[2];

};


#endif // CLASSPACMEN_H
