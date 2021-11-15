#pragma once
#include "Board.h"

class PuzzleMaker
{
private:
	Board* toFill;

	//Constants to be re-examined in future improvements
	const int MAX_SQUARES = 81;
	const int SIDE_LENGTH = 9;
public:
	PuzzleMaker(Board* board);
	~PuzzleMaker();

	void fillFromCSV(std::fstream& input);
};

