#include <iostream>
#include <fstream>
#include <string>
#include "gameFunctions.h" 
#include "level1.h" 
#include "level2.h" 
#include "moveEnemies.h"
#include <stdlib.h>

void save(std::string& level, int& sword, int& bow, int& armor, int& keys, int& magicItem1, int& magicItem2, int& qwest1, int& qwest2, int& qwest3, int& qwest4, int& kills)
{
    std::ofstream file("level.txt");
    file << level << std::endl;
    file << sword << bow << armor << keys << magicItem1 << magicItem2 << std::endl;
    file << qwest1 << qwest2 << qwest3 << qwest4 << std::endl;
    file << kills;
    file.close();
}


int main() // Основная функция
{
    std::ifstream file("level.txt");


    std::string line;
    

    getline(file, line);
    std::string strLevel = line;


    getline(file, line);
    int sword = line[0] - '0';
    int bow = line[1] - '0';
    int armor = line[2] - '0';
    int keys = line[3] - '0';
    int magicItem1 = line[4] - '0';
    int magicItem2 = line[5] - '0';


    getline(file, line);
    int qwest1 = line[0];
    int qwest2 = line[1];
    int qwest3 = line[2];
    int qwest4 = line[3];


    getline(file, line);
    int kills = atoi(line.c_str());


    file.close();


    if (strLevel == "1") 
    {
        int tmp = level1(sword, bow, armor, keys, magicItem1, magicItem2, qwest1, qwest2, qwest3, qwest4, kills);
        if (tmp == 1)
        {
            save(strLevel, sword, bow, armor, keys, magicItem1, magicItem2, qwest1, qwest2, qwest3, qwest4, kills);
        }
        if (tmp == 2)
        {
            std::string a = "2";
            int b = 0;
            save(a, sword, bow, armor, keys, magicItem1, magicItem2, b, b, b, b, kills);
        }
    }
    else if (strLevel == "2") 
    {
        level2(sword, bow, armor, keys, magicItem1, magicItem2, qwest1, qwest2, qwest3, qwest4, kills);
    }
    // else if (strLevel == "2") level3;
    // else if (strLevel == "2") level4;
    // else if (strLevel == "2") level5;
    // else if (strLevel == "2") level6;
    // else if (strLevel == "2") level7;

    
    
    return 0;
}