#include <iostream>
#include <cstring>
#include <stdexcept>
#include "Console_UI.h"
#include "Game.h"
#include "gui/Gui.h"


int main(int argc, char** argv)
{
    std::cout << argc << std::endl;
    //std::cout << argv[1] << std::endl;

if (argc >= 3)
{
    std::cout << argv[2] << std::endl;
    std::string argv2 = argv[2];

    if (argv2 == "console")
    {
        std::cout << "Console ist aktiviert." << std::endl;
        Console_UI ui;
        Game game(ui);
        game.play();
    }

    if (argv2 == "graphic")
    {
        std::cout << "Graphisches Interface ist aktiviert." << std::endl;
        Gui gui;
        Game game(gui);
        game.play();
    }

    if (argv2 == "help")
    {
        std::cout << "4-Gewinnt Hilfe:   Verfuegbare Input parameter:" << std::endl;
        std::cout << "--gui graphic:     Graphisches Interface wird gestartet." << std::endl;
        std::cout << "--gui console:     Konsole wird gestartet." << std::endl;
        std::cout << "--gui:             Standardm�ssig wird die Konsole gestartet." << std::endl;
        std::cout << "--gui help:        Diese Hilfe erneut anzeigen." << std::endl << std::endl;
        std::cout << "24 Stunden Support: +435455548965485" << std::endl;
    }
}

else
{
    std::cout << "Modus ohne input argument: Console ist aktiviert.";
    Console_UI ui;
    Game game(ui);
    game.play();
}
//    try   {
//        UserInterface::ColumnType column = gui.askPlayer(UserInterface::Color::RED);
//        std::cout << (int)column << std::endl;
//    }
//    catch (const UserInterface::Abort& abort)  {
//        std::cout << "aborted " << std::endl;
//    }

    return 0;
}
