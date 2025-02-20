#include<bits/stdc++.h> 
using namespace std;

int main() {
    // your code goes here
    string s;
    cin >> s;

    for (auto i = 0; i < s.size();){
        if(s[i]=='-' and s[i+1]=='.'){
            cout << 1;
            i += 2;
        }
        else if (s[i] == '-' and s[i + 1] == '-')
        {
            cout << 2;
            i += 2;
        }else{
            cout << 0;
            i++;
        }
    }

        return 0;
}
