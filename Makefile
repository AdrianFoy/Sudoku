objects = main.o viewer.o board.o
CC = g++

sudoku : $(objects)
	$(CC) -o sudoku $(objects)

main.o : sudokuglobals.h viewer.h
viewer.o : sudokuglobals.h
board.o : sudokuglobals.h
clean :
	rm sudoku $(objects)