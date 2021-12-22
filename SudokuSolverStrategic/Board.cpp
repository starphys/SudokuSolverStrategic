#include "Board.h"

Board::Board(int sideLen) : sideLength(sideLen), totalSquares(sideLen*sideLen) {
	for (int i = 0; i < sideLength; ++i) {
		for (int j = 0; j < sideLength; ++j) {
			std::shared_ptr<Square> newSquare (new Square{ i,j });
			squares.push_back(std::move(newSquare));
		}
	}
}

Board::~Board() {}

void Board::printBoard() {
	int i = 1;

	for (std::vector<std::shared_ptr<Square>>::iterator it = squares.begin(); it != squares.end(); ++it) {
		std::cout << "|" << **it;
			if (i == sideLength) {
				std::cout << "|\n";
				i = 0;
			}
			++i;
	}
	std::cout << '\n';
}

int Board::findIndex(int i, int j) {
	return i * sideLength + j;
}
int Board::findIndex(Position& pos) {
	return pos.getX() * sideLength + pos.getY();
}

Position Board::findPosition(int index) {
	int i = index / sideLength;
	int j = index % sideLength;

	return Position{ i,j };
}

std::shared_ptr<Square> Board::getSquareAt(Position pos) {
	return getSquareAt(findIndex(pos));
}

std::shared_ptr<Square> Board::getSquareAt(int index) {
	return squares[index];
}