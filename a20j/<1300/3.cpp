#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int n, t;
    cin >> n >> t;

    string s;
    cin >> s;

    while (t > 0)
    {

        for (auto i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == 'B' and s[i + 1] == 'G')
            {
                swap(s[i], s[i + 1]);
                i++;
            }
        }
        // cout << s << endl;
        t--;
    }

    cout << s;

    return 0;
}
