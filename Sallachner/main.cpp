#include <iostream>
#include <array>
#include <stdlib.h>
#include<string>
#include"Userinterface.h"
#include"Console.h"
#include"Logic.h"
#include"gui/Gui.h"



using namespace std;

int main(int argc, char** argv)
{

    int Round=1;
    int column =0;
    bool winner = false;
    UserInterface::GridType grid;
    int field_lines = grid.size();
    int field_columns = grid[0].size();
    UI Console_ui;
    Logic Gamelogic;
    UserInterface& ui = Console_ui;
    Gui gui;

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
        while(1)
        {

            system("cls");
            ui.updateBoard(grid);


            if ( (Round % 2) == 0)
            {

                column = ui.askPlayer(UserInterface::Color::YELLOW) -48;                 // -48 um in ASCI Tabelle richtigen wert zu bekommen!

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

                column = ui.askPlayer(UserInterface::Color::RED) -48;

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


            system("cls");

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
                ui.notifyDraw();
                break;
            }
            else
            {
                Round++;
            }

        }
    }

    else if (argc != 2)
    {


        string select1(argv[1]);
        string select2(argv[2]);



        if (select1 == "--ui" && select2 == "console" )
        {
            while(1)
            {

                system("cls");
                ui.updateBoard(grid);


                if ( (Round % 2) == 0)
                {

                    column = ui.askPlayer(UserInterface::Color::YELLOW) -48;                 // -48 um in ASCI Tabelle richtigen wert zu bekommen!

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

                    column = ui.askPlayer(UserInterface::Color::RED) -48;

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


                system("cls");

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
                    ui.notifyDraw();
                    break;
                }
                else
                {
                    Round++;
                }

            }

        }

        if (select1== "--ui" && select2== "graphic" )
        {



            while(1)
            {

                system("cls");
                gui.updateBoard(grid);


                if ( (Round % 2) == 0)
                {

                    column = gui.askPlayer(UserInterface::Color::YELLOW) +1;                 // -48 um in ASCI Tabelle richtigen wert zu bekommen!

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

                    column = gui.askPlayer(UserInterface::Color::RED) +1;

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


                system("cls");

                winner = Gamelogic.WinCheck(grid);

                if (winner)
                {
                    gui.updateBoard(grid);
                    if ((Round % 2) == 0)
                    {
                        gui.notifyWinner(UserInterface::Color::YELLOW);
                    }
                    else
                    {
                        gui.notifyWinner(UserInterface::Color::RED);
                    }


                    break;
                }


                if (Round >= field_lines*field_columns)
                {
                    gui.notifyDraw();
                    break;
                }
                else
                {
                    Round++;
                }

            }

        }
    }
    return 0;
}
