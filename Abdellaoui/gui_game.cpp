#include <iostream>
#include <string>
#include "gui/Gui.h"

gui_game::Console_UI()
{

    UserInterface::GridType gride;
gui.updateBoard(gride);
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

Console_UI::~Console_UI()
{
}
