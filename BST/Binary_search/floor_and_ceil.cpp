#include<bits/stdc++.h>
using namespace std;

int Floor(vector<int>arr,int ele){
    int start=0;
    int end = arr.size()-1;
    int res=-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==ele){
            return arr[mid];
        }
        else if(arr[mid]<ele){
            res = arr[mid];
            start = mid+1;
        } 
        else{
            end = mid-1;
        }
    }
    return res;
}
int Ceil(vector<int>arr,int ele){
    int start=0;
    int end = arr.size()-1;
    int res=-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==ele){
            return arr[mid];
        }
        else if(arr[mid]<ele){
            start = mid+1;
        }
        else{
            res = arr[mid];
            end = mid-1;
        }
    }
    return res;
}

int main(){
    vector<int>arr ={1, 2, 4, 8, 10, 10, 12, 19};
    int key = 5;
    cout<<Floor(arr,key)<<endl;
    cout<<Ceil(arr,key)<<endl;
    return 0;
}