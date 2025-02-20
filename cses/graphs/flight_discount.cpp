#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<long long,long long>>> graph(n+1);

    for(auto i=0;i<m;i++){
        long long a,b,c;
        cin>>a>>b>>c;

        graph[a].push_back({b,c});
    }

    priority_queue<pair<long long,long long>,vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0,1});

    vector<int> dist(n+1,1e9);
    dist[1]= 0;

    while(!pq.empty()){
        auto dist_with_node = pq.top();
        pq.pop();

        if(dist_with_node.first!=dist[dist_with_node.second])
            continue;

        int node = dist_with_node.second;
        for(auto nbr : graph[node]){
            int distance = dist[node] + (nbr.second)/2;
            // int distance = dist[node] + nbr.second;
            int nbr_node = nbr.first;

            if(distance<dist[nbr_node]){
                dist[nbr_node] = distance;
                pq.push({dist[nbr_node],nbr_node});
            }
        }
    }


    // for(auto x :dist){
    //     cout<<x<<",";
    // }

    cout<<dist[n]+1;
    return 0;
}
