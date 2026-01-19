#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>
#include "gameFunctions.h"
#include "moveEnemies.h"
#include "chests.h"
#include "startGame.h"
#include "StuffLikeThat.h"
#include "spavner.h"
#include "NPCs.h"


int level6(int& sword, int& bow, int& armor, int& keys, char& qwest61, char& qwest62,int& killCount)
{

    // Создание всех переменных
    std::string line; // для чтения файла
    int playerX = -1, playerY = -1; // Позиция игрока
    bool flagMove = false; // Проверка, что игрок хочет двигаться, а не что-то другое
    bool flagWin = false;
    bool flagSave = false;
    int flagTalk = 0;
    bool tempp = false; // Проверка на правильность удара
    int temp = 0; // for killCount
    int bomb = 0;
    int killCountQwest = 0;
    

    char** arrMap = startGame("lvl6.txt", playerX, playerY);


    // Создание массива для врагов (в куче)
    const int MAX_ENEMIES = 80;
    int** enemyPositions = new int* [MAX_ENEMIES];
    for (int i = 0; i < MAX_ENEMIES; ++i)
    {
        enemyPositions[i] = new int[2];
    }

    // Выводим что на данном этапе есть
    print(arrMap);
    std::cout << std::endl;

    // Позиция игрока(Потом убрать)
    std::cout << "Player position: X=" << playerX << ", Y=" << playerY << std::endl;


    int i = 0;
    // Основной игровой цикл
    while (true)
    {
        int enemyCount = 0;
        ++i;

        clearMap(arrMap);

        if (i > 21) spavner(arrMap, enemyCount);


        enemyCount = enemies(arrMap);
        temp = enemyCount;


        //Проверяем смерть
        if (isDeapth(enemyPositions, playerX, playerY, enemyCount, armor))
        {
            std::cout << "An enemy caught you! Game Over!\n";
            break;
        }



        // Получение хода от игрока
        char move = ' ';
        std::cout << "Enter move (W/A/S/D/I/Q/R/T/S/X, or 'M' to save): ";
        std::cin >> move;
        std::cout << std::endl;

        //Выход без сохранения
        if (move == 'X' || move == 'x')
        {
            std::cout << "Game over!\n";
            break;
        }

        int newX = playerX;
        int newY = playerY;
        flagMove = false;

        // WDSA - ходьба
        // E - инвентарь
        switch (move)
        {
        case('W'):
        case('w'):
            // ВВЕРХ - уменьшаем X
            newX = playerX - 1;
            flagMove = true;
            break;

        case('S'):
        case('s'):
            // ВНИЗ - увеличиваем X
            newX = playerX + 1;
            flagMove = true;
            break;

        case('A'):
        case('a'):
            // ВЛЕВО - уменьшаем Y
            newY = playerY - 1;
            flagMove = true;
            break;

        case('D'):
        case('d'):
            // ВПРАВО - увеличиваем Y
            newY = playerY + 1;
            flagMove = true;
            break;

        case('I'):
        case('i'):
            inventory(sword, bow, armor, keys);
            continue; // Пропускаем перерисовку карты

        case('Q'):
        case('q'):
            tempp = bit(arrMap, playerX, playerY, sword, bow);
            if (tempp)
                break;
            else
                continue;

        case('R'):
        case('r'):
            printRules();
            continue;

        case('C'):
        case('c'):
            if ((playerX == 16 && playerY == 43) || (playerX == 15 && playerY == 44))
                if (bomb == 0)
                {
                    std::cout << "В сундуке одиноко лежит бомба и в углу свил свою паутину паучок. Вы не раздумывая взяли эту бомбу и захлопнули сундук, даже не подумав как от этого страшно пауку.\n";
                    bomb = 1;
                }
                else
                {
                    std::cout << "В сундуке неподвижно на паутине сидит паук и не подаёт признаков жизни, видимо в прошлый раз вы слишком сильно хлопнули крышкой сундука, от чего паук и не выжил, теперь живите с этим, что вы убили невиновного паука.\nПаук начинает сниться вам в кашмарах, один раз вы так испугались, что аж сломали броню на себе.\n";
                    std::ifstream file("spider.txt");
                    std::string line;
                    while (getline(file, line)) std::cout << line << std::endl;
                    file.close();
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    print(arrMap);
                }
            else if ((playerX == 8 && playerY == 10) || (playerX == 7 && playerY == 11))
            {
                if(bow == 0)
                {
                    std::cout << "В сундуке одиноко лежит лук, как удачно, что вы зашли сюда, а то так могли бы и не найти ничего. Но теперь надо с ним быть аккуратнее, чтобы не потерять его.\n\n";
                }
                else
                {
                    std::cout << "В сундуке пусто.\n\n";
                }
            }
            continue;

        case('T'):
        case('t'):
            if (playerX == 28 && playerY == 2)
            {
                person61(qwest61, keys);
            }
            else if (((playerX == 22 && playerY == 39) || (playerX == 23 && playerY == 40)) && flagTalk == 0)
            {
                std::cout << "Вы видите спящее тело, пытаясь его разбудить вы понимаете, что этот человек уже мёртв, а на его шее укус от зомби, вам стоит убираться отсюда.\n\n";
                flagTalk = i;
            }
            continue;


        case('M'):
        case('m'):
            flagSave = true;
            break;

        default:
            std::cout << "Unknown command. Try again.\n";
            continue;
        }

        if (flagSave)
        {
            std::ofstream file("lvl6.txt");
            for (int i = 0; i < 30; ++i)
            {
                for (int j = 0; j < 56; ++j)
                {
                    file << arrMap[i][j];
                }
                file << std::endl;
            }
            file.close();
            break;
        }

        // Проверяем, можно ли сделать ход и хочет ли игрок ходить
        if (movePlayer(arrMap, playerX, playerY, newX, newY, keys, flagMove, bomb))
        {
            flagWin = true;
            break;
        }

        i > 10 ? moveEnemies(arrMap, playerX, playerY, enemyPositions) : 1;

        // Также проверяем, не стоят ли враги прямо на игроке
        if (arrMap[playerX][playerY] == 'D')
        {
            std::cout << "An enemy caught you! Game Over!\n";
            break;
        }

        if (flagTalk != 0 && i - flagTalk == 10)
        {
            arrMap[22][40] = 'D';
        }

        enemyCount = enemies(arrMap);
        killCount += (temp - enemyCount);

        // Выводим карту и информацию
        std::cout << "Your kills: " << killCount << std::endl;
        print(arrMap);
        std::cout << std::endl;
    }


    // Освобождение памяти карты
    for (int i = 0; i < 30; ++i)
    {
        delete[] arrMap[i];
    }
    delete[] arrMap;

    // Освобождение памяти массива врагов
    for (int i = 0; i < MAX_ENEMIES; ++i)
    {
        delete[] enemyPositions[i];
    }
    delete[] enemyPositions;

    if (flagWin)
        return 2;
    if (flagSave)
        return 1;
    return 0;
}