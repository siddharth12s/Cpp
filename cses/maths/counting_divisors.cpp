#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// ull cnt_divisors(ull n, vector<ull> &dp)
// {

//     ull cnt = 1;

//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     for (auto i = 2; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//         {

//             if (n / i == i)
//             {
//                 cnt++;
//             }
//             else
//             {
//                 cnt += 2;
//             }
//         }
//     }

//     if (n >= 2)
//     {
//         cnt++;
//     }

//     return dp[n] = cnt;
// }
// int main()
// {
//     // your code goes here
//     ull t;
//     cin >> t;
//     vector<ull> dp(1000001, -1);
//     while (t--)
//     {
//         ull n;
//         cin >> n;

//         cout << cnt_divisors(n,dp) << endl;
//     }

//     return 0;
// }

int main(){

    vector<int> ans(1000001, 0);

    for (auto i = 1; i < 1000001;i++){

        for (auto j = i; j < 1000001;j+=i){
            ans[j]++;
        }
    }

    ull t;
    cin >> t;
    
    while (t--)
    {
        ull n;
        cin >> n;
        cout << ans[n] << endl;
    }

    return 0;
}