#include <bits/stdc++.h>
using namespace std;

int water_traping(int arr[], int size)
{
    int maxL[size], maxR[size];
    int water[size];
    maxL[0] = arr[0];
    maxR[size - 1] = arr[size - 1];
    for (int i = 1; i < size; i++)
    {
        maxL[i] = max(maxL[i - 1], arr[i]);
    }
    for (int i = size - 2; i >= 0; i--)
    {
        maxR[i] = max(maxR[i + 1], arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        water[i] = min(maxL[i], maxR[i])-arr[i];
    }
    int sum = 0;
    for(int i=0;i<size;i++){
        sum +=water[i];
    }
    return sum;
}

int main()
{
    int arr[] = {3,0,0,2,0,4};
    int size = 6;
    cout<<water_traping(arr,size)<<endl;
    return 0;
}