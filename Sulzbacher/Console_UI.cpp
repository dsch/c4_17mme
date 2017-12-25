#include "Console_UI.h"
#include <iostream>


Console_UI::Console_UI()
{
    //ctor

}

Console_UI::~Console_UI()
{
    //dtor
}

//Frag in der Console nach welche Spalte der jeweilige Spieler auswählt
UserInterface::ColumnType Console_UI::askPlayer(Color color)
{
    int spaltennummer;
    do{
        if(color == Color::RED)
        {
             std::cout << "Spierler Rot, waehle eine Spalte: ";
        }

        if(color == Color::YELLOW)
        {
             std::cout << "Spierler Gelb, waehle eine Spalte: ";
        }

        std::cin >> spaltennummer;
        std::cout << std::endl;

    }while(spaltennummer > 6 || spaltennummer < 0);  //Lässt nur bestimmte Zahlen zu

  return spaltennummer;

}

//Aktualisiert das Spielfeld
void Console_UI::updateBoard(const GridType& grid)
{
    //Zeichnet die erste Achse und beschriftet diese
    std::cout << "   | ";
    for(int i = 0; i < 7; i++)
    {
         std::cout << i << " | ";
    }
    std::cout << std::endl;

    //Zwischzeile
    std::cout << "--------------------------------" << std::endl;

    Color color;

    for(int zeile = 0; zeile < 6; zeile++)
    {
        std::cout << " " << zeile << " | ";

        for(int spalte = 0; spalte < 7; spalte++)
        {
            if(grid[zeile][spalte].isEmpty()==false)
            {
                if(grid[zeile][spalte].getColor() == UserInterface::Color::RED)
                {
                    std::cout << "R";
                }
                else
                {
                    std::cout << "G";
                }
                std::cout << " | ";
            }
            else
            {
                std::cout << "  | ";
            }
        }
        std::cout << std::endl << "--------------------------------" << std::endl;
    }
}

//wird aufgerufen wenn ein Gewinner feststeht
void Console_UI::notifyWinner(Color color)
{
    if(color == Color::RED)
    {
         std::cout << "Spierler Rot hat gewonnen" << std::endl;
    }

    if(color == Color::YELLOW)
    {
         std::cout << "Spierler Gelb hat gewonnnen" << std::endl;
    }
}

//wird aufgerufen wenn es sich um ein unentschieden handlet
void Console_UI::notifyDraw()
{
     std::cout << "Das Spiel endet unentschieden" << std::endl;
}


