#include<bits/stdc++.h>
using namespace std;

static int t[1001][1001];

int res(string x,string y,int m,int n){
    for(int i=1;i<(m+1);i++){
        for(int j=1;j<(n+1);j++){
            if(i==0 || j==0){
                t[i][j] =0;
            }
        }
    }
    for(int i=1;i<(m+1);i++){
        for(int j=1;j<(n+1);j++){
           if(x[i-1]==y[j-1]){
               t[i][j] = 1+t[i-1][j-1];
            }
           else{
               t[i][j] = max(t[i][j-1],t[i-1][j]);
           }
        }
    }
    return t[m][n];
}

int main(){
    string x,y;
    cin>>x;
    cin>>y;
    int m = x.length();
    int n = y.length();
    int result = res(x,y,m,n);
    if(result == x.length()){
        cout<<"Yes pattern matched"<<endl;
    }
    else{
        cout<<"NO not matched"<<endl;
    }
    return 0;
}
