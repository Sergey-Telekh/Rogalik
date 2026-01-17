#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include "gameFunctions.h" 
#include "level1.h" 
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "moveEnemies.h"
#include <stdlib.h>

void save(std::string& level, int& sword, int& bow, int& armor, int& keys, int& magicItem1, int& magicItem2, char& qwest1, char& qwest2, char& qwest3, char& qwest4, int& kills)
{
    std::ofstream file("level.txt");
    file << level << std::endl;
    file << sword << bow << armor << (keys >= 9 ? 9 : keys) << magicItem1 << magicItem2 << std::endl;
    file << qwest1 << qwest2 << qwest3 << qwest4 << std::endl;
    file << kills;
    file.close();
}


int main() // Основная функция
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream file("level.txt");


    std::string line;
    

    getline(file, line);
    std::string strLevel = line;


    getline(file, line);
    int sword = line[0] - '0';
    int bow = line[1] - '0';
    int armor = line[2] - '0';
    int keys = line[3] - '0';
    int magicItem1 = line[4] - '0';
    int magicItem2 = line[5] - '0';


    getline(file, line);
    char qwest1 = line[0];
    char qwest2 = line[1];
    char qwest3 = line[2];
    char qwest4 = line[3];


    getline(file, line);
    int kills = atoi(line.c_str());


    file.close();


    if (strLevel == "1") 
    {
        if (qwest1 == '0')
        {
            std::cout << "Вы - опытный пилот, выполняющий обычный рейс через спокойное небо.\n";
            std::cout << "Внезапно из командного центра поступает срочное сообщение:\n";
            std::cout << "\"Немедленно возвращайтесь на базу. Ситуация критическая.\"\n\n";

            std::cout << "Вы разворачиваетесь и начинаете обратный путь.\n";
            std::cout << "Но уже через несколько минут на горизонте появляется нечто странное -\n";
            std::cout << "громадное грозовое облако, неестественного фиолетового оттенка.\n\n";

            std::cout << "Радиосвязь прерывается. Навигационные системы отказывают одна за другой.\n";
            std::cout << "Чтобы не потерять ориентацию, вы принимаете решение:\n";
            std::cout << "спуститься ниже и попытаться обойти аномалию под ней.\n\n";

            std::cout << "В тот момент, когда вы начинаете снижение,\n";
            std::cout << "все приборы в кабине гаснут. Полная тишина.\n";
            std::cout << "Только вой ветра за бортом и нарастающая вибрация...\n\n";

            std::cout << "Самолёт больше не слушается управления.\n";
            std::cout << "Вы входите в штопор, беспомощно падая к земле.\n";
            std::cout << "Остаётся лишь один шанс - катапультирование.\n\n";

            std::cout << "Вы дёргаете за рычаг. Взрыв. Небо.\n";
            std::cout << "Тишина, прерываемая лишь свистом падения.\n";
            std::cout << "Парашют раскрывается с резким рывком.\n\n";

            std::cout << "Но что это? Ветер не ослабевает.\n";
            std::cout << "Наоборот - вас несёт куда-то в сторону,\n";
            std::cout << "к огромным заброшенным постройкам, скрытым в долине.\n\n";

            std::cout << "Вы видите гигантскую конструкцию со сломанной крышей.\n";
            std::cout << "Сквозь одну из трещин проглядывает темнота внутри.\n";
            std::cout << "Вас неудержимо затягивает прямо в эту чёрную пасть...\n\n";

            std::cout << "Последнее, что вы осознаёте -\n";
            std::cout << "свободное падение в неизвестность,\n";
            std::cout << "затем удар... и темнота.\n\n";

            std::cout << "-------------------------------\n\n";
            std::cout << "Сознание возвращается медленно.\n";
            std::cout << "Вы лежите на холодном бетоне в полной темноте.\n";
            std::cout << "Где-то сверху слышен завывающий ветер.\n";
            std::cout << "Нужно выбраться. Нужно выжить...\n\n";
            std::cout << "Для начала игры подойдите к персонажу слева от вас.\n";
            std::cout << "Введите что-нибудь для продолжения: ";
            std::string pass;
            std::cin >> pass;
            std::cout << std::endl;
            std::cout << "Для начала игры подойдите к человеку слева от вас и нажмите Т, для вывода правил нажмите R\n\n";
            std::cout << "Введите что-нибудь для продолжения: ";
            std::cin >> pass;
            std::cout << std::endl;
        }
        int tmp = level1(sword, bow, armor, keys, magicItem1, magicItem2, qwest1, qwest2, qwest3, qwest4, kills);
        if (tmp == 1)
        {
            save(strLevel, sword, bow, armor, keys, magicItem1, magicItem2, qwest1, qwest2, qwest3, qwest4, kills);
        }
        if (tmp == 2)
        {
            std::string a = "2";
            char b = '0';
            save(a, sword, bow, armor, keys, magicItem1, magicItem2, b, b, b, b, kills);
        }
    }
    else if (strLevel == "2") 
    {
        int tmp = level2(sword, bow, armor, keys, magicItem2, qwest1, qwest2, kills);
        if (tmp == 1)
        {
            save(strLevel, sword, bow, armor, keys, magicItem1, magicItem2, qwest1, qwest2, qwest3, qwest4, kills);
        }
        if (tmp == 2)
        {
            std::string a = "3";
            char b = '0';
            save(a, sword, bow, armor, keys, magicItem1, magicItem2, b, b, b, b, kills);
        }

    }
    else if (strLevel == "3")
    {
        int tmp = level3(sword, bow, armor, keys, qwest1, kills);
        if (tmp == 1)
        {
            save(strLevel, sword, bow, armor, keys, magicItem1, magicItem2, qwest1, qwest2, qwest3, qwest4, kills);
        }
        if (tmp == 2)
        {
            std::string a = "4";
            char b = '0';
            save(a, sword, bow, armor, keys, magicItem1, magicItem2, b, b, b, b, kills);
        }
    }
    else if (strLevel == "4")
    {
        int tmp = level4(sword, bow, armor, keys, qwest1, kills);
        if (tmp == 1)
        {
            save(strLevel, sword, bow, armor, keys, magicItem1, magicItem2, qwest1, qwest2, qwest3, qwest4, kills);
        }
        if (tmp == 2)
        {
            std::string a = "5";
            char b = '0';
            save(a, sword, bow, armor, keys, magicItem1, magicItem2, b, b, b, b, kills);
        }
    }
    // else if (strLevel == "2") level5;
    // else if (strLevel == "2") level6;
    // else if (strLevel == "2") level7;

    
    
    return 0;
}