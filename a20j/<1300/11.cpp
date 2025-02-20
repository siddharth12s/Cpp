#include<bits/stdc++.h> 
using namespace std;

bool is_prime(int n){

    if(n==2){
        return true;
    }

    for (auto i = 2; i <= sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }

    return true;
}

int main() {
    // your code goes here
    int n, m;
    cin >> n >> m;
    // cout << is_prime(10);
    int next;

    for (auto i = n + 1; i <= m;i++){
        if(is_prime(i)){
            // cout << is_prime(i) << endl;
            next = i;
            break;
        }
    }
    // cout << n << m << next << endl;

    (next == m) ? cout << "YES" : cout << "NO";

    return 0;
}
