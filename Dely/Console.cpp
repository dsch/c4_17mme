#include "Console_UI.h"
#include <iostream>

Console::Console()
{
    //ctor
}

Console::~Console()
{
    //dtor
}

UserInterface::ColumnType Console::askPlayer(Color color)
{
    unsigned int col;
    if (color == UserInterface::Color::RED)
    {
        std::cout << "Player R:  Which column? [1-7]   (To abort press 9):  ";
        std::cin>> col;
    }
    else if (color == UserInterface::Color::YELLOW)
    {
        std::cout << "Player Y:  Which column? [1-7]   (To abort press 9):  ";
        std::cin>> col;
    }
    else std::cout << "FAIL. ";


    if (col == 9 )
        {
        throw Abort();
        }

    return col;
}


/// //////////////////////////////////////////////////////////////////////////////
/// Feld: 6(rows) x 7(cols)
///        grid[row][col]

void Console::updateBoard(const GridType& grid)
{


    std::cout << std::endl << ".....Spielstand....." << std::endl;
    std::cout << "--------------------"<< "\n";
    std::cout << " 1  2  3  4  5  6  7"<< "\n";

    for(int row=0; row<=5; row++)
    {
        for(int col=1; col<=7; col++)
        {
            if (grid[row][col].isEmpty() == true)
            {
                std::cout << " - ";
            }
            else if (grid[row][col].getColor() == UserInterface::Color::RED)
            {
                std::cout << " R ";
            }
            else if (grid[row][col].getColor() == UserInterface::Color::YELLOW)
            {
                std::cout << " Y ";
            }
        } //end for 2
        std::cout << std::endl;
    } // end for 1
} // end update Board

void Console::notifyWinner(Color color)
{

    if (color == Color::RED)
    {
        std::cout << "RED is the winner! " <<std::endl;
    }
    if (color == Color::YELLOW)
    {
        std::cout << "YELLOW is the winner! " <<std::endl;
    }
}

void Console::notifyDraw() // Unentschieden
{
    std::cout << std::endl << "Unentschieden! "<< std::endl;

}
