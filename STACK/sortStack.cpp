#include<bits/stdc++.h>
using namespace std;

void printSTack(stack<int>&st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

void sortedInsert(stack<int>&st,int num){
    //base case
    if(st.empty() || (!st.empty() && st.top()<num)){
        st.push(num);
        return;
    }
    int n = st.top();
    st.pop();
    //recursive call
    sortedInsert(st,num);
    st.push(n);
}

void sortStack(stack<int>&st){
    if(st.empty()){
        return;
    }
    int num = st.top();
    st.pop();

    //recursive call
    sortStack(st);
    sortedInsert(st,num);
}

int main()
{
    stack<int>st;
    st.push(22);
    st.push(9);
    st.push(8);
    st.push(11);
    // cout<<"Before Sort-> ";
    // printSTack(st);
    // cout<<endl;
    sortStack(st);
    cout<<"After Sort-> ";
    printSTack(st);
    
    return 0;
}