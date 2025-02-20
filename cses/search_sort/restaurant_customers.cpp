#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int,int>> v;
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        v.push_back({a,1});
        v.push_back({b,-1});
    }

    sort(v.begin(),v.end());

    int curr = 0;
    int ans=0;
    for(auto i=0;i<v.size();i++){
        curr += v[i].second;
        ans = max(curr,ans);
    }

    cout<<ans;
    return 0;
}
