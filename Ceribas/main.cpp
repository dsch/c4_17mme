#include <iostream>
#include <cstring>
#include <stdexcept>
#include "Console_UI.h"
#include "Game.h"

#include "gui/Gui.h"

bool testPassed()
{
    Console_UI ui;
    Game game(ui);

    bool testSuccessful = true;

    game.loadBoard("teststate.txt"); //Extern ein Muster in die Software reinladen zum TESTEN.
    if (!game.test('R',2,3,true))  testSuccessful=false;
    if (!game.test('R',2,4,true))  testSuccessful=false;
    if (!game.test('R',1,1,true))  testSuccessful=false;
    if (!game.test('R',0,0,false)) testSuccessful=false;
    if (!game.test('R',0,6,false)) testSuccessful=false;
    if (!game.test('R',1,2,false)) testSuccessful=false;

    if(testSuccessful) return true; else return false;
}

int main(int argc,char** argv)
{
    std::cout << argc << std::endl;
   // std::cout << argv[1] << std::endl;

    if(argc>= 3)
    {
        std::string argv2 = argv[2];
        if(argv2=="console")
        {
            Console_UI ui;
            Game game(ui);
            game.play();
        }

        if(argv2=="graphic")
        {
            Gui ui;
            Game game(ui);
            game.play();
        }

        if(argv2 =="help")
        {
         std::cout << "Bitte console oder graphic auswaehlen, fuer Konsolen Anwendung oder graphische Interface." << std::endl;
        }

    }
        if (argc<=1)
        {

        Console_UI ui;
        Game game(ui);
        game.play();
        }

}
