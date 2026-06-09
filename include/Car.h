#ifndef CAR_H
#define CAR_H

class Car
{
private:

    int x;
    int y;
    int dir;

public:

    Car()
    {
        x = 0;
        y = 0;
        dir = 1;
    }

    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }

    int getDir() const
    {
        return dir;
    }

    void setX(int newX)
    {
        x = newX;
    }

    void setY(int newY)
    {
        y = newY;
    }

    void setDir(int newDir)
    {
        dir = newDir;
    }
};

#endif