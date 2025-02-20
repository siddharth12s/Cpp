#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &v,int n,int m, int i, int j){
    if(i<0 or j<0 or i>=n or j>=m){
        return;
    }

    if(v[i][j]!='.')
        return;

    v[i][j]='#';
    dfs(v,n,m,i+1,j);
    dfs(v,n,m,i,j+1);
    dfs(v,n,m,i-1,j);
    dfs(v,n,m,i,j-1);
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<char>> v(n,vector<char>(m,'#'));

    for(auto i=0;i<n;i++){
        for(auto j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    int ans = 0;
    for(auto i=0;i<n;i++){
        for(auto j=0;j<m;j++){
            if(v[i][j]=='.'){
                dfs(v,n,m,i,j);
                ans++;
            }
        }
    }

    cout<<ans;
    return 0;
}
