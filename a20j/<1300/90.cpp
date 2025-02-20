#include<bits/stdc++.h> 
using namespace std;

int main() {
    // your code goes here
    int t;
    cin>>t;
    vector<long long> v;
    while (t--)
    {
        long long n;
        cin >> n;
        v.push_back(n);
    }

    int m;
    cin >> m;

    vector<long long> temp = v;

    sort(temp.begin(), temp.end());

    for (auto i = 1; i<temp.size();i++){
        temp[i] += temp[i - 1];
        v[i] += v[i - 1];
    }



        while (m--)
        {
            int q, a, b;
            cin >> q >> a >> b;

            if(q==2){
                if(a>1){
                cout << temp[b - 1] - temp[a - 2]<<endl;
                }else{
                    cout << temp[b - 1]<<endl;
                }
            }else{
                if(a>1){
                cout << v[b - 1] - v[a - 2]<<endl;
                }else{
                    cout << v[b - 1]<<endl;
                }
            }
        }

    return 0;
}
