#include "Game.h"
#include <iostream>

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

bool Game::checkBoard(char gridRow,char gridCol)
{



  UserInterface::Color color=  grid[gridRow][gridCol].getColor();

    int rowStart=gridRow-3;
    int rowEnd=gridRow+3;
    int colStart=gridCol-3;
    int colEnd=gridCol+3;
    int i,j;

    if(rowStart<0) rowStart=0;
    if(rowEnd>5) rowEnd=5;

    if(colStart<0) colStart=0;
    if(colEnd>6) colEnd=6;


    //Vertical Check
    j=gridCol;
    for(char r=gridRow; r<=rowEnd-3; r++)
    {
        i=r;
        while ((!grid[i][j].isEmpty()) && (grid[i][j].getColor()==color)&&(i<r+4)) {i++;}
        if(i==r+4) return true;
    }

    // Horizontal Check
    i=gridRow;
    for(char c=colStart; c<=colEnd-3; c++)
    {
        j=c;
        while ((!grid[i][j].isEmpty()) && (grid[i][j].getColor()==color)&&(j<c+4)) {j++;}
        if(j==c+4) return true;
    }

    // Diagonal Right Check
    i=gridRow;
    for(char c=colStart; c<=colEnd-3; c++)
    {
        j=c;
        while ((!grid[i][j].isEmpty()) && (grid[i][j].getColor()==color)&&(j<c+4)) {i++; j++;}
        if(j==c+4) return true;
    }

    // Diagonal Left Check
    i=gridRow;
    for(char c=colEnd; c>=colStart+3; c--)
    {
        j=c;
        while ((!grid[i][j].isEmpty()) && (grid[i][j].getColor()==color)&&(j>c-4)) {i++; j--;}
        if(j==c-4)  return true;
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
       selectedColumn--;

       currentRow=getEmptyCell(selectedColumn);

       setBoard(CurrentPlayer,currentRow,selectedColumn);
       if (checkBoard(currentRow,selectedColumn)) {ui.updateBoard(grid); ui.notifyWinner(CurrentPlayer); gameRunning=false;}

        if(CurrentPlayer==UserInterface::Color::RED) CurrentPlayer=UserInterface::Color::YELLOW;
        else CurrentPlayer=UserInterface::Color::RED;






       if(selectedColumn=='0') {gameRunning=false; std::cout << "\n" <<  abort.what()<< "\n"; }

    }

    //Ablauf ungefähre Idee:
    // 1. leeres Spielfeld initialisieren
    // 2. aktueller (erster) Spieler: welche Spalte kommt Spielstein hin?
    //
    // 3. Hat wer gewonnen? Ist es unentschieden? -else: Spieler2
    // ---> 2. 3. 2. 3. ...
 //   ui.askPlayer(UserInterface::Color::RED);

}
