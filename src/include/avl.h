#ifndef __AVL_H__
#define __AVL_H__

typedef struct _AVL_Tree avl_tree;
struct _AVL_Tree {
	int key;
	int bal; // bal esq - bal dir
	struct _AVL_Tree* left;
	struct _AVL_Tree* right;
};

void rot_right(struct _AVL_Tree** pt, int* h);

void rot_left(struct _AVL_Tree** pt, int* h);

void insert_elem(struct _AVL_Tree** root, int* h, int x);

#endif // __AVL_H__