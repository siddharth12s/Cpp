#include<bits/stdc++.h> 
using namespace std;

int pow(int a,int b){
    int res = 1;
    while (b>0)
    {
        if(b&1){
            res = res * a;
        }
        a = a*a;
        b >>= 1;
    }
    return res;
}

vector<int> build(int p){
    vector<int> ans;

    for (auto i = 0; i <= p;i++){
        ans.push_back(pow(2, i));
    }

    return ans;
}

void fun(vector<int> &v, int i,int target, int n, vector<int> &tmp){
    
    if(i==0){
        if(target/v[0]==n){
            for (auto j = 0; j < n;j++){
                tmp.push_back(v[0]);
            }
            return;
        }

        tmp.pop_back();
    }

    if(n==0){
        if(target!=0){
            tmp.pop_back();
            return;
        }

        return;
    }

    fun(v, i - 1, target, n,tmp);
    int pick = 0;
    if(v[i]<=target){
        tmp.push_back(v[i]);
        fun(v, i, target - v[i], n - 1, tmp);
    }

    return;
}


int main() {
    // your code goes here
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        // cout << n << " " << k;

        if(n==1){
            cout << k << endl;
        }

        if(n==2){
            cout << k << " " << 0 << endl;
        }

        else{
            int p = log2(k);
            vector<int> arr = build(p);


            vector<int> ans;
            int i = arr.size() - 1;
            // fun(arr, arr.size() - 1, k, n, ans);
            while(k>0){
                ans.push_back(arr[i]);
        
                k -= arr[i];
                n--;

                if(arr[i]>k){
                    i--;
                }

                if(n>k){    
                    k += ans.back();
                    ans.pop_back();
                    n++;
                }
            }

            for(auto x : ans){
                cout << x << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
