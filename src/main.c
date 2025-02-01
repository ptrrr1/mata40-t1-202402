#include <stdio.h>
#include "include/heap.h"

int main() {
	int n, v;
	scanf("%d", &n);

	int heap[n];
	int cur_size = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v);
		insert_elem(n, heap, &cur_size, v);
		//leaf_nodes_start(cur_size);
	}

	for (int i = 0; i < cur_size; ++i) {
		printf("%d ", heap[i]);
	}

	printf("\n");

	remove_elem(n, heap, &cur_size);

	for (int i = 0; i < cur_size; ++i) {
		printf("%d ", heap[i]);
	}

	printf("\n");

	remove_elem(n, heap, &cur_size);

	for (int i = 0; i < cur_size; ++i) {
		printf("%d ", heap[i]);
	}

	return 0;
}