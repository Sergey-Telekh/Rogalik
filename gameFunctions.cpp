#include <iostream>
#include "gameFunctions.h"

void printRules() // Вывести правила
{
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "=== ПРАВИЛА ИГРЫ ===\n\n";
    std::cout << "СИМВОЛЫ НА КАРТЕ:\n";
    std::cout << "  #  = Стена (нельзя пройти)\n";
    std::cout << "  @  = Игрок (вы)\n";
    std::cout << "  l- = Дверь (требуется ключ)\n";
    std::cout << "  ?  = Сундук (содержит предметы)\n";
    std::cout << "  !  = Персонаж (можно поговорить)\n";
    std::cout << "  ' = Гнездо (враги появляются рядом)\n";
    std::cout << "  D  = Враг (опасность!)\n\n";

    std::cout << "УПРАВЛЕНИЕ:\n";
    std::cout << "  Движение: W, A, S, D\n";
    std::cout << "  Инвентарь: I (посмотреть предметы)\n";
    std::cout << "  Диалог: T (рядом с персонажем)\n";
    std::cout << "  Сундук: C (открыть рядом с сундуком)\n";
    std::cout << "    Взять добычу: T (взять все и закрыть)\n";
    std::cout << "    Закрыть сундук: !T (закрыть без взятия)\n";
    std::cout << "  Атака: Q, затем выбор оружия:\n";
    std::cout << "    Меч (S): ввести два направления (WW, WD, DD и т.д.)\n";
    std::cout << "    Лук (B): ввести одно направление (W, A, S, D)\n";
    std::cout << "  Сохранение: M (сохранить игру)\n";
    std::cout << "  Выход: X (выйти без сохранения)\n";
    std::cout << "  Правила: Z (показать это меню)\n";

    std::cout << "\nОПАСНОСТИ:\n";
    std::cout << "  Враги (D) будут преследовать вас!\n";
    std::cout << "  Если враг догонит вас, вы погибнете и проиграете!\n\n\n";
}

void print(char** arrMap) // Вывести карту
{
    for (int i = 0; i < 30; ++i)
    {
        for (int j = 0; j < 56; ++j)
        {
            std::cout << arrMap[i][j];
        }
        std::cout << std::endl;
    }
}

void inventory(int& sword, int& bow, int& armor, int& keys) // Вывести инвентарь
{
    std::cout << "You have: \n";
    std::cout << (sword == 1 ? "sword\n" : "");
    std::cout << (bow == 1 ? "bow\n" : "");
    std::cout << (armor >= 1 ? "armor\n" : "");
    if(keys != 0)
        std::cout << keys << " keys\n";
    if (sword == 0 && bow == 0 && armor == 0 && keys == 0)
    {
        std::cout << "nothing =)\n";
    }
}