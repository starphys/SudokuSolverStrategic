#include "SudokuHeaders.h"

int main(void) {
	Board toSolve{};
	toSolve.printBoard();

	PuzzleMaker maker {&toSolve};

	std::fstream fin;
	fin.open("sudokutosolve1.csv", std::fstream::in);

	maker.fillFromCSV(fin);
	toSolve.printBoard();

	Solver puzzleSolver{ toSolve };
	puzzleSolver.gradeBoard();
	puzzleSolver.nakedSingles();
	toSolve.printBoard();

	puzzleSolver.gradeBoard();
	puzzleSolver.nakedSingles();
	toSolve.printBoard();

	puzzleSolver.gradeBoard();
	puzzleSolver.nakedSingles();
	toSolve.printBoard();

	return 0;
}