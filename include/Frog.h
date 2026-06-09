#ifndef FROG_H
#define FROG_H

class Frog
{
private:
    int x;
    int y;

public:

    Frog()
    {
        x = 0;
        y = 0;
    }

    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }

    void setX(int newX)
    {
        x = newX;
    }

    void setY(int newY)
    {
        y = newY;
    }
};

#endif