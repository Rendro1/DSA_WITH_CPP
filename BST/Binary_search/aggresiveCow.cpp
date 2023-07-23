#include <bits/stdc++.h>
using namespace std;

bool canPlaceCow(int n, int k, vector<int> &stalls, int dist)
{
    int place = stalls[0];
    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if ((stalls[i] - place) >= dist)
        {
            count++;
            place = stalls[i];
        }
        if (k == count)
        {
            return true;
        }
    }

    return false;
}

int solve(int n, int k, vector<int> &stalls)
{

    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1];
    int res = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canPlaceCow(n, k, stalls, mid))
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return res;
}
int main()
{
    int n=5; 
    int k=3;
    vector<int>stalls = {10, 1, 2, 7, 5};
    cout<<solve(n,k,stalls);
    return 0;
}