#include <stdio.h>
#include "include/heap.h"

int main() {
	int n;
	scanf("%d", &n);

	int heap[n];
	int arr[n];
	int cur_size = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		insert_elem(n, heap, &cur_size, arr[i]);
	}

	for (int i = 0; i < cur_size; ++i) {
		printf("%d ", heap[i]);
	}
	printf("\n");

	for (int i = 0; i < cur_size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < cur_size; ++i) {
		printf("%d ", heap[i]);
	}
	printf("\n");

	heapsort(n, arr, cur_size);
	for (int i = 0; i < cur_size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}