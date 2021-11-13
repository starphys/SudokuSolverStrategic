#pragma once
#include <vector>
#include <memory>
#include "Square.h"
#include <fstream>
#include <string>
#include <sstream>



class Board
{
private:
	std::vector<std::shared_ptr<Square>> squares;

	//Constants to be re-examined in future improvements
	const int MAX_SQUARES = 81;
	const int SIDE_LENGTH = 9;

public:
	Board();
	~Board();

	void fillFromCSV(std::fstream& input);
	void printBoard();

	int findIndex(int i, int j);
	int findIndex(Position& pos);

	Position findPosition(int index);

	std::shared_ptr<Square> getSquareAt(Position pos);
	std::shared_ptr<Square> getSquareAt(int index);

	int size() { return MAX_SQUARES; }
};

