#include <bits/stdc++.h>
using namespace std;

void printSTack(stack<int>st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

void insertAtBottom(stack<int>&st,int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int num = st.top();
    st.pop();

    // recursive call
    insertAtBottom(st,ele);
    st.push(num);
}

void reverseStack(stack<int> &st)
{

    //base case
    if(st.empty()){
        return;
    }
    int num = st.top();
    st.pop();

    // recursive call->
    reverseStack(st);
    insertAtBottom(st,num);
  
    
}
int main()
{
    stack<int>st;
    st.push(2);
    st.push(9);
    st.push(17);
    st.push(19);
    cout<<"Before reverse-> ";
    printSTack(st);
    cout<<endl;
    reverseStack(st);
    cout<<"After Reverse-> ";
    printSTack(st);
    
    return 0;
}