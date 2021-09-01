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

string PostToPrefix(string exp){
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
            string temp = exp[i] + op2 + op1;
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
  cout << "Prefix : " << PostToPrefix(exp);
  return 0;
}
