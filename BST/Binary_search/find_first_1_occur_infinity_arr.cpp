#include<bits/stdc++.h>
using namespace std;

int firstOcc(vector<int>&arr,int low,int high,int target){
    int ans =-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==target){
            ans = mid;
            high = mid-1;
        }
        else if(arr[mid]<target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
int findElementRange(vector<int>&arr,int target){
    int low = 0;
    int high = 1;
    while(arr[high]<target){
        low = high;
        high = high*2;
    }
    return firstOcc(arr,low,high,target);
    
}

int main(){
    vector<int>arr = {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1};
    cout<<findElementRange(arr,1)<<endl;
    return 0;
}