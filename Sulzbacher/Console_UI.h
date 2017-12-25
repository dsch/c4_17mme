#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "UserInterface.h"

class Console_UI : public UserInterface
{
public:
    Console_UI();
    virtual ~Console_UI();

    ColumnType askPlayer(Color color);
    UserInterface::GridType GameField;

    void updateBoard(const GridType& grid);
    void notifyWinner(Color color);
    void notifyDraw();


protected:

private:

};

#endif // CONSOLE_UI_H
