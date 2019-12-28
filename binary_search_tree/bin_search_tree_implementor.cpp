#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <vector>
#include "utils.h"
#include "breadth_first_search.h"
#include "bin_search_tree.h"
using namespace std;

void generateRandomArray(int* empty, int length){
	srand (time(NULL));
	for (int i=0; i<length; i++){
		empty[i] = rand();
	}
}

void nodePrinter(node* nodeToPrint, int reachLevel){
	if(nodeToPrint == NULL){
		cout << "NULL\n";
	} else {
		cout << "Key: " << nodeToPrint->key << "\n";
		if(reachLevel > 0){
			reachLevel -= 1;
			cout << "Parent ";
			nodePrinter(nodeToPrint->p, reachLevel);
			cout << "Left ";
			nodePrinter(nodeToPrint->left, reachLevel);
			cout << "Right ";
			nodePrinter(nodeToPrint->right, reachLevel);
		}
	}
}

void do_in_order_tree_walk(node* tree){
		cout << "In-order Traversal: ";
		in_order_tree_walk(&tree);
}

void tree_search_query_cases(node* tree){
	node* found_node = NULL;
	int k = -1;
	cout << "Looking for " << k << "\n";
	found_node = tree_search_iterative(k, &tree);
	nodePrinter(found_node, 1);
	k = -5;
	cout << "Looking for " << k << "\n";
	found_node = tree_search_iterative(k, &tree);
	nodePrinter(found_node, 1);
	k = 15;
	cout << "Looking for " << k << "\n";
	found_node = tree_search_iterative(k, &tree);
	nodePrinter(found_node, 1);
	k = 17;
	cout << "Looking for " << k << "\n";
	found_node = tree_search_iterative(k, &tree);
	nodePrinter(found_node, 1);
	k=44;
	cout << "Looking for " << k << "\n";
	found_node = tree_search_iterative(k, &tree);
	nodePrinter(found_node, 1);
}

void successor_cases(node* z){
	cout << "finding successor for ";
	nodePrinter(z, 1);
	node* successor_z = successor(z);
	cout << "Successor: ";
	nodePrinter(successor_z, 1);
}

void testCase(vector<int> nodeElements){
	node* nodes = NULL;
	node* tree = NULL;

	int length = nodeElements.size();
	// cout << "Num Elements: " << length <<"\n";
	int randomNodeIndex = -1;
	cout << "Enter index of node for which I need to find the successor: ";
	cin >> randomNodeIndex;
	node* randomNode = NULL;
	nodes = new node[length];
	// cout << "Elements being inserted: ";
	for (int j=0; j < length; j++){
		// cout << nodeElements.at(j) << ",";
		nodes[j] = {nodeElements.at(j), NULL, NULL, NULL};
		tree_insert(&tree, &nodes[j]);
		if(j == randomNodeIndex)
			randomNode = &nodes[j];
	}
	// cout << "\n";
	// do_in_order_tree_walk();
	cout << "Breadth-First Traversal: ";
	bfs_binary_tree(&tree);
	cout << "\n";
	// tree_search_query_cases(tree);
	successor_cases(randomNode);

	tree = NULL;
	delete[] nodes;
	cout << "\n";

}

void successor_test(vector<int> nodeElements, int idxOfElmToFindSuccessorFor, int idxOfSuccessor){
	node* tree = NULL;
	node* nodes = new node[nodeElements.size()];
	node* elmToFindSuccessorFor = NULL;
	node* successor_actual = NULL;

	for (int j=0; j < (int)nodeElements.size(); j++){
		nodes[j] = {nodeElements.at(j), NULL, NULL, NULL};
		tree_insert(&tree, &nodes[j]);
		if(j == idxOfElmToFindSuccessorFor)
			elmToFindSuccessorFor = &nodes[j];

		if(j == idxOfSuccessor)
			successor_actual = &nodes[j];
	}

	node* successor_found = successor(elmToFindSuccessorFor);

	if(successor_actual == successor_found)
		cout << "Passed\n";
	else
		cout << "Failed\n";

	tree = NULL;
	delete[] nodes;
}

void successor_test_cases(){
	int caseNum = 0;
	int subCaseNum = 0;
	int idxOfElmToFindSuccessorFor = -1;
	int idxOfSuccessor = -1;
	vector<int> nodeElements;
	auto resetTestingParameters = [&](){
    nodeElements.clear();
    idxOfElmToFindSuccessorFor = -1;
    idxOfSuccessor = -1;
    subCaseNum = 0;
  };

	cout << "Case " << ++caseNum << ": ";
	nodeElements.push_back(5);
	idxOfElmToFindSuccessorFor = 0;
	successor_test(nodeElements, idxOfElmToFindSuccessorFor, idxOfSuccessor);
	resetTestingParameters();

	cout << "Case " << ++caseNum << ": ";
	nodeElements.push_back(5);
	nodeElements.push_back(6);
	idxOfElmToFindSuccessorFor = 0;
	idxOfSuccessor = 1;
	successor_test(nodeElements, idxOfElmToFindSuccessorFor, idxOfSuccessor);
	resetTestingParameters();

	cout << "Case " << ++caseNum << ": ";
	nodeElements.push_back(5);
	nodeElements.push_back(6);
	idxOfElmToFindSuccessorFor = 1;
	idxOfSuccessor = -1;
	successor_test(nodeElements, idxOfElmToFindSuccessorFor, idxOfSuccessor);
	resetTestingParameters();

	cout << "Case " << ++caseNum << ":\n";
	nodeElements.push_back(5);
	nodeElements.push_back(4);
	nodeElements.push_back(6);

	cout << "\tSubCase " << ++subCaseNum << ": ";
	idxOfElmToFindSuccessorFor = 0;
	idxOfSuccessor = 2;
	successor_test(nodeElements, idxOfElmToFindSuccessorFor, idxOfSuccessor);

	cout << "\tSubCase " << ++subCaseNum << ": ";
	idxOfElmToFindSuccessorFor = 1;
	idxOfSuccessor = 0;
	successor_test(nodeElements, idxOfElmToFindSuccessorFor, idxOfSuccessor);

	cout << "\tSubCase " << ++subCaseNum << ": ";
	idxOfElmToFindSuccessorFor = 2;
	idxOfSuccessor = -1;
	successor_test(nodeElements, idxOfElmToFindSuccessorFor, idxOfSuccessor);
	resetTestingParameters();

	cout << "Case " << ++caseNum << ":\n";
	nodeElements.push_back(4);
	nodeElements.push_back(5);
	nodeElements.push_back(6);

	cout << "\tSubCase " << ++subCaseNum << ": ";
	idxOfElmToFindSuccessorFor = 0;
	idxOfSuccessor = 1;
	successor_test(nodeElements, idxOfElmToFindSuccessorFor, idxOfSuccessor);

	cout << "\tSubCase " << ++subCaseNum << ": ";
	idxOfElmToFindSuccessorFor = 1;
	idxOfSuccessor = 2;
	successor_test(nodeElements, idxOfElmToFindSuccessorFor, idxOfSuccessor);

	cout << "\tSubCase " << ++subCaseNum << ": ";
	idxOfElmToFindSuccessorFor = 2;
	idxOfSuccessor = -1;
	successor_test(nodeElements, idxOfElmToFindSuccessorFor, idxOfSuccessor);
	resetTestingParameters();

	cout << "Case " << ++caseNum << ":\n";
	nodeElements.push_back(10);
	nodeElements.push_back(4);
	nodeElements.push_back(5);
	nodeElements.push_back(6);

	cout << "\tSubCase " << ++subCaseNum << ": ";
	idxOfElmToFindSuccessorFor = 0;
	idxOfSuccessor = -1;
	successor_test(nodeElements, idxOfElmToFindSuccessorFor, idxOfSuccessor);

	cout << "\tSubCase " << ++subCaseNum << ": ";
	idxOfElmToFindSuccessorFor = 1;
	idxOfSuccessor = 2;
	successor_test(nodeElements, idxOfElmToFindSuccessorFor, idxOfSuccessor);

	cout << "\tSubCase " << ++subCaseNum << ": ";
	idxOfElmToFindSuccessorFor = 2;
	idxOfSuccessor = 3;
	successor_test(nodeElements, idxOfElmToFindSuccessorFor, idxOfSuccessor);

	cout << "\tSubCase " << ++subCaseNum << ": ";
	idxOfElmToFindSuccessorFor = 3;
	idxOfSuccessor = 0;
	successor_test(nodeElements, idxOfElmToFindSuccessorFor, idxOfSuccessor);
	resetTestingParameters();

	cout << "Case " << ++caseNum << ":\n";
	nodeElements.push_back(10);
	nodeElements.push_back(9);
	nodeElements.push_back(4);
	nodeElements.push_back(5);
	nodeElements.push_back(6);

	cout << "\tSubCase " << ++subCaseNum << ": ";
	idxOfElmToFindSuccessorFor = 0;
	idxOfSuccessor = -1;
	successor_test(nodeElements, idxOfElmToFindSuccessorFor, idxOfSuccessor);

	cout << "\tSubCase " << ++subCaseNum << ": ";
	idxOfElmToFindSuccessorFor = 1;
	idxOfSuccessor = 0;
	successor_test(nodeElements, idxOfElmToFindSuccessorFor, idxOfSuccessor);

	cout << "\tSubCase " << ++subCaseNum << ": ";
	idxOfElmToFindSuccessorFor = 2;
	idxOfSuccessor = 3;
	successor_test(nodeElements, idxOfElmToFindSuccessorFor, idxOfSuccessor);

	cout << "\tSubCase " << ++subCaseNum << ": ";
	idxOfElmToFindSuccessorFor = 3;
	idxOfSuccessor = 4;
	successor_test(nodeElements, idxOfElmToFindSuccessorFor, idxOfSuccessor);

	cout << "\tSubCase " << ++subCaseNum << ": ";
	idxOfElmToFindSuccessorFor = 4;
	idxOfSuccessor = 1;
	successor_test(nodeElements, idxOfElmToFindSuccessorFor, idxOfSuccessor);
	resetTestingParameters();
}

bool tree_equal(node* root1, node* root2){
	if(root1 == NULL && root2 == NULL)
		return true;

	if(root1 == NULL || root2 == NULL)
		return false;

	return ((root1->key == root2->key) &&  tree_equal(root1->left, root2->left) && tree_equal(root1->right, root2->right)); 
}

void delete_test(vector<int> nodeElements, int idxOfElmToDelete, int idxOfSuccessor){
	node* tree = NULL;
	node* treeWithoutDeletedElm = NULL;
	node* nodes = NULL;
	node* nodes2 = NULL;

	if(nodeElements.size() > 0){
		nodes = new node[nodeElements.size()];
		nodes2 = new node[nodeElements.size()];
		node* elmToDelete = NULL;

		for (int j=0; j < (int)nodeElements.size(); j++){
			nodes[j] = {nodeElements.at(j), NULL, NULL, NULL};
			tree_insert(&tree, &nodes[j]);
			if(j == idxOfElmToDelete){
				elmToDelete = &nodes[j];
			}
		}

		if(idxOfSuccessor == -1){
			nodeElements.erase(nodeElements.begin()+idxOfElmToDelete);
		} else {
			nodeElements.at(idxOfElmToDelete) = nodeElements.at(idxOfSuccessor);
			nodeElements.erase(nodeElements.begin()+idxOfSuccessor);
		}

		for (int j=0; j < (int)nodeElements.size(); j++){
			nodes2[j] = {nodeElements.at(j), NULL, NULL, NULL};
			tree_insert(&treeWithoutDeletedElm, &nodes2[j]);
		}

		cout << "Breadth-First Traversals before: ";
		bfs_binary_tree(&tree);
		cout << "\n";

		tree_delete(&tree, elmToDelete);
	}
	
	cout << "Breadth-First Traversals After: ";
	bfs_binary_tree(&tree);
	cout << "\n";
	cout << (tree_equal(tree, treeWithoutDeletedElm) == true ? "Passed\n" : "Failed\n");

	if(nodeElements.size() > 0){
		tree = NULL;
		treeWithoutDeletedElm=NULL;
		delete[] nodes;
		delete[] nodes2;
	}
}

void delete_test_cases(){
	int caseNum = 0;
	int idxOfElmToDelete= -1;
	int idxOfSuccessor = -1;
	vector<int> nodeElements;
	auto resetTestingParameters = [&](){
    nodeElements.clear();
    idxOfElmToDelete = -1;
    idxOfSuccessor = -1;
  };

	cout << "Case " << ++caseNum << ": ";
	// nodeElements.push_back(5);
	delete_test(nodeElements, idxOfElmToDelete, idxOfSuccessor);
	resetTestingParameters();

	cout << "Case " << ++caseNum << ": ";
	nodeElements.push_back(5);
	idxOfElmToDelete = 0;
	delete_test(nodeElements, idxOfElmToDelete, idxOfSuccessor);
	resetTestingParameters();

	cout << "Case " << ++caseNum << ": ";
	nodeElements.push_back(5);
	nodeElements.push_back(6);
	idxOfElmToDelete = 0;
	idxOfSuccessor = 1;
	delete_test(nodeElements, idxOfElmToDelete, idxOfSuccessor);
	resetTestingParameters();

	cout << "Case " << ++caseNum << ": ";
	nodeElements.push_back(5);
	nodeElements.push_back(6);
	idxOfElmToDelete = 1;
	delete_test(nodeElements, idxOfElmToDelete, idxOfSuccessor);
	resetTestingParameters();

	cout << "Case " << ++caseNum << ": ";
	nodeElements.push_back(5);
	nodeElements.push_back(4);
	nodeElements.push_back(20);
	nodeElements.push_back(7);
	nodeElements.push_back(30);
	nodeElements.push_back(23);
	nodeElements.push_back(35);
	nodeElements.push_back(26);
	idxOfElmToDelete = 1;
	delete_test(nodeElements, idxOfElmToDelete, idxOfSuccessor);
	resetTestingParameters();

	cout << "Case " << ++caseNum << ": ";
	nodeElements.push_back(5);
	nodeElements.push_back(4);
	nodeElements.push_back(20);
	nodeElements.push_back(7);
	nodeElements.push_back(30);
	nodeElements.push_back(23);
	nodeElements.push_back(35);
	nodeElements.push_back(26);
	idxOfElmToDelete = 3;
	delete_test(nodeElements, idxOfElmToDelete, idxOfSuccessor);
	resetTestingParameters();

	cout << "Case " << ++caseNum << ": ";
	nodeElements.push_back(5);
	nodeElements.push_back(4);
	nodeElements.push_back(20);
	nodeElements.push_back(7);
	nodeElements.push_back(30);
	nodeElements.push_back(23);
	nodeElements.push_back(35);
	nodeElements.push_back(26);
	idxOfElmToDelete = 5;
	idxOfSuccessor = 7;
	delete_test(nodeElements, idxOfElmToDelete, idxOfSuccessor);
	resetTestingParameters();

	cout << "Case " << ++caseNum << ": ";
	nodeElements.push_back(5);
	nodeElements.push_back(4);
	nodeElements.push_back(20);
	nodeElements.push_back(7);
	nodeElements.push_back(30);
	nodeElements.push_back(23);
	nodeElements.push_back(35);
	nodeElements.push_back(26);
	idxOfElmToDelete = 2;
	idxOfSuccessor = 5;
	delete_test(nodeElements, idxOfElmToDelete, idxOfSuccessor);
	resetTestingParameters();
}

int main(int argc, char** argv){
	// vector<vector<int>> arrays = readArrays(argv[1]);
	// cout << "Num Testcases: " << arrays.size()<<"\n";
	// int caseNum = 0;
	// for (vector<vector<int>>::const_iterator i = arrays.begin(); i != arrays.end(); ++i){
	// 	cout << "Case number: " <<  ++caseNum << "\n";
	// 	testCase(*i);
	// }
	// successor_test_cases();
	delete_test_cases();
	return 0;
}

