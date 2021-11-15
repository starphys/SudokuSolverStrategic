#include "PuzzleMaker.h"

PuzzleMaker::PuzzleMaker(Board* board) : toFill{ board } {}
PuzzleMaker::~PuzzleMaker() {}

void PuzzleMaker::fillFromCSV(std::fstream& input) {
	//Assume CSV is a series of lines of SIDE_LENGTH for a total of SIDE_LENGTH^2 values
	std::string line, val;

	for (int i = 0; i < SIDE_LENGTH; ++i) {
		std::getline(input, line);
		std::stringstream stream(line);

		for (int j = 0; j < SIDE_LENGTH; ++j) {
			std::getline(stream, val, ',');
			if (!(val.empty())) {
				(*toFill->getSquareAt(toFill->findIndex(i, j))).setValue(std::stoi(val));
				(*toFill->getSquareAt(toFill->findIndex(i, j))).setClue(true);
			}
		}
	}
}