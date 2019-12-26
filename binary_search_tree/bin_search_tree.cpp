#include "bin_search_tree.h"
#include <iostream>

void tree_insert(node** root, node* z){
	if(*root == NULL){
		*root = z;
		(*root)->p = NULL;
		return;
	}

	node* x = *root;
	node* y = NULL;
	while( x != NULL){
		y = x;
		if (z->key < x->key){
			x = x->left;
		} else {
			x = x->right;
		}
	}

	if(z->key < y->key){
		y->left = z;
	} else {
		y->right = z;
	}
	
	z->p = y;
}

void in_order_tree_walk(node* root){
	if(root->left != NULL)
		in_order_tree_walk(root->left);

	std::cout <<  root->key << ", ";

	if(root->right != NULL)
		in_order_tree_walk(root->right);

}

void in_order_tree_walk(node** root){
	if(*root == NULL)
		return;
	in_order_tree_walk(*root);
}

node* tree_minimum(node** root){
	if(*root == NULL)
		return NULL;
	
	node* tree_min = *root;
	while(tree_min->left != NULL)
		tree_min = tree_min->left;

	return tree_min;
}

node* tree_maximum(node** root){
	if(*root == NULL)
		return NULL;
	
	node* tree_max = *root;
	while(tree_max->right != NULL)
		tree_max = tree_max->right;

	return tree_max;
}

node* tree_search_iterative(int k, node** root){
	if(*root == NULL)
		return NULL;

	node* found_node = *root;
	while(found_node != NULL && found_node->key != k){
		found_node = (k <= found_node->key) ? found_node->left : found_node->right;
	}
	return found_node;
}