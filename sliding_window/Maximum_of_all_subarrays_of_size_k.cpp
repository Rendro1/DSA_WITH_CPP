#include<bits/stdc++.h>
using namespace std;

vector<int>ans(vector<int>&arr,int k){
    list<int>l;
    vector<int>v;
    int i=0;
    int j=0;
    if(arr.size()<k){
        return 1;
    }
    while(j<arr.size()){
        while(l.size()>0 && arr[j]>l.back()){
            l.pop_back();
        }
        l.push_back(arr[j]);
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            v.push_back(l.front());    
            if(l.front()==arr[i]){
                l.pop_front();
            }            
            i++;
            j++;
        }
    }
    return v;
}

int main(){
    vector<int>v={1, 4, 2, 10, 2, 3, 1, 0, 20};
    vector<int>s = ans(v,3);
    for(int i=0;i<s.size();i++){
        cout<<s[i]<<" ";
    }
    return 0;
}