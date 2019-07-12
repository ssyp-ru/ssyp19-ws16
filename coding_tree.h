#ifndef CODING_TREE_H_INCLUDED
#define CODING_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
typedef st_ctree_node ctree_node;
struct st_ctree_node
{
    char letter;
    unsigned int freq;
    ctree_node *children[2];
};
ctree_node *new_ctree_node (int freq, char letter);
void ctree_free_tree (ctree_ctree_node *a);
#endif // CODING_TREE_H_INCLUDED
