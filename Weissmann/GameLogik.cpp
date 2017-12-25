/*
    M.Weissmann
*/

#include "GameLogik.h"
#include<iostream>


GameLogik::GameLogik()
{
    currentPlayer = UserInterface::Color::RED;
}
GameLogik::~GameLogik()
{
}

UserInterface::Color GameLogik::getCurrentPlayer()
{
    return currentPlayer;
}

void GameLogik::switchPlayer()
{
    if(currentPlayer == UserInterface::Color::RED)
    {

        currentPlayer = UserInterface::Color::YELLOW;
    }
    else//(currentPlayer == UserInterface::Color::YELLOW)
    {
        //std::cout<<"Und hier"<< std::cout;
        currentPlayer = UserInterface::Color::RED;
    }
}

void GameLogik::updateGame(UserInterface::ColumnType col)
{
   int field_line = grid.size();
   if(currentPlayer == UserInterface::Color::RED)
    {
            //column = ui.askPlayer(UserInterface::Color::YELLOW) - 48; //askPlayer gibt char aus ASCII-Tabelle zurück, "-48" um auf wahren Zahlenwert zu kommen

        for (int i=0; i <= field_line ; i++)
        {
            if (grid[i][col-1].isEmpty())                     // -1 ist die Indexkorrektur der Benutzereingabe =
            {
                if(i == field_line )
                {
                    grid[i-1][col-1] = UserInterface::Color::YELLOW; // wirft Stein in Spielfeld
                }
            }
            else
            {
                grid[i-1][col-1] = UserInterface::Color::YELLOW; // wirft Stein in Spielfeld
                break;
            }
        }
    }
    else
    {
        for (int i=0; i <= field_line ; i++)
        {
            if (grid[i][col-1].isEmpty())                     // -1 ist die Indexkorrektur der Benutzereingabe =
            {
                if(i == field_line )
                {
                    grid[i-1][col-1] = UserInterface::Color::RED; // wirft Stein in Spielfeld
                }
            }
            else
            {
                grid[i-1][col-1] = UserInterface::Color::RED; // wirft Stein in Spielfeld
                break;
            }
        }
    }
}

UserInterface::GridType GameLogik::getGrid()
{
    return grid;
}


bool GameLogik::isDraw(UserInterface::GridType grid)
{
    int grid_line   = grid.size();
    int grid_column = grid[0].size();
    int field_is_full = 0;

    bool draw = 0;

    int max_rounds = grid_line * grid_column;

    for(int i = 0; i < grid_line; i++)
    {
        for(int j = 0; j < grid_column; j++)
        {
            if (!(grid[i][j].isEmpty()))
            {
                field_is_full++;
                if (field_is_full >= max_rounds)
                {
                    draw = true;
                    break;
                }
            }
        }
        if (draw==true) break;
    }
    //std::cout<< "in der schleifr"<<std::endl;
    return draw;
}

bool GameLogik::isWin(UserInterface::GridType grid)
{
    static int FOUR_STONES = 3;
    int line = grid.size();
    int column = grid[0].size();
    bool win = 0;
    int connect = 0;

//===================================================================================
// Horizontale Gewinner-Ermittlung
    for (int i = line-1; i > 0; i--) //=
    {
        for (int j = column-1; j > 0; j--)
        {
            if (false == (grid[i][j].isEmpty()) && false ==(grid[i][j-1].isEmpty()) &&
                (grid[i][j].getColor() == grid[i][j-1].getColor()))
            {
                connect++;
                if (connect == FOUR_STONES)
                {
                    break;
                }
            }
            else
            {
                connect = 0;
            }
        }

        if (connect == FOUR_STONES)
        {
            win = true;
            break;
        }
    }

//===================================================================================
//Vertikale Gewinner-Ermittlung
    if (connect != FOUR_STONES)
    {
        for (int j = column-1; j > 0; j--) //=
        {
            for (int i = line-1; i > 0; i--)
            {
                if ((false == (grid[i][j].isEmpty())) && (false ==(grid[i-1][j].isEmpty())) &&
                    ((grid[i][j].getColor() == grid[i-1][j].getColor())))
                {
                    connect++;
                    if (connect == FOUR_STONES)
                    {
                        break;
                    }
                }
                else
                {
                    connect = 0;
                }
            }
            if (connect == FOUR_STONES)
            {
                win = true;
                break;
            }
        }
    }

//===================================================================================
//Diagonale von links unten - nach rechts oben: Gewinner-Ermittlung
    if (connect != FOUR_STONES)
    {
        for(int jj = 0; jj < column-3; jj++) //ii_column
        {
            for (int i=3; i < line; i++)         //i_line
            {
                for (int j=0; i-j > 0; j++) // i_column
                {
                    if (false == (grid[i-j][j+jj].isEmpty()) && false ==(grid[i-1-j][j+1+jj].isEmpty()) &&
                            (grid[i-j][j+jj].getColor() == grid[i-1-j][j+1+jj].getColor()))
                    {
                        connect++;
                        if (connect == FOUR_STONES)
                        {
                            break;
                        }
                    }
                    else
                    {
                        connect = 0;
                    }
                }

                if (connect == FOUR_STONES)
                {
                    break;
                }
            }

            if (connect == FOUR_STONES)
            {
                win = true;
                break;
            }
        }
    }

//===================================================================================
//Diagonale von links oben - nach rechts unten: Gewinner-Ermittlung

    if (connect != FOUR_STONES)
    {
        for(int ii=0; ii < line-3; ii++)     // ii_line
        {
            for (int j=column-4; j >= 0; j--) //i_column
            {
                for (int i=0; i+j< line; i++)    //i_line
                {
                    if (false == (grid[i+ii][i+j].isEmpty()) && false ==(grid[i+1+ii][i+j+1].isEmpty()) &&
                        (grid[i+ii][i+j].getColor() == grid[i+1+ii][i+j+1].getColor()))
                    {
                        connect++;

                        if (connect == FOUR_STONES)
                        {
                            break;
                        }
                    }
                    else
                    {
                        connect = 0;
                    }
                }

                if (connect == FOUR_STONES)
                {
                    break;
                }
            }

            if (connect == FOUR_STONES)
            {
                win = true;
                break;
            }
        }
    }

return win;
}







