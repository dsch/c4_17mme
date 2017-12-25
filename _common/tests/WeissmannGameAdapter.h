#ifndef C4_WEISSMANNGAMEADAPTER_H
#define C4_WEISSMANNGAMEADAPTER_H

#include "GameAdapterBase.h"

int play_game(UserInterface& ui);

class GameAdapter : public GameAdapterBase<>
{
public:
    static void play(UserInterface& ui)
    {
        play_game(ui);
    }
};

#endif //C4_WEISSMANNGAMEADAPTER_H
