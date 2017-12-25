#ifndef C4_WAGNERGAMEADAPTER_H
#define C4_WAGNERGAMEADAPTER_H

#include "GameAdapterBase.h"
#include "Game.h"

class GameAdapter : public GameAdapterBase<> {
public:
    static void play(UserInterface &ui) {
        Game game(ui);
        game.playGame();
    }
};


#endif //C4_WAGNERGAMEADAPTER_H
