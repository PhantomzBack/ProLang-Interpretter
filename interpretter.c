#include<stdio.h>
#include<stdlib.h>
#define LENGTH_ENCLOSING_OPENERS 4;
//const char enclosingOpeners[LENGTH_ENCLOSING_OPENERS]={'{','(','"','\''};
//const char dontReadTags[]={''}
struct var{
    int numBytes; //will hold the number of bytes possessed by data type
    int *memPtr; //holds the memory pointer
    //bool sign;
};
int main(){
    printf("hello");
}