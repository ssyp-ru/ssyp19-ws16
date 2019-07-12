#ifndef CODING_TREE_H_INCLUDED
#define CODING_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct st_ctree_node ctree_node;
struct st_ctree_node
{
    char letter;
    unsigned int freq;
    ctree_node *children[2];
};

ctree_node *new_ctree_node(unsigned int freq, char letter, ctree_node *child_0, ctree_node *child_1);

void ctree_free_tree(ctree_node *a);

#endif // CODING_TREE_H_INCLUDED
