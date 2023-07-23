//First non repeating charcter in a string:->
#include<bits/stdc++.h>
using namespace std;

string no_repeating(string str){
    unordered_map<char,int>count;
    queue<int>q;
    string ans=" ";
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        //increase the count of character
        count[ch]++;
        //push to queue:->
        q.push(ch);

        while(!q.empty()){
            if(count[q.front()]>1){
                // repeating character
                q.pop();
            }
            else{
                // non repeating character
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

int main(){
    string str = "AABC";
    cout<<no_repeating(str);
    return 0;
}