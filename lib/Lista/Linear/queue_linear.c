#include "queue_linear.h"

void queue(int arr[], int max, int *cur_size, int *left, int *right, int target) {
	if (*cur_size < max) {
		arr[*right] = target;
		*right = (*right + 1) % max;
		*cur_size += 1;
	} // Else Overflow
}

void queue_side(int arr[], int max, int *cur_size, int *left, int *right, int target, int is_left) {
	if (*cur_size < max) {
		if (is_left) {
			*left = (*left - 1 < 0) ? max - 1 : *left - 1;
			arr[*left] = target;
		} else {
			arr[*right] = target;
			*right = (*right + 1) % max;
		}
		*cur_size += 1;
	} // Else Overflow
}

void dequeue(int arr[], int max, int *cur_size, int *left, int *right) {
	if (*cur_size > 0) {
		*left = (*left + 1) % max;
		*cur_size -= 1;
	} // Underflow

	if (*cur_size == 0) {
		*left = 0;
		*right = 0;
	}
}