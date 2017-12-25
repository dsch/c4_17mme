#include<iostream>
#include<array>
#include<windows.h>
#include<stdio.h>
#include"Console.h"

UI :: UI()
{
}

UI :: ~UI()
{
}

UI::ColumnType UI::askPlayer(Color color)
{
    ColumnType column;

    if (color == Color::RED)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);    // Einf‰rben des Textes, Zahl gibt Farbe an 7= Weiﬂ, 12= Rot und 14= Gelb
        std::cout << "Spieler ROT bitte Spalte waehlen: ";
        std::cin >> column;
        std::cout << std::endl << std::endl;
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        std::cout << "Spieler GELB bitte Spalte waehlen: ";
        std::cin >> column;
        std::cout << std::endl << std::endl;
    }
    return column;

}

void UI::updateBoard(const GridType& grid)
{
    int row =grid.size();
    int col=grid[0].size();

    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            if (grid[i][j].isEmpty())
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                std::cout << "-" << " ";
            }
            else
            {
                if (grid[i][j].getColor() == Color::RED)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    std::cout << "R" << " ";
                }
                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    std::cout << "Y" << " ";
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void UI::notifyWinner(Color color)
{
    std::cout << std::endl;

    if (color == UserInterface::Color::RED)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        std::cout << "Gewinner: ROT!" << std::endl;
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        std::cout << "Gewinner: Gelb!" << std::endl;
    }
    std::cout << std::endl;
}

void UI::notifyDraw()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    std::cout << std::endl;
    std::cout << "Unentschieden!" << std::endl;
    std::cout << std::endl;
}
