#include <bits/stdc++.h>
// #include <set>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    vector<int> h(n,0);
    vector<int> t(m,0);
    multiset<int> tickets;

    for(auto i=0;i<n;i++){
        cin>>h[i];
        tickets.insert(h[i]);
    }

    sort(h.begin(),h.end());

    for(auto i=0;i<m;i++){
        cin>>t[i];
    }

    for(auto x : t){
        auto it = tickets.upper_bound(x);
        if(it==tickets.begin()){
            cout<<-1<<endl;
        }else{
            cout<<*(--it)<<endl;
            tickets.erase(it);
        }
    }

    return 0;
}
