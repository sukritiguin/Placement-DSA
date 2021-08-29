#include<bits/stdc++.h>
using namespace std;

stack<int> digit_stack;
int prefix_evaluation(string exp);

int main(){
    string exp;
    cout<<"Enter the expression : ";
    cin>>exp;
    cout<<"Answer : "<<prefix_evaluation(exp);
}

int prefix_evaluation(string exp){
    int i = exp.size()-1;
    while(i!=-1){
        if(isdigit(exp[i]))
            digit_stack.push(exp[i]-'0');
        else if(exp[i]=='*' || exp[i]=='/' || exp[i]=='+' ||exp[i]=='-' || exp[i]=='^'){
            int temp1 = digit_stack.top();
            digit_stack.pop();
            int temp2 = digit_stack.top();
            digit_stack.pop();
            if(exp[i]=='*'){
                digit_stack.push(temp1*temp2);
            }
            else if(exp[i]=='/'){
                digit_stack.push(temp1/temp2);
            }
            else if(exp[i]=='+'){
                digit_stack.push(temp1+temp2);
            }
            else if(exp[i]=='-'){
                digit_stack.push(temp1-temp2);
            }
        }
        i--;
    }
    return digit_stack.top();
}