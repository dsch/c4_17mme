#ifndef C4_VILJOENGAMEADAPTER_H
#define C4_VILJOENGAMEADAPTER_H

#include "GameAdapterBase.h"
#include "GameLogic.h"

class GameAdapter : public GameAdapterBase<> {
public:
    static void play(UserInterface &ui) {
        GameLogic Game(ui);
        Game.PlayGame();
    }
};

#endif //C4_VILJOENGAMEADAPTER_H
