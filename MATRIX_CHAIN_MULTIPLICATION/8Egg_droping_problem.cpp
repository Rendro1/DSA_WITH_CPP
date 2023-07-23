#include <bits/stdc++.h>
using namespace std;

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
    int mini = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        int temp_ans = 1 + max(solve(e - 1, k - 1), solve(e, f - k));
        mini = min(mini, temp_ans);
    }
    return mini;
}

int main()
{
    int egg = 3;
    int floor = 5;
    cout << solve(egg, floor) << endl;
    return 0;
}