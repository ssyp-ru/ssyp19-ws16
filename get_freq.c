#include <stdio.h>
#include <stdlib.h>
#define B_S 300

// ENCODER
void get_freq (char *buffer,int dlina){
int freq[257];
for (int i=0;i<257;i++){
    freq[i] = 0;
}


for (int i=0;i<dlina;i++){
freq[buffer[i]] += 1;
}
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
