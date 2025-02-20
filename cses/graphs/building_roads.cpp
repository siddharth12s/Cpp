#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1,0);

            for(auto i=0;i<=n;i++){
                parent[i]=i;
            }
        }

        int find_parent(int node){
            if(parent[node]!=node)
                return parent[node] = find_parent(parent[node]);

            return parent[node];
        }

        void Union(int u, int v){
            int pu = find_parent(u);
            int pv = find_parent(v);


            if(pu==pv)  return;
            if(rank[pu]<rank[pv]){
                parent[pu]=pv;
            }else if(rank[pu]>rank[pv]){
                parent[pv]=pu;
            }else{
                parent[pu]=pv;
                rank[pv]+=1;
            }
        }

        vector<int> get_parent(){
            return parent;
        }
};

int main(){
    int n,m;
    cin>>n>>m;

    auto dsj = DisjointSet(n);
    for(auto i=0;i<m;i++){
        int a, b;
        cin>>a>>b;

        dsj.Union(b, a);
    }

    auto parent = dsj.get_parent();

    vector<int> rep;
    for(auto i=1;i<=n;i++){
        if(dsj.find_parent(i)==i){
            rep.push_back(i);
        }
    }

    cout<<rep.size()-1<<endl;
    for(auto i=1;i<rep.size();i++){
        cout<<rep[i-1]<<" "<<rep[i]<<endl;
    }
    return 0;
}
