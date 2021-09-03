#include<bits/stdc++.h>
using namespace std;

bool Matrix[4][4] = {{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};

bool isKnows(int a,int b){
    return Matrix[a][b];
}

int isCelebrity(int n){
    stack<int> st;
    for(int i=0;i<n;i++)
        st.push(i);
    
    if(st.empty())
        return -1;
    
    int celebrity;
    while(st.size()>1){
        int a = st.top();
        st.pop();
        int b= st.top();
        st.pop();

        if(isKnows(a,b))
            st.push(b);
        else
            st.push(a);
    }

    celebrity = st.top(); //st.top() may be celebrity

    for(int i=0;i<n;i++){
        if(i!=celebrity && (!isKnows(i,celebrity) || isKnows(celebrity,i)))
            return -1;
    }

    return celebrity;
}


int main(){
    int n = 4;
    int id = isCelebrity(n);
    id!=-1?cout<<"Celebrity : "<<id<<endl:cout<<"No one is celebrity"<<endl;

    return 0;
}
