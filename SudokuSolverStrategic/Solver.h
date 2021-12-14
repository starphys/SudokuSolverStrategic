#pragma once
#include "Board.h"

//Assume solver receives the board in an initialized state
class Solver
{
private:
	Board toSolve;

	void updateCandidates();
	void findCandidatesSquare(std::shared_ptr<Square> thisSquare);
	bool backtrackRecurHelper(std::shared_ptr<Square> thisSquare);

public:
	Solver(Board newBoard);
	~Solver();

	bool nakedSingles();
	bool backtrack();
	int gradeBoard();
};

