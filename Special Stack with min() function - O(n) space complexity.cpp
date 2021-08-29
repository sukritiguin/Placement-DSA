#include<bits/stdc++.h>
using namespace std;
stack<int> auxilary_stack;
stack<int> actual_stack;

void push();
void pop();
int min();
int top();


int main(){
    int choice;
    while(1){
        cout<<"--- Operations ---\n";
        cout<<"0. Exit\n1. Push\n2. Pop\n3. Top\n4. Min\n"<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice;
        if(choice==0)
            exit(0);
        else if(choice==1)
            push();
        else if(choice==2)
            pop();
        else if(choice==3){
            cout<<"Top element is : "<<top()<<endl;
        }
        else if(choice==4){
            cout<<"Minimum element is : "<<min()<<endl;
        }
    }

    return 0;
}

void push(){
    int data;
    cout<<"Enter data : ";
    cin>>data;
    actual_stack.push(data);
    if(auxilary_stack.empty())
        auxilary_stack.push(data);
    else{
        if(actual_stack.top()<auxilary_stack.top())
            auxilary_stack.push(actual_stack.top());
    }
    cout<<"Element Pushed."<<endl;
}

void pop(){
    if(actual_stack.empty()){
        cout<<"Stack underflow!"<<endl;
        return;
    }
    else{
        if(actual_stack.top()==auxilary_stack.top() && !auxilary_stack.empty()){
            actual_stack.pop();
            auxilary_stack.pop();
        }
        else{
            actual_stack.pop();
        }
        cout<<"Top element is popped."<<endl;
        return;
    }
}

int min(){
    return auxilary_stack.top();
}

int top(){
    return actual_stack.top();
}
