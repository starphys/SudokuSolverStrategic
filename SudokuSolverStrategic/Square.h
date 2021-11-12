#pragma once
#include "Position.h"
#include <set>

class Square
{
private:
	Position position;

	std::set<Position> groups{};
	void findGroups();

	//Constants to be re-examined in future improvements
	const int BOX_SIZE = 3;
	const int MAX_POS = 8;
public:
	Square(int i, int j);
	Square(Position& pos);
	~Square();

	int value = 0;
	void setPosition(int newX, int newY);
	Position& getPosition() { return position; };

	//std::ostream& operator<< (std::ostream& os);
	friend std::ostream& operator<< (std::ostream& os, Square& sq);
};



