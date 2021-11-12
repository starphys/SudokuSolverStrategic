#include "Square.h"

Square::Square(int i = 0, int j = 0) : position{ i,j } {}
Square::Square(Position& pos) : position{ pos } {}
Square::~Square() {}


void Square::findGroups() {
	//Add every position in the same row and column
	for (int i = 0; i <= MAX_POS; ++i) {
		groups.insert({ position.x, i });
		groups.insert({ i, position.y });
	}

	//Find Box
	int boxX = (position.x/BOX_SIZE)*BOX_SIZE;
	int boxY = (position.y/BOX_SIZE)*BOX_SIZE;

	for (int i = boxX; i < boxX + BOX_SIZE; ++i) {
		for (int j = boxY; j < boxY + BOX_SIZE; ++j) {
			groups.insert({ i,j });
		}
	}
}

void Square::setPosition(int newX, int newY) {
	position.x = newX;
	position.y = newY;
}

/*std::ostream& Square::operator<< (std::ostream& os) {
	os << &position;
	return os;
}*/

std::ostream& operator<< (std::ostream& os, Square& sq) {
	os << sq.getPosition();
	return os;
}