#ifndef DECODE_H_INCLUDED
#define DECODE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "coding_tree.h"
#include "bitstream.h"

#define BUFER_SIZE 257

char tree_get_char(ctree_node *derevo, bitstream *logic);

ctree_node *huf_rebuild_tree(FILE *input);

void decode(char *from, char *where);

#endif
