#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;

    // int a[t];
    int c_100 = 0, c_200 = 0, sum = 0;

    for (auto i = 0; i < t; i++)
    {
        int x;
        cin >> x;
        x == 100 ? c_100++ : c_200++;
        sum += x;
    }

    c_200 %= 2;
    c_100 -= c_200 * 2;

    (c_100 % 2 == 0 and c_100 >= 0) ? cout << "YES" : cout << "NO";

    return 0;
}
