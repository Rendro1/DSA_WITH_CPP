#include<bits/stdc++.h>
using namespace std;

static int t[1001][1001];

int solve(int arr[],int i,int j){
    if(i>=j){
        return 0;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    int mini = INT_MAX;
    for(int k=i;k<j;k++){
        int temp_ans = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        if(temp_ans<mini){
            mini = temp_ans;
        }
    }
    return t[i][j] = mini; 
}
int main(){
    memset(t,-1,sizeof(t));
    int arr[] ={ 1, 2, 3, 4, 3 };
    int n = sizeof(arr)/sizeof(int);
    cout<<solve(arr,1,n-1)<<endl;
    return 0;
}