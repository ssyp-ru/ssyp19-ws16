#include <stdio.h>
#include <stdlib.h>
#include coding_tree.h
#define BUFER_SIZE = 257
 huf_rebuild_tree(FILE *input)
{
    int read;
    char buffer [BUFER_SIZE];
    int frequences[BUFER_SIZE];
    ctree_node mas_ctree_node [BUFER_SIZE];
    fread(frequences,sizeof(int), BUFER_SIZE , input);
    return ctree_build_tree(frequences)
}
