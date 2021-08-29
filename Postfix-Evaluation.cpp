#include<bits/stdc++.h>
using namespace std;

stack<int> digit_stack;
int postfix_evaluation(char exp[]);

int main(){
    char exp[100];
    cout<<"Enter the expression : ";
    gets(exp);
    cout<<"Answer : "<<postfix_evaluation(exp);
}

int postfix_evaluation(char exp[]){
    int i = 0;
    while(exp[i]!='\0'){
        if(isdigit(exp[i]))
            digit_stack.push(exp[i]);
        else if(!isdigit(exp[i])){
            int temp1 = digit_stack.top()-'0';
            digit_stack.pop();
            int temp2 = digit_stack.top()-'0';
            digit_stack.pop();
            if(exp[i]=='*'){
                digit_stack.push(temp2*temp1);
            }
            else if(exp[i]=='/'){
                digit_stack.push(temp2/temp1);
            }
            else if(exp[i]=='+'){
                digit_stack.push(temp2+temp1);
            }
            else if(exp[i]=='-'){
                digit_stack.push(temp2-temp1);
            }
        }
        i++;
    }
    return digit_stack.top();
}