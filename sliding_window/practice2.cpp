#include<bits/stdc++.h>
using namespace std;

vector<int>res(vector<int>v,int k){
    float sum=0;
    int i=0;
    int j=0;
    int f_ind,l_ind;
    float ans = FLT_MAX_EXP; // Maximum float value 
    while(j<v.size()){
        sum += v[j]; // calculating sum until the window size matched
        if(j-i+1<k){
            j++; // moving pointer which adding the number to the sum untill window size matched
        }
        else if(j-i+1==k){

            if(sum/k < ans){
                ans = sum/k;
                f_ind = i;
                l_ind = j; //variables to catch current i and j value
            }
            sum = sum - v[i]; // moving window size by 1;
            i++;
            j++;
        }
    }
    vector<int>a; // vector to push first and last index of max avg window
    a.push_back(f_ind);
    a.push_back(l_ind);
    return a;
}

int main(){
    vector<int>v = {30,11,43,32,8,15};
    // vector<int>v = {90,20};
    int k = v.size();
    vector<int>result = res(v,k);
    for(auto i:result){
        cout<<i<<" ";
    }
    return 0;
}