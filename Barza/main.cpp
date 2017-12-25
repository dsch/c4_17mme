#include <iostream>
#include <cstring>
#include <stdexcept>
#include "gui/Gui.h"
#include "Console_UI.h"
#include "Game.h"


// Test Cases verwenden ist auch für Prüfung wichtig!
// Test für Gewinner-Logik schreiben
//

bool testPassed() //startet nur alle Elemente
{
    Console_UI ui;
    Game game(ui);

    bool testSuccessful = true;

    game.loadBoard("teststate.txt");
    if (!game.test('R',2,3,true))  testSuccessful=false;
    if (!game.test('R',2,4,true))  testSuccessful=false;
    if (!game.test('R',1,1,true))  testSuccessful=false;
    if (!game.test('R',0,0,false)) testSuccessful=false;
    if (!game.test('R',0,6,false)) testSuccessful=false;
    if (!game.test('R',1,2,false)) testSuccessful=false;


   if(testSuccessful) return true; else return false;
}

int select;

int main(int argc,char** argv)
{
    std::cout << argc << std::endl;

    if(argc>= 3)
    {
        std::string argv2 = argv[2];
        if(argv2=="console")
        {
            Console_UI ui;
            Game game(ui);
            if(testPassed())game.play();
        }

        if(argv2=="graphic")
        {
            Gui ui;
            Game game(ui);
            game.play();
        }

        if(argv2 =="help")
        {
         std::cout << "Please choose CONSOLE or GRAPHIC for graphic user interface." << std::endl;
        }

    }
        if (argc<=1)
        {

        Console_UI ui;
        Game game(ui);
        if(testPassed())game.play();
        }

}

