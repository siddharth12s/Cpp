#include<bits/stdc++.h> 
using namespace std;

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
int main() {
    // your code goes here
    int t;
    cin>>t;
    unordered_map < pair<int, int>, int,pair_hash > m;
while(t--)
{
    int n,x;
    cin>>n>>x;
    m[{n, x}]++;
}

int ans = INT_MIN;
for (auto p : m)
{
    ans = max(ans, p.second);
}

cout << ans;

return 0;
}
