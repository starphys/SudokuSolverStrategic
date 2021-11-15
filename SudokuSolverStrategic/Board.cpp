#include "Board.h"

Board::Board() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			std::shared_ptr<Square> newSquare (new Square{ i,j });
			squares.push_back(std::move(newSquare));
		}
	}

}

Board::~Board() {}

void Board::printBoard() {
	//TODO: clean up this method of printing a board, it's sloppy
	int i = 1;

	std::cout << "Sudoku Board Current State:\n";
	for (std::vector<std::shared_ptr<Square>>::iterator it = squares.begin(); it != squares.end(); ++it) {
			std::cout << **it;
			if (i == SIDE_LENGTH) {
				std::cout << '\n';
				i = 0;
			}
			++i;
	}
	std::cout << '\n';
}

int Board::findIndex(int i, int j) {
	return i * SIDE_LENGTH + j;
}
int Board::findIndex(Position& pos) {
	return pos.x * SIDE_LENGTH + pos.y;
}

Position Board::findPosition(int index) {
	int i = index / SIDE_LENGTH;
	int j = index % SIDE_LENGTH;

	return Position{ i,j };
}

std::shared_ptr<Square> Board::getSquareAt(Position pos) {
	return getSquareAt(findIndex(pos));
}

std::shared_ptr<Square> Board::getSquareAt(int index) {
	return squares[index];
}