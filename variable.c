#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "variable.h"

#define CHECK_ALLOWED_CHARS(v1) ((v1>='a' && v1<='z') || (v1>='A' && v1<='Z') || v1=='_' || (v1>='0' && v1<='9'))
int num_variables=0;

/*
struct variable{
    int val;
};


*/


//typedef struct variable_names variable_names;
//typedef struct variable variable;





const int len_keywords=1;
const char* keywords[]={"var"};

//struct variable_names v1={{NULL, NULL, NULL, NULL, NULL}, {NULL, NULL, NULL, NULL, NULL}, NULL};

bool variable_exists(char* variable_name, struct variable_names* v){
    int z=0;
    for(int i=0;i!=num_variables;i++){
        
        if(strcmp(variable_name, v->list_var_names[z])==0){
            return true;
        }
        z++;
        if(z==5){
            v=v->next_ptr;
            z-=5;
        }
    }
    return false;
}

struct variable_names *initialize_new_variable_names_node(){
    struct variable_names* new_node_ptr=(struct variable_names*)malloc(sizeof(struct variable_names));

    for(int i=0; i!=5; i++){
        new_node_ptr->list_var_names[i]=NULL;
        new_node_ptr->list_var_pointers[i]=NULL;
    }
    new_node_ptr->next_ptr=NULL;
    return new_node_ptr;

    //*v={{NULL, NULL, NULL, NULL, NULL}, {NULL, NULL, NULL, NULL, NULL}, NULL};

}

struct variable *get_variable_value_ptr(char* variable_name, struct variable_names* v){
    int z=0;
    for(int i=0;i!=num_variables;i++){
        if(strcmp(variable_name, v->list_var_names[z])==0){
            return (struct variable*)(v->list_var_pointers[z]);
        }
        z++;
        if(z==5){
            v=v->next_ptr;
            if(v==NULL){
                return NULL;
            }
            z-=5;
        }
    }
    return NULL;
}

unsigned char set_variable_value(char* variable_name, int val, struct variable_names* v){
    int z=0;
    for(int i=0;i!=num_variables;i++){
        if(strcmp(variable_name, v->list_var_names[z])==0){
            if((v->list_var_pointers[z])==NULL){
                struct variable* new_var=(struct variable*)malloc(sizeof(struct variable));
                new_var->val=val;
                v->list_var_pointers[z]=new_var;
            }
            else{
                v->list_var_pointers[z]->val=val;
            }
        }
        z++;
        if(z==5){
            v=v->next_ptr;
            if(v==NULL){
                return 2;
            }
            z-=5;
        }
    }
    return 3;


}
/*Can easily be changed to set or create*/
unsigned char create_set_variable(char* variable_name, int val, struct variable_names* v){
    /*validation*/
    if(!validate_variable(variable_name)){
        if(!variable_exists(variable_name,v)){
            int x=num_variables;
            while(!(x<5)){
                if(v->next_ptr==NULL){
                    v->next_ptr=initialize_new_variable_names_node();
                }
                v=v->next_ptr;
                x-=5;
            }
            char* newPtr=(char*)malloc(sizeof(char)*strlen(variable_name));
            strcpy(newPtr, variable_name);
            //memcpy(, strlen(variable_name));
            
            v->list_var_names[x]=newPtr;
            struct variable* new_variable_ptr=(struct variable*)malloc(sizeof(new_variable_ptr));
            v->list_var_pointers[x]=new_variable_ptr;
            new_variable_ptr->val=val;
            num_variables++;
        }
        else{
            int z=0;
            for(int i=0;i!=num_variables;i++){
                if(strcmp(variable_name, v->list_var_names[z])==0){
                    struct variable* new_variable_ptr=(struct variable*)malloc(sizeof(new_variable_ptr));
                    v->list_var_pointers[z]=new_variable_ptr;
                    new_variable_ptr->val=val;
                    num_variables++;
                    break;
                }
                z++;
                if(z==5){
                    v=v->next_ptr;
                    z-=5;
                }
            }
        }
        
    }
    else{

    }


}
/*TODO: figure out if I need create, set or just create_set*/
unsigned char create_variable(char* variable_name, int val, struct variable_names* v){
    /*validation*/
    if(!validate_variable(variable_name)){
        if(!variable_exists(variable_name,v)){
            int x=num_variables;
            while(!(x<5)){
                if(v->next_ptr==NULL){
                    v->next_ptr=initialize_new_variable_names_node();
                }
                v=v->next_ptr;
                x-=5;
            }
            char* newPtr=(char*)malloc(sizeof(char)*strlen(variable_name));
            strcpy(newPtr, variable_name);
            //memcpy(, strlen(variable_name));
            
            v->list_var_names[x]=newPtr;
            struct variable* new_variable_ptr=(struct variable*)malloc(sizeof(new_variable_ptr));
            v->list_var_pointers[x]=new_variable_ptr;
            new_variable_ptr->val=val;
            num_variables++;
        }
        else{
            
        }
        
    }
    else{

    }
}


unsigned char validate_variable(char* variable_name)
{
    if(variable_name==""){
        return 3;
    }
    for(int i=0; i!=len_keywords; i++){
        if(!strcmp(variable_name, keywords[i])){
            return 2;
        }
    }
    if(variable_name[0]>='0' && variable_name[0]<='9'){
        // Starting with digit
        return 4;
    }
    int str_ptr=0;
    while(variable_name[str_ptr]!='\0'){
        // Unexpected Character
        if(!CHECK_ALLOWED_CHARS(variable_name[str_ptr])){
            return 5;
        }
        str_ptr++;
    }
    return 0;
}


/*int main(){
    
    int x=10;
    struct variable_names* v=initialize_new_variable_names_node();
    while(1){
        printf("1 to create or change, 2 to view");
        scanf("%d", &x);
        
        if(x==1){
            char name[100];
            int x;
            scanf("%s %d", name, &x);
            create_set_variable(name, x, v);
        }
        else if(x==2){
            char name[100];
            scanf("%s", name);
            printf("%d\n", get_variable_value_ptr(name, v)->val);
        }
        
        else{
            break;
        }
        
    }
    
    /*printf("%s %d" , v->list_var_names[0], v->list_var_pointers[0]);
    for(int i=1; i!=10; i++){
        sprintf(name, "test_variable_%d", i);
        printf("Current variable name: %s\n", name);
        create_set_variable(name, i, v);
    }
    
    printf("\n\n%s %d", v->list_var_names[0], v->list_var_pointers[0]->val);*/
    //printf("Lol: %d\n", get_variable_value_ptr("test_variable_1")->val);

//}