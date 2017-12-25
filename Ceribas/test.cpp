#include <iostream>
#include <cstring>
#include <stdexcept>
#include "Console_UI.h"
#include "Game.h"


// Test Cases verwenden ist auch für Prüfung wichtig!
// Test für Gewinner-Logik schreiben
//

bool testPassed() //startet nur alle Elemente
{


    Console_UI ui;
    Game game(ui);

    bool testSuccessful = true;

    game.loadBoard("teststate.txt");
    if (!game.test('R',2,3,true))  testSuccessful=false;
    if (!game.test('R',2,4,true))  testSuccessful=false;
    if (!game.test('R',1,1,true))  testSuccessful=false;
    if (!game.test('R',0,0,false)) testSuccessful=false;
    if (!game.test('R',0,6,false)) testSuccessful=false;
    if (!game.test('R',1,2,false)) testSuccessful=false;


   if(testSuccessful) true; else false;
}


