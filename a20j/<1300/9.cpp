#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    string num;
    cin >> num;

    int count = 0;

    for (auto &x : num)
    {
        if (x == '4' or x == '7')
            count++;
    }

    if (count==4 or count==7)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
