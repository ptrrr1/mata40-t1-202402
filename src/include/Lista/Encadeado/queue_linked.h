#ifndef __QUEUE_LINKED_H__
#define __QUEUE_LINKED_H__


typedef struct node Node;
struct node {
	int value;
	Node *addr;
};

// O(n) complexity without tail
// O(1) complexity with tail
void queue(Node *header, int *cur_size, int target);

void dequeue(Node *header, int *cur_size);

// Unite two ordered queue into a single ordered one
void unify(Node *h1, int n1, Node *h2, int n2, Node *h3, int *n3);

#endif //__QUEUE_LINKED_H__