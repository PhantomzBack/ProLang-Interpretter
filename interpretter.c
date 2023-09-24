#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define LENGTH_ENCLOSING_OPENERS 4;
//const char enclosingOpeners[LENGTH_ENCLOSING_OPENERS]={'{','(','"','\''};
//const char dontReadTags[]={''}
struct var{
    int numBytes; //will hold the number of bytes possessed by data type
    int *memPtr; //holds the memory pointer
};


const char* statement_format[]={"hello", "hi"};
int main(int argc, char* argv[]){ 
    if(argc!=2){
        printf("Incorrect number of arguments");
        exit(1); //error code 1 for incorrect number of arguments
    }
    
    /*FILE* program_fp=fopen(argv[1], "r");
    if(program_fp==NULL){
        printf("Unable to open file");
        exit(2); //error code 2 for file not opening
    }*/
    int x;
    scanf("%d", &x);
    printf("%d", x);
    
    //printf("%s", statement_format[1]);
    


}