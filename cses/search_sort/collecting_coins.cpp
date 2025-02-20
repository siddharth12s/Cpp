#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> v(n,0);
    unordered_map<int, int>m;
    for(auto i=0;i<n;i++){
        cin>>v[i];
        m[v[i]]=i;
    }

    int cnt = 0;

    for(auto i=1;i<n;i++){
        if(m[i]>m[i+1])
            cnt++;
    }

    cout<<cnt+1;
    return 0;
}
