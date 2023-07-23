//Largest histogram of a rectangle:->

#include<bits/stdc++.h>
using namespace std;

vector<int>nextSmallerElement(vector<int>arr,int n){
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    // {2,1,5,6,2,3};->for better understanding please dry run it.
    for(int i=n-1;i>=0;i--){
        int curr =arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int>previousSmallerElement(vector<int>arr,int n){
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    // {2,1,5,6,2,3};->for better understanding please dry run it.
    for(int i=0;i<n;i++){
        int curr =arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int>&heights){
    int n = heights.size();
    vector<int>next(n);
    next = nextSmallerElement(heights,n);
    vector<int>previous(n);
    previous = previousSmallerElement(heights,n);
    int area = INT_MIN; 
    for(int i=0;i<n;i++){
        int l = heights[i];
        if(next[i]==-1){    
            next[i] = n;
        }
        int b = next[i]-previous[i]-1;
        int newArea = l*b;
        area = max(area,newArea); 
    }
    return area;
}

int main(){
    vector<int>v = {2,1,5,6,2,3};
    cout<<"Maximum area is->"<<largestRectangleArea(v);
    return 0;
}