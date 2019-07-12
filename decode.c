char tree_get_char(ctree_node *derevo,bitstream *logic){
for(derevo -> children[0] =! NULL){
    if(bitstream_get_bit(logic)) = 0){
        derevo = derevo ->children[0];
    }
    else{
        derevo = derevo ->children[1];
    }
}
return derevo.letter;

}

node huf_rebuild_tree(FILE *input)
{
    int read;
    char buffer [BUFER_SIZE];
    int frequences[BUFER_SIZE];
    ctree_node mas_ctree_node [BUFER_SIZE];
    fread(frequences,sizeof(int), BUFER_SIZE , input);
    return ctree_build_tree(frequences)
}
void decode(FILE *from, FILE *where)
{
    bitstream file = bitstream_init(from, r);
    node *tree = huf_rebuild_tree(*from)
    while (tree->letter != 257)
    {
        while (tree -> children[0] != NULL)
        {
            if (bitstream_get_bit = 0)
            {
                tree = tree -> children[0]
            }
            else
            {
                tree = tree-> children[1]
            }
        }
        fwrite (tree->letter, sizeof(char),1,where)
    }
    return where
}
