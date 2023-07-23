#include<bits/stdc++.h>
using namespace std;

int ans(vector<int>&arr,int k){
    if(arr.size()<k){
        return 0;
    }
    int sum = 0;
    int i=0;
    int j=0;
    int mx=INT_MIN;
    while(j<arr.size()){
        sum +=arr[j];
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            mx = max(mx,sum);
            sum = sum-arr[i];
            i++;
            j++;
        }
    }
    return mx;
}

int main(){
    vector<int>v={1, 4, 2, 10, 2, 3, 1, 0, 20};
    cout<<ans(v,4);
    return 0;
}