#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "expression_evaluator.h"
//12*(8+3-4)




/*TODO: Build functions to skip over character strings and all, character string should be innermost skipping thing, above which can be parentheses. I.e, '(' will skip the over the bracket but ('') should not skip over the character string */
const pro_operator operator_list[]={{'*',1},{'/',1}, {'+',0},{'-',0}};
bool valid_character(char x){
    return 1;
}


/*typedef struct{
    char *format_string;
    int len_possible_sub_formats;
    format_spec possible_sub_formats[];

} format_spec;*/

int eval(int val1, int val2, char denotion_char)
{
    switch (denotion_char)
    {
    case '/':
        return val1/val2;
    case '+':
        return val1+val2;
    case '*':
        return val1*val2;
    case '-':
        return val1-val2;
    default:
        break;
    }
}
/*Return the next index after crossing the matching closing parentheses*/
int skip_parentheses(char* eval_string, int str_ptr){
    str_ptr++;
    while(eval_string[str_ptr]!='\0'){
        if(eval_string[str_ptr]=='('){
            str_ptr=skip_parentheses(eval_string, str_ptr)-1;
            if(str_ptr==-1){
                return -1;
            }
        }
        else if(eval_string[str_ptr]==')'){
            return str_ptr+1;
        }
        str_ptr++;
    }
    return -1;

}


/*Slice string to new one, with start index included, end not included, also get rid of unnecessary characters*/
/*char* copy_string(char* orig_str, int start_index, int end_index, int num_args, char* remove_char_args)
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
//}


int eval_expr(char* eval_string, int str_ptr){
    int current_operator_position=-1, lowest_operator_precedence=HIGHEST_OPERATOR_PRECEDENCE+1, num_operators=0;
    char current_operator;
    while(eval_string[str_ptr]!='\0'){
        if(eval_string[str_ptr]==' '){
        }
        else if(eval_string[str_ptr]=='('){
            str_ptr=skip_parentheses(eval_string, str_ptr);
            //return 0;
            if(str_ptr==-1){
                printf("Bracket mismatch, couldn't find closing bracket!");
                exit(17);
            }
            continue;
        }
        else{
        for(int j=0;j!=OPERATOR_LIST_LENGTH; j++){
            /*<= used in next statement to evaluate 12/2*4 as 12/2 * 4, else left most pro_operator would have lesser precedence*/
            if(eval_string[str_ptr]==operator_list[j].denotion_char && operator_list[j].precedence<=lowest_operator_precedence){
                lowest_operator_precedence=operator_list[j].precedence;
                current_operator_position=str_ptr;
                current_operator=operator_list[j].denotion_char;
            }
            if(eval_string[str_ptr]==operator_list[j].denotion_char){
                num_operators+=1;
            }
        }
        }
        str_ptr++;
    }
    if(num_operators==0){

        //TODO: Eval expression with shortened string instead of creating new memory space
        if(eval_string[0]=='('){
            return eval_expr(copy_string(eval_string, 1, str_ptr-1, 1, " "), 0);
        }
        else{
            return atoi(eval_string);
        }
    }
    else if(num_operators==1){
        //char* val1_str = char* copy_string(char* orig_str, int start_index, int end_index);
        char* val1_str=copy_string(eval_string, 0, current_operator_position, 1, " ");
        char* val2_str=copy_string(eval_string, current_operator_position+1, str_ptr, 1, " ");
        /*char* val1_str=(char*)malloc(current_operator_position+1);
        char* val2_str=(char*)malloc(str_ptr-current_operator_position);
        for (int i = 0; i < current_operator_position; i++)
        {
            val1_str[i]=eval_string[i];
        }
        val1_str[current_operator_position]='\0';
        for (int i = 0; i < str_ptr-current_operator_position-1; i++)
        {
            val2_str[i]=eval_string[current_operator_position+1+i];
        }
        val2_str[str_ptr-current_operator_position-1]='\0';*/
        int x=eval(eval_expr(val1_str, 0), eval_expr(val2_str, 0), current_operator);
        free(val1_str);
        free(val2_str);
        return x;
    }
    else if(num_operators>1){
        char* val1_str=copy_string(eval_string, 0, current_operator_position, 1, " ");
        char* val2_str=copy_string(eval_string, current_operator_position+1, str_ptr, 1, " ");

        /*char* val1_str=(char*)malloc(current_operator_position+1);
        char* val2_str=(char*)malloc(str_ptr-current_operator_position);
        
        for (int i = 0; i < current_operator_position; i++)
        {
            val1_str[i]=eval_string[i];
        }
        val1_str[current_operator_position]='\0';
        for (int i = 0; i < str_ptr-current_operator_position-1; i++)
        {
            val2_str[i]=eval_string[current_operator_position+1+i];
        }
        val2_str[str_ptr-current_operator_position-1]='\0';
        printf("\nEvaluating: %s as %s, %s\n", eval_string,val1_str, val2_str);*/
        int x=eval(eval_expr(val1_str,0),eval_expr(val2_str,0), current_operator);
        free(val1_str);
        free(val2_str);
        return x;
    }
    return -1;
}
/*
int eval_expr_old(char* eval_string, int str_ptr){
    int current_operator_position=-1, highest_precedence=-1,prev_operator_position, prev_operator_position_dynamic=-1, next_operator_position=0;
    char current_operator;
    while(eval_string[str_ptr]!='\0'){
        for(int j=0; j!=OPERATOR_LIST_LENGTH; j++){
            //printf("Here: %c %c\n", eval_string[str_ptr], operator_list[j].denotion_char);
            if(eval_string[str_ptr]==operator_list[j].denotion_char && operator_list[j].precedence>highest_precedence){
                current_operator_position=str_ptr;
                current_operator=operator_list[j].denotion_char;
                prev_operator_position=prev_operator_position_dynamic; // to store the value when a possible highest precendce pro_operator is found.
                next_operator_position=-1;
                highest_precedence=operator_list[j].precedence;
                break;
            }
            else if(eval_string[str_ptr]==operator_list[j].denotion_char){
                printf("%d\n", prev_operator_position_dynamic);
                prev_operator_position_dynamic=str_ptr;
                if(next_operator_position==-1){
                    next_operator_position=str_ptr;
                }
                break;
            }
        }
        str_ptr++;
    }
    if(next_operator_position==-1){
        next_operator_position=str_ptr;
    }
    printf("%d %d %d %c", prev_operator_position ,current_operator_position, next_operator_position, current_operator);
}
*/

/*int main(){
    char x[1000];
    scanf("%s", x);
    printf("%d", eval_expr(x, 0));
}*/