#include "Includes.h"
#ifndef GLOBAL_DECLARATION
#define GLOBAL_DECLARATION
#define NO_OF_COLLISION_TARGETS 24

namespace Global
{
    static SDL_Window *MainWindow = NULL;
    static SDL_Renderer *MainRenderer = NULL;
    static const int SCREENWIDTH = 800;
    static const int RENDERWIDTH = 800;
    static const int SCREENHEIGHT = 388;
    static const int RENDERHEIGHT = 388;
    static const int ORIGIN_XY = 0;
    static const SDL_Rect GameZone = {ORIGIN_XY, ORIGIN_XY, RENDERWIDTH, RENDERHEIGHT};

    typedef struct
    {
        int Radius;
        int CX, CY;
    }SDL_Circle;

    typedef enum
    {
        LEFT    = 0x1,
        RIGHT   = 0x2,
        UP      = 0x4,
        DOWN    = 0x8
    }MovementFlag;

    typedef enum
    {
        REGION_A = 0,
        REGION_B,
        REGION_C,
        REGION_D
    }Region;

    typedef enum
    {
        PACMENMODE  = 0,
        GHOSTMODE   = 1
    }Mode;
    typedef enum
    {
        SIDE_A = 1,
        SIDE_B = 2,
        SIDE_1 = 1,
        SIDE_2 = 2,
        SIDE_0 = 0
    }Side;
    typedef struct
    {
        SDL_Rect PacmenCollider;
        Side Allegiance;
    }PacmenDetail;

   // Side Winner;

}

#endif // GLOBAL_DECLARATION
