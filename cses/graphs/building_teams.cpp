#include<bits/stdc++.h>
using namespace std;

// class DisjointSet{
//     vector<int> rank,parent;
//     public:

//         DisjointSet(int size){
//             rank.resize(size,0);
//             parent.resize(size+1,0);

//             for(auto i=0;i<=size;i++){
//                 parent[i]=i;
//             }
//         }
//         int find_parent(int node){
//             if(parent[node]==node)
//                 return node;

//             return parent[node]=find_parent(parent[node]);
//         }

//         void Union(int u, int v){
//             int pu = find_parent(u);
//             int pv = find_parent(v);
//             if(pu==pv){
//                 return;
//             }

//             if(rank[u]<rank[v]){
//                 parent[u]=v;
//             }else if(rank[u]>rank[v]){
//                 parent[v]=u;
//             }else{
//                 parent[u]=v;
//                 rank[v]+=1;
//             }
//         }

//         vector<int> get_parent(){
//             return parent;
//         }

// };
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

    queue<int> q;
    vector<int> color(n+1,-1);
    bool flag = true;
    for(auto i=1;i<=n;i++){
        if(color[i]==-1){
            color[i]=0;
            q.push(i);

            while(!q.empty()){
                auto node = q.front();
                q.pop();

                for(auto nbr : graph[node]){
                    if(color[nbr]==-1){
                        color[nbr]=1-color[node];
                        q.push(nbr);
                    }else if(color[node]==color[nbr]){
                        // cout<<"IMPOSSIBLE";
                        flag = false;
                        break;
                    }
                }
            }

            if(!flag)   break;
        }
    }

    if(flag){
        for(auto i=1;i<=n;i++){
            cout<<color[i]+1<<" ";
        }
    }else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}
