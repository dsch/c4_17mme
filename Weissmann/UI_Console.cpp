#include<iostream>
#include "UI_Console.h"
#include <string>

UI_Console::UI_Console()
{
    this->init();
}
UI_Console::~UI_Console()
{
}


UI_Console::ColumnType UI_Console::askPlayer(Color color)
{
        currentPlayer(color);
        std::cout << "\n\r          Bitte setzen!       " << std::endl;
        int readValue=0;

        std::string input;

        std::cin >> input;

        if(input.size() > 1)
        {
            throw 2;
        }

        ColumnType ct = input[0];

        std::cout << "\n" << std::endl;
        if(ct == 'q' || ct == 'Q')
        {
          Abort except;
          throw except;
        }

        if(ct >'0' && ct < '8')
        {
            readValue = ct - 48;
        }
        else
        {
            throw 2;
        }

        return readValue;
}

void UI_Console::updateBoard(const GridType& grid)
{
    int line = grid.size();
    int column = grid[0].size();

    for(int i = 0; i<=line-1; i++)
    {
        for(int j=0; j<column; j++)
        {
            if(grid[i][j].isEmpty())
            {
                std::cout << "0" << " ";
            }
            else
            {
                Color c = grid[i][j].getColor();
                if(c == Color::RED)
                {
                    std::cout << "R" << " ";
                }
                else if(c == Color::YELLOW)
                {
                    std::cout << "Y" << " ";
                }
                else
                {
                    std::cout << "ALLES FALSCH AUSGABE IN BOARDuPDTE" << " ";
                }
            }
        }
        std::cout << std::endl;
    }

}

void UI_Console::notifyWinner(Color color)
{
    if(color == UserInterface::Color::RED)
    {
        std::cout << "\n::::::::::::::::Spieler Rot hat gewonnen::::::::::::::::" << std::endl;
        std::cout << "::::::::::::::::::::Spiel wird beendendet:::::::::::::::::" << std::endl;
    }
    if(color == UserInterface::Color::YELLOW)
    {
        std::cout << "\n::::::::::::::::Spieler Gelb hat gewonnen::::::::::::::::" << std::endl;
        std::cout << "::::::::::::::::::::Spiel wird beendendet:::::::::::::::::" << std::endl;
    }
}

void UI_Console::notifyDraw()
{
    std::cout<< "------------ Unentschieden --------------" << std::endl;
    std::cout<< "---------- Spiel wird beendet -----------" << std::endl;
}

void UI_Console::init()
{
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "-         Spieler RED beginnt!                -" << std::endl;
    std::cout << "- mit Q oder q wird das Programm beendet      -" << std::endl;
    std::cout << "- Es sind nur Zahlen zwischen 1 und 7 gueltig -" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "-----------------------------------------------\n\n" << std::endl;
}

void UI_Console::currentPlayer(Color color)
{
    if(color == UserInterface::Color::RED)
            {
                std::cout << "\n-------- Gelber Spieler ist am Zug --------" << std::endl;
            }
            if(color == UserInterface::Color::YELLOW)
            {
               std::cout << "\n--------Roter Spieler ist am Zug--------" << std::endl;
            }
}
