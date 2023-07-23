// normal common prefix .There will be a array of strings we have to output which characters are common in each string from the left of the string.

// if it would say suffix then we have to traverse from last to first

#include<bits/stdc++.h>
using namespace std;

string LCP(vector<string>&v,int n){
    string ans="";
    for(int i=0;i<v[0].size();i++){

        char ch = v[0][i];

        bool match = true;

        for(int j=1;j<n;j++){
            if(v[j].size()<i || ch !=v[j][i]){
                match = false;
                break;
            }
        }
        if(match==false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;
}

int main(){
    vector<string>s = {"coding","codezen","codingninja","coder"};
    int n = s.size();
    cout<<"The maximum continues common character of the all string is->"<<LCP(s,n)<<endl;

    return 0;
}

// TC = O(N*M);
// SC = O(M); // size of ans string.