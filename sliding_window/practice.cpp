// #include<bits/stdc++.h>
// using namespace std;

// void result(vector<int>&v,int k){
//     int i=0;
//     int j=0;
//     list<int>l;
//     vector<int>vi;
//     while(j<v.size()){
//         if(v[j]<k){
//             l.push_back(v[j]);
//         }
//         if(j-i+1<k){
//             j++;
//         }
//         else if(j-i+1==k){
//             if(l.size()==0){
//                 vi.push_back(0);
//             }
//             else{
//                 vi.push_back(l.front());
//                 if(v[i]==l.front()){
//                     l.pop_front();
//                 }
//                 i++;
//                 j++;
//             }
//         }
//     }
//     for(int i=0;i<vi.size();i++){
//         cout<<vi[i]<<" ";
//     }
// }
// int main(){
//     vector<int>v ={7,9,-5,6,8,-11,13,-14};
//     int k =3;
//     result(v,k);
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int result(vector<int>&v,int k){
//     int i=0,j=0;
//     int sum =0;
//     int mx = INT_MIN;
//     while(j<v.size()){
//         sum += v[j];
//         if(j-i+1<k){
//             j++;
//         }
//         else if(j-i+1==k){
//             mx = max(mx,sum);
//             sum = sum - v[i];
//             i++;
//             j++;

//         }
//     }
//     return mx;
// }

// int main(){
//     vector<int>v={1, 4, 2, 10, 2, 3, 1, 0, 20};
//     cout<<result(v,4);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int substring(string s,int k){
    int i=0,j=0;
    int mx=INT_MIN;
    unordered_map<char,int>mp;
    while(j<s.size()){
        mp[s[j]]++;
        if(mp.size()<k){
            j++;
        }
        else if(mp.size()==k){
            mx = max(mx,j-i+1);
            j++;
        }
        else if(mp.size()>k){
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return mx;
}
int main(){
    string str = "aabacbebebe";
    int k=3;
    // cout<<str;
    cout<<substring(str,k);
    return 0;
}