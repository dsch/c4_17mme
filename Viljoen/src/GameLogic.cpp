#include <iostream>
#include "../include/GameLogic.h"


using namespace std;

GameLogic::GameLogic(UserInterface& ui):PlayingField(), ui(ui)
{
    //ctor
}

GameLogic::~GameLogic()
{
    //dtor
}


bool GameLogic::CheckHorizontalWin()// check horizontal
{
    int WinHorizontalCounter = 0;

    for (int i=5; i>=0; i--)
    {
        for(int j=0; 6>j; j++)
        {
            if (!PlayingField[i][j].isEmpty() && !PlayingField[i][j+1].isEmpty())
            {
                if (WinHorizontalCounter==0)
                {
                    WinHorizontalCounter++;
                }

                if(PlayingField[i][j].getColor()==PlayingField[i][j+1].getColor())
                {
                    WinHorizontalCounter++;
                }
                else
                {
                    WinHorizontalCounter = 0;
                }

                if (WinHorizontalCounter>=4)
                {
                    WinHorizontalCounter = 0;
                    return true;
                }
            }
        }
        WinHorizontalCounter = 0;
    }
    return false;
}

bool GameLogic::CheckVerticalWin()// check vertical
{
    int WinVerticalCounter = 0;

    for (int j=0; j<=6; j++)
    {
        for(int i=5; i>0; i--)
        {
            if (!PlayingField[i][j].isEmpty() && !PlayingField[i-1][j].isEmpty())
            {
                if (WinVerticalCounter==0)
                {
                    WinVerticalCounter++;
                }

                if(PlayingField[i][j].getColor()==PlayingField[i-1][j].getColor())
                {
                    WinVerticalCounter++;
                }
                else
                {
                    WinVerticalCounter = 0;
                }

                if (WinVerticalCounter>=4)
                {
                    WinVerticalCounter = 0;
                    return true;
                }
            }
        }
        WinVerticalCounter = 0;
    }
    return false;
}

bool GameLogic::CheckDiagonalWin() // check diagonal
{
    int WinDiagonalCounter = 0;

    for (int j=0; j<=6; j++) // to the right
    {
        for(int i=5, q=0; i>0 && j+1+q<=6; i--,q++)
        {
            if (!PlayingField[i][j+q].isEmpty() && !PlayingField[i-1][j+1+q].isEmpty())
            {
                if (WinDiagonalCounter==0)
                {
                    WinDiagonalCounter++;
                }

                if(PlayingField[i][j+q].getColor()==PlayingField[i-1][j+1+q].getColor())
                {
                    WinDiagonalCounter++;
                }
                else
                {
                    WinDiagonalCounter = 0;
                }

                if (WinDiagonalCounter>=4)
                {
                    WinDiagonalCounter = 0;
                    return true;
                }
            }
        }
        WinDiagonalCounter = 0;
    }

   for (int j=0; j<=6; j++) // to the left
    {
        for(int i=5, q=0; i>0 && j-1-q>=0; i--,q++)
        {
            if (!PlayingField[i][j-q].isEmpty() && !PlayingField[i-1][j-1-q].isEmpty())
            {
                if (WinDiagonalCounter==0)
                {
                    WinDiagonalCounter++;
                }

                if(PlayingField[i][j-q].getColor()==PlayingField[i-1][j-1-q].getColor())
                {
                    WinDiagonalCounter++;
                }
                else
                {
                    WinDiagonalCounter = 0;
                }

                if (WinDiagonalCounter>=4)
                {
                    WinDiagonalCounter = 0;
                    return true;
                }
            }
        }
        WinDiagonalCounter = 0;
    }
    return false;
}


void GameLogic :: PlayGame() // game logic when GamePlay is called
{
    int DropPosition;
    int MoveCounter = 0;
    int PlayerCounter = 1;

    while(MoveCounter<42) // main game logic
    {
       ui.updateBoard(PlayingField); // displays the game field

       DropPosition = ui.askPlayer(UserInterface::Color(PlayerCounter-1)); // determine drop location, conforming to color definition in UI

        if (DropPosition>=0 && DropPosition<=6) // determine valid drop location
       {
            for(int i=5; i>=0; i--)
            {
                if(PlayingField[i][DropPosition].isEmpty()) // checking if the field is empty, if yes, slot it in, if no move up and check again
                {

                    if (PlayerCounter == 1) // swapping players and assigning a color to a field and checking for winner
                    {
                        PlayingField[i][DropPosition] = UserInterface::Color::RED;
                        if(CheckHorizontalWin() || CheckVerticalWin() || CheckDiagonalWin())
                       {
                           ui.updateBoard(PlayingField);
                           ui.notifyWinner(UserInterface::Color::RED);
                           MoveCounter = 43;
                       }
                        PlayerCounter = 2;
                    }
                    else
                    {
                        PlayingField[i][DropPosition] = UserInterface::Color::YELLOW;
                        if(CheckHorizontalWin() || CheckVerticalWin() || CheckDiagonalWin())
                       {
                           ui.updateBoard(PlayingField);
                           ui.notifyWinner(UserInterface::Color::YELLOW);
                           MoveCounter = 43;
                       }
                        PlayerCounter = 1;
                    }
                    MoveCounter ++;
                    break;// breaks for loop
                }
            }
        }
    }

    if (MoveCounter == 42) // draw
    {
        ui.updateBoard(PlayingField);
        ui.notifyDraw();
    }
}


