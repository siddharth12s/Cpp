#include<bits/stdc++.h> 
using namespace std;

#define ull unsigned long long

int gcd(int a, int b){
    if (b==0){
        return a;
    }

    return gcd(b, a % b);
}

unsigned long long euclid(ull a, ull b, ull& x, ull& y){

    if(b==0){
        x = 1;
        y = 0;
        return a;
    }

    ull x1, y1;
    ull d = euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

int main() {
    // your code goes here
    unsigned long long a, b;
    cin >> a >> b;

    unsigned long long x = 0;
    unsigned long long y = 0;

    int _gcd = gcd(a, b);
    ull euclid_gcd = euclid(a, b, x, y);

    // cout << _gcd << endl;
    cout  <<x<<" "<<y<<" "<<euclid_gcd<< endl;

    return 0;
}
