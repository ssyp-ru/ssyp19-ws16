#ifndef ENCODER_H_INCLUDED
#define ENCODER_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 257
typedef st_ctree_node ctree_node;
typedef st_code code;
struct st_code
{
	int size;
	char code[257];
};
struct st_ctree_node
{
	char letter;
	unsigned int freq;
	ctree_node *children[2];
};
ctree_node* huf_tree_build(FILE* file);
ctree_node* calc_codes(ctree_node* tree, int length, code* symbol);
ctree_node* code_char (bitstream* b_stream, code* symbol);
void get_freq (FILE *input);
encode(char *in,char *ou);


#endif // ENCODER_H_INCLUDED
