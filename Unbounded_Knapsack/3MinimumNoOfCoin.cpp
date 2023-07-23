#include <bits/stdc++.h>
using namespace std;


int minCoins(int coins[], int m, int V)
{
    // base case
    if (V == 0)
        return 0;

    // Initialize result
    int res = INT_MAX;


    for (int i = 0; i < m; i++)
    {
        if (coins[i] <= V)
        {
            int sub_res = minCoins(coins, m, V - coins[i]);

            // Check for INT_MAX to avoid overflow and see if
            // result can minimized
            if (sub_res != INT_MAX && sub_res + 1 < res)
                res = sub_res + 1;
        }
    }
    return res;
}
int main()
{
    int coins[] = {1,2,5};
    int m = sizeof(coins) / sizeof(coins[0]);
    // int V = 11;
    int v;
    cin>>v;
    cout << "Minimum coins required is "
         << minCoins(coins, m, v);
    return 0;
}
