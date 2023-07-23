#include<bits/stdc++.h>
using namespace std;

bool redundentBraket(string &s){
    stack<char>st;
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            st.push(ch);
        }
        else{
            if(ch==')'){
                bool isRedunt = true;
                while(st.top() !='('){
                    char top = st.top();
                    if(top=='+' || top=='-' || top=='*' || top=='/'){
                        isRedunt = false;
                    }
                    st.pop();
                } 
                if(isRedunt==true){
                    return true;
                }
                st.pop();  
            }
        }
    }
    return false;
}

int main(){
    string s = "((a+b))";
    if(redundentBraket(s)){
        cout<<"It's Redundent";
    }
    else{
        cout<<"Not Redundent";
    }
    return 0;
}