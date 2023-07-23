#include<bits/stdc++.h>
using namespace std;

static int t[1001][1001];

int res(string x,string y,int m,int n){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i==0 || j==0){
                t[i][j] = 0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1+t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[m][n];
}

int main(){
    string x;
    cin>>x;
    int m = x.length();
    string y = x;
    reverse(y.begin(),y.end());
    cout<<"Minimum no of deletion required is->"<<(x.length()-res(x,y,m,m))<<endl;
    cout<<"Minimum no of insertion required is->"<<(x.length()-res(x,y,m,m))<<endl;
    return 0;
}