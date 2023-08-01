TARGET = main
CC = gcc
OBJS = main.o vector.o linked_list.o
CFLAGS = 

.PHONY: all clean

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(TARGET)