#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string s){
    string temp = s;
    reverse(s.begin(),s.end());
    if(temp == s){
        return true;
    }
    return false;
}

int solve(string s,int i,int j){
    if(i>=j){
        return 0;
    }
    if(ispalindrome(s)){
        return 0;
    }
    int ans = INT_MAX;
    for(int k=i;k<j;k++){
        int temp_ans = 1+solve(s,i,k) + solve(s,k+1,j);
        
        ans = min(ans,temp_ans);
    }
    return ans;

}

int main(){
    string s = "arka";
    int i = 0;
    int j = s.size();
    cout<<"minimum no of partition required is->"<<solve(s,i,j);
    return 0;
}