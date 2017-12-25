#include <iostream>
#include <cstring>
#include <stdexcept>
#include "Console_UI.h"
#include "Game.h"
#include "gui/Gui.h"


Gui game_ui()
{


//UserInterface::GridType gride;

//gui.updateBoard(gride);

try
{
    UserInterface::ColumnType column =  gui.askPlayer(UserInterface::Color::GREEN);
    std::cout <<(int)column <<std::endl;

}
catch (const UserInterface::Abort& abort )
{
    std::cout <<"aborted" <<std::endl;
}
}
