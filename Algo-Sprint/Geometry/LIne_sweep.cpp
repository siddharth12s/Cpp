#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        // unordered_map<int, int> m;
        int n, k;
        cin >> n >> k;
        vector<vector<char>> v(n, vector<char>(k));

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < k; j++)
            {
                cin >> v[i][j];
            }
        }

        auto ch = v[n - 1][k - 1];
        char prev;
        bool check = false;
        for (auto i = 0; i < n - 1; i++)
        {
            for (auto j = 0; j < k - 1;j++){
                if(v[i][j]==ch){
                    check = true;
                    break;
                }
            }
        }

        

        // if (v[0][0] != v[n - 1][k - 1] and n == 1)
        // {
        //     cout << "NO" << endl;
        //     continue;
        // }

        set<char> s;
        set<char> t;
        set<char> u;
        for (auto &ch : v[0])
        {
            s.insert(ch);
        }

        for (auto i = 0; i < n; i++)
        {
            auto ch = v[i][0];
            t.insert(ch);
        }
        for (auto &ch : v[n-1])
        {
            // auto ch = v[0][k];
            u.insert(ch);
        }


        if(s.size()==1 )
        // if (s.size() == 1 and v[0][0] != v[n - 1][k - 1])
        // {
        //     cout << "NO" << endl;
        // }
        // bool check2 = false;
        if (s.size() == 2)
        {
            bool check2 = false;
            for (auto x : s)
            {
                if (t.count(x) == 0)
                {
                    cout << "NO" << endl;
                    check2 = true;
                    // check2 = true;
                    break;
                }
            }
            if(check2){
                continue;
            }
        }


        if(s.size()==1){

        }

        
        if(v[0][0]==v[n-1][k-1]){
            cout << "YES" << endl;
            continue;
        }
        if (check==false)
        {
            cout << "NO" << endl;
        }   
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}
