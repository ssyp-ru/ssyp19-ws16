#include <stdio.h>
#include <stdlib.h>

void get_freq (FILE *input){
char buffer[257];
}
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
// -------

/*
int main(){
    FILE *input = fopen("C:\\C\\File1.txt","r");
    char buffer[B_S];
    int char_read = fread(buffer, sizeof(char),B_S,input);
    get_freq(buffer,char_read);
}
*/
