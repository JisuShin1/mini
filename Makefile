CC = gcc
CFLAGS = -W -Wall
TARGET = main
OBJECTS = main.o product.o manager.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm *.o main
