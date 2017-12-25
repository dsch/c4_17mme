#include <iostream>
#include <gmock/gmock.h>
#include "../main/GameLogic.h"
#include "../main/ConsoleUI.h"

TEST(identifies_win_row, CheckForWinner) {
  ConsoleUI game_ui;
  GameLogic game(game_ui);

  // Insert four disks next to each other
  for (size_t i = 0; i < 4; i++)
    game.game_grid[0][i] = UserInterface::Color::RED;

  EXPECT_TRUE(game.CheckForWinner());
  EXPECT_EQ(game.winner, UserInterface::Color::RED);
}

TEST(identifies_win_column, CheckForWinner) {
  ConsoleUI game_ui;
  GameLogic game(game_ui);

  // Insert four disks next to each other
  for (size_t i = 0; i < 4; i++)
    game.game_grid[i][0] = UserInterface::Color::RED;

  EXPECT_TRUE(game.CheckForWinner());
  EXPECT_EQ(game.winner, UserInterface::Color::RED);
}

TEST(identifies_win_diagonal_right, CheckForWinner) {
  ConsoleUI game_ui;
  GameLogic game(game_ui);

  // Insert four disks next to each other
  for (size_t i = 0; i < 4; i++)
    game.game_grid[i][i] = UserInterface::Color::RED;

  EXPECT_TRUE(game.CheckForWinner());
  EXPECT_EQ(game.winner, UserInterface::Color::RED);
}

TEST(identifies_win_diagonal_left, CheckForWinner) {
  ConsoleUI game_ui;
  GameLogic game(game_ui);

  // Insert four disks next to each other
  for (size_t i = 0; i < 4; i++)
    game.game_grid[i][game.game_grid.size()-1-i] = UserInterface::Color::RED;

  EXPECT_TRUE(game.CheckForWinner());
  EXPECT_EQ(game.winner, UserInterface::Color::RED);
}

TEST(identifies_no_win, CheckForWinner) {
  ConsoleUI game_ui;
  GameLogic game(game_ui);

  // This time only three disks are inserted
  for (size_t i = 0; i < 3; i++)
    game.game_grid[0][i] = UserInterface::Color::RED;

  EXPECT_FALSE(game.CheckForWinner());
}

TEST (place_yellow_disk, PlaceDisk) {
  ConsoleUI game_ui;
  GameLogic game(game_ui);

  game.PlaceDisk(0, UserInterface::Color::YELLOW);

  EXPECT_FALSE(game.game_grid[game.game_grid.size()-1][0].isEmpty());
  EXPECT_TRUE(game.game_grid[game.game_grid.size()-1][1].isEmpty());
  EXPECT_EQ(game.game_grid[game.game_grid.size()-1][0].getColor(), UserInterface::Color::YELLOW);
}
