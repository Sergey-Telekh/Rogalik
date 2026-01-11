#include <iostream>

void chest21(int& keys, int& keysInChest21)
{
    std::cout << "In the chest:\n";
    std::cout << (keysInChest21 == 6 ? "6 keys.\n" : "Nothing.\n");

    char toDo = ' ';
    std::cout << "What do you want to do? ('Y' to tack all)" << std::endl;
    std::cin >> toDo;
    if (toDo == 'Y' || toDo == 'y')
    {
        if (keysInChest21 == 6)
        {
            keys += 6;
            keysInChest21 = 0;
            std::cout << "You tack 6 keys.\n";
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

void chest22(int& magicItem2, int& magicItemInChest22)
{
    std::cout << "In the chest:\n";
    std::cout << (magicItemInChest22 == 1 ? "a Magic item.\n" : "Nothing.\n");

    char toDo = ' ';
    std::cout << "What do you want to do? ('Y' to tack all)" << std::endl;
    std::cin >> toDo;
    if (toDo == 'Y' || toDo == 'y')
    {
        if (magicItemInChest22 == 1)
        {
            magicItem2 = 1;
            magicItemInChest22 = 0;
            std::cout << "You tack a magic item.\n";
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