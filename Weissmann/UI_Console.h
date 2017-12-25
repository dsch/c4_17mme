/*
    M.Weissmann
*/
#ifndef UI_CONSOLE_H
#define UI_CONSOLE_H
#include"UserInterface.h"
#include "UserInterface.h"

class UI_Console :
	public UserInterface
{
public:
	UI_Console();
	~UI_Console();

	ColumnType askPlayer(Color color);

	void updateBoard(const GridType& grid);
	void notifyWinner(Color color);
	void notifyDraw();
	void init();
	void currentPlayer(Color Color);
};




#endif // UI_CONSOLE_H
