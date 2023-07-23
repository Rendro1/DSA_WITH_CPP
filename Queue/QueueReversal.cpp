// Reverse a queue:->
#include<bits/stdc++.h>
using namespace std;

void rev(queue<int>q){
    stack<int>s;
    while(!q.empty()){
        int ele = q.front();
        s.push(ele);
        q.pop();
    }
    while(!s.empty()){
        int ele = s.top();
        s.pop();
        q.push(ele);
    }
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main(){
    queue<int>q;
    int n;
    cout<<"Enter the size of arr-";
    cin>>n;
    for(int i=0;i<n;i++){
        int inp;
        cin>>inp;
        q.push(inp);
    }
    rev(q);

    return 0;
}