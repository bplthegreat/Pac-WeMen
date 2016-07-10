#include "ClassMotion.h"

ClassMotion::ClassMotion()
{
    //ctor
    VelocityX = 0;
    VelocityY = 0;
}
ClassMotion::ClassMotion(int x, int y)
{
    //ctor
    PositionX = x;
    VelocityX = 0;
    PositionY = y;
    VelocityY = 0;
}

ClassMotion::~ClassMotion()
{
    //dtor
}

void ClassMotion::HandleEvent(MovementFlag Flag)
{
    switch(Flag)
    {
    case LEFT:
        VelocityX   = -Velocity;
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
void ClassMotion::Move(SDL_Rect *B)
{
    int PreviousX = PositionX,PreviousY = PositionY;
        PositionX += VelocityX;
        PositionY += VelocityY;
        if(IsOutOfZone() ) || MovingTexture::CheckCollision( SDL_Rect *B) )
        {
            PositionX = PreviousX;
            PositionY = PreviousY;
        }
}
bool ClassMotion::IsOutOfZone()
{
    if(PositionX < 2)
        return true;
    if(PositionX > 780)
        return true;
    if(PositionY < 2)
        return true;
    if(PositionY > 380)
        return true;
    return false;

}

const int ClassMotion::Velocity;
