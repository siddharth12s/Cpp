#include<bits/stdc++.h> 
using namespace std;

int main() {
    // your code goes here
    int t;
    cin>>t;
    int flag = 0;
    int change = 0;
    int coin_25 = 0, coin_50 = 0, coin_100 = 0;
    while (t--)
    {
        int n;
        cin >> n;

        if (n == 25)
        {
            change += 25;
            coin_25++;
        }
        else if (n == 50 and change >= 25 and coin_25>=1)
        {
            change += 25;
            coin_25--;
            coin_50++;
        }
        else if (n == 100 and change >= 75 and (coin_25>=3 or (coin_50>=1 and coin_25>=1)))
        {
            change += 25;
            if(coin_50>=1 and coin_25>=1){
                coin_50--;
                coin_25--;
            }else{
                coin_25 -= 3;
            }
            coin_100++;
        }
        else
        {
            flag = 1;
            break;
        }

}

    if (flag){
        cout << "NO";
    }else{
        cout << "YES";
    }

    return 0;
}
