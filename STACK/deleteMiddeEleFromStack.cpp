#include<bits/stdc++.h>
using namespace std;

void Solve(stack<int>&st,int n,int count){
    //base case recurssion
    if(count== n/2){
        st.pop();
        return;
    }
    int num = st.top();
    st.pop();
    Solve(st,n,count+1);
    st.push(num);
}
void deleteMiddle(stack<int>&st,int n){
    int count = 0;
    Solve(st,n,count);
}
int main(){
    stack<int>s;
    int n;
    cin>>n;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        s.push(num);
    }
    deleteMiddle(s,n);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}

// input:-> 2 4 6 8 9
// output:-> 9 8 4 2
// middle element 6 is deleted