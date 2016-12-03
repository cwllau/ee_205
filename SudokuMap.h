/*  File: Sudoku.h 
     Sudoku with 9x9, 16x16, 25x15 dimension */

#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

class SudokuPuzzle{
    
    public:
    SudokuPuzzle(int size);
    
    void InputPuzzle();
    void LoadPuzzle();
    void GeneratePuzzle();
    
    void PrintPuzzle();
    
    // int Isfixed(const int &x, const int &y);
    
    void Setblock(const int &x, const int &y, const int &num);
    void remove(const int &x, const int&y);
    bool isSafe(const int &x,const int &y, const int &num) const;
    bool isOnlySolution(const int &x,const int &y, const int &num) const;
    
    int Getblock(const int &x, const int &y) const;
    
    int size() const;
    bool isfull() const;
    
    private:
    bool CheckHorizontal(const int &x,const int &y, const int &num) const;
    bool CheckVertical(const int &x,const int &y, const int &num) const;
    bool CheckSquare(const int &x,const int &y, const int &num) const;
    
    vector < vector < int > > puzzle;
    int row;
    int column;
    
};
#endif