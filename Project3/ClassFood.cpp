#include "ClassFood.h"

ClassFood::ClassFood()
{
    EatenFlag = false;
}


void ClassFood::SetLocation(int x, int y)
{
    SDL_Rect *Collider = GetCollider();
    Collider->x = x;
    Collider->y = y;
    PositionX = x;
    PositionY = y;
    EatenFlag = false;
    TotalNoOfFood++;
}
void ClassFood::SetSideFlag(Side SideFlag)
{
    MySide = SideFlag;
    if(SideFlag == SIDE_A)
        Side_AFood++;
    else
        Side_BFood++;
    EatenFlag = false;
}


ClassFood::~ClassFood()
{
    //dtor
}

int ClassFood::GetTotalFood()
{
    return TotalNoOfFood;
}
int ClassFood::GetRemainingFood()
{
    return (TotalNoOfFood - NoOfEatenFood);
}
int ClassFood::GetNoOfEatenFood()
{
    return NoOfEatenFood;
}

Side ClassFood::Operate(SDL_Renderer *Renderer)
{
    Side Winner = SIDE_0;
    Winner = CheckCollisionWithPacmen();
    Render(Renderer);
    return Winner;
}

void ClassFood::Render(SDL_Renderer * Renderer)
{
    if(!EatenFlag)
        ClassTexture::Render(Renderer, PositionX, PositionY);
}

Side ClassFood::CheckCollisionWithPacmen()
{
    if(!EatenFlag)
    {
        for(int i = 0; i < 2;i++)
        {
            if(  PacmenData[i].Allegiance!= MySide)
            {
                if( CheckCollision( &PacmenData[i].PacmenCollider, GetCollider() ) )
                {

                    EatenFlag = true;
                    switch(MySide)
                    {
                    case SIDE_A:
                        Side_AFood--;
                        if(Side_AFood == 0)
                            return SIDE_B;

                        break;
                    case SIDE_B:
                        Side_BFood--;
                        if(Side_BFood == 0)
                            return SIDE_A;

                    }

                }
                break;
            }
        }
    }
    return SIDE_0;

}
PacmenDetail* ClassFood::GetPacmenDetailPointer( int PacmenNo )
{
    return &PacmenData[ PacmenNo -1 ];
}

int ClassFood::TotalNoOfFood;
int ClassFood::NoOfEatenFood;
int ClassFood::Side_AFood;
int ClassFood::Side_BFood;
PacmenDetail ClassFood::PacmenData[2];




void ClassFood::ShowFoodDetail()
{
    cout << " x, y =" << PositionX << ',' << PositionY ;
    if(EatenFlag)
        cout << " Eaten ";
    if(MySide == 1)
        cout << " side a\n";
    else cout << " side b\n";
}

void SetFoodLocation( ClassFood *Food)
{
    int iX, iY;
    int FoodNo = 0;
    int XArray[] = {40, 70, 100, 130, 160, 190, 210, 240, 270, 300, 330, 360, 390, 410};
    int YArray[] = {360, 325, 288, 250 ,173 ,100, 61, 16};
    for ( int iX = 0 ; iX < 14 ; iX ++ )
    {
        for (iY = 0 ; iY < 8 ; iY++, FoodNo++ )
        {
            (Food + FoodNo)->SetLocation( *(XArray + iX) - 30, *(YArray + iY) );
            if( iY == 2 && ( iX == 2 || iX == 11 ) )
                (Food + FoodNo)->SetLocation( *(XArray + iX -1) - 30, *(YArray + iY) );
            (Food + FoodNo)->SetSideFlag(SIDE_A);
        }
    }

    for (iX = 0 ; iX < 14 ; iX++)
    {
        *(XArray + iX) = *(XArray + iX) + 400;
    }

    for ( iX = 0 ; iX < 14 ; iX ++ )
    {
        for (iY = 0 ; iY < 8 ; iY++, FoodNo++)
        {
            (Food + FoodNo)->SetLocation( *(XArray + iX) - 30, *(YArray + iY) );
            if( iY == 2 && ( iX == 2 || iX == 11 ) )
                (Food + FoodNo)->SetLocation( *(XArray + iX -1) - 30, *(YArray + iY) );
            (Food + FoodNo)->SetSideFlag(SIDE_B);
        }
    }
    int CurrentFoodCount = (iX -1) * ( iY -1) * 2;

}
