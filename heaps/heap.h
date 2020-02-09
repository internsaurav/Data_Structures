#ifndef HEAP_H
#define HEAP_H
#include <cstddef>
struct heap{
	int heap_size;
	int length;
	const int* elms;
};
int leftChild(int i, int* elms, int heapSize);
int rightChild(int i, int* elms, int heapSize);
heap initHeap(int length, const int *elms);
bool verifyMaxHeap(heap A);
bool verifyMinHeap(heap A);
#endif