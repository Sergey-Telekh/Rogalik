#include <iostream>
#include <fstream>
#include <string>
#include "gameFunctions.h" 
#include "level1.h" 
#include "moveEnemies.h"


char** startGame(std::string fileName, int& playerX, int& playerY)
{
	std::ifstream file(fileName);

    std::string line;


    // Создание карты
    char** arrMap = new char* [30];
    for (int i = 0; i < 30; ++i)
    {
        arrMap[i] = new char[56];
    }

    // Заполнение карты
    int row = 1;
    while (getline(file, line))
    {
        if (row <= 30)
        {
            for (int j = 0; j < 56; ++j)
            {
                if (j < line.length())
                    arrMap[row - 1][j] = line[j];
                else
                    arrMap[row - 1][j] = ' ';

                if (line[j] == '@') // Координаты игрока
                {
                    playerX = row - 1;
                    playerY = j;
                }
            }
        }
        ++row;
    }

    // Закрываем чтение файла
    file.close();

    return arrMap;
}
