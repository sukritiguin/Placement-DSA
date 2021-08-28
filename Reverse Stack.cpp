#include<iostream>
#include<stack>
using namespace std;

stack<int> st;

void reverse_stack();
void insert_at_buttom(int top_element);
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
        else if(choice==2){
            reverse_stack();
            cout<<"Stack is reversed successfully.\n";
        }
        else if(choice==3){
            cout<<"Stack is : ";
            display();
            cout<<"\n";
        }
    }
}

void reverse_stack(){
    if(st.empty())
        return;
    int top_element = st.top();//we will take the top element and will do recursive call for others
    //1st : take the top element
    //2nd : pop the top
    //3rd : reverse the extra stack using recursion call
    //4th : insert the top element(that was taken in 1st step) to the buttom of the stack
    st.pop();
    reverse_stack();
    insert_at_buttom(top_element);
}

void insert_at_buttom(int top_element){
    if(st.empty()){//now stack is empty now we have to insert top_element of the prev function
        st.push(top_element);
        return;
    }
    int top_ele = st.top();//keep the top element of the stack and call recursion for others
    st.pop();
    insert_at_buttom(top_element);
    st.push(top_ele);
}

void display(){
    if(st.empty())return;
    int x = st.top();
    st.pop();
    cout<<x<<" ";
    display();
    st.push(x);
}
