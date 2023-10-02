#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#ifndef _EXPRESSION_EVALUATOR_H
#define _EXPRESSION_EVALUATOR_H
#ifndef OPERATOR_LIST_LENGTH
#define OPERATOR_LIST_LENGTH 4
#endif
#ifndef HIGHEST_OPERATOR_PRECEDENCE
#define HIGHEST_OPERATOR_PRECEDENCE 1
#endif
typedef struct pro_operator{
    char denotion_char;
    unsigned char precedence;
}pro_operator;

const pro_operator operator_list[4];
bool valid_character(char x);
int eval(int val1, int val2, char denotion_char);
int skip_parentheses(char* eval_string, int str_ptr);
char* copy_string(char* orig_str, int start_index, int end_index, int num_args, char* remove_char_args);
int eval_expr(char* eval_string, int str_ptr);
#endif
/*TODO: Build functions to skip over character strings and all, character string should be innermost skipping thing, above which can be parentheses. I.e, '(' will skip the over the bracket but ('') should not skip over the character string */
