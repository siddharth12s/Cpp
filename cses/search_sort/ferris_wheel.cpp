#include <bits/stdc++.h>
using namespace std;



int main(){
    int n;
    int x;
    cin>>n>>x;

    vector<int> v(n,0);
    unordered_map<int, int>m;
    for(auto i=0;i<n;i++){
        cin>>v[i];
        m[v[i]]++;
    }

    sort(v.begin(),v.end());

    int cnt = 0;
    int i=0,j=n-1;
    vector<int> vis(n,0);
    while(i<j){
        if(v[i]+v[j]>x){
            j--;
        }else{
            cnt++;
            vis[i]=vis[j]=1;
            i++;
            j--;
        }
    }

    for(auto x : vis){
        if(x==0)
            cnt++;
    }



    cout<<cnt<<endl;
    return 0;
}
