#include "stack_linear.h"

void push(int arr[], int max, int *top, int target) {
	if (*top < max) {
		arr[*top] = target;
		*top += 1;
	} // Overflow
}

int pop(int arr[], int max, int *top) {
	if (*top > 0) {
		*top -= 1;
		return arr[*top];
	} // Underflow
}