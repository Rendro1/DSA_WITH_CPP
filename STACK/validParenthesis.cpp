#include<bits/stdc++.h>
using namespace std;

bool solve(string str){
    stack<char>st;
    for(int i=0;i<str.size();i++){
        if(str[i]=='[' || str[i]=='{' || str[i]=='('){
            st.push(str[i]);
        }
        if(str[i]==']' && st.top()=='['){
            // st.push(str[i]);
            st.pop();
        }
        else if(str[i]=='}' && st.top()=='{'){
            // st.push(str[i]);
            st.pop();
        }
        else if(str[i]==')' && st.top()=='('){
            // st.push(str[i]);
            st.pop();
        }
    }
    if(st.empty()){
        return true;
    }
    
    return false;
}

int main(){
    string str;
    cin>>str;
    if(solve(str)){
        cout<<"Valid Parenthesis spotted"<<endl;
    }
    else{
        cout<<"not valid"<<endl;
    }
    return 0;
}