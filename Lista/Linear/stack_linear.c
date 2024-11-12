#include <stdio.h>

void push(int arr[], int max, int *top, int target) {
	if (*top < max) {
		arr[*top] = target;
		*top += 1;
	}
}

void pop(int arr[], int max, int *top) {
	if (*top > 0) {
		*top -= 1;
	}
}

int main(int argc, char const *argv[]) {
	int n; // cur size
	int max; // max size
	int arr[max];

	return 0;
}