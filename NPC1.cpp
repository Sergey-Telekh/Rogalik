#include <iostream>
#include <string>

void person11(int& qwest11, int& armor, int& killCount)
{
    if (qwest11 == '0')
    {
        std::cout << "Have you fallen from the sky? Well, it seems that we're not the only ones going through difficult times. Recently, our scientists have developed a superpower serum that makes people immortal. Well... They thought so. In reality, this serum gradually kills a person's brain and turns them into zombies. If you want to help us, I have something to offer you. But first, I want to make sure your intentions are pure. There's a sword in the chest opposite you. Take it and kill the seven evil zombies!\n";
        qwest11 = '1';
    }
    else if (qwest11 == '1' && killCount < 7)
    {
        std::cout << "Have you not killed those creatures yet? Are you sure you're not one of them? Hmm... Well, since you haven't killed me yet, you're not a zombie yet, but why are you refusing to fight these creatures? But if you think about it, they were once human, so maybe they can be saved? Then you're doing the right thing! But... Wait, they're currently killing millions of people, so why should we care about the lives of zombies? It seems to me that it's easier to kill them and save at least those who are still alive at this very moment. However, is there anyone else alive besides you and me? Unfortunately, we don't know, and I don't want to leave this dungeon. Who knows what awaits us above? BUT... Wait a minute... What if there is... NO, IT CAN'T BE TRUE!!! Although... Who knows what's possible in this world... But what if the authorities have managed to defeat the zombies and the upper world is safe... But I don't believe in it... In any case, if the authorities have won, sooner or later they will come for us. Or not........... However, I'm thinking about it, go kill the zombies." << std::endl;
    }
    else if (qwest11 == '1' && killCount >= 7)
    {
        std::cout << "Oh! I see you killed them, well, it seems you're on our side after all, so I'll give you an armor, now you can survive one zombie bite without any consequences. And remember! If you put one armor on top of another, nothing will happen, you'll still have 1 armor." << std::endl;
        armor++;
        qwest11 = '2';
    }
    else
    {
        std::cout << "I've already helped you as much as I could, have I been wrong about you? Show me that you haven't, help us." << std::endl;
    }
}

void person12(int& qwest22, int& keys)
{
    if (qwest22 == '0')
    {
        std::string answer = "";
        std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
        std::cout << "A? You're not going to kill me? You're not one of them? Are there any people left alive? Are you really a human? Well, don't think I trust you, but I still need to check if you're really a human. If you are, then answer my question.\n";
        std::cout << "I am an Entity whose nature compels me to always tell the truth, but my power allows me to create any object, even one that is logically impossible. You stand before me, and you must ask me a single question. What question must you ask me, so that I, by the nature of my being, incapable of lying but equally incapable of refusing to exercise my power, am forced to create and destroy the very first stone that went into the construction of your home, thereby providing you with irrefutable proof of both my truth and my omnipotence, without violating the logical coherence of this world?\n";

        while (true)
        {
            std::getline(std::cin, answer);

            if (answer == "The question you just asked." ||
                answer == "the question you just asked." ||
                answer == "Your question" ||
                answer == "your question" ||
                answer == "Your question." ||
                answer == "your question." ||
                answer == "The question you just asked" ||
                answer == "the question you just asked")
            {
                std::cout << "Well, you've outmaneuvered me, you're a real human after all, now I'm sure of you and I'm ready to give you something. This is a universal key that will open any door for you, except for the central gate, which is electronic.\n";
                keys++;
                qwest22 = '2';
                break;
            }
            else
            {
                std::cout << "Wrong! It's a pity that I don't have a weapon with me and I can't kill you, but as long as I'm alive, I'll still give you chances, because since you haven't killed me, I have reason to believe that you're human. So what's your new answer?\n";
                continue;
            }
        }
    }
    else
    {
        std::cout << "You've already answered my question, and I have nothing more to offer you.\n";
    }
}

void person13(int& qwest33, int& magicItem)
{
    if (qwest33 == '0')
    {
        std::cout << "Oh, finally a living soul! I've been trapped here for... I don't even know how long. Those creatures don't touch me for some reason. Maybe because I was one of the first test subjects? Never mind. Listen, I need your help. There's a special artifact in this complex - a 'Stabilization Core'. It looks like a glowing blue crystal the size of a fist.\n";
        std::cout << "It's very important to me. Personally. Without it, I... I can feel my mind slipping away. The serum is still in my blood, you see. The Core suppresses its effects. Please, find it and bring it to me. I beg you. I have nothing to offer you in return, except... except my eternal gratitude. And maybe the knowledge that you saved what's left of my humanity.\n";
        qwest33 = '1';
    }
    else if (qwest33 == '1' && magicItem == 0)
    {
        std::cout << "Have you found the Core yet? It should be in the main laboratory sector. Or maybe in the reactor room? Or... wait, did the guards move it to the safe zone before everything collapsed? I can't remember clearly anymore. The memories come in fragments... Sometimes I think I see its glow in the corner of my eye, but it's just another hallucination.\n";
        std::cout << "Please, hurry. Every hour without it feels like my thoughts are becoming less... mine. Sometimes I look at my hands and wonder if they're really moving, or if I'm just imagining it. Find the Core. Please.\n";
    }
    else if (qwest33 == '1' && magicItem == 1)
    {
        std::cout << "Is that... is that the Core? You found it! Give it to me! Quick!\n";
        std::cout << "Thank you... Thank you... I can feel it working. The noise in my head is fading. But...\n";
        std::cout << "You know, I lied to you. The Core doesn't suppress the serum. It amplifies it. Exponentially. In a few hours, I will become something... much worse than those zombies outside. And this crystal will give me power over all of them.\n";
        std::cout << "Why did you help me? Because I asked nicely? How wonderfully naive. Now run. While you still can.\n";
        magicItem = 0;
        qwest33 = '2';
    }
    else
    {
        std::cout << "S-s-still here? I w..w.wwarned you. The transformation has begun. Can you hea.. it? The whisp...rs in the walls? The..... c..l me t......ir k...g. LEAVE NOW, o ..u w...il.... be...c... my......\n";
        std::cout << "*His soulless body falls to the floor, as if he was too weak for this world.\n";
    }
}

void person14(int& bomb)
{
    if (bomb == 0)
    {
        std::string frase = "";
        std::cout << "You a human? If so, you must be able to talk? So, can you say something to me?";
        std::cin >> frase;
        std::cout << "O_O  YOU DID IT!!! So I'll give a bomb to you!\n";
        bomb = 1;
    }
    else
    {
        std::cout << "Zzz... ZZzzzzz...........";
    }
}
void persons1(int& playerX, int& playerY, int& qwest11, int& qwest12, int& qwest13, int& qwest14, int& armor, int& keys, int& killCount, int& magicItem, int& bomb)
{
    if ((playerX == 1 && playerY == 22) || (playerX == 2 && playerY == 21))
    {
        person11(qwest11, armor, killCount);
    }
    else if ((playerX == 6 && playerY == 15) || (playerX == 5 && playerY == 14))
    {
        person12(qwest12, keys);
    }
    else if ((playerX == 28 && playerY == 19) || (playerX == 27 && playerY == 18))
    {
        person13(qwest13, magicItem);
    }
    else if ((playerX == 8 && playerY == 50) || (playerX == 9 && playerY == 49))
    {
        person14(bomb);
    }
}