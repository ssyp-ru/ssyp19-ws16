#include <stdio.h>
#include <stdlib.h>
#define 257 BUFFER_SIZE
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
    ctree_node *d= ctree_build_tree(get_freq(input);
    code char_codes[BUFFER_SIZE];
    calc_codes(d , 0 , char_codes);			    
    while(int char_read2 = fread(buffer, sizeof(char),257,input)){
        for(int i=0;i < char_read2;i ++){
            code_char(bitstream, char_codes[257]);
        }
    }
