#include <iostream>
#include <cstring>
#include <stdexcept>
#include "Console_UI.h"
#include "Game.h"
#include "gui/Gui.h"


// Test Cases verwenden ist auch für Prüfung wichtig!
// Test für Gewinner-Logik schreiben
//

int main(int argc,char** argv) //startet nur alle Elemente
{

    std::cout << argc << std::endl;
    std::cout << argv[1] << std::endl;
    //std::cout << argv[2] << std::endl;

    if(argc >= 3)
    {



        std::string argv2 = argv[2];

        if(argv2 == "console")
        {
            Console_UI ui; // "instanzieren" -> erstelle eine Instanz (=ein Exemplar) von Console_UI
            // ui hat die struktur von Console_UI
            //auch wenn es nicht aktiv verwendet werden soll muss es einmal erstellt werden
            // aber es soll nur über das UerInterface angesprochen werden
            Game game(ui);  // Spiel wird erstellt
            // Klasse "Game" enthält Spielregeln
            game.play(); //Funktio: Spiel starten
            // play() hast ganzen Spielablauf

        }

        if(argv2 == "graphic")
        {
            Gui ui; // "instanzieren" -> erstelle eine Instanz (=ein Exemplar) von Console_UI
            // ui hat die struktur von Console_UI
            //auch wenn es nicht aktiv verwendet werden soll muss es einmal erstellt werden
            // aber es soll nur über das UerInterface angesprochen werden
            Game game(ui);  // Spiel wird erstellt
            // Klasse "Game" enthält Spielregeln
            game.play(); //Funktio: Spiel starten
            // play() hast ganzen Spielablauf

        }

        if(argv2 == "help")
        {
            std::cout << std::endl << "Select in the parameters console for the console application" << std::endl;
            std::cout << "or graphic for the graphic user interface" << std::endl;
        }

    }

    if(argc <= 2)
    {
        Console_UI ui; // "instanzieren" -> erstelle eine Instanz (=ein Exemplar) von Console_UI
        // ui hat die struktur von Console_UI
        //auch wenn es nicht aktiv verwendet werden soll muss es einmal erstellt werden
        // aber es soll nur über das UerInterface angesprochen werden
        Game game(ui);  // Spiel wird erstellt
        // Klasse "Game" enthält Spielregeln
        game.play(); //Funktio: Spiel starten
        // play() hast ganzen Spielablauf
    }


    // Gui gui;




    return 0;
}
