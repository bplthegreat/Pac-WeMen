#include "ClassTexture.h"
#include "ClassMovingTexture.h"

ClassMovingTexture::ClassMovingTexture()
{
    //ctor
    PositionX = 0;
    PositionY = 0;
    VelocityX = 0;
    VelocityY = 0;
    AssignRegion();
}
ClassMovingTexture::ClassMovingTexture(int x, int y):ClassTexture(x,y)
{
    //ctor
    PositionX = x;
    VelocityX = 0;
    PositionY = y;
    VelocityY = 0;
    AssignRegion();
}

ClassMovingTexture::~ClassMovingTexture()
{
    //dtor
}

void ClassMovingTexture::Render(SDL_Renderer * Renderer)
{
    SDL_Point Center = { 0, 0};
    SDL_Rect * Collider = GetCollider();
    if(VelocityY == 0)
    {
        if(VelocityX < 0 )
            ClassTexture::Render(Renderer, ClassMovingTexture::PositionX,ClassMovingTexture::PositionY, NULL, 0, NULL, SDL_FLIP_HORIZONTAL);
        else
            ClassTexture::Render(Renderer, ClassMovingTexture::PositionX,ClassMovingTexture::PositionY);
    }
//    else if( VelocityY < 0)
//    {
//        Center.x = Collider->x + Collider->w / 2;
//        Center.y = Collider->y + Collider->h / 2;
//
//        ClassTexture::Render(Renderer, ClassMovingTexture::PositionX,ClassMovingTexture::PositionY, NULL, 90, &Center , SDL_FLIP_NONE);
//    }
//    else
//    {
//        Center.x = Collider->x + Collider->w / 2;
//        Center.y = Collider->y + Collider->h / 2;
//
//        ClassTexture::Render(Renderer, ClassMovingTexture::PositionX,ClassMovingTexture::PositionY, NULL, 270, &Center , SDL_FLIP_NONE);
//
//    }
    else
        ClassTexture::Render(Renderer, ClassMovingTexture::PositionX,ClassMovingTexture::PositionY);
}


void ClassMovingTexture::HandleEvent(MovementFlag Flag)
{
    switch(Flag)
    {
    case LEFT:
        VelocityX   = - Velocity;
        VelocityY   = 0;
        break;
    case RIGHT:
        VelocityX   = Velocity;
        VelocityY   = 0;
        break;
    case UP:
        VelocityX   = 0;
        VelocityY   = - Velocity;
        break;
    case DOWN:
        VelocityX = 0;
        VelocityY = Velocity;
    }
}
void ClassMovingTexture::Move( bool  DOYOUREALLYWANTTOMOVE)
{
    int *CollisionResult, CollisionResultSum = 0;
    CollisionResult = new int[NO_OF_COLLISION_TARGETS];
    SDL_Rect *Collider = GetCollider();
    int PreviousX = PositionX, PreviousY = PositionY;

        if(DOYOUREALLYWANTTOMOVE)
        {
            PositionX += VelocityX;
            PositionY += VelocityY;
            Collider->x = PositionX;
            Collider->y = PositionY;
        }


        ClassMovingTexture::CheckCollision( CurrentCollisionTargets, NO_OF_COLLISION_TARGETS,  CollisionResult);

        for(int j = 0; j < NO_OF_COLLISION_TARGETS; j++)
            CollisionResultSum+=*(CollisionResult + j);
        if((IsOutOfZone() || CollisionResultSum ))
        {
            //std::cout << PositionX << "  ";
            //std::cout << PositionY << "\n";
            PositionX = PreviousX;
            PositionY = PreviousY;
           // std::cout << PositionX << "  ";
           // std::cout << PositionY << "\n";
        }
}

void ClassMovingTexture::SetPositionX(int x)
{
    PositionX = x;
}

bool ClassMovingTexture::IsOutOfZone()
{
    if(PositionX < ORIGIN_XY + 5)
        return true;
    if(PositionX > RENDERWIDTH - 25)
        return true;
    if(PositionY < ORIGIN_XY + 5)
        return true;
    if(PositionY > RENDERHEIGHT - 25)
        return true;
    return false;

}



bool ClassMovingTexture::CheckCollision(SDL_Rect *B)
{
    SDL_Rect *A = GetCollider();
    return FunctionIdentfiers::CheckCollision(A ,B);
}

void ClassMovingTexture::CheckCollision (SDL_Rect *Targets, int TotalTargets, int *Result)
{
    for(int i = 0; i < TotalTargets; i++)
    {
        *(Result + i) = CheckCollision((Targets + i));
    }

}


Region ClassMovingTexture::AssignRegion()
{
    if(PositionX > 3 * RENDERWIDTH / 4)
        CurrentRegion = REGION_D;
    else if (PositionX > 2 * RENDERWIDTH / 4)
        CurrentRegion = REGION_C;
    else if (PositionX >  RENDERWIDTH / 4)
        CurrentRegion = REGION_B;
    else
        CurrentRegion = REGION_A;
    return CurrentRegion;
}
 Region ClassMovingTexture::GetCurrentRegion()
 {
    return AssignRegion();
 }

 void ClassMovingTexture::SetCollisionTargets()
 {
    AssignRegion();
    CurrentCollisionTargets =  ClassTargets::SetCollisionTargets(CurrentRegion);
 }


const int ClassMovingTexture::Velocity;
