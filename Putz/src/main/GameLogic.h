#ifndef MAIN_GAMELOGIC_H
#define MAIN_GAMELOGIC_H

#include "UserInterface.h"

class GameLogic {

  public:
    UserInterface::GridType game_grid;
    UserInterface::Color winner;

    explicit GameLogic(UserInterface& game_ui) : winner(), game_ui(game_ui)  {};
    bool PlaceDisk(UserInterface::ColumnType column, UserInterface::Color color);
    bool CheckForWinner();
    bool CheckForDraw();
    void PlayGame();

    ~GameLogic() = default;

  private:
    UserInterface& game_ui;
};

#endif //MAIN_GAMELOGIC_H
