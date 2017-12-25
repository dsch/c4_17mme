#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ConsoleInterface.h"
#include "UserInterface.h"
#include "Game.h"

using namespace std;

ConsoleInterface console_ui;
UserInterface & ui = console_ui;

int maxRows = 6;
int maxColumn = 7;

const int RED = 0;
const int YELLOW = 1;

TEST(vertikalWinner,RED_Up)
{
    int winner = 0;

    Game game(ui);
    game.writeInField(0, 2, RED);
    game.writeInField(1, 2, RED);
    game.writeInField(2, 2, RED);
    game.writeInField(3, 2, RED);

    /*for(int disk=1; disk < 5 ; disk++)
    {
        vertikal[disk][1] = UserInterface::Color::RED;
        newDisk = disk;
    }*/
    winner = game.checkVertikalWinner(3, 2, YELLOW); //Reihe, Column, Player
    ASSERT_TRUE(winner == 4);
}

TEST(vertikalWinner,YELLOW_Up)
{
    int winner = 0;

    Game game(ui);
    game.writeInField(0, 2, YELLOW);
    game.writeInField(1, 2, YELLOW);
    game.writeInField(2, 2, YELLOW);
    game.writeInField(3, 2, YELLOW);
    /*for(int disk=1; disk < 5 ; disk++)
    {
        vertikalYellow[disk][1] = UserInterface::Color::YELLOW;
        newDisk = disk;
    }*/
    winner = game.checkVertikalWinner(3, 2, RED); //Reihe, Column, Player
    ASSERT_TRUE(winner == 4);
}

TEST(horizontalWinner,RED_Up)
{
    Game game(ui);
    int winner = 0;

    for(int disk=1; disk < 5 ; disk++)
    {
        game.writeInField(0, disk, RED);
    }
    winner = game.checkHorizontalWinner(0,YELLOW); //Reihe, Column, Player
    ASSERT_TRUE(winner == 4);
}


TEST(diagonalRightWinnerTest,RED_Diagonal_Right)
{
    Game game(ui);
    int winner = 0;

    for(int disk = 1; disk < 5 ; disk++)
    {
        game.writeInField(disk, disk, RED);
    }

    //ui.updateBoard(diagonalRight);

    winner = game.checkDiagonalRightWinner();
    ASSERT_TRUE(winner == 4);
}


TEST(diagonalLeftWinnerTest,RED_Diagonal_Left)
{
    Game game(ui);
    int winner = 0;

    game.writeInField(1, 5, RED);
    game.writeInField(2, 4, RED);
    game.writeInField(3, 3, RED);
    game.writeInField(4, 2, RED);

    //ui.updateBoard(diagonalLeft);

    winner = game.checkDiagonalLeftWinner(); //Reihe, Column, Player
    ASSERT_TRUE(winner==4);
}

TEST(drawCheck,draw)
{
    Game game(ui);
    int diskCounter = 42;

    bool gameRunning = game.checkIfDraw(diskCounter);

    ASSERT_FALSE(gameRunning);
}
