#include<bits/stdc++.h>
using namespace std;
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;

        int i=0,j=0;

        while(i<pushed.size() && j<pushed.size()){
            st.push(pushed[i]);

            while((!st.empty()) && popped[j]==st.top() && j<popped.size()){
                st.pop();
                j++;
            }
            i++;
        }
        
        if(st.empty()){
            return true;
        }     
        return false;
}

int main(){
    vector<int>pushed = {1,2,3,4,5};
    vector<int>popped = {4,5,3,2,1};
    cout<<validateStackSequences(pushed,popped)<<endl;

    return 0;
}