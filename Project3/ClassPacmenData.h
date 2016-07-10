#ifndef CLASSPACMENDATA_H
#define CLASSPACMENDATA_H

#include "Includes.h"
#include "GlobalDec.h"
#include "FunctionDec.h"


using namespace FunctionIdentfiers;
using namespace Global;

class ClassPacmenData
{
    public:
        static SDL_Rect * GetPacmenCollider(int );

        static Side * GetPacmenSide(int);
        static void ShowRects();

    protected:

    private:
        static SDL_Rect PacmenCollider[2];
        static Side PacmenSide[2];
};

#endif // CLASSPACMENDATA_H
