#include<bits/stdc++.h>
using namespace std;

int result(vector<int>&arr,int target){
    int low = 0;
    int high = 1;
    while(arr[high]<target){
        low = high;
        high = high*2;
    }
    // cout<<low<<" "<<high<<endl;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}
int main(){
    vector<int>arr = {1,2,3,4,5,6,7,8,9,10,11};
    cout<<result(arr,7)<<endl;
    return 0;
}
