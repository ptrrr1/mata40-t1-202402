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

// Recursivo
Tree* find(Tree* root, int value, int* exit_code, Tree** father) {
	Tree* ptr = root;

	if (ptr == NULL) { *exit_code = 0; } // Root Doesn't exist
	else if (value == ptr->value) { *exit_code = 1; } // Found
	else if (value < ptr->value) {
		if (ptr->left == NULL) { *exit_code = 2; } // Not found - Left
		else {
			*father = ptr;
			ptr = find(ptr->left, value, exit_code, father);
		}
	} else if (value > ptr->value) {
		if (ptr->right == NULL) { *exit_code = 3; } // Not Found - Right
		else {
			*father = ptr;
			ptr = find(ptr->right, value, exit_code, father);
		}
	}

	return ptr;
}

// Não recursivo
Tree* find2(Tree* root, int value, int* exit_code, Tree** father) {
	Tree* ptr = root;
	if (ptr == NULL) { *exit_code = 0; } // Root Doesn't exist
	else {
		while(*exit_code == -1) {
			if (value == ptr->value) { *exit_code = 1; }
			else if (value < ptr->value) {
				if (ptr->left != NULL) { *father = ptr; ptr = ptr->left; }
				else { *exit_code = 2; } // Not found - Left
			}
			else if (value > ptr->value) {
				if (ptr->right != NULL) { *father = ptr; ptr = ptr->right; }
				else { *exit_code = 3; } // Not Found - Right
			}
		}
	}

	return ptr;
}

Tree* insert_node(Tree* root, int value) {
	int exit_code = -1;
	Tree* subroot = root;
	//Tree* subtree = find(subroot, value, &exit_code, &subroot);
	Tree* subtree = find2(subroot, value, &exit_code, &subroot);

	if (exit_code == 1) {} // Already Exists
	else {
		Tree* node = create_node(value);
		if (exit_code == 0) { root = node; }
		else if (exit_code == 2) { subtree->left = node; }
		else if (exit_code == 3) { subtree->right = node; }
	}

	return root;
}

Tree* remove_node(Tree* root, int value) {
	int exit_code = -1;
	Tree* subroot = root;
	//Tree* subtree = find(subroot, value, &exit_code, &subroot);
	Tree* subtree = find2(subroot, value, &exit_code, &subroot);

	if (exit_code == 1) {
		// no nodes
		if (subtree->left == NULL && subtree->right == NULL) {
			if (subtree == root) { /* free it */ }
			else if (subroot->left == subtree) { subroot->left = NULL; }
			else { subroot->right = NULL; }
	    }
		// only has left node
		else if (subtree->left != NULL && subtree->right == NULL) {
			if (subtree == root) { root = root->left; }
			else if (subroot->left == subtree) { subroot->left = subtree->left; }
			else { subroot->right = subtree->left; }
		}
		// only has right node
		else if (subtree->left == NULL && subtree->right != NULL) {
			if (subtree == root) { root = root->right; }
			else if (subroot->left == subtree) { subroot->left = subtree->right; }
			else { subroot->right = subtree->right; }
		}
		// has both nodes
		else {
			Tree* root_ptr = subtree;
			Tree* ptr = subtree->right;

			// find leftmost node
			while (ptr->left != NULL) {
				root_ptr = ptr;
				ptr = ptr->left;
			}

			if (root_ptr != subtree) {
				root_ptr->left = ptr->right;
				ptr->right = subtree->right;
			}

			ptr->left = subtree->left;

			if (subtree == root) { root = ptr; }
			else {
				if (subroot->left == subtree) { subroot->left = ptr; }
				else { subroot->right = ptr; }
			}
		}

		free(subtree);
	}

	return root;
}

// Recursivo
int compare(Tree* r1, Tree* r2) {
	int isEqual = 0; // 1 equal, 0 not equal

	if (r1 == NULL && r2 == NULL) { isEqual = 1; }
	else if (r1 && r2) {
		if (r1->value == r2->value) {
			int ll = compare(r1->left, r2->left);
			int rr = compare(r1->right, r2->right);

			isEqual = ll && rr;
		}
	}

	return isEqual;
}

// Não recursivo usando pré ordem
int compare2(Tree* r1, Tree* r2) {
	int isEqual = 1; // 1 equal, 0 not equal

	int top1 = 0;
	Tree* arr1[100];
	arr1[top1] = r1;
	top1++;

	int top2 = 0;
	Tree* arr2[100];
	arr2[top2] = r2;
	top2++;

	while (isEqual && top1 > 0 && top2 > 0) {
		top1--; Tree* n1 = arr1[top1];
		top2--; Tree* n2 = arr2[top2];

		if (n1 && n2) {
			if (n1->value != n2->value) { isEqual = 0; }
			else {
				if (n1->left != NULL) { arr1[top1] = n1->left; top1++; }
				if (n1->right != NULL) { arr1[top1] = n1->right; top1++; }

				if (n2->left != NULL) { arr2[top2] = n2->left; top2++; }
				if (n2->right != NULL) { arr2[top2] = n2->right; top2++; }
			}
		} else if (!(!n1 && !n2)) { isEqual = 0; }
	}

	return isEqual;
}

void traverse_preorder(Tree* root) {
	if (root == NULL) return;

	int top = 0;
	Tree* arr[100];
	arr[top] = root;
	top++;

	while (top > 0) {
		Tree* node = arr[top-1]; top--;
		//printf("%d ", node->value);

		if (node->right != NULL) {
			arr[top] = node->right;
			top++;
		}
		if (node->left != NULL) {
			arr[top] = node->left;
			top++;
		}
	}
}

void traverse_postorder(Tree* root) {
	if (root == NULL) return;

	int t1 = 0, t2 = 0;
	Tree* arr1[100];
	int arr2[100];

	arr1[t1] = root;
	t1++;

	while(t1 > 0) {
		t1--;
		Tree* node = arr1[t1];
		arr2[t2] = node->value;
		t2++;

		if (node->left != NULL) {
			arr1[t1] = node->left;
			t1++;
		}

		if (node->right != NULL) {
			arr1[t1] = node->right;
			t1++;
		}
	}

	while (t2 > 0) {
		t2--;
		//printf("%d ", arr2[t2]);
	}
}

void traverse_inorder(Tree* root) {
	int top = 0;
	Tree* arr[100];
	Tree* node = root;

	while(top > 0 || node != NULL) {
		if (node != NULL) {
			arr[top] = node; top++;
			node = node->left;
		} else {
			top--;
			node = arr[top];
			//printf("%d ", node->value);
			node = node->right;
		}
	}
}