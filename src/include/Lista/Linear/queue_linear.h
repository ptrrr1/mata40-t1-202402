#ifndef __QUEUE_LINEAR_H__
#define __QUEUE_LINEAR_H__

void queue(int arr[], int max, int *cur_size, int *left, int *right, int target);

void queue_side(int arr[], int max, int *cur_size, int *left, int *right, int target, int is_left);

void dequeue(int arr[], int max, int *cur_size, int *left, int *right);

#endif //__QUEUE_LINEAR_H__