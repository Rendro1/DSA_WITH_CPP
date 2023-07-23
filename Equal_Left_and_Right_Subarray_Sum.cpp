#include<bits/stdc++.h>
using namespace std;

int res(vector<int>&v,int n){
    int pref[n];
    int suff[n];

    int sum=0,sum1=0;

    for(int i=0;i<n;i++){
        sum += v[i];
        pref[i] = sum;
    }
    for(int i=n-1;i>=0;i--){
        sum1 += v[i];
        suff[i] = sum1;
    }
    for(int i=0;i<n;i++){
        if(pref[i]==suff[i]){
            return (i+1);
        }
    }
    return -1;
}

int main(){
    vector<int>arr = {1,3,5,2,2};
    int n = arr.size();
    cout<<res(arr,n)<<endl;
    // res(arr,n);
    return 0;
}