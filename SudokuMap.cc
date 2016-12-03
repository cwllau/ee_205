#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <math.h>
#include "SudokuMap.h"

using namespace std;

SudokuPuzzle::SudokuPuzzle(int size){
    row = size;
    column = size;
    puzzle.resize( column , vector<int>( row, 0 ) );
}

void SudokuPuzzle::Setblock(const int &x, const int &y, const int &num){
    puzzle[x][y] = num;
}

void SudokuPuzzle::remove(const int &x, const int &y){
    puzzle[x][y] = 0;
}

bool SudokuPuzzle::isSafe(const int &x,const int &y, const int &num) const{
    if (CheckHorizontal(x, y, num) && CheckVertical(x, y, num) && CheckSquare(x, y, num)) // Lazy evaluation guarantees efficient handling
        return true;
    else
        return false;
}

bool SudokuPuzzle::isOnlySolution(const int &x,const int &y, const int &num) const{
    bool valid = (puzzle[x][y] == 0);
    bool unique_column,unique_horizontal = true;
    int i,j,k;
    k=0;
    if (CheckSquare(x,y,num) && valid){
        int startx, starty; // Position of the first element in a block
        int boxlength = sqrt(row);
        // cout << "boxlength is " << boxlength << endl;
        startx = x - (x % boxlength); 
        starty = y - (y % boxlength);
        // cout << x << y << " " << num << " starting at block " << startx << starty << startx+boxlength << endl;
        for (i = 0; i < row;i++){
            if (i != x){
                if (puzzle[i][y] == 0){
                    unique_column = false;
                }
            }
        }
        for (j = 0; j < column;j++){
            if (j != y){
                if (puzzle[x][j] == 0){
                    unique_horizontal = false;
                }
            }
        }
        if (unique_column || unique_horizontal){
            return true;
        }
        for (i = startx; ((i < startx+boxlength));i++){
            for (j = starty;j < starty+boxlength;j++){
                if (!(i ==  x && j == y)){
                    // cout << i << j << endl;
                    if (isSafe(i,j,num)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }else{
        return false;
    }
}

int SudokuPuzzle::Getblock(const int &x, const int &y) const{
    return puzzle[x][y];
}

void SudokuPuzzle::PrintPuzzle(){
    int i,j;
    for (i = 0;i<row;i++){
        for (j = 0;j<column;j++){
            cout << puzzle[i][j] <<"  ";
        }
        cout << endl;
    }
}

int SudokuPuzzle::size() const{
    return row;
}

bool SudokuPuzzle::isfull() const{
    bool full = true;
    
    for (int i = 0; full && i < row; ++i)
        for (int j = 0; full && j < column; ++j)
            full = (puzzle[i][j] != 0);
    
    return full;
}

void SudokuPuzzle::InputPuzzle(){

	std::cout<<"Fill the SudokuMap, space for empty element"<<std::endl;

	std::string SKLine="";

	for(int line=0;line<row;line++){
		std::cout<<"Line "<<line+1<<":";
// 		cout << endl;
        std::getline(std::cin, SKLine);
        
    //     if (line == 0)SKLine=("   26 7 1");
    // 	if (line == 1)SKLine=("68  7  9 ");
    // 	if (line == 2)SKLine=("19   45  ");
    // 	if (line == 3)SKLine=("82 1   4 ");
    // 	if (line == 4)SKLine=("  46 29  ");
    // 	if (line == 5)SKLine=(" 5   3 28");
    // 	if (line == 6)SKLine=("  93   74");
    // 	if (line == 7)SKLine=(" 4  5  36");
    // 	if (line == 8)SKLine=("7 3 18   ");
    	
    	for(int i=0;i<SKLine.size();i++){
    		if(SKLine.at(i)==' ')puzzle[line][i]=0;
    		else puzzle[line][i]=SKLine[i]-48;
    	}

		SKLine="";
	}
}

void SudokuPuzzle::LoadPuzzle(){
    FILE * fp;
    char fname[100];
    int i,j;
    cout << "Enter the name of the puzzle file: ";
    cin >> fname;
    fp = fopen(fname,"r");
    if (fp==NULL) {
        printf("File %s didn't open\n",fname);
        exit(1);
    }
    for (i=0;i<row;i++){
        for (j=0;j<column;j++){
            fscanf(fp,"%d",&puzzle[i][j]);
        }
    }
    fclose(fp);
}

void SudokuPuzzle::GeneratePuzzle(){
    
}

/* Private functions */
bool SudokuPuzzle::CheckHorizontal(const int &x,const int &y, const int &num) const{
    bool valid = (puzzle[x][y] == 0); // Position can't be already filled in
    
    for (int i = 0; valid && i < column; i++)
        valid = (puzzle[x][i] != num);
    
    return valid;
}

bool SudokuPuzzle::CheckVertical(const int &x,const int &y, const int &num) const{
    bool valid = (puzzle[x][y] == 0); // Position can't be already filled in
    
    for (int i = 0; valid && i < row; i++)
        valid = (puzzle[i][y] != num);
    
    return valid;
}

bool SudokuPuzzle::CheckSquare(const int &x,const int &y, const int &num) const{
    bool valid = (puzzle[x][y] == 0);
    int startx, starty; // Position of the first element in a block
    int boxlength = sqrt(row);
    // cout << "boxlength is " << boxlength << endl;
    startx = x - (x % boxlength); 
    starty = y - (y % boxlength);
    
    for (int i = starty; valid && (i % boxlength != 0 || i == starty); i++) // While not in the next block, and not at end of the board
        for (int j = startx; valid && (j % boxlength != 0 || j == startx); j++)
            valid = (puzzle[j][i] != num);
    
    return valid;
}