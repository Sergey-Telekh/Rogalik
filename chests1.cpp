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

void chest3(int& armor, int& armorInChest3)
{
    std::cout << "In the chest:\n";
    std::cout << (armorInChest3 == 1 ? "Armor.\n" : "Nothing.\n");

    char toDo = ' ';
    std::cout << "What do you want to do? ('Y' to tack all)" << std::endl;
    std::cin >> toDo;
    if (toDo == 'Y' || toDo == 'y')
    {
        if (armorInChest3 == 1)
        {
            armor = 1;
            armorInChest3 = 0;
            std::cout << "You tack an armor.\n";
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

void chest4(int& armor, int& keys, int& armorInChest4, int& keysInChest4)
{
    std::cout << "In the chest:\n";
    std::cout << (armorInChest4 == 1 && keysInChest4 == 4 ? "Armor and 4 Keys.\n" : "Nothing.\n");

    char toDo = ' ';
    std::cout << "What do you want to do? ('Y' to tack all)" << std::endl;
    std::cin >> toDo;
    if (toDo == 'Y' || toDo == 'y')
    {
        if (armorInChest4 == 1 && keysInChest4 == 4)
        {
            armor = 1;
            keys += 4;
            armorInChest4 = 0;
            keysInChest4 = 0;
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

void chestsInLvl1(int& playerX, int& playerY, int& sword, int& keys, int& swordInChest1, int& keysInChest1, int& magicItem, int& magicItemInChest2, int& keysInChest2, int& armor, int& armorInChest3, int& keysInChest3, int& armorInChest4, int& keysInChest4)
{
    if ((playerX == 1 && playerY == 33) || (playerX == 2 && playerY == 32))
    {
        chest1(sword, keys, swordInChest1, keysInChest1);
    }
    else if ((playerX == 5 && playerY == 7) || (playerX == 6 && playerY == 6))
    {
        chest2(magicItem, keys, magicItemInChest2, keysInChest2);
    }
    else if ((playerX == 5 && playerY == 22) || (playerX == 4 && playerY == 21))
    {
        chest3(armor, armorInChest3);
    }
    else if ((playerX == 28 && playerY == 17) || (playerX == 27 && playerY == 18))
    {
        chest4(armor, keys, armorInChest4, keysInChest4);
    }
    else if ((playerX == 24 && playerY == 46) || (playerX == 25 && playerY == 47))
    {
        std::cout << "There is nothing in the chest =(" << std::endl;
    }
}