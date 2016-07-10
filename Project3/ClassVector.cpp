#include "ClassVector.h"

ClassVector::ClassVector( int x , int y ):ComponentX(x), ComponentY(y)
{
    //ctor
}

ClassVector::~ClassVector()
{
    //dtor
}


ClassVector ClassVector::operator+(ClassVector A)
{
    ClassVector Temp;
    Temp.ComponentX = ComponentX + A.ComponentX;
    Temp.ComponentX = ComponentY + A.ComponentY;
    return Temp;
}





