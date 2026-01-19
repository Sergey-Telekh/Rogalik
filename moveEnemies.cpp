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
        if (i > 50) continue;
        int enemyX = enemyPositions[i][0];
        int enemyY = enemyPositions[i][1];

        // Проверяем соседние клетки (вверх, вниз, влево, вправо)
        if ((abs(enemyX - playerX) == 1 && enemyY == playerY) ||  // сверху или снизу
            (abs(enemyY - playerY) == 1 && enemyX == playerX))    // слева или справа
        {
            if (armor >= 1)
            {
                armor--;
                std::cout << "Зомби настиг вас, но не всё так плохо, у вас была броня, жалко она не уцелела(\n";
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

        bool moved = false;

        // Определяем направление к игроку
        int targetX = 0, targetY = 0;

        if (enemyX > playerX) targetX = -1; // Игрок выше - идём вверх
        else if (enemyX < playerX) targetX = 1; // Игрок ниже - идём вниз

        if (enemyY > playerY) targetY = -1; // Игрок левее - идём влево
        else if (enemyY < playerY) targetY = 1; // Игрок правее - идём вправо

        // Пробуем 4 направления в порядке приоритета:
        // 1. Вертикальное направление к игроку (если нужно)
        // 2. Горизонтальное направление к игроку (если нужно)
        // 3. Альтернативное вертикальное (если вертикальное заблокировано)
        // 4. Альтернативное горизонтальное (если горизонтальное заблокировано)

        // 1. Пробуем вертикальное направление к игроку
        if (targetX != 0)
        {
            int newX = enemyX + targetX;
            if (newX >= 0 && newX < 30 && arrMap[newX][enemyY] == ' ')
            {
                arrMap[enemyX][enemyY] = ' ';
                arrMap[newX][enemyY] = 'D';
                enemyPositions[e][0] = newX;
                moved = true;
            }
        }

        // 2. Если не вышло по вертикали, пробуем горизонтальное направление к игроку
        if (!moved && targetY != 0)
        {
            int newY = enemyY + targetY;
            if (newY >= 0 && newY < 56 && arrMap[enemyX][newY] == ' ')
            {
                arrMap[enemyX][enemyY] = ' ';
                arrMap[enemyX][newY] = 'D';
                enemyPositions[e][1] = newY;
                moved = true;
            }
        }

        // 3. Если не вышло ни то, ни другое, но нужно двигаться по вертикали
        // (игрок выше или ниже), пробуем обходной путь по горизонтали
        if (!moved && targetX != 0 && targetY == 0)
        {
            // Игрок прямо сверху или снизу, но путь вертикально заблокирован
            // Пробуем пойти влево или вправо (в любую свободную сторону)
            if (enemyY + 1 < 56 && arrMap[enemyX][enemyY + 1] == ' ')
            {
                // Вправо
                arrMap[enemyX][enemyY] = ' ';
                arrMap[enemyX][enemyY + 1] = 'D';
                enemyPositions[e][1] = enemyY + 1;
                moved = true;
            }
            else if (enemyY - 1 >= 0 && arrMap[enemyX][enemyY - 1] == ' ')
            {
                // Влево
                arrMap[enemyX][enemyY] = ' ';
                arrMap[enemyX][enemyY - 1] = 'D';
                enemyPositions[e][1] = enemyY - 1;
                moved = true;
            }
        }

        // 4. Если не вышло, но нужно двигаться по горизонтали
        // (игрок слева или справа), пробуем обходной путь по вертикали
        if (!moved && targetY != 0 && targetX == 0)
        {
            // Игрок прямо слева или справа, но путь горизонтально заблокирован
            // Пробуем пойти вверх или вниз (в любую свободную сторону)
            if (enemyX + 1 < 30 && arrMap[enemyX + 1][enemyY] == ' ')
            {
                // Вниз
                arrMap[enemyX][enemyY] = ' ';
                arrMap[enemyX + 1][enemyY] = 'D';
                enemyPositions[e][0] = enemyX + 1;
                moved = true;
            }
            else if (enemyX - 1 >= 0 && arrMap[enemyX - 1][enemyY] == ' ')
            {
                // Вверх
                arrMap[enemyX][enemyY] = ' ';
                arrMap[enemyX - 1][enemyY] = 'D';
                enemyPositions[e][0] = enemyX - 1;
                moved = true;
            }
        }
    }
    return enemyCount;
}

// Функция удара
bool bit(char** arrMap, int playerX, int playerY, int sword, int bow) // Удары
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
                return false;
            }
        }
        else
        {
            std::cout << "You don't have a sword\n";
            return false;
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
            else
            {
                std::cout << "You can't strike in that direction!\n";
                return false;
            }
        }
        else
        {
            std::cout << "You don't have a bow\n";
            return false;
        }
    }
    else
    {
        std::cout << "Hmmm... I don't think you can do it";
        return false;
    }
    return true;
}