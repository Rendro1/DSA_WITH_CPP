#include<bits/stdc++.h>
using namespace std;

void result(queue<int>q,int n){
    stack<int>s;
    queue<int>res;
    for(int i=0;i<n/2;i++){
        int val = q.front();
        s.push(val);
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    for(int i=0;i<n/2;i++){
        int val = q.front();
        q.push(val);
        q.pop();
    }
    for(int i=0;i<n/2;i++){
        int val = q.front();
        s.push(val);
        q.pop();
    }
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    cout<<endl;
    while(!q.empty()){
        int sval = s.top();
        int qval = q.front();
        res.push(sval);
        res.push(qval);
        s.pop();
        q.pop();
    }
    while(!res.empty()){
        cout<<res.front()<<" ";
        res.pop();
    }
}

int main(){
    queue<int>q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    result(q,10);
    return 0;
}