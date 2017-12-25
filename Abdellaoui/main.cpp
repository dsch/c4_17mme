#include <iostream>
#include <cstring>
#include <stdexcept>
#include "Console_UI.h"
#include "Game.h"
#include "gui/Gui.h"





/*
switch(argc)
{
case 1:
    {

       Console_UI ui;
        Game game(ui);
        gaime.play();

        break;

    }
case 2:
    {
        if(strcmp(argv[1], "--hlep")== 0)

    }
}*/
// Gui gui;
/*UserInterface::GridType gride;
gui.updateBoard(gride);
try
{
    UserInterface::ColumnType column =  gui.askPlayer(UserInterface::Color::GREEN);
    std::cout <<(int)column <<std::endl;

}
catch (const UserInterface::Abort& abort )
{
    std::cout <<"aborted" <<std::endl;
}*/


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
         std::cout << "PLEASE CHOOSE Graphic or Console,fur USE Console or Grphic ." << std::endl;
        }

    }
        if (argc<=1)
        {

        Console_UI ui;
        Game game(ui);
        game.play();
        }

}



