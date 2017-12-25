#include <iostream>
#include <gmock/gmock.h>
#include <math.h>
#include "Funktions.h"
#include "UserInterface.h"

UserInterface::GridType board;
Funktions allFunctions;
int line_maxIndex = board.size()-1;
int column_maxIndex = board[0].size()-1;


/**Kontrolliert ob horizontal 4 RED in einer Reihe sind**/
TEST(WinTest_Horizontal,RED_FieldBorderLeftUp)
{
    UserInterface::GridType horizontal_win;

    for(int stone=0; stone < 4 ; stone++)
    {
        horizontal_win[0][stone] = UserInterface::Color::RED;
    }

    ASSERT_TRUE(allFunctions.winCheck(horizontal_win));
}

/**Kontrolliert ob horizontal 4 RED in einer Reihe sind**/
TEST(WinTest_Horizontal,RED_FieldBorderRightDown)
{
    UserInterface::GridType horizontal_win;

    for(int stone=0; stone < 4 ; stone++)
    {
        horizontal_win[line_maxIndex][column_maxIndex-stone] = UserInterface::Color::RED;
    }

    ASSERT_TRUE(allFunctions.winCheck(horizontal_win));
}

/**Kontrolliert ob horizontal 4 YELLOW in einer Reihe sind**/
TEST(WinTest_Horizontal, Horizontal_YELLOW)
{
    UserInterface::GridType horizontal_win;

    for(int stone=0; stone < 4 ; stone++)
    {
        horizontal_win[0][stone] = UserInterface::Color::YELLOW;
    }

    ASSERT_TRUE(allFunctions.winCheck(horizontal_win));
}

/**Kontrolliert ob, bei nur 2 Steinen horizontal kein Gewinner ausgegeben wird**/
TEST(NoWinTest, Horizontal)
{
    UserInterface::GridType horizontal_nowin;

    for(int stone=0; stone < 2 ; stone++)
    {
        horizontal_nowin[line_maxIndex][column_maxIndex-stone] = UserInterface::Color::RED;
    }

    ASSERT_FALSE(allFunctions.winCheck(horizontal_nowin));
}

/**Kontrolliert ob vertikal 4 RED in einer Reihe sind**/
TEST(WinTest_Vertikal, RED_FieldBorderLeftUp)
{
    UserInterface::GridType vertikal_win;

    for(int stone=0; stone < 4 ; stone++)
    {
        vertikal_win[stone][0] = UserInterface::Color::RED;
    }

    ASSERT_TRUE(allFunctions.winCheck(vertikal_win));
}

/**Kontrolliert ob vertikal 4 RED in einer Reihe sind**/
TEST(WinTest_Vertikal, RED_FieldBorderRightDown)
{
    UserInterface::GridType vertikal_win;

    for(int stone=0; stone < 4 ; stone++)
    {
        vertikal_win[line_maxIndex][column_maxIndex-stone] = UserInterface::Color::RED;
    }

    ASSERT_TRUE(allFunctions.winCheck(vertikal_win));
}

/**Kontrolliert ob vertikal 4 YELLOW in einer Reihe sind**/
TEST(WinTest_Vertikal, YELLOW)
{
    UserInterface::GridType vertikal_win;

    for(int stone=0; stone < 4 ; stone++)
    {
        vertikal_win[4-stone][3] = UserInterface::Color::YELLOW;
    }

    ASSERT_TRUE(allFunctions.winCheck(vertikal_win));
}

/**Kontrolliert ob, bei nur 2 Steinen vertikal kein Gewinner ausgegeben wird**/
TEST(NoWinTest, Vertikal)
{
    UserInterface::GridType vertikal_nowin;

    for(int stone=0; stone < 2 ; stone++)
    {
        vertikal_nowin[line_maxIndex-stone][column_maxIndex] = UserInterface::Color::RED;
    }

    ASSERT_FALSE(allFunctions.winCheck(vertikal_nowin));
}

/**Kontrolliert ob diagonal (links unten - rechts oben) 4 RED in einer Reihe sind**/
TEST(WinTest_Diagonal_LDtoRU,RED_FieldBorderLeftUp)  //letzt mögliche Gewinnkombination in der linken oberen Spielfeldecke
{
    UserInterface::GridType diagonal_win;

    for(int stone = 0; stone < 4 ; stone++)
    {
        diagonal_win[3-stone][stone] = UserInterface::Color::RED;
    }

    ASSERT_TRUE(allFunctions.winCheck(diagonal_win));
}

/**Kontrolliert ob diagonal (links unten - rechts oben) 4 RED in einer Reihe sind**/
TEST(WinTest_Diagonal_LDtoRU,RED_FieldBorderRightDown)  //letzt mögliche Gewinnkombination in der rechten oberen Spielfeldecke
{
    UserInterface::GridType diagonal_win;

    for(int stone = 0; stone < 4 ; stone++)
    {
        diagonal_win[line_maxIndex-stone][column_maxIndex+stone-3] = UserInterface::Color::RED;
    }

    ASSERT_TRUE(allFunctions.winCheck(diagonal_win));
}

/**Kontrolliert ob diagonal (links unten - rechts oben) 4 YELLOW in einer Reihe sind**/
TEST(WinTest_Diagonal_LDtoRU,YELLOW)
{
    UserInterface::GridType diagonal_win;

    for(int stone = 0; stone < 4 ; stone++)
    {
        diagonal_win[4-stone][2+stone] = UserInterface::Color::YELLOW;
    }

    ASSERT_TRUE(allFunctions.winCheck(diagonal_win));
}

/**Kontrolliert ob, bei nur 2 Steinen diagonal (links unten - rechts oben) kein Gewinner ausgegeben wird**/
TEST(NoWinTest, Diagonal_LDtoRU)
{
    UserInterface::GridType diagonal_nowin;

    for(int stone = 0; stone < 1 ; stone++)
    {
        diagonal_nowin[line_maxIndex-stone][column_maxIndex+stone-3] = UserInterface::Color::YELLOW;
    }

    ASSERT_FALSE(allFunctions.winCheck(diagonal_nowin));
}

/**Kontrolliert ob diagonal (links oben - rechts unten) 4 RED in einer Reihe sind**/
TEST(WinTest_Diagonal_LUtoRD,RED_FieldBorderRightUp)
{
    UserInterface::GridType diagonal_win;

    for(int stone = 0; stone < 4 ; stone++)
    {
        diagonal_win[stone][column_maxIndex-stone-3] = UserInterface::Color::RED;
    }

    ASSERT_TRUE(allFunctions.winCheck(diagonal_win));
}

/**Kontrolliert ob diagonal (links oben - rechts unten) 4 RED in einer Reihe sind**/
TEST(WinTest_Diagonal_LUtoRD,RED_FieldBorderLeftDown)
{
    UserInterface::GridType diagonal_win;

    for(int stone = 0; stone < 4 ; stone++)
    {
        diagonal_win[line_maxIndex-3+stone][stone] = UserInterface::Color::RED;
    }

    ASSERT_TRUE(allFunctions.winCheck(diagonal_win));
}

/**Kontrolliert ob diagonal (links oben - rechts unten) 4 YELLOW in einer Reihe sind**/
TEST(WinTest_Diagonal_LUtoRD, YELLOW)
{
    UserInterface::GridType diagonal_win;

    for(int stone = 0; stone < 4 ; stone++)
    {
        diagonal_win[1+stone][3+stone] = UserInterface::Color::YELLOW;
    }

    ASSERT_TRUE(allFunctions.winCheck(diagonal_win));
}

/**Kontrolliert ob, bei nur 2 steinen diagonal (links oben - rechts unten) kein Gewinner ausgegeben wird**/
TEST(NoWinTest, Diagonal_LUtoRD)
{
    UserInterface::GridType diagonal_nowin;

    for(int stone = 0; stone < 2 ; stone++)
    {
        diagonal_nowin[line_maxIndex-3+stone][column_maxIndex+stone] = UserInterface::Color::YELLOW;
    }

    ASSERT_FALSE(allFunctions.winCheck(diagonal_nowin));
}

/**Überprüft die Draw-Funktion, mit voll befüllten Spielfeld**/
TEST(DrawTest, FullGrid)
{
    UserInterface::GridType draw_RED;
    int lines = draw_RED.size();
    int columns = draw_RED[0].size();

    for(int index_line = 0; index_line < lines; index_line++)
    {
        for(int index_column = 0; index_column < columns; index_column++)
        {
            draw_RED[index_line][index_column] = UserInterface::Color::RED;
        }
    }

    ASSERT_TRUE(allFunctions.drawCheck(draw_RED));
}

/**Überprüft die Draw-Funktion, mit nicht ganz befüllten Spielfeld**/
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

    ASSERT_FALSE(allFunctions.drawCheck(draw_RED));
}

