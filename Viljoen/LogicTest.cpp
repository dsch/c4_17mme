#include <iostream>
#include <gmock/gmock.h>
#include "include/GameLogic.h"
#include "include/ConsoleUI.h"


using namespace std;

TEST(CheckHorizontal, True)
{
    ConsoleUI ui; // instantiates ui

    GameLogic Game(ui); // initialises the game, class game has the game logic rules

    Game.PlayingField[0][0]= ConsoleUI::Color::RED;
    Game.PlayingField[0][1]= ConsoleUI::Color::RED;
    Game.PlayingField[0][2]= ConsoleUI::Color::RED;
    Game.PlayingField[0][3]= ConsoleUI::Color::RED;
    ASSERT_THAT(Game.CheckHorizontalWin(),true);
}

TEST(CheckVertical, True)
{
    ConsoleUI ui; // instantiates ui

    GameLogic Game(ui); // initialises the game, class game has the game logic rules

    Game.PlayingField[0][0]= ConsoleUI::Color::RED;
    Game.PlayingField[1][0]= ConsoleUI::Color::RED;
    Game.PlayingField[2][0]= ConsoleUI::Color::RED;
    Game.PlayingField[3][0]= ConsoleUI::Color::RED;
}

TEST(CheckDiagonal, LeftTrue)
{
    ConsoleUI ui; // instantiates ui

    GameLogic Game(ui); // initialises the game, class game has the game logic rules

    Game.PlayingField[0][0]= ConsoleUI::Color::RED;
    Game.PlayingField[1][1]= ConsoleUI::Color::RED;
    Game.PlayingField[2][2]= ConsoleUI::Color::RED;
    Game.PlayingField[3][3]= ConsoleUI::Color::RED;
}

TEST(CheckDiagonal, RightTrue)
{
    ConsoleUI ui; // instantiates ui

    GameLogic Game(ui); // initialises the game, class game has the game logic rules


    Game.PlayingField[0][3]= ConsoleUI::Color::RED;
    Game.PlayingField[1][2]= ConsoleUI::Color::RED;
    Game.PlayingField[2][1]= ConsoleUI::Color::RED;
    Game.PlayingField[3][0]= ConsoleUI::Color::RED;
}
