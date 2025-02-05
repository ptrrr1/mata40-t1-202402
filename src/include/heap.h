#ifndef __HEAP_H__
#define __HEAP_H__

void up(int m_size, int arr[m_size], int pos);

void up_iterative(int m_size, int arr[m_size], int pos);

void down(int m_size, int arr[m_size], int size, int pos);

void down_interative(int m_size, int arr[m_size], int size, int pos);

void insert_elem(int m_size, int arr[m_size], int *size, int elem);

void remove_elem(int m_size, int arr[m_size], int *size);

void heapsort(int m_size, int arr[m_size], int size);

void leaf_nodes_start(int size);

#endif // __HEAP_H__