#include<bits/stdc++.h>
using namespace std;

static bool compare(const pair<int,int> &p1, const pair<int,int> &p2){
    if (p1.second==p2.second)
        return p1.first<p2.first;

    return p1.second<p2.second;
}
int main(){

    int n;
    cin>>n;

    vector<pair<int,int>> v;
    while(n--){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }


    sort(v.begin(),v.end(),compare);
    int ans = 0;
    int curr=0;
    auto prev = v[0];

    int end_time = 0;
    for(auto i=0;i<v.size();i++){
        if(end_time<=v[i].first){
            ans++;
            end_time=v[i].second;
        }
    }

    cout<<ans;
    return 0;
}
