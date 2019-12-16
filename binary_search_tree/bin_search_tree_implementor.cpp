#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include "bin_search_tree.h"
#include <vector>
#include "utils.h"
using namespace std;

void generateRandomArray(int* empty, int length){
	srand (time(NULL));
	for (int i=0; i<length; i++){
		empty[i] = rand();
	}
}

void testCase(vector<int> nodeElements){
	node* nodes = NULL;
	node* tree = NULL;

	int length = nodeElements.size();
	cout << "Num Elements: " << length <<"\n";
	nodes = new node[length];
	cout << "Elements being inserted: ";
	for (int j=0; j < length; j++){
		cout << nodeElements.at(j) << ",";
		nodes[j] = {nodeElements.at(j), NULL, NULL, NULL};
		tree_insert(&tree, &nodes[j]);
	}
	cout << "\n";
	cout << "In-order Traversal: ";
	in_order_tree_walk(&tree);
	tree = NULL;
	delete[] nodes;
	cout << "\n";

}

int main(int argc, char** argv){
	vector<vector<int>> arrays = readArrays(argv[1]);
	cout << "Num Testcases: " << arrays.size()<<"\n";
	int caseNum = 0;
	for (vector<vector<int>>::const_iterator i = arrays.begin(); i != arrays.end(); ++i){
		cout << "Case number: " <<  ++caseNum << "\n";
		testCase(*i);
	}
	return 0;
}

