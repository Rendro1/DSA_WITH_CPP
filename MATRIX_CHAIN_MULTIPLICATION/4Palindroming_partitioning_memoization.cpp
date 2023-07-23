// #include<bits/stdc++.h>
// using namespace std;

// static int t[1001][1001];

// bool ispalindrome(string s){
//     string temp = s;
//     reverse(s.begin(),s.end());
//     if(temp == s){
//         return true;
//     }
//     return false;
// }

// int solve(string s,int i,int j){
//     if(i>=j){
//         return 0;
//     }
//     if(ispalindrome(s)){
//         return 0;
//     }
//     if(t[i][j]!=-1){
//         return t[i][j];
//     }
//     int ans = INT_MAX;
//     for(int k=i;k<j;k++){
//         int temp_ans = 1+solve(s,i,k) + solve(s,k+1,j);

//         ans = min(ans,temp_ans);
//     }
//     return t[i][j]=ans;

// }

// int main(){
//     memset(t,-1,sizeof(t));
//     string s = "arka";
//     int i = 0;
//     int j = s.size();
//     cout<<"minimum no of partition required is->"<<solve(s,i,j);
//     return 0;
// }

// More optimize solution->

#include <bits/stdc++.h>
using namespace std;

static int t[1001][1001];

bool ispalindrome(string s)
{
    string temp = s;
    reverse(s.begin(), s.end());
    if (temp == s)
    {
        return true;
    }
    return false;
}

int solve(string s, int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    if (ispalindrome(s))
    {
        return 0;
    }
    if (t[i][j] != -1)
    {
        return t[i][j];
    }
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int left, right;
        if (t[i][k] != -1)
        {
            left = t[i][k];
        }
        else
        {
            left = solve(s, i, k);
        }
        if (t[k + 1][j] != -1)
        {
            right = t[k + 1][j];
        }
        else
        {
            right = solve(s, k + 1, j);
        }
        int temp_ans = 1 + left + right;

        ans = min(ans, temp_ans);
    }
    return t[i][j] = ans;
}

int main()
{
    memset(t, -1, sizeof(t));
    string s = "arka";
    int i = 0;
    int j = s.size();
    cout << "minimum no of partition required is->" << solve(s, i, j);
    return 0;
}