#include "Solver.h"

Solver::Solver(Board newBoard) : toSolve{ newBoard } {}
Solver::~Solver() {}

void Solver::updateCandidates() {
	//Temporary pointer for simplicity
	std::shared_ptr<Square> tempSquare;

	//Iterate through entire board
	for (int i = 0; i < toSolve.size(); ++i) {
		tempSquare = toSolve.getSquareAt(i);

		//Only update non-clue candidates
		if (!tempSquare->isClue()) {
			//Check each position in this square's groups for values. If a non-zero value is found, remove from candidates
			for (std::set<Position>::iterator groupsIter = tempSquare->groups.begin(); groupsIter != tempSquare->groups.end(); ++groupsIter) {
				int tempVal = toSolve.getSquareAt(*groupsIter)->getValue();
				if (tempVal != 0) {
					tempSquare->candidates.erase(tempVal);
				}
			}
		}
		else {}
	}
}

bool Solver::nakedSingles() {
	//Temporary pointer for simplicity
	std::shared_ptr<Square> tempSquare;

	//Iterate through entire board
	for (int i = 0; i < toSolve.size(); ++i) {
		tempSquare = toSolve.getSquareAt(i);

		//Do not modify clues
		if (!tempSquare->isClue()) {
			//If the length of candidates is 1, we can fill in that cell with that candidate
			if (tempSquare->candidates.size() == 1) {
				tempSquare->setValue(*tempSquare->candidates.begin());
				tempSquare->candidates.clear();
				tempSquare->setClue(true);
			}
		}
		else {}
	}
	return false;
}

int Solver::gradeBoard() {
	updateCandidates();
	return 0;
}
