#include<bits/stdc++.h>
using namespace std;

int ans(vector<int>&arr,int target){
    int low =0;
    int high = arr.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(mid-1>=low && arr[mid-1]==target){
            return mid-1;
        }
        else if(mid+1<=high && arr[mid+1]==target){
            return mid+1;
        }
        else if(arr[mid]<target){
            high = mid-2;
        }
        else{
            low = mid+2;
        }
    }
    return -1;
}
int main(){
    vector<int>arr = {5,10,30,20,40};
    cout<<ans(arr,20);
    return 0;
}