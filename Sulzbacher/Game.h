#ifndef GAME_H
#define GAME_H

#include "UserInterface.h"


class Game
{
    public:
        Game(UserInterface& ui);
        virtual ~Game();
        void play(); // FUNKTION, DIE DAS SPIEL startet oder vorbereitet f�r ersten Spielzug

    protected:

    private:
        UserInterface& ui;
        UserInterface::GridType GameField;

        //Funktionen
        void PlaceField(char spalte, UserInterface::Color color);  //Paziert die Farbe auf dem n�chsten Element
        int Spielstand(int spielstatus);    //liefert die 0 wenn Rot gewonnen hat, 1 bei Geld und 2 wenn noch keiner gewonnen hat
        int Spielstanddraw(int spielstatus);
};

#endif // GAME_H
