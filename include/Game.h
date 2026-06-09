#ifndef GAME_H
#define GAME_H

#include "Car.h"
#include "Frog.h"
#include "Coin.h"

class Game
{
private:

    static const int WIDTH = 30;
    static const int HEIGHT = 15;

    Frog frog;

    Car cars[10];

    Coin coin;

    int carCount;
    int gameSpeed;

    int score;
    int lives;
    int level;

    bool gameOver;

    bool greenLight;
    int trafficCounter;

public:

    Game();

    void selectDifficulty();

    void setup();

    void draw();

    void input();

    void updateCars();

    void updateTrafficLight();

    void checkCollision();

    void checkCoin();

    void checkWin();

    void run();
};

#endif