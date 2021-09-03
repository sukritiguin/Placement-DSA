#include<bits/stdc++.h>
using namespace std;

void deleteMiddle(stack<int> &st,int n,int count=0){
    //if stack empty or all the elements are traversed then return
    if(st.empty() || count==n)
        return;
    
    //store the top element then pop then call recursive function
    int temp = st.top();
    st.pop();
    deleteMiddle(st,n,count+1);

    //if the middle element is found then don't push
    if(count!=n/2)
        st.push(temp);
}

void PrintStack(stack<int> s)
{
    // If stack is empty then return
    if (s.empty())
        return;
     
 
    int x = s.top();
 
    // Pop the top element of the stack
    s.pop();
 
    // Recursively call the function PrintStack
    PrintStack(s);
 
    // Print the stack element starting
    // from the bottom
    cout << x << " ";
 
    // Push the same element onto the stack
}

int main(){
    int choice=1;
    stack<int> st;
    while(1){
        cout<<"0. Exit\n1. Push Data\n2. Delete Middle\n3. Display Stack\n";
        cout<<"Enter Choice : ";
        cin>>choice;
        if(choice==0)
            exit(0);
        else if(choice==1){
            int data;
            cout<<"\nPush Data : ";
            cin>>data;
            st.push(data);
        }
        else if(choice==2)
            deleteMiddle(st,st.size());
        else if(choice==3){
            PrintStack(st);
            cout<<"\n";
        }
        else
            cout<<"Wrong Input\n";
    }

    return 0;
}
