

#include "Includes.h"
#include "FunctionDec.h"
#include "GlobalDec.h"
#include "ClassTexture.h"
#include "ClassMovingTexture.h"
#include "ClassMovingtexture.h"
#include "ClassPacmen.h"
#include "ClassPacmenData.h"
#include "ClassFood.h"
#include "ClassGhost.h"



using namespace std;
using namespace FunctionIdentfiers;
using namespace Global;



bool FunctionIdentfiers::Initialisation()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Video Init error:" << SDL_GetError();
        return false;
    }

    if (SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1") < 0)
    {
        cout << "Linear Texture error:" << SDL_GetError();
        return false;
    }

    MainWindow = SDL_CreateWindow("Pac- We men", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREENWIDTH, SCREENHEIGHT, SDL_WINDOW_SHOWN);
    if (MainWindow == NULL)
    {
        cout << "Window Error:" << SDL_GetError();
        return false;
    }



    MainRenderer = SDL_CreateRenderer(MainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (MainRenderer == NULL)
    {
        cout << "Renderer error:" << SDL_GetError();
        return false;
    }

    SDL_SetRenderDrawColor(MainRenderer, 0x0F, 0x0F, 0xFF, 0xFF);

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG ;

    if (!((IMG_Init(imgFlags)) & imgFlags))
    {
        cout << "Img Error:" << SDL_GetError();
        return false;
    }

    return true;
}


void FunctionIdentfiers::Close()
{
    Free(MainRenderer);
    Free(MainWindow);
    IMG_Quit();
    SDL_Quit();
}
int FunctionIdentfiers::Hello(char *str)
{
    int a = 37;
    cout << "Hello" << str;
    return a;
}

int FunctionIdentfiers::EntryLoop()
{
    int PACMEN_1 = 1;
	int PACMEN_2 = 2;
    Side Winner = SIDE_0;
    ClassPacmen PacMan1(5,5, SIDE_1);
    ClassPacmen PacMan2(200,200, SIDE_2);
    ClassMovingTexture a(500,400);
    ClassMovingTexture b(700,300);
    ClassMovingTexture c(100,400);
    ClassMovingTexture d(300,300);
    //ClassGhost G1(765, 360, SIDE_2);
    ClassGhost Ghost[6] = {ClassGhost( 360, 360, SIDE_1), ClassGhost(365,5, SIDE_1), ClassGhost(10, 355, SIDE_1),
                           ClassGhost( 765, 260, SIDE_2), ClassGhost(765,5, SIDE_2), ClassGhost(410, 365, SIDE_2) };
    ClassTexture Background;


    ClassFood Food[256];

   // ClassFood F;
   // F.SetLocation(500,300);
   // F.SetSideFlag(SIDE_2);

    SetFoodLocation(Food);



//    F.CreateTexture(MainRenderer ,"Resources/Food.jpg");

    for(int i =0; i < 6 ;i++)
    {
        if( i < 3)
            Ghost[i].CreateTexture(MainRenderer, "Resources/Ghost1.png");
        if ( i >= 3)
            Ghost[i].CreateTexture(MainRenderer, "Resources/Ghost2.png");
    }


    //G1.CreateTexture(MainRenderer, "Resources/Ghost1.jpg");

    for (int i = 0 ;i < 256 ; i++)
        if(!((Food + i)->CreateTexture(MainRenderer ,"Resources/Food.jpg") ))
            std::cout << endl << "Food Texture not Created" << endl;

    if(!Background.CreateTexture(MainRenderer, "Resources/Original.jpg"))
        std::cout << endl << "Texture not created"<< SDL_GetError();

    SDL_RenderClear(MainRenderer);


/*
    if(!PacMan1.CreateTexture(MainRenderer, "Resources/Pacman1.jpg",PACMENMODE))
        std::cout << endl << "1 Texture not created "<< SDL_GetError();
    if(!PacMan2.CreateTexture(MainRenderer, "Resources/Pacman2.jpg", PACMENMODE))
        std::cout << endl << "2 Texture not created "<< SDL_GetError();
    if(!PacMan1.CreateTexture(MainRenderer, "Resources/PacGhost1.jpg",GHOSTMODE))
        std::cout << endl << "3 Texture not created "<< SDL_GetError();
    if(!PacMan2.CreateTexture(MainRenderer, "Resources/PacGhost2.jpg", GHOSTMODE))
        std::cout << endl << "4 Texture not created "<< SDL_GetError();
*/

    if(!PacMan1.CreateTexture(MainRenderer, "Resources/Pacmen1.png",PACMENMODE))
        std::cout << endl << "1 Texture not created "<< SDL_GetError();
    if(!PacMan2.CreateTexture(MainRenderer, "Resources/Pacmen2.png", PACMENMODE))
        std::cout << endl << "2 Texture not created "<< SDL_GetError();
    if(!PacMan1.CreateTexture(MainRenderer, "Resources/pacmen_ghost1.png",GHOSTMODE))
        std::cout << endl << "3 Texture not created "<< SDL_GetError();
    if(!PacMan2.CreateTexture(MainRenderer, "Resources/pacmen_ghost2.png", GHOSTMODE))
        std::cout << endl << "4 Texture not created "<< SDL_GetError();






    SDL_Event Event;
    bool Quit = false;

    while (!Quit)
    {
        while(SDL_PollEvent(&Event)!= 0)
        {
           //Quit = HandleEvent(Event);
           switch(Event.type)
            {
            case SDL_QUIT:
                Quit = true;
                break;
            case SDL_KEYDOWN:
                switch(Event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    Quit = true;
                    break;
                case SDLK_p:
                    Quit = Pause(MainRenderer);
                    break;
                case SDLK_w:
                    PacMan1.HandleEvent(UP);
                    break;
                case SDLK_a:
                    PacMan1.HandleEvent(LEFT);
                    break;
                case SDLK_s:
                    PacMan1.HandleEvent(DOWN);
                    break;
                case SDLK_d:
                    PacMan1.HandleEvent(RIGHT);
                    break;
                case SDLK_UP:
                    PacMan2.HandleEvent(UP);
                    break;
                case SDLK_LEFT:
                    PacMan2.HandleEvent(LEFT);
                    break;
                case SDLK_DOWN:
                    PacMan2.HandleEvent(DOWN);
                    break;
                case SDLK_RIGHT:
                    PacMan2.HandleEvent(RIGHT);
                    break;
                }
                break;
            }
        }
        SDL_SetRenderDrawColor(MainRenderer, 0x2F, 0x2F, 0x2F, 0xFF);
        SDL_RenderClear(MainRenderer);
        SDL_SetRenderDrawColor(MainRenderer, 0xFF, 0x7F, 0x7F, 0xFF);

        SDL_RenderDrawRect(MainRenderer,&GameZone);
        a.SetCollisionTargets();
        b.SetCollisionTargets();
        c.SetCollisionTargets();
        d.SetCollisionTargets();
        Background.Render(MainRenderer, ORIGIN_XY,ORIGIN_XY);

        SDL_RenderDrawRects(MainRenderer, d.CurrentCollisionTargets, NO_OF_COLLISION_TARGETS);
        SDL_RenderDrawRects(MainRenderer, c.CurrentCollisionTargets, NO_OF_COLLISION_TARGETS);
        SDL_RenderDrawRects(MainRenderer, b.CurrentCollisionTargets, NO_OF_COLLISION_TARGETS);
        SDL_RenderDrawRects(MainRenderer, a.CurrentCollisionTargets, NO_OF_COLLISION_TARGETS);

        SDL_SetRenderDrawColor(MainRenderer, 0x00, 0x0F,0xFF,0xF7);



        Winner = PacMan1.Operate(MainRenderer, PACMEN_1);
		if (Winner != SIDE_0)
			return Winner;

        Winner = PacMan2.Operate(MainRenderer, PACMEN_2);
		if (Winner != SIDE_0)
			return Winner;

        PacMan1.GetPacmenData(ClassFood::GetPacmenDetailPointer(PACMEN_1) );
        PacMan2.GetPacmenData( ClassFood::GetPacmenDetailPointer(PACMEN_2) );

        PacMan1.GetPacmenData(ClassGhost::GetPacmenDetailPointer(PACMEN_1) );
        PacMan2.GetPacmenData( ClassGhost::GetPacmenDetailPointer(PACMEN_2) );




        for(int i = 0; i < 6; i++)
		{
			Winner = Ghost[i].Operate(MainRenderer);
			if (Winner != SIDE_0)
				return Winner;
		}

        //G1.Operate(MainRenderer);

        //F.Operate(MainRenderer);
		for (int i = 0; i < 256; i++)
		{
			Winner = (Food + i)->Operate(MainRenderer);
			if (Winner != SIDE_0)
				return Winner;
		}

        SDL_RenderPresent(MainRenderer);
    }


    return 0;
}



bool FunctionIdentfiers::Pause(SDL_Renderer* MainRenderer)
{
    bool UpFlag = true;
    int i = 0;
    while(1)
    {

        if( UpFlag )
        {
            i++;
            if( i == 200)
                UpFlag = false;
        }
        else
        {
            i--;
            if(i == 50)
                UpFlag = true;
        }

        SDL_Event EventWhilePaused;
        while(SDL_PollEvent( &EventWhilePaused) != 0)
        {
            if(EventWhilePaused.type == SDL_QUIT)
                return true;
            if(EventWhilePaused.type == SDL_KEYDOWN)
                switch(EventWhilePaused.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    return true;

                case SDLK_r:
                case SDLK_s:
                case SDLK_p:
                    return false;

                }
        }
        SDL_SetRenderDrawColor(MainRenderer, i , i, i , 0xFF);
        SDL_Rect PauseRects[2] = {{365,122, 25, 110 }, {408, 122, 25, 110 }};
        SDL_RenderFillRects(MainRenderer, PauseRects, 2);
        //SDL_RenderDrawCircle();
        //SDL_RenderDrawRects(MainRenderer, PauseRects, 2);
        SDL_RenderPresent(MainRenderer);
    }

}

bool FunctionIdentfiers::CheckCollision(SDL_Rect *A, SDL_Rect *B)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A->x;
    rightA = A->x + A->w;
    topA = A->y;
    bottomA = A->y + A->h;

    //Calculate the sides of rect B
    leftB = B->x;
    rightB = B->x + B->w;
    topB = B->y;
    bottomB = B->y + B->h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }
   // ShowRect(A);

    //If none of the sides from A are outside B
    return true;
}


void Free(SDL_Surface *Surface)
{
    SDL_FreeSurface(Surface);
}


void FunctionIdentfiers::ShowRect(SDL_Rect* A)
{
    cout << "x,y = " << A->x << ',' << A->y << "  h, w = " << A->h << ',' << A->w;
}
