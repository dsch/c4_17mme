#ifndef C4_MAURERGAMEADAPTER_H
#define C4_MAURERGAMEADAPTER_H

#include "GameAdapterBase.h"
#include "Game.h"

class GameAdapter : public GameAdapterBase<> {
public:
    static void play(UserInterface &ui) {
        Game game(ui);
        game.play();
    }
};

#endif //C4_MAURERGAMEADAPTER_H
