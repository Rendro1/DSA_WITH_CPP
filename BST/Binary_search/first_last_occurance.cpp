#include<bits/stdc++.h>
using namespace std;

int first_occ(vector<int>arr,int ele){
    int start=0;
    int end=arr.size()-1;
    int res=-1;
    while(start<=end){
        int mid=start + (end-start)/2;
        
        if(arr[mid]==ele){
            res = mid;
            end = mid-1;
        }
        else if(arr[mid]<ele){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return res;
}
int last_occ(vector<int>arr,int ele){
    int start=0;
    int end=arr.size()-1;
    int res=-1;
    while(start<=end){
        int mid=start + (end-start)/2;
        
        if(arr[mid]==ele){
            res = mid;
            start = mid+1;
        }
        else if(arr[mid]<ele){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return res;
}

int main(){
   vector<int>arr = {4,5,6,7,8,8,8,8,9,10};
   cout<<first_occ(arr,8)<<endl;
   cout<<"LAST OCCR->"<<last_occ(arr,8)<<endl;
   cout<<"no of occ->"<<(last_occ(arr,8)-first_occ(arr,8)+1);
    return 0;
}
