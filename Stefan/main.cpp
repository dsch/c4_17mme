#include <iostream>
#include <cstring>
#include <stdexcept>
#include "Console_UI.h"
#include "Game.h"
#include "gui/Gui.h"

// Test Cases verwenden ist auch für Prüfung wichtig!
// Test für Gewinner-Logik schreiben
//
//  int argc, char** argv
int main(int argc, char** argv) //startet nur alle Elemente
{
    std::cout << argc << std::endl;
//    std::cout << argv[1] << std::endl;
//    std::cout << argv[2]  << std::endl;
//
//

//    std::cout << "Bitte waehle das Designe aus" << std::endl;
//    cin

//    UserInterface::GridType SpielFeld ;
//    gui.updateBoard(SpielFeld);

    if(argc >= 3)
    {
    std::string argv2 = argv[2];
    if(argv2 == "graphic")
       {
        Gui gui;
        Game game(gui);
        game.play();
       }
    if(argv2 == "console")
       {
        Console_UI ui;
        Game game(ui);
        game.play();
       }

    if(argv2 == "help")
       {
            std::cout << "Hilfe ueber Programm-Arguments" << std::endl;
            std::cout << "Eingabe: --gui console  fuer normale Konsole " << std::endl;
            std::cout << "Eingabe: --gui graphic  fuer graphische Visualisierung " << std::endl;
            std::cout << "Eingabe: --gui help fuer Behilfbeschreibung:" << std::endl;
       }
    }
    if(argc == 2)
    {
        Console_UI ui;
        Game game(ui);
        game.play();
    }
    return 0;
}
