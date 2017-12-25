#include "Game.h"
#include "stdlib.h"
#include "iostream"

#define WINNER 4
#define MAXIMUMOFDISK 42

Game::Game(UserInterface& ui) : ui(ui)
{
    //ctor
}

Game::~Game()
{
    //dtor
}

void Game::updateBoard() {
    UserInterface::GridType flip_grid;
    for (std::size_t i=0; i<6; i++)
    {
        flip_grid[i] = grid[5-i];
    }
    ui.updateBoard(flip_grid);
}

void Game::playGame()
{
    bool gameRunning = true;
    int decisionColumn = 0;
    int player = RED;           //0 = RED; 1=YELLOW;
    int actualRow = 0;
    int winnerVertikal = 0;
    int winnerHorizontal = 0;
    int winnerLeftDiagonal = 0;
    int winnerRightDiagonal = 0;
    int diskCounter = 0;

    while(gameRunning)
    {
        updateBoard();

        decisionColumn = changeBetweenPlayer(player);

        actualRow = searchFreeRow(decisionColumn, player);

        player = writeInField(actualRow,decisionColumn,player);

        diskCounter ++;

        winnerVertikal = checkVertikalWinner(actualRow,decisionColumn,player);
        winnerHorizontal = checkHorizontalWinner(actualRow,player);
        winnerLeftDiagonal = checkDiagonalLeftWinner();
        winnerRightDiagonal = checkDiagonalRightWinner();

        gameRunning = checkIfDraw(diskCounter);

        if((winnerVertikal==WINNER) || (winnerHorizontal == WINNER) || (winnerLeftDiagonal ==WINNER) || (winnerRightDiagonal==WINNER))
        {
            gameRunning = outputWinner(player);
        }

        /*if(decisionColumn == 'exit')
        {
            gameRunning=false;
            std::cout<<"\n"<<abort.what()<<"\n";
        }*/

    }
}


int Game::changeBetweenPlayer(int player)   //Ständiges welches zwischen Rot und Gelb, es beginnt immer Rot
{
    int choosenColumn = 0;

    if(player == RED)
    {
        choosenColumn = ui.askPlayer(UserInterface::Color::RED);    //Frage den Roten-Spieler in welche Spalte er setzen will
    }

    else if(player == YELLOW)
    {
        choosenColumn = ui.askPlayer(UserInterface::Color::YELLOW);     //Frage den Gelben-Spieler in welche Spalte er setzen will
    }
    return choosenColumn;
}


int Game::searchFreeRow(int columnVariable,int player) //Überprüfung in welcher Reihe ein freies Feld existiert
{
    int runThrewRows = 0;
    int newRow = 0;

    for(runThrewRows=0; runThrewRows < 6; runThrewRows++)
    {
             if(grid[runThrewRows][columnVariable].isEmpty()==true)
             {
                 newRow = runThrewRows;
                 break;
             }
    }
    return newRow;
}


int Game::writeInField(int emptyRow,int columnToWrite, int player)  //Setzen der Disk abhängig vom Spieler
{
    switch(player)
    {
        case YELLOW:     grid[emptyRow][columnToWrite]=ui.Color::YELLOW; //field[Reihe][Spalte]
                    player = RED;   
                    break;

        case RED:     grid[emptyRow][columnToWrite]=ui.Color::RED;    //field[Reihe][Spalte]
                    player = YELLOW;   
                    break;
    }
    return player;
}


int Game::checkVertikalWinner(int row, int column, int player)
{
    int runningVariable = row;
    int lockRed = 0;
    int lockYellow = 0;
    int vertikalWinnerCounter = 0;

    if(player == YELLOW) //RED
    {
        lockYellow = 1;
    }
    else if(player == RED) //YELLOW
    {
        lockRed = 1;
    }

    while(runningVariable >= 0)
    {
        if(vertikalWinnerCounter == WINNER)
        {
            break;
        }
        else if(grid[runningVariable][column].getColor()==ui.Color::RED && lockRed == 0)
        {
            vertikalWinnerCounter += 1;
        }
        else if(grid[runningVariable][column].getColor()==ui.Color::YELLOW && lockYellow == 0)
        {
            vertikalWinnerCounter += 1;
        }

        else vertikalWinnerCounter = 0;

        runningVariable--;
    }

    lockRed = 0;
    lockYellow = 0;

    return vertikalWinnerCounter;
}


int Game::checkHorizontalWinner(int row, int player)
{
    int runningVariable = 1;
    int horizontalCounter = 0;
    int lockRed = 0;
    int lockYellow = 0;

    if(player==YELLOW) //RED
    {
        lockYellow =1;
    }
    else if(player == RED) //YELLOW
    {
        lockRed=1;
    }

    while(runningVariable <=7)      //Für ein aufsteigendes Spielfeld
    {
        if(horizontalCounter ==4)
        {
            break;
        }
        else if(grid[row][runningVariable].isEmpty()==true)
        {
             horizontalCounter = 0;
        }
        else if(grid[row][runningVariable].getColor()==UserInterface::Color::RED && lockRed == 0 )//&& grid[runningVariable][column].isEmpty() ==false)
        {
            horizontalCounter += 1;
        }
        else if(grid[row][runningVariable].getColor()==UserInterface::Color::YELLOW && lockYellow == 0) //&& grid[runningVariable][column].isEmpty() ==false)
        {
            horizontalCounter += 1;
        }
        else horizontalCounter = 0;

        runningVariable++;
    }

    lockRed = 0;
    lockYellow = 0;

    return horizontalCounter;
}


int Game::checkDiagonalLeftWinner()//int row)
{
    int diagonalCounter= 0;

    for(int runningColumn = 0; runningColumn < 4; runningColumn++)
    {
        //std::cout<<"for1"<<std::endl;

        for(int runningRow = 3; runningRow < 6; runningRow++)
        {
            //std::cout<<"for2"<<std::endl;
            if( grid[runningRow][runningColumn].isEmpty() == false
                    && grid[runningRow][runningColumn].getColor() == ui.Color::RED
                    && grid[runningRow-1][runningColumn+1].isEmpty() == false
                    && grid[runningRow-1][runningColumn+1].getColor() == ui.Color::RED
                    && grid[runningRow-2][runningColumn+2].isEmpty() == false
                    && grid[runningRow-2][runningColumn+2].getColor() == ui.Color::RED
                    && grid[runningRow-3][runningColumn+3].isEmpty() == false
                    && grid[runningRow-3][runningColumn+3].getColor() == ui.Color::RED )
            {
                //std::cout<<"ich bin im if"<<std::endl;
                diagonalCounter = WINNER;
                break;
            }


            if( grid[runningRow][runningColumn].isEmpty() == false
                    && grid[runningRow][runningColumn].getColor() == ui.Color::YELLOW
                    && grid[runningRow-1][runningColumn+1].isEmpty() == false
                    && grid[runningRow-1][runningColumn+1].getColor() == ui.Color::YELLOW
                    && grid[runningRow-2][runningColumn+2].isEmpty() == false
                    && grid[runningRow-2][runningColumn+2].getColor() == ui.Color::YELLOW
                    && grid[runningRow-3][runningColumn+3].isEmpty() == false
                    && grid[runningRow-3][runningColumn+3].getColor() == ui.Color::YELLOW )
            {
                diagonalCounter = WINNER;
                break;
            }
        }
    }
    return diagonalCounter;

    //first Version
    /*while(runningRow >= 0)
    {
        if(diagonalCounter ==4)
        {
            break;
        }
        else if(grid[runningRow][runningColumn].isEmpty()==true)
        {
            diagonalCounter = 0;
        }
        else if(grid[runningRow][runningColumn].getColor()==UserInterface::Color::RED && lockRed == 0 )//&& grid[runningVariable][column].isEmpty() ==false)
        {
            diagonalCounter += 1;
        }
        else if(grid[runningRow][runningColumn].getColor()==UserInterface::Color::YELLOW && lockYellow == 0) //&& grid[runningVariable][column].isEmpty() ==false)
        {
            diagonalCounter += 1;
        }
        else diagonalCounter = 0;

        runningColumn--;
        runningRow--;
    }*/
}


int Game::checkDiagonalRightWinner()
{
    int diagonalCounter = 0;

    for(int runningColumn = 7; runningColumn >= 4; runningColumn--)
    {

        for(int runningRow = 3; runningRow < 6; runningRow++)
        {

            if( grid[runningRow][runningColumn].isEmpty() == false
                    && grid[runningRow][runningColumn].getColor() == ui.Color::RED
                    && grid[runningRow-1][runningColumn-1].isEmpty() == false
                    && grid[runningRow-1][runningColumn-1].getColor() == ui.Color::RED
                    && grid[runningRow-2][runningColumn-2].isEmpty() == false
                    && grid[runningRow-2][runningColumn-2].getColor() == ui.Color::RED
                    && grid[runningRow-3][runningColumn-3].isEmpty() == false
                    && grid[runningRow-3][runningColumn-3].getColor() == ui.Color::RED )
            {
                diagonalCounter = WINNER;
                break;
            }


            if( grid[runningRow][runningColumn].isEmpty() == false
                    && grid[runningRow][runningColumn].getColor() == ui.Color::YELLOW
                    && grid[runningRow-1][runningColumn-1].isEmpty() == false
                    && grid[runningRow-1][runningColumn-1].getColor() == ui.Color::YELLOW
                    && grid[runningRow-2][runningColumn-2].isEmpty() == false
                    && grid[runningRow-2][runningColumn-2].getColor() == ui.Color::YELLOW
                    && grid[runningRow-3][runningColumn-3].isEmpty() == false
                    && grid[runningRow-3][runningColumn-3].getColor() == ui.Color::YELLOW )
            {
                diagonalCounter = WINNER;
                break;
            }
        }
    }

    return diagonalCounter;

    //first Version
    /*while(runningRow >=1)
    {
        if(diagonalCounter ==4)
        {
            break;
        }
        else if(grid[runningRow][runningColumn].isEmpty()==true)
        {
            diagonalCounter = 0;
        }
        else if(grid[runningRow][runningColumn].getColor()==UserInterface::Color::RED && lockRed == 0 )//&& grid[runningVariable][column].isEmpty() ==false)
        {
            diagonalCounter += 1;
        }
        else if(grid[runningRow][runningColumn].getColor()==UserInterface::Color::YELLOW && lockYellow == 0) //&& grid[runningVariable][column].isEmpty() ==false)
        {
            diagonalCounter += 1;
        }
        else diagonalCounter = 0;

        runningColumn++;
        runningRow--;
    }*/
}


bool Game::outputWinner(int player)
{
    bool runningGame = true;

    updateBoard();

    if(player != RED) //This is inverted
    {
        ui.notifyWinner(UserInterface::Color::RED);
          runningGame =false;
    }
    else if(player != YELLOW)
    {
        ui.notifyWinner(UserInterface::Color::YELLOW);
          runningGame =false;
    }

    return runningGame;
}


bool Game::checkIfDraw(int settedDisks)
{
    bool localVariable = true;

    if(settedDisks == 42)
    {
        updateBoard();
        ui.notifyDraw();
        localVariable = false;
    }
    return localVariable;
}

