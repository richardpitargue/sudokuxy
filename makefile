all: main
	./a.out

main: sudoku.c
	gcc sudoku.c
