#include<bits/stdc++.h> 
using namespace std;
typedef unsigned long long ull;

int main()
{
    // your code goes here
    ull t;
    cin>>t;
    vector<ull> div(1e6 + 1, 0);

while(t--)
{
    ull n;
    cin>>n;

    ull up = int(sqrt(n));
    for (ull i = 1; i <= up; i++)
    {
        if(n%i==0){
            div[i]++;
        }

        if(i != n/i){
            div[n/i]++;
        }
    }
}

// ull max = -1;
ull ans = 0;
for (ull i = 1e6; i >=1; i--)
{
    // cout << div[i] << ",";
    if (div[i] > 1)
    {
        ans = i;
        break;
        // max = div[i];
    }
}
cout << ans<<endl;

return 0;
}
