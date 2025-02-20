#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    string s;
    cin >> s;

    for (auto i = 0; i < s.size(); i++)
    {
        if (i == 0)
        {
            cout << char(toupper(s[i]));
        }
        else
        {
            cout << s[i];
        }
    }
}
