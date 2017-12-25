#include <iostream>
#include <cstring>
#include <stdexcept>
#include "Console_UI.h"
#include "Game.h"


// Test Cases verwenden ist auch f�r Pr�fung wichtig!
// Test f�r Gewinner-Logik schreiben
//

bool testPassed() //startet nur alle Elemente
{


    Console_UI ui;

    bool testSuccessful = true;

    {
        Game game(ui);
        game.loadBoard("teststate.txt");
        if (!game.test('R', 2, 3, true)) testSuccessful = false;
    }

    {
        Game game(ui);
        game.loadBoard("teststate.txt");
        if (!game.test('R', 2, 4, true)) testSuccessful = false;
    }
    {
        Game game(ui);
        game.loadBoard("teststate.txt");
        if (!game.test('R', 1, 1, true)) testSuccessful = false;
    }
    {
        Game game(ui);
        game.loadBoard("teststate.txt");
        if (!game.test('R', 0, 0, false)) testSuccessful = false;
    }
    {
        Game game(ui);
        game.loadBoard("teststate.txt");
        if (!game.test('R', 0, 6, false)) testSuccessful = false;
    }
    {
        Game game(ui);
        game.loadBoard("teststate.txt");
        if (!game.test('R', 1, 2, false)) testSuccessful = false;
    }

    return testSuccessful;
}

int main() {
    if (testPassed()) {
        return 0;
    } else {
        return 1;
    }
}
