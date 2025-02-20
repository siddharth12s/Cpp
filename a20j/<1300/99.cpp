#include<bits/stdc++.h> 
using namespace std;

int main() {
    // your code goes here
    int t;
    cin>>t;
    vector<int> v;
    while (t--)
    {
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());



    return 0;
}
