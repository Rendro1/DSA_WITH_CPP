#include<bits/stdc++.h>
using namespace std;


int solve(int arr[],int i,int j){
    if(i>=j){
        return 0;
    }
 
    int mini = INT_MAX;
    for(int k=i;k<j;k++){
        int temp_ans = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        if(temp_ans<mini){
            mini = temp_ans;
        }
    }
    return  mini; 
}
int main(){
    int arr[] ={ 1, 2, 3, 4, 3 };
    int n = sizeof(arr)/sizeof(int);
    cout<<solve(arr,1,n-1)<<endl;
    return 0;
}