#include<bits/stdc++.h>
using namespace std;

stack<int> st;

void reverse_stack();
void display();

int main(){
    while(1){
        int choice;
        cout<<"--- Options ---"<<endl;
        cout<<"0. Exit\n1. Push\n2. Reverse\n3. Display\n"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        if(choice==0)exit(0);
        else if(choice==1){
            int data;
            cout<<"Enter data : ";
            cin>>data;
            st.push(data);
        }
        else if(choice==2)reverse_stack();
        else if(choice==3){
            cout<<"Stack is : ";
            display();
            cout<<"\n";
        }
    }
}

void reverse_stack(){
    stack<int> temp1,temp2;
    while(!st.empty()){ //store the elements of st stack to temp1 stack
        temp1.push(st.top());
        st.pop();
    }
    //st : 2 4 6 8 10 then temp : 10 8 6 4 2
    while(!temp1.empty()){ //store the elements of temp1 stack to temp2 stack
        temp2.push(temp1.top());
        temp1.pop();
    }
    // then temp2 : 2 4 6 8 10
    while(!temp2.empty()){ //store the elements of temp2 stack to st stack
        st.push(temp2.top());
        temp2.pop();
    }
    // then st : 10 8 6 4 2
    cout<<"Stack is reversed."<<endl;
}

void display(){
    if(st.empty())return;
    int x = st.top();
    st.pop();
    cout<<x<<" ";
    display();
    st.push(x);
}