

#include "ClassTargets.h"


inline void ClassTargets::ShowRect(SDL_Rect *a)
{
    std::cout << "x ,y = " << a->x << ", " << a->y <<endl<< "w ,h = " << a->w << ", " << a->h<< endl << endl;
}
ClassTargets::ClassTargets()
{
    //ctor
    TargetsInRegionA = new SDL_Rect[NO_OF_COLLISION_TARGETS];
    TargetsInRegionB = new SDL_Rect[NO_OF_COLLISION_TARGETS];
    TargetsInRegionC = new SDL_Rect[NO_OF_COLLISION_TARGETS];
    TargetsInRegionD = new SDL_Rect[NO_OF_COLLISION_TARGETS];
    AssignTargetsInAllRegions();

}

SDL_Rect *ClassTargets::SetCollisionTargets(Region CurrentRegion)
{
    switch(CurrentRegion)
    {
    case REGION_A:
        return TargetsInRegionA;
        break;

    case REGION_B:
        return TargetsInRegionB;
        break;

    case REGION_C:
        return TargetsInRegionC;
        break;

    case REGION_D:
        return TargetsInRegionD;
        break;

    }

}

void inline ClassTargets::AssignRectProperties(SDL_Rect * A, int x, int y, int w, int h)
{
    A->x = x;
    A->y = y;
    A->h = h;
    A->w = w;

}

 void ClassTargets::AssignTargetsInAllRegions()
{
    SDL_Rect *A = TargetsInRegionA;
    SDL_Rect *B = TargetsInRegionB;
    SDL_Rect *C = TargetsInRegionC;
    SDL_Rect *D = TargetsInRegionD;
    int i = 0;
    const int NewOrigin = RENDERWIDTH / 4;
    AssignRectProperties((TargetsInRegionA +i), 0, 120, 78, 46);
    i++;
    AssignRectProperties((TargetsInRegionA +i), 0, 195, 78, 46);
    i++;
    AssignRectProperties((TargetsInRegionA +i), 0, 308, 36, 12);
    i++;
    AssignRectProperties((TargetsInRegionA +i), 36, 31, 42, 25);
    i++;
    AssignRectProperties((TargetsInRegionA +i), 36, 82, 42, 12);
    i++;
    AssignRectProperties((TargetsInRegionA +i), 36, 270, 42, 12);
    i++;
    AssignRectProperties((TargetsInRegionA +i), 36, 344, 129, 12);
    i++;
    AssignRectProperties((TargetsInRegionA +i), 66, 270, 12, 50);
    i++;
    AssignRectProperties((TargetsInRegionA +i), 108, 31, 57, 25);
    i++;
    AssignRectProperties((TargetsInRegionA +i), 108, 82, 12, 82);
    i++;
    AssignRectProperties((TargetsInRegionA +i), 108, 195, 12, 50);
    i++;
    AssignRectProperties((TargetsInRegionA +i), 108, 120, 57, 12);
    i++;
    AssignRectProperties((TargetsInRegionA +i), 108, 270, 57, 13);
    i++;
    AssignRectProperties((TargetsInRegionA +i), 108, 308, 12, 47);
    i++;
    AssignRectProperties((TargetsInRegionA +i), 150, 82, 98, 12 );
    i++;
    AssignRectProperties((TargetsInRegionA +i), 150, 232, 98, 12 );
    i++;
    AssignRectProperties((TargetsInRegionA +i), 150, 308, 98, 12 );
    i++;
    AssignRectProperties((TargetsInRegionA +i), 194, 0, 12, 55 );
    i++;
    AssignRectProperties((TargetsInRegionA +i), 194, 82, 12, 48 );
    i++;
    AssignRectProperties((TargetsInRegionA +i), 194, 232, 12, 48 );
    i++;
    AssignRectProperties((TargetsInRegionA +i), 194, 308, 12, 48 );
    int j = ++i;

    for(i = 0; i < j; i++ )
    {
        AssignRectProperties( B+i, (2 * NewOrigin - ( (A + i)->w + (A + i)->x )), (A + i)->y , (A + i)->w , (A + i)->h );
    }

    for(i = 0; i < j; i++ )
    {
        AssignRectProperties( C+i, (2 * NewOrigin + (A + i)->x), (A + i)->y , (A + i)->w , (A + i)->h );
    }
    for(i = 0; i < j; i++ )
    {
        AssignRectProperties( D+i, (2 * NewOrigin + ( B+ i)->x), (B + i)->y , (B + i)->w , (B + i)->h );
    }
    AssignRectProperties( (B + 22), 392, 0, 16, 160);
    AssignRectProperties( (B + 23), 392, 195, 16, 192);

    AssignRectProperties( (C + 22), 392, 0, 16, 160);
    AssignRectProperties( (C + 23), 392, 195, 16, 192);

    AssignRectProperties( (A + 22), 392, 0, 16, 160);
    AssignRectProperties( (A + 23), 392, 195, 16, 192);

    AssignRectProperties( (A + 22), 392, 0, 16, 160);
    AssignRectProperties( (A + 23), 392, 195, 16, 192);

}

 ClassTargets::~ClassTargets()
 {
     delete TargetsInRegionA;
     delete TargetsInRegionB;
     delete TargetsInRegionC;
     delete TargetsInRegionD;

 }







