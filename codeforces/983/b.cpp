// #include <bits/stdc++.h>
// // For ordered_set
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define MOD 1000000007
// #define test  \
//     int t;    \
//     cin >> t; \
//     while (t--)
// #define init(arr, val) memset(arr, val, sizeof(arr))
// #define loop(i, a, b) for (auto i = a; i < b; i++)
// #define loopr(i, a, b) for (auto i = a; i >= b; i--)
// #define loops(i, a, b, step) for (auto i = a; i < b; i += step)
// #define looprs(i, a, b, step) for (auto i = a; i >= b; i -= step)
// #define ull unsigned long long int
// #define ll long long int
// #define P pair
// #define PLL pair<long long, long long>
// #define PII pair<int, int>
// #define PUU pair<unsigned long long int, unsigned long long int>
// #define L list
// #define V vector
// #define D deque
// #define ST set
// #define MS multiset
// #define M map
// #define UM unordered_map
// #define mp make_pair
// #define pb push_back
// #define pf push_front
// #define MM multimap
// #define F first
// #define S second
// #define IT iterator
// #define RIT reverse_iterator
// #define FAST                          \
//     ios_base::sync_with_stdio(false); \
//     cin.tie();                        \
//     cout.tie();
// #define FILE_READ_IN freopen("input.txt", "r", stdin);
// #define FILE_READ_OUT freopen("output.txt", "w", stdout);
// #define all(a) a.begin(), a.end()
// #define sortall(a) sort(all(a))
// #define rev(a) reverse(all(a))
// #define sz(a) a.size()
// #define yes cout << "YES" << endl
// #define no cout << "NO" << endl
// #define ct cout <<
// #define ci cin >>
// int mod = 998244353;
// using namespace std;
// // For ordered_set
// using namespace __gnu_pbds;
// template <typename T>
// using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// const ll maxn = 1e5;
// const ll inf = 1e9;
// const double pi = acos(-1);

// int mpow(int base, int exp)
// {
//     base %= mod;
//     int result = 1;
//     while (exp > 0)
//     {
//         if (exp & 1)
//             result = ((ll)result * base) % mod;
//         base = ((ll)base * base) % mod;
//         exp >>= 1;
//     }
//     return result;
// }

// bool bs(int mid,vector<int> &v){
//     return v.size()%mid==0;
// }
// void solve()
// {
//     // FAST;
//     int n, k;
//     ci n >> k;

//     vector<int> v;
//     for (auto i = 1; i <= n;i++){
//         v.push_back(i);
//     }
//         int start = 1, end = n;
//     while(start<=end){
//         int mid = start + (end - start) / 2;
//         if (bs(mid,v))
//         {
//             start = mid + 1;
//         }else{
//             end = mid - 1;
//         }
//     }
// }

// int main()
// {
//     int t;
//     ci t;
//     while (t > 0)
//     {
//         solve();
//         t--;
//     }

//     return 0;
// }
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;  // array a is [1, 2, ..., n]
    }

    // To store the starting indices of subarrays
    vector<int> partition_points;
    
    int count_of_k = 0, current_count = 0;

    for (int i = 0; i < n; i++) {
        current_count++;
        
        // Check if the current element is equal to k
        if (a[i] >= k) {
            count_of_k++;
        }

        // If we formed an odd-length subarray that includes k as median, add it as a partition
        if (current_count % 2 == 1 && count_of_k > 0) {
            partition_points.push_back(i + 1);  // Store the starting index for each partition
            current_count = 0;
            count_of_k = 0;
        }
    }

    // If we couldn't find a valid partition configuration, output -1
    if (partition_points.empty() || partition_points.size() % 2 == 0) {
        cout << -1 << endl;
        return;
    }

    // Output the number of partitions
    cout << partition_points.size() << endl;
    
    // Output the partition starting points
    for (int i = 0; i < partition_points.size(); i++) {
        cout << partition_points[i] << (i == partition_points.size() - 1 ? "\n" : " ");
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

