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

node* successor(node* z){
	if(z == NULL)
		return NULL;

	if(z->right != NULL)
		return tree_minimum(&(z->right));

	if(z->p == NULL)
		return NULL;

	node* y1 = z->p;
	node* y2 = z;
	while(y1!= NULL && y1->left != y2){
		y2=y1;
		y1 = y1->p;
	}
	return y1;
}

node* predecessor(node* z){
	if(z == NULL)
		return NULL;

	if(z->left != NULL)
		return tree_maximum(&(z->left));

	if(z->p == NULL)
		return NULL;

	node* y1 = z->p;
	node* y2 = z;
	while(y1!= NULL && y1->right != y2){
		y2=y1;
		y1 = y1->p;
	}
	return y1;
}

//Replaces the subtree at u with subtree at v. Doesnt care about the final state of u. v might be null.
void transplant(node** root, node* u, node* v){
	if(u->p == NULL){
		*root = v;
		return;
	}

	if(u->p->left == u){
		u->p->left = v;
	} else {
		u->p->right = v;
	}

	if(v != NULL)
		v->p = u->p;
}

void tree_delete(node** root, node* z){
	if(z == NULL || *root == NULL)
		return;

	if(z->left == NULL){
		transplant(root, z, z->right);
	} else if (z->right == NULL){
		transplant(root, z, z->left);
	} else {
		node* z_successor = successor(z);
		if(z_successor != z->right){
			transplant(root, z_successor, z_successor->right);
			z_successor->right = z->right;
			z_successor->right->p = z_successor;
		}
		transplant(root, z, z_successor);
		z_successor->left = z->left;
		z_successor->left->p = z_successor;
	}
}