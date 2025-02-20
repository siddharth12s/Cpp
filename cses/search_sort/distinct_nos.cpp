#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    set<long long> st;
    while(n){
        long long x;
        cin>>x;
        st.insert(x);
        n--;
    }

    cout<<st.size();
    return 0;
}
