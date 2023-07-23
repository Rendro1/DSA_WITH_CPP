// #include<bits/stdc++.h>
// using namespace std;

// void res(vector<int>arr){
//     int i=0;
//     while(i<arr.size()){
//         if(arr[i] != arr[arr[i]-1]){
//             swap(arr[i],arr[arr[i]-1]);
//         }
//         else{
//             i++;
//         }
//     }
//     for(int i=0;i<arr.size();i++){
//         if(arr[i] != i+1){
//             cout<<"Missing no ->"<<i+1<<endl;
//             cout<<"duplicate no->"<<arr[i]<<endl;
//         }
//     }
// }
// int main(){
//     vector<int>arr ={2,3,1,5,1};
//     res(arr);
//     return 0;
// }


// //Missing number O(n^2) solution-> STRIVER'S LECTURE

// #include<bits/stdc++.h>
// using namespace std;

// int missingNum(vector<int>&v){
//     int n = v.size();
//     for(int i=1;i<=n;i++){
//         bool flag=0;
//         for(int j=0;j<n-1;j++){
//             if(v[j]==i){
//                 flag=1;
//                 break;
//             }
//         }
//         if(flag==0){
//             return i;
//         }
//     }
//     return -1;
// }

// int main(){
//     vector<int>v = {1,2,4,5};
//     cout<<"Missing number is->"<<missingNum(v);
//     return 0;
// }


//Missing number O(n log n)1st optimal solution->

// #include<bits/stdc++.h>
// using namespace std;

// // Basically declearing an array hash which is initially 0 and then i am looking at the given array which element is present and changing that index to 1 to that index and finally checking that which reamins 0 that is my element which is missing.
// int missingNum(vector<int>&v){
//     int n = v.size();
//     int hash[n+2] ={0};
//     for(int i=0;i<n;i++){
//         hash[v[i]]=1;
//     }

//     for(int i=1;i<=n;i++){
//         if(hash[i]==0){
//             return i;
//         }
//     }
//     return -1;
// }

// int main(){
//     vector<int>v = {1,2,4,5};
//     cout<<"Missing number is->"<<missingNum(v);
//     return 0;
// }


// //Solution 3 optimal solution where TC = O(n);

// #include<bits/stdc++.h>
// using namespace std;

// int missingNum(vector<int>&v){
// //as we know the value of n coz and here is 5 coz the array contains element upto 5
//     int n=5;
//     int sumOfGivenArray =0;
//     int sumOfActualNnumber=0;
//     for(int i=0;i<v.size();i++){
//         sumOfGivenArray +=v[i]; // here the sum = 12;
//     }
//     for(int i=1;i<=n;i++){
//         sumOfActualNnumber +=i; //so here it is 15;
//     }
//     return (sumOfActualNnumber-sumOfGivenArray); // so 15-12 = 3 so the missing number is 3;

// }

// int main(){
//     vector<int>v = {1,2,4,5};
//     cout<<"Missing number is->"<<missingNum(v);
//     return 0;
// }



//  Solution 4 most optimal solution where TC = O(n) with the help of XOR;
#include<bits/stdc++.h>
using namespace std;

int missingNum(vector<int>&v){
    int xor1 = 0;
    int xor2 = 0;
    int n=5;
    for(int i=1;i<=n;i++){
        xor1 = xor1^i;  //so xor1 = 1 2 3 4 5
    }
    for(int i=0;i<n-1;i++){
        xor2 = xor2^v[i]; //xor2 = 1 2 4 5
    }
    return (xor1^xor2); // Here xor1^xor2 = 1 2 3 4 5
                                    //    = 1 2   4 5
                                    // so 1^1 =0, 2^2=0,3^0(nothing have)=3,4^4=0,5^5=0
                                    // so 0^0^3^0^0 = 3
                                    // xor of same number = 0 and xor of a number and 0 = number
}

int main(){
    vector<int>v = {1,2,4,5};
    cout<<"Missing number is->"<<missingNum(v);
    return 0;
}

