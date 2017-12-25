#include <iostream>
#include <cstring>
#include <stdexcept>
#include "Console_UI.h"
#include "Game.h"

#include "gui/Gui.h"


int main(int argc, char** argv)
{
    //argc gibt an wie viele zusätliche Argumente eingegeben sind
    // --help           2 Argumente
    // --ui graphic     3 Argumente
    // --ui console     3 Argumente
    // bei allem anderen zusätzlichen eingaben wird nichts ausgeführt
    switch(argc)
    {

        case 2:
            {
                if(strcmp(argv[1],"--help")==0)
                {
                    std::cout << "--ui graphic" << std::endl;
                    std::cout << "--ui console" << std::endl;
                    std::cout << "--help" << std::endl;
                }
                break;
            }
        case 3:
            {
                if(strcmp(argv[2],"graphic")==0)
                {
                    Gui gui;
                    Game game(gui);
                    game.play();
                }
                else if(strcmp(argv[2],"console")==0)
                {
                    Console_UI ui;
                    Game game(ui);
                    game.play();
                }
                break;
            }
        //Standard Console
        default:
            {
                Console_UI ui;
                Game game(ui);
                game.play();
            }
    }

/*
Running it with ./test a1 b2 c3 will output

Have 4 arguments:
./test
a1
b2
c3

*/







    return 0;
}
