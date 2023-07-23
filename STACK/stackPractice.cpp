// // // stack implementataion->
// // #include<bits/stdc++.h>
// // using namespace std;

// // class Stack{
// //     // stack structure complete->
// //     public:
// //     int *arr;
// //     int top;
// //     int size;

// //     Stack(int size){
// //         this->size = size;
// //         arr = new int[size];
// //         top = -1;
// //     }

// //     // stack operation now ->
// //     void push(int ele){
// //         if(size-top >1){
// //             top++;
// //             arr[top] = ele;
// //         }
// //         else{
// //             cout<<"Stack overflow..."<<endl;
// //         }   
// //     }
// //     void pop(){
// //         if(top>=0){
// //             top--;
// //         }
// //         else{
// //             cout<<"Stack Underflow..."<<endl;
// //         }
// //     }
// //     void peek(){
// //         if(top >=0){
// //             cout<<arr[top]<<endl;
// //         }
// //         else{
// //             cout<<"Stack is empty..."<<endl;
// //         }
// //     }
// //     void isEmpty(){
// //         if(top == -1){
// //             cout<<"Stack is Empty..."<<endl; 
// //         }
// //         else{
// //             cout<<"Stack is not empty..."<<endl;
// //         }
// //     }


// // };

// // int main(){
// //     Stack s(4);

// //     s.push(5);
// //     s.push(8);
// //     s.push(9);
// //     s.push(11);

// //     s.peek();
// //     s.pop();
// //     s.peek();
// //     s.pop();
// //     s.peek();
// //     s.isEmpty();
// //     return 0;
// // }


// // Next Greater Element ->

// #include<bits/stdc++.h>
// using namespace std;

// vector<int>res(vector<int>v){
//     vector<int>vres;
//     stack<int>s;
//     for(int i= v.size()-1;i>=0;i--){
//         if(s.size()==0){
//             vres.push_back(-1);
//         }
//         else if(s.size()>0 && s.top()>v[i]){
//             vres.push_back(s.top());
//         }
//         else if(s.size()>0 && s.top()<=v[i]){
//             while(s.size()>0 && s.top()<=v[i]){
//                 s.pop();
//             }
//             if(s.size()==0){
//                 vres.push_back(-1);
//             }
//             else{
//                 vres.push_back(s.top());
//             }
//         }
//         s.push(v[i]);
//     }
//     reverse(vres.begin(),vres.end());
//     return vres;

// }

// int main(){
//     vector<int>v = {17,18,5,4,6,1};
//     vector<int>vi = res(v);
//     for(int i=0;i<vi.size();i++){
//         cout<<vi[i]<<" ";
//     }
//     return 0;
// }

// maximum area histogram:->

// #include<bits/stdc++.h>
// using namespace std;

// vector<int>nextSmaller(vector<int>arr,int n){
//     stack<int>s;
//     s.push(-1);
//     vector<int>ans(n);
//     for(int i=n-1;i>=0;i--){
//         int curr = arr[i];
//         while(s.top()!=-1 && arr[s.top()]>=curr){
//             s.pop();
//         }
//         ans[i] = s.top();
//         s.push(i);
//     }
//     return ans;
// }
// vector<int>prevSmaller(vector<int>arr,int n){
//     stack<int>s;
//     s.push(-1);
//     vector<int>ans(n);
//     for(int i=0;i<n;i++){
//         int curr = arr[i];
//         while(s.top()!=-1 && arr[s.top()]>=curr){
//             s.pop();
//         }
//         ans[i] = s.top();
//         s.push(i);
//     }
//     return ans;
// }


// int largestRectangleArea(vector<int>&height){
//     int n = height.size();
//     vector<int>next(n);
//     next = nextSmaller(height,n);
//     vector<int>prev(n);
//     prev = prevSmaller(height,n);
//     int newArea = INT_MIN;
//     for(int i=0;i<n;i++){
//         int l = height[i];
//         if(next[i]==-1){
//             next[i] = n;
//         }
//         int b = next[i] - prev[i] - 1;
//         int area = l*b;
//         newArea = max(newArea,area);
//     }
//     return newArea;

// }

// int main(){
//     vector<int>v = {2,1,5,6,2,3};
//     cout<<"Maximum area is->"<<largestRectangleArea(v);
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// void nextGreater(int arr[],int n){
//     vector<int>v;
//     stack<int>s;
//     for(int i=n-1;i>=0;i--){
//         if(s.size()==0){
//             v.push_back(-1);
//         }
//         else if(s.size()>0 && s.top()>arr[i]){
//             v.push_back(s.top());
//         }
//         else if(s.size()>0 && s.top()<=arr[i]){
//             while(s.size()>0 && s.top()<=arr[i]){
//                 s.pop();
//             }
//             if(s.size()==0){
//                 v.push_back(-1);
//             }
//             else{
//                 v.push_back(s.top());
//             }
//         }
//         s.push(arr[i]);
//     }
//     reverse(v.begin(),v.end());
//     for(auto it:v){
//         cout<<it<<" ";
//     }    

// }
// void prevGreater(int arr[],int n){
//     vector<int>v;
//     stack<int>s;
//     for(int i=0;i<n;i++){
//         if(s.size()==0){
//             v.push_back(-1);
//         }
//         else if(s.size()>0 && s.top()>arr[i]){
//             v.push_back(s.top());
//         }
//         else if(s.size()>0 && s.top()<=arr[i]){
//             while(s.size()>0 && s.top()<=arr[i]){
//                 s.pop();
//             }
//             if(s.size()==0){
//                 v.push_back(-1);
//             }
//             else{
//                 v.push_back(s.top());
//             }
//         }
//         s.push(arr[i]);
//     }
//     for(auto it:v){
//         cout<<it<<" ";
//     }    

// }

// int main(){
//     int arr[]= {17,18,5,4,6,1};
//     int n = 6;
//     nextGreater(arr,n);
//     cout<<endl;
//     prevGreater(arr,n);
//     return 0;
// }