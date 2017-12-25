#ifndef C4_SCHEIBLAUERGAMEADAPTER_H
#define C4_SCHEIBLAUERGAMEADAPTER_H

#include "GameAdapterBase.h"

void play_game(UserInterface &ui);

class GameAdapter : public GameAdapterBase<>
{
public:
    static void play(UserInterface& ui)
    {
        play_game(ui);
    }
};

#endif //C4_SCHEIBLAUERGAMEADAPTER_H
