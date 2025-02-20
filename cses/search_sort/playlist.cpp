#include <bits/stdc++.h>
#include <math.h>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> v(n);
    unordered_map<long long, long long>m;
    long long ans = 0;
    for(auto i=0;i<n;i++){
        cin>>v[i];
    }
    long long start =0,end=0;
    long long cnt = 0;
    set<long long> s;
    // while(end<n){
    //     m[v[end]]++;
    //     cnt++;

    //     if(m.size()==cnt){
    //         ans = max(ans,end-start+1);
    //     }else{
    //         while(m.size()<cnt){
    //             m[v[start]]--;
    //             if(m[v[start]]==0){
    //                 m.erase(v[start]);
    //             }
    //             start++;
    //             cnt--;
    //         }
    //     }
    //     end++;
    // }
    // ans = max(ans,(int)s.size());
    //


    while(end<n){
        while(s.count(v[end])){
            s.erase(v[start]);
            start++;
        }

        s.insert(v[end]);
        ans = max(ans,end-start+1);
        end++;
    }
    cout<<ans;
    return 0;
}
