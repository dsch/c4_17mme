#ifndef GAME_H
#define GAME_H

#include "UserInterface.h"

class Game
{
    public:
        Game(UserInterface& ui);
        virtual ~Game();
        void playGame();
        int changeBetweenPlayer(int);
        int searchFreeRow(int, int);
        int writeInField(int,int,int);

        int checkVertikalWinner(int,int,int);
        int checkHorizontalWinner(int,int);
        int checkDiagonalLeftWinner();
        int checkDiagonalRightWinner();
        bool outputWinner(int);
        bool checkIfDraw(int);

    protected:

    private:
        UserInterface& ui;
        UserInterface::GridType grid;
};

#endif // GAME_H
