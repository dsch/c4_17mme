#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

#include"UserInterface.h"

class UI : public UserInterface
{
public:

    UI();

    ~UI();

    ColumnType askPlayer(Color color);

    void updateBoard(const GridType& grid);

    void notifyWinner(Color color);

    void notifyDraw();


};

#endif // CONSOLE_H_INCLUDED
