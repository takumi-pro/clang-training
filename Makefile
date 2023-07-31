TARGET = main
CC = gcc
OBJS = main.c vector.c
CFLAGS = 

.PHONY: all clean

main: main.o vector.o linked_list.o
	$(CC) $(CFLAGS) -o $@ main.o vector.o linked_list.o && ./$(TARGET)

main.o: main.c vector.h linked_list.h
	$(CC) $(CFLAGS) -c main.c

vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -c vector.c

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c

clean:
	rm -f $(TARGET)