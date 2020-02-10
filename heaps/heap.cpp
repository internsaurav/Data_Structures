#include "heap.h"

heap initHeap(int length, int *elms){
	heap h;
	h.heap_size = length;
	h.length = length;
	h.elms = elms;
	return h;
}

/* Return left child if available, else null */
int leftChild(int i, int* elms, int heapSize){
	if (2*i+1 < heapSize){
		return elms[2*i+1];
	}
	return NULL;
}

int leftChildIdx(int i, int heapSize){
	int NOT_FOUND = -1;
	if (2*i+1 < heapSize){
		return 2*i+1;
	}
	return NOT_FOUND;
}

/* Return left child if available, else null */
int rightChild(int i, int* elms, int heapSize){
	if (2*i+2 < heapSize){
		return elms[2*i+2];
	}
	return NULL;
}

int rightChildIdx(int i, int heapSize){
	int NOT_FOUND = -1;
	if (2*i+2 < heapSize){
		return 2*i+2;
	}
	return NOT_FOUND;
}

/*
Verifies Max Heap order property for subtree rooted at element i
*/
bool verifyMaxHeap(int i, int* elms, int heapSize){
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
bool verifyMinHeap(int i, int* elms, int heapSize){
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
Floats the element at i downwards so that max-heap property is maintained
Assumptions - Child nodes of element at i are max-heaps
*/
void max_heapify(heap A, int i){
	int NULL_CHILD = -1;
	//Last Element
	if (i >= A.heap_size-1)
		return;

	bool maxHeapPropertySatisfied = false;
	while(maxHeapPropertySatisfied == false){
		maxHeapPropertySatisfied = true;
		int largest = i;
		int leftChild_idx = leftChildIdx(i,A.heap_size);
		int rightChild_idx = rightChildIdx(i, A.heap_size);

		if (leftChild_idx != NULL_CHILD && A.elms[largest] < A.elms[leftChild_idx]){
			largest = leftChild_idx;
			maxHeapPropertySatisfied = false;
		}

		if (rightChild_idx != NULL_CHILD && A.elms[largest] < A.elms[rightChild_idx]){
			largest = rightChild_idx;
			maxHeapPropertySatisfied = false;
		}

		if (maxHeapPropertySatisfied == false){
			int temp = A.elms[i];
			A.elms[i] = A.elms[largest];
			A.elms[largest] = temp;
			i = largest;
		}
	}
}

/*
Floats the element at i downwards so that min-heap property is maintained
Assumptions - Child nodes of element at i are min-heaps
*/
void min_heapify(heap A, int i){
	int NULL_CHILD = -1;
	//Last Element
	if (i >= A.heap_size-1)
		return;

	bool minHeapPropertySatisfied = false;
	while(minHeapPropertySatisfied == false){
		minHeapPropertySatisfied = true;
		int smallest = i;
		int leftChild_idx = leftChildIdx(i,A.heap_size);
		int rightChild_idx = rightChildIdx(i, A.heap_size);

		if (leftChild_idx != NULL_CHILD && A.elms[smallest] > A.elms[leftChild_idx]){
			smallest = leftChild_idx;
			minHeapPropertySatisfied = false;
		}

		if (rightChild_idx != NULL_CHILD && A.elms[smallest] > A.elms[rightChild_idx]){
			smallest = rightChild_idx;
			minHeapPropertySatisfied = false;
		}

		if (minHeapPropertySatisfied == false){
			int temp = A.elms[i];
			A.elms[i] = A.elms[smallest];
			A.elms[smallest] = temp;
			i = smallest;
		}
	}
}