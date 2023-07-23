#include<bits/stdc++.h>
using namespace std;

int minimumCost(string s){
    if(s.size()%2 !=0){
        return -1;
    }
    stack<char>st;
    for(int i=0;i<s.size();i++){
        char ch = s[i];

        if(ch=='{'){
            st.push(ch);
        }
        else{
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        
    }
    // if stack contain invalid character
        int a =0,b=0;
        while(!st.empty()){
            if(st.top()=='{'){
                b++;
            }
            else{
                a++;
            }
        }
        int ans = (a+1)/2 + (b+1)/2;
        return ans;
    
}

int main(){
    string s= "{{{}";
    cout<<minimumCost(s);
    cout<<"Number of string need to reverse->";
    return 0;
}