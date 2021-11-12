#pragma once
#include <vector>
#include <memory>
#include "Square.h"


class Board
{
private:
	std::vector<std::shared_ptr<Square>> squares;

	//Constants to be re-examined in future improvements
	const int MAX_SQUARES = 81;
public:
	Board();
	~Board();

	void fillFromCSV();
	void printBoard();

};

