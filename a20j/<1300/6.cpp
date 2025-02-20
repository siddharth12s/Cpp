#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int a[3][3];
    int b[3][3];

    for (auto i = 0; i < 3; i++)
    {
        for (auto j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }

    b[0][0] = a[0][0] + a[1][0] + a[0][1];
    b[0][1] = a[0][0] + a[0][2] + a[1][1] + a[0][1];
    b[0][2] = a[0][1] + a[1][2] + a[0][2];
    b[1][0] = a[0][0] + a[1][1] + a[1][0] + a[2][0];
    b[1][1] = a[1][0] + a[1][1] + a[0][1] + a[1][2] + a[2][1];
    b[1][2] = a[1][1] + a[0][2] + a[1][2] + a[2][2];
    b[2][0] = a[2][0] + a[1][0] + a[2][1];
    b[2][1] = a[2][0] + a[1][1] + a[2][2] + a[2][1];
    b[2][2] = a[2][1] + a[2][2] + a[1][2];

    for (auto i = 0; i < 3; i++)
    {
        for (auto j = 0; j < 3; j++)
        {
            if (b[i][j] % 2 == 0)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        cout << endl;
    }

    return 0;
}
