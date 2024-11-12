#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct node Node;
struct node {
	int value;
	Node *addr;
};

// O(n) complexity without tail
// O(1) complexity with tail
void queue(Node *header, int *cur_size, int target) {
	Node *ptr = (Node*)malloc(sizeof(Node));
	if (!ptr) return; // Malloc failed

	ptr->value = target;
	ptr->addr = NULL;

	if (header->addr == NULL) {
		header->addr = ptr;
	} else {
		Node *last = header->addr;
		while (last->addr != NULL) {
			last = last->addr;
		}
		last->addr = ptr;
	}
	*cur_size += 1;
}

void dequeue(Node *header, int *cur_size) {
	if (header->addr != NULL) {
		if (*cur_size > 1) {
			Node *ptr = header->addr;
			header->addr = ptr->addr;
			free(ptr);
		} else {
			free(header->addr);
			header->addr = NULL;
		}
		
		*cur_size -= 1;
	} // Underflow
}

void unify(Node *h1, int n1, Node *h2, int n2, Node *h3, int *n3) {
	Node *ptr1 = h1->addr;
	Node *ptr2 = h2->addr;
	Node *ptr3 = h3;
	while (ptr1 != NULL && ptr2 != NULL) {
		Node *ptr = (Node*)malloc(sizeof(Node));

		if (ptr1->value < ptr2->value) {
			ptr->value = ptr1->value;
			ptr1 = ptr1->addr;
		}
		else {
			ptr->value = ptr2->value;
			ptr2 = ptr2->addr;
		}

		ptr->addr = NULL;
		ptr3->addr = ptr;
		ptr3 = ptr;

		(*n3)++;
	}

	while (ptr1 != NULL) {
		Node *ptr = (Node*)malloc(sizeof(Node));

		ptr->value = ptr1->value;
		ptr1 = ptr1->addr;		

		ptr->addr = NULL;
		ptr3->addr = ptr;
		ptr3 = ptr;

		(*n3)++;
	
	}

	while (ptr2 != NULL) {
		Node *ptr = (Node*)malloc(sizeof(Node));

		ptr->value = ptr2->value;
		ptr2 = ptr2->addr;		

		ptr->addr = NULL;
		ptr3->addr = ptr;
		ptr3 = ptr;

		(*n3)++;
	
	}
}

int main(int argc, char const *argv[]) {
	int n1 = 0; // Size of list
	Node header1 = {
		.value = 0,
		.addr = NULL
	};

	return 0;
}