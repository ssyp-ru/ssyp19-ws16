#ifndef ENCODER_H_INCLUDED
#define ENCODER_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "bitstream.h"
#include "coding_tree.h"
#include "definitions.h"

#define BUFFER_SIZE 257

typedef struct st_code code;
struct st_code
{
    int size;
    char code[BUFFER_SIZE];
};

ctree_node *huf_tree_build(FILE *file);

void calc_codes(ctree_node *tree, int length, char *path);

ctree_node *code_char(bitstream *b_stream, code *symbol);

int *get_freq(FILE *input);

void encode(char *in, char *out);


#endif