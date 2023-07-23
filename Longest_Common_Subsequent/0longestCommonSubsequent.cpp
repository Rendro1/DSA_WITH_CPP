#include<bits/stdc++.h>
using namespace std;

int LCS(int n ,int m,string s1,string s2){
    if(n==0 || m ==0){
        return 0;
    }
    if(s1[n-1]==s2[m-1]){
        return 1+ LCS(n-1,m-1,s1,s2);
    }
    return max(LCS(n-1,m,s1,s2),LCS(n,m-1,s1,s2));
}
int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int n = s1.length();
    int m = s2.length();
    cout<<LCS(n,m,s1,s2)<<endl;
    return 0;
}