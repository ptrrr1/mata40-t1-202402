#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct tree{

    size_t typesize;
    void * value;
    size_t base;
    struct tree ** nodes;
    bool (*cmp)(void * a, void * b);
}treenode_t;


int memcmp(const void * a, const void * b, size_t n);

void memcpy(void * dst, const void * src, size_t n);

treenode_t * Tree(size_t typesize, size_t base, bool(*cmp)(void * a, void * b));

inline bool Tree_IsEmpty(treenode_t * tree);

inline bool Tree_IsFull(treenode_t * tree);

int Tree_Find(treenode_t * tree, void * value);

treenode_t * Tree_Get(treenode_t * tree, void* value);

bool Tree_PushNode(treenode_t * tree, void * value);

bool Tree_PullNode(treenode_t * tree, void * value);

void Tree_DestroyNode(treenode_t * node);

