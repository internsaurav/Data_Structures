#ifndef BIN_SEARCH_TREE_H
#define BIN_SEARCH_TREE_H

#include "tree_node.h"

void tree_insert(node** root, node* z);
void in_order_tree_walk(node** root);
node* tree_minimum(node** root);
node* tree_maximum(node** root);

#endif