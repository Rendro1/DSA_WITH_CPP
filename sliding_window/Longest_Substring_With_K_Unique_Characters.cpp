#include<bits/stdc++.h>
using namespace std;

int substring(string s,int k){

    if(s.size()<k){
        return -1;
    }
    int i=0;
    int j=0;
    int mx=INT_MIN;
    unordered_map<char,int>mp;
    // mp.clear();
    while(j<s.size()){
        mp[s[j]]++;
        if(mp.size()<k){
            j++;
        }
        else if(mp.size()==k){
            mx = max(mx,j-i+1);
            j++;
        }
        else if(mp.size()>k){
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    if(mx == INT_MIN){
        return -1;
    }
    return mx;
}
int main(){
    string str = "aabacbebebe";
    int k=3;
    // cout<<str;
    cout<<substring(str,k);
    return 0;
}