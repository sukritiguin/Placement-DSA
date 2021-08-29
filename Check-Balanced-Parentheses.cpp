#include<bits/stdc++.h>
using namespace std;
stack<char> st;
#define size_of_exp 50

void checkParentheses(char exp[],int n){
    for(int i=0;i<n;i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            st.push(exp[i]);
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(st.empty() || st.top()!=exp[i])
                return;
            else
                st.pop();
        }
    }
}

int main(){
    char exp[size_of_exp];
    printf("Enter the expression : ");
    scanf("%s",&exp);
    checkParentheses(exp,(unsigned)strlen(exp));
    (st.empty())?cout<<"Balanced Parentheses."<<endl:cout<<"Unbalanced Parentheses."<<endl;
}