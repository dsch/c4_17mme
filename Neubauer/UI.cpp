#include <iostream>
#include <stdio.h>

#include "UI.h"

using namespace std;

UI::UI(){}
UI::~UI(){}

void UI::notifyDraw()
{
    cout << "DRAW - nobody won!" << endl;
}

UserInterface::ColumnType UI::askPlayer(Color color)
{
    unsigned char col = 0;
    if(color == UserInterface::Color::RED)
    {
        cout << "Player RED:" << endl;
        col = getColumn();
        return col;
    }
    else
    {
        cout << "Player YELLOW:" << endl;
        col = getColumn();
        return col;
    }
}

unsigned char UI::getColumn()
{
    cout << "Select your column: ";
    int col = ' ';
    fflush(stdin);
    cin >> col;
    return col;
}

void UI::updateBoard(const GridType& grid)
{
    system("cls");
    SetConsoleColor(COLOR_STD);

    cout << "Connect four" << endl << endl;
    DrawXAxis();
    DrawHorizontalSeparator();
    DrawAllRows(grid);
    cout << endl;
}

void UI::notifyWinner(Color color)
{
    if(color == Color::RED)
        cout << "Player RED has won!" << endl;
    else
        cout << "Player YELLOW has won!" << endl;
}

void UI::DrawRow(RowType row)
{
    for(int i = 0; i < GAME_COLUMNS; i++)
    {
        if(!row[i].isEmpty())
        {
            UI::SetConsoleColor(row[i].getColor());
            cout << "X";
            UI::SetConsoleColor(COLOR_STD);
            cout << " | ";
        }
        else
        {
            cout << "  | ";
        }
    }
    cout << endl;
}

void UI::DrawAllRows(const GridType& grid)
{
    for(int i = 0; i < GAME_ROWS; i++)
    {
        cout << " " << i << " | ";
        UI::DrawRow(grid[i]);
        UI::DrawHorizontalSeparator();
    }
}

void UI::DrawXAxis()
{
    cout << "   | ";
    for(int i = 0; i < sizeof(xAxis); i++)
    {
         cout << (int)xAxis[i] << " | ";
    }
    cout << endl;
}

void UI::DrawHorizontalSeparator()
{
    for(int i = 0; i < TABLE_WIDTH; i++)
    {
        cout << '-';
    }
    cout << endl;
}

void UI::SetConsoleColor(Color color)
{
    if(color == UserInterface::Color::RED)
        SetConsoleTextAttribute(hstdout, COLOR_RED);
    else
        SetConsoleTextAttribute(hstdout, COLOR_YELLOW);
}

void UI::SetConsoleColor(int color)
{
    SetConsoleTextAttribute(hstdout, color);
}
