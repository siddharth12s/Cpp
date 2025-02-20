#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<long long>v;
    for (auto i=0;i<n; i++) {
        long long a;
        cin>>a;
        v.push_back(a);
    }

    long long max_sum = LLONG_MIN;
    long long curr_sum = 0;

    for(auto i=0;i<n;i++){
        curr_sum += v[i];
        max_sum = max(curr_sum,max_sum);
        curr_sum = max(curr_sum,0LL);
    }

    cout<<max_sum;
    return 0;
}
