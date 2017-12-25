/*
    M.Weissmann
*/

#include<gtest/gtest.h>
#include "UserInterface.h"
#include "UI_Console.h"
#include "GameLogik.h"
//#include"nurEinTest.h"

#include <iostream>

UserInterface::GridType board;
GameLogik game;

int line_Index_max = board.size()-1;         //int line_maxIndex = board.size()-1;
int column_Index_max = board[0].size()-1;    //int column_maxIndex = board[0].size()-1;

// horizontal 4 RED in einer Reihe sind
TEST(Win_Horizontal,Left_Up_Red)
{
    UserInterface::GridType win_horizontal;

    for(int i=0; i < 4 ; i++)
    {
        win_horizontal[0][i] = UserInterface::Color::RED;
    }

    ASSERT_TRUE(game.isWin(win_horizontal));
}

// horizontal 4 YELLOW in einer Reihe sind
TEST(Win_Horizontal,Left_Up_Yellow)
{
    UserInterface::GridType win_horizontal;

    for(int i=0; i < 4 ; i++)
    {
        win_horizontal[0][i] = UserInterface::Color::YELLOW;
    }

    ASSERT_TRUE(game.isWin(win_horizontal));
}

//Test ob, bei 3 geworfenen Steinen ein Gewinner ausgegeben wird horizontal
TEST(NoWinner, Horizontal)
{
    UserInterface::GridType noWin_horizontal;

    for(int i=0; i < 3 ; i++)
    {
        noWin_horizontal[line_Index_max][column_Index_max] = UserInterface::Color::RED;
    }

    ASSERT_FALSE(game.isWin(noWin_horizontal));
}

//Test ob 4 RED vertikal in einer Reihe sind
TEST(Win_Vertikal, Left_Up_Red)
{
    UserInterface::GridType win_vertikal;

    for(int i=0; i < 4 ; i++)
    {
        win_vertikal[i][0] = UserInterface::Color::RED;
    }

    ASSERT_TRUE(game.isWin(win_vertikal));
}

//Test ob 4 YELLOW vertikal in einer Reihe sind
TEST(Win_Vertikal, Left_Up_Yellow)
{
    UserInterface::GridType win_vertikal;

    for(int i=0; i < 4 ; i++)
    {
        win_vertikal[i][0] = UserInterface::Color::YELLOW;
    }

    ASSERT_TRUE(game.isWin(win_vertikal));
}

//Test ob, bei 3 geworfenen Steinen ein Gewinner ausgegeben wird vertikal
TEST(NoWinner, Vertikal)
{
    UserInterface::GridType noWin_vertikal;

    for(int i=0; i < 3 ; i++)
    {
        noWin_vertikal[line_Index_max][column_Index_max] = UserInterface::Color::RED;
    }

    ASSERT_FALSE(game.isWin(noWin_vertikal));
}

//==============================================================================================
//Test ob diagonal 4 RED in einer Reihe sind (links u. - rechts o.)

TEST(Win_Diagonal_LuRo,RED)
{
    UserInterface::GridType win_diagonal;

    for(int i = 0; i < 4 ; i++)
    {
        win_diagonal[line_Index_max-i][column_Index_max+i-3] = UserInterface::Color::RED;
    }

    ASSERT_TRUE(game.isWin(win_diagonal));
}

//Test ob diagonal  4 YELLOW in einer Reihe sind (links u - rechts o)
TEST(Win_Diagonal_LuRo,YELLOW)
{
    UserInterface::GridType win_diagonal;

    for(int i = 0; i < 4 ; i++)
    {
        win_diagonal[line_Index_max-i][column_Index_max+i-3] = UserInterface::Color::YELLOW;
    }

    ASSERT_TRUE(game.isWin(win_diagonal));
}



//Test ob bei 3 Steinen diagonal kein Gewinner ausgegeben wird (LoRu)
TEST(NoWinTest, Diagonal_LoRu)
{
    UserInterface::GridType nowin_diagonal;

    for(int i = 0; i < 2 ; i++)
    {
        nowin_diagonal[line_Index_max-3+i][column_Index_max+i] = UserInterface::Color::YELLOW;
    }

    ASSERT_FALSE(game.isWin(nowin_diagonal));
}

//Test ob diagonal  4 RED in einer Reihe sind LoRu
TEST(WinTest_Diagonal_LoRu,RED)
{
    UserInterface::GridType win_diagonal;

    for(int i = 0; i< 4 ; i++)
    {
        win_diagonal[i][column_Index_max-i-3] = UserInterface::Color::RED;
    }

    ASSERT_TRUE(game.isWin(win_diagonal));
}

//Test ob diagonal  4 RED in einer Reihe sind LoRu
TEST(WinTest_Diagonal_LoRu,RED_LeftUp)
{
    UserInterface::GridType win_diagonal;

    for(int i = 0; i < 4 ; i++)
    {
        win_diagonal[line_Index_max-3+i][i] = UserInterface::Color::RED;
    }

    ASSERT_TRUE(game.isWin(win_diagonal));
}

//Test ob diagonal  4 YELLOW in einer Reihe sind LoRu
TEST(WinTest_Diagonal_LoRu,YELLOW)
{
    UserInterface::GridType win_diagonal;

    for(int i = 0; i< 4 ; i++)
    {
        win_diagonal[i][column_Index_max-i-3] = UserInterface::Color::YELLOW;
    }

    ASSERT_TRUE(game.isWin(win_diagonal));
}

//Test ob diagonal  4 YELLOW in einer Reihe sind LoRu
TEST(WinTest_Diagonal_LoRu,YELLOW_LeftUp)
{
    UserInterface::GridType win_diagonal;

    for(int i = 0; i < 4 ; i++)
    {
        win_diagonal[line_Index_max-3+i][i] = UserInterface::Color::YELLOW;
    }

    ASSERT_TRUE(game.isWin(win_diagonal));
}

//==============================================================================================

//Überprüft die Draw-Funktion, mit voll befüllten Spielfeld
TEST(Test_Draw, Field_Full)
{
    UserInterface::GridType draw;
    int lines = draw.size();
    int columns = draw[0].size();

    for(int i = 0; i < lines; i++)
    {
        for(int j= 0; j < columns; j++)
        {
            draw[i][j] = UserInterface::Color::RED;
        }
    }

    ASSERT_TRUE(game.isDraw(draw));
}

//Überprüft die Draw-Funktion, mit nicht ganz befüllten Spielfeld
TEST(DrawTest, NotFullGrid)
{
    UserInterface::GridType draw_RED;
    int lines = draw_RED.size();
    int columns = draw_RED[0].size();

    for(int index_line = 0; index_line < lines; index_line++)
    {
        for(int index_column = 0; index_column < columns-4; index_column++)
        {
            draw_RED[index_line][index_column] = UserInterface::Color::RED;
        }
    }

    ASSERT_FALSE(game.isDraw(draw_RED));
}



