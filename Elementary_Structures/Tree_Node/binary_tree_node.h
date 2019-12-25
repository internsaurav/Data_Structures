#ifndef TREE_NODE_H
#define TREE_NODE_H

struct node {
	int key;
	node* p;
	node* left;
	node* right;
};

#endif