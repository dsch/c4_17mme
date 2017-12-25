#include "ConsoleInterface.h"
#include <iostream>

using namespace std;
ConsoleInterface::~ConsoleInterface() {}

void ConsoleInterface::updateBoard(const GridType& field)
{
    system("cls");

    int Row = 6; //UserInterface::RowType

    //Auflistung von oben nach unten
    /*cout<<" "<<endl;
    cout<<"0|1|2|3|4|5|6|  Column"<<endl;
    cout<<" "<<endl;

    for(int rowVariable=6; rowVariable>=1; rowVariable--)
    {
        for(int gridVariable=7; gridVariable>=1; gridVariable--)
        {

            if(field[Row-rowVariable][Grid-gridVariable].getColor() == UserInterface::Color::RED &&
                    field[Row-rowVariable][Grid-gridVariable].isEmpty() == false)
            {
              cout<< 'R';
            }

            else if(field[Row-rowVariable][Grid-gridVariable].getColor() == UserInterface::Color::YELLOW &&
               field[Row-rowVariable][Grid-gridVariable].isEmpty() == false)
            {
                cout<< 'Y';
            }

            else if(field[Row-rowVariable][Grid-gridVariable].isEmpty()==true || '0')
            {
                cout<< " ";
            }

            //cout<<" "<<gridVariable<<"GRI"; //To proof Variables
            //cout<<" "<<rowVariable<<"ROW";
            cout<<"|";
            if(gridVariable == 1)
            {
                cout<<"  Row  "<<Row-rowVariable<<endl;
            }
        }
    }
    cout<<" "<<endl;*/

    //Auflistung von unten nach oben
    cout<<"----------------------"<<endl;
    cout<<"|    Connect Four    |"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"1|2|3|4|5|6|7|  Column"<<endl;
    cout<<"                      "<<endl;

    for(int rowVariable = 1; rowVariable <= 6; rowVariable++)
    {
        for(int gridVariable = 1; gridVariable <= 7; gridVariable++)
        {

            if(field[rowVariable-1][gridVariable-1].getColor() == UserInterface::Color::YELLOW
                &&field[rowVariable-1][gridVariable-1].isEmpty() == false)
            {
                cout<< 'Y';
            }

            else if(field[rowVariable-1][gridVariable-1].getColor() == UserInterface::Color::RED
                    &&field[rowVariable-1][gridVariable-1].isEmpty() == false)
            {
                cout<< 'R';
            }

            else if(field[rowVariable-1][gridVariable-1].isEmpty()== true)
            {
                cout<< " ";
            }

            //cout<<" "<<gridVariable<<"GRI"; //To proof Variables
            //cout<<" "<<rowVariable<<"ROW";
            cout<<"|";
            if(gridVariable == 7)
            {
                cout<<"  Row  "<<Row-rowVariable+1<<endl;
            }
        }
    }
    cout<<" "<<endl;
}

UserInterface::ColumnType ConsoleInterface::askPlayer(Color color)
{
    int columnNumber = 0;
    int checkFlag = 1;

    cout<<" "<<endl;

    if ( color == Color::RED )    cout<< "Player (Red) => ";
    if ( color == Color::YELLOW ) cout<< "Player (Yellow) => ";

    cout<< "Type in column number: ";


    while(checkFlag == 1)
    {
        while(!(cin>> columnNumber))
        {
            string tmp;
            cin.clear();
            cin >> tmp;
            cout<<"Allowed numbers { 1, 2, 3, 4, 5, 6, 7 }: ";
            checkFlag = 1;
        }
        if(columnNumber <= 0 || columnNumber >= 8)
        {
            cout<<"Allowed numbers { 1, 2, 3, 4, 5, 6, 7 }: ";
            checkFlag = 1;
        }
        else checkFlag = 0;
    }
    cout<<"Saved"<<endl;

    return columnNumber - 1;
}

void ConsoleInterface::notifyWinner(Color color)
{
    cout<<" "<<endl;
    if ( color == Color::RED )    cout<< "The Winner is Red => Congratulations";
    if ( color == Color::YELLOW ) cout<< "The Winner is Yellow => Congratulations ";
    cout<<" "<<endl;
}

void ConsoleInterface::notifyDraw()
{
    cout<<" "<<endl;
    cout<<"Draw"<<endl;
}


