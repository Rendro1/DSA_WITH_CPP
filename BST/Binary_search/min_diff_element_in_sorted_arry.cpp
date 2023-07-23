#include<bits/stdc++.h>
using namespace std;

int res(vector<int>arr,int ele){
    int l=0,h=arr.size()-1;
    while(l<=h){
        int mid = l + (h-l)/2;
        if(arr[mid]==ele){
            return arr[mid];
        }
        else if(arr[mid]<ele){
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    int one_value = abs(ele-arr[h]);
    int second_value = abs(ele-arr[l]);
    if(one_value<second_value){
        return arr[h];
    }
    else{
        return arr[l];
    }
    return -1;
}

int main(){
    vector<int>arr = {1,4,6,8,10,15};
    cout<<res(arr,12)<<endl;
    return 0;
}