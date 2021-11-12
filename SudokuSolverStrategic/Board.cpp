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

void Board::fillFromCSV() {}

void Board::printBoard() {

	std::cout << "Sudoku Board Current State:\n";
	for (std::vector<std::shared_ptr<Square>>::iterator it = squares.begin(); it != squares.end(); ++it) {
			std::cout << **it;
	}
	std::cout << '\n';
}