#include "Game.h"


Game::Game(UserInterface& ui) : ui(ui)
{
    //ctor
}

Game::~Game()
{
    //dtor
}

//definieren was gemacht wird wenn play() aufgerufen wird
void Game::play()
{

    int einwurfSpalte;
    bool spieler = 0;
    int spielstatus = 2;    //0...Gewonnen Rot, 1...Gewonnnen Gelb, 2...Spiel fortsetzen, 3...unentschiden

    ui.updateBoard(GameField);

    do{
        if(spieler == 0)
        {
            einwurfSpalte = ui.askPlayer(UserInterface::Color::RED);    //Fragt den Spieler Rot welche Spalte er wählt, Wert wird auf ColumnType zurückgegeben
            Game::PlaceField(einwurfSpalte, UserInterface::Color::RED);
            spieler = 1;
        }
        else
        {
            einwurfSpalte = ui.askPlayer(UserInterface::Color::YELLOW);    //Fragt den Spieler Rot welche Spalte er wählt, Wert wird auf ColumnType zurückgegeben
            Game::PlaceField(einwurfSpalte, UserInterface::Color::YELLOW);
            spieler = 0;
        }

        ui.updateBoard(GameField);

        //unentschide muss vor dem Sieg stehen, es ist möglich alle felder zu besetzt und trotzdem das wer gewinnt
        spielstatus = Game::Spielstanddraw(spielstatus);
        spielstatus = Game::Spielstand(spielstatus);


    }while(spielstatus == 2);   //Spiel wird so lange gespielt bis wer gwonnen hat oder unentschieden ist

    switch(spielstatus)
    {
        case 0:
        {
            ui.notifyWinner(UserInterface::Color::RED);
            break;
        }
        case 1:
        {
            ui.notifyWinner(UserInterface::Color::YELLOW);
            break;
        }
        default:
        {
            ui.notifyDraw();
            break;
        }
    }


}

//Weist dem passenden Feld eine Farbe zu
void Game::PlaceField(char spalte, UserInterface::Color color)
{

    int laufvariableZeile = 0;
    do
    {
            //Wenn das aktuelel Feld frei ist und das darunter liegenende besetzt ist, wird das Feld eingefärbt
            if(GameField[laufvariableZeile][spalte].isEmpty()==true && GameField[laufvariableZeile+1][spalte].isEmpty()==false)
            {

                    GameField[laufvariableZeile][spalte] = color;

            }
            //Ist noch kein Feld in dieser Spalte besetzt, wird das unterste eingefärbt
            else if(laufvariableZeile == 5 && GameField[laufvariableZeile][spalte].isEmpty()==true)
            {
                GameField[laufvariableZeile][spalte] = color;
            }

    laufvariableZeile = laufvariableZeile + 1;

    }while(laufvariableZeile <= 5);

}


int Game::Spielstand(int spielstatus)
{
    int spalte;
    int zeile;

    //Untersucht das Spielfeld auf vertikale 4-Gewinnt
    for(spalte = 0; spalte <= 6; spalte++)
    {
        for(zeile = 0; zeile <= 2; zeile++)
        {

            if(GameField[zeile + 0][spalte].isEmpty() == false && GameField[zeile + 0][spalte].getColor() == UserInterface::Color::RED &&
               GameField[zeile + 1][spalte].isEmpty() == false && GameField[zeile + 1][spalte].getColor() == UserInterface::Color::RED &&
               GameField[zeile + 2][spalte].isEmpty() == false && GameField[zeile + 2][spalte].getColor() == UserInterface::Color::RED &&
               GameField[zeile + 3][spalte].isEmpty() == false && GameField[zeile + 3][spalte].getColor() == UserInterface::Color::RED)
                {
                    return(0);
                }

            if(GameField[zeile + 0][spalte].isEmpty() == false && GameField[zeile + 0][spalte].getColor() == UserInterface::Color::YELLOW &&
               GameField[zeile + 1][spalte].isEmpty() == false && GameField[zeile + 1][spalte].getColor() == UserInterface::Color::YELLOW &&
               GameField[zeile + 2][spalte].isEmpty() == false && GameField[zeile + 2][spalte].getColor() == UserInterface::Color::YELLOW &&
               GameField[zeile + 3][spalte].isEmpty() == false && GameField[zeile + 3][spalte].getColor() == UserInterface::Color::YELLOW)
                {
                    return(1);
                }
        }
    }

    //Untersucht das Spielfeld auf horizontale 4-Gewinnt
    for(spalte = 0; spalte <= 3; spalte++)
    {
        for(zeile = 0; zeile <= 5; zeile++)
        {
            if(GameField[zeile][spalte + 0].isEmpty() == false && GameField[zeile][spalte + 0].getColor() == UserInterface::Color::RED &&
               GameField[zeile][spalte + 1].isEmpty() == false && GameField[zeile][spalte + 1].getColor() == UserInterface::Color::RED &&
               GameField[zeile][spalte + 2].isEmpty() == false && GameField[zeile][spalte + 2].getColor() == UserInterface::Color::RED &&
               GameField[zeile][spalte + 3].isEmpty() == false && GameField[zeile][spalte + 3].getColor() == UserInterface::Color::RED)
                {
                    return(1);
                }

            if(GameField[zeile][spalte + 0].isEmpty() == false && GameField[zeile][spalte + 0].getColor() == UserInterface::Color::YELLOW &&
               GameField[zeile][spalte + 1].isEmpty() == false && GameField[zeile][spalte + 1].getColor() == UserInterface::Color::YELLOW &&
               GameField[zeile][spalte + 2].isEmpty() == false && GameField[zeile][spalte + 2].getColor() == UserInterface::Color::YELLOW &&
               GameField[zeile][spalte + 3].isEmpty() == false && GameField[zeile][spalte + 3].getColor() == UserInterface::Color::YELLOW)
                {
                    return(1);
                }
        }
    }

    //Untersucht das Spielfeld auf Diogonale 4-Gewinnt
    for(spalte = 0; spalte <=2; spalte++)
    {
        for(zeile = 0; zeile <=3; zeile++)
        {
            //Diogonal lvon links unten nach rechts oben
            if(GameField[zeile + 0][spalte + 0].isEmpty() == false && GameField[zeile + 0][spalte + 0].getColor() == UserInterface::Color::RED &&
               GameField[zeile + 1][spalte + 1].isEmpty() == false && GameField[zeile + 1][spalte + 1].getColor() == UserInterface::Color::RED &&
               GameField[zeile + 2][spalte + 2].isEmpty() == false && GameField[zeile + 2][spalte + 2].getColor() == UserInterface::Color::RED &&
               GameField[zeile + 3][spalte + 3].isEmpty() == false && GameField[zeile + 3][spalte + 3].getColor() == UserInterface::Color::RED)
                {
                    return(0);
                }
            //Diogonal von links oben nach rechts unten
            if(GameField[zeile + 0][spalte + 3].isEmpty() == false && GameField[zeile + 0][spalte + 3].getColor() == UserInterface::Color::RED &&
               GameField[zeile + 1][spalte + 2].isEmpty() == false && GameField[zeile + 1][spalte + 2].getColor() == UserInterface::Color::RED &&
               GameField[zeile + 2][spalte + 1].isEmpty() == false && GameField[zeile + 2][spalte + 1].getColor() == UserInterface::Color::RED &&
               GameField[zeile + 3][spalte + 0].isEmpty() == false && GameField[zeile + 3][spalte + 0].getColor() == UserInterface::Color::RED)
                {
                    return(0);
                }
            //Diogonal lvon links unten nach rechts oben
            if(GameField[zeile + 0][spalte + 0].isEmpty() == false && GameField[zeile + 0][spalte + 0].getColor() == UserInterface::Color::YELLOW &&
               GameField[zeile + 1][spalte + 1].isEmpty() == false && GameField[zeile + 1][spalte + 1].getColor() == UserInterface::Color::YELLOW &&
               GameField[zeile + 2][spalte + 2].isEmpty() == false && GameField[zeile + 2][spalte + 2].getColor() == UserInterface::Color::YELLOW &&
               GameField[zeile + 3][spalte + 3].isEmpty() == false && GameField[zeile + 3][spalte + 3].getColor() == UserInterface::Color::YELLOW)
                {
                    return(1);
                }
            //Diogonal von links oben nach rechts unten
            if(GameField[zeile + 0][spalte + 3].isEmpty() == false && GameField[zeile + 0][spalte + 3].getColor() == UserInterface::Color::YELLOW &&
               GameField[zeile + 1][spalte + 2].isEmpty() == false && GameField[zeile + 1][spalte + 2].getColor() == UserInterface::Color::YELLOW &&
               GameField[zeile + 2][spalte + 1].isEmpty() == false && GameField[zeile + 2][spalte + 1].getColor() == UserInterface::Color::YELLOW &&
               GameField[zeile + 3][spalte + 0].isEmpty() == false && GameField[zeile + 3][spalte + 0].getColor() == UserInterface::Color::YELLOW)
                {
                    return(1);
                }
        }
    }

    return(spielstatus);

}

//Überprüft ob das Spielfeld komplett gefüllt ist
int Game::Spielstanddraw(int spielstatus)
{
    //Überprüft ob alle Felder der obersten Reihe besetzt sind
    for(int spalte = 0; spalte <=6; spalte++)
    {
         if(GameField[0][spalte].isEmpty() == true)
         {
             return(spielstatus);
         }

    }
    return(3);

}
