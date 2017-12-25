#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#include "UserInterface.h"
#include <Windows.h>

#define COLOR_RED 0b00001100
#define COLOR_YELLOW 0b00001110
#define COLOR_STD 0b00001111
#define TABLE_WIDTH 32
#define GAME_COLUMNS 7
#define GAME_ROWS 6

class UI : public UserInterface
{
    public:
        UI();
        virtual ~UI();

        void updateBoard(const GridType& grid);
        ColumnType askPlayer(Color color);
        void notifyWinner(Color color);
        void notifyDraw();

    private:
        unsigned char getColumn();
        void DrawRow(RowType rowIndex);
        void DrawAllRows(const GridType& grid);
        void DrawXAxis();
        void SetConsoleColor(Color color);
        void SetConsoleColor(int color);
        void DrawHorizontalSeparator();
        HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );

        uint8_t xAxis[7] = {0, 1, 2, 3, 4, 5, 6};
};

#endif // UI_H_INCLUDED
