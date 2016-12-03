
CCC = g++
CCFLAGS = -ansi

sudoku: test.o Solver.o SudokuMap.o 
	$(CCC) -o sudoku test.o Solver.o SudokuMap.o 

test.o: Solver.h

Solver.o: Solver.h 

SudokuMap.o: SudokuMap.h

clean:
	rm -f *.o

real_clean: clean
	rm -f sudoku