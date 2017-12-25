#include"Logic.h"

Logic::Logic()
{
}

Logic::~Logic()
{
}

bool Logic::WinCheck(UserInterface::GridType board)
{

    static int FOUR = 3;
    bool game_win = false;
    int connect = 0;
    int line = board.size();
    int column = board[0].size();



    /** Überprüfung für Zeilen-kette **/

    for (int i_line=0; i_line < line; i_line++)         //Überprufung der Horizontale
    {
        for (int i_column=0; i_column < column - 1; i_column++)
        {
            if (false == (board[i_line][i_column].isEmpty()) && false ==(board[i_line][i_column+1].isEmpty()) && (board[i_line][i_column].getColor() == board[i_line][i_column+1].getColor()))
            {
                connect++;
                if (connect == FOUR)
                {
                    break;
                }
            }
            else
            {
                connect = 0;
            }

        }



        if (connect == FOUR)
        {

            game_win = true;
            break;
        }

    }

    connect = 0;
    {
        for (int i_column=0; i_column < column; i_column++)         // Überprüfung  der Vertikale
        {
            for (int i_line=0; i_line < line; i_line++)
            {
                if (false == (board[i_line][i_column].isEmpty()) && false ==(board[i_line+1][i_column].isEmpty()) && (board[i_line][i_column].getColor() == board[i_line+1][i_column].getColor()))
                {
                    connect++;
                    if (connect == FOUR)
                    {
                        break;
                    }
                }
                else
                {
                    connect = 0;
                }

            }
            if (connect == FOUR)
            {

                game_win = true;
                break;
            }
        }
    }

    connect = 0;
    {
        for(int ii_column = 0 ; ii_column < column-3; ii_column++)      //Überprüfung von Links unten nach Rechts oben
        {
            for (int i_line=3; i_line < line; i_line++)
            {

                for (int i_column=0; i_line-i_column > 0; i_column++)
                {
                    if (false == (board[i_line-i_column][i_column+ii_column].isEmpty()) && false ==(board[i_line-1-i_column][i_column+1+ii_column].isEmpty()) && (board[i_line-i_column][i_column+ii_column].getColor() == board[i_line-1-i_column][i_column+1+ii_column].getColor()))
                    {
                        connect++;
                        if (connect == FOUR)
                        {
                            break;
                        }
                    }
                    else
                    {
                        connect = 0;
                    }

                }

                if (connect == FOUR)
                {
                    break;
                }
            }

            if (connect == FOUR)
            {

                game_win = true;
                break;
            }
        }
    }

    connect = 0;
    {
        for(int ii_line = 0 ; ii_line < line-3; ii_line++)
        {
            for (int i_column=column-4; i_column >= 0; i_column--)         // Überprufung von Links oben nach Rechts unten
            {

                for (int i_line=0; i_line+i_column < line; i_line++)
                {
                    if (false == (board[i_line+ii_line][i_line+i_column].isEmpty()) && false ==(board[i_line+1+ii_line][i_line+i_column+1].isEmpty()) && (board[i_line+ii_line][i_line+i_column].getColor() == board[i_line+1+ii_line][i_line+i_column+1].getColor()))
                    {
                        connect++;
                        if (connect == FOUR)
                        {
                            break;
                        }
                    }
                    else
                    {
                        connect = 0;
                    }

                }

                if (connect == FOUR)
                {
                    break;
                }
            }

            if (connect == FOUR)
            {

                game_win = true;
                break;
            }
        }
    }

    return game_win;
}
