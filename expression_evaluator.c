#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//12*(8+3-4)
typedef struct {
    char denotion_char;
    unsigned char precedence;
}operator;
#define OPERATOR_LIST_LENGTH 4
#define HIGHEST_OPERATOR_PRECEDENCE 1
const operator operator_list[]={{'*',1},{'/',1}, {'+',0},{'-',0}};
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

int eval_expr(char* eval_string, int str_ptr){
    printf("Eval str: %s\n\n", eval_string);
    int current_operator_position=-1, lowest_operator_precedence=HIGHEST_OPERATOR_PRECEDENCE+1, num_operators=0;
    char current_operator;
    while(eval_string[str_ptr]!='\0'){
        for(int j=0;j!=OPERATOR_LIST_LENGTH; j++){
            if(eval_string[str_ptr]==operator_list[j].denotion_char && operator_list[j].precedence<lowest_operator_precedence){
                lowest_operator_precedence=operator_list[j].precedence;
                current_operator_position=str_ptr;
                current_operator=operator_list[j].denotion_char;
            }
            if(eval_string[str_ptr]==operator_list[j].denotion_char){
                num_operators+=1;
            }
        }
        str_ptr++;
    }
    printf("%c\n", current_operator);
    if(num_operators==1){
        char* val1_str=(char*)malloc(current_operator_position+1);
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
        val2_str[current_operator_position]='\0';
        return eval(atoi(val1_str), atoi(val2_str), current_operator);
    }
    else if(num_operators>1){
        printf("Herehere\n");
        char* val1_str=(char*)malloc(current_operator_position+1);
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
        printf("%s %d    ...\n", val1_str, eval_expr(val1_str,0));
        printf("%s %d    ...\n", val2_str, eval_expr(val2_str,0));
        return eval(eval_expr(val1_str,0),eval_expr(val2_str,0), current_operator);
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
                prev_operator_position=prev_operator_position_dynamic; // to store the value when a possible highest precendce operator is found.
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
int main(){
    char x[]="3/4+13/3";
    printf("%d", eval_expr(x, 0));
}