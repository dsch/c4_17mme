#include <iostream>
#include "GameLogic.h"
#include "UserInterface.h"
#include <string.h>

using namespace std;

GameLogic::GameLogic(UserInterface& Interface) : Interface(Interface){}
GameLogic::~GameLogic(){}

void GameLogic::NewGame(UserInterface::Color _beginner)
{
    Beginner = _beginner;
    CurrentPlayer = _beginner;
    Play();
}

void GameLogic::Play()
{
    try
    {
        Interface.updateBoard(GameBoard);

        do
        {
            unsigned char col = 0;
            do
            {
                col = Interface.askPlayer(CurrentPlayer);
            } while(!CheckColumn(col));
            SetField(col, GetRowByColumn(col), CurrentPlayer);
            Interface.updateBoard(GameBoard);
            TogglePlayer();
        } while(!CheckForWinner() && !CheckForDraw());
    }
    catch(...)
    {
        return;
    }
}

void GameLogic::SetField(unsigned char i_col, unsigned char i_row, UserInterface::Color color)
{
    UserInterface::RowType row = GameBoard[i_row];
    row[i_col] = color;
    GameBoard[i_row] = row;
}

void GameLogic::TogglePlayer()
{
    if(CurrentPlayer == UserInterface::Color::RED)
        CurrentPlayer = UserInterface::Color::YELLOW;
    else
        CurrentPlayer = UserInterface::Color::RED;
}

bool GameLogic::CheckColumn(unsigned char col)
{
    UserInterface::RowType row = GameBoard[0];
    if(row[col].isEmpty())
        return true;

    return false;
}

unsigned char GameLogic::GetRowByColumn(unsigned char col)
{
    for(unsigned char i = 0; i < GAME_ROWS; i++)
    {
        UserInterface::RowType row = GameBoard[i];
        if(!row[col].isEmpty())
        {
            return i-1;
        }
    }
    return GAME_ROWS - 1;
}

bool GameLogic::CheckForDraw()
{
    UserInterface::RowType row = GameBoard[0];
    for(int i = 0; i < GAME_COLUMNS; i++)
    {
        if(row[i].isEmpty())
            return false;
    }
    Interface.notifyDraw();
    return true;
}

bool GameLogic::CheckForWinner()
{
    //Checker-Algorithm
    //Check rows
    for(int i = 0; i < GAME_ROWS; i++)
    {
        if(CheckForColor(RowToString(GameBoard[i])))
            return true;
    }

    //Check columns
    for(int i = 0; i < GAME_COLUMNS; i++)
    {
        if(CheckForColor(ColumnToString(GameBoard, i)))
            return true;
    }

    //Check diagonal
    for(int i = 0; i < (GAME_COLUMNS + GAME_ROWS - 1); i++)
    {
        if(CheckForColor(DiagonalToString(GameBoard, i)))
            return true;
    }
    return false;
}

bool GameLogic::CheckForColor(string checker)
{
    if(CheckForRed(checker))
    {
        Interface.notifyWinner(UserInterface::Color::RED);
        return true;
    }
    else if(CheckForYellow(checker))
    {
        Interface.notifyWinner(UserInterface::Color::YELLOW);
        return true;
    }
    else
        return false;
}

bool GameLogic::CheckForYellow(string checker)
{
    size_t contains = checker.find("YYYY");
        if(contains >= 0 && contains <= 2*GAME_COLUMNS-4+1)
            return true;

    return false;
}

bool GameLogic::CheckForRed(string checker)
{
    size_t contains = checker.find("RRRR");
        if(contains >= 0 && contains <= 2*GAME_COLUMNS-4+1)
            return true;

    return false;
}

string GameLogic::RowToString(UserInterface::RowType row)
{
    char buffer[GAME_COLUMNS];
    for(int i = 0; i < GAME_COLUMNS; i++)
    {
        if(row[i].isEmpty())
            buffer[i] = ' ';
        else if(row[i].getColor() == UserInterface::Color::RED)
            buffer[i] = 'R';
        else
            buffer[i] = 'Y';
    }
    string out(buffer, GAME_COLUMNS);
    return out;
}

string GameLogic::ColumnToString(UserInterface::GridType grid, uint8_t col)
{
    char buffer[GAME_COLUMNS];
    for(int i = 0; i < GAME_ROWS; i++)
    {
        UserInterface::RowType row = grid[i];
        if(row[col].isEmpty())
            buffer[col] = ' ';
        else if(row[col].getColor() == UserInterface::Color::RED)
            buffer[i] = 'R';
        else
            buffer[i] = 'Y';
    }
    string out(buffer, GAME_ROWS);
    return out;
}

string GameLogic::DiagonalToString(UserInterface::GridType grid, uint8_t i_diag)
{
    int8_t y = 0;
    uint8_t x_left = 0;
    uint8_t x_right = 0;
    char buffer_left[GAME_COLUMNS] = {' ', ' ', ' ', ' ', ' ', ' ', ' '};   //contains colors from bottom-left to top-right
    char buffer_right[GAME_COLUMNS] = {' ', ' ', ' ', ' ', ' ', ' ', ' '};  //contains colors from bottom-right to top-left

    //Get coordinates from diagonal index
    if(i_diag < GAME_ROWS)
    {
        y = i_diag;
        x_left = 0;
        x_right = GAME_COLUMNS - 1;
    }
    else
    {
        y = GAME_ROWS - 1;
        x_left = i_diag - (GAME_ROWS - 1);
        x_right = (GAME_COLUMNS - 1) - x_left;
    }

    do
    {
        //copy row each cycle
        UserInterface::RowType row = grid[y];

        //copy color information to bottom-left/top-right array
        if(row[x_left].isEmpty())
            buffer_left[x_left] = ' ';
        else if(row[x_left].getColor() == UserInterface::Color::RED)
            buffer_left[x_left] = 'R';
        else
            buffer_left[x_left] = 'Y';

        //copy color information to bottom-right/top-left array
        if(row[x_right].isEmpty())
            buffer_right[x_right] = ' ';
        else if(row[x_right].getColor() == UserInterface::Color::RED)
            buffer_right[x_right] = 'R';
        else
            buffer_right[x_right] = 'Y';

        //calculate new coordinates
        x_left++;
        x_right--;
        y--;
    } while(y >= 0 && x_left < GAME_COLUMNS);

    //merge left and right array to one string with a '#' as a separator
    string out(buffer_left, GAME_COLUMNS);
    string tmp = "#";
    string tmp2(buffer_right, GAME_COLUMNS);
    out = (out + tmp) + tmp2;
    return out;
}
