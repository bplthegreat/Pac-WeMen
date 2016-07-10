#include "ClassPacmenData.h"


SDL_Rect * ClassPacmenData::GetPacmenCollider(int i)
{
    return (PacmenCollider + i);
}

Side* ClassPacmenData::GetPacmenSide(int i)
{
    return (PacmenSide + i);
}


void ClassPacmenData::ShowRects()
{

    cout << "I am in";
    ShowRect(PacmenCollider);

    ShowRect((PacmenCollider + 1));
}

SDL_Rect ClassPacmenData::PacmenCollider[2];
Side ClassPacmenData::PacmenSide[2];
