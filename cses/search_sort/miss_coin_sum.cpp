#include<bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<long long>v;
    for (auto i=0; i<n; i++){
        long long a;
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    long long x = 1ll;
    bool flag = true;
    for(auto i=0;i<n;i++){
        if(v[i]>x){
            cout<<x;
            flag=false;
            break;
        }

        x+=v[i];
    }

    if(flag)
        cout<<x;


    return  0;
}
