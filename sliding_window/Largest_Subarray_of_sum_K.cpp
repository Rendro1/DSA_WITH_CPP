// variable size window

#include<bits/stdc++.h>
using namespace std;

void res(vector<int>&v,int k){
    int i=0;
    int j=0;
    int sum =0;
    int mx = 0;
    while(j<v.size()){
        sum +=v[j];
        if(sum<k){
            j++;
        }
        // cout<<j<<endl;
        if(sum==k){
            mx = max(mx,(j-i+1));           
            j++;
            // cout<<i<<" "<<j<<endl;
        }
        if(sum>k){
            while(sum>k){
                sum = sum-v[i];
                i++;
            }                
            j++;      
        }
        
    }
    
    cout<<mx<<endl;
    // return mx;
}

int main(){
    // vector<int>v = {4,1,1,1,2,3,5};
    vector<int>v = {17, 15, -13, 0, 6, 15, 16, 2, 15, -12, 17, -16, 0, -3, 19, -3, 2,-9,-6};
    int sum = 15;
    res(v,sum);
    return 0;
}

