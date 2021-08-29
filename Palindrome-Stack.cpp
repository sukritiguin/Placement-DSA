/*
    Given an array of characters formed with a’s and b’s. The string is marked with
    special character X which represents the middle of the list (for example:
    ababa...ababXbabab baaa). Check whether the string is palindrome.

    Algorithm:
        • Traverse the list till we encounter X as input element.
        • During the traversal push all the elements (until X) on to the stack.
        • For the second half of the list, compare each element’s content with top of the stack.
          If they are the same then pop the stack and go to the next element in the input list.
        • If they are not the same then the given string is not a palindrome.
        • Continue this process until the stack is empty or the string is not a palindrome.

*/


#include<bits/stdc++.h>
using namespace std;

stack<char> st;

void check_palindrome(char arr[]);

int main(){
    char arr[100];
    cout<<"Enter the input : ";
    gets(arr);
    check_palindrome(arr);
}

void check_palindrome(char arr[]){
    int i = 0;
    while(arr[i]!='X' || arr[i]!='x'){
        st.push(arr[i]);
        i++;
    }
    i++;
    while(arr[i]!='\0'){
        if(arr[i]!=st.top()){
            cout<<"Input is not palindrome."<<endl;
            return;
        }
        else if(arr[i]==st.top()){
            st.pop();
        }
        i++;
    }
    st.empty()?cout<<"Input is Palindrome"<<endl:cout<<"Input is not palindrome."<<endl;
    return;
}