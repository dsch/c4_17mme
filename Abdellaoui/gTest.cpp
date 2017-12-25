#include <iostream>
#include <cstring>
#include <stdexcept>
#include "Console_UI.h"
#include "Game.h"
#include "gtest/gtest.h"

TEST(SquareRootTest, PositiveNos) {
    bool success;
    Console_UI ui;
    Game game(ui);
    for (size_t i = 0; i < 5; i++)
        game.grid[0][i] = Console_UI::Color::RED;

    success = game.checkBoard(0, 0);

    ASSERT_True(success);

    //EXPECT_EQ (row=r, colow=r, col-48 (1));
    //EXPECT_EQ (25.4, square-root (645.16));
    //EXPECT_EQ (50.3321, square-root (2533.310224));
}

/*TEST (SquareRootTest, ZeroAndNegativeNos) {
    ASSERT_EQ (0.0, square-root (0.0));
    ASSERT_EQ (-1, square-root (-22.0));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}*/
