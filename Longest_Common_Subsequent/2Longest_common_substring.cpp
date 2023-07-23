//longest common substreang full dp solution->
#include <bits/stdc++.h>
using namespace std;

static int t[1001][1001];

int res(string x, string y, int m, int n)
{
    for (int i = 1; i < (m + 1); i++)
    {
        for (int j = 1; j < (n + 1); j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < (m + 1); i++)
    {
        for (int j = 1; j < (n + 1); j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                // t[i][j] = max(LCS(n-1,m,s1,s2),LCS(n,m-1,s1,s2))
                t[i][j] =max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[m][n];
}

int main()
{
    string x, y;
    cin >> x;
    cin >> y;
    int m = x.length();
    int n = y.length();
    cout << res(x, y, m, n) << endl;
    return 0;
}