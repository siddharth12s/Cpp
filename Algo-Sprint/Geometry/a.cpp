#include<bits/stdc++.h> 
using namespace std;

int main() {
    // your code goes here
    int t;
    cin>>t;
while(t--)
{
    int n;
    cin>>n;
    int a[n];
    unordered_map<int, int> m;
    for (auto i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    int ans = 0;
    for (auto x : m)
    {
        ans += x.second / 3;
    }

    cout << ans << endl;
}

    return 0;
}
