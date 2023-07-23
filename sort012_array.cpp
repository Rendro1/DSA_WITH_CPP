#include<bits/stdc++.h>
using namespace std;

void sort012(vector<int>v){
    int low = 0;
    int mid = 0;
    int high = v.size()-1;

    while(mid<=high){
        if(v[mid]==0){
            swap(v[low],v[mid]);
            low++;
            mid++;
        }
        else if(v[mid]==1){
            mid++;
        }
        if(v[mid]==2){
            swap(v[mid],v[high]);
            high--;
        }
    }

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

int main(){
    vector<int>arr = {0,1,1,1,1,0,0,0,2,2,2,1,0};
    sort012(arr);
    return 0;
}