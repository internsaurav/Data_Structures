#ifndef ROOTED_TREE_NODE_H
#define ROOTED_TREE_NODE_H

struct node {
	int key;
	node* p;
	node* left;
	node* right;
};

#endif