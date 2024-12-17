#include <stdio.h>
#include "include/tree.h"

void traverse(Tree* root, int level) {
	if (root == NULL) return;

	traverse(root->left, level + 1);
	printf("%*s", 4*level, "");
	printf("%d\n", root->value);
	traverse(root->right, level + 1);
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

	traverse(root, 0);

	root = remove_node(root, 45);

	printf("\n-------------------\n");
	traverse(root, 0);

	return 0;
}