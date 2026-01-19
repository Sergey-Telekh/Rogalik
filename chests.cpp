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
                std::cout << "Вы уже брали ключи из этого сундука, ещё больше взять вам не позволяет совесть =(\n\n";
                return;
            }
            keys = 9;
            std::cout << "Вы пытаетесь взять как можно бюольше ключей, но ваших корманов хватает только на 9 штук, теперь вы счастливый обладатель 9 ключей.\n\n";
        }
        else
        {
            std::cout << "You don't tack anything.\n\n";
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
            std::cout << "You tack an armor.\n\n";
        }
        else
        {
            std::cout << "You tack nothing)\n\n";
        }
    }
    else
    {
        std::cout << "You don't tack anything.\n\n";
    }
}
void chest51(int& bomb, int& bow)
{
    std::cout << (bow == 1 ? "Открыв сундук вы видите какую-то странную зелёную жидкость, вы уже хотите закрыть сундук и пойти дальше, но что-то не позволяет вам отвести от неё взгляд. В попытках отвернуться вы начинаете махать перед собой луком, но тут жидкость начинает пульсировать и вы чувстуете, как она затягивает ваш лук в себя, вы не в силах этому противостоять и ваш лук ломается об стенки сундука и его обломки засасываются в жидкость, после чего она начинает ярко светиться и исчезает, теперь у вас нет лука (\n":"В сундуке ничего нет\n");
    std::cout << (bomb == 0 ? "Но не всё так плохо, рядом с сундуком лежит одинокая бомбочка для ванной, не знаю как, но мне кажется она вам поможет, теперь у вас есть бомба.\n\n" : "\n");
    bow = 0;
    bomb = 1;
}
