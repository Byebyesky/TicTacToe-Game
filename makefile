CC=g++
CFLAGS=-pedantic -Wall -std=c++0x
SOURCES=main.cpp board.cpp
EXECUTABLE=tictactoe

all: $(SOURCES) $(EXECUTABLE)

clean:
	rm -r tictactoe*
    
$(EXECUTABLE): $(SOURCES) 
	$(CC) $(CFLAGS) $(SOURCES) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@