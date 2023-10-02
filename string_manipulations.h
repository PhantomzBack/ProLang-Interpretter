#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#ifndef _STRING_MANIPULATIONS_H
#define _STRING_MANIPULATIONS_H
unsigned char segregate_as_i_v_f(char* input_str);
int search_index(char* input_string, char check_char, int starting_pointer);
int len_string(char* input_string);
char* copy_string(char* orig_str, int start_index, int end_index, int num_args, char* remove_char_args);
char* strip_spaces(char* input_string);
#endif