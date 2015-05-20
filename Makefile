CC      = g++
CFLAGS  = -std=c++11 -Wall -lncurses -c
LFLAGS  = -lncurses

TARGET 	= a
OBJECTS = main.o curses.o
SOURCES = $(OBJECTS:.o=.cpp)
HEADERS = $(OBJECTS:.o=.h)

# Link objects
all: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $(TARGET)

# Compile sources & headers to object modules
$(OBJECTS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(HEADERS) $(SOURCES)

# Destroy all object modules
clean:
	rm -rf *.o *.gch bj