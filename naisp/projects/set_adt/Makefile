CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -g
TARGET = set_demo
SOURCES = main.c set.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all run clean valgrind

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c set.h
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)
