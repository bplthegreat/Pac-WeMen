//!
//!This class concerns the Position of obstacles in the GameField and initialises their address in Rectangle Data structure "SDL_Rect
//!     Inherited by:
//!         ClassMoving texture <--- ClassGhost
//!     DataTypes:
//!         SDL_Rect *TargetsInRegionA, *TargetsInRegionB, *TargetsInRegionC, *TargetsInRegionD:
//!             --The pointer to the rectangles that represent the Position of Obstacles: CollisionTargets;
//!     Functions
//!          SetCollisionTargets            -- Gives Collision Target For Moving Objects
//!          AssignTargetszInAllRegions     -- Initialises The Position Collision Targets Present in all region To respective Region Variable;
//!

#ifndef CLASSTARGETS_H
#define CLASSTARGETS_H
#include "Includes.h"
#include "FunctionDec.h"
#include "GlobalDec.h"
using namespace Global;
using namespace FunctionIdentfiers;


class ClassTargets
{
    public:
        ClassTargets();
        ~ClassTargets();
        void AssignRegionTargets();
        //Targets();
        SDL_Rect *SetCollisionTargets(Region );
        inline void ShowRect(SDL_Rect*);

    protected:

    private:
         SDL_Rect *TargetsInRegionA, *TargetsInRegionB, *TargetsInRegionC, *TargetsInRegionD;
         void AssignRectProperties(SDL_Rect* A, int x, int y, int w, int h);
         void AssignTargetsInAllRegions();
};

#endif // CLASSTARGETS_H
