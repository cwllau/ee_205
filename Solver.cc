#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "SudokuMap.h"
#include "Solver.h"
#include <math.h>
using namespace std;

Solver::Solver(const SudokuPuzzle &p):puzzle(p){
    
}

Solver::~Solver(){
    
}

void Solver::PrintSolvedPuzzle(){
    puzzle.PrintPuzzle();
}

bool Solver::NatrualSolve(){
    bool found = true;
    
    int size;
    size = puzzle.size();
    bool possibleSolutions[size][size][size+1]; // Possibilities of each block
    for (int y = 0; y < size; y++) // Initialization
        for (int x = 0; x < size; x++) {
            possibleSolutions[x][y][0] = false;
            for (int e = 1; e < size+1; e++)
                possibleSolutions[x][y][e] = true;
        }
    
    while (!puzzle.isfull() && found) { // While we still found possible moves
        found = false; 
        for (int y = 0; y < size; y++)
            for (int x = 0; x < size; x++) {
                for (int e = 1; e < size+1; e++) { 
                    if (possibleSolutions[x][y][e]) { 
                        possibleSolutions[x][y][e] = puzzle.isSafe(x, y, e);
                        if (possibleSolutions[x][y][e]) 
                            if (puzzle.isOnlySolution(x,y,e)){   //Look for Singles
                                puzzle.Setblock(x, y, e);
                                PrintSolvedPuzzle();
                                cout << endl;
                                possibleSolutions[x][y][e]=false;
                                found = true;
                                break;
                            }
                    }
                }
            }
    }
    
    return puzzle.isfull();
}


bool Solver::SolvePuzzle(int startx, int starty){    /*BackTracking*/
    PrintSolvedPuzzle();
    cout << endl;
    bool solved = puzzle.isfull(); // If we are at a leaf we have to return true, because the board is filled
    bool foundzero = false;
    int x = startx, y;
    
    for (y = starty; !solved && !foundzero && y < puzzle.size(); y++) { // Find the first element that is not filled in (we are working recursively)
        for (x = startx; !foundzero && x < puzzle.size(); x++)
            foundzero = (puzzle.Getblock(x, y) == 0);
        startx = 0;
    }
    x--;
    y--;
    
    if (!solved && foundzero) { // Only if there is a 0 found we can still backtrack, else: end this recursion
        for (int e = 1; e < puzzle.size()+1 && !solved; e++)
            if (puzzle.isSafe(x, y, e)) {
                puzzle.Setblock(x, y, e);
                if (SolvePuzzle( x + 1, y))
                    solved = true;
                else
                    puzzle.remove(x, y);
            }
    }

    return solved;
}