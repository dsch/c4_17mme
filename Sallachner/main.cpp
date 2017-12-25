#include <iostream>
#include <array>
#include <stdlib.h>
#include<string>
#include"UserInterface.h"
#include"Console.h"
#include"Logic.h"
#include"gui/Gui.h"


void play_game(UserInterface &ui);

using namespace std;

int main(int argc, char** argv)
{
    if(argc == 2)
    {
        string select1(argv[1]);


        if (select1 == "--help" )
        {
            std::cout<< "Fuer Console eingeben: --ui console" << std::endl;
            std::cout<< "Fuer Graphic eingeben: --ui graphic" << std::endl;
        }

    }

    if (argc == 1)
    {
        UI Console_ui;
        play_game(Console_ui);
    }

    else if (argc != 2)
    {
        string select1(argv[1]);
        string select2(argv[2]);

        if (select1 == "--ui" && select2 == "console" )
        {
            UI Console_ui;
            play_game(Console_ui);
        }

        if (select1== "--ui" && select2== "graphic" )
        {
            Gui gui;
            play_game(gui);
        }
    }
    return 0;
}

void play_game(UserInterface &ui) {
    int Round=1;
    int column =0;
    bool winner = false;
    UserInterface::GridType grid;
    int field_lines = grid.size();
    int field_columns = grid[0].size();
    Logic Gamelogic;

    while(1)
        {
            ui.updateBoard(grid);


            if ( (Round % 2) == 0)
            {

                column = ui.askPlayer(UserInterface::Color::YELLOW) + 1;                 // -48 um in ASCI Tabelle richtigen wert zu bekommen!

                for (int line=0; line <= field_lines ; line++)
                {
                    if (grid[line][column-1].isEmpty())
                    {
                        if(line == field_lines)
                        {
                            grid[line-1][column-1] = UserInterface::Color::YELLOW;
                        }

                    }
                    else
                    {
                        grid[line-1][column-1] = UserInterface::Color::YELLOW;
                        break;

                    }

                }

            }
            else
            {

                column = ui.askPlayer(UserInterface::Color::RED) + 1;

                for (int line=0; line <= field_lines ; line++)
                {
                    if (grid[line][column-1].isEmpty())
                    {
                        if(line == field_lines)
                        {
                            grid[line-1][column-1] = UserInterface::Color::RED;
                        }

                    }
                    else
                    {
                        grid[line-1][column-1] = UserInterface::Color::RED;
                        break;

                    }

                }

            }

            winner = Gamelogic.WinCheck(grid);

            if (winner)
            {
                ui.updateBoard(grid);
                if ((Round % 2) == 0)
                {
                    ui.notifyWinner(UserInterface::Color::YELLOW);
                }
                else
                {
                    ui.notifyWinner(UserInterface::Color::RED);
                }


                break;
            }


            if (Round >= field_lines*field_columns)
            {
                ui.updateBoard(grid);
                ui.notifyDraw();
                break;
            }
            else
            {
                Round++;
            }

        }
}
