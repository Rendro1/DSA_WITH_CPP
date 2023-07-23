// #include <bits/stdc++.h>
// using namespace std;

// int res(vector<int> v, int k)
// {
//     unordered_set<int> s;
//     vector<int>arr;
//     for(int i=0;i<v.size();i++){
//       s.insert(v[i]);
//     }
//     for(auto it=s.begin();it!=s.end();it++){
//       arr.push_back(*it);
//     }
//     // for(int i=0;i<arr.size();i++){
//     //   cout<<arr[i]<<" ";
//     // }
//     int i=0,j=0,sum=0;
//     int maxi = INT_MIN;
//     while(j<arr.size()){
//       sum +=arr[j];
//       if(j-i+1<k){
//         j++;
//       }
//       else if(j-i+1==k){
//          maxi = max(sum,maxi);
//          sum = sum-arr[i];
//          i++,j++;
//       }
//     }
//     return maxi;

// }

// int main()
// {
//   vector<int>arr = {1,2,7,7,4,3,6};
//   int k=3;
//   cout<<res(arr,k);
//   return 0;
// }

#include<bits/stdc++.h>
using namespace std;

void ans(int *arr,int *mf,int *mt){
  vector<int>v(10);
  for(int i=0;i<v.size();i++){
    v[i] = 0;
  }
  for(int i=0;i<4;i++){
     v[arr[i]] = 1;
  }
  for(int i=0;i<3;i++){
    if(v[mf[i]]==1){
      v[mt[i]]=1;
      v[mf[i]] =0;
    }
  }
  for(int i=0;i<v.size();i++){
    if(v[i]==1){
      cout<<i<<" ";
    }
  }

}

int main(){
  int arr[] = {1,7,6,8};
  int mf[] = {1,7,2};
  int mt[] = {2,9,5};
  cout<<"So the data of amazon is present on these memory->";
  ans(arr,mf,mt);
  return 0;
}





// #include<bits/stdc++.h>
// using namespace std;

// int val=0;
// bool flagg(vector<int>v,int k){
//   bool flag=0;
//   for(int i=0;i<k;i++){
//     if(v[i] !=v[i+1]){
//       flag = 1;
//     }
//     else{
//       val = v[i];
//       flag=0;
//     }
//   }
//   if(flag){
//     return true;
//   }
//   return false;
// }

// int ans(vector<int>v,int k){
//   int i=0,j=0;
//   int sum =0;
//   int maxi = INT_MIN;
//   vector<int>vi;
//   while(j<v.size()){
//     for(int i=0;i<k;i++){
//       vi.push_back(v[i]);
//     }
//     if(flagg(vi,k)){
//       sum +=v[j];
//     }

//     if(j-i+1<k){
//       j++;
//     }
//     if(j-i+1==k){
//         maxi = max(maxi,sum);
//         sum = sum - v[i];
//         i++,j++;
//       }
     
     
//     }
//   return maxi;
// }


// int main(){
//   vector<int>arr = {1,2,7,7,4,3,6};
//   int k=3;
//   cout<<ans(arr,k);
//   return 0;
// }