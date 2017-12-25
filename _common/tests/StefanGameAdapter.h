#ifndef C4_STEFANGAMEADAPTER_H
#define C4_STEFANGAMEADAPTER_H

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
};



#endif //C4_STEFANGAMEADAPTER_H
