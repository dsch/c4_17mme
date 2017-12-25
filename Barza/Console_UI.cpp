#include "Console_UI.h"
#include <iostream>
#include <string>

// implementierung der Funktionen, die in Console_UI.h vorangekündigt wurden

Console_UI::Console_UI()
{
    //ctor            case RED:       std::cout<< "Player : Red";


}

Console_UI::~Console_UI()
{
    //dtor
}

UserInterface::ColumnType Console_UI::askPlayer(Color color)
{
    char col;
    if ( color == Color::RED )    std::cout<< "Player(Red) => ";
    if ( color == Color::YELLOW ) std::cout<< "Player (Yellow) => ";

    std::cout<< "Please Choose collumn number: ";
    std::cin>>col;

    return col-49;
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

    std::cout << "|      For exit game Press 9.       | "<< "\n";

    std::cout << "-------------------------------------"<< "\n\n";

}

//wird jetzt hier im quasi main/ die cpp. von console_UI .cpp definiert implementiert
void Console_UI::notifyWinner(Color color)
{
    if ( color == Color::RED )    std::cout<< "Player(Red) => ";
    if ( color == Color::YELLOW ) std::cout<< "Player (Yellow) => ";
    std::cout<< "Der gewinner bin ich. \n";
}

void Console_UI::cls()
{
        std::cout << std::string(50, '\n');
}


