#include <tree.h>


//memcmp e memcpy existem, mas não quis incluir a lib <string.h> inteira somente por conta de duas funções, que nem tem a ver com string diretamente...

int memcmp(const void * a, const void * b, size_t n){
    char * p1 = a, * p2 = b;
    
    for(size_t i = 0; i < n; i++)
        if(p1[i] != p2[i])
            return p1[i] - p2[i];

    return 0;
}
void memcpy(void * dst, const void * src, size_t n){
    char * p1 = dst;
    const char * p2 = src;
    
    for(size_t i = 0; i < n; i++)
        p1[i] = p2[i];
}

void memset(void * dst, const char value, size_t n){
    char * p = dst;
    for(size_t i = 0; i < n; i++)
        p[i] = value;
}

treenode_t * Tree(size_t typesize, size_t base, bool(*cmp)(void * a, void * b)){
    treenode_t * tree = malloc(sizeof(treenode_t));
    if(!tree)
        return NULL;

    tree->typesize = typesize;
    tree->base = base;
    tree->cmp = cmp;

    tree->value = malloc(tree->typesize);
    if(!tree->value){
        free(tree);
        return NULL;
    }

    memset(tree->value, 0, tree->typesize);

    tree->nodes = malloc(sizeof(treenode_t *) * tree->base);
    if(!tree->nodes){
        free(tree->value);
        free(tree);
        return NULL;
    }

    for(size_t i = 0; i < tree->base; i++)
        tree->nodes[i] = NULL;

    return tree;
}

inline bool Tree_IsEmpty(treenode_t * tree){
    for(int i = 0; i < tree->base; i++)
        if(tree->nodes[i] != NULL)
            return false;

    return true;
}

inline bool Tree_IsFull(treenode_t * tree){
    for(int i = 0; i < tree->base; i++)
        if(tree->nodes[i] == NULL)
            return false;

    return true;
}

int Tree_Find(treenode_t * tree, void * value){
    for(size_t i = 0; i < tree->base; i++)
        if(!memcmp(tree->nodes[i]->value, value, tree->typesize))
            return i;

    return -1;
}

treenode_t * Tree_Get(treenode_t * tree, void* value){
    int index = Tree_Find(tree, value);
    return index == -1 ? NULL : tree->nodes[index];
}

bool Tree_PushNode(treenode_t * tree, void * value){
    if(Tree_IsFull(tree) || !tree->base)
        return false;

    size_t i = 0;
    for(; i < tree->base; i++)
        if(tree->nodes[i] == NULL || !tree->cmp(tree->nodes[i]->value, value))
            break;

    treenode_t * node = Tree(tree->typesize, tree->base, tree->cmp);
    if(!node)
        return false;

    node->value = malloc(tree->typesize);
    if(!node->value){
        Tree_DestroyNode(node);
        return false;
    }

    memcpy(node->value, value, node->typesize);

    tree->nodes[i] = node;

    return true;
}

bool Tree_PullNode(treenode_t * tree, void * value){
    if(Tree_IsEmpty(tree))
        return false;

    int index = Tree_Find(tree, value);
    if(index == -1)
        return false;

    Tree_DestroyNode(tree->nodes[index]);
    
    
    size_t i = index + 1;
    for(; i < tree->base && tree->nodes[i]; i++)
        tree->nodes[i - 1] = tree->nodes[i];

    if(i != index + 1)
        tree->nodes[i - 1] = NULL;
    
    return true;
}

void Tree_DestroyNode(treenode_t * node){
    if(!node)
        return;

    for(size_t i = 0; i < node->base; i++)
        if(node->nodes[i] == NULL)
            break;
        else
            Tree_DestroyNode(node->nodes[i]);
    free(node->value);
    free(node->nodes);
    free(node);
}