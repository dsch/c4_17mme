#ifndef C4_NEUBAUERGAMEADAPTER_H
#define C4_NEUBAUERGAMEADAPTER_H

#include "GameAdapterBase.h"
#include "GameLogic.h"

class GameAdapter : public GameAdapterBase<> {
public:
    static void play(UserInterface &ui) {
        GameLogic game(ui);
        game.Play();
    }
};

#endif //C4_NEUBAUERGAMEADAPTER_H
