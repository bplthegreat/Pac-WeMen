/*
    This is the topmost class in the Hierarchy of our Classes.
    This class has
    -Collider structure ( which is a Rectangle ) for checking collision with other Colliders (Also Rectangle).
    -Texture for loading Medias;

*/

#include "ClassTexture.h"

int ClassTexture::CreateTexture(SDL_Renderer * Renderer, std::string path)
{
    SDL_Surface *TempSurface = NULL;
    SDL_Texture *TempTexture = NULL;
    TempSurface = IMG_Load(path.c_str());
   // FunctionIdentifiers::Check('a');
    if(TempSurface == NULL)
        std::cout << "Image not loaded " << SDL_GetError();
    Clear();
    SDL_SetColorKey( TempSurface, SDL_TRUE, SDL_MapRGB( TempSurface->format, 0, 0xFF, 0xFF ) );
    TempTexture = SDL_CreateTextureFromSurface(Renderer, TempSurface);
    if(TempTexture == NULL)
        std:: cout << "Texture could not be created" <<SDL_GetError();
    Height = TempSurface->h;
    Width = TempSurface->w;
    Collider.h = Height;
    Collider.w = Width;
    FunctionIdentfiers::Free(TempSurface);
    DataTexture = TempTexture;


    //cout << endl << "From ClassTexture:" << (DataTexture != NULL) << endl;

    if(DataTexture != NULL)
        return 1;
    else
        return 0;
}


void ClassTexture::Render(SDL_Renderer * Renderer, int x, int y, SDL_Rect* Clip,
                           double Angle, SDL_Point* Center, SDL_RendererFlip Flip)
{
    SDL_Rect DestinationSpace = {x, y, Width, Height};
    if(Clip != NULL)
    {
        DestinationSpace.w = Clip->w;

        DestinationSpace.h = Clip->h;

    }
//    std::cout <<" " << DestinationSpace.w;
//        std::cout <<" " << DestinationSpace.h;
    if(Flip == SDL_FLIP_NONE && Center == NULL && Angle == 0)
        SDL_RenderCopy(Renderer, DataTexture, Clip , &DestinationSpace);
    else if(Center == NULL && Angle == 0)
        SDL_RenderCopyEx(Renderer, DataTexture, Clip , &DestinationSpace, 0, NULL, Flip);
    else
        SDL_RenderCopyEx(Renderer, DataTexture, Clip , &DestinationSpace, Angle, Center, Flip);
}

void ClassTexture::SetColliderPosition( int x, int y)
    {
        Collider.x = x;
        Collider.y = y;
    }

int ClassTexture::GetWidth()
{
    return Width;
}

int ClassTexture::GetHeight()
{
    return Height;
}

SDL_Rect * ClassTexture::GetCollider()
{
    return &Collider;
}

ClassTexture::ClassTexture()
{
    //ctor
    DataTexture = NULL;
    Width = 0;
    Height = 0;
    Collider.x = 0;
    Collider.y = 0;
    Collider.w = 0;
    Collider.h = 0;
}

ClassTexture::ClassTexture( int x , int y)
{
    //ctor
    DataTexture = NULL;
    Width = 0;
    Height = 0;
    Collider.x = x;
    Collider.y = y;
    Collider.w = 0;
    Collider.h = 0;
}

ClassTexture::~ClassTexture()
{
    //dtor
    FunctionIdentfiers::Free(DataTexture);
}

void ClassTexture::Free()
{
    //cout<<"nth";
    DataTexture = NULL;
    Width = 0;
    Height = 0;
    Collider.x = 0;
    Collider.y = 0;
    Collider.w = 0;
    Collider.h = 0;
}











