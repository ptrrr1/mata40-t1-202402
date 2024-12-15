#ifndef __STACK_LINKED_H__
#define __STACK_LINKED_H__

typedef struct node Node;
struct node {
	int value;
	Node *addr;
};

void push(Node *header, int *cur_size, int target);

void pop(Node *header, int *cur_size);

int main(int argc, char const *argv[]);

#endif //__STACK_LINKED_H__