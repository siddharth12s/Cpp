#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    long long k;
    cin>>n>>m>>k;
    vector<long long> applicant(n);
    vector<long long> apartment_size(m);

    for(auto i=0;i<n;i++){
        cin>>applicant[i];
    }

    for (auto i=0; i<m; i++) {
        cin>>apartment_size[i];
    }

    int ans = 0;
    int i=0,j=0;
    sort(apartment_size.begin(),apartment_size.end());
    sort(applicant.begin(),applicant.end());

    while(i<n and j<m){
        if(abs(applicant[i]-apartment_size[j])<=k){
            ans++;
            i++;
            j++;
        }else if(applicant[i]<apartment_size[j]-k){
            i++;
        }else{
            j++;
        }
    }

    cout<<ans;
    return 0;
}
