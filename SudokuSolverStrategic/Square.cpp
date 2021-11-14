#include "Square.h"

Square::Square(int i = 0, int j = 0) : position{ i,j } {
	findGroups();
	initCandidates();
}
Square::Square(Position& pos) : position{ pos } {
	findGroups();
	initCandidates();
}
Square::~Square() {}


void Square::findGroups() {
	//Add every position in the same row and column
	for (int i = 0; i < SIDE_LEN; ++i) {
		groups.insert({ position.x, i });
		groups.insert({ i, position.y });
	}

	//Find box bounds
	int boxX = (position.x/BOX_SIZE)*BOX_SIZE;
	int boxY = (position.y/BOX_SIZE)*BOX_SIZE;

	//Add all box squares to groups
	for (int i = boxX; i < boxX + BOX_SIZE; ++i) {
		for (int j = boxY; j < boxY + BOX_SIZE; ++j) {
			groups.insert({ i,j });
		}
	}
}

void Square::initCandidates() {
	//Add digits  1->SIDE_LEN to candidates set
	for (int digit = 1; digit <= SIDE_LEN; ++digit) {
		candidates.insert(digit);
	}
}

void Square::setPosition(int newX, int newY) {
	position.x = newX;
	position.y = newY;
}

void Square::setClue(bool status) { 
	if (status) {
		candidates.clear();
	}

	clue = status; 
}

void Square::setValue(int val) {
	assert(clue == false);
	value = val;
}

/*std::ostream& Square::operator<< (std::ostream& os) {
	os << &position;
	return os;
}*/

std::ostream& operator<< (std::ostream& os, Square& sq) {
	os << sq.value << "|";
	return os;
}