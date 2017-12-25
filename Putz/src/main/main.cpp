#include <iostream>
#include "GameLogic.h"
#include "ConsoleUI.h"
#include "gui/Gui.h"

void ConsoleHelp (char* exec_name) {
  std::cout << "Usage:" << std::endl;
  std::cout << exec_name << " <--mode> <mode option>" << std::endl << std::endl;
  std::cout << "  --ui graphic" << "  launch program with gui" << std::endl;
  std::cout << "  --ui console" << "  launch program with console ui" << std::endl;
  std::cout << "  --help" << "  display console arguments" << std::endl;
}

int main(int argc, char** argv) {

  if (argc == 3) {
    std::string param_one(argv[1]);
    std::string param_two(argv[2]);

    if (param_one == "--ui" && param_two == "graphic") {
      Gui game_ui;
      GameLogic game(game_ui);
      game.PlayGame();
    }
    else if (param_one == "--ui" && param_two == "console") {
      ConsoleUI game_ui;
      GameLogic game(game_ui);
      game.PlayGame();
    }
  }
  else if (argc == 1) {
    ConsoleUI game_ui;
    GameLogic game(game_ui);
    game.PlayGame();
  }
  else {
    ConsoleHelp(argv[0]);
  }

  return 0;
}