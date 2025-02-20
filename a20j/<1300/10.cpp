#include<bits/stdc++.h> 
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    string s;
    cin >> s;

    int ans = 0;
    for (auto i = 0; i < s.size() - 1;i++){
        if(s[i]==s[i+1]){
            ans++;
        }
    }
    cout << ans;

    return 0;
}
