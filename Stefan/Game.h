#ifndef GAME_H
#define GAME_H

#include "UserInterface.h"

class Game
{
    public:
        Game(UserInterface& ui);
        virtual ~Game();
        void play(); // FUNKTION, DIE DAS SPIEL startet oder vorbereitet für ersten Spielzug

        int GewinnErmittlung(const UserInterface::GridType& grid);

    protected:

    private:
        UserInterface& ui;
};

#endif // GAME_H
