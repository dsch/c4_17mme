#include <iostream>
#include "Console_UI.h"
#include "Funktions.h"
#include <array>
#include <stdlib.h>
#include "gui/Gui.h"
#include <string>

void play_game(UserInterface& gui)
{
    int round = 1;
    UserInterface::ColumnType column;
    bool winner = false;
    bool game_is_running = true;

    UserInterface::GridType grid;      //definiert die Variable "grid" und initialisiert alle Felder mit "empty"
    int field_lines = grid.size();
    Funktions allFunctions;            //enthält alle Funktionen zur Gewinner-Ermittlung
    UserInterface::Abort abortExeption;

    while(game_is_running)
    {
        try
        {
            system("cls"); //löscht den Bildschirm der Console
            gui.updateBoard(grid);

            /**ermittelt welcher Spieler den nächsten Stein wirft**/
            if ( (round % 2) == 0)
            {
                column = gui.askPlayer(UserInterface::Color::YELLOW)+1;

                if (column < 1 || column > 9)
                {
                    throw abortExeption;
                }

                for (int line=0; line <= field_lines ; line++)
                {
                    if (grid[line][column-1].isEmpty()) // column-1=Indexkorrektur, Eingabe 1...7 und Arrayindex 0...6
                    {
                        if(line == field_lines)
                        {
                            grid[line-1][column-1] = UserInterface::Color::YELLOW; // wirft Stein in Spielfeld
                        }
                    }
                    else
                    {
                        grid[line-1][column-1] = UserInterface::Color::YELLOW; // wirft Stein in Spielfeld
                        break;
                    }
                }
            }

            else
            {
                column = gui.askPlayer(UserInterface::Color::RED)+1;

                if (column < 1 || column > 9)
                {
                    throw abortExeption;
                }

                for (int line=0; line <= field_lines ; line++)
                {
                    if (grid[line][column-1].isEmpty())
                    {
                        if(line == field_lines)
                        {
                            grid[line-1][column-1] = UserInterface::Color::RED; // wirft Stein in Spielfeld
                        }
                    }
                    else
                    {
                        grid[line-1][column-1] = UserInterface::Color::RED; // wirft Stein in Spielfeld
                        break;
                    }
                }
            }

            system("cls"); //löscht den Bildschirm der Console

            /** Gewinner Überprüfung **/
            winner = allFunctions.winCheck(grid);

            if (winner)
            {
                gui.updateBoard(grid);

                if ((round % 2) == 0)
                {
                    gui.notifyWinner(UserInterface::Color::YELLOW);
                }
                else
                {
                    gui.notifyWinner(UserInterface::Color::RED);
                }
                game_is_running = false;
            }


            /**Unentschieden Überprüfung**/
            if (allFunctions.drawCheck(grid))   // wenn maximale Rundenanzahl erreicht ist wird Unentscheiden ausgegeben.
            {
                gui.notifyDraw();
                game_is_running = false;
            }
            else
            {
                round++;
            }
        }

        catch(const UserInterface::Abort abortExeption)
        {
            std::cerr << abortExeption.what() << std::endl;
            game_is_running = false;
        }
    }
}

int main(int argc, char** argv)
{
    if (argc>2)
    {
        std::string option1(argv[1]);
        std::string option2(argv[2]);

        if(option1== "--ui" && option2=="graphic")
        {
            Gui gui;
            play_game(gui);
        }
        else
        {
            Console_UI console_ui;
            play_game(console_ui);
        }
    }

    return 0;
}
