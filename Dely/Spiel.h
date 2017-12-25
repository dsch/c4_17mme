#ifndef SPIEL_H
#define SPIEL_H

#include "UserInterface.h"

class Spiel
{
    public:
        Spiel(UserInterface& ui);
        virtual ~Spiel();
        void play();
        int Gewonnen(const UserInterface::GridType& grid);
        void Unentschieden(const UserInterface::GridType& grid);

    protected:

    private:
        UserInterface& ui;
};

#endif // SPIEL.H
