#include <iostream>

#include "Game.h"
#include "ConsoleInterface.h"

#include "gui/Gui.h"



using namespace std;

int main(int argc, char ** argv) //Anzahl der Argumente , Liste der Argumente
{
    /*std::cout << argc << std::endl;
    std::cout << argv[1] << std::endl;
    std::cout << argv[2] << std::endl;*/

    if(argc == 3)
    {
        std::string argv2 = argv[2];

        if(argv2 == "graphic")
        {
            Gui gui;
            Game game(gui);
            game.playGame();
        }
        else if(argv2 == "console")
        {
            ConsoleInterface console_ui;
            Game game(console_ui);
            game.playGame();
        }
        else if(argv2 == "help")
        {
            system("cls");

            cout<<"Options: "<<endl;
            cout<<" --ui console"<<endl;
            cout<<" --ui graphic"<<endl;
            cout<<" --ui help"<<endl;
            cout<<" "<<endl;
            cout<<"Default: "<<endl;
            cout<<" --ui console "<<endl;
        }
    }
    else
    {
        ConsoleInterface console_ui;
        Game game(console_ui);
        game.playGame();
    }

   // else

    /*try{

        UserInterface::ColumnType column = gui.askPlayer(UserInterface::Color::RED);
        std::cout<<(int)column<<std::endl;
    }

    catch(const UserInterface::Abort& abort)
    {
        std::cout <<"abborted" <<std::endl;
    }*/


    //New Config for game
    /*ConsoleInterface console_ui;
    UserInterface & ui = console_ui;        //Implizit

    Game game(ui);
    game.playGame();*/

    //Old Config only Console Interface Testing
    /*ConsoleInterface console_ui;
    UserInterface& ui = console_ui;
    UserInterface::GridType grid;

    grid[1][1] = UserInterface::Color::YELLOW; //field[Reihe][Spalte]

    ui.updateBoard(grid);

    int testVariable = ui.askPlayer(UserInterface::Color::YELLOW);

    system("cls");

    grid[2][testVariable] = UserInterface::Color::YELLOW;
    grid[5][0] = UserInterface::Color::YELLOW;*/
}
