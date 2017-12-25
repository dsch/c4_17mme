#include "Game.h"
#include <iostream>
#include <fstream>


// im ganzen game kann man nur das machen was im UserInterface definiert ist

Game::Game(UserInterface& ui) : ui(ui)
{
    CurrentPlayer= UserInterface::Color::RED;
    //ctor
}

Game::~Game()
{
    //dtor
}
int Game::getEmptyCell(char column)
{
  char row=6;
  do
    {
        row--;
        if(grid[row][column].isEmpty()) return row;

    } while ( !row==0 );
    return -1;

}

void Game::setBoard(UserInterface::Color color, char row,char column)
{
  grid[row][column]=color;
}

bool Game::test( char color, char gridRow,char gridCol, bool expectedValue)
{

    if (color=='R') CurrentPlayer= UserInterface::Color::RED;
    if (color=='Y') CurrentPlayer= UserInterface::Color::YELLOW;

    setBoard(CurrentPlayer,gridRow,gridCol);
    bool testResult = checkBoard(gridRow,gridCol);
    grid[gridRow][gridCol].empty=true;

    std::cout <<"test("<<"'"<<color<<"',"<<gridRow+1<<","<<gridCol+1<<")"<<" : ";

    if (testResult==expectedValue) {std::cout << "Passed. \n"; return true;} else { std::cout << "failed. \n";  return false;}

}

void Game::loadBoard(std::string filename)
{
    using namespace std;

    ifstream file(filename);
    if(file.is_open())
    {
        string ColumnData;

        for(int i = 0; i <= 5; ++i)
        {
            file >> ColumnData;
            for(int j = 0; j <= 6; ++j)
            {
               if (ColumnData[j]=='R') setBoard( UserInterface::Color::RED, i,j);
               if (ColumnData[j]=='Y') setBoard( UserInterface::Color::YELLOW, i,j);

            }

        }

        ui.updateBoard(grid);
    }

}

bool Game::checkBoard(char gridRow,char gridCol)
{



  UserInterface::Color color=  grid[gridRow][gridCol].getColor();

    int rowStart=gridRow-3;
    int rowEnd=gridRow+3;
    int colStart=gridCol-3;
    int colEnd=gridCol+3;
    int i,j;
    int cellSet = 4;

    if(rowStart<0) rowStart=0;
    if(rowEnd>5) rowEnd=5;

    if(colStart<0) colStart=0;
    if(colEnd>6) colEnd=6;


    //Vertical Check
        j=gridCol;
        i=gridRow;
        while ((grid[i][j].getColor()==color)&&(i<gridRow+cellSet)&&(i<6)) {i++;}
        if(i==gridRow+cellSet) return true;

    // Horizontal Check
    i=gridRow;
    for(char c=colStart; c<=gridCol; c++)
    {
        j=c;
        while ((!grid[i][j].isEmpty()) && (grid[i][j].getColor()==color)&&(j<c+cellSet)&&(j<7)) {j++;}
        if(j==c+cellSet) return true;
    }

    // Diagonal Right Check
    i=gridRow;
    for(char c=colStart; c<=colEnd-3; c++)
    {
        j=c;
        while ((!grid[i][j].isEmpty()) && (grid[i][j].getColor()==color)&&(j<c+cellSet)) {i++; j++;}
        if(j==c+cellSet) return true;
    }

    // Diagonal Left Check
    i=gridRow;
    for(char c=colEnd; c>=colStart+3; c--)
    {
        j=c;
        while ((!grid[i][j].isEmpty()) && (grid[i][j].getColor()==color)&&(j>c-cellSet)) {i++; j--;}
        if(j==c-cellSet)  return true;
    }


    return false;
}

//definieren was gemacht wird wenn play() aufgerufen wird
void Game::play()
{
    bool gameRunning=true;
    char selectedColumn;
    char currentRow;
    UserInterface::Abort abort;


    while(gameRunning) {

       ui.updateBoard(grid);


       selectedColumn = ui.askPlayer(CurrentPlayer);
       if(selectedColumn==9) {gameRunning=false; std::cout << "\n" <<  abort.what()<< "\n"; }

       selectedColumn--;

       currentRow=getEmptyCell(selectedColumn);

       setBoard(CurrentPlayer,currentRow,selectedColumn);
       if (checkBoard(currentRow,selectedColumn)) {ui.updateBoard(grid); ui.notifyWinner(CurrentPlayer); gameRunning=false;}

        if(CurrentPlayer==UserInterface::Color::RED) CurrentPlayer=UserInterface::Color::YELLOW;
        else CurrentPlayer=UserInterface::Color::RED;



    }

    //Ablauf ungefähre Idee:
    // 1. leeres Spielfeld initialisieren
    // 2. aktueller (erster) Spieler: welche Spalte kommt Spielstein hin?
    //
    // 3. Hat wer gewonnen? Ist es unentschieden? -else: Spieler2
    // ---> 2. 3. 2. 3. ...
 //   ui.askPlayer(UserInterface::Color::RED);

}
