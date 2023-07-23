#include <bits/stdc++.h>
using namespace std;

int cutRod(int price[], int n)
{
    if (n <= 0)
        return 0;
    int max_val = INT_MIN;

    for (int i = 0; i < n; i++)
        max_val = max(max_val, price[i] + cutRod(price, n - i - 1));

    return max_val;
}


int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"Maximum Obtainable Value is ->"<<cutRod(arr, size);
    return 0;
}
