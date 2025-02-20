#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    long long mod = 1e9 + 7;
    long long x, y;
   
    int n;
    cin >> x >> y >> n;
    vector<long long> dp(n + 1, 0);
    dp[1] = x;
    dp[2] = y;

    for (auto i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] - dp[i - 2]);
    }

    long long ans;
    if (dp[n] < 0)
        ans = ((dp[n]% mod)+mod)%mod;
    else
        ans = dp[n] % mod;

    cout << ans;

    return 0;
}
