#include <iostream>
#include <stack>
#include<string>
using namespace std;

stack<string> st;

bool isOperator(char checkOp){
    if(checkOp=='^' || checkOp=='*' || checkOp=='/' || checkOp=='+' || checkOp=='-')
        return true;
    else
        return false;
}

string PostToInfix(string exp){
    int len = exp.size();
    int i = 0;
    while(i<len){
        if(!isOperator(exp[i]))
            st.push(string(1,exp[i]));//convert char to string
        else{
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = "(" + op2 + exp[i] + op1 + ")";
            st.push(temp);
        }
        i++;
    }
    return st.top();
}


int main() {
  string exp;
  cout<<"Enter Postfix : ";
  cin>>exp;
  cout << "Infix : " << PostToInfix(exp);
  return 0;
}
