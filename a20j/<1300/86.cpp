#include <bits/stdc++.h>
using namespace std;

static bool comp(pair<int,int> &p1, pair<int,int> &p2){
    if(p1.first > p2.first){
        return true;
    }
    else if(p1.first==p2.first){
        return p1.second < p2.second;
    }
    return false;
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};

int main()
{
    // your code goes here
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> v;
    while (n--)
    {
        int p, k;
        cin >> p >> k;

        v.push_back({p, k});
    }

    sort(v.begin(), v.end(), comp);
    // for(auto x : v){
    //     cout << x.first << "," << x.second << endl;
    // }
    unordered_map < pair<int, int>, int, pair_hash > m;

    for(auto x : v){
        m[x]++;
    }

    pair<int, int> ans = v[k-1];
    // cout << ans.first<<","<<ans.second << endl;

    cout << m[ans];

    return 0;
}
