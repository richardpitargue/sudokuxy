all: gui_prep
	java -cp bin Main

gui_prep:
	javac -d bin src/*
