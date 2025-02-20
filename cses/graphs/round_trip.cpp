#include <bits/stdc++.h>
using namespace std;

int cycle_start,cycle_end;
bool dfs(vector<vector<int>> &graph, vector<int> &vis, int src,vector<int> &parent, int par=-1){
    // if(vis[src])
    //     return true;

    vis[src]=1;
    parent[src]=par;
    for(auto nbr : graph[src]){
        if(!vis[nbr]){
            if(dfs(graph,vis,nbr,parent,src)){
                return true;
            }
        }else if(nbr!=par){
            cycle_start=nbr;
            cycle_end=src;
            return true;
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> graph(n+1);
    for(auto i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> vis(n+1,0);
    vector<int> parent(n+1,-1);
    bool flag = false;
    for(auto i=1;i<=n;i++){
        if(!vis[i] and dfs(graph,vis,i,parent,parent[i])){
            flag=true;
            break;
        }
    }

    if(flag){
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for(auto i = cycle_end;i!=cycle_start;i=parent[i]){
            cycle.push_back(i);
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(),cycle.end());
        cout<<cycle.size()<<endl;
        for(auto x :cycle){
            cout<<x<<" ";
        }
    }else{
        cout<<"IMPOSSIBLE";
    }


    return 0;
}
