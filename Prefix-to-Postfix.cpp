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

string preToPostfix(string exp){
    int len = exp.size();
    int i = --len;
    while(i>=0){
        if(!isOperator(exp[i]))
            st.push(string(1,exp[i]));//convert char to string
        else{
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = op1 + op2 + exp[i];
            st.push(temp);
        }
        i--;
    }
    return st.top();
}


int main() {
  string exp;
  cout<<"Enter Infix : ";
  cin>>exp;
  cout << "Postfix : " << preToPostfix(exp);
  return 0;
}
