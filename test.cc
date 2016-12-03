#include "Solver.h"
#include "SudokuMap.h"

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <time.h>

int main(){
    int n=0;
    int size=0;
    time_t now;
    time_t later;
    cout << "Enter the size of your Sudoku: " ;
    cin >> size;
    
    SudokuPuzzle p(size);
    while (n != 1 && n != 2){
        cout << "Press 1 to Input Puzzle manually" << endl;
        cout << "Press 2 to load puzzle file" << endl;
        // cout << "Press 3 to generate puzzle(Not Implemented Yet)" << endl;
        cin >> n;
    }
    cin.ignore(1,'\n');
    if (n == 1){
        p.InputPuzzle();
    }else{
        p.LoadPuzzle();
    }
    p.PrintPuzzle();
    
    Solver s(p);

    cout << endl;
    time(&now);
    if (s.NatrualSolve()){
        cout << "Puzzle Solved Successful" << endl;
    }else{
    
        if (s.SolvePuzzle()){
            cout << "Puzzle Solved Successful" << endl;
        }else{
            cout << "Puzzle Solved Unsuccessful" << endl;
        }
    }
    time(&later);
    
    s.PrintSolvedPuzzle();
    cout << "Time used " << (later-now) << " Seconds" << endl;
    // cout << "Original Puzzle" << endl;
    
    // p.PrintPuzzle();
};