#pragma once
#include <iostream>

class Position
{
public:
	Position(int i, int j);
	~Position();

	bool operator== (const Position& right) const;
	bool operator< (const Position& right) const;
	//std::ostream& operator<< (std::ostream& os);

	friend std::ostream& operator<< (std::ostream& os, const Position& pos);

	int x = 0;
	int y = 0;
};


