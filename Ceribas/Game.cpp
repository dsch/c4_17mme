#include "Game.h"
#include <iostream>
#include <fstream>

Game::Game(UserInterface& ui) : ui(ui)
{
    CurrentPlayer= UserInterface::Color::RED;
    //nicht notwendig.
}

Game::~Game()
{
    //nicht notwendig.
}
int Game::getEmptyCell(char column)
{
  char row=6;
  do
    {
        row--;
        if(grid[row][column].isEmpty()) return row;

    } while ( row>0 );
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
    //grid[gridRow][gridCol].empty=true;

    std::cout <<"Getestet wird auf dem obigem Feld folgendes Muster -->("<<"'"<<color<<"',"<<gridRow+1<<","<<gridCol+1<<")"<<" : ";

    if (testResult==expectedValue) {std::cout << "Der folgende Test war erfolgreich. \n"; return true;} else { std::cout << "Test nicht bestanden. \n";  return false;}
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

    //Vertikale Überprüfung
        j=gridCol;
        i=gridRow;
        while ((grid[i][j].getColor()==color)&&(i<gridRow+cellSet)&&(i<6)) {i++; if (i>5) break;}
        if(i==gridRow+cellSet) return true;

    //Horizontale Überprüfung
    i=gridRow;
    for(char c=colStart; c<=gridCol; c++)
    {
        j=c;
        while ((!grid[i][j].isEmpty()) && (grid[i][j].getColor()==color)&&(j<c+cellSet)&&(j<7)) {j++;}
        if(j==c+cellSet) return true;
    }

    // Diagonale Überprüfung
    i=gridRow;
    for(char c=colStart; c<=colEnd-3; c++)
    {
        j=c;
        while ((!grid[i][j].isEmpty()) && (grid[i][j].getColor()==color)&&(j<c+cellSet)) {i++; j++; if (i>5) break;}
        if(j==c+cellSet) return true;
    }

    // Diagonale Überprüfung links
    i=gridRow;
    for(char c=colEnd; c>=colStart+3; c--)
    {
        j=c;
        while ((!grid[i][j].isEmpty()) && (grid[i][j].getColor()==color)&&(j>c-cellSet)) {i++; j--; if (i>5) break;}
        if(j==c-cellSet)  return true;
    }


    return false;
}

//Spiel LOGIK
void Game::play()
{
    bool gameRunning=true;
    char selectedColumn;
    char currentRow;
    UserInterface::Abort abort;

    while(gameRunning) {

       ui.updateBoard(grid);

       selectedColumn = ui.askPlayer(CurrentPlayer);
       if(selectedColumn==-1) {gameRunning=false; std::cout << "\n" <<  abort.what()<< "\n"; }
       else {
       currentRow=getEmptyCell(selectedColumn);

       setBoard(CurrentPlayer,currentRow,selectedColumn);
       if (checkBoard(currentRow,selectedColumn)) {ui.updateBoard(grid); ui.notifyWinner(CurrentPlayer); gameRunning=false;}

       if(CurrentPlayer==UserInterface::Color::RED) CurrentPlayer=UserInterface::Color::YELLOW;
       else CurrentPlayer=UserInterface::Color::RED;
       }
    }

}
