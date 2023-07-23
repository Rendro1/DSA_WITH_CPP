// same as longest substring with k unique characters.
#include<bits/stdc++.h>
using namespace std;

int Max_toys(string s,int type){
    int i=0,j=0;
    int mx=INT_MIN;
    unordered_map<char,int>mp;
    while(j<s.size()){
        mp[s[j]]++;
        if(mp.size()<type){
            j++;
        }
        else if(mp.size()==type){
            mx = max(mx,j-i+1);
            j++;
        }
        else if(mp.size()>type){
            while(mp.size()>type){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return mx;
}

int main(){
    string str="abaccab";
    int type=2;
    cout<<Max_toys(str,type);
    return 0;
}