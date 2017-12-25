#include "Console_UI.h"
#include <iostream>
#include <array>


Console_UI::Console_UI()
{
    //ctor
}

Console_UI::~Console_UI()
{
    //dtor
}

#if 1

Console_UI::ColumnType Console_UI::askPlayer(Color color)
{
    ColumnType column;

    if (color == Color::YELLOW)
    {
        std::cout << "Gelber Spieler Spalte auswaehlen: " ;
        std::cin >> column;
        std::cout << std::endl << std::endl;
    }

    if (color == Color::RED)
    {
        std::cout << "Roter Spieler Spalte auswaehlen: " ;
        std::cin >> column;
        std::cout << std::endl << std::endl;
    }
    return column-49;
}

void Console_UI::updateBoard(const GridType& grid)
{
    system("cls"); //löscht den Bildschirm der Console
    int line = grid.size();             //Zeilen werden ausgelesen, ohne Indexangabe
    int column = grid[0].size();        //alle Element aus der 0ten-Zeile ausgegeben, mit ersten Index

    for(int i=0; i<line; i++)
    {
        for (int j=0; j<column; j++)
        {
            if (grid[i][j].isEmpty())
            {
                std::cout << "O" << " ";
            }
            else
            {
                if (grid[i][j].getColor() == Color::YELLOW)
                {
                    std::cout << "Y" << " ";
                }
                if (grid[i][j].getColor() == Color::RED)
                {
                    std::cout << "R" << " ";
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Console_UI::notifyWinner(Color color)
{
    std::cout << std::endl;
    if (color == UserInterface::Color::RED)
    {
        std::cout << "ROT hat gewonnen!!"<< std::endl;
    }
    if (color == UserInterface::Color::YELLOW)
    {
        std::cout << "GELB hat gewonnen!!"<< std::endl;
    }

    std::cout << std::endl;
}

void Console_UI::notifyDraw()
{
    std::cout << std::endl;
    std::cout << "Kein Sieger mehr moeglich. Unentschieden!"<< std::endl;
    std::cout << std::endl;
}

#endif
