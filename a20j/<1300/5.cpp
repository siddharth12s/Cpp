#include<bits/stdc++.h> 
using namespace std;

int main() {
    // your code goes here
    int t;
    cin>>t;
    int ans = 0;

    while(1){
        t++;
        string year = to_string(t);
        unordered_map<int, int> m;
        for (auto ch : year)
        {
            m[ch - '0']++;
        }

        if(m.size()!=4){
            continue;
        }else{
            ans = t;
            break;
        }
    }

    cout << ans;

    return 0;
}
