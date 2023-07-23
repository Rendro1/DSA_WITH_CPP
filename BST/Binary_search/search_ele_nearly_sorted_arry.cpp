#include<bits/stdc++.h>
using namespace std;

int result(vector<int>arr,int ele){
    int start=0;
    int end = arr.size()-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==ele){
            return mid;
        }
        else if(mid-1>=start && arr[mid-1]==ele){
            return mid-1;
        }
        else if(mid+1<=end && arr[mid+1]==ele){
            return mid+1;
        }
        else if(arr[mid]>ele){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}

int main(){
    vector<int>arr ={10, 3, 40,30, 20, 50, 80, 70};
    int key = 10;
    cout<<result(arr,key);
    return 0;
}