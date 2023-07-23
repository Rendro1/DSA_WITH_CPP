//optimize memoization of egg dropping problem or top down dp->

#include <bits/stdc++.h>
using namespace std;

static int t[11][51]; // t[egg+1][floor+1]-> constraints wise

int solve(int egg, int floor)
{
    int e = egg;
    int f = floor;
    if (f == 0 || f == 1)
    {
        return f;
    }
    if (e == 1)
    {
        return f;
    }
    if (t[e][f] != -1)
    {
        return t[e][f];
    }
    int mini = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        int low, high;
        if (t[e - 1][k - 1] != -1)
        {
            low = t[e - 1][k - 1];
        }
        else
        {
            low = solve(e - 1, k - 1);
            t[e - 1][k - 1] = low;
        }
        if (t[e][f - k] != -1)
        {
            high = t[e][f - k];
        }
        else
        {
            high = solve(e, f - k);
            t[e][f - k] = high;
        }

        int temp_ans = 1 + max(low, high);
        mini = min(mini, temp_ans);
    }
    return t[e][f] = mini;
}

int main()
{
    memset(t, -1, sizeof(t));
    int egg = 3;
    int floor = 5;

    cout << solve(egg, floor) << endl;
    return 0;
}