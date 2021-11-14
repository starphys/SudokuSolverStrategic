#pragma once
#include "Board.h"

//Assume solver receives the board in an initialized state
class Solver
{
private:
	Board toSolve;

	void updateCandidates();

public:
	Solver(Board newBoard);
	~Solver();

	bool nakedSingles();
	int gradeBoard();
};

