#include "Includes.h"
#include "Functions.h"
#include "ClassTexture.h"
#include "ClassMovingTexture.h"
#include "ClassMovingTexture.h"

using namespace FunctionIdentfiers;
using namespace Global;



int main(int argc, char *argv[])
{

    if(!Initialisation())
    {
        cout << "Error During Initialisation:" << SDL_GetError();
    }
    SDL_RenderClear(MainRenderer);
//    Texture.CreateTexture(MainRenderer, "Resources/Dot.bmp");
//    Texture.Render(MainRenderer, 0,0);
   //cout << Hello(" world");
    cout << EntryLoop();
    Close();
    return 0;
}
