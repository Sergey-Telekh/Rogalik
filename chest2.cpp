#include <iostream>

void chest21(int& keys, int& keysInChest21)
{
    std::cout << "In the chest:\n";
    std::cout << (keysInChest21 == 6 ? "6 keys.\n" : "Nothing.\n");

    char toDo = ' ';
    std::cout << "What do you want to do? ('Y' to tack all)" << std::endl;
    std::cin >> toDo;
    if (toDo == 'T' || toDo == 't')
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

void chest22(int& bomb)
{
    std::cout << "In the chest:\n";
    std::cout << "Куча бомб.";

    char toDo = ' ';
    std::cout << "What do you want to do? ('Y' to tack)" << std::endl;
    std::cin >> toDo;
    if (toDo == 'T' || toDo == 't')
    {
        if (bomb == 0)
        {
            std::cout << "You tack a bomb.\n";
            bomb = 1;
        }
        else
        {
            std::cout << "You already have a bomb, but unfortunately you don't have anywhere to put the second one(\n";
        }
    }
    else
    {
        std::cout << "You don't tack anything.\n";
    }
}