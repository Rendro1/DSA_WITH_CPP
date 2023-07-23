// // frog-1-problem->stone ache jekhane hoi akta or duto stone jump korte parbe so protita stone jump korte cost lage kichu to minimum cost koto lagbe
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e5+10;
// int h[N];
// int dp[N];

// int func(int i){

//     if(i==0) return 0;
//     if(dp[i]!=-1) return dp[i];
//     int cost = INT_MAX;
//     // way->1
//     cost = min(cost,func(i-1)+abs(h[i]-h[i-1]));
//     // / way->2
//     if(i>1){
//         cost = min(cost,func(i-2)+abs(h[i]-h[i-2]));
//     }
//     return dp[i]=cost;
// }

// int main(){
//     memset(dp,-1,sizeof(dp));
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>h[i];
//     }
//     cout<<func(n-1);
//     return 0;
// }

// input->
// 4
// 10 30 40 20

// output-> 30
          
// frog-1-problem->stone ache jekhane hoi k(no of stone) stone jump korte parbe so protita stone jum korte cost lage kichu to minimum cost koto lagbe
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int h[N];
int k;
int dp[N];

int func(int i){

    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];
    int cost = INT_MAX;
    // way->1
    for(int j=1;j<=k;j++){
        if(i-j>=0){
            cost = min(cost,func(i-j)+abs(h[i]-h[i-j]));
        }
    }  
    return dp[i]=cost;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    cout<<func(n-1);
    return 0;
}

// input->
// 3 1
// 10 20 10

// output-> 20
