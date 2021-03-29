#include <locale.h>
#include <fstream>
#include "sudokuglobals.h"
#include "viewer.h"
#include "board.h"

Control promptForInput() {
	printf("Press D to display board\n");
	printf("Press L to load sudoku.txt file\n");
	printf("Press S to solve current board\n");
	printf("Press anything else to exit\n");
	int intUserInput;
	
	while((intUserInput = getchar()) == '\n' || intUserInput == '\r'); // Consume any new-line characters
	
	char userInput = (char) intUserInput;
	
	if (userInput == 'D' || userInput == 'd') {
		return Display;
	} else if (userInput == 'L' || userInput == 'l') {
		return Load;
	} else if (userInput == 'S' || userInput == 's') {
		return Solve;
	} else {
		return Exit;
	}
}

void load(Board &board) {
	std::ifstream infile;
	infile.open("sudoku.txt");
	if (infile.is_open()) {
		int arr[numTokens];
		for (int i = 0; i < numTokens; ++i) {
			int thisChar;
			do {
				thisChar = infile.get();
			} while (thisChar == '\n' || thisChar == '\r');
			arr[i] = thisChar;
		}
		board.populate(arr);
		infile.close();
	} else {
		printf("File opening failed.\n");
		return;
	}
}

int main(void) {
	#ifdef _WIN32
	setlocale(LC_ALL, ".utf8");
	#else
	setlocale(LC_ALL, "C.UTF-8");
	#endif
	Board board;
	Viewer viewer(board);

	Control userInput = Display;
	
	bool keepGoing = true;
	while (keepGoing) {
		switch (userInput) {
		case Load:
			load(board);
		case Display:
			viewer.display();
			userInput = promptForInput();
			break;

		case Solve:
			board.solve();
			viewer.display();
			userInput = promptForInput();
			break;
		
		case Exit:
		default:
			keepGoing = false;
			break;
		}
	}
	return 0;
}
