#ifndef GAMELOGIC_H_INCLUDED
#define GAMELOGIC_H_INCLUDED

#include <iostream>
#include "UserInterface.h"
#include <string>

#define GAME_COLUMNS 7
#define GAME_ROWS 6

using namespace std;

class GameLogic
{
    public:
        GameLogic(UserInterface& Interface);
        virtual ~GameLogic();
        void Play();
        void NewGame(UserInterface::Color _beginner);

    private:
        UserInterface& Interface;
        UserInterface::Color Beginner = UserInterface::Color::RED;
        UserInterface::Color CurrentPlayer = UserInterface::Color::RED;
        UserInterface::Color Winner;
        UserInterface::GridType GameBoard;

        unsigned char GetRowByColumn(unsigned char col);
        bool CheckColumn(unsigned char col);
        void SetField(unsigned char i_col, unsigned char i_row, UserInterface::Color color);
        bool CheckForWinner();
        void TogglePlayer();
        string RowToString(UserInterface::RowType row);
        bool CheckForYellow(string checker);
        bool CheckForRed(string checker);
        bool CheckForColor(string checker);
        string ColumnToString(UserInterface::GridType grid, uint8_t col);
        string DiagonalToString(UserInterface::GridType grid, uint8_t i_diag);
        bool CheckForDraw();
};

#endif // GAMELOGIC_H_INCLUDED
