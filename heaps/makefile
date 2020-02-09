CC = g++
CFLAGS  = -g -Wall
RM = rm

default: heap

heap: heap.o heap_implementor.o
	$(CC)  $(CFLAGS) -o bin/heap  heap_implementor.o heap.o

heap_implementor.o: heap_implementor.cpp heap.h
	$(CC) $(CFLAGS) -c heap_implementor.cpp

heap.o: heap.cpp heap.h
	$(CC) $(CFLAGS) -c heap.cpp

clean:
	$(RM) bin/heap *.o