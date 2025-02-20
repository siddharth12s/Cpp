#include<bits/stdc++.h> 
using namespace std;

int main() {
    // your code goes here
    int t = 5;
    int a[t][t];

    int posi = 0, posj = 0;
    for (auto i = 0; i < t; i++)
    {
        for (auto j = 0; j < t;j++){
            cin >> a[i][j];
            if(a[i][j]){
                posi = i;
                posj = j;
            }
        }
    }

    cout << abs(posi - 2) + abs(posj - 2);

    return 0;
}
