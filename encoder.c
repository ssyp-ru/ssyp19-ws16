#include <stdio.h>
#include <stdlib.h>
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
void get_freq (FILE *input){
char buffer[257];
int size = fread(buffer, sizeof(char),257,input)
int freq[257];
for (int i=0;i<257;i++){
    freq[i] = 0;
}

for (int i=0;i<size;i++){
freq[buffer[i]] += 1;
}
rewind(FILE*input)
return freq;
}
encode(char *in,char *ou){
    FILE *input = fopen(in,"rb");
    FILE *out = fopen(ou,"wb+");
    int char_read = fread(buffer, sizeof(char),257,input);
    fwrite(get_freq(input),sizeof(int),257,out);

    while(int char_read2 = fread(buffer, sizeof(char),257,input)){
        for(int i=0;i < char_read2;i ++){
            code_char(i,ctree_build_tree(get_freq(input)),bitstream*);
        }
    }
}
ctree_node* huf_tree_build(FILE* file)
{
	ctree_node* tree;
	tree = ctree_build_tree(get_freq(file));
	return tree;
}
ctree_node* calc_codes(ctree_node* tree, int length, code* symbol)
{
	if (tree->child[0] != NULL)
	{
		symbol[length] = 0;
		code_char(tree->children[0], length + 1);
	}
	if (tree->child[1] != NULL)
	{
		symbol[length] = 1;
		code_char(tree->children[1], length + 1);
	}
	if ((tree->child[1] == NULL) && (tree->child[0] == NULL))
	{
		for(int index = 0; index < length; index++)
		{
			symbol->code[index] = symbol[index];
		}
	}
}
ctree_node* code_char (bitstream* b_stream, code* symbol)
{
	bitstream* bs;
	for (int i = 0; i < 257; i++)
	{
		bitstream_put_bit(symbol->code[i], bs);
	}
}
