#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    string s;
    cin >> s;

    int low = 0, high = 0;
    for (auto ch : s)
    {
        if (ch >= 'a' and ch <= 'z')
        {
            low++;
        }
        else
        {
            high++;
        }
    }

    if (low < high)
    {
        for (auto ch : s)
        {
            cout << char(toupper(ch));
        }
    }
    else
    {
        for (auto ch : s)
        {
            cout << char(tolower(ch));
        }
    }

    return 0;
}
