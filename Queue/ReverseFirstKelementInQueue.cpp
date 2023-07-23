#include<bits/stdc++.h>
using namespace std;

void K_Ele_reversal(queue<int>q,int k){
    stack<int>s;
    int i=0;
    while(i<k){
        s.push(q.front());
        q.pop();
        i++;
    }
    while(!s.empty()){
        int ele = s.top();
        q.push(ele);
        s.pop();
    }
    int t = q.size()-k;
    while(t--){
        int val = q.front();
        q.push(val);
        q.pop();
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
    cout<<endl;
    int k;
    cout<<"enter the value of k-";
    cin>>k;
    cout<<endl;
    for(int i=0;i<n;i++){
        int inp;
        cin>>inp;
        q.push(inp);
    }
    K_Ele_reversal(q,k);

    return 0;
}