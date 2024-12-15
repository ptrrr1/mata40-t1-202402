#ifndef __LISTA_LINEAR_H__
#define __LISTA_LINEAR_H__

/* ------------------------UNORDERED--------------------------- */

int search_unordered(int arr[], int cur_size, int target);

void include_unordered(int arr[], int max, int *cur_size, int target);

void remove_unordered(int arr[], int max, int *cur_size, int target);

/* --------------------------ORDERED--------------------------- */

int binary_search(int arr[], int cur_size, int target);

void include_ordered(int arr[], int max, int *cur_size, int target);

void remove_ordered(int arr[], int max, int *cur_size, int target);

#endif //__LISTA_LINEAR_H__