#include<bits/stdc++.h>
using namespace std;
stack<int> price_stack;
stack<int> span_stack;

void spanCalculate(int price_arr[],int n){
    //Create one Span array
    int span_arr[n];
    //initilize i = 0 that will go upto n
    int i = 0;
    //span of 1st element of the price_arr always will be 1 then initilize it
    int span=1;
    price_stack.push(price_arr[0]);
    span_stack.push(span);
    span_arr[0]=span;
    i++;
    while(i<n){
        span = 1; //by default/minimum span is 1 for every price_arr element
        while(price_arr[i]>=price_stack.top()){
            span = span + span_stack.top(); //top of the price_stack is less than update span
            price_stack.pop(); //pop price_stack
            span_stack.pop(); //pop span_stack
        }
        span_stack.push(span); //push updated span
        price_stack.push(price_arr[i]); //push the current price_arr element
        span_arr[i] = span; //update span_arr using span_arr
        i++; //increment i
    }

    cout<<"Span Array : ";
    for(int i=0;i<n;i++){
        cout<<span_arr[i]<<" ";
    }
}
