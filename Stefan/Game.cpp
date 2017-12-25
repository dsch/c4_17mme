#include "Game.h"

int Game::GewinnErmittlung(const UserInterface::GridType& grid)
{
    int spalte = 0;
    int zeile = 0;
    int gewinnRueckgabe = 0;

    //-------------VERTIKALUEBERPRUEFUNG
    for(spalte= 0; spalte <= 6; spalte++)
    {
        for(zeile = 0; zeile <= 2; zeile++)
        {
            if(grid[zeile][spalte].isEmpty() == false
                    && grid[zeile][spalte].getColor() == UserInterface::Color::RED
                    && grid[zeile+1][spalte].isEmpty() == false
                    && grid[zeile+1][spalte].getColor() == UserInterface::Color::RED
                    && grid[zeile+2][spalte].isEmpty() == false
                    && grid[zeile+2][spalte].getColor() == UserInterface::Color::RED
                    && grid[zeile+3][spalte].isEmpty() == false
                    && grid[zeile+3][spalte].getColor() == UserInterface::Color::RED )
            {
//                std::cout << "zeile = " << zeile << std::endl;
//                std::cout << "spalte = " << spalte << std::endl;
//                std::cout << "vertikal" << std::endl;
                ui.notifyWinner(ui.Color::RED);
                gewinnRueckgabe = 1;
                //std::cout << "rueckgabe" << gewinnRueckgabe << std::endl;
            }
            //  std::cout << "zeile = " << zeile << std::endl;

            if(grid[zeile][spalte].isEmpty() == false
                    && grid[zeile][spalte].getColor() == UserInterface::Color::YELLOW
                    && grid[zeile+1][spalte].isEmpty() == false
                    && grid[zeile+1][spalte].getColor() == UserInterface::Color::YELLOW
                    && grid[zeile+2][spalte].isEmpty() == false
                    && grid[zeile+2][spalte].getColor() == UserInterface::Color::YELLOW
                    && grid[zeile+3][spalte].isEmpty() == false
                    && grid[zeile+3][spalte].getColor() == UserInterface::Color::YELLOW )
            {
//                std::cout << "zeile = " << zeile << std::endl;
//                std::cout << "spalte = " << spalte << std::endl;
//                std::cout << "vertikal" << std::endl;
                ui.notifyWinner(ui.Color::YELLOW);
                gewinnRueckgabe = 2;
             //   std::cout << "rueckgabe" << gewinnRueckgabe << std::endl;
            }
        }
    }
    //-------------QUERUEBERPRUEFUNG
    for(zeile = 5; zeile >= 0; zeile--)
    {
        for(spalte= 0; spalte <= 3; spalte++)
        {
            if( grid[zeile][spalte].isEmpty() == false
                    && grid[zeile][spalte].getColor() == ui.Color::RED
                    && grid[zeile][spalte+1].isEmpty() == false
                    && grid[zeile][spalte+1].getColor() == ui.Color::RED
                    && grid[zeile][spalte+2].isEmpty() == false
                    && grid[zeile][spalte+2].getColor() == ui.Color::RED
                    && grid[zeile][spalte+3].isEmpty() == false
                    && grid[zeile][spalte+3].getColor() == ui.Color::RED )
            {
//                std::cout << "zeile = " << zeile << std::endl;
//                std::cout << "spalte = " << spalte << std::endl;
//                std::cout << "quer" << std::endl;
                ui.notifyWinner(ui.Color::RED);
                gewinnRueckgabe = 1;
        //        std::cout << "rueckgabe" << gewinnRueckgabe << std::endl;
            }
            if(grid[zeile][spalte].isEmpty() == false
                    && grid[zeile][spalte].getColor() == ui.Color::YELLOW
                    && grid[zeile][spalte+1].isEmpty() == false
                    && grid[zeile][spalte+1].getColor() == ui.Color::YELLOW
                    && grid[zeile][spalte+2].isEmpty() == false
                    && grid[zeile][spalte+2].getColor() == ui.Color::YELLOW
                    && grid[zeile][spalte+3].isEmpty() == false
                    && grid[zeile][spalte+3].getColor() == ui.Color::YELLOW )
            {
//                std::cout << "zeile = " << zeile << std::endl;
//                std::cout << "spalte = " << spalte << std::endl;
//                std::cout << "quer" << std::endl;
                ui.notifyWinner(ui.Color::YELLOW);
                gewinnRueckgabe = 2;
            //    std::cout << "rueckgabe" << gewinnRueckgabe << std::endl;
            }
        }
    }
    //-------------DIAGONAL VON LINKS UNTEN RECHTS RAUF
    // int durchgang =0;
    for(spalte = 0; spalte <= 3; spalte++)
    {
        for(zeile= 3; zeile <= 5; zeile++)
        {
            if( grid[zeile][spalte].isEmpty() == false
                    && grid[zeile][spalte].getColor() == ui.Color::RED
                    && grid[zeile-1][spalte+1].isEmpty() == false
                    && grid[zeile-1][spalte+1].getColor() == ui.Color::RED
                    && grid[zeile-2][spalte+2].isEmpty() == false
                    && grid[zeile-2][spalte+2].getColor() == ui.Color::RED
                    && grid[zeile-3][spalte+3].isEmpty() == false
                    && grid[zeile-3][spalte+3].getColor() == ui.Color::RED )
            {
//                std::cout << "zeile = " << zeile << std::endl;
//                std::cout << "spalte = " << spalte << std::endl;
//                std::cout << "diagonal links nach rechts" << std::endl;
                ui.notifyWinner(ui.Color::RED);
                gewinnRueckgabe = 1;
          //      std::cout << "rueckgabe" << gewinnRueckgabe << std::endl;
            }
            // std::cout << "spalte = " << spalte << std::endl;

            if( grid[zeile][spalte].isEmpty() == false
                    && grid[zeile][spalte].getColor() == ui.Color::YELLOW
                    && grid[zeile-1][spalte+1].isEmpty() == false
                    && grid[zeile-1][spalte+1].getColor() == ui.Color::YELLOW
                    && grid[zeile-2][spalte+2].isEmpty() == false
                    && grid[zeile-2][spalte+2].getColor() == ui.Color::YELLOW
                    && grid[zeile-3][spalte+3].isEmpty() == false
                    && grid[zeile-3][spalte+3].getColor() == ui.Color::YELLOW )
            {
//                std::cout << "zeile = " << zeile << std::endl;
//                std::cout << "spalte = " << spalte << std::endl;
//                std::cout << "diagonal links nach rechts" << std::endl;
                ui.notifyWinner(ui.Color::YELLOW);
                gewinnRueckgabe = 2;
           //     std::cout << "rueckgabe" << gewinnRueckgabe << std::endl;
            }
        }
    }
    //-------------DIAGONAL VON rechts UNTEN links RAUF
    for(spalte = 6; spalte >= 3; spalte--)
    {
        for(zeile= 3; zeile <= 5; zeile++)
        {
            if( grid[zeile][spalte].isEmpty() == false
                    && grid[zeile][spalte].getColor() == ui.Color::RED
                    && grid[zeile-1][spalte-1].isEmpty() == false
                    && grid[zeile-1][spalte-1].getColor() == ui.Color::RED
                    && grid[zeile-2][spalte-2].isEmpty() == false
                    && grid[zeile-2][spalte-2].getColor() == ui.Color::RED
                    && grid[zeile-3][spalte-3].isEmpty() == false
                    && grid[zeile-3][spalte-3].getColor() == ui.Color::RED )
            {
//                std::cout << "zeile = " << zeile << std::endl;
//                std::cout << "spalte = " << spalte << std::endl;
//                std::cout << "diagonal rechts nach lanks" << std::endl;
                ui.notifyWinner(ui.Color::RED);
                gewinnRueckgabe = 1;
            //    std::cout << "rueckgabe" << gewinnRueckgabe << std::endl;
            }
            // std::cout << "spalte = " << spalte << std::endl;

            if( grid[zeile][spalte].isEmpty() == false
                    && grid[zeile][spalte].getColor() == ui.Color::YELLOW
                    && grid[zeile-1][spalte-1].isEmpty() == false
                    && grid[zeile-1][spalte-1].getColor() == ui.Color::YELLOW
                    && grid[zeile-2][spalte-2].isEmpty() == false
                    && grid[zeile-2][spalte-2].getColor() == ui.Color::YELLOW
                    && grid[zeile-3][spalte-3].isEmpty() == false
                    && grid[zeile-3][spalte-3].getColor() == ui.Color::YELLOW )
            {
//                std::cout << "zeile = " << zeile << std::endl;
//                std::cout << "spalte = " << spalte << std::endl;
//                std::cout << "diagonal rechts nach links" << std::endl;
                ui.notifyWinner(ui.Color::YELLOW);
                gewinnRueckgabe = 2;
               // std::cout << "rueckgabe" << gewinnRueckgabe << std::endl;
            }
        }
    }
    //-------------UNENTSCHIEDEN
    int zaehler = 0;
    for(spalte=0; spalte<=6; spalte++)
    {
        if(grid[0][spalte].isEmpty() == false)
        {
            zaehler++;
        }
    }
    if(zaehler >= 7)
    {
        ui.notifyDraw();
        gewinnRueckgabe = 3; //3
       // std::cout << "rueckgabe" << gewinnRueckgabe << std::endl;
    }

   // std::cout << "rueckgabe" << gewinnRueckgabe << std::endl;

    return gewinnRueckgabe;

}

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
    UserInterface::GridType SpielFeld ;


    int auswahlSpalte_GELB = 0;
    int auswahlSpalte_ROT = 0;
    int laufVar_Reihe = 5;
    int durchlauf =0;
    ui.updateBoard(SpielFeld);

    while(1)
    {

        auswahlSpalte_ROT = ui.askPlayer(ui.Color::RED);        //wird mit rot definiert
        if(SpielFeld[laufVar_Reihe][auswahlSpalte_ROT].isEmpty() == false)
        {
            do
            {
                laufVar_Reihe--;
            }
            while(SpielFeld[laufVar_Reihe][auswahlSpalte_ROT].isEmpty() == false);
            SpielFeld [laufVar_Reihe][auswahlSpalte_ROT] = ui.Color::RED;
        }
        else if(SpielFeld[laufVar_Reihe][auswahlSpalte_ROT].isEmpty() == true)
        {
            SpielFeld [laufVar_Reihe][auswahlSpalte_ROT] = ui.Color::RED;
        }
        //system("cls");
        ui.updateBoard(SpielFeld);
        durchlauf = GewinnErmittlung(SpielFeld);
        if(durchlauf > 0 )
        {
            break;
        }

//--------------------------------------------------------------------------

        laufVar_Reihe = 5;
        auswahlSpalte_GELB = ui.askPlayer(ui.Color::YELLOW);
        if(SpielFeld[laufVar_Reihe][auswahlSpalte_GELB].isEmpty() == false)
        {
            do
            {
                laufVar_Reihe--;
            }
            while(SpielFeld[laufVar_Reihe][auswahlSpalte_GELB].isEmpty() == false);
            SpielFeld [laufVar_Reihe][auswahlSpalte_GELB] = ui.Color::YELLOW;
        }
        else if(SpielFeld[laufVar_Reihe][auswahlSpalte_GELB].isEmpty() == true)
        {
            SpielFeld [laufVar_Reihe][auswahlSpalte_GELB] = ui.Color::YELLOW;
        }
        laufVar_Reihe = 5;

        //system("cls");
        ui.updateBoard(SpielFeld);
        durchlauf = GewinnErmittlung(SpielFeld);
        if(durchlauf > 0 )
        {
            break;
        }
    }
}

