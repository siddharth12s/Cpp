#include<bits/stdc++.h> 
using namespace std;

#define ull unsigned long long 

ull m = 1e9 + 7;

ull bin_expo(ull a,ull b){
    a %= m;
    ull res = 1;
    while(b>0){
        if(b&1){
            res = res * a % m;
        }
        b >>= 1;
        a = a * a % m;
    }
    return res;
}

int main() {
    // your code goes here
    int t;
    cin>>t;
while(t--)
{
    int a, b;
    cin >> a >> b;
    ull ans = bin_expo(a, b);
    cout << ans << endl;
}

    return 0;
}
