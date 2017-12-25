#ifndef GAME_H
#define GAME_H

#include "UserInterface.h"

class Game
{
    public:
        Game(UserInterface& ui);
        virtual ~Game();
        void play(); // Spiel wird gestartet
        int Gewonnen(const UserInterface::GridType& grid);
        bool Unentschieden(const UserInterface::GridType& grid);

    protected:

    private:
        void updateBoard(const UserInterface::GridType& grid);
        UserInterface& ui;
};

#endif // GAME_H
