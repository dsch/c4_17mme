// Bei unabsichtlichem schlieﬂen: cb_testrunner in TaskManager
#include "gtest/gtest.h"
#include "Game.h"
#include "Console_UI.h"
#include <iostream>
//#include "Gewinnerfunktion.h"

Console_UI ui;
Game game(ui);
UserInterface::GridType testSpielFeld;

//GewinnErmittlung() -> Rueckgabewert = 1 rot gewonnen , = 2 gelb gewonnen , 3 = draw
TEST(_4gewinntTEST, testvomtest)
{
    int uebergabe12 = 0;

    if(testSpielFeld[0][0].isEmpty() == true)
    {
        //std::cout << "feld leer " << std::endl;
        uebergabe12 = 1;
    }

    ASSERT_TRUE(uebergabe12);
}

TEST(_4gewinntTEST, testvomtest2)
{
    int uebergabe13 = 0;
    testSpielFeld[0][0] = UserInterface::Color::RED;

    if(testSpielFeld[0][0].getColor() == UserInterface::Color::RED)
    {
        //std::cout << "farbe rot " << std::endl;
        uebergabe13 = 1;
    }
    ASSERT_TRUE(uebergabe13);
}

TEST(_4gewinntTEST, vertikalTest_YELLOW)
{

    for(int i= 3; i >= 0 ; i--)
    {
        testSpielFeld[i][0] = UserInterface::Color::YELLOW;
    }

    ASSERT_EQ(game.GewinnErmittlung(testSpielFeld), 2);
}

TEST(_4gewinntTEST, vertikalTest_RED)
{

    for(int i= 3; i >= 0 ; i--)
    {
        testSpielFeld[i][0] = UserInterface::Color::RED;
    }

    ASSERT_EQ(game.GewinnErmittlung(testSpielFeld), 1);
}

TEST(_4gewinntTEST, horizontTest_GELB)
{

    for(int i= 3; i >= 0 ; i--)
    {
        testSpielFeld[0][i] = UserInterface::Color::YELLOW;
    }

    ASSERT_EQ(game.GewinnErmittlung(testSpielFeld), 2);
}

TEST(_4gewinntTEST, schraegTest1_ROT)
{

    for (int j = 0; j <= 3; j++)
    {
            testSpielFeld[j][j] = UserInterface::Color::RED;
    }

    ASSERT_EQ(game.GewinnErmittlung(testSpielFeld), 1);
}




