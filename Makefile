CC = gcc
LDFLAGS = -lglut -lGL -lm
SOURCES = *.c
EXECUTABLE = main

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(SOURCES) 
	$(CC) $(SOURCES) -o $@ $(LDFLAGS)
