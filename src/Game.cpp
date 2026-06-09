#include "Game.h"

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

Game::Game()
{
    score = 0;
    level = 1;

        gameOver = false;

    greenLight = true;
    trafficCounter = 0;

}

void Game::selectDifficulty()
{
    int choice;

        cout << "===== Difficulty =====\n";
    cout << "1. Easy\n";
    cout << "2. Normal\n";
    cout << "3. Hard\n";
    cout << "Choose : ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        lives = 5;
        carCount = 4;
        gameSpeed = 250;
        break;

    case 2:
        lives = 3;
        carCount = 6;
        gameSpeed = 180;
        break;

    case 3:
        lives = 2;
        carCount = 8;
        gameSpeed = 100;
        break;

    default:
        lives = 3;
        carCount = 6;
        gameSpeed = 180;
    }

}

void Game::setup()
{
    selectDifficulty();

        frog.setX(WIDTH / 2);
    frog.setY(HEIGHT - 1);

    for (int i = 0; i < carCount; i++)
    {
        cars[i].setX(rand() % WIDTH);
        cars[i].setY(2 + i);
        cars[i].setDir((i % 2 == 0) ? 1 : -1);
    }

    coin.setX(rand() % WIDTH);
    coin.setY(1 + rand() % (HEIGHT - 2));
    coin.setActive(true);

}

void Game::draw()
{
    system("cls");

        cout << "===== Frogger =====\n";

    cout << "Score : " << score
        << "  Lives : " << lives
        << "  Level : " << level
        << endl;

    cout << "Traffic Light : ";

    if (greenLight)
        cout << "GREEN\n";
    else
        cout << "RED\n";

    cout << "\n";

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            bool printed = false;

            if (x == frog.getX() &&
                y == frog.getY())
            {
                cout << "F";
                printed = true;
            }

            for (int i = 0; i < carCount; i++)
            {
                if (x == cars[i].getX() &&
                    y == cars[i].getY())
                {
                    cout << "C";
                    printed = true;
                }
            }

            if (coin.isActive() &&
                x == coin.getX() &&
                y == coin.getY())
            {
                cout << "$";
                printed = true;
            }

            if (!printed)
            {
                if (y == 0)
                    cout << "=";
                else if (y % 2 == 0)
                    cout << ".";
                else
                    cout << " ";
            }
        }

        cout << endl;
    }

}

void Game::input()
{
    if (_kbhit())
    {
        char key = _getch();

            if (key == 'w' || key == 'W')
                frog.setY(frog.getY() - 1);

        if (key == 's' || key == 'S')
            frog.setY(frog.getY() + 1);

        if (key == 'a' || key == 'A')
            frog.setX(frog.getX() - 1);

        if (key == 'd' || key == 'D')
            frog.setX(frog.getX() + 1);

        if (frog.getX() < 0)
            frog.setX(0);

        if (frog.getX() >= WIDTH)
            frog.setX(WIDTH - 1);

        if (frog.getY() < 0)
            frog.setY(0);

        if (frog.getY() >= HEIGHT)
            frog.setY(HEIGHT - 1);
    }

}

void Game::updateTrafficLight()
{
    trafficCounter++;

        if (trafficCounter >= 30)
        {
            greenLight = !greenLight;
            trafficCounter = 0;
        }

}

void Game::updateCars()
{
    if (!greenLight)
        return;

        for (int i = 0; i < carCount; i++)
        {
            cars[i].setX(
                cars[i].getX() +
                cars[i].getDir()
            );

            if (cars[i].getX() >= WIDTH)
                cars[i].setX(0);

            if (cars[i].getX() < 0)
                cars[i].setX(WIDTH - 1);
        }

}

void Game::checkCoin()
{
    if (coin.isActive() &&
        frog.getX() == coin.getX() &&
        frog.getY() == coin.getY())
    {
        score += 50;

            coin.setX(rand() % WIDTH);
        coin.setY(1 + rand() % (HEIGHT - 2));

        cout << "\nGet Coin! +50 Score";
        Sleep(500);
    }

}

void Game::checkCollision()
{
    for (int i = 0; i < carCount; i++)
    {
        if (frog.getX() == cars[i].getX() &&
            frog.getY() == cars[i].getY())
        {
            lives--;

                frog.setX(WIDTH / 2);
            frog.setY(HEIGHT - 1);

            cout << "\nHit By Car!";
            Sleep(1000);

            if (lives <= 0)
            {
                gameOver = true;
            }
        }
    }

}

void Game::checkWin()
{
    if (frog.getY() == 0)
    {
        score += 100;

            level++;

        frog.setX(WIDTH / 2);
        frog.setY(HEIGHT - 1);

        cout << "\nLevel Up!";
        Sleep(1000);

        if (gameSpeed > 60)
        {
            gameSpeed -= 10;
        }
    }
}

void Game::run()
{
    setup();

        while (!gameOver)
        {
            draw();

            input();

            updateTrafficLight();

            updateCars();

            checkCoin();

            checkCollision();

            checkWin();

            Sleep(gameSpeed);
        }

    system("cls");

    cout << "===== GAME OVER =====\n";
    cout << "Final Score : " << score << endl;

}
