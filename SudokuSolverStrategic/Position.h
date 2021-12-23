#pragma once
#include <iostream>

class Position
{
protected:
	int x;
	int y;
public:
	Position(int i = 0, int j = 0);
	~Position();

	bool operator== (const Position& right) const;
	bool operator< (const Position& right) const;

	friend std::ostream& operator<< (std::ostream& os, const Position& pos);

	int getX();
	int getY();

	void setPosition(int i, int j);
	void setX(int i);
	void setY(int j);
};

