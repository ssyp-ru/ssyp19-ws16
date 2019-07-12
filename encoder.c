#include "encoder.h"

ctree_node* huf_tree_build(FILE* file)
{
    ctree_node* tree;
    tree = ctree_build_tree(get_freq(file));
    return tree;
}
void calc_codes(ctree_node* tree, int length, char* path, code* symbols[])
{
    if (tree->children[0] != NULL)
    {
        path[length] = 0;
        calc_codes(tree->children[0], length + 1, path, symbols);
    }
    if (tree->children[1] != NULL)
    {
        path[length] = 1;
        calc_codes(tree->children[1], length + 1, path, symbols);
    }
    if ((tree->children[1] == NULL) && (tree->children[0] == NULL))
    {
        for(int index = 0; index < length; index++)
        {
            symbols[tree->letter]->code[index] = path[index];
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

int *get_freq(FILE *input)
{
    char buffer[257];
    int size = fread(buffer, sizeof(char), 257, input);
    int *freq = (int *)malloc(sizeof(unsigned int) * BUFFER_SIZE);
    for (int i = 0; i < 257; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        freq[buffer[i]] += 1;
    }
    rewind(input);
    return freq;
}

void encode(char *in, char *out)
{
    FILE *input = fopen(in, "rb");
    FILE *file_out = fopen(out, "wb+");
    char buffer[BUFFER_SIZE];
    int char_read = fread(buffer, sizeof(char), 257, input);
    fwrite(get_freq(input), sizeof(int), 257, file_out);
    int *frequences = get_freq(input);
    ctree_node *d = ctree_build_tree(frequences);
    code *char_codes[BUFFER_SIZE];
    char path[BUFFER_SIZE];
    calc_codes(d, 0, path, char_codes);
    bitstream *bstream = bitstream_init(file_out, 'w');

    while (char_read = fread(buffer, sizeof(char), 257, input))
    {
        for (int i = 0; i < char_read; i++)
        {
            code_char(bstream, char_codes[buffer[i]]);
        }
    }
}
