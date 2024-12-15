#include "tree.h"
#include <stdlib.h>

Tree* create_node(int value) {
	Tree* node = (Tree *)malloc(sizeof(Tree));

	node->value = value;
	//node->height = 1;
	node->left = NULL;
	node->right = NULL;

	return node;
}

Tree* find(Tree* root, int value, int* exit_code) {
	Tree* ptr = root;

	if (ptr == NULL) { *exit_code = 0; } // Root Doesn't exist
	else if (value == ptr->value) { *exit_code = 1; } // Found
	else if (value < ptr->value) {
		if (ptr->left == NULL) { *exit_code = 2; } // Not found - Left
		else { ptr = find(ptr->left, value, exit_code); }
	} else if (value > ptr->value) {
		if (ptr->right == NULL) { *exit_code = 3; } // Not Found - Right
		else { ptr = find(ptr->right, value, exit_code); }
	}

	return ptr;
}

Tree* insert_node(Tree* root, int value) {
	int exit_code = -1;
	Tree* subtree = find(root, value, &exit_code);

	if (exit_code == 1) {} // Already Exists
	else {
		Tree* node = create_node(value);
		if (exit_code == 0) { root = node; }
		else if (exit_code == 2) { subtree->left = node; }
		else if (exit_code == 3) { subtree->right = node; }
	}

	return root;
}