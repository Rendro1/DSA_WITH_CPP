// Next greater number ->
// example input-> 123
// output -> 132

#include <bits/stdc++.h>
using namespace std;

// vector<int> nextGreater(vector<int>arr){
//     next_permutation(arr.begin(),arr.end()); // stl function that directly give the next permutation with the help of next_permutation function
//     return arr;
// }
vector<int> nextGreater(vector<int> &arr)
{
    int ind = -1;
    int n = arr.size();
    // {2,1,5,4,3,4,0,0}
    for (int i = n - 2; i >= 0; i--) 
    {
        if (arr[i] < arr[i + 1])
        {
            ind = i; //4
            break;
        }
    }
    if(ind==-1){
        reverse(arr.begin(),arr.end());
        return arr;
    } // 5 4 3 2 1 0 0

    // {2,1,5,4,3,4,0,0} -> 2 1 5 4 4 3 0 0-> 2 1 5 4 4 0 0 3
    for(int i=n-1;i>=0;i--){
        if(arr[i]>arr[ind]){ 
            swap(arr[i],arr[ind]);
            break;
        }
    }
    reverse(arr.begin()+ind+1,arr.end());
    return arr;
}
// 2,1,5,4,4,0,0,3-> ind = 4

int main()
{
    vector<int> arr = {2,1,5,4,3,4,0,0};
    vector<int> res = nextGreater(arr);
    for (auto i : res)
    {
        cout << i;
    }

    return 0;
}

// 2,1,| 5,4,3,0,0-> 2 3 0 0 1 4 5
/*
// explaination of approach->

// 2,1,5,4,3,0,0
// so the arr is in increasing order from right but the arr suddenly decreasing in the index 1 where the element is 1 so the break point is between 1 and 5

step-1->// now the array is 2,1 | 5,4,3,0,0 the first loop detecting the break point where is arr[i]<arr[i+1] and storing the break point index into ind variable

step-2-> after that we are checking that the array is in increasing order from the right side or not(if increasing then the ind value will be stay -1 till end) if the full array is in increasing order then the number is in highest permutation so we have to return the first permutation in this case example if the arr is->
3 2 1 then the next permutation is 1 2 3the lowest number so that is happening with the reverse function

step-3->checking the break point index value is just less than which value from the right elements 2,1 | 5,4,3,0,0 Here 1 is just less than 3 so in this step we are swaping 1 and 3 accordingly so now the arr is like 2 3 5 4 1 0 0 ....but it's not a next permutation till now so after that we are reversing the full array from the breaking index to end of the array so after reverse the arr will be 2 3 0 0 1 4 5(that's the original next permutation)


*/