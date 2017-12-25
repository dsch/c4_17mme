#ifndef CONSOLE_H
#define CONSOLE_H

#include "UserInterface.h"

class Console : public UserInterface
{
public:
    Console();
    virtual ~Console();

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


protected:

private:
};

#endif // CONSOLE_H
