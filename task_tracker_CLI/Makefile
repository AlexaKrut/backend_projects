CC=g++
CFLAGS= -Wall -Werror -Wextra
LFLAGS=-o

SOURCES=./src/cli.cpp ./src/json.cpp ./src/main.cpp ./src/utils.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=cli

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LFLAGS) $@ $^

.cpp.o:
	$(CC) $(CFLAGS) $<

clean:
	rm -f *.o $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)