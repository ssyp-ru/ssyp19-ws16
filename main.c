#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[]){
if((strcmp(argv[3],"-c"))==0){
    encode(argv[1],argv[2]);
}
if((strcmp(argv[3],"-d"))==0){
    decode(argv[1],argv[2]);
}
}
