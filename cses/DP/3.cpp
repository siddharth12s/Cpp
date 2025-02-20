
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int mod = 1e9 + 7;
    int n, x;
    cin >> n >> x;

    vector<int> v(n);

    for (auto i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        v[i] = j;
    }

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= x; i++)
    {
        for (int c : v)
        {
            if (c <= i)
            {
                (dp[i] += dp[i - c]) %= mod;
            }
        }
    }

    cout << dp[x];

    return 0;
}
