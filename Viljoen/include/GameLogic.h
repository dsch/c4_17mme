#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "../UserInterface.h"


class GameLogic
{
    public:
        GameLogic(UserInterface& ui);
        virtual ~GameLogic();

        void PlayGame();
        bool CheckHorizontalWin();
        bool CheckVerticalWin();
        bool CheckDiagonalWin();

        UserInterface::GridType PlayingField;


    protected:

    private:

    UserInterface& ui;
};

#endif // GAMELOGIC_H
