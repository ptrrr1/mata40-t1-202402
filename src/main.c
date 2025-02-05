#include <stdio.h>
#include "include/avl.h"

void traverse(avl_tree *root, int h) {
	if (root == NULL) return;

	traverse(root->left, h+1);
	printf("%*s%d\n", 2*h, "", root->key);
	traverse(root->right, h+1);
}

int main() {
	int n, v;
	scanf("%d", &n);

	int h = 0;
	avl_tree* root = NULL;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v);
		insert_elem(&root, &h, v);
	}

	traverse(root, 0);

	return 0;
}