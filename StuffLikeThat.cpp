#include <iostream>
void clearMap(char** arrMap)
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
}

int enemies(char** arrMap)
{
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
    return enemyCount;
}

bool movePlayer(char** arrMap, int& playerX, int& playerY, int& newX, int& newY, int& keys, bool& flagMove, int& bomb)
{
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
        }
        else if (arrMap[newX][newY] == 'l') //Дверь
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
        else if (arrMap[newX][newY] == '^')
        {
            if (bomb == 1)
            {
                arrMap[playerX][playerY] = ' ';
                arrMap[newX][newY] = '@';
                playerX = newX;
                playerY = newY;
                --bomb;
                return true;
            }
            else
            {
                std::cout << "Can't move there! (Cell: '" << arrMap[newX][newY] << "')\n";
            }
        }
        else // Хочет ходить куда не может
        {
            std::cout << "Can't move there! (Cell: '" << arrMap[newX][newY] << "')\n";
        }
    }
    return false;
}