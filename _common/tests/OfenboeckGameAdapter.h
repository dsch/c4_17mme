#ifndef C4_OFENBOECKGAMEADAPTER_H
#define C4_OFENBOECKGAMEADAPTER_H

#include "GameAdapterBase.h"

void play_game(UserInterface& gui);

class GameAdapter : public GameAdapterBase<>
{
public:
    static void play(UserInterface& ui)
    {
        play_game(ui);
    }
};

#endif //C4_OFENBOECKGAMEADAPTER_H
