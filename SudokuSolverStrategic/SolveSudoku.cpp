#include "SudokuHeaders.h"

int main(void) {
	Board toSolve{};
	PuzzleMaker maker {&toSolve};

	std::fstream fin;
	fin.open("sudokutosolve3.csv", std::fstream::in);

	maker.fillFromCSV(fin);
	std::cout << "Puzzle Initialized from CSV:\n";
	toSolve.printBoard();

	Solver puzzleSolver{ toSolve };

	std::cout << "Puzzle Difficulty = " << puzzleSolver.gradeBoard() << "\n";

	/*
	if (puzzleSolver.backtrack())
		std::cout << "Success.\n";
	else
		std::cout << "Failure.\n";
	*/

	return 0;
}