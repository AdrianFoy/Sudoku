#ifndef VIEWER_H
#define VIEWER_H

#include "sudokuglobals.h"

class Board;

class Viewer
{
public:
	Viewer(Board& board_) {board = &board_;}
	void display();
	
private:
	void printTopLine();
	void printBottomLine();
	void printMidLine();
	
	char mapToNum(Token token);
	
	void black();
	void red();
	void green();
	void white();
	void yellow();
	
	const int asciiWidth = 2*cols + 1;
	const int asciiHeight = 2*rows + 1;

	Board *board;
};

#endif