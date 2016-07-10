
//
// This class is to be used in future Builds to
//
// Do all types of Vector Manipulation
//
// Position Velocity Projection Collision Targeting


#ifndef CLASSVECTOR_H
#define CLASSVECTOR_H


class ClassVector
{
    public:
        ClassVector(int x = 0, int y = 0);
        virtual ~ClassVector();
        ClassVector operator+(ClassVector A);

    protected:

    private:
        int ComponentX;
        int ComponentY;
};

#endif // CLASSVECTOR_H
