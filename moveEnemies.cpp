#include <iostream>
#include <fstream>
#include <string>
#include "gameFunctions.h"
#include "level1.h"


// Проверка, находится ли враг рядом с игроком
bool isDeapth(int** enemyPositions, int playerX, int playerY, int enemyCount, int& armor)
{
    for (int i = 0; i < enemyCount; ++i)
    {
        int enemyX = enemyPositions[i][0];
        int enemyY = enemyPositions[i][1];

        // Проверяем соседние клетки (вверх, вниз, влево, вправо)
        if ((abs(enemyX - playerX) == 1 && enemyY == playerY) ||  // сверху или снизу
            (abs(enemyY - playerY) == 1 && enemyX == playerX))    // слева или справа
        {
            if (armor == 1)
            {
                armor--;
                return false;
            }
            return true;
        }
    }
    return false;
}

// Функция для движения врагов
int moveEnemies(char** arrMap, int playerX, int playerY, int** enemyPositions)
{
    int enemyCount = 0;

    // Находим всех врагов на карте
    for (int i = 0; i < 30; ++i)
    {
        for (int j = 0; j < 56; ++j)
        {
            if (arrMap[i][j] == 'D')
            {
                enemyPositions[enemyCount][0] = i; // X координата
                enemyPositions[enemyCount][1] = j; // Y координата
                enemyCount++;
            }
        }
    }

    // Двигаем каждого врага
    for (int e = 0; e < enemyCount; ++e)
    {
        int enemyX = enemyPositions[e][0];
        int enemyY = enemyPositions[e][1];

        // Определяем направление к игроку
        int dx = 0, dy = 0;

        // Сначала определяем вертикальное направление
        if (enemyX > playerX)
        {
            dx = -1; // Игрок выше - идём вверх
        }
        else if (enemyX < playerX)
        {
            dx = 1; // Игрок ниже - идём вниз
        }
        // Если на одной вертикали, определяем горизонтальное
        else if (enemyY > playerY)
        {
            dy = -1; // Игрок левее - идём влево
        }
        else if (enemyY < playerY)
        {
            dy = 1; // Игрок правее - идём вправо
        }

        // Пытаемся двигаться
        bool moved = false;

        // Пробуем вертикальное движение (если нужно)
        if (dx != 0)
        {
            int newX = enemyX + dx;
            if (newX >= 0 && newX < 30)
            {
                if (arrMap[newX][enemyY] == ' ')
                {
                    // Можем двигаться по вертикали
                    arrMap[enemyX][enemyY] = ' ';
                    arrMap[newX][enemyY] = 'D';
                    moved = true;
                    // Обновляем позицию
                    enemyPositions[e][0] = newX;
                }
            }
        }

        // Если не двигались вертикально, пробуем горизонтально
        if (!moved && dy != 0)
        {
            int newY = enemyY + dy;
            if (newY >= 0 && newY < 56)
            {
                if (arrMap[enemyX][newY] == ' ')
                {
                    // Можем двигаться по горизонтали
                    arrMap[enemyX][enemyY] = ' ';
                    arrMap[enemyX][newY] = 'D';
                    moved = true;
                    // Обновляем позицию
                    enemyPositions[e][1] = newY;
                }
            }
        }
    }
    return enemyCount;
}
void bit(char** arrMap, int playerX, int playerY, int sword, int bow) // Удары
{
    std::string bit = "";
    std::cout << "What do you want to hit?\n";
    std::cin >> bit;
    if (bit == "s" || bit == "S")
    {
        if (sword == 1) // Удар мечом
        {
            std::cout << "Where do you want to hit?(Two directions) \n";
            std::cin >> bit;
            if (bit == "ww" || bit == "WW") //Вверх
            {
                arrMap[playerX - 1][playerY] = (arrMap[playerX - 1][playerY] == ' ' || arrMap[playerX - 1][playerY] == 'D' || arrMap[playerX - 1][playerY] == '|' ? '|' : arrMap[playerX - 1][playerY]);
                playerX - 2 > 0 ? arrMap[playerX - 2][playerY] = (arrMap[playerX - 2][playerY] == ' ' || arrMap[playerX - 2][playerY] == 'D' || arrMap[playerX - 2][playerY] == '|' ? '|' : arrMap[playerX - 2][playerY]) : 1;
            }
            else if (bit == "ss" || bit == "SS")// Вниз
            {
                arrMap[playerX + 1][playerY] = (arrMap[playerX + 1][playerY] == ' ' || arrMap[playerX + 1][playerY] == 'D' || arrMap[playerX + 1][playerY] == '|' ? '|' : arrMap[playerX + 1][playerY]);
                playerX + 2 < 30 ? arrMap[playerX + 2][playerY] = (arrMap[playerX + 2][playerY] == ' ' || arrMap[playerX + 2][playerY] == 'D' || arrMap[playerX + 2][playerY] == '|' ? '|' : arrMap[playerX + 2][playerY]) : 1;
            }
            else if (bit == "dd" || bit == "DD")//Вправо
            {
                arrMap[playerX][playerY + 1] = (arrMap[playerX][playerY + 1] == ' ' || arrMap[playerX][playerY + 1] == 'D' || arrMap[playerX][playerY + 1] == '-' ? '-' : arrMap[playerX][playerY + 1]);
                playerY + 2 < 56 ? arrMap[playerX][playerY + 2] = (arrMap[playerX][playerY + 2] == ' ' || arrMap[playerX][playerY + 2] == 'D' || arrMap[playerX][playerY + 2] == '-' ? '-' : arrMap[playerX][playerY + 2]) : 1;
            }
            else if (bit == "aa" || bit == "AA")//Влево
            {
                arrMap[playerX][playerY - 1] = (arrMap[playerX][playerY - 1] == ' ' || arrMap[playerX][playerY - 1] == 'D' || arrMap[playerX][playerY - 1] == '-' ? '-' : arrMap[playerX][playerY - 1]);
                playerY - 2 > 0 ? arrMap[playerX][playerY - 2] = (arrMap[playerX][playerY - 2] == ' ' || arrMap[playerX][playerY - 2] == 'D' || arrMap[playerX][playerY - 2] == '-' ? '-' : arrMap[playerX][playerY - 2]) : 1;
            }
            else if (bit == "wd" || bit == "WD" || bit == "dw" || bit == "DW") //Вправо вверх
            {
                arrMap[playerX - 1][playerY + 1] = (arrMap[playerX - 1][playerY + 1] == ' ' || arrMap[playerX - 1][playerY + 1] == 'D' ? 'Г' : arrMap[playerX - 1][playerY + 1]);
            }
            else if (bit == "ds" || bit == "DS" || bit == "sd" || bit == "SD") // Вправо вниз
            {
                arrMap[playerX + 1][playerY + 1] = (arrMap[playerX + 1][playerY + 1] == ' ' || arrMap[playerX + 1][playerY + 1] == 'D' ? 'L' : arrMap[playerX + 1][playerY + 1]);
            }
            else if (bit == "as" || bit == "AS" || bit == "sa" || bit == "SA") // Влево вниз
            {
                arrMap[playerX + 1][playerY - 1] = (arrMap[playerX + 1][playerY - 1] == ' ' || arrMap[playerX + 1][playerY - 1] == 'D' ? 'Г' : arrMap[playerX + 1][playerY - 1]);
            }
            else if (bit == "wa" || bit == "WA" || bit == "aw" || bit == "AW") // Влево вверх
            {
                arrMap[playerX - 1][playerY - 1] = (arrMap[playerX - 1][playerY - 1] == ' ' || arrMap[playerX - 1][playerY - 1] == 'D' ? 'L' : arrMap[playerX - 1][playerY - 1]);
            }
            else
            {
                std::cout << "You can't strike in that direction!\n";
            }
        }
        else
        {
            std::cout << "You don't have a sword\n";
        }
    }
    else if (bit == "b" || bit == "B")
    {
        if (bow == 1)
        {
            std::cout << "Where do you want to hit?\n";
            std::cin >> bit;
            if (bit == "w" || bit == "W") //Вверх
            {
                arrMap[playerX - 1][playerY] = (arrMap[playerX - 1][playerY] == ' ' || arrMap[playerX - 1][playerY] == 'D' || arrMap[playerX - 1][playerY] == '|' ? '|' : arrMap[playerX - 1][playerY]);
                playerX - 2 > 0 ? arrMap[playerX - 2][playerY] = (arrMap[playerX - 2][playerY] == ' ' || arrMap[playerX - 2][playerY] == 'D' || arrMap[playerX - 2][playerY] == '|' ? '|' : arrMap[playerX - 2][playerY]) : 1;
                playerX - 3 > 0 ? arrMap[playerX - 3][playerY] = (arrMap[playerX - 3][playerY] == ' ' || arrMap[playerX - 3][playerY] == 'D' || arrMap[playerX - 3][playerY] == '|' ? '|' : arrMap[playerX - 3][playerY]) : 1;
            }
            else if (bit == "s" || bit == "S")// Вниз
            {
                arrMap[playerX + 1][playerY] = (arrMap[playerX + 1][playerY] == ' ' || arrMap[playerX + 1][playerY] == 'D' || arrMap[playerX + 1][playerY] == '|' ? '|' : arrMap[playerX + 1][playerY]);
                playerX + 2 < 30 ? arrMap[playerX + 2][playerY] = (arrMap[playerX + 2][playerY] == ' ' || arrMap[playerX + 2][playerY] == 'D' || arrMap[playerX + 2][playerY] == '|' ? '|' : arrMap[playerX + 2][playerY]) : 1;
                playerX + 3 < 30 ? arrMap[playerX + 3][playerY] = (arrMap[playerX + 3][playerY] == ' ' || arrMap[playerX + 3][playerY] == 'D' || arrMap[playerX + 3][playerY] == '|' ? '|' : arrMap[playerX + 3][playerY]) : 1;
            }
            else if (bit == "d" || bit == "D")//Вправо
            {
                arrMap[playerX][playerY + 1] = (arrMap[playerX][playerY + 1] == ' ' || arrMap[playerX][playerY + 1] == 'D' || arrMap[playerX][playerY + 1] == '-' ? '-' : arrMap[playerX][playerY + 1]);
                playerY + 2 < 56 ? arrMap[playerX][playerY + 2] = (arrMap[playerX][playerY + 2] == ' ' || arrMap[playerX][playerY + 2] == 'D' || arrMap[playerX][playerY + 2] == '-' ? '-' : arrMap[playerX][playerY + 2]) : 1;
                playerY + 3 < 56 ? arrMap[playerX][playerY + 3] = (arrMap[playerX][playerY + 3] == ' ' || arrMap[playerX][playerY + 3] == 'D' || arrMap[playerX][playerY + 3] == '-' ? '-' : arrMap[playerX][playerY + 3]) : 1;
            }
            else if (bit == "a" || bit == "A")//Влево
            {
                arrMap[playerX][playerY - 1] = (arrMap[playerX][playerY - 1] == ' ' || arrMap[playerX][playerY - 1] == 'D' || arrMap[playerX][playerY - 1] == '-' ? '-' : arrMap[playerX][playerY - 1]);
                playerY - 2 > 0 ? arrMap[playerX][playerY - 2] = (arrMap[playerX][playerY - 2] == ' ' || arrMap[playerX][playerY - 2] == 'D' || arrMap[playerX][playerY - 2] == '-' ? '-' : arrMap[playerX][playerY - 2]) : 1;
                playerY - 3 > 0 ? arrMap[playerX][playerY - 3] = (arrMap[playerX][playerY - 3] == ' ' || arrMap[playerX][playerY - 3] == 'D' || arrMap[playerX][playerY - 3] == '-' ? '-' : arrMap[playerX][playerY - 3]) : 1;
            }
        }
        else
        {
            std::cout << "You don't have a bow\n";
        }
    }
    else
    {
        std::cout << "Hmmm... I don't think you can do it";
    }
}