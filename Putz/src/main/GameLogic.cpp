#include "GameLogic.h"

bool GameLogic::PlaceDisk(UserInterface::ColumnType column, UserInterface::Color color) {
  for (ssize_t i = game_grid.size()-1; i >= 0; i--) {
    if (game_grid[i][column].isEmpty()) {
      game_grid[i][column] = color;
      // Return true if placing the disk has succeeded
      return true;
    }
  }
  // Return false if we were unable to find an empty field in the column
  return false;
}

bool GameLogic::CheckForWinner() {
  UserInterface::Color current_color;
  size_t num_rows = game_grid.size();
  size_t num_columns = game_grid[0].size();

  // Iterate through the whole grid
  for (size_t row = 0; row < num_rows; row++) {
    for (size_t column = 0; column < num_columns; column++) {

      // Skip this field if it's empty
      if (game_grid[row][column].isEmpty())
        continue;

      current_color = game_grid[row][column].getColor();

      // Check horizontally
      for (size_t i = 1; i <= 3 && row + i < num_rows; i++) {

        // If the next field is empty or the colour doesn't match, we can stop checking
        if (game_grid[row + i][column].isEmpty() || game_grid[row + i][column].getColor() != current_color)
          break;

        if (i == 3) {
          winner = current_color;
          return true;
        }
      }

      // Check vertically
      for (size_t i = 1; i <= 3 && column + i < num_columns; i++) {

        // If the next field is empty or the colour doesn't match, we can stop checking
        if (game_grid[row][column + i].isEmpty() || game_grid[row][column + i].getColor() != current_color)
          break;

        if (i == 3) {
          winner = current_color;
          return true;
        }
      }

      // Check diagonally-right
      for (size_t i = 1; i <= 3 && row + i < num_rows && column + i < num_columns; i++) {

        // If the next field is empty or the colour doesn't match, we can stop checking
        if (game_grid[row + i][column + i].isEmpty() || game_grid[row + i][column + i].getColor() != current_color)
          break;

        if (i == 3) {
          winner = current_color;
          return true;
        }
      }

      // Check diagonally-left
      for (ssize_t i = 1; i <= 3 && row + i < num_rows && column - i >= 0; i++) {

        // If the next field is empty or the colour doesn't match, we can stop checking
        if (game_grid[row + i][column - i].isEmpty() || game_grid[row + i][column - i].getColor() != current_color)
          break;

        if (i == 3) {
          winner = current_color;
          return true;
        }
      }

    } // for columns
  } // for rows

  // If we haven't returned yet, there's no winner yet
  return false;
}

bool GameLogic::CheckForDraw(){
  UserInterface::Color current_color;
  bool current_empty;
  size_t num_rows = game_grid.size();
  size_t num_columns = game_grid[0].size();

  // Iterate through the whole grid
  for (size_t row = 0; row < num_rows; row++) {
    for (size_t column = 0; column < num_columns; column++) {

      current_empty = game_grid[row][column].isEmpty();
      current_color = game_grid[row][column].getColor();

      // Check horizontally
      for (size_t i = 1; i <= 3 && row + i < num_rows; i++) {

        // Make sure that the next fields are empty or have the same colour
        if (!game_grid[row + i][column].isEmpty())
          if (current_empty) {
            current_color = game_grid[row + i][column].getColor();
            current_empty = false;
          }
          else if (game_grid[row + i][column].getColor() != current_color)
            break;

        if (i == 3) {
          return false;
        }
      }
      current_empty = game_grid[row][column].isEmpty();

      // Check vertically
      for (size_t i = 1; i <= 3 && column + i < num_columns; i++) {

        // Make sure that the next fields are empty or have the same colour
        if (!game_grid[row][column + i].isEmpty())
          if (current_empty) {
            current_color = game_grid[row][column + i].getColor();
            current_empty = false;
          }
          else if (game_grid[row][column + i].getColor() != current_color)
            break;

        if (i == 3) {
          return false;
        }
      }
      current_empty = game_grid[row][column].isEmpty();

      // Check diagonally-right
      for (size_t i = 1; i <= 3 && row + i < num_rows && column + i < num_columns; i++) {

        // Make sure that the next fields are empty or have the same colour
        if (!game_grid[row + i][column + i].isEmpty())
          if (current_empty) {
            current_color = game_grid[row + i][column + i].getColor();
            current_empty = false;
          }
          else if (game_grid[row + i][column + i].getColor() != current_color)
            break;

        if (i == 3) {
          return false;
        }
      }
      current_empty = game_grid[row][column].isEmpty();

      // Check diagonally-left
      for (size_t i = 1; i <= 3 && row + i < num_rows && column - i >= 0; i++) {

        // Make sure that the next fields are empty or have the same colour
        if (!game_grid[row + i][column - i].isEmpty())
          if (current_empty) {
            current_color = game_grid[row + i][column - i].getColor();
            current_empty = false;
          }
          else if (game_grid[row + i][column - i].getColor() != current_color)
            break;

        if (i == 3) {
          return false;
        }
      }

    } // for columns
  } // for rows

  // If we haven't found a possibility to still win, we have a draw
  return true;
}

void GameLogic::PlayGame () {
  game_ui.updateBoard(game_grid);

  while (true) {
    while (!PlaceDisk(game_ui.askPlayer(UserInterface::Color::YELLOW), UserInterface::Color::YELLOW));
    game_ui.updateBoard(game_grid);
    if (CheckForWinner()) {
      game_ui.notifyWinner(winner);
      break;
    }
    if (CheckForDraw()) {
      game_ui.notifyDraw();
      break;
    }

    while (!PlaceDisk(game_ui.askPlayer(UserInterface::Color::RED), UserInterface::Color::RED));
    game_ui.updateBoard(game_grid);
    if (CheckForWinner()) {
      game_ui.notifyWinner(winner);
      break;
    }
    if (CheckForDraw()) {
      game_ui.notifyDraw();
      break;
    }
  }
};