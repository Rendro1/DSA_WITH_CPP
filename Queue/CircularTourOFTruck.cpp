#include<bits/stdc++.h>
using namespace std;

int ans(int *p,int *d,int n){
    int deficiate =0;
    int balance = 0;
    int start = 0;

    for(int i=0;i<n;i++){
        balance += p[i] - d[i];
        if(balance<0){
            deficiate +=balance;
            start = i+1;
            balance =0;
        }
    }
    if(deficiate+balance >=0){
        return start;
    }
    else{
        return -1;
    }
}
int main(){
    int n=4;
    int petrol[] = {4,6,7,4};
    int distance[] = {6,5,3,5};
    cout<<"If we start from indx-"<<ans(petrol,distance,n)<<" then we can tour all the pumps and distance"<<endl;
    return 0;
}