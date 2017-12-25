#ifndef C4_SALLACHNERGAMEADAPTER_H
#define C4_SALLACHNERGAMEADAPTER_H

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

#endif //C4_SALLACHNERGAMEADAPTER_H
