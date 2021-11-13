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

void Board::fillFromCSV(std::fstream& input) {
	//Assume CSV is a series of lines of SIDE_LENGTH for a total of SIDE_LENGTH^2 values
	std::string line, val;

	for (int i = 0; i < SIDE_LENGTH; ++i) {
		std::getline(input, line);
		std::stringstream stream(line);

		for (int j = 0; j < SIDE_LENGTH; ++j) {
			std::getline(stream, val, ',');
			if (!(val.empty())) {
				(*getSquareAt(findIndex(i, j))).value = std::stoi(val);
			}
		}
	}
}

void Board::printBoard() {

	std::cout << "Sudoku Board Current State:\n";
	for (std::vector<std::shared_ptr<Square>>::iterator it = squares.begin(); it != squares.end(); ++it) {
			std::cout << **it;
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

std::shared_ptr<Square> Board::getSquareAt(Position& pos) {
	return getSquareAt(findIndex(pos));
}

std::shared_ptr<Square> Board::getSquareAt(int index) {
	return squares[index];
}