#ifndef CODING_TREE_H_INCLUDED
#define CODING_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"

typedef struct st_ctree_node ctree_node;
struct st_ctree_node
{
    char letter;
    unsigned int freq;
    ctree_node *children[2];
};

ctree_node *new_ctree_node(unsigned int freq, char letter, ctree_node *child_0, ctree_node *child_1);
void ctree_sort(ctree_node *mass_of_nodes[], int index);
ctree_node *ctree_build_tree(unsigned int mass_of_int[]);
void ctree_free_tree(ctree_node *a);

#endif
