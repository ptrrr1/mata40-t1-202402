#include <stdlib.h>
#include <stdio.h>

typedef struct node Node;
struct node {
	int value;
	Node *addr;
};

void push(Node *header, int *cur_size, int target) {
	Node *ptr = (Node*)malloc(sizeof(Node));
	if (!ptr) return; // Malloc failed

	ptr->value = target;
	ptr->addr = NULL;

	if (header->addr == NULL) {
		header->addr = ptr;
	} else {
		Node *top = header->addr;
		while (top->addr != NULL) {	
			top = top->addr;
		}
		top->addr = ptr;
	}

	*cur_size += 1;
}

void pop(Node *header, int *cur_size) {
	if (header->addr != NULL) {
		Node *ptr = header->addr;

		if (*cur_size > 1) {
			while (ptr->addr->addr != NULL) {
				ptr = ptr->addr;
			}
			free(ptr->addr);
			ptr->addr = NULL;
		} else {
			free(header->addr);
			header->addr = NULL;
		}
		
		*cur_size -= 1;
	} // Underflow
}

int main(int argc, char const *argv[]) {
	int n = 0; // Size of list
	Node header = {
		.value = 0,
		.addr = NULL
	};

	return 0;
}