#include "Funktions.h"

Funktions::Funktions()
{
    //ctor
}

Funktions::~Funktions()
{
    //dtor
}

bool Funktions::winCheck(UserInterface::GridType board)
{
    static int FOUR = 3; //4 Steine verbunden

    bool game_win = false;
    int connect = 0;
    int line = board.size();                //Ohne Indexangabe werden die zeilen ausgelesen
    int column = board[0].size();           //Mit ersten Index werden alle Element aus der 0ten-Zeile ausgegeben

    /** Horizontale Gewinner-Ermittlung **/

    {
    for (int i_line=line-1; i_line >= 0; i_line--)
    {
        for (int i_column=column-1; i_column > 0; i_column--)
        {
            if (false == (board[i_line][i_column].isEmpty()) &&
            false ==(board[i_line][i_column-1].isEmpty()) &&
            (board[i_line][i_column].getColor() == board[i_line][i_column-1].getColor()))
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

    /** Vertikale Gewinner-Ermittlung **/
    connect = 0;
    {
        for (int i_column=column-1; i_column >= 0; i_column--)
        {
            for (int i_line=line-1; i_line > 0; i_line--)
            {
                if ((false == (board[i_line][i_column].isEmpty())) &&
                        (false ==(board[i_line-1][i_column].isEmpty())) &&
                        ((board[i_line][i_column].getColor() == board[i_line-1][i_column].getColor())))
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

    /** Diagonale von links unten - nach rechts oben: Gewinner-Ermittlung **/
    connect = 0;
    {
        for(int ii_column = 0 ; ii_column < column-3; ii_column++)
        {
            for (int i_line=3; i_line < line; i_line++)
            {
                for (int i_column=0; i_line-i_column > 0; i_column++)
                {
                    if (false == (board[i_line-i_column][i_column+ii_column].isEmpty()) &&
                            false ==(board[i_line-1-i_column][i_column+1+ii_column].isEmpty()) &&
                            (board[i_line-i_column][i_column+ii_column].getColor() == board[i_line-1-i_column][i_column+1+ii_column].getColor()))
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

    /** Diagonale von links oben - nach rechts unten: Gewinner-Ermittlung **/
    connect = 0;
    {
        for(int ii_line = 0 ; ii_line < line-3; ii_line++)
        {
            for (int i_column=column-4; i_column >= 0; i_column--)
            {
                for (int i_line=0; i_line+i_column < line; i_line++)
                {
                    if (false == (board[i_line+ii_line][i_line+i_column].isEmpty()) &&
                            false ==(board[i_line+1+ii_line][i_line+i_column+1].isEmpty()) &&
                            (board[i_line+ii_line][i_line+i_column].getColor() == board[i_line+1+ii_line][i_line+i_column+1].getColor()))
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

/** Unentschieden-Ermittlung **/
bool Funktions::drawCheck(UserInterface::GridType board)
{
    int lines = board.size();
    int columns = board[0].size();
    int full_field = 0;
    bool draw = false;

    int max_rounds = lines*columns;

    for(int index_line = 0; index_line < lines; index_line++)
    {
        for(int index_column = 0; index_column < columns; index_column++)
        {
            if (!(board[index_line][index_column].isEmpty()))
            {
                full_field++;
                if (full_field >= max_rounds)
                {
                    draw = true;
                    break;
                }
            }
        }
        if (draw==true) break;
    }

    return draw;
}

