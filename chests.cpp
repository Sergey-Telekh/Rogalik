#include <iostream>

void chest31(int& keys)
{
        std::cout << "Отурыв сундук вы видите кучу ключей.\n";
        

        char toDo = ' ';
        std::cout << "What do you want to do? ('T' to tack all)" << std::endl;
        std::cin >> toDo;
        if (toDo == 'T' || toDo == 't')
        {
            if (keys == 8)
            {
                std::cout << "Вы уже брали ключи из этого сундука, ещё больше взять вам не позволяет совесть =(\n";
                return;
            }
            keys = 9;
            std::cout << "Вы пытаетесь взять как можно бюольше ключей, но ваших корманов хватает только на 9 штук, теперь вы счастливый обладатель 9 ключей.\n";
        }
        else
        {
            std::cout << "You don't tack anything.\n";
        }
        return;
}
void chest41(int& armor, int& armorInChest41)
{
    std::cout << "In the chest:\n";
    std::cout << (armorInChest41 == 1 ? "Armor.\n" : "Nothing.\n");

    char toDo = ' ';
    std::cout << "What do you want to do? ('Y' to tack all)" << std::endl;
    std::cin >> toDo;
    if (toDo == 'T' || toDo == 't')
    {
        if (armorInChest41 == 1)
        {
            armor += 1;
            armorInChest41 = 0;
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