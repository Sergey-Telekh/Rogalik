#include <iostream>
#include <fstream>
#include <string>
#include "gameFunctions.h" 
#include "level1.h" 
#include "moveEnemies.h"


void person11(int& qwest11, int& armor)
{
    if (qwest11 == 0)
    {
        std::cout << "Did you just fall from the sky? Well, it seems we're not the only ones having a hard time. If you want to help us, I need to give you something. But first, I want to make sure your intentions are pure. There's a bow in the chest across from you. Take it and kill these seven evil zombies!\n";
        qwest11 = 1;
    }
    
}

int main() // Основная функция
{



    level1();
    

    return 0;
}