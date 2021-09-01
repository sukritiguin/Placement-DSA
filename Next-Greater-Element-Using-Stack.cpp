#include<bits/stdc++.h>
using namespace std;

void next_greater_element(int arr[],int arr_size){
    stack<int> st;
    st.push(arr[0]);
    for(int i=0;i<arr_size;i++){
        if(st.empty()){
            st.push(arr[i]);
            continue;
        }
        while(!st.empty() && st.top()<arr[i]){
            cout<<st.top()<<" -> "<<arr[i]<<endl;
            st.pop();
        }
        st.push(arr[i]);
    }
    while(!st.empty()){
        cout<<st.top()<<" -> "<<-1<<endl;
        st.pop();
    }
}

int main(){
    int arr_size;
    cout<<"Enter size of array : ";
    cin>>arr_size;
    int arr[arr_size];
    cout<<"Enter the array element : ";
    for(int i=0;i<arr_size;i++)
        cin>>arr[i];
    next_greater_element(arr,arr_size);
}
