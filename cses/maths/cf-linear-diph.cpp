#include<bits/stdc++.h> 
using namespace std;

int euclid(int a,int b, int &x, int &y){
    if(b==0){
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int d = euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int find_solutions(int a,int b, int c, int &x0, int &y0){
    int g = euclid(a, b, x0, y0);
    cout << g << endl;

    if(c%g){
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;


    if (a<0)
        x0 = -x0;
    if (b<0)
        y0 = -y0;

    return true;
}

int main() {
    // your code goes here
    int a, b, c;
    cin >> a >> b >> c;

    int flag = 0;
    for (auto i = 0; i <= c; i++)
    {
        for (auto j = 0; j <= c;j++){
            if(i*a+j*b==c){
                cout << "Yes";
                flag = 1;
                break;
            }
        }

        if(flag){
            break;
        }
    }

    if(!flag){
        cout << "No";
    }

        return 0;
}
