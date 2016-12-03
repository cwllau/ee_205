/*  File: Solver.h 
     Solve an sudoku with 9x9, 16x16, 25x15 dimension*/

#ifndef SOLVER_H
#define SOLVER_H

#include "SudokuMap.h"

class Solver{
    
    public:
    Solver(const SudokuPuzzle &p);
    ~Solver();
    
    void setSoduku(const SudokuPuzzle &p);
    
    bool NatrualSolve();
    bool SolvePuzzle(int startx = 0, int starty = 0);
    
    void PrintSolvedPuzzle();
    
    private:
    SudokuPuzzle puzzle;
};
#endif