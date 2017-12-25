#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H

#include "UserInterface.h"

class ConsoleInterface : public UserInterface
{
    public:
        //ConsoleInterface();
        virtual ~ConsoleInterface();

        ColumnType askPlayer(Color color);
        virtual void updateBoard(const GridType& grid);
        void notifyWinner(Color color);
        void notifyDraw();

    protected:

    private:
};

#endif // CONSOLEINTERFACE_H
