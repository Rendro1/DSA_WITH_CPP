#include <bits/stdc++.h>
using namespace std;

int LCS_cal(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (x[m - 1] == y[n - 1])
    {
        return 1 + LCS_cal(x, y, m - 1, n - 1);
    }

    return max(LCS_cal(x, y, m - 1, n), LCS_cal(x, y, m, n - 1));
}

int main()
{
    string x, y;
    cin >> x;
    cin >> y;
    int m = x.length();
    int n = y.length();
    cout << (m + n - LCS_cal(x, y, m, n)) << endl;
    return 0;
}