#include<bits/stdc++.h>
using namespace std;
stack<int> st;

void next_largest(int arr[],int arr_size,int target);

int main(){
    int arr_size;
    cout<<"Enter the array size : ";
    cin>>arr_size;
    int arr[arr_size];
    cout<<"Enter array elements : ";
    for(int i=0;i<arr_size;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the target element : ";
    cin>>target;
    next_largest(arr,arr_size,target);
}

void next_largest(int arr[],int arr_size,int target){
    int index = arr_size-1;
    while(arr[index]!=target){
        if(arr[index]>target)
            st.push(arr[index]);
        index--;
    }
    cout<<"Next largest element is : "<<st.top()<<endl;

}
