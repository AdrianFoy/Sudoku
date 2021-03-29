#include "viewer.h"
#include "board.h"

void Viewer::display()
{	
	board->check();
	printTopLine();
	
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col) {
			if (col % 3 == 0)
				printf("\u2502"); // vertical line
			else 
				printf(" ");

			ColoredToken thisColoredToken = *((board->state() + row*cols) + col);
			char displayChar = mapToNum(thisColoredToken.token);

			if (thisColoredToken.color == Red) {
				red();
			} else if (thisColoredToken.color == Green) {
				green();
			}

			printf("%c", displayChar);

			white();
		}
		printf("\u2502\n"); // vertical line
		if (row == 2 || row == 5) {
			printMidLine();
		}
	}
	printBottomLine();
}

char Viewer::mapToNum(Token token)
{
	switch (token) {
	case A:
		return '1';
	case B:
		return '2';
	case C:
		return '3';
	case D:
		return '4';
	case E:
		return '5';
	case F:
		return '6';
	case G:
		return '7';
	case H:
		return '8';
	case I:
		return '9';
	default:
		return ' ';
	}
}

void Viewer::black()
{
	printf("\033[0;30m");
}

void Viewer::red()
{
	printf("\033[1;31m");
}

void Viewer::green()
{
	printf("\033[0;32m");
}

void Viewer::white()
{
	printf("\033[0;37m");
}

void Viewer::yellow()
{
	printf("\033[0;33m");
}

void Viewer::printTopLine()
{
	wchar_t topLine[asciiWidth + 1];
	topLine[0] = 0x250c; // top left corner
	for (int i = 0; i < 5; ++i) {
		topLine[i + 1] = 0x2500; // horizontal line
	}
	topLine[6] = 0x252c; // cell separator on top border
	for (int i = 0; i < 5; ++i) {
		topLine[i + 7] = 0x2500; // horizontal line
	}
	topLine[12] = 0x252c; // cell separator on top border
	for (int i = 0; i < 5; ++i) {
		topLine[i + 13] = 0x2500; // horizontal line
	}
	topLine[18] = 0x2510; // top right corner
	topLine[19] = 0;
	printf("\n%ls\n", topLine);
}

void Viewer::printBottomLine()
{
	wchar_t bottomLine[asciiWidth + 1];
	bottomLine[0] = 0x2514; // bottom left corner
	for (int i = 0; i < 5; ++i) {
		bottomLine[i + 1] = 0x2500; // horizontal line
	}
	bottomLine[6] = 0x2534; // cell separator on bottom border
	for (int i = 0; i < 5; ++i) {
		bottomLine[i + 7] = 0x2500; // horizontal line
	}
	bottomLine[12] = 0x2534; // cell separator on bottom border
	for (int i = 0; i < 5; ++i) {
		bottomLine[i + 13] = 0x2500; // horizontal line
	}
	bottomLine[18] = 0x2518; // bottom right corner
	bottomLine[19] = 0;
	printf("%ls\n", bottomLine);
}

void Viewer::printMidLine()
{
	wchar_t midLine[asciiWidth + 1];
	midLine[0] = 0x251c; // cell separator on left border
	for (int i = 0; i < 5; ++i) {
		midLine[i + 1] = 0x2500; // horizontal line
	}
	midLine[6] = 0x253c; // cell separator
	for (int i = 0; i < 5; ++i) {
		midLine[i + 7] = 0x2500; // horizontal line
	}
	midLine[12] = 0x253c; // cell separator
	for (int i = 0; i < 5; ++i) {
		midLine[i + 13] = 0x2500; // horizontal line
	}
	midLine[18] = 0x2524; // cell separator on right border
	midLine[19] = 0;
	printf("%ls\n", midLine);
}
