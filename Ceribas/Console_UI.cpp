#include "Console_UI.h"
#include <iostream>
#include <string>

Console_UI::Console_UI()
{
    //nicht notwendig.
}

Console_UI::~Console_UI()
{
    //nicht notwendig.
}

UserInterface::ColumnType Console_UI::askPlayer(Color color)
{
    char col;
    if ( color == Color::RED )    std::cout<< "Spieler [RED]  ";
    if ( color == Color::YELLOW ) std::cout<< "Spieler [YELLOW]  ";

    std::cout<< "in welche Spalte moechten Sie spielen? ";
    std::cin>>col;

    return col-48;
}

void Console_UI::updateBoard(const GridType& grid)
{
    char color;
    Color cellColor;
    cls();
    std::cout << "-------------------------------------"<< "\n";
    std::cout << "| 1    2    3    4    5    6     7  |"<< "\n";
    for(char r=0; r<6; r++) {

       std::cout << "-------------------------------------"<< "\n";
       for(char c=0; c<7; c++)
        {
            if(grid[r][c].isEmpty()) color=' ';
            else
            {
                cellColor= grid[r][c].getColor();
                if (cellColor == UserInterface::Color::RED )   color='R';
                if (cellColor == UserInterface::Color::YELLOW )   color='Y';
            }


            std::cout   << "| " << " " << color << " ";
        }
       std::cout << " | "<< "\n";
    }
    std::cout << "-------------------------------------"<< "\n";

    std::cout << "|      For exit game Press 0.       | "<< "\n";

    std::cout << "-------------------------------------"<< "\n\n";
}

void Console_UI::notifyWinner(Color color)
{
    if ( color == Color::RED )    std::cout<< "Spieler [RED]  ";
    if ( color == Color::YELLOW ) std::cout<< "Spieler [YELLOW]  ";
    std::cout<< "GRATULATION Sie haben gewonnen. \n";
}

void Console_UI::cls()
{
        std::cout << std::string(50, '\n');
}


