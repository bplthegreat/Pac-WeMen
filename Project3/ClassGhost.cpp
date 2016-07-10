

#include "ClassGhost.h"

ClassGhost::ClassGhost(Side SideFlag) : MySide(SideFlag)
{
    //ctor
}

ClassGhost::ClassGhost(int x, int y , Side SideFlag): MySide(SideFlag), ClassMovingTexture( x, y )
{
    //ctor

}

ClassGhost::~ClassGhost()
{
    //dtor
}

PacmenDetail* ClassGhost::GetPacmenDetailPointer( int PacmenNo )
{
    return &PacmenData[ PacmenNo -1 ];
}



void ClassGhost::SetVelocityY(int Y_DistanceFromPacmen)
{

        if(Y_DistanceFromPacmen < 0)
            VelocityY = - Velocity;
        else
            VelocityY = Velocity;
        VelocityX = 0;
}
void ClassGhost::SetVelocityX( int X_DistanceFromPacmen)
{

        if(X_DistanceFromPacmen < 0)
            VelocityX =  - Velocity;
        else
            VelocityY = Velocity;
        VelocityY = 0;
}

void ClassGhost::ProduceRegionConfinement()
{
    SDL_Rect Confinement[3] = {{392, 168, 16, 27}, {0, 168, 16, 27}, {792, 168, 16, 27} };

    for(int Looper = 0 ; Looper < 3 ; Looper++)
    {
        if(CheckCollision(Confinement + Looper))
        {

            switch(Looper)
            {
            case 0:
                if(MySide == SIDE_A)
                    PositionX = ORIGIN_XY + 5;
                else
                    PositionX = RENDERWIDTH - 25;
                break;
            case 1:
                if(MySide == SIDE_A)
                    PositionX = 392-25;
                else
                    PositionX = RENDERWIDTH - 25;
                break;
            case 2:
                if(MySide == SIDE_A)
                    PositionX = 408 + 5;
                else
                    PositionX = RENDERWIDTH - 25;
                break;

            }
        }
    }
}

void ClassGhost::SetMyVelocity()
{
    int CollisionResult[NO_OF_COLLISION_TARGETS];
    int CollisionResultSum = 0;
    int X_DistanceFromPacmen, Y_DistanceFromPacmen;


    GetDistanceFromPacmen(&X_DistanceFromPacmen , &Y_DistanceFromPacmen );

//    if(X_DistanceFromPacmen != 0)
//        X_DistanceFromPacmen = X_DistanceFromPacmen / abs(X_DistanceFromPacmen);
//    if(Y_DistanceFromPacmen != 0)
//        Y_DistanceFromPacmen = Y_DistanceFromPacmen / abs(Y_DistanceFromPacmen);
//    VelocityX = Velocity * X_DistanceFromPacmen;
//    VelocityY = Velocity * Y_DistanceFromPacmen;

    int X = abs(X_DistanceFromPacmen);
    int Y = abs(Y_DistanceFromPacmen);
    if( X >= Y)
    {

        SetVelocityX(X_DistanceFromPacmen);

        PositionX +=VelocityX;
        PositionY +=VelocityY;

        SetColliderPosition(PositionX, PositionY);
        ClassMovingTexture::CheckCollision( CurrentCollisionTargets, NO_OF_COLLISION_TARGETS,  CollisionResult);
        for(int j = 0; j < NO_OF_COLLISION_TARGETS; j++)
            CollisionResultSum+=*(CollisionResult + j);



        if( CollisionResultSum > 0 || IsOutOfZone())
        {
            PositionX -= VelocityX;
            PositionY -= VelocityY;
            SetColliderPosition(PositionX, PositionY);
            SetVelocityY(Y_DistanceFromPacmen);
            ShouldIMove = true;
        }
        else
            ShouldIMove = false;

    }
    else
    {
        SetVelocityY(Y_DistanceFromPacmen);

        PositionX +=VelocityX;
        PositionY +=VelocityY;


        SetColliderPosition(PositionX, PositionY);
        ClassMovingTexture::CheckCollision( CurrentCollisionTargets, NO_OF_COLLISION_TARGETS,  CollisionResult);
        for(int j = 0; j < NO_OF_COLLISION_TARGETS; j++)
            CollisionResultSum+=*(CollisionResult + j);

        if( CollisionResultSum > 0 || IsOutOfZone())
        {
            PositionX -= VelocityX;
            PositionY -= VelocityY;
            SetColliderPosition(PositionX, PositionY);
            SetVelocityX(X_DistanceFromPacmen);
            ShouldIMove = true;
        }
        else
            ShouldIMove = false;
    }

    PositionX += VelocityX;
    PositionY += VelocityY;

//        int PreviousVX = VelocityX;
//        int PreviousVY = VelocityY;

        SetColliderPosition(PositionX, PositionY);
        ClassMovingTexture::CheckCollision( CurrentCollisionTargets, NO_OF_COLLISION_TARGETS,  CollisionResult);
        for(int j = 0; j < NO_OF_COLLISION_TARGETS; j++)
            CollisionResultSum+=*(CollisionResult + j);


    PositionX -= VelocityX;
    PositionY -= VelocityY;
    SetColliderPosition(PositionX, PositionY);

    if(CollisionResultSum > 0)
    {
        VelocityX = - VelocityX;
        VelocityY = - VelocityY;
    }

}

void ClassGhost::GetDistanceFromPacmen(int *X_DistanceFromPacmen , int *Y_DistanceFromPacmen )
{
    SDL_Rect *Collider = GetCollider();
    //cout << Collider-> x << " " << Collider->y << endl;

    for( int PacmenNo = 0; PacmenNo < 2; PacmenNo++)
    {
        if(PacmenData[PacmenNo].Allegiance != MySide)
        {
            *X_DistanceFromPacmen = PacmenData[PacmenNo].PacmenCollider.x - Collider->x;
            *Y_DistanceFromPacmen = PacmenData[PacmenNo].PacmenCollider.y - Collider->y;
//            std::cout << " x " << Collider->x << " y "<< Collider->y << " Vx " << VelocityX << " Vy " << VelocityY
//                    <<" del X =" << *X_DistanceFromPacmen << " delY " << *Y_DistanceFromPacmen <<endl;
        }
        break;
    }
}


bool ClassGhost::CheckCollisionWithPacmen()
{

    for(int PacmenNo = 0; PacmenNo < 2; PacmenNo++)
    {
        if(  PacmenData[PacmenNo].Allegiance != MySide)
        {
            return CheckCollision( &PacmenData[PacmenNo].PacmenCollider ) ;

            break;
        }
    }
    return false;

}


Side ClassGhost::Operate(SDL_Renderer * Renderer)
{

    //cout << "\t hello \t";

    SetCollisionTargets();
    if(CheckCollisionWithPacmen())
    {
        return MySide;//GEnerate exception
    }
    SetMyVelocity();
    Move(ShouldIMove);
    ProduceRegionConfinement();
    //cout << VelocityX << VelocityY;

    Render(Renderer);
    return SIDE_0;
}

PacmenDetail ClassGhost::PacmenData[2];
