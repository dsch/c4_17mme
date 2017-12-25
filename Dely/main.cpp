#include <iostream>
#include <cstring>
#include <stdexcept>
#include "Console_UI.h"
#include "Spiel.h"
#include "gui/Gui.h"


int main(int argc, char** argv)
//int main()
{

if (argc >=3)
{


    std::string argv2 = argv[2];

    //std::cout << argc << std::endl;
    //std::cout << argv[1] << std::endl;
    //std::cout << argv[2] << std::endl;


    if (argv2 == "console")
    {
        std::cout << "Console wird aktiviert" << std::endl;
        Console ui;
        Spiel spiel(ui);  // Spiel wird erstellt
        spiel.play(); //Funktion: Spiel starten

    }
    if (argv2 == "graphic")
    {
        std::cout << "Graphic wird aktiviert" << std::endl;
        Gui gui;
        Spiel spiel(gui);  // Spiel wird erstellt
        spiel.play(); //Funktion: Spiel starten


        UserInterface::GridType grid;
        gui.updateBoard(grid);
        gui.askPlayer(UserInterface::Color::RED);
    }
      if (argv2 == "help")
    {
        std::cout << "HILFE" << std::endl;
        std::cout << "--gui graphic: Graphisches Interface wird gestartet" << std::endl;
        std::cout << "--gui console: Console wird gestartet" << std::endl;
        std::cout << "--gui: Standardmeassig wird die Console wird gestartet" << std::endl;
        std::cout << "--gui help: Hilfe wird nocheinmal angezeigt" << std::endl;

    }
}
else
{
    Console ui;
    Spiel spiel(ui);  // Spiel wird erstellt
    spiel.play(); //Funktion: Spiel starten
    std::cout << "Console wird aktiviert" << std::endl;
}
    return 0;
}
