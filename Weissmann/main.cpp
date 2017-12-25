
#include <iostream>
#include <stdexcept>
#include "UserInterface.h"
#include "UI_Console.h"
#include "GameLogik.h"
#include <stdlib.h>
#include "gui/Gui.h"

int play_game(UserInterface& UI)
{
    GameLogik game;
    bool playing = true;

    UI.updateBoard(game.getGrid());

    while(playing)
    {
        try
        {
            UserInterface::ColumnType col = UI.askPlayer(game.getCurrentPlayer()) + 1;

            game.updateGame(col);

            UI.updateBoard(game.getGrid());

            if(game.isWin(game.getGrid()))
            {
                UI.notifyWinner(game.getCurrentPlayer());
                playing = false;

                break;
            }
            else if (game.isDraw(game.getGrid()))
            {
                UI.notifyDraw();
                playing = false;
                break;
            }
            game.switchPlayer();
        }
        catch(UserInterface::Abort abortException )
        {
            std::cout << abortException.what() << std::endl;
            playing = false;
        }

        catch(int e)
        {
            std::cout<<"Der Eingegebene Wert ist ung�ltig. Bitte setzen Sie erneut"<<std::endl;
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    std::cout << argc << std::endl;
    std::cout << argv[1] << std::endl;
    std::cout << argv[2] << std::endl;

    std::string argv2 = argv[2];

    if(argv2 == "console")
    {
        UI_Console console_ui;
        return play_game(console_ui);
    }

    else if(argv2 == "graphic")
    {
        Gui gui;
        return play_game(gui);
    }


    return 0;
}

