#ifndef BOARD_H
#define BOARD_H

#include "sudokuglobals.h"
#include <vector>

class Board
{
public:
	Board();
	ColoredToken* state();
	void populate(int* arr);
	void solve();
	bool check(bool colorInvalid=true);
private:
	Token mapToToken(int thisChar);
	ColoredToken board[numTokens];

	bool checkRow(int index);
	bool checkCol(int index);
	bool checkCell(int index);

	int getCell(int row, int col);
	int getCellOffset(int cell);
};

#endif