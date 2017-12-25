#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ConsoleInterface.h"
#include "UserInterface.h"
#include "Game.h"

using namespace std;

ConsoleInterface console_ui;
UserInterface & ui = console_ui;
Game game(ui);

int maxRows = 6;
int maxColumn = 7;


TEST(vertikalWinner,RED_Up)
{
    UserInterface::GridType vertikalRed;
    int winner = 0;

    vertikalRed[1][2] = UserInterface::Color::RED;
    vertikalRed[2][2] = UserInterface::Color::RED;
    vertikalRed[3][2] = UserInterface::Color::RED;
    vertikalRed[4][2] = UserInterface::Color::RED;

    /*for(int disk=1; disk < 5 ; disk++)
    {
        vertikal[disk][1] = UserInterface::Color::RED;
        newDisk = disk;
    }*/
    winner = game.checkVertikalWinner(4,2,0); //Reihe, Column, Player
    ASSERT_TRUE(winner == 4);
}

TEST(vertikalWinner,YELLOW_Up)
{
    UserInterface::GridType vertikalYellow;
    int winner = 0;

    vertikalYellow[1][2] = UserInterface::Color::RED;
    vertikalYellow[2][2] = UserInterface::Color::RED;
    vertikalYellow[3][2] = UserInterface::Color::RED;
    vertikalYellow[4][2] = UserInterface::Color::RED;
    /*for(int disk=1; disk < 5 ; disk++)
    {
        vertikalYellow[disk][1] = UserInterface::Color::YELLOW;
        newDisk = disk;
    }*/
    winner = game.checkVertikalWinner(4,2,1); //Reihe, Column, Player
    ASSERT_TRUE(winner == 4);
}

TEST(horizontalWinner,RED_Up)
{
    UserInterface::GridType horizontal;
    int winner = 0;

    for(int disk=1; disk < 5 ; disk++)
    {
        horizontal[1][disk] = UserInterface::Color::RED;
    }
    winner = game.checkHorizontalWinner(1,0); //Reihe, Column, Player
    ASSERT_TRUE(winner == 4);
}


TEST(diagonalRightWinnerTest,RED_Diagonal_Right)
{
    UserInterface::GridType diagonalRight;
    int winner = 0;

    for(int disk = 1; disk < 5 ; disk++)
    {
        diagonalRight[disk][disk] = UserInterface::Color::RED;
    }

    //ui.updateBoard(diagonalRight);

    winner = game.checkDiagonalRightWinner();
    ASSERT_TRUE(winner == 4);
}


TEST(diagonalLeftWinnerTest,RED_Diagonal_Left)
{
    UserInterface::GridType diagonalLeft;
    int winner = 0;

    diagonalLeft[1][5] = UserInterface::Color::RED;
    diagonalLeft[2][4] = UserInterface::Color::RED;
    diagonalLeft[3][3] = UserInterface::Color::RED;
    diagonalLeft[4][2] = UserInterface::Color::RED;

    //ui.updateBoard(diagonalLeft);

    winner = game.checkDiagonalLeftWinner(); //Reihe, Column, Player
    ASSERT_TRUE(winner==4);
}

TEST(drawCheck,draw)
{
    UserInterface::GridType diagonalLeft;
    int diskCounter = 42;

    bool gameRunning = game.checkIfDraw(diskCounter);

    ASSERT_FALSE(gameRunning);
}
