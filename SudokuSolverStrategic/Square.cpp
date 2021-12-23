#include "Square.h"

Square::Square(int i = 0, int j = 0) : position{ i,j } {
	findGroups();
}
Square::Square(Position& pos) : position{ pos } {
	findGroups();
}
Square::~Square() {}


void Square::findGroups() {
	//Add every position in the same row and column
	int xLocal = position.getX();
	int yLocal = position.getY();
	for (int i = 0; i < SIDE_LEN; ++i) {
		Position tempPosCol{ xLocal, i };
		Position tempPosRow{ i,yLocal };
		groups.insert(tempPosCol);
		groups.insert(tempPosRow);
	}

	//Find box bounds
	int boxX = (position.getX() / BOX_SIZE) * BOX_SIZE;
	int boxY = (position.getY() / BOX_SIZE) * BOX_SIZE;

	//Add all box squares to groups
	for (int i = boxX; i < boxX + BOX_SIZE; ++i) {
		for (int j = boxY; j < boxY + BOX_SIZE; ++j) {
			Position tempPosBox{ i,j };
			groups.insert(tempPosBox);
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
	position.setPosition(newX, newY);
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

std::ostream& operator<< (std::ostream& os, Square& sq) {
	os << sq.value;
	return os;
}