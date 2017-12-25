#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "UserInterface.h"

class Console_UI : public UserInterface
{
public:
    Console_UI();
    virtual ~Console_UI();


    ColumnType askPlayer(Color color);

    void updateBoard(const GridType& grid);
    //hier: Meldung dass die funktion existiert.
    // Implementierung / ausgeschriebener Code ist in ...cpp File von console_UI
    void notifyWinner(Color color);
    void notifyDraw()
    {

    }
    void cls();


protected:

private:
};

#endif // CONSOLE_UI_H
