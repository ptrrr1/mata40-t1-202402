#include <stdio.h>
#include "include/tree.h"

void traverse(Tree* root) {
	if (root == NULL) return;

	traverse(root->left);
	printf("%d ", root->value);
	traverse(root->right);
}

int main() {
	int n, v;
	scanf("%d", &n);

	Tree* root = NULL;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v);
		root = insert_node(root, v);
	}

	scanf("%d", &n);

	Tree* r2 = NULL;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v);
		r2 = insert_node(r2, v);
	}

	traverse(r2);

	remove_node(r2, 45);

	printf("\n");
	traverse(r2);

	return 0;
}