#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "../UserInterface.h"




class ConsoleUI : public UserInterface
{

public:

    ConsoleUI();

    virtual ~ConsoleUI();
    ColumnType askPlayer(Color color);
    void updateBoard(const GridType& PlayingField);
    void notifyWinner(Color color);
    void notifyDraw();


protected:

private:
};

#endif // CONSOLEUI_H
