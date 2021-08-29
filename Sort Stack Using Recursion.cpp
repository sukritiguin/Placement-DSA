#include<bits/stdc++.h>
using namespace std;

stack<int> st;
void sort_stack();
void insert_correct_pos(int data);

int main(){
    st.push(11);
    st.push(2);
    st.push(32);
    st.push(3);
    st.push(12);
    st.push(41);
    sort_stack();
    cout<<"Stack after sort : ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n"<<endl;

    return 0;
}

void sort_stack(){
    if(st.size()>0){//if stack is not empty
        int temp = st.top(); //create a call-stack of temp
        st.pop();
        sort_stack();
        insert_correct_pos(temp);//from call stack take each element and insert at correct position
    }
}
void insert_correct_pos(int data){
    if(st.size()==0 || st.top()<data)//if stack is empty or top element of stack is lower than data the simply insert the data in top of the element
        st.push(data);
    else{
        int temp = st.top();//create a call-stack of temp and apply recursive call to push the data after popping in correct position
        st.pop();
        insert_correct_pos(data);
        st.push(temp);
    }
}
