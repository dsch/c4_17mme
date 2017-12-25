
#include <iostream>
#include <stdexcept>
#include "UserInterface.h"
#include "UI_Console.h"
#include "GameLogik.h"
#include <stdlib.h>
#include "gui/Gui.h"

int column = 0;

int main(int argc, char** argv)
{
    std::cout << argc << std::endl;
    std::cout << argv[1] << std::endl;
    std::cout << argv[2] << std::endl;

    std::string argv2 = argv[2];

    if(argv2 == "console")
    {
        UI_Console console_ui;
        UserInterface& UI = console_ui;
        GameLogik game;

        bool playing = true;
        console_ui.init();

        while(playing)
        {
            try
            {

                UserInterface::ColumnType col = UI.askPlayer(game.getCurrentPlayer());

                game.updateGame(col);

                UI.updateBoard(game.getGrid());

                game.switchPlayer();

                if(game.isWin(game.getGrid()))
                {
                    UI.notifyWinner(game.getCurrentPlayer());
                    playing = false;

                    break;
                }

                console_ui.currentPlayer(game.getCurrentPlayer());

                game.isDraw(game.getGrid());
            }
            catch(UserInterface::Abort abortException )
            {
                std::cout << abortException.what() << std::endl;
                playing = false;
            }

            catch(int e)
            {
                std::cout<<"Der Eingegebene Wert ist ungültig. Bitte setzen Sie erneut"<<std::endl;
            }
        }
        return 0;
    }


    else if(argv2 == "graphic")
    {
        UI_Console console_ui;
        UserInterface& UI = console_ui;
        Gui gui;
        GameLogik game;
        bool playing = true;

        while(playing)
        {
            try
                {
                    UserInterface::GridType grid;

                    UserInterface::ColumnType col = gui.askPlayer(UserInterface::Color::RED);
                    game.updateGame(col);

                    gui.updateBoard(game.getGrid());
                    game.switchPlayer();

                    if(game.isWin(game.getGrid()))
                    {
                        UI.notifyWinner(game.getCurrentPlayer());
                        playing = false;

                        break;
                    }
                     game.isDraw(game.getGrid());
                }
            catch(UserInterface::Abort abortException )
            {
                std::cout << abortException.what() << std::endl;
                playing = false;
            }

            catch(int e)
            {
                std::cout<<"Der Eingegebene Wert ist ungültig. Bitte setzen Sie erneut"<<std::endl;
            }

        }

        return 0;
    }



}

