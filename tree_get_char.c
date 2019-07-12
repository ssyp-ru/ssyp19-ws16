#include <stdio.h>
#include <stdlib.h>
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
