#ifndef C4_DELYGAMEADAPTER_H
#define C4_DELYGAMEADAPTER_H

#include "GameAdapterBase.h"
#include "Spiel.h"

class GameAdapter : public GameAdapterBase<> {
public:
    static void play(UserInterface &ui) {
        Spiel spiel(ui);
        spiel.play();
    }
};

#endif //C4_DELYGAMEADAPTER_H
