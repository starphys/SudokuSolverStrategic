#include "Position.h"

Position::Position(int i, int j) : x{ i }, y{ j } {}
Position::~Position() {}

bool Position::operator== (const Position& right) const {
	if (x == right.x && y == right.y)
		return true;
	return false;
}

bool Position::operator< (const Position& right) const {
	if(x < right.x || (x == right.x && y < right.y))
		return true;
	return false;
}

int Position::getX()
{
	return x;
}

int Position::getY()
{
	return y;
}

void Position::setPosition(int i, int j)
{
	x = i;
	y = j;
}

void Position::setX(int i)
{
	x = i;
}

void Position::setY(int j)
{
	y = j;
}

std::ostream& operator<< (std::ostream& os, const Position& pos) {
	os << "(" << pos.x << "," << pos.y << ")";
	return os;
}