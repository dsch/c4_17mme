#include <iostream>
#include "GameLogic.h"
#include "ConsoleUI.h"
#include "gui/Gui.h"

using namespace std;

int main(int argc, char** argv)
{

    if (argc>2)
    {
        string option_1(argv[1]);
        string option_2(argv[2]);
        if (option_1=="--ui" && option_2=="console")
        {
            ConsoleUI ui;// instantiates ui
            GameLogic Game(ui); // initialises the game, class game has the game logic rules
            Game.PlayGame(); //starts the game
        }

        if (option_1=="--ui" && option_2=="graphic")
        {
            Gui ui;// instantiates gui
            GameLogic Game(ui); // initialises the game, class game has the game logic rules
            Game.PlayGame(); //starts the game
        }
    }

    if (argc==1)
    {
        ConsoleUI ui;// instantiates ui
        GameLogic Game(ui); // initialises the game, class game has the game logic rules
        Game.PlayGame(); //starts the game
    }

    if (argc>1)
    {
        string option_1(argv[1]);
        if (option_1=="--help")
        {
            cout << "Game Options are: Run on Console (default) or Run on Graphic UI" << endl;
            cout << "To play on Console set arguments to:    ** --ui console **   or no input!" << endl;
            cout << "To play on Graphic UI set arguments to: ** --ui graphic **" <<endl;
            cout << "For Help set arguments to:              ** --help **" << endl << endl;
        }
    }

    return 0;
}
