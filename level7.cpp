#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "gameFunctions.h"
#include "moveEnemies.h"
#include "chests1.h"
#include "startGame.h"
#include "StuffLikeThat.h"
#include "spavner.h"
#include "NPC1.h"

void spawn(char** arrMap, int& enemyCount)
{
    srand(time(NULL));
    if (enemyCount >= 400) return;

    for (int i = 0; i < 30; ++i)
    {
        for (int j = 0; j < 56; ++j)
        {
            if (arrMap[i][j] == '"')
            {
                bool spawnX = false;
                bool spawnY = false;
                for (int l = -3; l < 4; ++l)
                {
                    int temp = rand() % 40;
                    if (temp == 54 && i + l < 30 && i + l > 0 && !spawnX)
                    {
                        if (arrMap[i + l][j] == ' ')
                        {
                            arrMap[i + l][j] = 'D';
                            spawnX = true;
                        }
                    }
                    if (temp == 61 && j + l < 56 && j + l > 0 && !spawnY)
                    {
                        if (arrMap[i][j + l] == ' ')
                        {
                            arrMap[i][j + l] = 'D';
                            spawnY = true;
                        }
                    }
                }
            }
        }
    }
}


int level7(int& sword, int& bow, int& armor, int& keys, int& killCount)
{
    srand(time(NULL));


    // Создание всех переменных
    std::string line; // для чтения файла
    int playerX = -1, playerY = -1; // Позиция игрока
    bool flagMove = false; // Проверка, что игрок хочет двигаться, а не что-то другое
    bool flagSave = false;
    int temp = { 0 }; // Счётчик килов
    bool tempp = false; // Проверка на правильность удара


    char** arrMap = startGame("lvl7.txt", playerX, playerY);


    // Создание массива для врагов (в куче)
    const int MAX_ENEMIES = 500;
    int** enemyPositions = new int* [MAX_ENEMIES];
    for (int i = 0; i < MAX_ENEMIES; ++i)
    {
        enemyPositions[i] = new int[2];
    }

    // Выводим что на данном этапе есть
    print(arrMap);
    std::cout << std::endl;


    int i = 0;
    // Основной игровой цикл
    while (true)
    {
        int enemyCount = 0;
        ++i;

        clearMap(arrMap);

        spawn(arrMap, enemyCount);


        enemyCount = enemies(arrMap);
        temp = enemyCount;


        //Проверяем смерть
        if (isDeapth(enemyPositions, playerX, playerY, enemyCount, armor))
        {
            std::cout << "An enemy caught you! Game Over!\n";
            int roll = rand() % 3;
            if(roll == 1)
            {
                std::cout << "Видимо у этой истории не будет хорошего конца,постепенно зомби заразили всех землян. Видимо на этом конец этой планеты. Власти решили, что в зомби ещё осталась частичка человечности и пытались поймать всех зомби в загоны для дальнейшего лечения, но они не учли, насколько бычтро зомби вирус расспростроняется и в итоге все умерли. Чтож, на этом и конец этой истории.\n\n\n\n\n\n";
            }
            else if (roll == 2)
            {
                std::cout << "Перед смертью вы вы подняли глаза к небу и увидели вертолёт, из которого говорили: 'Обращение ко всем жителям Земли: эпидемия зомби была почти полностью ликвидирована, но карантин продлится ещё 3 месяца' чтож, видимо ваша смерть была не напрасна, сейчас вы вспоминаете всех тех, с кем когда-то говорили в этой лабаратории. Вам их жалко, хотя с другой стороны они же всё это начали. Хотя, все совершают ошибки, так что нельзя винить только работников во всём этом хаосе. Как бы оно ни было, вы умираете с чувством счастья, теперь вы знаете, что Земляне спаслись и наша расса не покончила с собой.\n\n\n\n\n";
            }
            else
            {
                std::cout << "Перед смертью вы слышите крит откуда-то сзади 'ДАААА, ПОЛУЧИЛОСЬ!!!!' голос кажется вам знакомым, это голос того работника, которому вы отдали ту странную жидкость, видимо он всё-таки смог синтезировать противоядие, значит оли это, что Земля не обречена на смерть? Неизвестно, а вдруг выживших слишком мало, впрочем хоть какая-то надежда перед смертью это уже хоть что-то, теперь вы умираете спокойными.\n\n\n\n\n";
            }
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
            continue;

        case('T'):
        case('t'):
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
            std::ofstream file("lvl7.txt");
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
        int a = 0;
        movePlayer(arrMap, playerX, playerY, newX, newY, keys, flagMove, a);
        

        moveEnemies(arrMap, playerX, playerY, enemyPositions);

        // Также проверяем, не стоят ли враги прямо на игроке
        if (arrMap[playerX][playerY] == 'D')
        {
            std::cout << "An enemy caught you! Game Over!\n";
            break;
        }

        enemyCount = enemies(arrMap);
        killCount += (temp - enemyCount);

        // Выводим карту и информацию
        std::cout << "Your kills: " << killCount << std::endl;
        print(arrMap);
        std::cout << std::endl;
        std::cout << "Player position: X=" << playerX << ", Y=" << playerY << std::endl;
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

    if (flagSave)
        return 1;
    return 0;
}