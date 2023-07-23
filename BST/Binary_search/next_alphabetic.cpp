#include<bits/stdc++.h>
using namespace std;

char Result(string str,char l){
    int start=0,end= str.size();
    char res= '#';
    while(start<=end){
        int mid = start + (end-start)/2;
        if(str[mid]==l){
            start = mid+1;
        }
        else if(str[mid]<l){
            start = mid+1;
        }
        else{
            res = str[mid];
            end = mid-1;
        }
    }
    return res;
}

int main(){
    string str = "acfh";
    char s = 'f';
    cout<<Result(str,s);
    return 0;
}