#include "Position.h"

Position::Position(int i = 0, int j = 0) : x{ i }, y{ j } {}
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

/*std::ostream& Position::operator<< (std::ostream& os) {
	os << "(\t" << x << ",\t" << y << ")";
	return os;
}*/

std::ostream& operator<< (std::ostream& os, const Position& pos) {
	os << "(" << pos.x << "," << pos.y << ")";
	return os;
}