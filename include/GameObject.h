#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
protected:

    int x;
    int y;

public:

    GameObject(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }

    virtual ~GameObject() {}

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

    virtual char getSymbol() const = 0;
};

#endif