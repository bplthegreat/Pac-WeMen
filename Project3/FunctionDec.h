#include "Includes.h"

#ifndef FUNCTION_DECLARATION
#define FUNCTION_DECLARATION

class ClassTexture;
class ClassMovingTexture;
class ClassMovingTexture;

using namespace std;

//template <typename Any >;

namespace FunctionIdentfiers{

    bool Initialisation();
    int Hello(char *);
    int EntryLoop();
    bool Pause(SDL_Renderer * );

    void Close();
    inline void Free(SDL_Surface *Surface)
    {
        SDL_FreeSurface(Surface);
    }
    inline void Free(SDL_Window *Window)
    {
        SDL_DestroyWindow(Window);
    }
    inline void Free(SDL_Texture *Texture)
    {
        SDL_DestroyTexture(Texture);
    }

    inline void Free(SDL_Renderer *Renderer)
    {
        SDL_DestroyRenderer(Renderer);
    }
    bool CheckCollision(SDL_Rect *, SDL_Rect *);
    void ShowRect(SDL_Rect *);
};


    #endif // FUNCTION_DECLARATION
