#include<bits/stdc++.h>
using namespace std;


int uniqueChar(string s){
    unordered_map<char,int>mp;
    int i=0,j=0,mx=0;
    while(j<s.size()){
        mp[s[j]]++;
        if(mp.size()==j-i+1){
            mx = max(mx,j-i+1);
            j++;
        }
        else if(mp.size()<j-i+1){
            while(mp.size()<j-i+1){
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
    string str="pwwkew";
    cout<<uniqueChar(str)<<endl;
    return 0;
}