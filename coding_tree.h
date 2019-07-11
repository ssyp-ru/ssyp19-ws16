#ifndef CODING_TREE_H_INCLUDED
#define CODING_TREE_H_INCLUDED

#include <stdio.h>

typedef st_ctree_node node;
struct st_ctree_node
{
    char letter;
    unsigned int freq;
    node children[2];
};

#endif // CODING_TREE_H_INCLUDED
