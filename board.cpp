#include "board.h"
#include <vector>

Board::Board()
{
	// Initialize board to all 'none's
	for (int i = 0; i < numTokens; ++i) {
		board[i].token = None;
		board[i].color = White;
	}
}

ColoredToken* Board::state()
{
	return (ColoredToken* ) board;
}

void Board::populate(int* arr)
{
	for (int i = 0; i < numTokens; ++i) {
		board[i].token = mapToToken(arr[i]);
		board[i].color = White;
	}
}

Token Board::mapToToken(int thisChar)
{
	switch (thisChar) {
	case '1':
		return A;
	case '2':
		return B;
	case '3':
		return C;
	case '4':
		return D;
	case '5':
		return E;
	case '6':
		return F;
	case '7':
		return G;
	case '8':
		return H;
	case '9':
		return I;
	default:
		return None;
	}
}

void Board::solve()
{	
	// Get indices of spaces
	std::vector<int> spaceIndices = {};
	for (int i = 0; i < numTokens; ++i) {
		if (board[i].token == None) {
			spaceIndices.push_back(i);
		}
	}

	// For each space, solve until the first non-invalid token is found (Note: not robust)
	for (int i = 0; i < spaceIndices.size(); ++i) {
		// Cycle through tokens, checking board until success
		for (int tokenIndex = A; tokenIndex < None; ++tokenIndex) {
			board[spaceIndices[i]].token = (Token) tokenIndex;
			bool success = check(false);
			if (success) {
				board[spaceIndices[i]].color = Green;
				break;
			}
		}
	}
}

bool Board::check(bool colorInvalid)
{
	bool validBoard = true;
	for (int i = 0; i < numTokens; ++i) {
		// Check if this token is valid;

		// Check this token in its row
		bool validRow = checkRow(i);

		// Check this token in its col
		bool validCol = checkCol(i);

		// Check this token in its cell
		bool validCell = checkCell(i);

		bool validToken = validRow & validCol & validCell;

		if (!validToken) {
			if (colorInvalid)
				board[i].color = Red;
			validBoard = false;
		}
	}
	return validBoard;
}

bool Board::checkRow(int index)
{
	Token thisToken = board[index].token;

	// If this token is None, then it can't be invalid - return true
	if (thisToken == None)
		return true;

	// Determine which row this token is in
	int row = index / cols;

	// See how many matching tokens are in this row
	int matches = 0;
	for (int i = row * cols; i < (row + 1) * cols; ++i) {
		if (board[i].token == thisToken) {
			matches++;
		}
	}

	// If there is more than one match (the one match would be the original), return false
	if (matches > 1) {
		return false;
	} else {
		return true;
	}
}

bool Board::checkCol(int index)
{
	Token thisToken = board[index].token;

	// If this token is None, then it can't be invalid - return true
	if (thisToken == None)
		return true;

	// Determine which col this token is in
	int col = index % cols;

	// See how many matching tokens are in this column
	int matches = 0;
	for (int i = col; i < numTokens; i += cols) {
		if (board[i].token == thisToken) {
			matches++;
		}
	}

	// If there is more than one match (the one match would be the original), return false
	if (matches > 1) {
		return false;
	} else {
		return true;
	}
}

bool Board::checkCell(int index)
{
	Token thisToken = board[index].token;

	// If this token is None, then it can't be invalid - return true
	if (thisToken == None)
		return true;

	// Determine which cell this token is in
	int row = index / cols;
	int col = index % cols;
	int cell = getCell(row, col);
	int offset = getCellOffset(cell);

	// See how many matching tokens are in this column
	int matches = 0;
	for (int subRow = 0; subRow < 3; subRow++) {
		for (int subCol = 0; subCol < 3; subCol++) {
			if (board[subCol + offset].token == thisToken) {
				matches++;
			}
		}
		offset += 9;
	}

	// If there is more than one match (the one match would be the original), return false
	if (matches > 1) {
		return false;
	} else {
		return true;
	}
}

int Board::getCell(int row, int col)
{
	// First 3 rows
	if (row < 3) {
		// First 3 cols - cell 0
		if (col < 3) {
			return 0;
		}

		// Second 3 cols - cell 1
		else if (col < 6) {
			return 1;
		}

		// Last 3 cols - cell 2
		else {
			return 2;
		}
	}

	// Second 3 rows
	else if (row < 6) {
		// First 3 cols - cell 3
		if (col < 3) {
			return 3;
		}

		// Second 3 cols - cell 4
		else if (col < 6) {
			return 4;
		}

		// Last 3 cols - cell 5
		else {
			return 5;
		}
	}

	// Last 3 rows
	else {
		// First 3 cols - cell 6
		if (col < 3) {
			return 6;
		}

		// Second 3 cols - cell 7
		else if (col < 6) {
			return 7;
		}

		// Last 3 cols - cell 8
		else {
			return 8;
		}
	}
}

int Board::getCellOffset(int cell)
{
	switch (cell) {
	case 0:
		return 0;
	case 1:
		return 3;
	case 2:
		return 6;
	case 3:
		return 27;
	case 4:
		return 30;
	case 5:
		return 33;
	case 6:
		return 54;
	case 7:
		return 57;
	case 8:
		return 60;
	default:
		return 0;
	}
}