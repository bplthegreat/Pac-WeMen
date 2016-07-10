#include "ClassPacmen.h"

ClassPacmen::ClassPacmen(Side SideFlag):MySide(SideFlag)
{
    //ctor

}
ClassPacmen::ClassPacmen(  int x , int y, Side SideFlag):MySide(SideFlag), PacmenMode(x, y), GhostMode(x, y)
{
    //ctor


}

ClassPacmen::~ClassPacmen()
{
    //dtor
}

void ClassPacmen::SetRegion()
{
    PacmenMode.AssignRegion();
    GhostMode.AssignRegion();
}


 void ClassPacmen::SetModeFlag()
 {
     SetRegion();
     switch(MySide)
     {
     case SIDE_A:
        if(PacmenMode.GetCurrentRegion() == REGION_A || PacmenMode.GetCurrentRegion() == REGION_B)
        {
            ModeFlag = GHOSTMODE;
            break;
        }
        ModeFlag = PACMENMODE;
        break;

    case SIDE_B:
        if(PacmenMode.GetCurrentRegion() == REGION_C || PacmenMode.GetCurrentRegion() == REGION_D)
        {
            ModeFlag = GHOSTMODE;
            break;
        }
        ModeFlag = PACMENMODE;
        break;
     }
 }
 void ClassPacmen::PublishPacmenInformation(int PacmenNo)
 {
     GetPacmenData(PacmenData + PacmenNo);
 }


 void ClassPacmen::Render(SDL_Renderer *Renderer)
 {
    switch(ModeFlag)
    {
    case PACMENMODE:
        PacmenMode.Render(Renderer);
        break;
    case GHOSTMODE:
        GhostMode.Render(Renderer);
        break;
    }
 }

 Side ClassPacmen::Operate(SDL_Renderer * Renderer, int PacmenNo)
 {
     PublishPacmenInformation(PacmenNo - 1);
     if( CheckCollisionWithPacmen() )
     {
        if(PacmenMode.GetCurrentRegion() == REGION_A || PacmenMode.GetCurrentRegion() == REGION_B)
            return SIDE_A;
        else
            return SIDE_B;
     }

     SetCollisionTargets();
     SetModeFlag();
     ProduceRegionConfinement();
     PacmenMode.Move();
     GhostMode.Move();
     Render(Renderer);
 }

 void ClassPacmen::HandleEvent(MovementFlag Flag)
 {
     PacmenMode.HandleEvent(Flag);
     GhostMode.HandleEvent(Flag);
 }
 void ClassPacmen::Move()
 {
    PacmenMode.Move();
    PacmenMode.Move();
 }

 void ClassPacmen::SetCollisionTargets()
 {
     PacmenMode.SetCollisionTargets();
     GhostMode.SetCollisionTargets();
 }

 int ClassPacmen::CreateTexture(SDL_Renderer * Renderer, std::string path, Mode Flag)
 {
     //std::cout << endl<< path ;
     //std::cout << endl<< Flag ;

     int ReturnValue = 0;
     switch(Flag)
     {
     case PACMENMODE:
        ReturnValue += PacmenMode.CreateTexture(Renderer, path);
        break;
     case GHOSTMODE:
        ReturnValue += GhostMode.CreateTexture(Renderer , path);
        break;
     }
     return ReturnValue;
 }
 void ClassPacmen::ProduceRegionConfinement()
{
    SDL_Rect Confinement[2] = {{0, 168, 16, 27}, {792, 168, 16, 27} };

    for(int Looper = 0 ; Looper < 2 ; Looper++)
    {
        if(PacmenMode.CheckCollision(Confinement + Looper))
        {

            switch(Looper)
            {
            case 0:

                PacmenMode.SetPositionX( 792-20);
                GhostMode.SetPositionX( 792-20);
                break;
            case 1:


                PacmenMode.SetPositionX( ORIGIN_XY + 20);
                GhostMode.SetPositionX( ORIGIN_XY + 20);
                break;

            }
        }
    }
}


 void ClassPacmen::GetPacmenData(PacmenDetail *DetailPointer )
 {
     DetailPointer->PacmenCollider =  *PacmenMode.GetCollider();
     DetailPointer->Allegiance = GetMySide();
 }

Side ClassPacmen::GetMySide()
{
    return MySide;
}

bool ClassPacmen::CheckCollisionWithPacmen()
{

    for(int PacmenNo = 0; PacmenNo < 2; PacmenNo++)
    {
        if(  PacmenData[PacmenNo].Allegiance != MySide)
        {
            return GhostMode.CheckCollision( &PacmenData[PacmenNo].PacmenCollider ) ;

            break;
        }
    }
    return false;
}


PacmenDetail ClassPacmen::PacmenData[2];


