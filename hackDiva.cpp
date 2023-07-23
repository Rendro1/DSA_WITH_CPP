// #include<bits/stdc++.h>
// using namespace std;

// int solve(vector<int>arr,int n,int k){
//     set<int>s;
//     for(int i=0;i<n;i++){
//         s.insert(arr[i]);
//     }
//     vector<int>v;
//     for(auto it=s.begin();it != s.end();it++){
//         v.push_back(*it); // 2 3 4 6 9 10
//     }
//     int ans =0;
//     int mini = INT_MAX;
//     for(int i=0;i<v.size();i++){
//         for(int j=0;j<arr.size();j++){
//             if(arr[j]<=v[i]){
//                 ans += v[i]/arr[j]; //{6,6,4,3,4,9,3,2,6,10} v = {2,3,4,6,9,10}
//             }
//             if(ans>=k){
//                 mini = min(mini,v[i]);
//             }
//         }
//         ans = 0;
//     }
//     return mini;

// }

// int main(){
//     vector<int>arr = {6,6,4,3,4,9,3,2,6,10};
//     int n =10;
//     int k=10;
//     cout<<solve(arr,n,k); // ans will be 6
//     return 0;
// }

// optimal solution-> O(n log n)->

#include<bits/stdc++.h>
using namespace std;
#define lli long long int

bool result(int v[],int n,int k,int lim){
    lli count=0;
    for(int i=0;i<n;i++){
        if(lim>=v[i]){
            count += lim/v[i];
        }
    }
    if(count>=k){
        return true;
    }
    return false;
}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int low = 0;
    int high = n-1;
    int ans = -1;
    int mid;

    while(low<=high){
        mid = low + (high-low)/2;

        if(result(arr,n,k,mid)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    cout<<ans<<endl;


    return 0;
}

