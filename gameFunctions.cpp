#include <iostream>
#include "gameFunctions.h"

void printRules() // Вывести правила
{
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "=== GAME RULES ===\n\n";
    std::cout << "SYMBOLS:\n";
    std::cout << "  #  = Wall (cannot pass)\n";
    std::cout << "  @  = Player (you)\n";
    std::cout << "  l- = Door (requires key)\n";
    std::cout << "  ?  = Chest (contains loot)\n";
    std::cout << "  !  = Person (can talk to)\n";
    std::cout << " '''" << std::endl;
    std::cout << " ''' = Spawner (enemies spawn nearby)\n";
    std::cout << "  D  = Enemy (danger!)\n\n";

    std::cout << "CONTROLS:\n";
    std::cout << "  Movement: W, A, S, D\n";
    std::cout << "  Inventory: E (check what you have)\n";
    std::cout << "  Talk: T (when near a person)\n";
    std::cout << "  Chests: R (open chest when near)\n";
    std::cout << "    Chest Loot: Y (take all and close)\n";
    std::cout << "    Close Chest: U (close without taking)\n";
    std::cout << "  Attack: Q, then choose weapon:\n";
    std::cout << "    Sword (S): Enter two directions (WW, WD, DD, etc.)\n";
    std::cout << "    Bow (B): Enter one direction (W, A, S, D)\n";

    std::cout << "\nDANGERS:\n";
    std::cout << "  Enemies (D) will chase you!\n";
    std::cout << "  If an enemy catches you, you will die and lose the game!\n\n\n";
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
    std::cout << (armor == 1 ? "armor\n" : "");
    if(keys != 0)
        std::cout << keys << " keys\n";
    if (sword == 0 && bow == 0 && armor == 0 && keys == 0)
    {
        std::cout << "nothing =)\n";
    }
}