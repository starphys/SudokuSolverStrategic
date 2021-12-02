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
	}
	return false;
}

bool Solver::backtrack() {
	return backtrackRecurHelper(toSolve.getSquareAt(0));
}

bool Solver::backtrackRecurHelper(std::shared_ptr<Square> thisSquare) {

	bool backtrackResult = false;

	//This is a clue
	if (thisSquare->isClue()) {
		//It's not the last square so move forward
		if (!(toSolve.findIndex(thisSquare->getPosition()) == toSolve.size() - 1)) {
			backtrackResult = backtrackRecurHelper(toSolve.getSquareAt(toSolve.findIndex(thisSquare->getPosition()) + 1));
			if (backtrackResult) {
				//Somewhere below us in the callstack the last value was successfully placed.
				return true;
			}
			//Something went wrong below this clue, must change value above this clue
			return backtrackResult;
		}
		//It is the last square so we succeeded
		return true;
	}

	//This is not a clue
	else {
		//Fresh list of valid candidates
		thisSquare->initCandidates();
		findCandidatesSquare(thisSquare);

		//If this is the last square we should only have one candidate which we place and return true
		if (toSolve.findIndex(thisSquare->getPosition()) == toSolve.size() - 1) {
			if (!thisSquare->isClue()) {
				assert(thisSquare->candidates.size() == 1);
				thisSquare->setValue(*(thisSquare->candidates.begin()));
			}
			return true;
		}

		//Loop through candidates trying to place a value that allows the board to be completed
		for (std::set<int>::iterator candIter = thisSquare->candidates.begin(); candIter != thisSquare->candidates.end(); ++candIter) {
			thisSquare->setValue(*candIter);
			backtrackResult = backtrackRecurHelper(toSolve.getSquareAt(toSolve.findIndex(thisSquare->getPosition()) + 1));
			if (backtrackResult) {
				//Somewhere below us in the callstack the last value was successfully placed.
				return true;
			}
			//The candidate we placed was wrong, try the next one.
		}
		//No candidates can be placed, an earlier square must be wrong.
		thisSquare->setValue(0);
		return backtrackResult;
	}

	//This line should not be called
	return false;
}

void Solver::findCandidatesSquare(std::shared_ptr<Square> thisSquare) {
	if (!thisSquare->isClue()) {
		//Check each position in this square's groups for values. If a non-zero value is found, remove from candidates
		for (std::set<Position>::iterator groupsIter = thisSquare->groups.begin(); groupsIter != thisSquare->groups.end(); ++groupsIter) {
			int tempVal = toSolve.getSquareAt(*groupsIter)->getValue();
			if (tempVal != 0) {
				thisSquare->candidates.erase(tempVal);
			}
		}
	}
}

int Solver::gradeBoard() {
	updateCandidates();
	return 0;
}
