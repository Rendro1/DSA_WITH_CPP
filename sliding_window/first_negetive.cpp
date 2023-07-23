#include<bits/stdc++.h>
using namespace std;

void res(vector<int>&v,int k){
    if(v.size()<k){
        cout<<"INVALID";
    }
    int i=0,j=0;
    list<int>l;
    vector<int>vi;
    while(j<v.size()){
        if(v[j]<0){
            l.push_back(v[j]);
        }
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            if(l.size()==0){
                vi.push_back(0);
            }
            else{
                vi.push_back(l.front());
                if(v[i]==l.front()){
                    l.pop_front();
                }
                i++;
                j++;
            }
        }
    }
    for(int i=0;i<vi.size();i++){
        cout<<vi[i]<<" ";
    }
}

int main(){
    vector<int>v ={7,9,-5,6,8,-11,13,-14};
    int k = 3;
    res(v,k);
    return 0;
}