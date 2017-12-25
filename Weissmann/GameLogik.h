/*
    M.Weissmann
*/
#ifndef GAMELOGIK_H_
#define GAMELOGIK_H_

#include "UserInterface.h"

class GameLogik
{
private:
    UserInterface::GridType grid;
    UserInterface::Color currentPlayer;
public:
    GameLogik();
    ~GameLogik();

    UserInterface::Color getCurrentPlayer();
    UserInterface::GridType getGrid();

    void switchPlayer();
    void updateGame(UserInterface::ColumnType col);

    bool isDraw(UserInterface::GridType grid);
    bool isWin(UserInterface::GridType grid);

};

#endif
