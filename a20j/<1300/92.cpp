#include <bits/stdc++.h>
# include <unordered_map>
using namespace std;

int main()
{
    // your code goes here
    int n, m;
    cin >> n >> m;
    int size = n;
    vector<int> v;
    unordered_map<int,int> vis;
    vector<int> dp(n+1, 0);
    while (n--)
    {
        int q;
        cin >> q;

        v.push_back(q);
        vis[q] = 0;
    }

    int i = size - 1;
    for (int itr = size - 1; itr >= 0; itr--)
    {
        if (vis[v[itr]] == 0)
        {
            dp[itr]++;
        }
        vis[v[itr]] = 1;
    }

    for (int i = size - 1; i >= 0; i--)
    {
        // cout << dp[i] << "before" << endl;
        dp[i] += dp[i + 1];
        // cout << dp[i] << "after" << endl;

    }

    while (m--)
    {
        int t;
        cin >> t;

        cout << dp[t - 1] << endl;
        }

    return 0;
}

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n, m, t;
//     cin >> n >> m;
//     int a[100005], d[100005] = {0};
//     bool v[100005];

//     for (int i = 1; i <= n; i++)
//         cin >> a[i];

//     for (int i = n; i >= 1; i--)
//     {
//         if (!v[a[i]])
//           d[i]++;
//         v[a[i]] = true;
//     }

//     for (int i = n; i >= 1; i--)
//         d[i] += d[i + 1];

//     for (int i = 0; i < m; i++)
//     {
//         cin >> t;
//         cout << d[t] << endl;
//     }

//     return 0;
// }