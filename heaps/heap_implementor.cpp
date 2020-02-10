#include "heap.h"
#include <iostream>

void testInitHeap(){
	std:: cout << "testInitHeap\n";
	int caseNum =1;
	std::cout << "Case " << caseNum << "\n";
	int arr[] = {16};
	int length = 1;
	heap h = initHeap(length, arr);
	std::cout << (h.heap_size == 1);
	std::cout << (h.length == 1);
	std::cout << (h.elms[0] == 16);
	std::cout << "\n";

	caseNum =2;
	std::cout << "Case " << caseNum << "\n";
	int arr2[] = {16,4,10,14,7,9,3};
	length = 7;
	h = initHeap(length, arr2);
	std::cout << (h.heap_size == 7);
	std::cout << (h.length == 7);
	std::cout << (h.elms[0] == 16);
	std::cout << (h.elms[3] == 14);
	std::cout << (h.elms[6] == 3);
	std::cout << "\n";
}

void verifyMaxHeapTest(){
	std:: cout << "verifyMaxHeapTest\n";
	int caseNum =1;
	std::cout << "Case " << caseNum << "\n";
	int arr[] = {5,4,3,2,1};
	int length = 5;
	heap h = initHeap(length, arr);
	std::cout << (verifyMaxHeap(h) == true); 
	std::cout << "\n";

	caseNum =2;
	std::cout << "Case " << caseNum << "\n";
	int arr2[] = {5,4,30,2,1};
	length = 5;
	h = initHeap(length, arr2);
	std::cout << (verifyMaxHeap(h) == false); 
	std::cout << "\n";

	caseNum =3;
	std::cout << "Case " << caseNum << "\n";
	int arr3[] = {5};
	length = 1;
	h = initHeap(length, arr3);
	std::cout << (verifyMaxHeap(h) == true); 
	std::cout << "\n";

	caseNum =4;
	std::cout << "Case " << caseNum << "\n";
	int arr4[] = {5,4};
	length = 2;
	h = initHeap(length, arr4);
	std::cout << (verifyMaxHeap(h) == true); 
	std::cout << "\n";

	caseNum =5;
	std::cout << "Case " << caseNum << "\n";
	int arr5[] = {5,4,6};
	length = 3;
	h = initHeap(length, arr5);
	std::cout << (verifyMaxHeap(h) == false); 
	std::cout << "\n";

	caseNum =6;
	std::cout << "Case " << caseNum << "\n";
	int arr6[] = {5,5,5,5,5};
	length = 5;
	h = initHeap(length, arr6);
	std::cout << (verifyMaxHeap(h) == true); 
	std::cout << "\n";
}

void verifyMinHeapTest(){
	std:: cout << "verifyMinHeapTest\n";
	int caseNum =1;
	std::cout << "Case " << caseNum << "\n";
	int arr[] = {5,4,3,2,1};
	int length = 5;
	heap h = initHeap(length, arr);
	std::cout << (verifyMinHeap(h) == false); 
	std::cout << "\n";

	caseNum =2;
	std::cout << "Case " << caseNum << "\n";
	int arr2[] = {5,4,30,2,1};
	length = 5;
	h = initHeap(length, arr2);
	std::cout << (verifyMinHeap(h) == false); 
	std::cout << "\n";

	caseNum =3;
	std::cout << "Case " << caseNum << "\n";
	int arr3[] = {5};
	length = 1;
	h = initHeap(length, arr3);
	std::cout << (verifyMinHeap(h) == true); 
	std::cout << "\n";

	caseNum =4;
	std::cout << "Case " << caseNum << "\n";
	int arr4[] = {5,4};
	length = 2;
	h = initHeap(length, arr4);
	std::cout << (verifyMinHeap(h) == false); 
	std::cout << "\n";

	caseNum =5;
	std::cout << "Case " << caseNum << "\n";
	int arr5[] = {5,4,6};
	length = 3;
	h = initHeap(length, arr5);
	std::cout << (verifyMinHeap(h) == false); 
	std::cout << "\n";

	caseNum =6;
	std::cout << "Case " << caseNum << "\n";
	int arr6[] = {5,5,5,5,5};
	length = 5;
	h = initHeap(length, arr6);
	std::cout << (verifyMinHeap(h) == true); 
	std::cout << "\n";

	caseNum =7;
	std::cout << "Case " << caseNum << "\n";
	int arr7[] = {1,2,3,4,5};
	length = 5;
	h = initHeap(length, arr7);
	std::cout << (verifyMinHeap(h) == true); 
	std::cout << "\n";

	caseNum =8;
	std::cout << "Case " << caseNum << "\n";
	int arr8[] = {55,77,66,22,33,66,66};
	length = 7;
	h = initHeap(length, arr8);
	std::cout << (verifyMinHeap(h) == false); 
	std::cout << "\n";

	caseNum =9;
	std::cout << "Case " << caseNum << "\n";
	int arr9[] = {55,77,66,122,133,66,66};
	length = 7;
	h = initHeap(length, arr9);
	std::cout << (verifyMinHeap(h) == true); 
	std::cout << "\n";
}

void verifyMaxHeapifyUnit(int caseNum, int length, int* arr, int destroyer, bool debugPrint){
	std::cout << "Case " << caseNum << "\n";
	heap h = initHeap(length, arr);
	if(debugPrint == true)
		std::cout << "Previous state is not max-heapified: " << (verifyMaxHeap(h) == false) << "\n";
	max_heapify(h, destroyer);
	if(debugPrint == true)
		std::cout << "New state is max-heapified: " << (verifyMaxHeap(h) == true) << "\n";
	if(debugPrint == true){
		std::cout << "Printing Array\n";
		for (int x=0; x< length; x++){
			std::cout << h.elms[x] << " | ";
		}
	}
	if (verifyMaxHeap(h) == true)
		std::cout << "PASS";
	else
		std::cout << "Fail";
	std::cout << "\n";
}

void verifyMinHeapifyUnit(int caseNum, int length, int* arr, int destroyer, bool debugPrint){
	std::cout << "Case " << caseNum << "\n";
	heap h = initHeap(length, arr);
	if(debugPrint == true)
		std::cout << "Previous state is not min-heapified: " << (verifyMinHeap(h) == false) << "\n";
	min_heapify(h, destroyer);
	if(debugPrint == true)
		std::cout << "New state is min-heapified: " << (verifyMinHeap(h) == true) << "\n";
	if(debugPrint == true){
		std::cout << "Printing Array\n";
		for (int x=0; x< length; x++){
			std::cout << h.elms[x] << " | ";
		}
	}
	if (verifyMinHeap(h) == true)
		std::cout << "PASS";
	else
		std::cout << "Fail";
	std::cout << "\n";
}

void verifyMaxHeapifyTest(){
	std:: cout << "verifyMaxHeapifyTest\n";
	int caseNum =0;
	verifyMaxHeapifyUnit(++caseNum, 7, new int[7]{5,4,3,2,1,4,3},2, false);
	verifyMaxHeapifyUnit(++caseNum, 11, new int[11]{10,30,20,28,29,20,20,25,20,20,20},0, false);
	verifyMaxHeapifyUnit(++caseNum, 2, new int[2]{10,30},0, false);
	verifyMaxHeapifyUnit(++caseNum, 1, new int[1]{10},0, false);
}

void verifyMinHeapifyTest(){
	std:: cout << "verifyMaxHeapifyTest\n";
	int caseNum =0;
	verifyMinHeapifyUnit(++caseNum, 1, new int[1]{10},0, false);
	verifyMinHeapifyUnit(++caseNum, 2, new int[2]{30,10},0, false);
	verifyMinHeapifyUnit(++caseNum, 9, new int[9]{10,40,30,25,26,35,36,35,35},1, false);
}

int main(int argc, char const *argv[]){
	verifyMinHeapifyTest();
}