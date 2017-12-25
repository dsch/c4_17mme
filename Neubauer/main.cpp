#include <iostream>
#include <stdexcept>
#include "GameLogic.h"
#include "UserInterface.h"
#include "UI.h"
#include <string.h>

#include "gui/Gui.h"

using namespace std;

int main(int argc, char** argv)
{
    switch(argc)
    {
        case 1:
            {
                UI ui;
                GameLogic Game(ui);
                Game.NewGame(UserInterface::Color::RED);
                break;
            }
        case 2:
            {
                if(strcmp(argv[1], "--help") == 0)
                {
                    cout << "Connect four" << endl;
                    cout << "Following arguments are allowed:" << endl;
                    cout << "no argument   " << "Execution with console UI" << endl;
                    cout << "--ui console  " << "Execution with console UI" << endl;
                    cout << "--ui graphic      " << "Execution with graphical UI" << endl;
                }
                else
                {
                    cout << "ERROR: INVALID INPUT PARAMETERS" << endl;
                    cout << "Use --help for further information" << endl;
                }
                break;
            }
        case 3:
            {
                if(strcmp(argv[1], "--ui") == 0)
                {
                    if(strcmp(argv[2], "console") == 0)
                    {
                        UI ui;
                        GameLogic Game(ui);
                        Game.NewGame(UserInterface::Color::RED);
                    }
                    else if(strcmp(argv[2], "graphic") == 0)
                    {
                        Gui gui;
                        GameLogic Game(gui);
                        Game.NewGame(UserInterface::Color::RED);
                    }
                }
                else
                {
                    cout << "ERROR: INVALID INPUT PARAMETERS" << endl;
                    cout << "Use --help for further information" << endl;
                }
                break;
            }
        default:
            cout << "ERROR: INVALID INPUT PARAMETERS" << endl;
            cout << "Use --help for further information" << endl;
            break;
    }

    return 0;
}
