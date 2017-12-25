#include <iostream>
#include <cstring>
#include <stdexcept>
#include "Console_UI.h"
#include "Game.h"

#include "gui/Gui.h"

using namespace std;

int main(int argc, char** argv) //startet alle Elemente
{


if(argc == 1)
    {
    Console_UI ui;
    Game game(ui);
    game.play();
    }
    else if (argc == 2)
    {
    if(strcmp(argv[1], "--help") == 0)
        {
        std::cout << std::endl << "'--ui console': Startet Console" << std::endl;
        std::cout << "'--ui graphic': Startet graphisches Interface" << std::endl;

        }
    else
        {
        Console_UI ui;
        Game game(ui);
        game.play();
        }
    }
    else
    {
    if(strcmp(argv[1], "--ui") == 0)
        {
        if(strcmp(argv[2], "console") == 0)
            {
            Console_UI ui;
            Game game(ui);
            game.play();
            }
        else if(strcmp(argv[2], "graphic") == 0)
            {
            Gui ui;
            Game game(ui);
            game.play();
            }
        else
            {
            Console_UI ui;
            Game game(ui);
            game.play();
            }
        }


    }
    //Gui gui;
    //Console_UI ui;
    //Game game(ui);
    //game.play();

    return 0;
}
