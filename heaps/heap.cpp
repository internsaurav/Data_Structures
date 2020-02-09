#include "heap.h"

heap initHeap(int length, const int *elms){
	heap h;
	h.heap_size = length;
	h.length = length;
	h.elms = elms;
	return h;
}

/* Return left child if available, else null */
int leftChild(int i, const int* elms, int heapSize){
	if (2*i+1 < heapSize){
		return elms[2*i+1];
	}
	return NULL;
}

/* Return left child if available, else null */
int rightChild(int i, const int* elms, int heapSize){
	if (2*i+2 < heapSize){
		return elms[2*i+2];
	}
	return NULL;
}

/*
Verifies Max Heap order property for subtree rooted at element i
*/
bool verifyMaxHeap(int i, const int* elms, int heapSize){
	if (i >= heapSize-1)
		return true;

	int leftChild_i = leftChild(i, elms, heapSize);
	int rightChild_i = rightChild(i, elms, heapSize);
	if (leftChild_i != NULL && elms[i] < leftChild_i)
		return false;

	if (rightChild_i != NULL && elms[i] < rightChild_i)
		return false;

	return (verifyMaxHeap(2*i+1, elms, heapSize) && verifyMaxHeap(2*i+2, elms, heapSize));
}

bool verifyMaxHeap(heap A){
	if (A.heap_size < 2)
		return true;
	return verifyMaxHeap(0, A.elms, A.heap_size);
}

/*
Verifies Min Heap order property for subtree rooted at element i
*/
bool verifyMinHeap(int i, const int* elms, int heapSize){
	if (i >= heapSize-1)
		return true;

	int leftChild_i = leftChild(i, elms, heapSize);
	int rightChild_i = rightChild(i, elms, heapSize);
	if (leftChild_i != NULL && elms[i] > leftChild_i)
		return false;

	if (rightChild_i != NULL && elms[i] > rightChild_i)
		return false;

	return (verifyMinHeap(2*i+1, elms, heapSize) && verifyMinHeap(2*i+2, elms, heapSize));
}

bool verifyMinHeap(heap A){
	if (A.heap_size < 2)
		return true;
	return verifyMinHeap(0, A.elms, A.heap_size);
}

/*
Floats the element at i downwards so that heap property is maintained
Assumptions - Child nodes of element at i are max-heaps
*/
void max_heapify(heap A, int i){

}