#pragma once
#include "Position.h"
#include <set>
#include <cassert>

class Square
{
private:
	Position position;
	bool clue = false;
	int value = 0;

	void findGroups();

	//Constants to be re-examined in future improvements
	const int BOX_SIZE = 3;
	const int SIDE_LEN = 9;
public:
	Square(int i, int j);
	Square(Position& pos);
	~Square();

	void initCandidates();

	void setPosition(int newX, int newY);
	Position& getPosition() { return position; };

	void setClue(bool status);
	bool isClue() { return clue; }

	void setValue(int val);
	int getValue() { return value; }

	//std::ostream& operator<< (std::ostream& os);
	friend std::ostream& operator<< (std::ostream& os, Square& sq);

	std::set<int> candidates{};
	std::set<Position> groups{};
};



