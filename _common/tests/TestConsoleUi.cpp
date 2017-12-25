#include <iostream>
#include <vector>

using Color = UserInterface::Color;
using ColumnType = UserInterface::ColumnType;

void passed() {
    std::cout << "Test PASSED" << std::endl;
}

void failed() {
    std::cout << "Test FAILED" << std::endl;
}

void assert(bool condition) {
    if (condition) {
        passed();
    } else {
        failed();
    }
}

void updateBoardRed(UserInterface &ui) {
    UserInterface::GridType grid;
    grid[0][0] = Color::RED;
    ui.updateBoard(grid);
}

void updateBoardYellow(UserInterface &ui) {
    UserInterface::GridType grid;
    grid[0][0] = Color::YELLOW;
    ui.updateBoard(grid);
}

void updateBoardDiag(UserInterface &ui) {
    UserInterface::GridType grid;
    grid[0][0] = Color::YELLOW;
    grid[1][1] = Color::RED;
    grid[2][2] = Color::YELLOW;
    grid[3][3] = Color::RED;
    grid[4][4] = Color::YELLOW;
    grid[5][5] = Color::RED;
    grid[5][6] = Color::YELLOW;
    ui.updateBoard(grid);
}


void notifyYellowWinner(UserInterface &ui) {
    ui.notifyWinner(Color::YELLOW);
    std::cout << std::endl;
}

void notifyRedWinner(UserInterface &ui) {
    ui.notifyWinner(Color::RED);
    std::cout << std::endl;
}

void notifyDraw(UserInterface &ui) {
    ui.notifyDraw();
    std::cout << std::endl;
}

void askYellowPlayer(UserInterface &ui) {
    ColumnType column = ui.askPlayer(Color::YELLOW);
    std::cout << "Column: " << (int) column << std::endl;
    assert(column == 0);
}

void askRedPlayer(UserInterface &ui) {
    ColumnType column = ui.askPlayer(Color::RED);
    std::cout << "Column: " << (int) column << std::endl;
    assert(column == 1);
}

void abortGame(UserInterface &ui) {
    try {
        ColumnType column = ui.askPlayer(Color::RED);
        std::cout << "Column: " << (int) column << std::endl;
        failed();

    } catch (const UserInterface::Abort &ex) {
        std::cout << "Aborted: " << ex.what() << std::endl;
        passed();
    }
}

typedef void (* TestFunc)(UserInterface &);

struct TestDef {
    const char* name;
    TestFunc func;
};


int main() {
    UI_CLASS console_ui;

    const std::vector<TestDef> tests = {
            {"left-top to right-bottom",       updateBoardDiag},
            {"Player Yellow, select column 1", askYellowPlayer},
            {"Player Red, select column 2",    askRedPlayer},
            {"abort the game",                 abortGame},
            {"notifyYellowWinner",             notifyYellowWinner},
            {"notifyRedWinner",                notifyRedWinner},
            {"notifyDraw",                     notifyDraw},
    };

    for (const TestDef &test : tests) {
        std::cout << "*****************************************" << std::endl;
        std::cout << "* " << test.name << std::endl;
        std::cout << "*****************************************" << std::endl;
        test.func(console_ui);
        std::cout << std::endl;
    }

    return 0;
}

