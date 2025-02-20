#include<bits/stdc++.h> 
using namespace std;

#define ull unsigned long long

ull m = 1e9 + 7;


ull bin_expo_mod(ull b,ull c, ull m){
    b %= m;
    ull res = 1;
    while(c>0){
        if(c&1){
            res = res * b % m;
        }

        c >>= 1;
        b = b * b % m;
    }
    return res;
}

ull bin_expo(ull b, ull c){
    ull res = 1;

    while(c>0){
        if(c&1){
            res = res * b;
        }
        c >>= 1;
        b = b * b;
    }
    return res;
}

double log_a_to_base_b(ull a, ull b){
    // cout << log10(a) << "," << log10(b) << endl;
    return log10(a) / log10(b);
}

int main() {
    // your code goes here
    int t;
    cin>>t;
while(t--)
{
    int a, b, c;
    cin >> a >> b >> c;


    ull apowb = bin_expo_mod(b, c,m-1);
    ull ans = bin_expo_mod(a, apowb,m);

    cout << ans << endl;

}

    return 0;
}
