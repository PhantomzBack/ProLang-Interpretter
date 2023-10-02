#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "variable.h"
#include "string_manipulations.h"
#include "expression_evaluator.h"


#define LENGTH_ENCLOSING_OPENERS 4;
#define CHECK_ALLOWED_CHARS(v1) ((v1>='a' && v1<='z') || (v1>='A' && v1<='Z') || v1=='_' || (v1>='0' && v1<='9'))

//const char* statement_openers[]={"var"};
bool parse_statement()
{
    return true;
}
//const char enclosingOpeners[LENGTH_ENCLOSING_OPENERS]={'{','(','"','\''};
//const char dontReadTags[]={''}
struct var{
    int numBytes; //will hold the number of bytes possessed by data type
    int *memPtr; //holds the memory pointer
};




int match_str(char* input_string, char* matched_str){
    return 1;
}

int skip_quotes(int str_ptr){
    return str_ptr;
}

char* s1=" var T = E :";
char* s2=" var T :";

typedef struct substat_structure{
    char denotion_char;
    void (*func_ptr)(char*, char*);
    int len_possible_sub_statements;
    char (*sub_statements)[];
    //struct substat_structure possible_sub_statements[];
};

const struct substat_structure expression={'E', &match_str};
const char* statement_format[]={"hello", "hi"};
int main(int argc, char* argv[]){
    printf("%d", segregate_as_i_v_f("ravi_arora(hi)"));
    //printf("%s", statement_format[1]);
    


}