#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &v, int i){
    if(i==0){
        if(v[i]==0)
            return 1;

        return 0;
    }

    int notpick = f(v, i - 1);
    int pick = 0;
    if(v[i]==0){
        pick = 1 + f(v, i - 1);
    }

    return max(pick,notpick);
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    vector<int> v;
    vector<int> dp(t+1,0);
    for (auto i = 0; i < t;i++){
        int n;
        cin >> n;

        v.push_back(n);
    }

    int ans = f(v, t - 1);

    cout << ans;
    return 0;
}


// pending