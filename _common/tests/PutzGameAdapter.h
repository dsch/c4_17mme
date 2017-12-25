#ifndef C4_PUTZGAMEADAPTER_H
#define C4_PUTZGAMEADAPTER_H

#include "GameAdapterBase.h"
#include "src/main/GameLogic.h"

class GameAdapter : public GameAdapterBase<UserInterface::Color::YELLOW> {
public:
    static void play(UserInterface &ui) {
        GameLogic game(ui);
        game.PlayGame();
    }
};


#endif //C4_PUTZGAMEADAPTER_H
