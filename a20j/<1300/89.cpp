#include<bits/stdc++.h> 
using namespace std;
#define ll long long

int main()
{
    // your code goes here
    long int t;
    cin>>t;

    ll temp = t;
    vector<ll> v;
    while (t--)
    {
        ll n;
        cin >> n;

        v.push_back(n);
    }

    sort(v.begin(), v.end());
    ll ans = 0;

    for (auto i =1;i<=temp;i++){
        ans += abs(i - v[i - 1]);
    }

    cout << ans;

    return 0;
}
