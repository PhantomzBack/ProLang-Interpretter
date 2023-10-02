#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



#ifndef _VARIABLE_H
#define _VARIABLE_H

struct variable
{
    int val;
};
struct variable_names{
    char* list_var_names[5];
    struct variable* list_var_pointers[5];
    struct variable_names* next_ptr;

};
bool variable_exists(char* variable_name, struct variable_names* v);
struct variable_names *initialize_new_variable_names_node();
struct variable *get_variable_value_ptr(char* variable_name, struct variable_names* v);
unsigned char set_variable_value(char* variable_name, int val, struct variable_names* v);
unsigned char validate_variable(char* variable_name);


#endif