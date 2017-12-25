#ifndef GAME_H
#define GAME_H

#include "UserInterface.h"
#include <string>

// .h-Files: benennen / aufzählen der vorhandenen Funktionen
// .cpp-Files: schreiben / implementieren / defini;ren der Funktionen
class Game
{
    public:
        Game(UserInterface& ui);
        virtual ~Game();
        void play(); // FUNKTION, DIE DAS SPIEL startet oder vorbereitet für ersten Spielzug

        void setBoard(UserInterface::Color color, char row,char column);
        int getEmptyCell(char column);
        bool checkBoard(char row,char column);
        void loadBoard(std::string filename);
        bool test(char color, char gridRow,char gridCol, bool expectedValue);


    protected:

    private:


        UserInterface& ui;
        UserInterface::GridType grid;
        char gridSelection[4] = { 0,0,0,0 };
        UserInterface::Color CurrentPlayer;





};

#endif // GAME_H
