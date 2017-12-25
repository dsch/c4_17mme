#include <iostream>
#include "Console_UI.h"
#include "Funktions.h"
#include <array>
#include <stdlib.h>
#include "gui/Gui.h"

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        std::string help(argv[1]);
        if(help == "help")
        {
            std::cout << "Mögliche eingaben sind:"<<std::endl;
            std::cout << "--gui graphics" << std::endl;
            std::cout << "--gui console" << std::endl;

        }

    }

    if(argc == 1)
    {
        int column;
        int round = 1;

        bool winner = false;
        bool game_is_running = true;

        UserInterface::GridType grid;       //definiert die Variable "grid" und initialisiert alle Felder mit "empty"
        int field_lines = grid.size();
        Console_UI console_ui;
        Funktions allFunctions;             //enthält alle Funktionen zur Gewinner-Ermittlung
        UserInterface& ui = console_ui;
        UserInterface::Abort abortExeption; //Abbruchbedingung

        while(game_is_running)
        {
            try
            {
                system("cls");                                                          //löscht den Bildschirm der Console
                ui.updateBoard(grid);

                /**ermittelt welcher Spieler den nächsten Stein wirft**/
                if ( (round % 2) == 0)
                {
                    column = ui.askPlayer(UserInterface::Color::YELLOW)-48;
                    //column = ui.askPlayer(UserInterface::Color::YELLOW) - 48;//askPlayer gibt char aus ASCII-Tabelle zurück, "-48" um auf wahren Zahlenwert zu kommen

                    if((column < 0)||(column >9))                                       //Wird ein Buchstabe eingegeben wird das spiel abgebrochen
                    {
                        throw abortExeption;
                    }

                    for (int line=0; line <= field_lines ; line++)
                    {
                        if (grid[line][column-1].isEmpty())                             // -1 ist die Indexkorrektur der Benutzereingabe
                        {
                            if(line == field_lines)
                            {
                                grid[line-1][column-1] = UserInterface::Color::YELLOW;  // wirft Stein in Spielfeld
                            }
                        }
                        else
                        {
                            grid[line-1][column-1] = UserInterface::Color::YELLOW;      // wirft Stein in Spielfeld
                            break;
                        }
                    }
                }

                else
                {
                    column = ui.askPlayer(UserInterface::Color::RED)-48;              //askPlayer gibt char aus ASCII-Tabelle zurück, "-48" um auf wahren Zahlenwert zu kommen

                    if((column < 0)||(column >9))                                       //Wird ein Buchstabe eingegeben wird das spiel abgebrochen
                    {
                        throw abortExeption;
                    }

                    for (int line=0; line <= field_lines ; line++)
                    {
                        if (grid[line][column-1].isEmpty())
                        {
                            if(line == field_lines)
                            {
                                grid[line-1][column-1] = UserInterface::Color::RED;     // wirft Stein in Spielfeld
                            }
                        }
                        else
                        {
                            grid[line-1][column-1] = UserInterface::Color::RED;         // wirft Stein in Spielfeld
                            break;
                        }
                    }
                }

                system("cls");                                                          //löscht den Bildschirm der Console

                /** Gewinner Überprüfung **/
                winner = allFunctions.winCheck(grid);

                if (winner)
                {
                    ui.updateBoard(grid);

                    if ((round % 2) == 0)
                    {
                        ui.notifyWinner(UserInterface::Color::YELLOW);
                    }
                    else
                    {
                        ui.notifyWinner(UserInterface::Color::RED);
                    }

                    game_is_running = false;
                }


                /**Unentschieden Überprüfung**/
                if (allFunctions.drawCheck(grid))                                       // wenn maximale Rundenanzahl erreicht ist wird Unentscheiden ausgegeben.
                {
                    ui.notifyDraw();
                    game_is_running = false;
                }
                else
                {
                    round++;
                }

            }
            catch(UserInterface::Abort abortExeption)
            {
                std::cerr << abortExeption.what() << std::endl;
                game_is_running=false;
            }
        }
    }

    else if (argc != 2)
    {
        std::string command(argv[2]);

        int round = 1;

        bool winner = false;
        bool game_is_running = true;

        UserInterface::GridType grid;       //definiert die Variable "grid" und initialisiert alle Felder mit "empty"
        int field_lines = grid.size();
        Console_UI console_ui;
        Funktions allFunctions;             //enthält alle Funktionen zur Gewinner-Ermittlung
        UserInterface& ui = console_ui;
        UserInterface::Abort abortExeption; //Abbruchbedingung

        if(command == "console")
        {
            int column;

            while(game_is_running)
            {
                try
                {
                    system("cls");                                                          //löscht den Bildschirm der Console
                    ui.updateBoard(grid);

                    /**ermittelt welcher Spieler den nächsten Stein wirft**/
                    if ( (round % 2) == 0)
                    {
                        column = ui.askPlayer(UserInterface::Color::YELLOW)-48;
                        //column = ui.askPlayer(UserInterface::Color::YELLOW) - 48;//askPlayer gibt char aus ASCII-Tabelle zurück, "-48" um auf wahren Zahlenwert zu kommen

                        if((column < 0)||(column >9))                                       //Wird ein Buchstabe eingegeben wird das spiel abgebrochen
                        {
                            throw abortExeption;
                        }

                        for (int line=0; line <= field_lines ; line++)
                        {
                            if (grid[line][column-1].isEmpty())                             // -1 ist die Indexkorrektur der Benutzereingabe
                            {
                                if(line == field_lines)
                                {
                                    grid[line-1][column-1] = UserInterface::Color::YELLOW;  // wirft Stein in Spielfeld
                                }
                            }
                            else
                            {
                                grid[line-1][column-1] = UserInterface::Color::YELLOW;      // wirft Stein in Spielfeld
                                break;
                            }
                        }
                    }

                    else
                    {
                        column = ui.askPlayer(UserInterface::Color::RED)-48;              //askPlayer gibt char aus ASCII-Tabelle zurück, "-48" um auf wahren Zahlenwert zu kommen

                        if((column < 0)||(column >9))                                       //Wird ein Buchstabe eingegeben wird das spiel abgebrochen
                        {
                            throw abortExeption;
                        }

                        for (int line=0; line <= field_lines ; line++)
                        {
                            if (grid[line][column-1].isEmpty())
                            {
                                if(line == field_lines)
                                {
                                    grid[line-1][column-1] = UserInterface::Color::RED;     // wirft Stein in Spielfeld
                                }
                            }
                            else
                            {
                                grid[line-1][column-1] = UserInterface::Color::RED;         // wirft Stein in Spielfeld
                                break;
                            }
                        }
                    }

                    system("cls");                                                          //löscht den Bildschirm der Console

                    /** Gewinner Überprüfung **/
                    winner = allFunctions.winCheck(grid);

                    if (winner)
                    {
                        ui.updateBoard(grid);

                        if ((round % 2) == 0)
                        {
                            ui.notifyWinner(UserInterface::Color::YELLOW);
                        }
                        else
                        {
                            ui.notifyWinner(UserInterface::Color::RED);
                        }

                        game_is_running = false;
                    }


                    /**Unentschieden Überprüfung**/
                    if (allFunctions.drawCheck(grid))                                       // wenn maximale Rundenanzahl erreicht ist wird Unentscheiden ausgegeben.
                    {
                        ui.notifyDraw();
                        game_is_running = false;
                    }
                    else
                    {
                        round++;
                    }

                }
                catch(UserInterface::Abort abortExeption)
                {
                    std::cerr << abortExeption.what() << std::endl;
                    game_is_running=false;
                }
            }
        }

        if(command == "graphics")
        {
            Gui gui;
            UserInterface::ColumnType column;

            while(game_is_running)
            {
                try
                {
                    system("cls");                                                          //löscht den Bildschirm der Console
                    gui.updateBoard(grid);

                    /**ermittelt welcher Spieler den nächsten Stein wirft**/
                    if ( (round % 2) == 0)
                    {
                        column = gui.askPlayer(UserInterface::Color::YELLOW)+1;


                        if((column < 0)||(column >9))                                       //Wird ein Buchstabe eingegeben wird das spiel abgebrochen
                        {
                            throw abortExeption;
                        }

                        for (int line=0; line <= field_lines ; line++)
                        {
                            if (grid[line][column-1].isEmpty())                             // -1 ist die Indexkorrektur der Benutzereingabe
                            {
                                if(line == field_lines)
                                {
                                    grid[line-1][column-1] = UserInterface::Color::YELLOW;  // wirft Stein in Spielfeld
                                }
                            }
                            else
                            {
                                grid[line-1][column-1] = UserInterface::Color::YELLOW;      // wirft Stein in Spielfeld
                                break;
                            }
                        }
                    }

                    else
                    {
                        column = gui.askPlayer(UserInterface::Color::RED)+1;              //askPlayer gibt char aus ASCII-Tabelle zurück, "-48" um auf wahren Zahlenwert zu kommen

                        if((column < 0)||(column >9))                                       //Wird ein Buchstabe eingegeben wird das spiel abgebrochen
                        {
                            throw abortExeption;
                        }

                        for (int line=0; line <= field_lines ; line++)
                        {
                            if (grid[line][column-1].isEmpty())
                            {
                                if(line == field_lines)
                                {
                                    grid[line-1][column-1] = UserInterface::Color::RED;     // wirft Stein in Spielfeld
                                }
                            }
                            else
                            {
                                grid[line-1][column-1] = UserInterface::Color::RED;         // wirft Stein in Spielfeld
                                break;
                            }
                        }
                    }

                    system("cls");                                                          //löscht den Bildschirm der Console

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
                    if (allFunctions.drawCheck(grid))                                       // wenn maximale Rundenanzahl erreicht ist wird Unentscheiden ausgegeben.
                    {
                        gui.notifyDraw();
                        game_is_running = false;
                    }
                    else
                    {
                        round++;
                    }

                }
                catch(UserInterface::Abort abortExeption)
                {
                    std::cerr << abortExeption.what() << std::endl;
                    game_is_running=false;
                }
            }
        }

    }




    return 0;
}
