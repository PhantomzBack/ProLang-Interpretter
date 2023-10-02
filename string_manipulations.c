#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include "expression_evaluator.h"
#include "variable.h"
int search_index(char* input_string, char check_char, int starting_pointer){
    for(int x=starting_pointer; input_string[x]!='\0'; x++){
        if(input_string[x]==check_char){
            return x;
        }
    }
    return -1;
}

unsigned char segregate_as_i_v_f(char* input_str){
    /*
    Integer- 1293
    Variable- abc_de_123
    Function- abc_de_123()
    */
   /*TODO: catch the exception of variable name like 123_abc here itself.*/
    bool integer=true, function=false;
    for(size_t i = 0; i < strlen(input_str); i++)
    {
        if(!(input_str[i]>='0' && input_str[i]<='0')){
            integer=false;
        }
        if(input_str[i]=='('){
            if(validate_variable(copy_string(input_str, 0, i+1, 0, "")) && skip_parentheses(input_str, i)==strlen(input_str)){
                function=true;
                return 3; //3=function
            }

        }
    }
    if(integer==true){
        return 1;
    }
    else if(!validate_variable(input_str)){
        return 2;
    }
    else{
        return 0;
    }
    

}



int len_string(char* input_string){
    int x=0;
    for(;input_string[x]!='\0';x++){

    }
    return x;

}


char* copy_string(char* orig_str, int start_index, int end_index, int num_args, char* remove_char_args)
{
    if(num_args==0){
        char* new_string= (char*)malloc(end_index-start_index+1);
        int i=0;
        for(i=start_index; i!=end_index &&  orig_str[i]!='\0'; i++){
            new_string[i-start_index]=orig_str[i];
        }
        new_string[i-start_index]='\0';
        return new_string;
    }
    if(num_args!=0){
        char* new_string= (char*)malloc(end_index-start_index+1);
        int i=start_index, p=0;
        for(i=start_index; i!=end_index &&  orig_str[i]!='\0'; i++){
            bool to_be_removed=false;
            for(int j=0;j!=num_args;j++){
                if(orig_str[i]==remove_char_args[j]){
                    to_be_removed=true;
                    break;
                }
            }
            if(!to_be_removed){
                new_string[p]=orig_str[i];
                p++;
            }
        }
        new_string[p]='\0';
        return new_string;
    }
    /*else{
        //TODO: Need to decide which method to remove extra letters is better, use a for loop and create a string of shortened size itself, or just create a string of same size as before, but put a '\0' at a smaller indice and waste memory
        int new_length;
        for(int i=start_index; i!=end_index &&  orig_str[i]!='\0';i++){
            bool to_be_removed=false;
            for(int j=0;j!=num_args;j++){
                if(orig_str[i]==remove_char_args[j]){
                    to_be_removed=true;
                    break;
                }
            }
            if(!to_be_removed){
                new_length+=1;
            }
        }
        char* new_string=(char*)malloc(new_length);
        //for(int i=start_index; i!=end_index)
    }*/
}


int search_str(char* main_str, char* sub_str, int start_index){
    int sub_str_len=strlen(sub_str), main_str_len=strlen(main_str);
    for(int i=start_index; i!=main_str_len-sub_str_len;i++){
        bool match=true;
        for(int j=0;j!=sub_str_len;j++){
            if(sub_str[j]!=main_str[i+j]){
                match=false;
                break;
            }
        }
        if(match){
            return i;
        }
    }
    return -1;
}

//" T1 somesubstring T2 "


char* strip_spaces(char* input_string)
{
    // "  hello  "
    int len_str=strlen(input_string), new_str_ptr=0, old_str_ptr=0;
    int starting_index=0, ending_index=len_str-1;
    for(;input_string[starting_index]==' ';starting_index++){

    }
    for(;input_string[ending_index]==' ';ending_index--){

    }
    return copy_string(input_string, starting_index, ending_index+1, 0, "");
    //char* new_str=(char*)malloc(ending_index-starting_index+1);
}
char* extract_substring(char* input_str, char* token_1, char* token_2){
    int t1_len=strlen(token_1), t2_len=strlen(token_2);
    int t1_index=search_str(input_str, token_1, 0);
    if(t1_index!=-1){
        t1_index+=t1_len;
        int t2_index=search_str(input_str, token_2, t1_index);
        if(t2_index!=-1){
            return strip_spaces(copy_string(input_str, t1_index, t2_index, 0, ""));
        }
    }
    else{
        return NULL;
    }
}
/*int main(){
    printf("%s", extract_substring("var T = E :", "var", "="));
}*/