#include <bits/stdc++.h>
#include <climits>
#include <queue>
using namespace std;

int main(){
    long long n,m;
    cin>>n>>m;

    vector<vector<pair<long long,long long>>> graph(n+1);

    for(auto i=0;i<m;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        // graph[b].push_back({a,c});
    }

    vector<long long> dist(n+1,LLONG_MAX);
    priority_queue<pair<long long ,long long>, vector<pair<long long, long long>>, greater<pair<long long,long long>>> pq;
    pq.push({0LL,1});
    dist[1]=0;

    while(!pq.empty()){
        const auto [check_dist,node] = pq.top();
        pq.pop();

        // int dist = node_and_dist.second;
        if(check_dist!=dist[node]){         // we will never go through the adjacency list of any vertex more than once.
            continue;
        }

        for(auto nbr_with_dist : graph[node]){
            long long distance = nbr_with_dist.second;
            long long nbr = nbr_with_dist.first;

            if(distance + dist[node]< dist[nbr]){
                dist[nbr] = distance + dist[node];
                pq.push({dist[nbr],nbr});
            }
        }
    }

    for(auto i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}
