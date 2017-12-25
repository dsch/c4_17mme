#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "UserInterface.h"

// Console ist dumm. Console gibt nur aus! xD

// Funktionen machen sachen wie zB:
// Spielfeld aufzeichnen / graphische darstellung
// Spielstand anzeigen
// Benachrichtigungstext wer gewonnen hat

// --Zu Beachten:
// matrizen Koordinaten sind oben links (0,0)
// aber für Game-Logik ist es besser wenn zB unten links (0,0) ist
// besser an einer einzigen Stelle im Programm umdrehen dass man nicht verwirrt ist

class Console_UI : public UserInterface
{
public:
    Console_UI();
    virtual ~Console_UI();

    class Field
    {
    public:
        //Field() : empty(true), color();
        bool isEmpty() const;
        Color getColor() const;
    };

    /**
    typedef unsigned char ColumnType;
    typedef std::array<Field, 7> RowType;
    typedef std::array<RowType, 6> GridType;
    */
    ColumnType askPlayer(Color color);
    void updateBoard(const GridType& grid);
    void notifyWinner(Color color);
    void notifyDraw();
    // ~UserInterface();

protected:

private:
};

#endif // CONSOLE_UI_H
