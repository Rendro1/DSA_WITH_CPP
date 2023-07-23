#include<bits/stdc++.h>
using namespace std;

int res(vector<int>arr,int size,int ele){
    int start=0;
    int end=arr.size()-1;
    while(start<=end){
        int mid=start + (end-start)/2;
        
        if(arr[mid]==ele){
            return mid;
        }
        else if(arr[mid]<ele){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}

int main(){
   vector<int>arr = {20,18,15,13,12,10,8,7,5,3,1};
   int s = arr.size();
   cout<<res(arr,s,10);
    return 0;
}
