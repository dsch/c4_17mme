#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "UserInterface.h"

class Console_UI : public UserInterface
{
public:
    Console_UI();
    virtual ~Console_UI();

    class Field
    {
    public:
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


protected:

private:
};

#endif
