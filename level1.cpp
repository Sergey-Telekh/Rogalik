#include <iostream>
#include <fstream>
#include <string>
#include "gameFunctions.h"
#include "level1.h"
#include "moveEnemies.h"
#include "chests1.h"



void person11(int& qwest11, int& armor)
{
    if (qwest11 == 0)
    {
        std::cout << "Did you just fall from the sky? Well, it seems we're not the only ones having a hard time. If you want to help us, I need to give you something. But first, I want to make sure your intentions are pure. There's a bow in the chest across from you. Take it and kill these seven evil zombies!\n";
        qwest11 = 1;
    }

}



void level1()
{
    // Открытие файла
    std::ifstream file("lvl1.txt");

    // Создание всех переменных
    std::string line; // для чтения файла
    int sword = 0, bow = 0, armor = 0, keys = 0, magicItem = { 0 }; // Для инвенторя
    int playerX = -1, playerY = -1; // Позиция игрока
    bool flagMove = false; // Проверка, что игрок хочет двигаться, а не что-то другое
    int qwest11 = 0, qwest12 = 0, qwest13 = 0, qwest14 = 0; // Квесты на первой карте
    int killCount = { 0 }, temp = { 0 }; // Счётчик килов
    int swordInChest1 = 1, keysInChest1 = 1, magicItemInChest2 = 1, keysInChest2 = 2, keysInChest3 = 1, armorInChest3 = 1; // Заполнение сундуков

    // Создание карты
    char** arrMap = new char* [30];
    for (int i = 0; i < 30; ++i)
    {
        arrMap[i] = new char[56];
    }

    // Создание массива для врагов (в куче)
    const int MAX_ENEMIES = 50;
    int** enemyPositions = new int* [MAX_ENEMIES];
    for (int i = 0; i < MAX_ENEMIES; ++i)
    {
        enemyPositions[i] = new int[2];
    }

    // Заполнение карты
    int row = 0;
    while (getline(file, line))
    {
        if (row == 0)
        {
            row++;
            continue;
        }
        if (row <= 30)
        {
            for (int j = 0; j < 56; ++j)
            {
                if (j < line.length())
                    arrMap[row - 1][j] = line[j];
                else
                    arrMap[row - 1][j] = ' ';

                if (line[j] == '@') // Координаты игрока - исправлено!
                {
                    playerX = row - 1;
                    playerY = j;
                }
                if (line[j] == '?')
                {
                    std::cout << row - 1 << " ";
                    std::cout << j << std::endl;
                }
            }
        }
        else if (row == 31) // Инвентарь
        {
            if (line.length() >= 4)
            {
                if (line[0] == '1') sword = 1;
                if (line[1] == '1') bow = 1;
                if (line[2] == '1') armor = 1;
                if (line[3] >= '0' && line[3] <= '9')
                    keys = line[3] - '0';
                if (line[4] == '1') magicItem = 1;
            }
        }
        else if (row == 32) // Квесты
        {
            if (line.length() >= 4)
            {
                if (line[0] == '2') qwest11 = 2;
                if (line[1] == '2') qwest12 = 2;
                if (line[2] == '2') qwest13 = 2;
                if (line[3] == '2') qwest14 = 2;
            }
        }

        ++row;
    }

    // Закрываем чтение файла
    file.close();

    // Выводим что на данном этапе есть
    inventory(sword, bow, armor, keys);
    printRules();
    print(arrMap);
    std::cout << std::endl;

    // Позиция игрока(Потом убрать)
    std::cout << "Player position: X=" << playerX << ", Y=" << playerY << std::endl;

    // Основной игровой цикл
    while (true)
    {
        for (int i = 0; i < 30; ++i)
        {
            for (int j = 0; j < 56; ++j)
            {
                if (arrMap[i][j] == '|' || arrMap[i][j] == '-' || arrMap[i][j] == 'L' || arrMap[i][j] == 'Г')
                {
                    arrMap[i][j] = ' ';
                }
            }
        } // Удаляем следы от ударов // Удаление остатков после удара

        int enemyCount = { 0 };
        // Подсчёт врагов
        for (int i = 0; i < 30; ++i)
        {
            for (int j = 0; j < 56; ++j)
            {
                if (arrMap[i][j] == 'D')
                {
                    enemyCount++;
                }
            }
        }  // Подсчёт врагов
        // счётчик киллов
        if (temp != 0)
        {
            killCount += (temp - enemyCount);
        }
        temp = enemyCount;
        //Проверяем смерть
        if (isDeapth(enemyPositions, playerX, playerY, enemyCount, armor))
        {
            std::cout << "An enemy caught you! Game Over!\n";
            break;
        }



        // Получение хода от игрока
        char move = ' ';
        std::cout << "Enter move (W/A/S/D/E/Q/R/T, or 'X' to exit): ";
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

        case('E'):
        case('e'):
            inventory(sword, bow, armor, keys);
            continue; // Пропускаем перерисовку карты

        case('Q'):
        case('q'):
            bit(arrMap, playerX, playerY, sword, bow);
            break;

        case('Z'):
        case('z'):
            printRules();
            continue;

        case('R'):
        case('r'):
            if ((playerX == 1 && playerY == 33) || (playerX == 2 && playerY == 32))
            {
                chest1(sword, keys, swordInChest1, keysInChest1);
            }
            else if ((playerX == 5 && playerY == 7) || (playerX == 6 && playerY == 6))
            {
                chest2(magicItem, keys, magicItemInChest2, keysInChest2);
            }
            else if ((playerX == 5 && playerY == 22) || (playerX == 6 && playerY == 21))
            {
                chest3(armor, keys, armorInChest3, keysInChest3);
            }
            continue;

        default:
            std::cout << "Unknown command. Try again.\n";
            continue;
        }

        // Проверяем, можно ли сделать ход и хочет ли игрок ходить
        if (newX >= 0 && newX < 30 && newY >= 0 && newY < 56 && flagMove == true)
        {
            if (arrMap[newX][newY] == ' ' || arrMap[newX][newY] == '|' || arrMap[newX][newY] == '-') // Можно идти только на пустую клетку
            {
                // Перемещаем игрока
                arrMap[playerX][playerY] = ' ';
                arrMap[newX][newY] = '@';
                playerX = newX;
                playerY = newY;
            }
            else if (arrMap[newX][newY] == '?') //сундук
            {
                std::cout << "You found a chest! Press 'R' to open it.\n";
            }
            else if (arrMap[newX][newY] == '!') //человек
            {
                std::cout << "You see a person! Press 'T' to talk.\n";
            }
            else if (arrMap[newX][newY] == 'D') // ВРАГ - СМЕРТЬ
            {
                std::cout << "You walked into an enemy! Game Over!\n";
                break;
            }
            else if (arrMap[newX][newY] == 'l' || arrMap[newX][newY] == '_') //Дверь
            {
                if (keys > 0) // Игрок имеет ключи 
                {
                    arrMap[playerX][playerY] = ' ';
                    arrMap[newX][newY] = '@';
                    playerX = newX;
                    playerY = newY;
                    --keys;
                }
                else // ключей нет
                {
                    std::cout << "You don't have keys( \n";
                }
            }
            else // Хочет ходить куда не может
            {
                std::cout << "Can't move there! (Cell: '" << arrMap[newX][newY] << "')\n";
            }
        }

        moveEnemies(arrMap, playerX, playerY, enemyPositions);

        // Также проверяем, не стоят ли враги прямо на игроке
        if (arrMap[playerX][playerY] == 'D')
        {
            std::cout << "An enemy caught you! Game Over!\n";
            break;
        }

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

    return;
}