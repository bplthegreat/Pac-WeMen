//!
//!
//!
//!
//!
//!
//!


#ifndef CLASSTEXTURE_H
#define CLASSTEXTURE_H
#include "Includes.h"
#include "GlobalDec.h"
#include "FunctionDec.h"

using namespace Global;
//class ClassMovingTexture;
class ClassTexture
{
public:
    ClassTexture();
    ClassTexture(int x, int y);
    virtual ~ClassTexture();
    int CreateTexture(SDL_Renderer * Renderer, std::string );
    void Free();
    void Render( SDL_Renderer * Renderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0,
                SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
    int GetWidth();
    int GetHeight();
    SDL_Rect * GetCollider();

    void SetColliderPosition( int , int );
protected:
private:
    SDL_Texture* DataTexture;
    int Width, Height;
    SDL_Rect Collider;

    inline void Clear()
    {   DataTexture = NULL;}
};

#endif // CLASSTEXTURE_H
