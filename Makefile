TARGET = main
CC = gcc
OBJS = main.c vector.c
CFLAGS = 

.PHONY: all clean

main: main.o vector.o
	$(CC) $(CFLAGS) -o $@ main.o vector.o && ./$(TARGET)

main.o: main.c vector.h
	$(CC) $(CFLAGS) -c main.c

vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -c vector.c

clean:
	rm -f $(TARGET)