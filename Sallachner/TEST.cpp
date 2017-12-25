#include<iostream>
#include<gtest/gtest.h>
#include<math.h>
#include"Logic.h"
#include"UserInterface.h"

TEST(WinTest, Horizontal_RED)                   //Kontrolle ob 4 horizontal ROT sind
{
    UserInterface::GridType horizontal_win;

    for(int stone=0; stone < 4 ; stone++)
    {
        horizontal_win[1][2+stone] = UserInterface::Color::RED;
    }

    Logic Gamelogic;
    ASSERT_TRUE(Gamelogic.WinCheck(horizontal_win));
}

TEST(WinTest, Horizontal_YELLOW)                  //Kontrolle ob 4 horizontal GELB sind
{
    UserInterface::GridType horizontal_win;

    for(int stone=0; stone < 4 ; stone++)
    {
        horizontal_win[1][2+stone] = UserInterface::Color::YELLOW;
    }

    Logic Gamelogic;
    ASSERT_TRUE(Gamelogic.WinCheck(horizontal_win));
}

TEST(NoWinTest, Horizontal)                 //Kontrolle das bei nur 2 Steinen horizontal kein Gewinner fest steht
{
    UserInterface::GridType horizontal_win;

    for(int stone=0; stone < 2 ; stone++)
    {
        horizontal_win[1][2+stone] = UserInterface::Color::RED;
    }

    Logic Gamelogic;
    ASSERT_FALSE(Gamelogic.WinCheck(horizontal_win));
}

TEST(WinTest, Vertikal_RED)                      //Kontrolle ob 4 vertikal ROT sind
{
    UserInterface::GridType vertikal_win;

    for(int stone=0; stone < 4 ; stone++)
    {
        vertikal_win[4-stone][3] = UserInterface::Color::RED;
    }

    Logic Gamelogic;
    ASSERT_TRUE(Gamelogic.WinCheck(vertikal_win));
}

TEST(WinTest, Vertikal_YELLOW)                     //Kontrolle ob 4 vertikal GELB sind
{
    UserInterface::GridType vertikal_win;

    for(int stone=0; stone < 4 ; stone++)
    {
        vertikal_win[4-stone][3] = UserInterface::Color::YELLOW;
    }

    Logic Gamelogic;
    ASSERT_TRUE(Gamelogic.WinCheck(vertikal_win));
}

TEST(NoWinTest, Vertikal)                   //Kontrolle das bei nur 2 Steinen vertikal kein Gewinner fest steht
{
    UserInterface::GridType vertikal_win;

    for(int stone=0; stone < 2 ; stone++)
    {
        vertikal_win[4-stone][3] = UserInterface::Color::RED;
    }

    Logic Gamelogic;
    ASSERT_FALSE(Gamelogic.WinCheck(vertikal_win));
}

TEST(WinTest, Diagonal_LDtoRU_RED)                   //Kontrolle ob 4 mal ROT in der Diagonale von Links unten nach Rechts oben sind
{
    UserInterface::GridType diagonal_win;

        for(int stone = 0; stone < 4 ; stone++)
        {
            diagonal_win[4-stone][2+stone] = UserInterface::Color::RED;
        }

    Logic Gamelogic;
    ASSERT_TRUE(Gamelogic.WinCheck(diagonal_win));
}

TEST(WinTest, Diagonal_LDtoRU_YELLOW)                   //Kontrolle ob 4 mal GELB in der Diagonale von Links unten nach Rechts oben sind
{
    UserInterface::GridType diagonal_win;

        for(int stone = 0; stone < 4 ; stone++)
        {
            diagonal_win[4-stone][2+stone] = UserInterface::Color::YELLOW;
        }

    Logic Gamelogic;
    ASSERT_TRUE(Gamelogic.WinCheck(diagonal_win));
}

TEST(NoWinTest, Diagonal_LDtoRU)                   //Kontrolle das kein gewinner fest steht wenn nur 2 Steine diagonal von Links unten nach Rechts oben liegen
{
    UserInterface::GridType diagonal_win;

        for(int stone = 0; stone < 2 ; stone++)
        {
            diagonal_win[4-stone][2+stone] = UserInterface::Color::YELLOW;
        }

    Logic Gamelogic;
    ASSERT_FALSE(Gamelogic.WinCheck(diagonal_win));
}

TEST(WinTest, Diagonal_LUtoRD_RED)                   //Kontrolle ob 4 mal ROT in der Diagonale von Rechts unten nach Links oben sind
{
    UserInterface::GridType diagonal_win;

        for(int stone = 0; stone < 4 ; stone++)
        {
            diagonal_win[1+stone][3+stone] = UserInterface::Color::RED;
        }

    Logic Gamelogic;
    ASSERT_TRUE(Gamelogic.WinCheck(diagonal_win));
}

TEST(WinTest, Diagonal_LUtoRD_YELLOW)                   //Kontrolle ob 4 mal GELB in der Diagonale von Rechts unten nach Links oben sind d
{
    UserInterface::GridType diagonal_win;

        for(int stone = 0; stone < 4 ; stone++)
        {
            diagonal_win[1+stone][3+stone] = UserInterface::Color::YELLOW;
        }

    Logic Gamelogic;
    ASSERT_TRUE(Gamelogic.WinCheck(diagonal_win));
}

TEST(NoWinTest, Diagonal_LUtoRD)                   //Kontrolle das kein gewinner fest steht wenn nur 2 Steine diagonal von Rechts unten nach Links oben liegen
{
    UserInterface::GridType diagonal_win;

        for(int stone = 0; stone < 2 ; stone++)
        {
            diagonal_win[1+stone][3+stone] = UserInterface::Color::YELLOW;
        }

    Logic Gamelogic;
    ASSERT_FALSE(Gamelogic.WinCheck(diagonal_win));
}
