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
        void Unentschieden(const UserInterface::GridType& grid);

    protected:

    private:
        UserInterface& ui;
};

#endif // GAME_H
