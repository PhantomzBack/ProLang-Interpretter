#include<stdio.h>
#include<string.h>
//12*(8+3-4)
struct operator{
    char denotion_char;
    unsigned char precedence;
};
int eval(int val1, int val2, char denotion_char)
{
    switch (denotion_char)
    {
    case '/':
        return val1/val2;
        break;
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
    while(eval_string[str_ptr]!='\0'){
        
    }
}
int main(){
    char x[]="3/4+12/13";
    float eval_result;
    for(int i=0; x[i]!='\0';i++){
        
    }
}