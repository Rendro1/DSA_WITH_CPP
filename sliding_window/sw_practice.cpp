// #include<bits/stdc++.h>
// using namespace std;

// int res(vector<int>v,int s){
//     int i=0,j=0;
//     int mx = INT_MIN;
//     int sum =0;
//     if(v.size()<s){
//         return 0;
//     }
//     while(j<v.size()){
//         sum += v[j];
//         if(j-i+1<s){
//             j++;
//         }
//         else if(j-i+1==s){
//             mx = max(sum,mx);
//             sum = sum - v[i];
//             i++;
//             j++;
//         }
//     }
//     return mx;
// }

// int main(){
//     vector<int>v={1, 4, 2, 10, 2, 3, 1, 0, 20};
//     cout<<res(v,4);
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// void res(vector<int>v,int s){
//     if(v.size()<s){
//         cout<<"Not Possible";
//     }
//     int i=0,j=0;
//     list<int>l;
//     vector<int>vi;
//     while(j<v.size()){
//         if(v[j]<0){
//             l.push_back(v[j]);
//         }
//         if(j-i+1<s){
//             j++;
//         }
//         else if(j-i+1==s){
//             if(l.size()==0){
//                 vi.push_back(0);
//             }
//             else{
//                 vi.push_back(l.front());
//                 if(v[i]==l.front()){
//                     l.pop_front();
//                 }
//                 i++;j++;
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
//     res(v,k);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// bool isAna(string s1, string s2)
// {
//     map<char, int> mp;
//     for (int i = 0; i < s1.length(); i++)
//     {
//         mp[s1[i]]++;
//     }
//     for (int i = 0; i < s2.length(); i++)
//     {
//         mp[s2[i]]--;
//     }
//     for (auto it = mp.begin(); it != mp.end(); it++)
//     {
//         if (it->second != 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int countAnagrams(string s, string w)
// {
//     int res = 0;
//     for (int i = 0; i < s.size() - w.size() + 1; i++)
//     {
//         if (isAna(s.substr(i, w.length()), w))
//         {
//             res++;
//         }
//     }
//     return res;
// }

// int main()
// {
//     string text = "forxxorfxdofr";
//     string word = "for";
//     // for (int i = 0; i < text.size() - word.size() + 1; i++){
//     //     cout<<text.substr(i, word.length())<<endl;
//     // }
//     cout << countAnagrams(text, word);
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;

// bool Ana(string str,string st){
//     map<char,int>mp;
//     for(int i=0;i<str.size();i++){
//         mp[str[i]]++;
//     }
//     for(int i=0;i<st.size();i++){
//         mp[st[i]]--;
//     }
//     for(auto it=mp.begin();it!=mp.end();it++){
//         if(it->second !=0){
//             return false;
//         }
//     }
//     return true;
// }

// int count(string text,string word){
//     int res =0;
//     for(int i=0;i<text.size()-word.size()+1;i++){
//         if(Ana(text.substr(i,word.size()),word)){
//             res++;
//         }
//     }
//     return res;
// }

// int main(){
//      string text = "forxxorfxdofr";
//     string word = "for";
//     cout << count(text, word);
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// vector<int>res(vector<int>&arr,int k){
//     int i=0,j=0;
//     vector<int>v;
//     list<int>l;
//     while(j<arr.size()){
//         while(l.size()>0 && arr[j]>l.back()){
//             l.pop_back();
//         }
//         l.push_back(arr[j]);
//         if(j-i+1<k){
//             j++;
//         }
//         else if(j-i+1==k){
//             v.push_back(l.front());
//             if(l.front()==arr[i]){
//                 l.pop_front();
//             }
//             i++;
//             j++;
//         }
//     }
//     return v;
// }

// int main(){
//     vector<int>v={1, 4, 2, 10, 2, 3, 1, 0, 20};
//     vector<int>s = res(v,3);
//     for(int i=0;i<s.size();i++){
//         cout<<s[i]<<" ";
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int res(vector<int>v,int k){
    int i=0;
    int j=0;
    int s=0;
    int mx = INT_MIN;
    int sum=0;
    while(j<v.size()){
        sum +=v[j];
        if(sum<k){
            j++;
        }
        if(sum==k){
            s = j-i+1;
            mx = max(s,mx);
            j++;
        }
        else if(sum>k){
            sum = sum - v[i];
            j++;i++;
        }
    }
    return mx;
}
int main(){
    vector<int>arr = {4,1,1,1,2,3,5};
    int k=5;
    cout<<res(arr,k);
    return 0;
}