#include<bits/stdc++.h>
using namespace std;
#define arr_size 100

stack<char> st;

void check_balanced_parentheses(char exp[]);

int main(){
    char exp[arr_size];
    cout<<"Enter the expression : ";
    gets(exp);
    cout<<"Expression is : "<<exp<<endl;
    check_balanced_parentheses(exp);
}

void check_balanced_parentheses(char exp[]){
    int i = 0;
    while(exp[i]!='\0'){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            st.push(exp[i]);
        }
        else if(exp[i]=='}' || exp[i]=='}' || exp[i]=='}'){
            if(st.empty()){
                cout<<"Expression is not correct."<<endl;
                return;
            }
            else if(exp[i]!=st.top()){
                cout<<"Expression is not correct."<<endl;
                return;
            }
            else if(exp[i]==st.top()){
                st.pop();
            }
        }
        i++;
    }
    if(!st.empty()){
        cout<<"Expression is not correct."<<endl;
        return;
    }
    else if(st.empty()){
        cout<<"Expression is correct."<<endl;
        return;
    }
}