// Binary search in unsorted array
#include <bits/stdc++.h>
using namespace std;

int peak(vector<int> arr)
{
    int l = 0;
    int h = arr.size() - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (mid > 0 && mid < arr.size()-1)
        {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else if (arr[mid - 1] > arr[mid])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else if(mid==0){
            if(arr[mid]>arr[mid+1]){
                return mid;
            }
            else{   
                return mid+1;
            }
        }
        else if(mid==arr.size()-1){
            if(arr[mid]>arr[mid-1]){
                return mid;
            }
            else{
                return mid-1;
            }
        }
    }
    return -1;
}

int accend(vector<int>arr,int l,int h,int ele){
    while(l<=h){
        int mid = l +(h-l)/2;
        if(arr[mid]==ele){
            return mid;
        }
        else if(arr[mid]<ele){
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    return -1;
}
int decend(vector<int>arr,int l,int h,int ele){
    while(l<=h){
        int mid = l +(h-l)/2;
        if(arr[mid]==ele){
            return mid;
        }
        else if(arr[mid]<ele){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {-3, 9, 8, 20, 17, 5, 1};
    int key = 20;
    int p = peak(arr);
    int ans1 = accend(arr,0,p-1,key);
    int ans2 = decend(arr,p,arr.size()-1,key);
    cout<<ans1<<" "<<ans2<<endl;
    if(ans1==-1){
        cout<<ans2;
    }
    else{
        cout<<ans1;
    }
    return 0;
}