#include<bits/stdc++.h>
using namespace std;

const long long BIG = 1e18;
int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<long long>> edges;

    for(auto i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }

    vector<int> dist(n+1,1e9);
    dist[1]=0;
    for(auto k=1;k<n;k++){
        for(auto &E : edges){
            int u = E[0];
            int v = E[1];
            int distance = E[2];

            if(distance + dist[u]<dist[v]){
                dist[v] = distance + dist[u];
            }
        }
    }

    for(auto x : dist){
        cout<<x<<" ";
    }




}
