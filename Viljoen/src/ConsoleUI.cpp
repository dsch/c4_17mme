#include <iostream>
#include "../include/ConsoleUI.h"

using namespace std;

ConsoleUI::ConsoleUI()
{
    //ctor
}

ConsoleUI::~ConsoleUI()
{
    //dtor
}


UserInterface::ColumnType ConsoleUI::askPlayer(Color color) // code to ask for player to drop token
{
    int InputNumber;
    if(color == UserInterface::Color::RED) // checking whose turn it is
    {
        cout << endl << "Select Drop Position Player 1: ";
    }
    else
    {
        cout << endl << "Select Drop Position Player 2: ";
    }
    cin >> InputNumber;
    cout << endl;

    if (InputNumber == -1)
    {
        throw UserInterface::Abort();
    }


    return InputNumber-1; // returning the desired drop location
}

void ConsoleUI::updateBoard(const GridType& PlayingField) // code to display the playing field
{

    cout << "1 2 3 4 5 6 7" << endl;
    for(size_t i=0; i<PlayingField.size(); i++)
    {
        for(size_t j=0; j<PlayingField[i].size(); j++)
        {
            if (PlayingField[i][j].isEmpty())
            {
                cout << "O ";
            }
            else
            {
                if(PlayingField[i][j].getColor()==Color::RED) // outputting a visual for the selected fields
                {
                    cout << "R ";
                }
                else
                {
                    cout << "Y ";
                }
            }
        }
        cout << endl;
    }
}

void ConsoleUI::notifyWinner(Color color) // code to notify who won the game
{
    char EndGame;
    if (color == Color::RED)
    {
        cout << endl <<  "~#~#~#~#~ You Win Player 1 ~#~#~#~#~" << endl;
    }
    else
    {
        cout << endl << "~#~#~#~#~ You Win Player 2 ~#~#~#~#~" << endl;
    }

    cout << endl << "Enter any key to exit the Game! ";
    cin >> EndGame;
}

void ConsoleUI::notifyDraw() // notify if its draw
{
    cout << endl << "Welp, it's a DRAW!" << endl << endl;
}
