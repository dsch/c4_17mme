#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H

#include "UserInterface.h"


class ConnectFour : public UserInterface
{
    public:
        ConnectFour();
        virtual ~connectFour();

        int ColumnType askPlayer(Color color);
        void updateBoard();
        void notifyWinner();
        void notifyDraw();
        void drawEmptyBoard();

    protected:

    private:
};

#endif // CONNECTFOUR_H
