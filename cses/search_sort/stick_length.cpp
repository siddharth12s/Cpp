#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<long long> v;
    unordered_map<long long, long long>m;
    for(auto i=0;i<n;i++){
        long long a;
        cin>>a;
        v.push_back(a);
        m[a]++;
    }

    sort(v.begin(),v.end());


    long long median = n/2;
    long long elem = v[median];
    long long ans = 0;
    for(auto x : v){
        ans += abs(elem-x);
    }

    cout<<ans;
    return 0;
}
