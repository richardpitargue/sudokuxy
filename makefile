all: main
	./a.out

main: sudoku.c
	gcc sudoku.c

gui: gui_prep
	java -cp bin Main

gui_prep:
	javac -d bin src/*