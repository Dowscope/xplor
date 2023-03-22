VERSION = c++20
INPUT_FILES = main.cpp
OUTPUT_FILE = game.run

LIBS = -lSDL2 -lSDL2main -lstdc++

main:
	gcc -std=$(VERSION) $(INPUT_FILES) -o $(OUTPUT_FILE) $(LIBS)

clear:
	rm game.run