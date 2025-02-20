#include<bits/stdc++.h> 
using namespace std;

int main() {
    // your code goes here
    int t;
    cin>>t;
    int sumx = 0, sumy = 0, sumz = 0;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;

        sumx += x;
        sumy += y;
        sumz += z;
    }

    if (sumx==0 and sumy==0 and sumz==0){
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
