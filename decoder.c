#include "decoder.h"
/*
char tree_get_char(ctree_node *derevo, bitstream *logic)
{
    while (derevo->children[0] != NULL)
    {
        derevo = derevo->children[bitstream_get_bit(logic)];
        /*
        if(bitstream_get_bit(logic)) == 0){
            derevo = derevo ->children[0];
        }
        else{
            derevo = derevo ->children[1];
        }
    }
    return derevo->letter;

}
*/
ctree_node *huf_rebuild_tree(FILE *input)
{
    int read;
    char buffer[BUFFER_SIZE];
    int frequences[BUFFER_SIZE];
    ctree_node mas_ctree_node[BUFFER_SIZE];
    fread(frequences, sizeof(int), BUFFER_SIZE, input);
    return ctree_build_tree(frequences);
}

void decode(char *from, char *where)
{
	FILE *fromf = fopen(from, "rb");
	FILE *wheref = fopen(where, "wb+");
    bitstream *file = bitstream_init(fromf, 'r');
    ctree_node *tree = huf_rebuild_tree(fromf);
    ctree_node *tree1;
    tree1 = tree;
    while (tree->letter != BUFFER_SIZE)
    {
        while (tree->children[0] != NULL)
        {
            tree = tree->children[bitstream_get_bit(file)];
        }
        fwrite(&tree->letter, sizeof(char), 1, wheref);
    }
    tree = tree1;
}