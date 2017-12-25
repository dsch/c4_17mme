#include <iostream>
#include <limits>
#include "ConsoleUI.h"

void ConsoleUI::ClearInputStream() {
  // Clear the input stream up to the carriage return
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

ConsoleUI::ConsoleUI() : hConsole(GetStdHandle(STD_OUTPUT_HANDLE)) {
  // Initialise the text colour to be white
  SetConsoleTextAttribute(hConsole, 15);
}

ConsoleUI::ColumnType ConsoleUI::askPlayer(Color color) {

  std::string playerString;
  if (color == Color::RED) playerString = "RED";
  else if (color == Color::YELLOW) playerString = "YELLOW";

  ssize_t chosen_column = 0;
  while (true) {
    std::cout << "Player " << playerString << ", please enter a column number: ";

    // Check if the user entered a column number
    if (std::cin >> chosen_column) {

      // Abort the program if '-1' is entered as the column number
      if (chosen_column == -1) {
        ClearInputStream();
        throw Abort();
      }

      if (chosen_column < 7 && chosen_column >= 0) {
        ClearInputStream();
        break;
      }
    }

    ClearInputStream();
    std::cout << "Invalid input. Please enter a valid value!" << std::endl << std::endl;
  }

  return static_cast<ColumnType>(chosen_column);
}

void ConsoleUI::updateBoard(const GridType &grid) {
  // Clear the console
  // OS-specific!
  system("cls");

  std::cout << std::endl << "New game board state:" << std::endl << std::endl;
  for (size_t i = 0; i < grid.size(); i++) {
    for (size_t j = 0; j < grid[i].size(); j++) {

      if (grid[i][j].isEmpty()) {
        std::cout << "\tO";
        continue;
      }

      if (grid[i][j].getColor() == Color::RED) {
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "\tR";
        SetConsoleTextAttribute(hConsole, 15);
      }
      else if (grid[i][j].getColor() == Color::YELLOW) {
        SetConsoleTextAttribute(hConsole, 14);
        std::cout << "\tY";
        SetConsoleTextAttribute(hConsole, 15);
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void ConsoleUI::notifyWinner(Color color) {

  std::string playerString;
  if (color == Color::RED) playerString = "RED";
  else if (color == Color::YELLOW) playerString = "YELLOW";

  std::cout << "Player " << playerString << " has won!" << std::endl;
}
