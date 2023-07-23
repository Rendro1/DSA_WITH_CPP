// // subset sum
// #include<bits/stdc++.h>
// using namespace std;

// int tab[2000][2000];

// int subsetSum(int a[],int n,int sum){
//     if(sum==0){
//         return 1;
//     }
//     if(n==0 && sum != 0){
//         return 0;
//     }
    
//     if(tab[n-1][sum]!=-1){
//         return tab[n-1][sum];
//     }
//     if(tab[n-1][sum]>sum){
//         return tab[n-1][sum] = subsetSum(a,n-1,sum);
//     }
//     else{
//         return tab[n-1][sum] = (subsetSum(a,n-1,sum) || subsetSum(a,n-1,sum-a[n-1]));
//     }
// }

// int main()
// {
// 	// Storing the value -1 to the matrix
// 	memset(tab, -1, sizeof(tab));
// 	int n = 5;
// 	int a[] = {1, 5, 3, 7, 4};
// 	int sum = 34;

// 	if (subsetSum(a, n, sum))
// 	{
// 		cout << "YES" << endl;
// 	}
// 	else
// 		cout << "NO" << endl;

// }


// equal sum partition->

// // subset sum
// #include<bits/stdc++.h>
// using namespace std;

// int tab[2000][2000];

// int subsetSum(int a[],int n,int sum){
//     if(sum==0){
//         return 1;
//     }
//     if(n==0 && sum != 0){
//         return 0;
//     }
    
//     if(tab[n-1][sum]!=-1){
//         return tab[n-1][sum];
//     }
//     if(tab[n-1][sum]>sum){
//         return tab[n-1][sum] = subsetSum(a,n-1,sum);
//     }
//     else{
//         return tab[n-1][sum] = (subsetSum(a,n-1,sum) || subsetSum(a,n-1,sum-a[n-1]));
//     }
// }

// int equalSum(int a[],int n){
//     int sum =0;
//     for(int i=0;i<n;i++){
//         sum +=a[i];
//     }
//     if(sum % 2 !=0){
//         return 0;
//     }
//     return subsetSum(a,n,sum/2);
// }

// int main()
// {
// 	// Storing the value -1 to the matrix
// 	memset(tab, -1, sizeof(tab));
// 	int n = 5;
// 	int arr[] = {3, 1, 5, 9, 12};

// 	if (equalSum(arr, n))
// 	{
// 		cout << "YES" << endl;
// 	}
// 	else
// 		cout << "NO" << endl;

// }


#include<bits/stdc++.h>
using namespace std;

int totalWays(vector<int>nums,int sum){
    int n = nums.size();
    int t[n+1][sum+1];
    for(int i=1;i<sum+1;i++){
        t[0][i] =0;
    }
    for(int i=0;i<n+1;i++){
        t[i][0] =1;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(nums[i-1]<=j){
                t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main(){
    vector<int>nums = {2, 3, 5, 6, 8, 10};
    int x = 10;

    cout << totalWays(nums,x);

    return 0;
}