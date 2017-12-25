#ifndef MAIN_CONSOLEUI_H
#define MAIN_CONSOLEUI_H

#include "UserInterface.h"
#include "windows.h"

class ConsoleUI : public UserInterface {
  public:
    ConsoleUI();
    ColumnType askPlayer(Color color) override;
    void updateBoard(const GridType &grid) override;
    void notifyWinner(Color color) override;
    void notifyDraw() override {};

    ~ConsoleUI() override = default;

  private:
    // We need a console handle to set text colours
    // OS-specific!
    HANDLE hConsole;

    void ClearInputStream();
};

#endif //MAIN_CONSOLEUI_H
