#include "SudokuHeaders.h"

int main(void) {
	Board toSolve{};
	toSolve.printBoard();

	PuzzleMaker maker {&toSolve};

	std::fstream fin;
	fin.open("sudokutosolve3.csv", std::fstream::in);

	maker.fillFromCSV(fin);
	toSolve.printBoard();

	Solver puzzleSolver{ toSolve };
	//May be unnecessary
	puzzleSolver.gradeBoard();

	if (puzzleSolver.backtrack())
		std::cout << "Success.\n";
	else
		std::cout << "Failure.\n";
	
	toSolve.printBoard();

	return 0;
}