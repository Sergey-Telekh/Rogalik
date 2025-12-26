#include <iostream>
#include "chests1.h"


void chest1(int& sword, int& keys, int& swordInChest1, int& keysInChest1)
{
    std::cout << "In the chest:\n";
    std::cout << (swordInChest1 == 1 && keysInChest1 == 1 ? "Sword and a Key.\n" : "Nothing.\n");

    char toDo = ' ';
    std::cout << "What do you want to do? ('Y' to tack all)" << std::endl;
    std::cin >> toDo;
    if (toDo == 'Y' || toDo == 'y')
    {
        if (swordInChest1 == 1 && keysInChest1 == 1)
        {
            sword = 1;
            keys += 1;
            swordInChest1 = 0;
            keysInChest1 = 0;
            std::cout << "You tack a sword and a key.\n";
        }
        else
        {
            std::cout << "You tack nothing)\n";
        }
    }
    else
    {
        std::cout << "You don't tack anything.\n";
    }
}

void chest2(int& magicItem, int& keys, int& magicItemInChest2, int& keysInChest2)
{
    std::cout << "In the chest:\n";
    std::cout << (magicItemInChest2 == 1 && keysInChest2 == 2 ? "Magic item and 2 Keys.\n" : "Nothing.\n");

    char toDo = ' ';
    std::cout << "What do you want to do? ('Y' to tack all)" << std::endl;
    std::cin >> toDo;
    if (toDo == 'Y' || toDo == 'y')
    {
        if (magicItemInChest2 == 1 && keysInChest2 == 2)
        {
            magicItem = 1;
            keys += 2;
            magicItemInChest2 = 0;
            keysInChest2 = 0;
            std::cout << "You tack a magic item and 2 keys.\n";
        }
        else
        {
            std::cout << "You tack nothing)\n";
        }
    }
    else
    {
        std::cout << "You don't tack anything.\n";
    }
}

void chest3(int& armor, int& keys, int& armorInChest3, int& keysInChest3)
{
    std::cout << "In the chest:\n";
    std::cout << (armorInChest3 == 1 && keysInChest3 == 1 ? "Armor and a Key.\n" : "Nothing.\n");

    char toDo = ' ';
    std::cout << "What do you want to do? ('Y' to tack all)" << std::endl;
    std::cin >> toDo;
    if (toDo == 'Y' || toDo == 'y')
    {
        if (armorInChest3 == 1 && keysInChest3 == 1)
        {
            armor += 1;
            keys += 1;
            armorInChest3 = 0;
            keysInChest3 = 0;
            std::cout << "You tack an armor and a key.\n";
        }
        else
        {
            std::cout << "You tack nothing)\n";
        }
    }
    else
    {
        std::cout << "You don't tack anything.\n";
    }
}