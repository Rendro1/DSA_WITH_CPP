// Celebrity problem where a celebrity knows no one and everyone knows that celebrity
//so we have a given matrix and we have to find that which element is celebrity

#include<bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int>>&m,int a,int b){
    if(m[a][b]==1){
        return true;
    }
    else{
        return false;
    }
}

int celebrity(vector<vector<int>>&m,int n){
    stack<int>s;
    //step-1
    for(int i=0;i<n;i++){
        s.push(i); //pusing all element to the stack
    }
    //step-2
    while(s.size()>1){
        // storing top 2 element to check knows function
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        // checking wheather a and b knows each other or not
        if(knows(m,a,b)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int candidate = s.top();
    //step-3->when one element present in stack is it celebrity or not
    bool rowcheck = false;
    int zerocount=0;
    for(int i=0;i<n;i++){
        if(m[candidate][i]==0){
            zerocount++;
        }
    }
    if(zerocount==n){
        rowcheck = true; 
    }
    // column check->
    bool colcheck = false;
    int onecount=0;
    for(int i=0;i<n;i++){
        if(m[i][candidate]==1){
            onecount++;
        }
    }
    if(onecount==n-1){
        colcheck = true;
    }

    if(rowcheck==true && colcheck==true){
        return candidate;
    }
    else{
        return -1;
    }

}

int main(){
    vector<vector<int>>m = {{0,1,0},{0,0,0},{0,1,0}};
    int n=3;
    cout<<celebrity(m,n);
    return 0;
}