// Binary search in unsorted array
#include <bits/stdc++.h>
using namespace std;

int res(vector<int> arr)
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

int main()
{
    // vector<int> arr = {5, 10, 20, 15};
    // vector<int> arr = {5, 12, 26, 19, 17};
    vector<int> arr = {14, 14, 10, 4, 13, 8, 17};
    cout<<res(arr);
    return 0;
}
   
