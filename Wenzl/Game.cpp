#include "Game.h"

bool Game::Unentschieden(const UserInterface::GridType& grid)
{
int row = 5;
int zaehler = 0;

    for(int col=0; col<=6; col++)
        {
        if(grid[row][col].isEmpty() == false)
            {
                zaehler++;
            }
        }
        if(zaehler >= 7)
            {
                ui.notifyDraw();
                return true;
            }
    return false;
}

int Game::Gewonnen(const UserInterface::GridType& grid)
{
int rueckgabe = 0;

    for(int row=0; row<=7; row++)
    {
        for(int col=0; col<=3; col++)
        {
            if((grid[row][col].isEmpty() == false)&&\
                    (grid[row][col].getColor() == UserInterface::Color::RED)&&\
                    (grid[row][col+1].getColor() == UserInterface::Color::RED)&&\
                    (grid[row][col+1].isEmpty() == false)&&\
                    (grid[row][col+2].getColor() == UserInterface::Color::RED)&&\
                    (grid[row][col+2].isEmpty() == false)&&\
                    (grid[row][col+3].getColor() == UserInterface::Color::RED)&&\
                    (grid[row][col+3].isEmpty() == false))
            {
                ui.notifyWinner(ui.Color::RED);
                rueckgabe = 1;
            }
            if((grid[row][col].isEmpty() == false)&&\
                    (grid[row][col].getColor() == UserInterface::Color::YELLOW)&&\
                    (grid[row][col+1].getColor() == UserInterface::Color::YELLOW)&&\
                    (grid[row][col+1].isEmpty() == false)&&\
                    (grid[row][col+2].getColor() == UserInterface::Color::YELLOW)&&\
                    (grid[row][col+2].isEmpty() == false)&&\
                    (grid[row][col+3].getColor() == UserInterface::Color::YELLOW)&&\
                    (grid[row][col+3].isEmpty() == false))
            {
                ui.notifyWinner(ui.Color::YELLOW);
                rueckgabe = 1;

            }
        }
    }


    for(int col=0; col<=6; col++) //vertikale Gewinnbedingung
    {
        for(int row=0; row<=2; row++)
        {
            if((grid[row][col].isEmpty() == false)&&\
                    (grid[row][col].getColor() == UserInterface::Color::RED)&&\
                    (grid[row+1][col].getColor() == UserInterface::Color::RED)&&\
                    (grid[row+1][col].isEmpty() == false)&&\
                    (grid[row+2][col].getColor() == UserInterface::Color::RED)&&\
                    (grid[row+2][col].isEmpty() == false)&&\
                    (grid[row+3][col].getColor() == UserInterface::Color::RED)&&\
                    (grid[row+3][col].isEmpty() == false))
            {
                ui.notifyWinner(ui.Color::RED);
                rueckgabe = 1;
            }
            if((grid[row][col].isEmpty() == false)&&\
                    (grid[row][col].getColor() == UserInterface::Color::YELLOW)&&\
                    (grid[row+1][col].getColor() == UserInterface::Color::YELLOW)&&\
                    (grid[row+1][col].isEmpty() == false)&&\
                    (grid[row+2][col].getColor() == UserInterface::Color::YELLOW)&&\
                    (grid[row+2][col].isEmpty() == false)&&\
                    (grid[row+3][col].getColor() == UserInterface::Color::YELLOW)&&\
                    (grid[row+3][col].isEmpty() == false))
            {
                ui.notifyWinner(ui.Color::YELLOW);
                rueckgabe = 1;
            }
        }
    }


    for(int col=0; col<=6; col++) //Schraeg rechts nach oben - Gewinnbedningung
    {
        for(int row=0; row<=2; row++)
        {
            if((grid[row][col].isEmpty() == false)&&\
                    (grid[row][col].getColor() == UserInterface::Color::RED)&&\
                    (grid[row+1][col+1].getColor() == UserInterface::Color::RED)&&\
                    (grid[row+1][col+1].isEmpty() == false)&&\
                    (grid[row+2][col+2].getColor() == UserInterface::Color::RED)&&\
                    (grid[row+2][col+2].isEmpty() == false)&&\
                    (grid[row+3][col+3].getColor() == UserInterface::Color::RED)&&\
                    (grid[row+3][col+3].isEmpty() == false))
            {
                ui.notifyWinner(ui.Color::RED);
                rueckgabe = 1;
            }
            if((grid[row][col].isEmpty() == false)&&\
                    (grid[row][col].getColor() == UserInterface::Color::YELLOW)&&\
                    (grid[row+1][col+1].getColor() == UserInterface::Color::YELLOW)&&\
                    (grid[row+1][col+1].isEmpty() == false)&&\
                    (grid[row+2][col+2].getColor() == UserInterface::Color::YELLOW)&&\
                    (grid[row+2][col+2].isEmpty() == false)&&\
                    (grid[row+3][col+3].getColor() == UserInterface::Color::YELLOW)&&\
                    (grid[row+3][col+3].isEmpty() == false))
            {
                ui.notifyWinner(ui.Color::YELLOW);
                rueckgabe = 1;
            }
        }
    }


    for(int col=3; col<=6; col++) // schräg links nach oben - Gewinnbedingung
    {
        for(int row=7; row>=0; row--)
        {
            if((grid[row][col].isEmpty() == false)&&\
                    (grid[row][col].getColor() == UserInterface::Color::RED)&&\
                    (grid[row+1][col-1].getColor() == UserInterface::Color::RED)&&\
                    (grid[row+1][col-1].isEmpty() == false)&&\
                    (grid[row+2][col-2].getColor() == UserInterface::Color::RED)&&\
                    (grid[row+2][col-2].isEmpty() == false)&&\
                    (grid[row+3][col-3].getColor() == UserInterface::Color::RED)&&\
                    (grid[row+3][col-3].isEmpty() == false))
            {
                ui.notifyWinner(ui.Color::RED);
                rueckgabe = 1;
            }
            if((grid[row][col].isEmpty() == false)&&\
                    (grid[row][col].getColor() == UserInterface::Color::YELLOW)&&\
                    (grid[row+1][col-1].getColor() == UserInterface::Color::YELLOW)&&\
                    (grid[row+1][col-1].isEmpty() == false)&&\
                    (grid[row+2][col-2].getColor() == UserInterface::Color::YELLOW)&&\
                    (grid[row+2][col-2].isEmpty() == false)&&\
                    (grid[row+3][col-3].getColor() == UserInterface::Color::YELLOW)&&\
                    (grid[row+3][col-3].isEmpty() == false))
                {
                ui.notifyWinner(ui.Color::YELLOW);
                rueckgabe = 1;
                }
        }
    }
    if (rueckgabe == 1){
        return 1;
    }
    else return 0;
}



Game::Game(UserInterface& ui) : ui(ui)
{
    //ctor
}

Game::~Game()
{
    //dtor
}


void Game::play() //definieren was play() macht
{
    UserInterface::GridType SpielFeld;

    unsigned int colNow;

    UserInterface::RowType row;
    UserInterface::GridType grid;

    int Reihe = 0;
    int run =1;

    updateBoard(SpielFeld);

    while (run)
    {
        Reihe = 0;
        colNow = ui.askPlayer(ui.Color::RED);
        while (SpielFeld[Reihe][colNow].isEmpty() == false)
        {
            Reihe++;
            if(Reihe >=6)
                {
                colNow = ui.askPlayer(ui.Color::RED);
                Reihe = 0;
                }
        }

        SpielFeld[Reihe][colNow] = (ui.Color::RED);
        updateBoard(SpielFeld);
        run = (Gewonnen(SpielFeld) == 0) && !Unentschieden(SpielFeld);

        if (run)
        {
            Reihe = 0;
            colNow = ui.askPlayer(ui.Color::YELLOW);
            while (SpielFeld[Reihe][colNow].isEmpty() == false) {
                Reihe++;
                if (Reihe >= 6) {

                    colNow = ui.askPlayer(ui.Color::YELLOW);

                    Reihe = 0;
                }
            }
            SpielFeld[Reihe][colNow] = (ui.Color::YELLOW);
            updateBoard(SpielFeld);

            run = (Gewonnen(SpielFeld) == 0) && !Unentschieden(SpielFeld);
        }
    }
}

void Game::updateBoard(const UserInterface::GridType& SpielFeld)
{
    UserInterface::GridType flipped;
    for (std::size_t i = 0; i<6; i++)
    {
        flipped[5 - i] = SpielFeld[i];
    }
    ui.updateBoard(flipped);
}