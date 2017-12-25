#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "UserInterface.h"

class Console_UI : public UserInterface
{
public:
    Console_UI();
    ~Console_UI();

    class Field
    {
    public:
        bool isEmpty() const;
        Color getColor() const;
    };

    ColumnType askPlayer(Color color);
    void updateBoard(const GridType& grid);
    void notifyWinner(Color color);
    void notifyDraw();

protected:

private:
};

#endif // CONSOLE_UI_H
