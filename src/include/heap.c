#include "heap.h"
#include <stdio.h>

void up(int m_size, int arr[m_size], int pos) {
	int j = (pos - 1) / 2;
	if (j >= 0) {
		if (arr[pos] > arr[j]) {
			int aux = arr[pos];
			arr[pos] = arr[j];
			arr[j] = aux;
			up(m_size, arr, j);
		}
	}
}

void up_iterative(int m_size, int arr[m_size], int pos) {
	int j;
	int aux;
	while (pos > 0) {
		j = (pos - 1) / 2;
		if (arr[pos] > arr[j]) {
			aux = arr[pos];
			arr[pos] = arr[j];
			arr[j] = aux;

			aux = pos;
			pos = j;
			j = (aux - 1) / 2;
		} else { pos = 0; }
	}
}

void down(int m_size, int arr[m_size], int size, int pos) {
	int j = 2 * pos + 1;
	if (j <= size) {
		if (j < size) {
			if (arr[j+1] > arr[j]) {
				j++;
			}
		}
		if (arr[pos] < arr[j]) {
			int aux = arr[pos];
			arr[pos] = arr[j];
			arr[j] = aux;
			down(m_size, arr, size, j);
		}
	}
}

void insert_elem(int m_size, int arr[m_size], int *size, int elem) {
	if (*size < m_size) {
		arr[*size] = elem;
		up_iterative(m_size, arr, *size);
		(*size)++;
	} // else overflow
}

void remove_elem(int m_size, int arr[m_size], int *size) {
	if (*size > 0) {
		printf("removed max: %d\n", arr[0]);
		(*size)--;
		arr[0] = arr[*size];
		down(m_size, arr, *size, 0);
	}
}

void leaf_nodes_start(int size) {
	int start = (size / 2); // + 1 for index base 1
	printf("leaf nodes start [%d, %d]\n", start, size-1);
}