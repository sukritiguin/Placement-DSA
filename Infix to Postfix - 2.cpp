#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define size 150

char stack[size];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    if(top==-1)
        return -1;
    else
        return stack[top--];
}

int priority(char ch){
    if(ch == '(')
        return 0;
    else if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '^')
        return 3;
}

int main(){
    char exp[size];
    printf("Enter the expression : ");
    scanf("%s",&exp);
    char *exp_ptr,x;
    exp_ptr = exp;
    while(*exp_ptr!='\0'){
        if(isalnum(*exp_ptr))
            printf("%c",*exp_ptr);
        else if(*exp_ptr == '(')
            push(*exp_ptr);
        else if(*exp_ptr == ')'){
            while((x=pop()) != '(')
                printf("%c",x);        }
        else{
            while(priority(stack[top]) >= priority(*exp_ptr))
                printf("%c",pop());
            push(*exp_ptr);
        }
        exp_ptr++;
    }
    while(top != -1)
        printf("%c",pop());

    return 0;
}
