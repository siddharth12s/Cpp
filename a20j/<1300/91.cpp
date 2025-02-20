#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

bool is_prime(int n){

    for (auto i = 2; i <= sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main()
{
    // your code goes here
    int t;
    cin >> t;

    while (t--)
    {
        ull n;
        cin >> n;

        double check = sqrt(n);

        if (n == 1)
        {
            cout << "NO" << endl;
        }

        else if ((int)check == ceil(check) and is_prime(ceil(check)))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
