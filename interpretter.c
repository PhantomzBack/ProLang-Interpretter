#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "variable.h"
#include "string_manipulations.h"
#include "expression_evaluator.h"
#include "interpretter.h"


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

char* s1=" var T = E ;";
char* s2=" var T ;";

typedef struct prolang_file{
    FILE* fptr;
    int num_statements;
    char **statements_list;

}prolang_file;

typedef struct substat_structure{
    char denotion_char;
    void (*func_ptr)(char*, char*);
    int len_possible_sub_statements;
    char (*sub_statements)[];
    //struct substat_structure possible_sub_statements[];
};

const struct substat_structure expression={'E', &match_str};
const char* statement_format[]={"hello", "hi"};

prolang_file* initialize_file(FILE* fptr){
    
    if(fptr==NULL){
        
        return NULL;
    }
    
    prolang_file *new_file=malloc(sizeof(prolang_file));
    new_file->fptr=fptr;
    
    unsigned int num_statements=0;
    FILE* fp_copy=fptr;
    char ch;
    bool in_quotes=false;
    unsigned int len_file=0;
    printf("Hello");
    while(1){
        ch=fgetc(fp_copy);
        if(ch==EOF){
            break;
        }
        if(ch==';' && !in_quotes){
            num_statements+=1;
        }
        if(ch=='\''){
            in_quotes=!in_quotes;
        }
        else if(ch=='\n'){
        }
        else{
            len_file+=1;
        }
    }
    printf("\nHow are %d, ", num_statements);
    fp_copy=fptr;
    char **statements=malloc(num_statements*sizeof(char*));
    unsigned int *statement_lengths=malloc(num_statements*sizeof(unsigned int));
    unsigned int current_statement_length=0;
    new_file->num_statements=num_statements;
    
    for(unsigned int counter=0; counter!=num_statements;counter++){
        while(1){
            ch=fgetc(fp_copy);
            if(ch==EOF){
                break;
            }
            if(ch==';' && !in_quotes){
                current_statement_length+=1;
                statement_lengths[counter]=current_statement_length;
                break;
            }
            if(ch=='\''){
                in_quotes=!in_quotes;
            }
            else if(ch=='\n'){
            }
            else{
                current_statement_length+=1;
            }
        }
        printf("\nStatement %d: %d\n", counter, statement_lengths[counter]);
    }
    
    fp_copy=fptr;
    printf("Reached here too.");
    for(unsigned int counter=0; counter!=num_statements;counter++){
        char* current_statement=malloc(statement_lengths[counter]*sizeof(char));
        int x=0;
        printf("Yahan tak sahi hai");
        while(1){
            ch=fgetc(fp_copy);
            if(ch==EOF){
                break;
            }
            if(ch==';' && !in_quotes){
                current_statement[x]=ch;
                statements[counter]=current_statement;
                break;
            }
            if(ch=='\''){
                in_quotes=!in_quotes;
            }
            else if(ch=='\n'){
            }
            else{
                current_statement[x]=ch;
                x++;
            }
        }
        printf("\nStatement %d: %s\n", counter, statements[counter]);
    }
    printf("Did I reach here?");
    new_file->statements_list=statements;
    return new_file;
    #ifdef HELLO
    while(1){
        /*Keep iterating to get statements. Statements end with ;. Make sure the ; isn't in quotes.*/
        FILE* fptr_copy=fptr;
        char ch;
        unsigned int statement_length=0;
        bool file_ended=false;
        while(1){
            ch=fgetc(fptr_copy);
            if(ch=='\n'){
                continue;
            }
            else if(ch==';'){
                statement_length+=1;
                break;
            }
            else if(ch=='\''){
                do{
                    ch=fgetc(fptr_copy);
                    statement_length+=1;
                }while(ch=='\'');
            }
            else if(ch==EOF){
                file_ended=true;
                break;
            }
            else{
                statement_length+=1;
            }
        }
        if(!file_ended){
            num_statements+=1;
            
            char* statement=malloc(statement_length*sizeof(char));
            unsigned int x=0;
            while(1){
                ch=fgetc(fptr);
                if(ch=='\n'){
                    continue;
                }
                else if(ch==';'){
                    statement[x]=ch;
                    break;
                }
                else{
                    statement[x]=ch;
                    x++;
                }
            }
        }
        
    }
    #endif
}

int main(int argc, char* argv[]){
    /*if(argc!=1){
        printf("incorrect number of arguments");
        exit(10);
    }
    FILE* fptr;
    fptr=fopen(argv[1],"r");*/
    prolang_file *new_file=initialize_file(fopen(argv[1], "r"));
    for(int i=0; i!=new_file->num_statements;i++){
        printf("%s\n", new_file->statements_list[i]);
    }
    printf("Done printing \n");
    int x=10;
    current_scope_variable_names=initialize_new_variable_names_node();
    printf("%d", segregate_as_i_v_f("10"));
    printf("%d", eval_expr("10", 0));
    while(1){
        char name[100];
        printf("1 to create or change, 2 to view, 3 to evaluate expression");
        scanf("%d", &x);
        if(x==1){
            char y[1000];
            scanf("%s %s", name, y);
            create_set_variable(name, eval_expr(y, 0), current_scope_variable_names);
        }
        else if(x==2){
            
            scanf("%s", name);
            printf("%d\n", get_variable_value_ptr(name, current_scope_variable_names)->val);
        }
        else if(x==3){
            
            scanf("%s", name);
            printf("%d", eval_expr(name, 0));
        }
        else{
            break;
        }
        
    }
    printf("%d", segregate_as_i_v_f("ravi_arora(hi)"));
    //printf("%s", statement_format[1]);
    


}