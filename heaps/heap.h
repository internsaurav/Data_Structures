#ifndef HEAP_H
#define HEAP_H
#include <cstddef>
struct heap{
	int heap_size;
	int length;
	int* elms;
};
int leftChild(int i, int* elms, int heapSize);
int rightChild(int i, int* elms, int heapSize);
heap initHeap(int length, int *elms);
bool verifyMaxHeap(heap A);
bool verifyMinHeap(heap A);
void max_heapify(heap A, int i);
void min_heapify(heap A, int i);
#endif