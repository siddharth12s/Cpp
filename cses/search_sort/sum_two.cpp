#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;

    vector<pair<int,int>>v;
    bool flag=false;

    for(auto i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back({a,i+1});
    }

    int start=0,end=n-1;

    sort(v.begin(),v.end());

    while(start<end){
        if(v[start].first+v[end].first==x){
            cout<<v[start].second<<" "<<v[end].second;
            flag=true;
            break;
        }else{
            if(v[start].first+v[end].first>x){
                end--;
            }else{
                start++;
            }
        }
    }

    if(!flag)
        cout<<"IMPOSSIBLE";


    return 0;
}
