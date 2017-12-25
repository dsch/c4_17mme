#include <iostream>
#include <gtest\gtest.h>
#include "gui/Gui.h"
#include "UserInterface.h"
#include "GameLogic.h"
#include "UI.h"

#define r UserInterface::Color::RED
#define y UserInterface::Color::YELLOW

using namespace std;

TEST(RowToStringTest, OutString)
{
    UserInterface::RowType row;
    row[0] = y;
    row[1] = y;
    row[2] = r;
    row[3] = y;
    row[4] = y;
    row[5] = r;
    row[6] = y;
    UI ui;
    GameLogic game(ui);
    EXPECT_EQ("YYRYYRY", game.RowToString(row));
}
