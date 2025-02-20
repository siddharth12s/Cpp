#include<bits/stdc++.h> 
using namespace std;

void dfs(char mat[4][4], char ch, int i,int j){

    if(i<0 or i>=4 or j<0 or j>=4){
        return;
    }

    int cnt_d = 0, cnt_h = 0;

    if(mat[i][j]=='#'){
        cnt_h++;
    }
}

int main() {
    // your code goes here
    char mat[4][4];

    for (auto i = 0; i < 4;i++){
        for (auto j = 0; j < 4;j++){
            cin >> mat[i][j];
        }
    }

    bool flag = false;

    for (auto i = 0; i <= 2; i++)
    {
        int cnt_h = 0, cnt_d = 0;
        for (auto j = i; j < i + 2; j++)
        {
            if(mat[i][j]=='#'){
                cnt_h++;
            }else{
                cnt_d++;
            }
        }

        cout << cnt_h << "," << cnt_d << endl;
        if (cnt_h == 3 and cnt_d == 1)
        {
            flag = true;
        }
        else if (cnt_h == 4 and cnt_d == 0)
        {
            flag = true;
        }
        else if (cnt_h == 1 and cnt_d == 3)
        {
            flag = true;
        }
        else if (cnt_h == 0 and cnt_d == 4)
        {
            flag = true;
        }

        if(flag){
            break;
        }
    }

    if(flag){
        cout << "YES";
    }else{
        cout << "NO";
    }

        return 0;
}
