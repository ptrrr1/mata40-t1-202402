#ifndef __TREE_H__
#define __TREE_H__

typedef struct tree_t Tree;

struct tree_t {
	int value;
	//int height;
	Tree* left;
	Tree* right;
};

Tree* create_node(int value);

Tree* find(Tree* root, int value, int* exit_code, Tree** father);

Tree* insert_node(Tree* root, int value);

Tree* remove_node(Tree* root, int value);

int compare(Tree* r1, Tree* r2);

int compare2(Tree* r1, Tree* r2);

#endif //__TREE_H__