#ifndef C4_CERIBASGAMEADAPTER_H
#define C4_CERIBASGAMEADAPTER_H

#include "GameAdapterBase.h"
#include "Game.h"

class GameAdapter : public GameAdapterBase<>
{
public:
    static void play(UserInterface& ui)
    {
        Game game(ui);
        game.play();
    }
    static const bool abort_with_exception = false;
    static const UserInterface::ColumnType abort_column = -1;
};


#endif //C4_CERIBASGAMEADAPTER_H
