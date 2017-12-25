#include "Console_UI.h"
#include <iostream>
// implementierung der Funktionen, die in Console_UI.h vorangekündigt wurden

Console_UI::Console_UI()
{
    //ctor
//    std::cout << "Hier steht der Anfang des Spiels" << std::endl;
    std::cout << "Willkommen bei 4 Gewinnt Spieler ROT beginnt" << std::endl;

}

Console_UI::~Console_UI()
{
    //dtor
}

//warum zwei mal :: erstes weil man userinterface :: columnType verwenden will könnt ja auch .

//man schaut im UserInterface nach dem ColumnType welches "char" ist
//also char Console_UI::askPlayer(Color color)
//im Console_UI wird nach askPlayer geschaut
UserInterface::ColumnType Console_UI::askPlayer(Color color)
{
    int Eingabe = 13;

    if( color == UserInterface::Color::RED)
    {

        std::cout<< "Spieler ROT Spalte auswählen [1-7] mit 13 Abbrechen" <<std::endl;
        std::cin >> Eingabe;
    }

    if(color == UserInterface::Color::YELLOW)
    {
        std::cout<< "Spieler GELB Spalte auswählen [1-7] mit 13 Abbrechen" <<std::endl;
        std::cin >> Eingabe;
    }
    if( Eingabe == 13)
    {
        throw Abort();
    }

    return Eingabe - 1;
}

void Console_UI::updateBoard(const GridType& grid)
{
    std::cout<< "updateBoard" <<std::endl;
    for(int w=0; w <=5 ; w++ )
    {
        for(int i=0; i <=6 ; i++ )
        {
            if(grid[w][i].isEmpty() == true)
            {
                std::cout << "I LEER " << " " ;
            }
            else if(grid[w][i].isEmpty() == false)
            {
                if(grid[w][i].getColor() == UserInterface::Color::RED )
                {
                    std::cout << "I ROT  " << " " ;
                }
                if(grid[w][i].getColor() == UserInterface::Color::YELLOW )
                {
                    std::cout << "I GELB " << " " ;
                }
            }
        }
        std::cout << "I" << std::endl;
    }
}

//wird jetzt hier im quasi main/ die cpp. von console_UI .cpp definiert implementiert
void Console_UI::notifyWinner(Color color)
{
    //std::cout<< "Der gewinner bin ich xD" <<std::endl;
    if( color == UserInterface::Color::RED)
    {
        std::cout<< "Spieler ROT ist der Gewinner" <<std::endl;
    }
    else if(color == UserInterface::Color::YELLOW)
    {
        std::cout<< "Spieler GELB ist der Gewinner" <<std::endl;
    }

}

void Console_UI::notifyDraw()
{
    std::cout<< "Unentschieden" <<std::endl;
}
