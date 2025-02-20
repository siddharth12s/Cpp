#include <bits/stdc++.h>
#include <climits>
using namespace std;
const long long BIG = 1e18;
int main(){
    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<long long>> dist(n+1,vector<long long>(n+1,BIG));

    for(auto i=0;i<=n;i++){
        dist[i][i]=0;
    }

    for(auto i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(c<dist[a][b]){
            dist[a][b]=c;
            dist[b][a]=c;
        }
    }

    for(auto k=1;k<=n;k++){
        for(auto i=1;i<=n;i++){
            for(auto j=1;j<=n;j++){
                if(dist[i][j]> dist[k][j] + dist[i][k] and dist[k][j]!=BIG and dist[i][k]!=BIG){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    // dist[j][i] = dist[i][j];
                }
            }
        }
    }

    for(auto i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        if(dist[a][b]==BIG){
            cout<<-1<<endl;
        }
        else{
            cout<<dist[a][b]<<endl;
        }
    }
    return 0;
}
