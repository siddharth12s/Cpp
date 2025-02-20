#include<bits/stdc++.h> 
using namespace std;

int main() {
    // your code goes here
    int t;
    cin>>t;
while(t--)
{
    int n;
    cin>>n;
    int a[n], b[n];
    for (auto i = 0; i < n;i++){
        cin >> a[i];
    }

    for (auto i = 0; i < n;i++){
        cin >> b[i];
    }

    int cnt = 0;
    for (auto i = 0; i < n; i++)
    {
        if(a[i]>b[i]){
            cnt++;
        }
    }

    if(n%2){
        cout << cnt / 2 + 1 << endl;
    }

    cout << cnt / 2 << endl;
}

    return 0;
}
