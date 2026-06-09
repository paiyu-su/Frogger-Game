#ifndef COIN_H
#define COIN_H

class Coin
{
private:

    int x;
    int y;
    bool active;

public:

    Coin()
    {
        x = 0;
        y = 0;
        active = true;
    }

    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }

    bool isActive() const
    {
        return active;
    }

    void setX(int newX)
    {
        x = newX;
    }

    void setY(int newY)
    {
        y = newY;
    }

    void setActive(bool state)
    {
        active = state;
    }
};

#endif