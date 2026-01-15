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

void chest22(int& bomb, int& keys)
{
    std::cout << "In the chest:\n";
    std::cout << "Куча бомб и рядом немного ключей";

    char toDo = ' ';
    std::cout << "What do you want to do? ('Y' to tack)" << std::endl;
    std::cin >> toDo;
    if (toDo == 'T' || toDo == 't')
    {
        if (bomb == 0)
        {
            std::cout << "Первым делом ты берёшь бомбу, после чего стараетешься взять как можно больше ключей, но у тебя не получается положить в карман больше 6, теперь у вас 6 ключей.\n";
            bomb = 1;
            keys = 6;
        }
        else
        {
            std::cout << "Ты уже взял из этого сундука всё, что мог, к сожалению тееперь тебе придётся оставить этот сундук в покое.\n";
        }
    }
    else
    {
        std::cout << "You don't tack anything.\n";
    }
}